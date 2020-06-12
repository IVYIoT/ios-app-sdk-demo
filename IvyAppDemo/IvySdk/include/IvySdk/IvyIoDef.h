#ifndef _IVYIO_DEF_H_B4B0A801ACC249be80EE295D810FD0E7_
#define _IVYIO_DEF_H_B4B0A801ACC249be80EE295D810FD0E7_

#ifdef _WIN32
	#include <windows.h>
	#define IVYIO_API WINAPI
#else
	#define IVYIO_API
#endif

//
// log level
//
#define IVYIO_LOG_LEVEL_NO 0
#define IVYIO_LOG_LEVEL_ERR 1
#define IVYIO_LOG_LEVEL_DBG 2
#define IVYIO_LOG_LEVEL_ALL 3

//
// const
//
#define IVYIO_HANDLE unsigned int
#define IVYIO_PLAYBACK_SEEK_TYPE_TIMESTAMP 0
#define IVYIO_PLAYBACK_SEEK_TYPE_PERCENT 1
#define IVYIO_EVENT_DATA_LEN 1024 * 2
#define IVYIO_ERROR_CODE_ARRAY_COUNT 16
#define IVYIO_INTERNET_ADDR_LEN 16

//
// frame tag
//
#define FRAME_TAG_LIVE_FRAME 0x4556494c
#define FRAME_TAG_PLAYBACK_FRAME 0x4b424c50
#define FRAME_TAG_PLAYBACK_E_FRAME 0x46454250


// Connection message
#define IVYIO_CONNECT_ERROR 88

//
// enum
//
typedef enum
{
	IVYIO_P2P_MODE_UDP = 0,
	IVYIO_P2P_MODE_TCP = 1,
	IVYIO_P2P_MODE_AUTO = 2
}IVYIO_P2P_MODE;


typedef enum { 
	IVYIO_DEV_IPC = 0, 
	IVYIO_DEV_BATTERY_CAMERA = 1, 
	IVYIO_DEV_NVR            = 2, 
	IVYIO_DEV_BASE_STATION   = 3, 
	IVYIO_DEV_OTHER          = 100,

	// for compatible with old fos dev
	IVYIO_DEV_FOS_IPC = 1000,
	IVYIO_DEV_FOS_NVR,
	IVYIO_DEV_FOS_BPI
}IVYIO_DEV_TYPE;


typedef enum
{
	IVYIO_CONNECTION_URL = 0,
	IVYIO_CONNECTION_UID = 1,
	IVYIO_CONNECTION_DEFAULT = 2
}IVYIO_CONNECTION_TYPE;

typedef enum
{
	IVYIO_HANDLE_STATE_INIT = 0,
	IVYIO_HANDLE_STATE_CONNECTTING = 1,
	IVYIO_HANDLE_STATE_ONLINE = 2,
	IVYIO_HANDLE_STATE_OFFLINE = 3,
	IVYIO_HANDLE_STATE_MAX_USERS = 4, 
	IVYIO_HANDLE_STATE_LOCKED = 5,
	IVYIO_HANDLE_STATE_USR_OR_PWD_ERR = 6,
	IVYIO_HANDLE_STATE_DENY = 7,
	IVYIO_HANDLE_STATE_UNKNOWN,
	IVYIO_HANDLE_STATE_INVALID_HANDLE,
	IVYIO_HANDLE_STATE_CANCEL_BY_USR,
    IVYIO_HANDLE_STATE_ON_RESET,
}IVYIO_HANDLE_STATE;

typedef enum
{
	IVYIO_RESULT_OK = 0,
	IVYIO_RESULT_FAIL,
	IVYIO_RESULT_HANDLE_ERR,
	IVYIO_RESULT_USR_OR_PWD_ERR,
	IVYIO_RESULT_ARGS_ERR,
	IVYIO_RESULT_APITIME_ERR,
	IVYIO_RESULT_DENY,
	IVYIO_RESULT_LOCKED,
	IVYIO_RESULT_MAX_USER,	
	IVYIO_RESULT_TALK_OPENED_BY_OTHERS,
	IVYIO_RESULT_CANCEL_BY_USER,
	IVYIO_RESULT_TIMEOUT,
	IVYIO_RESULT_UNSUPPORT,
	IVYIO_RESULT_UNKNOWN,
	IVYIO_RESULT_OFFLINE,
	IVYIO_RESULT_OK_ON_RESET_STATE,
	IVYIO_RESULT_NO_PERMITTION,
	IVYIO_RESULT_DOWNLOADING
}IVYIO_RESULT;

