// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
#pragma once
#pragma warning(disable: 4100)

// TODO: プログラムに必要な追加ヘッダーをここで参照してください。
#include <windows.h>
#include <Shlwapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <mmsystem.h>
#include <deque>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "winmm.lib")

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace System::Text;
using namespace System::Drawing;
using namespace System::Net;

void WriteErrorLog(String^ text, String^ caption);
void ApplicationThreadException(Object^ sender, Threading::ThreadExceptionEventArgs^ e);
void ApplicationUnhandledException(Object^ sender, UnhandledExceptionEventArgs^ e);

void LoadMTOption();
void SaveMTOption();
void SaveProfileOption();
void CheckMTOption();
void DeleteSection(TCHAR* obj);
void ChangeStageValue();
void SetCaption();

bool IsCompatibleFM2KExecutable(String^ fileDesc);
bool IsCompatibleFM95Executable(String^ fileDesc);
bool IsCompatibleFMExecutable(String^ fileDesc);

String^ EncryptionIP(String^ ip);
String^ MTEncryptionIP(String^ ip);
_int64 DecryptionIP(String^ cipher_ip, bool enc);
_int64 MTDecryptionIP(String^ cipher_ip);

UINT CipherRand(UINT32 seed = 0);
UINT XorShift(UINT32 seed = 0);
UINT RandomStage(UINT32 seed = 0);

// メンバー情報
public ref struct MemberInfo
{
	IPEndPoint^ IP_EP;
	String^     NAME;
	String^     COMMENT;
	UINT16      ID;
	UINT        TYPE;
	UINT        STATE;
	UINT        NUM_VS;
	DWORD       RESPONSE;
};

// バックアップ
public ref struct MemberInfoBackUp
{
	IPEndPoint^ IP_EP;
	UINT16      ID;
};

// プロファイルリスト
public ref class Profile
{
	public:
		static Generic::List<String^>^ ProfileList = gcnew Generic::List<String^>;
		// バリデーション用
		static array<String^>^ SystemSection = gcnew array<String^>{"System", "State", "Color"};
};

// DEBUGGEE
// KGT2KGAME
const UINT P1_INPUT = 0x004259C0;
const UINT P2_INPUT = 0x004259C4;

const UINT SINGLE_CONTROL_HOOK = 0x00414712;
const BYTE SINGLE_CONTROL_HOOK_CODE[] = {0xCC,0x90,0x90,0x90,0x90,0x90};
const UINT VS_CONTROL_HOOK = 0x00414748;
const BYTE VS_CONTROL_HOOK_CODE[] = {0x6A,0x00};

const UINT STORY_KEY = 0x00414729;
const BYTE STORY_KEY_CODE[] = {0xCC,0x90,0x90,0x90,0x90};
const UINT VS_P1_KEY = 0x0041474A;
const BYTE VS_P1_KEY_CODE[] = {0xCC,0x90,0x90,0x90,0x90};
const UINT VS_P2_KEY = 0x00414764;
const BYTE VS_P2_KEY_CODE[] = {0xCC,0x90,0x90,0x90,0x90};

const UINT RANDOM_SEED = 0x0041FB1C;
const UINT RAND_FUNC = 0x00417A22;
const BYTE RAND_FUNC_CODE[] = {0xCC,0x90,0x90,0x90,0x90};

const UINT HIT_JUDGE = 0x0042470C;
const UINT HIT_JUDGE_SET = 0x00414C90;
const BYTE HIT_JUDGE_SET_CODE[] = {0x90,0x90,0x90,0x90,0x90,0x90};

const UINT DEFAULT_ROUND = 0x00430124;
const UINT ROUND_SET = 0x00414AFC;
const BYTE ROUND_SET_CODE[] = {0x90,0x90,0x90,0x90,0x90};

const UINT TEAM_ROUND = 0x00430128;
const UINT TEAM_ROUND_SET = 0x00414ADB;
const BYTE TEAM_ROUND_SET_CODE[] = {0x90,0x90,0x90,0x90,0x90};

const UINT DEFAULT_TIMER = 0x00430114;
const UINT TIMER_SET = 0x00414A8C;
const BYTE TIMER_SET_CODE[] = {0x90,0x90,0x90,0x90,0x90};

const UINT VS_ROUND = 0x0040897F;
const BYTE VS_ROUND_CODE[] = {0xCC};
const UINT ROUND_ESI = 0x004EDCAC;
const UINT ROUND_END = 0x00409715;
const BYTE ROUND_END_CODE[] = {0xCC,0x90,0x90,0x90,0x90,0x90};

