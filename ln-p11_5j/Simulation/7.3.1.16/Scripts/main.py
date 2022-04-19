import cv2
import os
import math
import matplotlib.pyplot as plt
import numpy as np
import scipy.signal
import sys
from ast import literal_eval

def extractRGBcorners(imageDataR,imageDataG,imageDataB,patternSize):
    scaleFactor=1.0
    res=[False,False,False]
    if (imageDataG.shape[0]>1200):
        scaleFactor=imageDataG.shape[0]/1200.0
    ds4Size= (int(math.floor(imageDataG.shape[1]/scaleFactor)),int(math.floor(imageDataG.shape[0]/scaleFactor)))

    imageDataDs4=cv2.resize(imageDataG,ds4Size)
    res[0], cornersG =cv2.findChessboardCorners(imageDataDs4, patternSize)
    if res[0]:
        cornersG=cornersG*scaleFactor
        cv2.cornerSubPix(imageDataG,cornersG,(10,10),(3,3),(cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 100, 0.01))
    else:
        print('G channel: failed checkerboard extraction')
    

    imageDataDs4=cv2.resize(imageDataR,ds4Size)
    res[1], cornersR =cv2.findChessboardCorners(imageDataDs4, patternSize)
    if res[1]:
        cornersR=cornersR*scaleFactor
        cv2.cornerSubPix(imageDataR,cornersR,(10,10),(3,3),(cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 100, 0.01))
    else:
        print('R channel: failed checkerboard extraction')
    

    imageDataDs4=cv2.resize(imageDataB,ds4Size)
    res[2], cornersB =cv2.findChessboardCorners(imageDataDs4, patternSize)
    if res[2]:
        cornersB=cornersB*scaleFactor
        cv2.cornerSubPix(imageDataB,cornersB,(10,10),(3,3),(cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 100, 0.01))
    else:
        print('B channel: failed checkerboard extraction')

    if np.all(res):
        pass
    elif np.any(res):
        if res[0]:
            copyFrom=cornersG
        if res[1]:
            copyFrom=cornersR
        if res[2]:
            copyFrom=cornersB

        if res[0]==False:
            cornersG=copyFrom.copy()
        if res[1]==False:
            cornersR=copyFrom.copy()
        if res[2]==False:
            cornersB=copyFrom.copy()
    else:
        print('failed checkerboard extraction on all channels')
        raise 'failed checkerboard extraction on all channels'
    #make sure chart corners orientation is the same

    dxG=cornersG[0][0]-cornersG[patternSize[0]][0]
    dyG=cornersG[0][0]-cornersG[(patternSize[1]-1)*patternSize[0]][0]
    dxG=dxG/cv2.norm(dxG)
    dyG=dyG/cv2.norm(dyG)

    dxB=cornersB[0][0]-cornersB[patternSize[0]][0]
    dyB=cornersB[0][0]-cornersB[(patternSize[1]-1)*patternSize[0]][0]
    dxB=dxB/cv2.norm(dxB)
    dyB=dyB/cv2.norm(dyB)

    dxR=cornersR[0][0]-cornersR[patternSize[0]][0]
    dyR=cornersR[0][0]-cornersR[(patternSize[1]-1)*patternSize[0]][0]
    dxR=dxR/cv2.norm(dxR)
    dyR=dyR/cv2.norm(dyR)

    dotPxRG=dxR.dot(dxG)
    dotPyRG=dyR.dot(dyG)
    dotPxRB=dxB.dot(dxG)
    dotPyRB=dyB.dot(dyG)

    assert(dotPxRG>0.95)
    assert(dotPyRG>0.95)
    assert(dotPxRB>0.95)
    assert(dotPyRB>0.95)
    
    cornersR,_,_=cv2.calcOpticalFlowPyrLK(imageDataG,imageDataR,cornersG,cornersR)
    cornersB,_,_=cv2.calcOpticalFlowPyrLK(imageDataG,imageDataB,cornersG,cornersB)

    
    outR=[]
    outG=[]
    outB=[]
    for index in range(len(cornersG)):
        outR.append(cornersR[index][0])
        outG.append(cornersG[index][0])
        outB.append(cornersB[index][0])
    
    outR=np.array(outR)
    outG=np.array(outG)
    outB=np.array(outB)
    
    return outR,outG,outB


