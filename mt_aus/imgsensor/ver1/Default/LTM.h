
const ISP_NVRAM_LTM_TUNING_PARAM_T LTM_%04d = {
        .rAutoLTMParam = {
            LTM_MODE_LOCAL,    /* local_tone_mode */
            /* global tone info */
            10,    /* clipping_thd_perc */
            500,    /* high_bound_perc */
            /* strut mid_perc_lut */
            {
                2,
                {    600,    900 }
            },
            //   LV0     LV1     LV2     LV3     LV4     LV5     LV6     LV7     LV8     LV9    LV10    LV11    LV12    LV13
            {     20,     20,     20,     20,     20,     20,     20,     20,     20,     20,     20,     20,     20,     20 },    /* gct_limit_ratio */
            4095,    /* fix_clipping_thd */
            4095,    /* fix_turning_point */
            0,    /* fix_gtc_blending_ratio */
            /* local tone info */
            //   LV0     LV1     LV2     LV3     LV4     LV5     LV6     LV7     LV8     LV9    LV10    LV11    LV12    LV13
            {    300,    300,    300,    300,    300,    300,    300,    300,    300,    300,    300,    300,    400,    500 },    /* strength_lct */
            {   2500,   4095 },    /* strength_ltp_mean_idx */
            /* strength_ltp */
            {
                //   LV0     LV1     LV2     LV3     LV4     LV5     LV6     LV7     LV8     LV9    LV10    LV11    LV12    LV13
                {     80,     80,     80,     80,     80,     80,     80,     80,     80,     80,     80,     80,     80,     80 },
                {     20,     20,     20,     20,     20,     20,     20,     20,     20,     20,     20,     20,     20,     20 }
            },
            /* struct local_global_blending */
            {
                {   4095,   6000 },
                {    100,     80 },
                //   LV0     LV1     LV2     LV3     LV4     LV5     LV6     LV7     LV8     LV9    LV10    LV11    LV12    LV13
                {     80,     80,     80,     80,     80,     80,     80,     80,     80,     80,     80,     80,     80,     80 }
            },
            /* face tone info */
            1,    /* ltm_face_protection_enable */
            1,    /* multi_face_protection_enable */
            0,    /* ltm_face_state_link_enable */
            1,    /* ltm_face_ct_enable */
            0,    /* fcae_ct_size_prob */
            1,    /* fcae_ct_perc */
            //   LV0     LV1     LV2     LV3     LV4     LV5     LV6     LV7     LV8     LV9    LV10    LV11    LV12    LV13
            {     96,     96,     96,     96,     96,     96,     96,     96,     96,     96,     96,     96,     96,     96 },    /* fcae_ct_blending_ratio */
            1,    /* ltm_face_tp_enable */
            500,    /* non_robust_face_turning_point_reduction_ratio */
            200,    /* face_ratio_low_bound */
            400,    /* face_ratio_high_bound */
            //   LV0     LV1     LV2     LV3     LV4     LV5     LV6     LV7     LV8     LV9    LV10    LV11    LV12    LV13
            {   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000 },    /* face_protection_strength */
            /* spatial smooth */
            1,    /* spatial_smooth_enable */
            /* spatial_smooth_strength_table */
            {      0,  65535 },
            {   //   LV0     LV1     LV2     LV3     LV4     LV5     LV6     LV7     LV8     LV9    LV10    LV11    LV12    LV13
                {   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000 },
                {  20000,  20000,  20000,  20000,  20000,  20000,  20000,  20000,  20000,  20000,  20000,  20000,  10000,   1000 }
            },
            /* spatial_smooth_diff_table */
            {    600,    950,   1100,   2000 },
            /* spatial_smooth_variance_table */
            {      0,   5000,  65535,  70000 },
            {   1000,   1000,   1000,   1000 },
            /* face spatial smooth */
            0,        /* ltm_face_spatial_smooth_enable */
            /* ltm_b2f_turning_point_diff_spatial_smooth_weighting_table */
            {   //   LV0     LV1     LV2     LV3     LV4     LV5     LV6     LV7     LV8     LV9    LV10    LV11    LV12    LV13
                {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },    // x1
                {   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000 },    // x2
                {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },    // y1
                {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }     // y2
            },
            /* ltm_b2f_distance_reduction_ratio */
            {   1000,    500 },
            /* ltm_f2b_turning_point_diff_spatial_smooth_weighting_table */
            {   //   LV0     LV1     LV2     LV3     LV4     LV5     LV6     LV7     LV8     LV9    LV10    LV11    LV12    LV13
                {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },    // x1
                {   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000,   1000 },    // x2
                {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },    // y1
                {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }     // y2
            },
            /* ltm_f2b_distance_reduction_ratio */
            {   1000,    500 },

            /* multicamSync */
            {
                0,    /* enableSync */
                10,    /* zoomBase, 1x = 10, 5x = 50, 0.6x = 6 */
                {    /* syncWin[4][4]   Record Tele in Wide Window position, and Wide in UltraWide window position */
                    {      0,      0,      0,      0 },
                    {      0,      0,      0,      0 },
                    {      0,      0,      0,      0 },
                    {      0,      0,      0,      0 }
                }
            },

            /* table */
            {      0,      0,      1,      0,      2,     14,     32 },

            /* reserve - HDR */
            {
                {    300,    300,    100,    100,      3,      0,    300,    300,    100,    100,      3,      0,     10,     10 },
                {    300,    500,   1000,    100,     35,     10,     10,      5,      0,      0,      0,      0,      0,      0 },
                {      1,      1,      0,      1,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
                {     96,     96,     96,     96,     96,     96,     96,     96,     96,     96,     96,     96,     96,     96 },
                {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 },
                {      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0,      0 }
            },

            /* temporal Smooth */
            /* struct ltms_lock */
            {
                300,
                300,
                0,
                0,
                3,
                0
            },
            /* struct global_tone_lock */
            {
                300,
                300,
                100,
                100,
                3,
                0
            },
            /* struct local_tone_lock */
            {
                300,
                300,
                100,
                100,
                3,
                0
            },
            /* struct smooth_speed */
            {
                40,
                40,
                40,
                60
            },
            /* struct face_smooth_speed */
            {
                40,
                40,
                40,
                60
            },
            10,    /* ct_stable_thd */
            10,    /* tp_stable_thd */
            5,    /* pline_boudary_thd */
            /* pline_delta_ev_speed */
            { 300,    500,   1000 },
            { 100,     35,     10 },
            2,    /* delta_cwr_thsouhld */
            2    /* max_index_count_thsouhld */
        }
};