const UINT P1_HP     = 0x004DFC85;
const UINT P1_MAX_HP = 0x004DFC91;
const UINT P1_STATE  = 0x0047033E;
const UINT P2_HP     = 0x004EDCC4;
const UINT P2_MAX_HP = 0x004EDCD0;
const UINT P2_STATE  = 0x004704BC;

const UINT STAGE_SELECT = 0x00408756;
const BYTE STAGE_SELECT_CODE[] = {0xCC,0x90,0x90,0x90,0x90};

const UINT FRAME_RATE = 0x00404C37;
const BYTE FRAME_RATE_CODE[] = {0xCC,0x90};

const UINT BGM_VOLUME = 0x0040347E;
const UINT SE_VOLUME = 0x0040348C;
const UINT VOLUME_SET_1 = 0x00403401;
const BYTE VOLUME_SET_1_CODE[] = {0x58,0x8B,0x08,0x6A,0x01,0xEB,0x0D,0x58,0x8B,0x08,0x6A,0x00,0xEB,0x06,0x90,0xE9,
                                  0xEB,0x21,0x01,0x00,0x6A,0x00,0x6A,0x00,0x50,0xFF,0x51,0x30,0x5B,0xC3};
const UINT VOLUME_SET_2 = 0x0040347B;
const BYTE VOLUME_SET_2_CODE[] = {0x50,0x8B,0x08,0xCC,0x52,0x50,0xFF,0x51,0x3C,0xE9,0x78,0xFF,0xFF,0xFF,0x50,0x8B,
                                  0x08,0xCC,0x52,0x50,0xFF,0x51,0x3C,0xE9,0x71,0xFF,0xFF,0xFF};

// KGT95GAME
const UINT P1_INPUT_95 = 0x00437750;
const UINT P2_INPUT_95 = 0x00437754;
const UINT INPUT_COUNTER_95 = 0x00437700;

const UINT UNCHECK_JOYSTICK_95 = 0x00402A33;
const BYTE UNCHECK_JOYSTICK_95_CODE[] = {0xCC,0x90,0x90,0x90,0x90};

const UINT CONTROL_HOOK1_95 = 0x0040902B;
const BYTE CONTROL_HOOK1_95_CODE[] = {0xE8,0xB0,0xFA,0xFF,0xFF};
const UINT CONTROL_HOOK2_95 = 0x00409053;
const BYTE CONTROL_HOOK2_95_CODE[] = {0xE8,0x88,0xFA,0xFF,0xFF};

const UINT STORY_P1_KEY_95 = 0x0040901C;
const BYTE STORY_P1_KEY_95_CODE[] = {0xCC,0x90,0x90,0x90,0x90,0x90};
const UINT STORY_P2_KEY_95 = 0x00409030;
const BYTE STORY_P2_KEY_95_CODE[] = {0xCC,0x90,0x90,0x90,0x90,0x90};
const UINT VS_P1_KEY_95 = 0x0040904C;
const BYTE VS_P1_KEY_95_CODE[] = {0xCC,0x90,0x90,0x90,0x90};
const UINT VS_P2_KEY_95 = 0x00409058;
const BYTE VS_P2_KEY_95_CODE[] = {0xCC,0x90,0x90,0x90,0x90};

const UINT RANDOM_SEED_95 = 0x004243FC;
const UINT RAND_FUNC_95 = 0x0041A864;
const BYTE RAND_FUNC_95_CODE[] = {0xCC,0x90,0x90,0x90,0x90};

const UINT HIT_JUDGE_95 = 0x00432740;
const UINT HIT_JUDGE_SET_95 = 0x004029E9;
const BYTE HIT_JUDGE_SET_95_CODE[] = {0x90,0x90,0x90,0x90,0x90};

const UINT DEFAULT_TIMER_95 = 0x00432754;
const UINT TIMER_SET_95 = 0x00402A68;
const BYTE TIMER_SET_95_CODE[] = {0x90,0x90,0x90,0x90,0x90};

const UINT P1_WIN_95 = 0x005E9914;
const UINT P2_WIN_95 = 0x005E9978;
const UINT VS_ROUND_95 = 0x00411661;
const BYTE VS_ROUND_95_CODE[] = {0xCC,0x90};
const UINT ROUND_END_95 = 0x00413410;
const BYTE ROUND_END_95_CODE[] = {0xCC,0x90};

