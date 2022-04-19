#define IDX_DATA_MFNR_THRES_DIM_NS    6
#define IDX_DATA_MFNR_THRES_FACTOR_SZ    5
#define IDX_DATA_MFNR_THRES_ENTRY_NS    9

static unsigned int _cam_data_entry_MFNR_THRES_key0000[] = {0X00000FF0, 0X00000000, 0X00000000, 0X10000000, 0X14000220, };
static unsigned int _cam_data_entry_MFNR_THRES_key0001[] = {0X00000FF0, 0X00000000, 0X00000000, 0X08000000, 0X14000220, };
static unsigned int _cam_data_entry_MFNR_THRES_key0002[] = {0X00000FF0, 0X00000000, 0X00000000, 0X10000000, 0X18000220, };
static unsigned int _cam_data_entry_MFNR_THRES_key0003[] = {0X00000FF0, 0X00000000, 0X00000000, 0X08000000, 0X18000220, };
static unsigned int _cam_data_entry_MFNR_THRES_key0004[] = {0X00000FF0, 0X00000000, 0X00000000, 0X08000000, 0XFFFFFEC0, };
static unsigned int _cam_data_entry_MFNR_THRES_key0005[] = {0X00000FF0, 0X00000000, 0X00000000, 0X08000000, 0X2FFFFE20, };
static unsigned int _cam_data_entry_MFNR_THRES_key0006[] = {0X00000FF0, 0X00000000, 0X00000000, 0X08000000, 0X4FFFFE20, };
static unsigned int _cam_data_entry_MFNR_THRES_key0007[] = {0X00000FF0, 0X00000000, 0X00000000, 0X08000000, 0X8FFFFE20, };
static unsigned int _cam_data_entry_MFNR_THRES_key0008[] = {0X00000FF0, 0X00000000, 0X00000000, 0X10000000, 0XFFFFFFE0, };

static IDX_MASK_ENTRY _cam_data_entry_MFNR_THRES[IDX_DATA_MFNR_THRES_ENTRY_NS] =
{
    {(unsigned int*)&_cam_data_entry_MFNR_THRES_key0000, 0, 0, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_THRES_key0001, 0, 1, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_THRES_key0002, 1, 2, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_THRES_key0003, 1, 3, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_THRES_key0004, 2, 24, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_THRES_key0005, 3, 28, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_THRES_key0006, 4, 29, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_THRES_key0007, 5, 30, 2, 0},
    {(unsigned int*)&_cam_data_entry_MFNR_THRES_key0008, 0, 43, 2, 0},
};

static unsigned short _cam_data_dims_MFNR_THRES[] = 
{
    EDim_IspProfile,
    EDim_SensorMode,
    EDim_Flash,
    EDim_App,
    EDim_FaceDetection,
    EDim_Zoom,
};

static unsigned short _cam_data_expand_MFNR_THRES[] = 
{0, 0, 0};

const IDX_MASK_T cam_data_MFNR_THRES =
{
    {IDX_ALGO_MASK, IDX_DATA_MFNR_THRES_DIM_NS, (unsigned short*)&_cam_data_dims_MFNR_THRES, (unsigned short*)&_cam_data_expand_MFNR_THRES},
    {IDX_DATA_MFNR_THRES_ENTRY_NS, IDX_DATA_MFNR_THRES_FACTOR_SZ, (IDX_MASK_ENTRY*)&_cam_data_entry_MFNR_THRES}
};