def searchOptCenterSampleGD(dataGX,dataGY,dataRX,dataRY,resX,resY):
    derivSize=16.0
    stepInd=0
    currentCenterX=resX/2
    currentCenterY=resY/2
    lastErr=float('inf')
    currErr=0
    while stepInd<100 and derivSize>=1:
        _,_,e0=estimateLUT(dataGX,dataGY,dataRX,dataRY,currentCenterX,currentCenterY,resX,resY)
        _,_,eX=estimateLUT(dataGX,dataGY,dataRX,dataRY,currentCenterX+derivSize*2,currentCenterY,resX,resY)
        _,_,eY=estimateLUT(dataGX,dataGY,dataRX,dataRY,currentCenterX,currentCenterY+derivSize*2,resX,resY)
        dEdX=eX-e0
        dEdY=eY-e0
        gradVec=np.array([-dEdX, -dEdY])
        gradVec=gradVec/np.linalg.norm(gradVec)*derivSize
        currentCenterX=currentCenterX+gradVec[0]
        currentCenterY=currentCenterY+gradVec[1]
        currErr+=e0
        if (stepInd%10==9):
            currErr=currErr/10
            if currErr>0.9*lastErr:# less that 10% improvement
                derivSize=derivSize/2
            lastErr=currErr
            currErr=0
        stepInd+=1
    print('Made '+str(stepInd)+' GD steps')
    return [currentCenterX,currentCenterY],e0

def estimateLUT(cornersXG,cornersYG,cornersXB,cornersYB,optCenterX,optCenterY,resX,resY):
    binsCount=33
    minSamplesPerBin=np.ceil(len(cornersXG)*(1.0/binsCount))

    radius=[]
    dr=[]
    for index in range(len(cornersXG)):
        rVec=np.array([cornersXG[index],cornersYG[index]])-np.array([optCenterX,optCenterY])
        rVecUnity=rVec/cv2.norm(rVec)
        dbVec=np.array([cornersXB[index],cornersYB[index]])-np.array([cornersXG[index],cornersYG[index]])
        radius.append(cv2.norm(rVec))
        dr.append(dbVec.dot(rVecUnity))

    maxX=resX-optCenterX
    if (optCenterX>resX/2.0):
        maxX=optCenterX
    maxY=resY-optCenterY
    if (optCenterY>resY/2.0):
        maxY=optCenterY
    maxDist=(maxX**2+maxY**2)**0.5

    x=np.linspace(0,maxDist,binsCount)
    yBins=[]
    for binID in range(binsCount):
        yBins.append([])
    
    for index in range(len(radius)):
        for binID in range(1,binsCount-1):
            if radius[index]>x[binID-1] and radius[index]<x[binID+1]:
                yBins[binID].append(dr[index])
    
    binMedians=np.zeros(binsCount)
    binMediansValid=np.zeros(binsCount)
    for binID in range(1,binsCount-1):
        binMediansValid[binID]=len(yBins[binID])>minSamplesPerBin
        if binMediansValid[binID]:
            binMedians[binID]=np.median(yBins[binID])
        else:
            binMedians[binID]=0
    
    #interpolate to fill holes
    binMedians[0]=0
    binMediansValid[0]=1
    for binID in range(1,binsCount-1):
        if binMediansValid[binID]:
            continue
        prevValidId=binID-1
        while  (prevValidId>=0) and (not binMediansValid[prevValidId]):
            prevValidId-=1
        nextValidId=binID+1
        while (nextValidId<binsCount) and (not binMediansValid[nextValidId]):
            nextValidId+=1
        if (prevValidId>=0) and (nextValidId<binsCount):
            alpha=(nextValidId-binID)/float(nextValidId-prevValidId)
            binMedians[binID]=binMedians[nextValidId]*(1.0-alpha)+binMedians[prevValidId]*alpha
            binMediansValid[binID]=1
    
    #extrapolate edge
    for binID in range(2,binsCount):
        if binMediansValid[binID]:
            continue
        binMedians[binID]=binMedians[binID-1]+(binMedians[binID-1]-binMedians[binID-4])/3
        binMediansValid[binID]=1

    drLUT=np.interp(radius,x,binMedians)
    err=np.sort(np.abs(drLUT-dr))
    # allow for 5% outliers
    err=err[0:int(len(err)*0.95)]
    err=np.sum(err)

    binMedians[1:binsCount-2]=scipy.signal.convolve(binMedians,np.ones(3)/3,mode='same')[1:binsCount-2]
    xR2=np.linspace(0,maxDist**2,17)**0.5
    yR2=np.interp(xR2,x,binMedians)

    return xR2,yR2,err