const UINT STAGE_SELECT_95 = 0x0041162C;
const BYTE STAGE_SELECT_95_CODE[] = {0xCC,0x90,0x90,0x90,0x90,0x90};

const UINT FRAME_RATE_95 = 0x00404759;
const BYTE FRAME_RATE_95_CODE[] = {0xCC,0x90};

const UINT BGM_VOLUME_95 = 0x00402042;
const UINT SE_VOLUME_95 = 0x00402050;
const UINT VOLUME_SET_1_95 = 0x00401FC8;
const BYTE VOLUME_SET_1_95_CODE[] = {0x58,0x8B,0x08,0x6A,0x01,0xEB,0x16,0x90,0xE9,0xCB,0x85,0x01,0x00,0x58,0x8B,0x08,
                                     0x6A,0x00,0xEB,0x09,0x90,0x90,0x90,0x90,0xE9,0xAB,0x85,0x01,0x00,0x6A,0x00,0x6A,
                                     0x00,0x50,0xFF,0x51,0x30,0x5B,0xC3};
const UINT VOLUME_SET_2_95 = 0x0040203F;
const BYTE VOLUME_SET_2_95_CODE[] = {0x50,0x8B,0x08,0xCC,0x52,0x50,0xFF,0x51,0x3C,0xE9,0x7B,0xFF,0xFF,0xFF,0x50,0x8B,
                                     0x08,0xCC,0x52,0x50,0xFF,0x51,0x3C,0xE9,0x7A,0xFF,0xFF,0xFF};

// バージョン情報
// LilithPort 1.03以上互換, それ以前はなし
const UINT LP_VERSION = 107;

// 設定項目
const UINT MAX_NAME   = 32;
const UINT MAX_ARRAY  = 64;
const UINT MAX_ID     = 0x3FFF;
const UINT MAX_TITLE  = 256;
const UINT MAX_PACKET = 512;
const UINT MAX_WELCOME = 512;
const UINT MAX_KEYWORD = 256;
const UINT MAX_PROFILE = 2048;

const BYTE TYMT_VERSION = 6;
const UINT TIME_OUT = 3000;

// チームプレイ人数
const UINT MAX_TEAM_ROUND = 4;


typedef struct _MT_SP_INFORMATION
{
	bool   DEBUG;
	bool   RAND_SEARCH;
	bool   INITIALIZED;
	bool   SHOW_TOP;
	bool   KGT2K;
	UINT32 SEED;
	UINT32 MAX_STAGE;
	UINT32 STAGE_SELECT;
	UINT32 ROUND;
	UINT32 TIMER;
	HANDLE PROCESS;
	DWORD  PROCESS_ID;
	HWND   HWND;
	bool   CONTROL;  // 0:P1 1:P2
	TCHAR  P1_NAME[MAX_NAME];
	TCHAR  P2_NAME[MAX_NAME];
	TCHAR  ORIGINAL_TITLE[MAX_TITLE];
	TCHAR  TITLE[MAX_TITLE];
	INT32  VOLUME[21];
	bool VERSION_CHECKED;
	UINT P_HP;
	bool WINNER; // 0:P1 1:P2
	bool TEAM_ROUND_HP;
	bool SERVER_MODE;
	UINT SERVER_MODE_PORT;
	bool ERRORED;
} MT_SP_INFORMATION;

