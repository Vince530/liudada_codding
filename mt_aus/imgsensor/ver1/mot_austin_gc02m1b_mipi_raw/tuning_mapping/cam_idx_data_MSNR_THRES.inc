#define IDX_DATA_MSNR_THRES_DIM_NS    6
#define IDX_DATA_MSNR_THRES_FACTOR_SZ    5
#define IDX_DATA_MSNR_THRES_ENTRY_NS    14

static unsigned int _cam_data_entry_MSNR_THRES_key0000[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X11000030, 0X14000220, };
static unsigned int _cam_data_entry_MSNR_THRES_key0001[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X14000220, };
static unsigned int _cam_data_entry_MSNR_THRES_key0002[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X11000030, 0X18000220, };
static unsigned int _cam_data_entry_MSNR_THRES_key0003[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X18000220, };
static unsigned int _cam_data_entry_MSNR_THRES_key0004[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X14800020, };
static unsigned int _cam_data_entry_MSNR_THRES_key0005[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X18800020, };
static unsigned int _cam_data_entry_MSNR_THRES_key0006[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X19000030, 0X1D000020, };
static unsigned int _cam_data_entry_MSNR_THRES_key0007[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0XFFFFFEC0, };
static unsigned int _cam_data_entry_MSNR_THRES_key0008[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X2FFFFE20, };
static unsigned int _cam_data_entry_MSNR_THRES_key0009[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X4FFFFE20, };
static unsigned int _cam_data_entry_MSNR_THRES_key0010[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X8FFFFE20, };
static unsigned int _cam_data_entry_MSNR_THRES_key0011[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X01000030, 0XFFFFFFE2, };
static unsigned int _cam_data_entry_MSNR_THRES_key0012[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X1E000020, };
static unsigned int _cam_data_entry_MSNR_THRES_key0013[] = {0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0X17FFFFFF, 0XFFFFFFE0, };

static IDX_MASK_ENTRY _cam_data_entry_MSNR_THRES[IDX_DATA_MSNR_THRES_ENTRY_NS] =
{
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0000, 0, 0, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0001, 0, 1, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0002, 1, 2, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0003, 1, 3, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0004, 2, 21, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0005, 3, 22, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0006, 4, 23, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0007, 5, 24, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0008, 6, 28, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0009, 7, 29, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0010, 8, 30, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0011, 9, 34, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0012, 10, 36, 2, 0},
    {(unsigned int*)&_cam_data_entry_MSNR_THRES_key0013, 0, 43, 2, 0},
};

static unsigned short _cam_data_dims_MSNR_THRES[] = 
{
    EDim_IspProfile,
    EDim_SensorMode,
    EDim_Flash,
    EDim_App,
    EDim_FaceDetection,
    EDim_Zoom,
};

static unsigned short _cam_data_expand_MSNR_THRES[] = 
{0, 0, 0};

const IDX_MASK_T cam_data_MSNR_THRES =
{
    {IDX_ALGO_MASK, IDX_DATA_MSNR_THRES_DIM_NS, (unsigned short*)&_cam_data_dims_MSNR_THRES, (unsigned short*)&_cam_data_expand_MSNR_THRES},
    {IDX_DATA_MSNR_THRES_ENTRY_NS, IDX_DATA_MSNR_THRES_FACTOR_SZ, (IDX_MASK_ENTRY*)&_cam_data_entry_MSNR_THRES}
};