typedef enum
{	
	IVYIO_CMD_EXEC_CODE_SUCCESS = 0,
	IVYIO_CMD_EXEC_CODE_FAIL = -1,
	IVYIO_CMD_EXEC_CODE_ERR_ARGS = -2,
	IVYIO_CMD_EXEC_CODE_CHANNEL_OVERSTEP = -3,
	IVYIO_CMD_EXEC_CODE_UNSUPPORT = -9,
	IVYIO_CMD_EXEC_CODE_FORMAT_UNSUPPORT = -15
}IVYIO_COMMAND_RETRUN_CODE;

// Record event
typedef enum
{
	IVYIO_RECORD_ERROR_NO_ENOUGE_SPACE = 2052, 
	IVYIO_RECORD_ERROR_MAX_FILE,  
	IVYIO_RECORD_ERROR_SOLUTION_CHG,
	IVYIO_RECORD_ERROR_FILE_PATH_NOEXIST,
	IVYIO_RECORD_ERROR_UNKNOW
}IVYIO_RECORD_EVENT;

typedef enum 
{ 
	PLATFORM_HISI      = 0, 
	PLATFORM_AMBA      = 1, 
	PLATFORM_MSTAR      = 2, 
	PLATFORM_INGENIC   = 3, 
	PLATFORM_OTHER      = 100 
}IVYIO_PLATFORM_TYPE;


typedef enum
{
	IVYIO_MAIN_VIDEO_STREAM = 0,
	IVYIO_SUB_VIDEO_STREAM = 1
}IVYIO_VIDEO_STREAM_TYPE;

typedef enum
{
	IVYIO_MAIN_AUDIO_STREAM = 0,
	IVYIO_SUB_AUDIO_STREAM = 1
}IVYIO_AUDIO_STREAM_TYPE;


typedef enum
{
	IVYIO_PLAYBACK_CMD_PAUSE = 0,
	IVYIO_PLAYBACK_CMD_RESUME = 1,
	IVYIO_PLAYBACK_CMD_SEEK = 2
}IVYIO_PLAYBACK_CMD;

typedef enum
{
	IVYIO_STREAM_VIDEO = 0,
	IVYIO_STREAM_AUDIO = 1
}IVYIO_STREAM_TYPE;

typedef enum
{
	IVYIO_STREAM_H264 = 0,
	IVYIO_STREAM_H265 = 1,
	IVYIO_STREAM_MJ = 3,
	IVYIO_STREAM_PCM = 1000,
	IVYIO_STREAM_G726 = 1001,
	IVYIO_STREAM_AAC = 1002
}IVYIO_STREAM_FMT;

