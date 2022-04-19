@region_start
#define NVRAM_P1GGM_TUNING_PARAM_NUM 9181001
@region_end

const P1GGM_NVRAM_T P1GGM_%04d = {
    P1GGM_NVRAM_START
    { 
     {// gamma param
      {
					0x00000000, 0x00401004, 0x00802008, 0x00C0300C, 0x01004010, 0x01405014,
					0x01806018, 0x01C0701C, 0x02008020, 0x02609826, 0x02C0B02C, 0x0320C832,
					0x0380E038, 0x03E0F83E, 0x04411044, 0x04A1284A, 0x05014050, 0x05816058,
					0x06018060, 0x0681A068, 0x0701C070, 0x0781E078, 0x08020080, 0x08822088,
					0x09024090, 0x09625896, 0x09C2709C, 0x0A4290A4, 0x0AC2B0AC, 0x0B22C8B2,
					0x0B82E0B8, 0x0C0300C0, 0x0C8320C8, 0x0CE338CE, 0x0D4350D4, 0x0DC370DC,
					0x0E4390E4, 0x0EA3A8EA, 0x0F03C0F0, 0x0F63D8F6, 0x0FC3F0FC, 0x10240902,
					0x10842108, 0x10C4310C, 0x11044110, 0x11645916, 0x11C4711C, 0x12248922,
					0x1284A128, 0x12C4B12C, 0x1304C130, 0x1364D936, 0x13C4F13C, 0x14050140,
					0x14451144, 0x14852148, 0x14C5314C, 0x15054150, 0x15455154, 0x15A5695A,
					0x16058160, 0x16459164, 0x1685A168, 0x16C5B16C, 0x1705C170, 0x1785E178,
					0x18060180, 0x18862188, 0x19064190, 0x19866198, 0x1A0681A0, 0x1A86A1A8,
					0x1B06C1B0, 0x1B86E1B8, 0x1C0701C0, 0x1C4711C4, 0x1CC731CC, 0x1D4751D4,
					0x1DC771DC, 0x1E0781E0, 0x1E87A1E8, 0x1F07C1F0, 0x1F87E1F8, 0x20080200,
					0x20882208, 0x20C8320C, 0x21485214, 0x21886218, 0x21C8721C, 0x22489224,
					0x2288A228, 0x22C8B22C, 0x2308C230, 0x2348D234, 0x23C8F23C, 0x24090240,
					0x24491244, 0x24C9324C, 0x25495254, 0x26098260, 0x2689A268, 0x2709C270,
					0x2789E278, 0x280A0280, 0x288A2288, 0x290A4290, 0x298A6298, 0x2A0A82A0,
					0x2A8AA2A8, 0x2ACAB2AC, 0x2B4AD2B4, 0x2B8AE2B8, 0x2C0B02C0, 0x2C4B12C4,
					0x2C8B22C8, 0x2D0B42D0, 0x2D4B52D4, 0x2D8B62D8, 0x2DCB72DC, 0x2E4B92E4,
					0x2E8BA2E8, 0x2ECBB2EC, 0x2F4BD2F4, 0x2F8BE2F8, 0x300C0300, 0x304C1304,
					0x308C2308, 0x30CC330C, 0x310C4310, 0x314C5314, 0x318C6318, 0x31CC731C,
					0x320C8320, 0x324C9324, 0x328CA328, 0x330CC330, 0x334CD334, 0x338CE338,
					0x340D0340, 0x344D1344, 0x348D2348, 0x34CD334C, 0x350D4350, 0x354D5354,
					0x358D6358, 0x35CD735C, 0x360D8360, 0x364D9364, 0x368DA368, 0x36CDB36C,
					0x370DC370, 0x374DD374, 0x378DE378, 0x37CDF37C, 0x380E0380, 0x384E1384,
					0x388E2388, 0x38CE338C, 0x38CE338C, 0x390E4390, 0x394E5394, 0x398E6398,
					0x398E6398, 0x39CE739C, 0x3A0E83A0, 0x3A4E93A4, 0x3A8EA3A8, 0x3ACEB3AC,
					0x3B0EC3B0, 0x3B4ED3B4, 0x3B8EE3B8, 0x3BCEF3BC, 0x3C0F03C0, 0x3C4F13C4,
					0x3C4F13C4, 0x3C8F23C8, 0x3CCF33CC, 0x3D0F43D0, 0x3D0F43D0, 0x3D4F53D4,
					0x3D8F63D8, 0x3DCF73DC, 0x3E0F83E0, 0x3E4F93E4, 0x3E8FA3E8, 0x3E8FA3E8,
					0x3ECFB3EC, 0x3ECFB3EC, 0x3F0FC3F0, 0x3F4FD3F4, 0x3F8FE3F8, 0x3FCFF3FC
     },
	   {
					0x00000000, 0x00C0300C, 0x01806018, 0x02609826, 0x0340D034, 0x04010040,
					0x04C1304C, 0x05816058, 0x06419064, 0x06C1B06C, 0x0741D074, 0x07C1F07C,
					0x08421084, 0x08E2388E, 0x09826098, 0x0A0280A0, 0x0A82A0A8, 0x0B02C0B0,
					0x0B82E0B8, 0x0C0300C0, 0x0C8320C8, 0x0CC330CC, 0x0D0340D0, 0x0D6358D6,
					0x0DC370DC, 0x0E0380E0, 0x0E4390E4, 0x0E83A0E8, 0x0EC3B0EC, 0x0F23C8F2,
					0x0F83E0F8, 0x0FC3F0FC, 0x10040100, 0x10641906, 0x10C4310C, 0x11044110,
					0x11445114, 0x11846118, 0x11C4711C, 0x12248922, 0x1284A128, 0x12C4B12C,
					0x1304C130, 0x1344D134, 0x1384E138, 0x13C4F13C, 0x14050140, 0x14451144,
					0x14852148, 0x14C5314C, 0x15054150, 0x15455154, 0x15856158, 0x15C5715C,
					0x16058160, 0x16459164, 0x1685A168, 0x16C5B16C, 0x1705C170, 0x1745D174,
					0x1785E178, 0x17C5F17C, 0x18060180, 0x18260982, 0x18461184, 0x18C6318C,
					0x19064190, 0x19866198, 0x1A0681A0, 0x1A86A1A8, 0x1AC6B1AC, 0x1B46D1B4,
					0x1BC6F1BC, 0x1C0701C0, 0x1C8721C8, 0x1CC731CC, 0x1D0741D0, 0x1D8761D8,
					0x1DC771DC, 0x1E4791E4, 0x1E87A1E8, 0x1F07C1F0, 0x1F47D1F4, 0x1FC7F1FC,
					0x20080200, 0x20882208, 0x20C8320C, 0x21485214, 0x21886218, 0x21C8721C,
					0x22489224, 0x2288A228, 0x22C8B22C, 0x2348D234, 0x2388E238, 0x24090240,
					0x24491244, 0x25094250, 0x25896258, 0x26098260, 0x2689A268, 0x2709C270,
					0x2789E278, 0x280A0280, 0x288A2288, 0x290A4290, 0x298A6298, 0x2A0A82A0,
					0x2A4A92A4, 0x2ACAB2AC, 0x2B4AD2B4, 0x2BCAF2BC, 0x2C0B02C0, 0x2C4B12C4,
					0x2C8B22C8, 0x2D0B42D0, 0x2D4B52D4, 0x2D8B62D8, 0x2DCB72DC, 0x2E4B92E4,
					0x2E8BA2E8, 0x2F0BC2F0, 0x2F4BD2F4, 0x2FCBF2FC, 0x300C0300, 0x308C2308,
					0x30CC330C, 0x314C5314, 0x318C6318, 0x320C8320, 0x324C9324, 0x32CCB32C,
					0x330CC330, 0x338CE338, 0x33CCF33C, 0x344D1344, 0x348D2348, 0x34CD334C,
					0x350D4350, 0x354D5354, 0x35CD735C, 0x360D8360, 0x364D9364, 0x36CDB36C,
					0x370DC370, 0x374DD374, 0x378DE378, 0x37CDF37C, 0x380E0380, 0x384E1384,
					0x388E2388, 0x38CE338C, 0x394E5394, 0x398E6398, 0x398E6398, 0x39CE739C,
					0x3A0E83A0, 0x3A4E93A4, 0x3A8EA3A8, 0x3A8EA3A8, 0x3ACEB3AC, 0x3B0EC3B0,
					0x3B4ED3B4, 0x3B8EE3B8, 0x3BCEF3BC, 0x3BCEF3BC, 0x3C0F03C0, 0x3C0F03C0,
					0x3C4F13C4, 0x3C8F23C8, 0x3CCF33CC, 0x3CCF33CC, 0x3D0F43D0, 0x3D4F53D4,
					0x3D4F53D4, 0x3D4F53D4, 0x3D8F63D8, 0x3D8F63D8, 0x3DCF73DC, 0x3E0F83E0,
					0x3E0F83E0, 0x3E0F83E0, 0x3E4F93E4, 0x3E4F93E4, 0x3E8FA3E8, 0x3ECFB3EC,
					0x3ECFB3EC, 0x3F0FC3F0, 0x3F4FD3F4, 0x3F4FD3F4, 0x3F8FE3F8, 0x3FCFF3FC
	  	}
     }
    },
    {   // tuning param
            1,			  // mode
            8,			 // low_contrast_thr
            {// tuning_lut
                {	// contrast_wt_tbl
                 //	0	1	2	 3	  4    5	6	 7	  8    9	10
               	    50, 80, 100, 100, 100, 100, 100, 100, 100, 100, 100
                },
                {	// lv_wt_tbl
                    //LV0	1	2	3	4	5	6	7	8	9	10	 11   12   13	14	 15   16   17	18	 19
					 					33,  33,  33,	33,  33,  33,  33,	33, 33, 66, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100
                }
            },
		    		{   // tuning_smooth
                1,
                0,
                5
            },
            {   // tuning_flare
                0
            }
    }
};