def previewCAC(imageDataR,imageDataG,imageDataB,lutR,optXR,optYR,lutB,optXB,optYB):
    imageDataOut=np.zeros([imageDataG.shape[0],imageDataG.shape[1],3])

    resX=imageDataG.shape[1]
    resY=imageDataG.shape[0]
    
    maxX=resX-optXR
    if (optXR>resX/2.0):
        maxX=optXR
    maxY=resY-optYR
    if (optYR>resY/2.0):
        maxY=optYR
    maxDistR=(maxX**2+maxY**2)**0.5

    maxX=resX-optXB
    if (optXB>resX/2.0):
        maxX=optXB
    maxY=resY-optYB
    if (optYB>resY/2.0):
        maxY=optYB
    maxDistB=(maxX**2+maxY**2)**0.5

    grid=np.mgrid[0:resY,0:resX]
    radiusR=((grid[0,:,:]-optYR)**2+(grid[1,:,:]-optXR)**2)**0.5
    radiusR=radiusR
    radiusB=((grid[0,:,:]-optYB)**2+(grid[1,:,:]-optXB)**2)**0.5
    radiusB=radiusB

    lutXR=np.linspace(0,maxDistR**2,17)**0.5
    lutXB=np.linspace(0,maxDistB**2,17)**0.5

    distortionR=np.interp(radiusR,lutXR,lutR)
    distortionB=np.interp(radiusB,lutXB,lutB)

    distortionRX=(grid[1,:,:]-optXR)*(1+distortionR)+optXR
    distortionRY=(grid[0,:,:]-optYR)*(1+distortionR)+optYR
    distortionBX=(grid[1,:,:]-optXB)*(1+distortionB)+optXB
    distortionBY=(grid[0,:,:]-optYB)*(1+distortionB)+optYB


    imageDataOut[:,:,0]=cv2.remap(imageDataR,distortionRX.astype(np.float32),distortionRY.astype(np.float32),cv2.INTER_CUBIC)
    imageDataOut[:,:,1]=imageDataG.copy()
    imageDataOut[:,:,2]=cv2.remap(imageDataB,distortionBX.astype(np.float32),distortionBY.astype(np.float32),cv2.INTER_CUBIC)
    
    imageDataOut[imageDataOut<0]=0
    imageDataOut[imageDataOut>1]=1

    return imageDataOut

def loadImage(filename,res):
    if filename.endswith('.yuv'):
        f=open(filename,'rb')
        rawData=np.fromfile(f, dtype=np.uint16)
        f.close()
        
        #read data planes
        imageDataG=np.reshape(rawData[res[1]*res[0]*0:res[1]*res[0]*1],[res[1],res[0]])
        imageDataB=np.reshape(rawData[res[1]*res[0]*1:res[1]*res[0]*2],[res[1],res[0]])
        imageDataR=np.reshape(rawData[res[1]*res[0]*2:res[1]*res[0]*3],[res[1],res[0]])
        
        # convert to 8bpp - actual maxx according to bpp should be used in C7
        maxValR=np.max(imageDataR)
        maxValG=np.max(imageDataG)
        maxValB=np.max(imageDataB)
        maxVal=np.max([maxValR,maxValG,maxValB])

        # AWB - real AWB should be used in C7
        # medianR=np.median(imageDataR).astype(np.float64)
        # medianG=np.median(imageDataG).astype(np.float64)
        # medianB=np.median(imageDataB).astype(np.float64)

        gainR=1.0 #medianG/medianR
        gainB=1.0 #medianG/medianB

        
        imageDataR=(np.clip((imageDataR.astype(np.float64)/maxVal)*gainR,0,1.0)*255).astype(np.uint8)
        imageDataG=(np.clip((imageDataG.astype(np.float64)/maxVal)*1.0  ,0,1.0)*255).astype(np.uint8)
        imageDataB=(np.clip((imageDataB.astype(np.float64)/maxVal)*gainB,0,1.0)*255).astype(np.uint8)
        
        imageBGR=np.zeros([imageDataR.shape[0],imageDataR.shape[1],3],dtype=np.uint8)
        imageBGR[:,:,0]=imageDataB
        imageBGR[:,:,1]=imageDataG
        imageBGR[:,:,2]=imageDataR
        cv2.imwrite('tmpIn.png',imageBGR)

        return imageDataR, imageDataG, imageDataB
    
    elif (not os.path.isdir(filename)):
        imageData=cv2.imread(filename)
        imageDataR=imageData[:,:,2]
        imageDataG=imageData[:,:,1]
        imageDataB=imageData[:,:,0]
    
        #debug display/dump
        imageBGR=np.zeros([imageDataR.shape[0],imageDataR.shape[1],3],dtype=np.uint8)
        imageBGR[:,:,0]=imageDataB
        imageBGR[:,:,1]=imageDataG
        imageBGR[:,:,2]=imageDataR
        cv2.imwrite('tmpIn.png',imageBGR)

        return imageDataR, imageDataG, imageDataB
    else:
     raise