typedef enum  
{
	IVYIO_DECODE_VIDEORAW,

	IVYIO_DECODE_ARGB32,	  //packed ARGB 8:8:8:8, 32bpp, ARGBARGB...
	IVYIO_DECODE_RGBA32,    //packed RGBA 8:8:8:8, 32bpp, RGBARGBA...
	IVYIO_DECODE_ABGR32,    //packed ABGR 8:8:8:8, 32bpp, ABGRABGR...
	IVYIO_DECODE_BGRA32,    //packed BGRA 8:8:8:8, 32bpp, BGRABGRA...
	IVYIO_DECODE_RGB24,	  //packed RGB 8:8:8, 24bpp, RGBRGB...
	IVYIO_DECODE_BGR24,     //packed RGB 8:8:8, 24bpp, BGRBGR...
	IVYIO_DECODE_RGB565BE,  //packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), big-endian
	IVYIO_DECODE_RGB565LE,  //packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), little-endian
	IVYIO_DECODE_BGR565BE,  //packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), big-endian
	IVYIO_DECODE_BGR565LE,  //packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), little-endian

	IVYIO_DECODE_YUV420,
	IVYIO_DECODE_YUYV422,
	IVYIO_DECODE_UYVY422,
	IVYIO_DECODE_H264,
	IVYIO_DECODE_MJPEG,	
	IVYIO_DECODE_MJPEG_BASE64,
	IVYIO_DECODE_H264_BASE64,

	IVYIO_DECODE_AUDIORAW,
	IVYIO_DECODE_G726,
	IVYIO_DECODE_G711U,
	IVYIO_DECODE_PCM,
	IVYIO_DECODE_ADPCM,
	IVYIO_DECODE_G711A,
	IVYIO_DECODE_AAC,

	IVYIO_DECODE_HEVC
} IVYIO_DECODE_FORMAT;	


typedef enum
{
	IVYIO_RAW_STREAM_CB = 0,
	IVYIO_STREAM_CB = 1
}IVYIO_STREAM_CB_TYPE;

typedef enum
{
	IVYIO_RECORD_AVI = 0,
	IVYIO_RECORD_MP4 = 1
}IVYIO_RECORD_TYPE;


// IVY common cmd
typedef enum
{
	IVYIO_CMD_GET_DEV_INFO = 118,
	IVYIO_CMD_SET_DEV_NAME,
	IVYIO_CMD_SET_FLIP_MIRROR,
	IVYIO_CMD_GET_FLIP_MIRROR,
	IVYIO_CMD_SET_COLOR,
	IVYIO_CMD_GET_COLOR,
	IVYIO_CMD_ADD_DEV
}IVYIO_CMD;


// decode format
typedef enum
{
    IVYIO_DEC_TYPE_VIDEORAW,
    
    IVYIO_DEC_TYPE_ARGB32,      //packed ARGB 8:8:8:8, 32bpp, ARGBARGB...
    IVYIO_DEC_TYPE_RGBA32,    //packed RGBA 8:8:8:8, 32bpp, RGBARGBA...
    IVYIO_DEC_TYPE_ABGR32,    //packed ABGR 8:8:8:8, 32bpp, ABGRABGR...
    IVYIO_DEC_TYPE_BGRA32,    //packed BGRA 8:8:8:8, 32bpp, BGRABGRA...
    IVYIO_DEC_TYPE_RGB24,      //packed RGB 8:8:8, 24bpp, RGBRGB...
    IVYIO_DEC_TYPE_BGR24,     //packed RGB 8:8:8, 24bpp, BGRBGR...
    IVYIO_DEC_TYPE_RGB565BE,  //packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), big-endian
    IVYIO_DEC_TYPE_RGB565LE,  //packed RGB 5:6:5, 16bpp, (msb)   5R 6G 5B(lsb), little-endian
    IVYIO_DEC_TYPE_BGR565BE,  //packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), big-endian
    IVYIO_DEC_TYPE_BGR565LE,  //packed BGR 5:6:5, 16bpp, (msb)   5B 6G 5R(lsb), little-endian
    
    IVYIO_DEC_TYPE_YUV420,
    IVYIO_DEC_TYPE_YUYV422,
    IVYIO_DEC_TYPE_UYVY422,
    IVYIO_DEC_TYPE_H264,
    IVYIO_DEC_TYPE_MJPEG,
    IVYIO_DEC_TYPE_MJPEG_BASE64,
    IVYIO_DEC_TYPE_H264_BASE64,
    
    IVYIO_DEC_TYPE_AUDIORAW,
    IVYIO_DEC_TYPE_G726,
    IVYIO_DEC_TYPE_G711U,
    IVYIO_DEC_TYPE_PCM,
    IVYIO_DEC_TYPE_ADPCM,
    IVYIO_DEC_TYPE_G711A,
    IVYIO_DEC_TYPE_AAC,
    
    IVYIO_DEC_TYPE_HEVC
}IVYIO_DECODE_FMT;