typedef struct _MT_SP_OPTION
{
	TCHAR PATH[_MAX_PATH];
	UINT  CONNECTION_TYPE;
	TCHAR SERVER_NAME[MAX_NAME];
	TCHAR CONNECTION_IP[MAX_ARRAY];
	TCHAR WELCOME[MAX_WELCOME];
	UINT  BOOKMARK_COUNT;
	UINT  BOOKMARK_DELETED_COUNT;
	TCHAR BOOKMARK_SERVER_NAME[MAX_TITLE][MAX_ARRAY];
	TCHAR BOOKMARK_CONNECTION_IP[MAX_NAME][MAX_ARRAY];
	TCHAR BOOKMARK_CONNECTION_TYPE[MAX_NAME][MAX_ARRAY];
	TCHAR BOOKMARK_PORT[MAX_NAME][MAX_ARRAY];
	TCHAR GAME_EXE[_MAX_PATH];
	TCHAR REPLAY_FOLDER[_MAX_PATH];
	TCHAR VS_SOUND[_MAX_PATH];
	bool  VS_SOUND_ENABLE;
	TCHAR NOTICE_SOUND[_MAX_PATH];
	bool  NOTICE_SOUND_ENABLE;
	TCHAR ENTER_SOUND[_MAX_PATH];
	bool  ENTER_SOUND_ENABLE;
	TCHAR NAME_SOUND[_MAX_PATH];
	bool  NAME_SOUND_ENABLE;
	TCHAR TALK_SOUND[_MAX_PATH];
	bool  TALK_SOUND_ENABLE;
	TCHAR SEEK_SOUND[_MAX_PATH];
	bool  SEEK_SOUND_ENABLE;
	TCHAR KEYWORD_SOUND[_MAX_PATH];
	bool  KEYWORD_SOUND_ENABLE;
	TCHAR KEYWORD[MAX_KEYWORD];
	TCHAR NAME[MAX_NAME];
	TCHAR COMMENT[MAX_NAME];
	UINT  PORT;
	UINT  OPEN_PORT;
	UINT  AUTO_SAVE;
	UINT  MAX_CONNECTION;
	UINT  BGM_VOLUME;
	UINT  SE_VOLUME;
	UINT  MAX_STAGE;
	UINT  STAGE_SELECT;
	UINT  ROUND;
	UINT  TIMER;
	bool  TEAM_ROUND_HP;
	UINT  SIMULATE_DELAY;
	bool  HIT_JUDGE;
	bool  DISPLAY_NAME;
	bool  DISPLAY_VERSUS;
	bool  DISPLAY_FRAMERATE;
	bool  DISPLAY_RAND;
	bool  REPLAY_DIVIDE;
	bool  CHANGE_WINDOW_SIZE;
	UINT  CHAT_HISTORY;
	UINT  DELAY;
	UINT  INTERVAL;
	UINT  REPLAY_VERSION;
	bool  RECORD_REPLAY;
	bool  ALLOW_SPECTATOR;
	bool  LOG_WORDWRAP;
	bool  LOG_LOCK;
	bool  NAME_FLASH;
	bool  TALK_FLASH;
	bool  AFTER_REST;
	bool  AUTO_REST;
	UINT  AUTO_REST_TIME;
	bool  GET_IP_ENABLE;
	bool  SHOW_GAME_OPTION;
	bool  SHOW_RESULT;
	TCHAR PROFILE[MAX_ARRAY];
	TCHAR PROFILE_LIST[MAX_PROFILE];
	UINT  PROFILE_INDEX;
} MT_SP_OPTION;

typedef struct _MT_SP_WINDOW_STATE
{
	int LEFT;
	int TOP;
	int WIDTH;
	int HEIGHT;
	int SPLITTER;
	int DIALOG_LEFT;
	int DIALOG_TOP;
} MT_SP_WINDOW_STATE;

typedef struct _MT_SP_COLOR
{
	UINT32 SERVER_NAME;
	UINT32 HOST_NAME;
	UINT32 CLIENT_NAME;
	UINT32 REST_STATE;
	UINT32 VS_STATE;
	UINT32 WATCH_STATE;
	UINT32 SEEK_STATE;
	UINT32 SYSTEM_MESSAGE;
	UINT32 ERROR_MESSAGE;
	UINT32 DEBUG_MESSAGE;
	UINT32 NOTICE_BACK;
	UINT32 COMMENT_BACK;
	UINT32 SECRET;
} MT_SP_COLOR;

typedef struct _REPLAY_DATA
{
	UINT16 KEY;
	BYTE   COUNT;
} REPLAY_DATA;

typedef struct _REPLAY_INFO
{
	TCHAR  VERSION;
	bool   CONTROL;
	UINT16 KEY[2];
	BYTE   COUNT[2];

	std::deque<REPLAY_DATA> DEQUE[2];
} REPLAY_INFO;

typedef enum {
	CT_SERVER,
	CT_HOST,
	CT_CLIENT,
	CT_FREE,
} CONNECTION_TYPE;

typedef enum {
	SM_NORMAL,
	SM_MIX,
	SM_MATCH,
	SM_NORA,
} SERVER_MODE;

typedef enum {
	MS_FREE,
	MS_REST,
	MS_VS,
	MS_WATCH,
	MS_COUCH,
	MS_READY,
	MS_SEEK,
} MEMBER_STATE;

typedef enum {
	LV_NAME,
	LV_COMMENT,
	LV_BLIND,
} LIST_VIEW;