def calibrateLCAC(dataFolder,patternSize,res):
    dataFiles=os.listdir(dataFolder)
    corners={}
    for currentFile in dataFiles:
        print('extracting from '+currentFile)
        try:
            imageDataR, imageDataG, imageDataB = loadImage(dataFolder+'/'+currentFile,res)
            cornersR,cornersG,cornersB=extractRGBcorners(imageDataR,imageDataG,imageDataB,patternSize)
            corners[currentFile]=[cornersR,cornersG,cornersB]
        except:
            print('extracting from '+currentFile+' failed')


    #search for optical center
    cornersXR=[]
    cornersYR=[]
    cornersXG=[]
    cornersYG=[]
    cornersXB=[]
    cornersYB=[]
    for currentFile in corners:
        for index in range(len(corners[currentFile][0])):
            cornersXR.append(corners[currentFile][0][index][0])
            cornersYR.append(corners[currentFile][0][index][1])
            cornersXG.append(corners[currentFile][1][index][0])
            cornersYG.append(corners[currentFile][1][index][1])
            cornersXB.append(corners[currentFile][2][index][0])
            cornersYB.append(corners[currentFile][2][index][1])

    print('Distortion center search')
    outB,_=searchOptCenterSampleGD(cornersXG,cornersYG,cornersXB,cornersYB,imageDataG.shape[1],imageDataG.shape[0])
    outR,_=searchOptCenterSampleGD(cornersXG,cornersYG,cornersXR,cornersYR,imageDataG.shape[1],imageDataG.shape[0])

    optCenterXB=outB[0]
    optCenterYB=outB[1]

    optCenterXR=outR[0]
    optCenterYR=outR[1]

    if not os.path.exists(os.path.join(dataFolder, 'LCACFigures')):
         os.makedirs(os.path.join(dataFolder, 'LCACFigures'))
         figureDir = os.path.join(dataFolder, 'LCACFigures')
    else:
         figureDir = os.path.join(dataFolder, 'LCACFigures')

    plt.figure()
    plt.gca().invert_yaxis()
    dx=np.array(cornersXG)-np.array(cornersXR)
    dy=np.array(cornersYG)-np.array(cornersYR)
    plt.quiver(cornersXG,cornersYG,dx,-dy,color='r')
    plt.title('Unmerged Red Optical Center')
    plt.plot(optCenterXR,optCenterYR,'*k')
    plt.savefig(os.path.join(figureDir, 'UM_Red_OptCenter_Values.png'))

    plt.figure()
    plt.gca().invert_yaxis()
    dx=np.array(cornersXG)-np.array(cornersXB)
    dy=np.array(cornersYG)-np.array(cornersYB)
    plt.quiver(cornersXG,cornersYG,dx,-dy,color='b')
    plt.title('Unmerged Blue Optical Center')
    plt.plot(optCenterXB,optCenterYB,'*k')
    plt.savefig(os.path.join(figureDir, 'UM_Blue_OptCenter_Values.png'))
    
    rGB=[]
    drB=[]
    for currentFile in corners:
        for index in range(len(corners[currentFile][0])):
            rVec=corners[currentFile][1][index]-[optCenterXB,optCenterYB]
            rVecUnity=rVec/cv2.norm(rVec)
            dbVec=corners[currentFile][2][index]-corners[currentFile][1][index]
            rGB.append(cv2.norm(rVec))
            drB.append(dbVec.dot(rVecUnity))

    drR=[]
    rGR=[]
    for currentFile in corners:
        for index in range(len(corners[currentFile][0])):
            rVec=corners[currentFile][1][index]-[optCenterXR,optCenterYR]
            rVecUnity=rVec/cv2.norm(rVec)
            drVec=corners[currentFile][0][index]-corners[currentFile][1][index]
            rGR.append(cv2.norm(rVec))
            drR.append(drVec.dot(rVecUnity))

    resX=imageDataG.shape[1]
    resY=imageDataG.shape[0]

    x,y,_=estimateLUT(cornersXG,cornersYG,cornersXB,cornersYB,optCenterXB,optCenterYB,resX,resY)
    x[0]=1e-10
    print('Blue opt. center: '+str(optCenterXB)+' '+str(optCenterYB))
    print('Blue LUT: ['+' '.join([str(t) for t in y/x])+']')
    blue_Lut = list()
    for t in y/x:
        blue_Lut.append(t)
    for c in range(len(blue_Lut)):
        print blue_Lut[c]
    print('')
    lutB=y/x

    plt.figure()
    plt.plot(rGB,drB,'*')
    plt.plot(x,y,'-+')
    plt.title('Unmerged Blue Optical Center LUT Values')
    plt.savefig(os.path.join(figureDir, 'UM_Blue_LUT_Values.png'))

    x,y,_=estimateLUT(cornersXG,cornersYG,cornersXR,cornersYR,optCenterXR,optCenterYR,resX,resY)
    x[0]=1e-10
    print('Red opt. center: '+str(optCenterXR)+' '+str(optCenterYR))
    print('Red LUT: ['+' '.join([str(t) for t in y/x])+']')
    red_Lut = list()
    for t in y/x:
        red_Lut.append(t)
    for c in range(len(red_Lut)):
        print red_Lut[c]
    print('')
    lutR=y/x

    plt.figure()
    plt.plot(rGR,drR,'*')
    plt.plot(x,y,'-+')
    plt.title('Unmerged Red Optical Center LUT Values')
    plt.savefig(os.path.join(figureDir, 'UM_Red_LUT_Values.png'))


    imageDataR=imageDataR.astype(np.float32)/255.0
    imageDataG=imageDataG.astype(np.float32)/255.0
    imageDataB=imageDataB.astype(np.float32)/255.0
    previewStartX=800
    previewStartY=600
    previewSize=200

    plt.figure()
    plt.gca().invert_yaxis()
    imageDataOut=np.zeros([imageDataG.shape[0],imageDataG.shape[1],3])
    imageDataOut[:,:,0]=imageDataR.copy()
    imageDataOut[:,:,1]=imageDataG.copy()
    imageDataOut[:,:,2]=imageDataB.copy()
    plt.imshow(imageDataOut[previewStartY:previewStartY+previewSize,previewStartX:previewStartX+previewSize,:])

    plt.figure()
    plt.gca().invert_yaxis()
    imageDataOut=previewCAC(imageDataR,imageDataG,imageDataB,lutR,optCenterXR,optCenterYR,lutB,optCenterXB,optCenterYB)
    plt.imshow(imageDataOut[previewStartY:previewStartY+previewSize,previewStartX:previewStartX+previewSize,:])

    imageBGR=np.zeros([imageDataR.shape[0],imageDataR.shape[1],3],dtype=np.uint8)
    imageBGR[:,:,0]=imageDataOut[:,:,2]*255
    imageBGR[:,:,1]=imageDataOut[:,:,1]*255
    imageBGR[:,:,2]=imageDataOut[:,:,0]*255
    cv2.imwrite('tmpOut.png',imageBGR.astype(np.uint8))

    #common opt center for LCAC HW
    weightR=np.sum(np.abs(lutR))
    weightB=np.sum(np.abs(lutB))

    optCenterX=(optCenterXB*weightB+optCenterXR*weightR)/(weightR+weightB)
    optCenterY=(optCenterYB*weightB+optCenterYR*weightR)/(weightR+weightB)

    plt.figure()
    plt.gca().invert_yaxis()
    dx=np.array(cornersXG)-np.array(cornersXR)
    dy=np.array(cornersYG)-np.array(cornersYR)
    plt.quiver(cornersXG,cornersYG,dx,-dy,color='r')
    plt.title('Merged Red Optical Center')
    plt.plot(optCenterX,optCenterY,'*k')
    plt.savefig(os.path.join(figureDir, 'M_Red_OptCenter_Values.png'))

    plt.figure()
    plt.gca().invert_yaxis()
    dx=np.array(cornersXG)-np.array(cornersXB)
    dy=np.array(cornersYG)-np.array(cornersYB)
    plt.quiver(cornersXG,cornersYG,dx,-dy,color='b')
    plt.title('Merged Blue Optical Center')
    plt.plot(optCenterX,optCenterY,'*k')
    plt.savefig(os.path.join(figureDir, 'M_Blue_OptCenter_Values.png'))

    x,y,err=estimateLUT(cornersXG,cornersYG,cornersXB,cornersYB,optCenterX,optCenterY,resX,resY)
    x[0]=1e-10
    print('Blue opt. center: '+str(optCenterX)+' '+str(optCenterY))
    print('Blue LUT: ['+' '.join([str(t) for t in y/x])+']')
    blue_Lut2 = list()
    for t in y/x:
        blue_Lut2.append(t)
    for c in range(len(blue_Lut2)):
        print blue_Lut2[c]
    print('')
    lutB=y/x

    x,y,err=estimateLUT(cornersXG,cornersYG,cornersXR,cornersYR,optCenterX,optCenterY,resX,resY)
    x[0]=1e-10
    print('Red opt. center: '+str(optCenterX)+' '+str(optCenterY))
    print('Red LUT: ['+' '.join([str(t) for t in y/x])+']')
    red_Lut2 = list()
    for t in y/x:
        red_Lut2.append(t)
    for c in range(len(red_Lut2)):
        print red_Lut2[c]
    print('')
    lutR=y/x

    plt.figure()
    plt.gca().invert_yaxis()
    imageDataOut=previewCAC(imageDataR,imageDataG,imageDataB,lutR,optCenterX,optCenterY,lutB,optCenterX,optCenterY)
    plt.imshow(imageDataOut[previewStartY:previewStartY+previewSize,previewStartX:previewStartX+previewSize,:])

    #plt.show()