//
// struct
//

#ifndef _WIN32
	#define ATTRIBUTE_PACKED __attribute__((packed))
#else
	#define ATTRIBUTE_PACKED
	#pragma pack(push)
	#pragma pack(1)
#endif

typedef struct _IVYIO_DEVICE_NODE_
{
	unsigned int uVersion;
	unsigned int uType;
	unsigned int uIP;
	unsigned int uMask;
	unsigned int uDns;
	unsigned short usPort;
	unsigned short uDHCPEnable;
	unsigned int uState;
	char szMac[16];
	char szUid[32];
	char szName[32];
}ATTRIBUTE_PACKED IVYIO_DEV_NODE, *PIVYIO_DEV_NODE;


typedef struct _IVYIO_URL_
{
	char szUrl[256];
	unsigned short usPort;
}ATTRIBUTE_PACKED IVYIO_URL, *PIVYIO_URL;


typedef struct _IVYIO_SEEK_CMD_DATA_
{
	int iSeekType;
	int iValue;
}ATTRIBUTE_PACKED IVYIO_SEEK_CMD_DATA, *PIVYIO_SEEK_CMD_DATA;

typedef struct _IVYIO_VIDEO_INFO_
{
	unsigned int w;
	unsigned int h;
	unsigned int frameRate;
	unsigned int bitRate;
}ATTRIBUTE_PACKED IVYIO_VIDEO_INFO, *PIVYIO_VIDEO_INFO;


typedef struct _IVYIO_AUDIO_INFO_
{
	unsigned int bitsPerSample;
	unsigned int channels;
	unsigned int sample; 
}ATTRIBUTE_PACKED IVYIO_AUDIO_INFO, *PIVYIO_AUDIO_INFO;

typedef struct _IVYIO_MEDIA_DATA_
{
	unsigned int channel;
	unsigned int index;
	unsigned int iKey;

	unsigned int iFrameTag; // see FRAME_TAG_XXX_XXX
	unsigned long long pts;

	IVYIO_STREAM_TYPE type;
	IVYIO_STREAM_FMT fmt;

	union
	{
		IVYIO_VIDEO_INFO video;
		IVYIO_AUDIO_INFO audio;
	} media;

	unsigned int len;
	unsigned char data[0];
}ATTRIBUTE_PACKED IVYIO_FRAME, *PIVYIO_FRAME;

typedef struct _IVYIO_EVENT_
{
	int id;
	int iLenOfData;
	unsigned char data[IVYIO_EVENT_DATA_LEN];
}ATTRIBUTE_PACKED IVYIO_EVENT, *PIVYIO_EVENT;

typedef struct _IVYIO_CONNECT_INFO_
{
	int iP2PType;
	int iP2PMode;
	int iErrCode[IVYIO_ERROR_CODE_ARRAY_COUNT];
	int iCountOfErrCodeArray;
	unsigned long uStartTime;
	unsigned long uEndTime;
	int iLocalAddrType;
	int iRemoteAddrType;
	char szLocalInternetAddr[IVYIO_INTERNET_ADDR_LEN];
	char szRemoteInternetAddr[IVYIO_INTERNET_ADDR_LEN];
}ATTRIBUTE_PACKED IVYIO_CONNECT_INFO, *PIVYIO_CONNECT_INFO;



// XH get record list args
typedef struct _IVYIO_GET_RECORD_LIST_ARGS_TYPE1_
{
	int getRecordListArgsType;  // alway 1
	int year; // <= 0 represent no use
	int month; // <= 0 represent no use
	int day; // <= 0 represent no use
}ATTRIBUTE_PACKED IVYIO_GET_RECORD_LIST_ARGS_TYPE1, *PIVYIO_GET_RECORD_LIST_ARGS_TYPE1;

// XH response of get record list
typedef struct _IVYIO_RECORD_LIST_ARGS_TYPE1_
{
	int channel; 
	char yearMark[12]; // which year has record
	char dateMark[46]; // which date has record							
	char minuteMark[720]; // which minute has record
}ATTRIBUTE_PACKED IVYIO_RECORD_LIST_ARGS_TYPE1, *PIVYIO_RECORD_LIST_ARGS_TYPE1;