typedef enum {
	RT_FREE = 1,
	RT_VS,
	RT_PLAYBACK,
	RT_WATCH,
} RUN_TYPE;

typedef enum {
	PH_PING,
	PH_PONG,
	PH_REQ_CONNECTION,   // 1:protocol 1:name_l n:name 1:comment_l n:comment
	PH_REQ_CONNECTION_H, // HOSTな接続要求
	PH_RES_CONNECTION,   // 1:server_name_l n:server_name 2:ID 1:name_l n:name 1:comment_l n:comment 1:state
	PH_MESSAGE,          // 2:ID 1:msg_l n:msg
	PH_NOTICE,           // 1:len n:notice
	PH_REQ_LIST,         // 2:ID 0で全員分
	PH_RES_LIST,         // 2:ID 1:name_l n:name 1:comment_l n:comment 1:state 4:IP 2:Port + 暗号
	PH_NEW_MEMBER,       // 上と同じ
	PH_QUIT,             // 2:ID
	PH_LOST,             // 2:ID
	PH_CHANGE_STATE,     // 2:ID 1:STATE
	PH_REQ_STATE,        // 2:ID
	PH_RES_STATE,        // 2:ID 1:STATE
	PH_CHANGE_COMMENT,   // 2:ID 1:comment_l n:comment
	PH_DICE,             // 1:value
	PH_REQ_VS,           // 2:ID 4:実行ファイルのハッシュ
	PH_RES_VS,           // 1:state
	PH_REQ_VS_PING,      // 1:ID 5個バラでsend
	PH_RES_VS_PONG,      // 1秒間に4個以上受信で対戦開始
	PH_REQ_VS_SETTING,   // 1:delay localとhostで大きな値にあわせる
	PH_RES_VS_SETTING,   // 1:delay 4:seed 1:max_stage 1:stage 1:round 1:timer
	PH_VS_DATA,          // 4:frame n:data 4*delay個分送信
	PH_REQ_VS_DATA,      // 4:frame パケット来てないので緊急要請
	PH_RES_VS_DATA,      // 4:frame 2:input
	PH_VS_END,
	PH_REQ_WATCH,        // 2:ID
	PH_RES_WATCH,        // 1:state 2:P1ID 2:P2ID 4:seed 1:max_stage 1:stage 1:round 1:timer  state = 0:観戦開始 1～:観戦不可
	PH_WATCH_DATA,       // 4:frame 40:10フレーム分のデータ
	PH_WATCH_END,        // 2:ID 自分のと同じIDなら観戦終了、他のIDならリストから削除
	PH_SECRET,           // 1:type n:typeごとにいろいろ
} MT_SP_PACKET_HEADER;

typedef enum {
	ST_PING,             // 4:time
	ST_PONG,
} SECRET_TYPE;

typedef enum {
	VS_REQ,
	VS_PING,
	VS_SETTING,
	VS_STANDBY,
	VS_DATA,
	VS_END,
	VS_TIMEOUT,
	VS_ERROR,
} VERSUS_SEQUENCE;

extern MT_SP_INFORMATION  MTINFO;
extern MT_SP_OPTION       MTOPTION;
extern MT_SP_WINDOW_STATE MTWS;
extern MT_SP_COLOR        MTCOLOR;

public ref class PacketPacker
{
public:
	PacketPacker(void)
	{
		Length = 0;
		Packet = gcnew array<BYTE>(MAX_PACKET);
	}

protected:
	~PacketPacker()
	{
		if(Packet != nullptr){
			delete Packet;
		}
	}

public:
	int Length;
	array<BYTE>^ Packet;

	void Pack(BYTE data){
		Packet[Length] = data;
		Length++;
	}

	void Pack(array<BYTE>^% data){
		Array::Copy(data, 0, Packet, Length, data->Length);
		Length += data->Length;
	}

	void Clear(){
		Length = 0;
		Packet->Clear(Packet, 0, MAX_PACKET);
	}
};

public ref class PacketDivider
{
public:
	int Length;
	array<BYTE>^ Packet;

	PacketDivider(array<BYTE>^% datagram)
	{
		Length = 0;
		Packet = datagram;
	}

	BYTE Divide(){
		return Packet[Length++];
	}

	array<BYTE>^ Divide(int length){
		array<BYTE>^ data = gcnew array<BYTE>(length);

		Array::Copy(Packet, Length, data, 0, length);
		Length += length;

		return data;
	}
};