if __name__ == "__main__":
    _res=[int(sys.argv[4]), int(sys.argv[5])]
    _dataFolder = sys.argv[1]
    _patternSizeX = sys.argv[2]
    _patternSizeY = sys.argv[3]
    _patternSize = (int(_patternSizeX), int(_patternSizeY))
	
    #print(type(_patternSize))
    
    # _dataFolder=r'C:\Users\costiap\Perforce\costiap_COSTIAP-DT_6739\Users\costiap\CAC_calib_openCV\data'
    # _patternSize=(10,7)

    # _dataFolder=r'C:\Users\costiap\Perforce\costiap_COSTIAP-DT_6739\Users\costiap\CAC_calib_openCV\data2\MI8_4032x3024\Checkerboard'
    # _patternSize=(8,6)

    # _dataFolder= r'T:\SimulatorCmd_Tests\LCACtests_V10\Mi9F1\data\jpegs'
    # _patternSize=(10,7)

    # _dataFolder= r'C:\Users\costiap\Perforce\costiap_COSTIAP-DT_6739\Users\costiap\CAC_calib_openCV\LCACartificial\DistortedInputs'
    # _patternSize=(10,7)

    # _dataFolder=r'C:/Users/costiap/Perforce/costiap_COSTIAP-DT_6739/Users/costiap/CAC_calib_openCV/ONsemi'
    # _patternSize=(31,23)

    # _dataFolder= r'C:\Users\costiap\Perforce\costiap_COSTIAP-DT_6739\Users\costiap\CAC_calib_openCV\Mate20'
    # _patternSize=(9,6)
    # _res=[3968,2976]

    # _dataFolder= r'C:\LCAC\data'
    # _patternSize=(10,7)
    # _res = None

    calibrateLCAC(_dataFolder,_patternSize,_res)
    print('Done')