// Open playback args
typedef struct _IVYIO_OPEN_PLAY_BACK_ARGS_TYPE1_
{
	int openPlaybackArgsType; // always 1
	int year;
	int month;
	int day;
	int hour;
	int minute;
}ATTRIBUTE_PACKED IVYIO_OPEN_PLAY_BACK_ARGS_TYPE1, *PIVYIO_OPEN_PLAY_BACK_ARGS_TYPE1;


// Close playback args
typedef struct _IVYIO_CLOSE_PLAY_BACK_ARGS_TYPE1
{
	int openPlaybackArgsType; // always 1
}ATTRIBUTE_PACKED IVYIO_CLOSE_PLAY_BACK_ARGS_TYPE1, *PIVYIO_CLOSE_PLAY_BACK_ARGS_TYPE1;


// playback pause
typedef struct _IVYIO_PLAY_BACK_PAUSE_TYPE1_
{
	int openPlaybackArgsType;
}ATTRIBUTE_PACKED IVYIO_PLAY_BACK_PAUSE_TYPE1, *PIVYIO_PLAY_BACK_PAUSE_TYPE1;

// playback resume
typedef struct _IVYIO_PLAY_BACK_RESUME_TYPE1_
{
	int openPlaybackArgsType;
}ATTRIBUTE_PACKED IVYIO_PLAY_BACK_RESUME_TYPE1, *PIVYIO_PLAY_BACK_RESUME_TYPE1;

// playback seek
typedef struct _IVYIO_PLAY_BACK_SEEK_ARGS_TYPE1_
{
	int openPlaybackArgsType; 
	char date[32]; // format "2019-01-01 10:30:00"
}ATTRIBUTE_PACKED IVYIO_PLAY_BACK_SEEK_ARGS_TYPE1, *PIVYIO_PLAY_BACK_SEEK_ARGS_TYPE1;




// Open video args
typedef struct _IVYIO_OPEN_VIDEO_ARGS_TYPE0_
{
	int openVideoArgsType; // always 0
	int streamType; // 0: main stream 1: sub stream
}ATTRIBUTE_PACKED IVYIO_OPEN_VIDEO_ARGS_TYPE0, *PIVYIO_OPEN_VIDEO_ARGS_TYPE0;


// NVR get play back records list
typedef struct _IVYIO_GET_RECORD_LIST_ARGS_TYPE0_ 
{ 
	int getRecordListArgsType;    // always 0
	unsigned long long sTime; 
	unsigned long long eTime; 
	int type; 
	int startNo; 
	int cnt; 
} ATTRIBUTE_PACKED IVYIO_GET_RECORD_LIST_ARGS_TYPE0, *PIVYIO_GET_RECORD_LIST_ARGS_TYPE0;

// NVR play back records list
typedef struct _IVYIO_RECORD_INFO_TYPE0_ { 
	char channel; 
	unsigned long long sTime; 
	unsigned long long eTime; 
	unsigned int recordType; 
} ATTRIBUTE_PACKED IVYIO_RECORD_INFO_TYPE0, *PIVYIO_RECORD_INFO_TYPE0; 

// record list nvr
typedef struct _IVYIO_RECORD_LIST_ARGS_TYPE0_ 
{ 
	unsigned int totalCnt; 
	unsigned int curCnt; 
	IVYIO_RECORD_INFO_TYPE0 list[40]; 
} ATTRIBUTE_PACKED IVYIO_RECORD_LIST_ARGS_TYPE0, *PIVYIO_RECORD_LIST_ARGS_TYPE0;

// open nvr playback
typedef struct _IVYIO_OPEN_PLAY_BACK_ARGS_TYPE0_
{
	int openPlaybackArgsType; // always 0
	unsigned long long sTime; 
	unsigned long long eTime; 
	int streamType; 
}ATTRIBUTE_PACKED IVYIO_OPEN_PLAY_BACK_ARGS_TYPE0, *PIVYIO_OPEN_PLAY_BACK_ARGS_TYPE0;

