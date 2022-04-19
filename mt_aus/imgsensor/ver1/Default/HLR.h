const ISP_NVRAM_HLR_TUNING_PARAM_T HLR_%04d = {
    .rAutoHLRParam={
            //   LV00    LV01    LV02    LV03  
            { 0,      30,      85,      120 },  //Not support negative lv
                                                //   Low  Mid  High   
			{	2200,3400,5800 },
            HLR_MODE_ON,      //HLR_ON_OFF
            {
                0,
                1024,
                2304,
                3136,
                3600,
                3844,
                3969,
                4096,
                18,
				1,
                16,
                16,
                4,
                0,
            },
            {
                //Low CT
                {   // LV00       LV01       LV02      LV03 
                    { 16,12,2 },{ 16,14,2 },{ 16,16,4 },{ 16,16,4 }
                },
        //Mid CT
                {   // LV00       LV01       LV02      LV03
                    { 14,14,2 },{ 14,14,2 },{ 16,16,4 },{ 16,16,4 }
                },
        //High CT
                {   // LV00       LV01       LV02      LV03
                    { 14,16,2 },{ 16,16,2 },{ 16,16,4 },{ 16,16,4 }
                },
            },
        //Reserve
            {
                { 0,0,0 },{ 0,0,0 },{ 0,0,0 },{ 0,0,0 }
            },
		    0,//Reserve0
		    0,//Reserve1
		    0,//Reserve2
		    0,//Reserve3
		    0,//Reserve4
		    0,//Reserve5
		    0,//Reserve6   
		    0,//Reserve7
        }
};