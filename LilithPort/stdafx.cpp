// stdafx.cpp : 標準インクルード LilithPort.pch のみを
// 含むソース ファイルは、プリコンパイル済みヘッダーになります。
// stdafx.obj にはプリコンパイル済み型情報が含まれます。

#include "stdafx.h"

extern CRITICAL_SECTION CS_CAPTION;
using namespace System::Collections;

// 落ちる前にエラー内容をロギング
void WriteErrorLog(String^ text, String^ caption)
{
	IO::StreamWriter^ sw = gcnew IO::StreamWriter(gcnew String(MTOPTION.PATH) + L"error.log", true, Encoding::Default);
	try{
		sw->WriteLine("-------------------------------------------------------------------------------");
		sw->WriteLine("{0} {1} [{2}]", DateTime::Now.ToLongDateString(), DateTime::Now.ToLongTimeString(), caption);
		sw->WriteLine();
		sw->Write(text);
		sw->WriteLine();
		sw->WriteLine();
		sw->WriteLine();
	}
	finally{
		if(sw != nullptr){
			sw->Close();
			delete sw;
		}
	}
}

// 例外調査
void ApplicationThreadException(Object^ sender, Threading::ThreadExceptionEventArgs^ e)
{
	WriteErrorLog(e->Exception->ToString(), "ThreadException");
	MTINFO.ERRORED = true;

	if(!MTINFO.SERVER_MODE){
		MessageBox::Show(L"An error occurred, and LilithPort must exit.\nThe exception has been written to a text file.\n"+e->Exception->ToString(), L"Unhandled thread exception");
	}

	Application::Exit();
}

// 主にコンソールアプリの例外
void ApplicationUnhandledException(Object^ sender, UnhandledExceptionEventArgs^ e)
{
	WriteErrorLog(safe_cast<Exception^>(e->ExceptionObject)->ToString(), "UnhandledException");
	MTINFO.ERRORED = true;

	if(!MTINFO.SERVER_MODE){
        MessageBox::Show(L"An error occurred, and LilithPort must exit.\nThe exception has been written to a text file.\n" + safe_cast<Exception^>(e->ExceptionObject)->ToString(), L"Unhandled exception");
	}

	Application::Exit();
}