typedef struct _IVYIO_CLOSE_PLAY_BACK_ARGS_TYPE0_
{
	int openPlaybackArgsType; // always 0
}ATTRIBUTE_PACKED IVYIO_CLOSE_PLAY_BACK_ARGS_TYPE0, *PIVYIO_CLOSE_PLAY_BACK_ARGS_TYPE0;

typedef struct _IVYIO_PLAY_BACK_SEEK_ARGS_TYPE0_
{
	int openPlaybackArgsType; 
	unsigned long long time;
}ATTRIBUTE_PACKED IVYIO_PLAY_BACK_SEEK_ARGS_TYPE0, *PIVYIO_PLAY_BACK_SEEK_ARGS_TYPE0;

typedef struct _IVYIO_PLAY_BACK_PAUSE_TYPE0_
{
	int openPlaybackArgsType;
}ATTRIBUTE_PACKED IVYIO_PLAY_BACK_PAUSE_TYPE0, *PIVYIO_PLAY_BACK_PAUSE_TYPE0;

typedef struct _IVYIO_PLAY_BACK_RESUME_TYPE0_
{
	int openPlaybackArgsType;
}ATTRIBUTE_PACKED IVYIO_PLAY_BACK_RESUME_TYPE0, *PIVYIO_PLAY_BACK_RESUME_TYPE0;


// download
typedef struct _IVYIO_DOWNLOAD_RECORD_
{
	unsigned int channel;
	unsigned int startTime;
	unsigned int endTime;
	unsigned int recordType;
}ATTRIBUTE_PACKED IVYIO_DOWNLOAD_RECORD, *PIVYIO_DOWNLOAD_RECORD;


// Event
typedef struct _IVYIO_EVENT_ONLINE_UPGRADE_PROCESS_
{
	int state;
	int process;
	int err;
}ATTRIBUTE_PACKED IVYIO_EVENT_ONLINE_UPGRADE_PROCESS, *PIVYIO_EVENT_ONLINE_UPGRADE_PROCESS;

typedef struct _IVYIO_EVENT_MIRROR_FLIP_
{
    int mirror;
    int flip;
}ATTRIBUTE_PACKED IVYIO_EVENT_MIRROR_FLIP, *PIVYIO_EVENT_MIRROR_FLIP;

typedef struct _IVYIO_EVENT_DAY_NIGHT_
{
    int state; // 0 off 1 on
    int mode; // 0 auto 1 manual 2 schedule
}ATTRIBUTE_PACKED IVYIO_EVENT_DAY_NIGHT, *PIVYIO_EVENT_DAY_NIGHT;

typedef struct _IVYIO_EVENT_EDGE_ARRIVE_
{
	int orientation;
}ATTRIBUTE_PACKED IVYIO_EVENT_EDGE_ARRIVE, *PIVYIO_EVENT_EDGE_ARRIVE;

typedef struct _IVYIO_EVENT_PTZ_CURRENT_CRUISE_MAP_STATE_
{
	int state;
	char name[32];
}ATTRIBUTE_PACKED IVYIO_EVENT_PTZ_CURRENT_CRUISE_MAP_STATE, *PIVYIO_EVENT_PTZ_CURRENT_CRUISE_MAP_STATE;

typedef struct _IVYIO_EVENT_START_PLAY_BACK_
{
	int result; // 0=success
	// 1=access deny
	// 2=exceed max user
	// 3=open avi file error
	int videoWidth;
	int videoHeight;
	int totalFrame;
	int totalTime;
	char reserve[32];
}ATTRIBUTE_PACKED IVYIO_EVENT_START_PLAY_BACK, *PIVYIO_EVENT_START_PLAY_BACK;

#ifdef _WIN32
	#pragma pack(pop)
#endif





//
// callback
//
typedef void (*IVYIO_FUN_STREAM_CB)(IVYIO_FRAME *, void *);
typedef int (*IVYIO_FUN_EVENT_CB)(IVYIO_EVENT *, void *);


#endif

