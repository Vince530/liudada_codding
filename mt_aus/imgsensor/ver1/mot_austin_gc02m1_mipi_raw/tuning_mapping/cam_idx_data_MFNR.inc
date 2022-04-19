#define IDX_DATA_MFNR_DIM_NS    6
#define IDX_DATA_MFNR_FACTOR_SZ    5
#define IDX_DATA_MFNR_ENTRY_NS    9

static unsigned int _cam_data_entry_MFNR_key0000[] = {0X00000FF0, 0X00000000, 0X00000000, 0X10000000, 0X14000220, };
static unsigned int _cam_data_entry_MFNR_key0001[] = {0X00000FF0, 0X00000000, 0X00000000, 0X08000000, 0X14000220, };
static unsigned int _cam_data_entry_MFNR_key0002[] = {0X00000FF0, 0X00000000, 0X00000000, 0X10000000, 0X18000220, };
static unsigned int _cam_data_entry_MFNR_key0003[] = {0X00000FF0, 0X00000000, 0X00000000, 0X08000000, 0X18000220, };
static unsigned int _cam_data_entry_MFNR_key0004[] = {0X00000FF0, 0X00000000, 0X00000000, 0X08000000, 0XFFFFFEC0, };
static unsigned int _cam_data_entry_MFNR_key0005[] = {0X00000FF0, 0X00000000, 0X00000000, 0X08000000, 0X2FFFFE20, };
static unsigned int _cam_data_entry_MFNR_key0006[] = {0X00000FF0, 0X00000000, 0X00000000, 0X08000000, 0X4FFFFE20, };
static unsigned int _cam_data_entry_MFNR_key0007[] = {0X00000FF0, 0X00000000, 0X00000000, 0X08000000, 0X8FFFFE20, };
static unsigned int _cam_data_entry_MFNR_key0008[] = {0X00000FF0, 0X00000000, 0X00000000, 0X10000000, 0XFFFFFFE0, };

static IDX_MASK_ENTRY _cam_data_entry_MFNR[IDX_DATA_MFNR_ENTRY_NS] =
{
    {(unsigned int*)&_cam_data_entry_MFNR_key0000, 0, 0, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_key0001, 0, 1, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_key0002, 13, 2, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_key0003, 13, 3, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_key0004, 26, 24, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_key0005, 39, 28, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_key0006, 52, 29, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_key0007, 65, 30, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_key0008, 0, 43, 2, 0},
};

static unsigned short _cam_data_dims_MFNR[] = 
{
    EDim_IspProfile,
    EDim_SensorMode,
    EDim_Flash,
    EDim_App,
    EDim_FaceDetection,
    EDim_Zoom,
};

static unsigned short _cam_data_expand_MFNR[] = 
{0, 0, 1};

const IDX_MASK_T cam_data_MFNR =
{
    {IDX_ALGO_MASK, IDX_DATA_MFNR_DIM_NS, (unsigned short*)&_cam_data_dims_MFNR, (unsigned short*)&_cam_data_expand_MFNR},
    {IDX_DATA_MFNR_ENTRY_NS, IDX_DATA_MFNR_FACTOR_SZ, (IDX_MASK_ENTRY*)&_cam_data_entry_MFNR}
};