#define IDX_DATA_AIISP_ISO_APU_Part3_DIM_NS    6
#define IDX_DATA_AIISP_ISO_APU_Part3_FACTOR_SZ    5
#define IDX_DATA_AIISP_ISO_APU_Part3_ENTRY_NS    9

static unsigned int _cam_data_entry_AIISP_ISO_APU_Part3_key0000[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X11000030, 0X14000220, };
static unsigned int _cam_data_entry_AIISP_ISO_APU_Part3_key0001[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X14000220, };
static unsigned int _cam_data_entry_AIISP_ISO_APU_Part3_key0002[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X11000030, 0X18000220, };
static unsigned int _cam_data_entry_AIISP_ISO_APU_Part3_key0003[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X18000220, };
static unsigned int _cam_data_entry_AIISP_ISO_APU_Part3_key0004[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0XFFFFFEC0, };
static unsigned int _cam_data_entry_AIISP_ISO_APU_Part3_key0005[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X2FFFFE20, };
static unsigned int _cam_data_entry_AIISP_ISO_APU_Part3_key0006[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X4FFFFE20, };
static unsigned int _cam_data_entry_AIISP_ISO_APU_Part3_key0007[] = {0X000FFFFC, 0X00000000, 0X03FF0000, 0X09000030, 0X8FFFFE20, };
static unsigned int _cam_data_entry_AIISP_ISO_APU_Part3_key0008[] = {0XFFFFFFFF, 0XFFFFFFFF, 0XFFFFFFFF, 0X17FFFFFF, 0XFFFFFFE0, };

static IDX_MASK_ENTRY _cam_data_entry_AIISP_ISO_APU_Part3[IDX_DATA_AIISP_ISO_APU_Part3_ENTRY_NS] =
{
    {(unsigned int*)&_cam_data_entry_AIISP_ISO_APU_Part3_key0000, 0, 0, 2, 0},
    {(unsigned int*)&_cam_data_entry_AIISP_ISO_APU_Part3_key0001, 0, 1, 2, 0},
    {(unsigned int*)&_cam_data_entry_AIISP_ISO_APU_Part3_key0002, 0, 2, 2, 0},
    {(unsigned int*)&_cam_data_entry_AIISP_ISO_APU_Part3_key0003, 0, 3, 2, 0},
    {(unsigned int*)&_cam_data_entry_AIISP_ISO_APU_Part3_key0004, 0, 24, 2, 0},
    {(unsigned int*)&_cam_data_entry_AIISP_ISO_APU_Part3_key0005, 0, 28, 2, 0},
    {(unsigned int*)&_cam_data_entry_AIISP_ISO_APU_Part3_key0006, 0, 29, 2, 0},
    {(unsigned int*)&_cam_data_entry_AIISP_ISO_APU_Part3_key0007, 0, 30, 2, 0},
    {(unsigned int*)&_cam_data_entry_AIISP_ISO_APU_Part3_key0008, 0, 43, 2, 0},
};

static unsigned short _cam_data_dims_AIISP_ISO_APU_Part3[] = 
{
    EDim_IspProfile,
    EDim_SensorMode,
    EDim_Flash,
    EDim_App,
    EDim_FaceDetection,
    EDim_Zoom,
};

static unsigned short _cam_data_expand_AIISP_ISO_APU_Part3[] = 
{0, 0, 1};

const IDX_MASK_T cam_data_AIISP_ISO_APU_Part3 =
{
    {IDX_ALGO_MASK, IDX_DATA_AIISP_ISO_APU_Part3_DIM_NS, (unsigned short*)&_cam_data_dims_AIISP_ISO_APU_Part3, (unsigned short*)&_cam_data_expand_AIISP_ISO_APU_Part3},
    {IDX_DATA_AIISP_ISO_APU_Part3_ENTRY_NS, IDX_DATA_AIISP_ISO_APU_Part3_FACTOR_SZ, (IDX_MASK_ENTRY*)&_cam_data_entry_AIISP_ISO_APU_Part3}
};