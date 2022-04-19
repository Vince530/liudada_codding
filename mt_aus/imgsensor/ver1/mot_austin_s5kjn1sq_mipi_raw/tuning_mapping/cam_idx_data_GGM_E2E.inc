#define IDX_DATA_GGM_E2E_DIM_NS    2
#define IDX_DATA_GGM_E2E_FACTOR_SZ    5
#define IDX_DATA_GGM_E2E_ENTRY_NS    2

static unsigned int _cam_data_entry_GGM_E2E_key0000[] = {0X03E00000, 0X10000000, 0X00000000, 0X00000000, 0X00000100, };
static unsigned int _cam_data_entry_GGM_E2E_key0001[] = {0X03E00000, 0X20000000, 0X00000000, 0X00000000, 0X00000100, };

static IDX_MASK_ENTRY _cam_data_entry_GGM_E2E[IDX_DATA_GGM_E2E_ENTRY_NS] =
{
    {(unsigned int*)&_cam_data_entry_GGM_E2E_key0000, 0, 41, 2, 0},
    {(unsigned int*)&_cam_data_entry_GGM_E2E_key0001, 1, 42, 2, 0},
};

static unsigned short _cam_data_dims_GGM_E2E[] = 
{
    EDim_IspProfile,
    EDim_App,
};

static unsigned short _cam_data_expand_GGM_E2E[] = 
{0, 0, 0};

const IDX_MASK_T cam_data_GGM_E2E =
{
    {IDX_ALGO_MASK, IDX_DATA_GGM_E2E_DIM_NS, (unsigned short*)&_cam_data_dims_GGM_E2E, (unsigned short*)&_cam_data_expand_GGM_E2E},
    {IDX_DATA_GGM_E2E_ENTRY_NS, IDX_DATA_GGM_E2E_FACTOR_SZ, (IDX_MASK_ENTRY*)&_cam_data_entry_GGM_E2E}
};