// iniの読み込み
void LoadMTOption()
{
	IntPtr mp;
	TCHAR ini[_MAX_PATH], tmpName[MAX_TITLE], tmpIP[MAX_TITLE],
		tmpType[MAX_TITLE], tmpPort[MAX_TITLE], bufSection[MAX_ARRAY];
	TCHAR* iniSection = _T("LilithPort");
	UINT iniVersion;
	//_stprintf_s(ini, _T("%sLilithPort.ini"), MTOPTION.PATH);
	PathCombine(ini, MTOPTION.PATH, L"LilithPort.ini");
	// stdafx.hに記述
	TCHAR iniSystem[MAX_NAME], iniState[MAX_NAME], iniColor[MAX_NAME];

	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(Profile::SystemSection[0]);
	_tcscpy_s(iniSystem, static_cast<PTCHAR>(mp.ToPointer()));
	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(Profile::SystemSection[1]);
	_tcscpy_s(iniState, static_cast<PTCHAR>(mp.ToPointer()));
	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(Profile::SystemSection[2]);
	_tcscpy_s(iniColor, static_cast<PTCHAR>(mp.ToPointer()));
	Runtime::InteropServices::Marshal::FreeHGlobal(mp);

	// グローバルセクション読み込み
	// 1.04以下互換用
	iniVersion = GetPrivateProfileInt(iniSystem, _T("iniVersion"), 0, ini);
	if(iniVersion == 0){
		_tcscpy_s(iniSystem, iniSection);
	}

	if(_tcslen(MTOPTION.PROFILE) == 0){
		GetPrivateProfileString(iniSystem, _T("DefaultProfile"), _T("LilithPort"),  MTOPTION.PROFILE,        MAX_ARRAY,   ini);
	}
	GetPrivateProfileString(iniSystem, _T("ProfileList"),        _T(""),            MTOPTION.PROFILE_LIST,   MAX_PROFILE, ini);
	GetPrivateProfileString(iniSystem, _T("ServerName"),         _T(""),            MTOPTION.SERVER_NAME,    MAX_NAME,    ini);
	GetPrivateProfileString(iniSystem, _T("ConnectIP"),          _T(""),            MTOPTION.CONNECTION_IP,  MAX_ARRAY,   ini);
	GetPrivateProfileString(iniSystem, _T("Welcome"),            _T(""),            MTOPTION.WELCOME,        MAX_WELCOME, ini);
	GetPrivateProfileString(iniSystem, _T("VSSound"),            _T("vs.wav"),      MTOPTION.VS_SOUND,      _MAX_PATH,    ini);
	GetPrivateProfileString(iniSystem, _T("NoticeSound"),        _T("notice.wav"),  MTOPTION.NOTICE_SOUND,  _MAX_PATH,    ini);
	GetPrivateProfileString(iniSystem, _T("EnterSound"),         _T("enter.wav"),   MTOPTION.ENTER_SOUND,   _MAX_PATH,    ini);
	GetPrivateProfileString(iniSystem, _T("NameSound"),          _T("name.wav"),    MTOPTION.NAME_SOUND,    _MAX_PATH,    ini);
	GetPrivateProfileString(iniSystem, _T("TalkSound"),          _T("talk.wav"),    MTOPTION.TALK_SOUND,    _MAX_PATH,    ini);
	GetPrivateProfileString(iniSystem, _T("SeekSound"),          _T("seek.wav"),    MTOPTION.SEEK_SOUND,    _MAX_PATH,    ini);
	GetPrivateProfileString(iniSystem, _T("KeywordSound"),       _T("name.wav"),    MTOPTION.KEYWORD_SOUND, _MAX_PATH,    ini);
	GetPrivateProfileString(iniSystem, _T("Keyword"),            _T(""),            MTOPTION.KEYWORD,        MAX_KEYWORD, ini);
	GetPrivateProfileString(iniSystem, _T("Name"),               _T("NamelessDude"),MTOPTION.NAME,           MAX_NAME,    ini);
	GetPrivateProfileString(iniSystem, _T("Comment"),            _T(""),            MTOPTION.COMMENT,        MAX_NAME,    ini);
	MTOPTION.CONNECTION_TYPE      = GetPrivateProfileInt(iniSystem, _T("ConnectType"),          0, ini);
	MTOPTION.PORT                 = GetPrivateProfileInt(iniSystem, _T("Port"),              7500, ini);
	MTOPTION.OPEN_PORT            = GetPrivateProfileInt(iniSystem, _T("OpenPort"),          7500, ini);
	MTOPTION.AUTO_SAVE            = GetPrivateProfileInt(iniSystem, _T("AutoSave"),             0, ini);
	MTOPTION.MAX_CONNECTION       = GetPrivateProfileInt(iniSystem, _T("MaxConnection"),        1, ini);
	MTOPTION.BGM_VOLUME           = GetPrivateProfileInt(iniSystem, _T("BGMVolume"),          100, ini);
	MTOPTION.SE_VOLUME            = GetPrivateProfileInt(iniSystem, _T("SEVolume"),           100, ini);
	MTOPTION.RECORD_REPLAY        = GetPrivateProfileInt(iniSystem, _T("RecordReplay"),         0, ini) == 1 ? true : false;
	MTOPTION.ALLOW_SPECTATOR      = GetPrivateProfileInt(iniSystem, _T("AllowSpectator"),       1, ini) == 1 ? true : false;
	MTOPTION.LOG_WORDWRAP         = GetPrivateProfileInt(iniSystem, _T("LogWordWrap"),          0, ini) == 1 ? true : false;
	MTOPTION.LOG_LOCK             = GetPrivateProfileInt(iniSystem, _T("LogLock"),              0, ini) == 1 ? true : false;
	MTOPTION.NAME_FLASH           = GetPrivateProfileInt(iniSystem, _T("NameFlash"),            1, ini) == 1 ? true : false;
	MTOPTION.TALK_FLASH           = GetPrivateProfileInt(iniSystem, _T("TalkFlash"),            0, ini) == 1 ? true : false;
	MTOPTION.AFTER_REST           = GetPrivateProfileInt(iniSystem, _T("AfterRest"),            0, ini) == 1 ? true : false;
	MTOPTION.AUTO_REST            = GetPrivateProfileInt(iniSystem, _T("AutoRest"),             0, ini) == 1 ? true : false;
	MTOPTION.AUTO_REST_TIME       = GetPrivateProfileInt(iniSystem, _T("AutoRestTime"),        30, ini);
	MTOPTION.ENTER_SOUND_ENABLE   = GetPrivateProfileInt(iniSystem, _T("EnterSoundEnable"),     0, ini) == 1 ? true : false;
	MTOPTION.VS_SOUND_ENABLE      = GetPrivateProfileInt(iniSystem, _T("VSSoundEnable"),        0, ini) == 1 ? true : false;
	MTOPTION.NOTICE_SOUND_ENABLE  = GetPrivateProfileInt(iniSystem, _T("NoticeSoundEnable"),    0, ini) == 1 ? true : false;
	MTOPTION.NAME_SOUND_ENABLE    = GetPrivateProfileInt(iniSystem, _T("NameSoundEnable"),      1, ini) == 1 ? true : false;
	MTOPTION.TALK_SOUND_ENABLE    = GetPrivateProfileInt(iniSystem, _T("TalkSoundEnable"),      1, ini) == 1 ? true : false;
	MTOPTION.SEEK_SOUND_ENABLE    = GetPrivateProfileInt(iniSystem, _T("SeekSoundEnable"),      1, ini) == 1 ? true : false;
	MTOPTION.KEYWORD_SOUND_ENABLE = GetPrivateProfileInt(iniSystem, _T("KeywordSoundEnable"),   1, ini) == 1 ? true : false;
	MTOPTION.GET_IP_ENABLE        = GetPrivateProfileInt(iniSystem, _T("GetIPEnable"),          1, ini) == 1 ? true : false;
	MTOPTION.SHOW_GAME_OPTION     = GetPrivateProfileInt(iniSystem, _T("ShowGameOption"),       1, ini) == 1 ? true : false;
	MTOPTION.SHOW_RESULT          = GetPrivateProfileInt(iniSystem, _T("ShowResult"),           1, ini) == 1 ? true : false;
	
	// ブックマーク読み込み
	MTOPTION.BOOKMARK_COUNT = 0;
	GetPrivateProfileString(iniSystem, _T("BookMarkServerName"),  _T(""), tmpName, MAX_TITLE, ini);
	GetPrivateProfileString(iniSystem, _T("BookMarkConnectIP"),   _T(""), tmpIP,   MAX_TITLE, ini);
	GetPrivateProfileString(iniSystem, _T("BookMarkConnectType"), _T(""), tmpType, MAX_TITLE, ini);
	GetPrivateProfileString(iniSystem, _T("BookMarkPort"),        _T(""), tmpPort, MAX_TITLE, ini);
	try{
		if(_tcslen(tmpName) > 0){
			String^ bufBookMarkServerName    = gcnew String(tmpName);
			String^ bufBookMarkConnectIP     = gcnew String(tmpIP);
			String^ bufBookMarkConnectType, ^bufBookMarkConnectPort;
			array<String^>^ BookMarkNameList = bufBookMarkServerName->Split(',');
			array<String^>^ BookMarkIPList   = bufBookMarkConnectIP->Split(',');
			array<String^>^ BookMarkTypeList, ^BookMarkPortList;

			if(BookMarkNameList->Length != BookMarkIPList->Length){
				throw gcnew Exception;
			}
			if(_tcslen(tmpType) > 0){
				bufBookMarkConnectType   = gcnew String(tmpType);
				bufBookMarkConnectPort   = gcnew String(tmpPort);
				BookMarkTypeList         = bufBookMarkConnectType->Split(',');
				BookMarkPortList         = bufBookMarkConnectPort->Split(',');
			}
			MTOPTION.BOOKMARK_COUNT = BookMarkNameList->Length-1 < 1 ? 1 : BookMarkNameList->Length-1;
			for(UINT i=0; i < MTOPTION.BOOKMARK_COUNT; i++){
				mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(BookMarkNameList[i]);
				_tcscpy_s(MTOPTION.BOOKMARK_SERVER_NAME[i], static_cast<PTCHAR>(mp.ToPointer()));
				mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(BookMarkIPList[i]);
				_tcscpy_s(MTOPTION.BOOKMARK_CONNECTION_IP[i], static_cast<PTCHAR>(mp.ToPointer()));
				Runtime::InteropServices::Marshal::FreeHGlobal(mp);
				// 1.04以下互換用
				if(BookMarkTypeList != nullptr && BookMarkPortList != nullptr){
					mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(BookMarkTypeList[i]);
					_tcscpy_s(MTOPTION.BOOKMARK_CONNECTION_TYPE[i], static_cast<PTCHAR>(mp.ToPointer()));
					mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(BookMarkPortList[i]);
					_tcscpy_s(MTOPTION.BOOKMARK_PORT[i], static_cast<PTCHAR>(mp.ToPointer()));
					Runtime::InteropServices::Marshal::FreeHGlobal(mp);
				}else{
					// 手動初期化
					_tcscpy_s(MTOPTION.BOOKMARK_CONNECTION_TYPE[i], _T("2"));
					_tcscpy_s(MTOPTION.BOOKMARK_PORT[i],            _T("7500"));
				}
			}
		}
	}
	catch(Exception^){
		MessageBox::Show(L"Could not read bookmark information.\n", L"Bookmarks", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}

	// プロファイルリスト読み込み
	Profile::ProfileList->Clear();
	if(_tcslen(MTOPTION.PROFILE_LIST) > 0){
		String^ tmpList = gcnew String(MTOPTION.PROFILE_LIST);
		array<String^>^ tmpProfile = tmpList->Split(',');
		for(int i=0; i < tmpProfile->Length; i++){
			Profile::ProfileList->Add(tmpProfile[i]);
			// デフォルトプロファイル
			if(tmpProfile[i] == gcnew String(MTOPTION.PROFILE)){
				MTOPTION.PROFILE_INDEX = i;
				mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(tmpProfile[i]);
				_tcscpy_s(bufSection, static_cast<PTCHAR>(mp.ToPointer()));
				Runtime::InteropServices::Marshal::FreeHGlobal(mp);
				iniSection = bufSection;
			}
		}
	}else{
		// 初期化
		_tcsncpy_s(MTOPTION.PROFILE_LIST, _countof(MTOPTION.PROFILE_LIST), iniSection, MAX_PROFILE);
		Profile::ProfileList->Add(gcnew String(iniSection));
		MTOPTION.PROFILE_INDEX = 0;
	}

	// プロファイルセクション読み込み
	GetPrivateProfileString(iniSection, _T("GameExe"),            _T("game.exe"),    MTOPTION.GAME_EXE,      _MAX_PATH,    ini);
	GetPrivateProfileString(iniSection, _T("ReplayFolder"),       _T("Replay"),      MTOPTION.REPLAY_FOLDER, _MAX_PATH,    ini);
	MTOPTION.MAX_STAGE          = GetPrivateProfileInt(iniSection, _T("MaxStage"),         1, ini);
	MTOPTION.STAGE_SELECT       = GetPrivateProfileInt(iniSection, _T("StageSelect"),      0, ini);
	MTOPTION.ROUND              = GetPrivateProfileInt(iniSection, _T("Round"),            2, ini);
	MTOPTION.TIMER              = GetPrivateProfileInt(iniSection, _T("Timer"),            0, ini);
	MTOPTION.TEAM_ROUND_HP      = GetPrivateProfileInt(iniSection, _T("TeamRoundHP"),      0, ini) == 1 ? true : false;
	MTOPTION.SIMULATE_DELAY     = GetPrivateProfileInt(iniSection, _T("SimulateDelay"),    0, ini);
	MTOPTION.HIT_JUDGE          = GetPrivateProfileInt(iniSection, _T("HitJudge"),         0, ini) == 1 ? true : false;
	MTOPTION.DISPLAY_NAME       = GetPrivateProfileInt(iniSection, _T("DisplayName"),      1, ini) == 1 ? true : false;
	MTOPTION.DISPLAY_VERSUS     = GetPrivateProfileInt(iniSection, _T("DisplayVersus"),    1, ini) == 1 ? true : false;
	MTOPTION.DISPLAY_FRAMERATE  = GetPrivateProfileInt(iniSection, _T("DisplayFramerate"), 1, ini) == 1 ? true : false;
	MTOPTION.DISPLAY_RAND       = GetPrivateProfileInt(iniSection, _T("DisplayRand"),      0, ini) == 1 ? true : false;
	MTOPTION.REPLAY_DIVIDE      = GetPrivateProfileInt(iniSection, _T("ReplayDivide"),     0, ini) == 1 ? true : false;
	MTOPTION.CHANGE_WINDOW_SIZE = GetPrivateProfileInt(iniSection, _T("ChangeWindowSize"), 0, ini) == 1 ? true : false;
	MTOPTION.CHAT_HISTORY       = GetPrivateProfileInt(iniSection, _T("ChatHistory"),     20, ini);
	MTOPTION.DELAY              = GetPrivateProfileInt(iniSection, _T("Delay"),            0, ini);
	MTOPTION.INTERVAL           = GetPrivateProfileInt(iniSection, _T("Interval"),         1, ini);
	MTOPTION.REPLAY_VERSION     = GetPrivateProfileInt(iniSection, _T("ReplayVersion"),    2, ini);

	// ウィンドウ位置読み込み
	MTWS.LEFT        = GetPrivateProfileInt(iniState, _T("Left"),       0, ini);
	MTWS.TOP         = GetPrivateProfileInt(iniState, _T("Top"),        0, ini);
	MTWS.WIDTH       = GetPrivateProfileInt(iniState, _T("Width"),      0, ini);
	MTWS.HEIGHT      = GetPrivateProfileInt(iniState, _T("Height"),     0, ini);
	MTWS.SPLITTER    = GetPrivateProfileInt(iniState, _T("Splitter"),   0, ini);
	MTWS.DIALOG_LEFT = GetPrivateProfileInt(iniState, _T("DialogLeft"), 0, ini);
	MTWS.DIALOG_TOP  = GetPrivateProfileInt(iniState, _T("DialogTop"),  0, ini);

	// 色読み込み
	MTCOLOR.SERVER_NAME    = GetPrivateProfileInt(iniColor, _T("ServerName"),    Color::ForestGreen.ToArgb(), ini);
	MTCOLOR.HOST_NAME      = GetPrivateProfileInt(iniColor, _T("HostName"),      Color::MediumBlue.ToArgb(),  ini);
	MTCOLOR.CLIENT_NAME    = GetPrivateProfileInt(iniColor, _T("ClientName"),    Color::Black.ToArgb(),       ini);
	MTCOLOR.REST_STATE     = GetPrivateProfileInt(iniColor, _T("RestState"),     Color::Khaki.ToArgb(),       ini);
	MTCOLOR.VS_STATE       = GetPrivateProfileInt(iniColor, _T("VSState"),       Color::Salmon.ToArgb(),      ini);
	MTCOLOR.WATCH_STATE    = GetPrivateProfileInt(iniColor, _T("WatchState"),    Color::PaleGreen.ToArgb(),   ini);
	MTCOLOR.SEEK_STATE     = GetPrivateProfileInt(iniColor, _T("SeekState"),     Color::PowderBlue.ToArgb(),  ini);
	MTCOLOR.SYSTEM_MESSAGE = GetPrivateProfileInt(iniColor, _T("SystemMessage"), Color::Teal.ToArgb(),        ini);
	MTCOLOR.ERROR_MESSAGE  = GetPrivateProfileInt(iniColor, _T("ErrorMessage"),  Color::Red.ToArgb(),         ini);
	MTCOLOR.DEBUG_MESSAGE  = GetPrivateProfileInt(iniColor, _T("DebugMessage"),  Color::DarkOrange.ToArgb(),  ini);
	MTCOLOR.NOTICE_BACK    = GetPrivateProfileInt(iniColor, _T("NoticeBack"),    Color::PowderBlue.ToArgb(),  ini);
	MTCOLOR.COMMENT_BACK   = GetPrivateProfileInt(iniColor, _T("CommentBack"),   Color::MistyRose.ToArgb(),   ini);
	MTCOLOR.SECRET         = GetPrivateProfileInt(iniColor, _T("Secret"),        Color::HotPink.ToArgb(),     ini);

	// Welcomeのタブを改行に
	int len = _tcslen(MTOPTION.WELCOME);
	for(int i = 0; i < len; i++){
		if(MTOPTION.WELCOME[i] == _T('\t')){
			MTOPTION.WELCOME[i] = _T('\n');
		}
	}

	// 1.04以下互換用
	if(iniVersion == 0){
		DeleteSection(iniSection);
		SaveMTOption();
	}
}

// iniに書き出し
void SaveMTOption()
{
	// 改行をタブに置換
	int len = _tcslen(MTOPTION.WELCOME);
	for(int i = 0; i < len; i++){
		if(MTOPTION.WELCOME[i] == _T('\n')){
			MTOPTION.WELCOME[i] = _T('\t');
		}
	}

	IntPtr mp;
	TCHAR ini[_MAX_PATH], buf[MAX_NAME];
	TCHAR tmpStrName[MAX_TITLE] = _T("");
	TCHAR tmpStrIP[MAX_TITLE] = _T("");
	TCHAR tmpStrType[MAX_TITLE] = _T("");
	TCHAR tmpStrPort[MAX_TITLE] = _T("");
	TCHAR* iniSection = MTOPTION.PROFILE;

	// stdafx.hに記述
	TCHAR iniSystem[MAX_NAME], iniState[MAX_NAME], iniColor[MAX_NAME];
	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(Profile::SystemSection[0]);
	_tcscpy_s(iniSystem, static_cast<PTCHAR>(mp.ToPointer()));
	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(Profile::SystemSection[1]);
	_tcscpy_s(iniState, static_cast<PTCHAR>(mp.ToPointer()));
	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(Profile::SystemSection[2]);
	_tcscpy_s(iniColor, static_cast<PTCHAR>(mp.ToPointer()));
	Runtime::InteropServices::Marshal::FreeHGlobal(mp);

	//_stprintf_s(ini, _T("%sLilithPort.ini"), MTOPTION.PATH);
	PathCombine(ini, MTOPTION.PATH, L"LilithPort.ini");

	// グローバルセクション書き込み
	_itot_s(LP_VERSION, buf, 10);
	WritePrivateProfileString(iniSystem, _T("iniVersion"), buf, ini);
	_itot_s(MTOPTION.CONNECTION_TYPE, buf, 10);
	WritePrivateProfileString(iniSystem, _T("ConnectType"),          buf,                             ini);
	WritePrivateProfileString(iniSystem, _T("ServerName"),           MTOPTION.SERVER_NAME,            ini);
	WritePrivateProfileString(iniSystem, _T("ConnectIP"),            MTOPTION.CONNECTION_IP,          ini);
	WritePrivateProfileString(iniSystem, _T("Welcome"),              MTOPTION.WELCOME,                ini);
	WritePrivateProfileString(iniSystem, _T("VSSound"),              MTOPTION.VS_SOUND,               ini);
	WritePrivateProfileString(iniSystem, _T("NoticeSound"),          MTOPTION.NOTICE_SOUND,           ini);
	WritePrivateProfileString(iniSystem, _T("EnterSound"),           MTOPTION.ENTER_SOUND,            ini);
	WritePrivateProfileString(iniSystem, _T("NameSound"),            MTOPTION.NAME_SOUND,             ini);
	WritePrivateProfileString(iniSystem, _T("TalkSound"),            MTOPTION.TALK_SOUND,             ini);
	WritePrivateProfileString(iniSystem, _T("SeekSound"),            MTOPTION.SEEK_SOUND,             ini);
	WritePrivateProfileString(iniSystem, _T("KeywordSound"),         MTOPTION.KEYWORD_SOUND,          ini);
	WritePrivateProfileString(iniSystem, _T("Keyword"),              MTOPTION.KEYWORD,                ini);
	WritePrivateProfileString(iniSystem, _T("Name"),                 MTOPTION.NAME,                   ini);
	WritePrivateProfileString(iniSystem, _T("Comment"),              MTOPTION.COMMENT,                ini);

	_itot_s(MTOPTION.PORT, buf, 10);
	WritePrivateProfileString(iniSystem, _T("Port"), buf, ini);
	_itot_s(MTOPTION.OPEN_PORT, buf, 10);
	WritePrivateProfileString(iniSystem, _T("OpenPort"), buf, ini);
	_itot_s(MTOPTION.AUTO_SAVE, buf, 10);
	WritePrivateProfileString(iniSystem, _T("AutoSave"), buf, ini);
	_itot_s(MTOPTION.MAX_CONNECTION, buf, 10);
	WritePrivateProfileString(iniSystem, _T("MaxConnection"), buf, ini);
	_itot_s(MTOPTION.BGM_VOLUME, buf, 10);
	WritePrivateProfileString(iniSystem, _T("BGMVolume"), buf, ini);
	_itot_s(MTOPTION.SE_VOLUME, buf, 10);
	WritePrivateProfileString(iniSystem, _T("SEVolume"), buf, ini);
	_itot_s(MTOPTION.RECORD_REPLAY, buf, 10);
	WritePrivateProfileString(iniSystem, _T("RecordReplay"), buf, ini);
	_itot_s(MTOPTION.ALLOW_SPECTATOR, buf, 10);
	WritePrivateProfileString(iniSystem, _T("AllowSpectator"), buf, ini);
	_itot_s(MTOPTION.LOG_WORDWRAP, buf, 10);
	WritePrivateProfileString(iniSystem, _T("LogWordWrap"), buf, ini);
	_itot_s(MTOPTION.LOG_LOCK, buf, 10);
	WritePrivateProfileString(iniSystem, _T("LogLock"), buf, ini);
	_itot_s(MTOPTION.NAME_FLASH, buf, 10);
	WritePrivateProfileString(iniSystem, _T("NameFlash"), buf, ini);
	_itot_s(MTOPTION.TALK_FLASH, buf, 10);
	WritePrivateProfileString(iniSystem, _T("TalkFlash"), buf, ini);
	_itot_s(MTOPTION.AFTER_REST, buf, 10);
	WritePrivateProfileString(iniSystem, _T("AfterRest"), buf, ini);
	_itot_s(MTOPTION.AUTO_REST, buf, 10);
	WritePrivateProfileString(iniSystem, _T("AutoRest"), buf, ini);
	_itot_s(MTOPTION.AUTO_REST_TIME, buf, 10);
	WritePrivateProfileString(iniSystem, _T("AutoRestTime"), buf, ini);
	_itot_s(MTOPTION.ENTER_SOUND_ENABLE, buf, 10);
	WritePrivateProfileString(iniSystem, _T("EnterSoundEnable"), buf, ini);
	_itot_s(MTOPTION.VS_SOUND_ENABLE, buf, 10);
	WritePrivateProfileString(iniSystem, _T("VSSoundEnable"), buf, ini);
	_itot_s(MTOPTION.NOTICE_SOUND_ENABLE, buf, 10);
	WritePrivateProfileString(iniSystem, _T("NoticeSoundEnable"), buf, ini);
	_itot_s(MTOPTION.NAME_SOUND_ENABLE, buf, 10);
	WritePrivateProfileString(iniSystem, _T("NameSoundEnable"), buf, ini);
	_itot_s(MTOPTION.TALK_SOUND_ENABLE, buf, 10);
	WritePrivateProfileString(iniSystem, _T("TalkSoundEnable"), buf, ini);
	_itot_s(MTOPTION.SEEK_SOUND_ENABLE, buf, 10);
	WritePrivateProfileString(iniSystem, _T("SeekSoundEnable"), buf, ini);
	_itot_s(MTOPTION.KEYWORD_SOUND_ENABLE, buf, 10);
	WritePrivateProfileString(iniSystem, _T("KeywordSoundEnable"), buf, ini);
	_itot_s(MTOPTION.GET_IP_ENABLE, buf, 10);
	WritePrivateProfileString(iniSystem, _T("GetIPEnable"), buf, ini);
	_itot_s(MTOPTION.SHOW_GAME_OPTION, buf, 10);
	WritePrivateProfileString(iniSystem, _T("ShowGameOption"), buf, ini);
	_itot_s(MTOPTION.SHOW_RESULT, buf, 10);
	WritePrivateProfileString(iniSystem, _T("ShowResult"), buf, ini);

	// ブックマーク書き込み
	if(MTOPTION.BOOKMARK_COUNT > 0) {
		for(UINT i=0;i < MTOPTION.BOOKMARK_COUNT;i++) {
			if(gcnew String(MTOPTION.BOOKMARK_SERVER_NAME[i]) != ""){
				_stprintf_s(tmpStrName, _T("%s%s,"), tmpStrName, MTOPTION.BOOKMARK_SERVER_NAME[i]);
				_stprintf_s(tmpStrIP, _T("%s%s,"), tmpStrIP, MTOPTION.BOOKMARK_CONNECTION_IP[i]);
				_stprintf_s(tmpStrType, _T("%s%s,"), tmpStrType, MTOPTION.BOOKMARK_CONNECTION_TYPE[i]);
				_stprintf_s(tmpStrPort, _T("%s%s,"), tmpStrPort, MTOPTION.BOOKMARK_PORT[i]);
			}
		}
		WritePrivateProfileString(iniSystem, _T("BookMarkServerName"),  tmpStrName, ini);
		WritePrivateProfileString(iniSystem, _T("BookMarkConnectIP"),   tmpStrIP,   ini);
		WritePrivateProfileString(iniSystem, _T("BookMarkConnectType"), tmpStrType, ini);
		WritePrivateProfileString(iniSystem, _T("BookMarkPort"),        tmpStrPort, ini);
	}

	// プロファイルリスト書き込み
	WritePrivateProfileString(iniSystem, _T("DefaultProfile"), MTOPTION.PROFILE, ini);
	String^ bufProfileList;
	for(int i=0; i < Profile::ProfileList->Count; i++){
		if(i > 0){
			bufProfileList = String::Format(L"{0},{1}", bufProfileList, Profile::ProfileList[i]);
		}else{
			bufProfileList = String::Format(L"{0}{1}",  bufProfileList, Profile::ProfileList[i]);
		}
	}
	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(bufProfileList);
	_tcscpy_s(MTOPTION.PROFILE_LIST, static_cast<PTCHAR>(mp.ToPointer()));
	Runtime::InteropServices::Marshal::FreeHGlobal(mp);
	WritePrivateProfileString(iniSystem,  _T("ProfileList"), MTOPTION.PROFILE_LIST, ini);

	// プロファイルセクション書き込み
	WritePrivateProfileString(iniSection, _T("GameExe"),      MTOPTION.GAME_EXE,               ini);
	WritePrivateProfileString(iniSection, _T("ReplayFolder"), MTOPTION.REPLAY_FOLDER,          ini);
	_itot_s(MTOPTION.MAX_STAGE, buf, 10);
	WritePrivateProfileString(iniSection, _T("MaxStage"), buf, ini);
	_itot_s(MTOPTION.STAGE_SELECT, buf, 10);
	WritePrivateProfileString(iniSection, _T("StageSelect"), buf, ini);
	_itot_s(MTOPTION.ROUND, buf, 10);
	WritePrivateProfileString(iniSection, _T("Round"), buf, ini);
	_itot_s(MTOPTION.TIMER, buf, 10);
	WritePrivateProfileString(iniSection, _T("Timer"), buf, ini);
	_itot_s(MTOPTION.TEAM_ROUND_HP, buf, 10);
	WritePrivateProfileString(iniSection, _T("TeamRoundHP"), buf, ini);
	_itot_s(MTOPTION.SIMULATE_DELAY, buf, 10);
	WritePrivateProfileString(iniSection, _T("SimulateDelay"), buf, ini);
	_itot_s(MTOPTION.HIT_JUDGE, buf, 10);
	WritePrivateProfileString(iniSection, _T("HitJudge"), buf, ini);
	_itot_s(MTOPTION.DISPLAY_NAME, buf, 10);
	WritePrivateProfileString(iniSection, _T("DisplayName"), buf, ini);
	_itot_s(MTOPTION.DISPLAY_VERSUS, buf, 10);
	WritePrivateProfileString(iniSection, _T("DisplayVersus"), buf, ini);
	_itot_s(MTOPTION.DISPLAY_FRAMERATE, buf, 10);
	WritePrivateProfileString(iniSection, _T("DisplayFramerate"), buf, ini);
	_itot_s(MTOPTION.DISPLAY_RAND, buf, 10);
	WritePrivateProfileString(iniSection, _T("DisplayRand"), buf, ini);
	_itot_s(MTOPTION.REPLAY_DIVIDE, buf, 10);
	WritePrivateProfileString(iniSection, _T("ReplayDivide"), buf, ini);
	_itot_s(MTOPTION.CHANGE_WINDOW_SIZE, buf, 10);
	WritePrivateProfileString(iniSection, _T("ChangeWindowSize"), buf, ini);
	_itot_s(MTOPTION.CHAT_HISTORY, buf, 10);
	WritePrivateProfileString(iniSection, _T("ChatHistory"), buf, ini);
	_itot_s(MTOPTION.DELAY, buf, 10);
	WritePrivateProfileString(iniSection, _T("Delay"), buf, ini);
	_itot_s(MTOPTION.INTERVAL, buf, 10);
	WritePrivateProfileString(iniSection, _T("Interval"), buf, ini);
	_itot_s(MTOPTION.REPLAY_VERSION, buf, 10);
	WritePrivateProfileString(iniSection, _T("ReplayVersion"), buf, ini);

	// ウィンドウ位置書き込み
	_itot_s(MTWS.LEFT, buf, 10);
	WritePrivateProfileString(iniState, _T("Left"), buf, ini);
	_itot_s(MTWS.TOP, buf, 10);
	WritePrivateProfileString(iniState, _T("Top"), buf, ini);
	_itot_s(MTWS.WIDTH, buf, 10);
	WritePrivateProfileString(iniState, _T("Width"), buf, ini);
	_itot_s(MTWS.HEIGHT, buf, 10);
	WritePrivateProfileString(iniState, _T("Height"), buf, ini);
	_itot_s(MTWS.SPLITTER, buf, 10);
	WritePrivateProfileString(iniState, _T("Splitter"), buf, ini);
	_itot_s(MTWS.DIALOG_LEFT, buf, 10);
	WritePrivateProfileString(iniState, _T("DialogLeft"), buf, ini);
	_itot_s(MTWS.DIALOG_TOP, buf, 10);
	WritePrivateProfileString(iniState, _T("DialogTop"), buf, ini);

	// 色書き込み
	_ultot_s(MTCOLOR.SERVER_NAME, buf, 10);
	WritePrivateProfileString(iniColor, _T("ServerName"), buf, ini);
	_ultot_s(MTCOLOR.HOST_NAME, buf, 10);
	WritePrivateProfileString(iniColor, _T("HostName"), buf, ini);
	_ultot_s(MTCOLOR.CLIENT_NAME, buf, 10);
	WritePrivateProfileString(iniColor, _T("ClientName"), buf, ini);
	_ultot_s(MTCOLOR.REST_STATE, buf, 10);
	WritePrivateProfileString(iniColor, _T("RestState"), buf, ini);
	_ultot_s(MTCOLOR.VS_STATE, buf, 10);
	WritePrivateProfileString(iniColor, _T("VSState"), buf, ini);
	_ultot_s(MTCOLOR.WATCH_STATE, buf, 10);
	WritePrivateProfileString(iniColor, _T("WatchState"), buf, ini);
	_ultot_s(MTCOLOR.SEEK_STATE, buf, 10);
	WritePrivateProfileString(iniColor, _T("SeekState"), buf, ini);
	_ultot_s(MTCOLOR.SYSTEM_MESSAGE, buf, 10);
	WritePrivateProfileString(iniColor, _T("SystemMessage"),buf, ini);
	_ultot_s(MTCOLOR.ERROR_MESSAGE, buf, 10);
	WritePrivateProfileString(iniColor, _T("ErrorMessage"), buf, ini);
	_ultot_s(MTCOLOR.DEBUG_MESSAGE, buf, 10);
	WritePrivateProfileString(iniColor, _T("DebugMessage"), buf, ini);
	_ultot_s(MTCOLOR.NOTICE_BACK, buf, 10);
	WritePrivateProfileString(iniColor, _T("NoticeBack"), buf, ini);
	_ultot_s(MTCOLOR.COMMENT_BACK, buf, 10);
	WritePrivateProfileString(iniColor, _T("CommentBack"), buf, ini);
	_ultot_s(MTCOLOR.SECRET, buf, 10);
	WritePrivateProfileString(iniColor, _T("Secret"), buf, ini);
}
// プロファイルセクション削除
void DeleteSection(TCHAR* obj){
	TCHAR ini[_MAX_PATH];
	//_stprintf_s(ini, _T("%sLilithPort.ini"), MTOPTION.PATH);
	PathCombine(ini, MTOPTION.PATH, L"LilithPort.ini");
	WritePrivateProfileStruct(obj, NULL, NULL, 0, ini);
}
// プロファイル関連のみ書き出し
void SaveProfileOption(){
	TCHAR ini[_MAX_PATH];
	//_stprintf_s(ini, _T("%sLilithPort.ini"), MTOPTION.PATH);
	PathCombine(ini, MTOPTION.PATH, L"LilithPort.ini");

	IntPtr mp;
	TCHAR iniSystem[MAX_NAME];
	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(Profile::SystemSection[0]);
	_tcscpy_s(iniSystem, static_cast<PTCHAR>(mp.ToPointer()));

	WritePrivateProfileString(iniSystem, _T("DefaultProfile"), MTOPTION.PROFILE, ini);
	String^ bufProfileList;
	for(int i=0; i < Profile::ProfileList->Count; i++){
		if(i > 0){
			bufProfileList = String::Format(L"{0},{1}", bufProfileList, Profile::ProfileList[i]);
		}else{
			bufProfileList = String::Format(L"{0}{1}",  bufProfileList, Profile::ProfileList[i]);
		}
	}
	mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(bufProfileList);
	_tcscpy_s(MTOPTION.PROFILE_LIST, static_cast<PTCHAR>(mp.ToPointer()));
	WritePrivateProfileString(iniSystem,  _T("ProfileList"), MTOPTION.PROFILE_LIST, ini);

	Runtime::InteropServices::Marshal::FreeHGlobal(mp);
}
// 設定値を軽くチェック
void CheckMTOption()
{
	TCHAR buf[_MAX_PATH];
	// 相対パス -> 絶対パス
	_tchdir(MTOPTION.PATH);

	_tsplitpath_s(MTOPTION.GAME_EXE, NULL, 0, NULL, 0, NULL, 0, buf, _MAX_EXT);
	if(_tcscmp(buf, _T(".exe")) == 0){
		if(MTOPTION.GAME_EXE[1] != ':'){
			_tcscpy_s(buf, MTOPTION.GAME_EXE);
			_tfullpath(MTOPTION.GAME_EXE, buf, _MAX_PATH);
		}
	}
	if(MTOPTION.REPLAY_FOLDER[1] != ':'){
		_tcscpy_s(buf, MTOPTION.REPLAY_FOLDER);
		_tfullpath(MTOPTION.REPLAY_FOLDER, buf, _MAX_PATH);
	}
	if(MTOPTION.VS_SOUND[1] != ':'){
		_tcscpy_s(buf, MTOPTION.VS_SOUND);
		_tfullpath(MTOPTION.VS_SOUND, buf, _MAX_PATH);
	}
	if(MTOPTION.NOTICE_SOUND[1] != ':'){
		_tcscpy_s(buf, MTOPTION.NOTICE_SOUND);
		_tfullpath(MTOPTION.NOTICE_SOUND, buf, _MAX_PATH);
	}
	if(MTOPTION.ENTER_SOUND[1] != ':'){
		_tcscpy_s(buf, MTOPTION.ENTER_SOUND);
		_tfullpath(MTOPTION.ENTER_SOUND, buf, _MAX_PATH);
	}
	if(MTOPTION.NAME_SOUND[1] != ':'){
		_tcscpy_s(buf, MTOPTION.NAME_SOUND);
		_tfullpath(MTOPTION.NAME_SOUND, buf, _MAX_PATH);
	}
	if(MTOPTION.TALK_SOUND[1] != ':'){
		_tcscpy_s(buf, MTOPTION.TALK_SOUND);
		_tfullpath(MTOPTION.TALK_SOUND, buf, _MAX_PATH);
	}
	if(MTOPTION.SEEK_SOUND[1] != ':'){
		_tcscpy_s(buf, MTOPTION.SEEK_SOUND);
		_tfullpath(MTOPTION.SEEK_SOUND, buf, _MAX_PATH);
	}
	if(MTOPTION.KEYWORD_SOUND[1] != ':'){
		_tcscpy_s(buf, MTOPTION.KEYWORD_SOUND);
		_tfullpath(MTOPTION.KEYWORD_SOUND, buf, _MAX_PATH);
	}

	// 絶対パスに変換されるとドライブ名が小文字になるのが気になっていけない
	MTOPTION.GAME_EXE[0]      = _totupper(MTOPTION.GAME_EXE[0]);
	MTOPTION.REPLAY_FOLDER[0] = _totupper(MTOPTION.REPLAY_FOLDER[0]);
	MTOPTION.VS_SOUND[0]      = _totupper(MTOPTION.VS_SOUND[0]);
	MTOPTION.NOTICE_SOUND[0]  = _totupper(MTOPTION.NOTICE_SOUND[0]);
	MTOPTION.ENTER_SOUND[0]   = _totupper(MTOPTION.ENTER_SOUND[0]);
	MTOPTION.NAME_SOUND[0]    = _totupper(MTOPTION.NAME_SOUND[0]);
	MTOPTION.TALK_SOUND[0]    = _totupper(MTOPTION.TALK_SOUND[0]);
	MTOPTION.SEEK_SOUND[0]    = _totupper(MTOPTION.SEEK_SOUND[0]);
	MTOPTION.KEYWORD_SOUND[0] = _totupper(MTOPTION.KEYWORD_SOUND[0]);
}

// 対戦中のタイトルバー
void SetCaption()
{
	EnterCriticalSection(&CS_CAPTION);

	if(MTINFO.HWND != NULL){
		SetWindowText(MTINFO.HWND, MTINFO.TITLE);
	}
	else{
		if(MTINFO.KGT2K){
			MTINFO.HWND = FindWindow(_T("KGT2KGAME"), NULL);
		}
		else{
			MTINFO.HWND = FindWindow(_T("KGT95GAME"), NULL);
		}

		if(MTINFO.HWND != NULL){
			// 最前面表示
			if(MTINFO.SHOW_TOP == false){
				// 格ツク95ウィンドウサイズ変更
				if(MTOPTION.CHANGE_WINDOW_SIZE && MTINFO.KGT2K == false){
					RECT rc;
					SetRect(&rc, 0, 0, 640, 480);
					AdjustWindowRectEx(&rc, WS_OVERLAPPEDWINDOW, true, 0);
					SetWindowPos(MTINFO.HWND, NULL, GetSystemMetrics(SM_CXSCREEN)/2 - 320, GetSystemMetrics(SM_CYSCREEN)/2 - 240, rc.right - rc.left, rc.bottom - rc.top, 0);
				}

				SetWindowPos(MTINFO.HWND, HWND_TOPMOST,   0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE);
				SetWindowPos(MTINFO.HWND, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE);

				MTINFO.SHOW_TOP = true;
			}

			GetWindowText(MTINFO.HWND, MTINFO.ORIGINAL_TITLE, sizeof(MTINFO.ORIGINAL_TITLE));

			if(_tcslen(MTINFO.ORIGINAL_TITLE) == 0 || _tcscmp(MTINFO.ORIGINAL_TITLE, _T("２Ｄ格闘ツクール９５")) == 0){
				MTINFO.HWND = NULL;
			}
		}
	}

	LeaveCriticalSection(&CS_CAPTION);
}

bool IsCompatibleFM2KExecutable(String ^ fileDesc)
{
	return fileDesc == L"２Ｄ格闘ツクール2nd." ||
		fileDesc == L"2D Fighter Maker 2015";
}

bool IsCompatibleFM95Executable(String ^ fileDesc)
{
	return fileDesc == L"２Ｄ格闘ツクール９５";
}

bool IsCompatibleFMExecutable(String ^ fileDesc)
{
	return IsCompatibleFM2KExecutable(fileDesc) || IsCompatibleFM95Executable(fileDesc);
}

// 暗号復号用乱数
UINT CipherRand(UINT32 seed)
{
	static UINT32 a[4] = {1812433254, 3713160357, 3109174145, 64984499};

	if(seed == 0){
		UINT t = (a[0]^(a[0] << 11));

		a[0] = a[1]; a[1] = a[2]; a[2] = a[3];
		return (a[3] = (a[3]^(a[3] >> 19))^(t^(t >> 8)));
	}
	else{
		for(int i = 0; i < 4; i++){
			a[i] = seed = 1812433253*(seed^(seed >> 30)) + i;
		}
	}

	return 0;
}

// 通常用
UINT XorShift(UINT32 seed)
{
	static UINT32 a[4] = {1812433254, 3713160357, 3109174145, 64984499};

	if(seed == 0){
		UINT t = (a[0]^(a[0] << 11));

		a[0] = a[1]; a[1] = a[2]; a[2] = a[3];
		return (a[3] = (a[3]^(a[3] >> 19))^(t^(t >> 8)));
	}
	else{
		for(int i = 0; i < 4; i++){
			a[i] = seed = 1812433253*(seed^(seed >> 30)) + i;
		}
	}

	return 0;
}

// ランダムステージ用
UINT RandomStage(UINT32 seed)
{
	static UINT32 a[4] = {1812433254, 3713160357, 3109174145, 64984499};

	if(seed == 0){
		UINT t = (a[0]^(a[0] << 11));

		a[0] = a[1]; a[1] = a[2]; a[2] = a[3];
		return (a[3] = (a[3]^(a[3] >> 19))^(t^(t >> 8)));
	}
	else{
		for(int i = 0; i < 4; i++){
			a[i] = seed = 1812433253*(seed^(seed >> 30)) + i;
		}
	}

	return 0;
}


// IPのエンコード
String^ EncryptionIP(String^ ip)
{
	String ^ipString;
	try {
		ipString = Int64(Net::IPAddress::Parse(ip)->Address).ToString();
	}
	catch (ArgumentNullException^) {
		return L"IP conversion failed due to an ArgumentNullException.";
	}
	catch (FormatException^) {
		return L"IP conversion failed due to a FormatException.";
	}

	array<Byte> ^binaryData = gcnew array<Byte>(11);
	binaryData = System::Text::Encoding::ASCII->GetBytes(ipString);

	String ^ipBase64;
	try {
		ipBase64 = Convert::ToBase64String(binaryData);
	}
	catch (ArgumentNullException^) {
		return L"Null pointer trying to convert IP to Base64.";
	}
	catch (FormatException^) {
		return L"Base64 conversion failed due to a FormattingException.";
	}
	return ipBase64;
}
// IPの変換(MTSPアドレス)
String^ MTEncryptionIP(String^ ip)
{
	String^ result, ^buf, ^part;

    //DO NOT CHANGE DO NOT CHANGE
    //Strange that the dictionary is missing ひ through ん.
	String^ dic = L"そぞただちぢっつづてでとどなにぬねのはばabcdefghijklmnopqrstuvwxyz"
		L"ABCDEFGHIJKLMNOPQRSTUVWXYGぁあぃいぅうぇえぉおかがきぎくぐけげこごさざしじすずせぜ";

	try{
		// 10桁+シード
		Int64^ num = ((IPAddress::Parse(ip)->Address + 0xa68c8b5) ^ 0xe5c06811);
		ip = num->ToString();
		if((ip->Length % 2) == 1){
			ip = String::Concat("0", ip);
		}
		// 5桁にしよう
		for(int i=0; i < ip->Length; i+=2){
			part = String::Concat(ip->default[i], ip->default[i+1]);
			buf = String::Concat(dic->default[Convert::ToInt32(part)]);
			result = String::Concat(result, buf);
		}
		return result;
	}
	catch(Exception^){
		return L"MTSP conversion of the IP address failed.";
	}
}

// IPのデコード
_int64 DecryptionIP(String^ cipher_ip, bool enc)
{
	array<Byte> ^binaryData;

	try {
		binaryData = Convert::FromBase64String(cipher_ip);
	}
	catch (ArgumentNullException^) {
		throw gcnew ArgumentNullException;
		return 0;
	}
	catch (FormatException^) {
		throw gcnew FormatException;
		return 0;
	}

	if(enc){
		return Convert::ToInt64(Encoding::ASCII->GetString(binaryData));
	}else{
		// 1.02, 1.03互換用
		return Convert::ToInt64(Encoding::Unicode->GetString(binaryData));
	}
}
_int64 MTDecryptionIP(String^ cipher_ip)
{
	String^ buf;
	TCHAR part;
	int index;

    //DO NOT CHANGE DO NOT CHANGE
	String^ dic = L"そぞただちぢっつづてでとどなにぬねのはばabcdefghijklmnopqrstuvwxyz"
		L"ABCDEFGHIJKLMNOPQRSTUVWXYGぁあぃいぅうぇえぉおかがきぎくぐけげこごさざしじすずせぜ";

	try{
		for(int i=0; i < cipher_ip->Length; i++){
			part = cipher_ip->default[i];
			index = dic->IndexOf(part);
			if(index < 10){
				buf = String::Format(L"{0}0{1}", buf, index);
			}else{
				buf = String::Format(L"{0}{1}", buf, index);
			}
		}
		return ((Convert::ToInt64(buf) ^ 0xe5c06811) - 0xa68c8b5);
	}
	catch(Exception^){
		return 0;
	}
}