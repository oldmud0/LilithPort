#pragma once

#include "stdafx.h"
#include "StartupForm.h"
#include "OptionForm.h"

namespace LilithPort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Net::Sockets;
	using namespace System::Threading;
	using namespace System::Diagnostics;

	/// <summary>
	/// MainForm の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//

			// ブックマークをメニューに登録
			String^ tmpName;
			if(MTOPTION.BOOKMARK_COUNT > 0) {
				for(UINT i=0;i < MTOPTION.BOOKMARK_COUNT;i++) {
					tmpName = gcnew String(MTOPTION.BOOKMARK_SERVER_NAME[i]);
					
					toolStripMenuItemBookMark = (gcnew System::Windows::Forms::ToolStripMenuItem());
					toolStripMenuItemBookMarkMenu->DropDownItems->Add(toolStripMenuItemBookMark);
					toolStripMenuItemBookMark->Text = tmpName;
					toolStripMenuItemBookMark->Name = L"toolStripMenuItemBookMark" + i;
					toolStripMenuItemBookMark->Tag = i;
					toolStripMenuItemBookMark->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemBookMark_Click);
					
					toolStripMenuItemDelBookMark = (gcnew System::Windows::Forms::ToolStripMenuItem());
					toolStripMenuItemBookMark->DropDownItems->Add(toolStripMenuItemDelBookMark);
					toolStripMenuItemDelBookMark->Text = L"削除(&D)";
					toolStripMenuItemDelBookMark->Tag = L"toolStripMenuItemBookMark" + i;
					toolStripMenuItemDelBookMark->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelBookMark_Click);
				}
			}

			// プロファイルをコンボボックスに登録
			for(int i=0; i < Profile::ProfileList->Count; i++){
				if(Profile::ProfileList[i] == gcnew String(MTOPTION.PROFILE)){
					toolStripDropDownButtonProfile->Text = Profile::ProfileList[i];			
				}
				toolStripDropDownButtonProfile->DropDownItems->Add(Profile::ProfileList[i]);
				toolStripDropDownButtonProfile->DropDownItems[i]->Click += gcnew System::EventHandler(this, &MainForm::toolStripDropDownItemProfile_Click);
			}
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::ListBox^  listBoxMember;
	private: System::Windows::Forms::RichTextBox^  richTextBoxLog;
	private: System::Windows::Forms::TextBox^  textBoxInput;

	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemFile;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemSaveLog;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemExit;

	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemOption;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemSetting;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelayAuto;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay4;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay5;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay6;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay7;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay8;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay9;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemRecordReplay;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAllowSpectator;


	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemHelp;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemViewCommand;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemVersion;

	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStripMember;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStripLog;
	private: System::Windows::Forms::ToolStripMenuItem^  contextMenuItemCopy;

	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
	private: System::Windows::Forms::ToolStripMenuItem^  contxtMenuItemSaveLog;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemVS;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolTip^  toolTipMember;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemPing;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemReplay;

	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemWatch;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAfterRest;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemChangeList;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay10;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay11;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelay12;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemBookMarkMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAddBookMark;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemBookMark;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemDelBookMark;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator8;

	private: System::Windows::Forms::ToolStripMenuItem^  CommandToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  GameStartToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  RestartToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator9;
	private: System::Windows::Forms::ToolStripMenuItem^  LeaveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  RestToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  SeekToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ClearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator10;

private: System::Windows::Forms::ToolStripMenuItem^  ToggleHitJudgeToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  LogLockToolStripMenuItem;

private: System::Windows::Forms::ToolStripMenuItem^  GetIPToolStripMenuItem;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator11;
private: System::Windows::Forms::ToolStripMenuItem^  GameStartNoReplayToolStripMenuItem;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator12;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemKick;
private: System::Windows::Forms::StatusStrip^  statusStrip1;
private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel;

private: System::Windows::Forms::ToolStripDropDownButton^  toolStripDropDownButtonProfile;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemSeek;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRest;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestEnable;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator13;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime5;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime10;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime15;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime20;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime30;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime60;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemAutoRestTime120;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItemWordWrap;







	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::ToolStripMenuItem^  ReloadListToolStripMenuItem;
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItemFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemReplay = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemSaveLog = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemBookMarkMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAddBookMark = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator8 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->CommandToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GameStartToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->GameStartNoReplayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator9 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->RestartToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LeaveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RestToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SeekToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator10 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ClearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToggleHitJudgeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator11 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->GetIPToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemOption = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemSetting = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemDelay = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelayAuto = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemDelay2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay7 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay8 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay9 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay10 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay11 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemDelay12 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemRecordReplay = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAllowSpectator = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemWordWrap = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LogLockToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemAfterRest = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRest = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestEnable = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator13 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemAutoRestTime5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime10 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime15 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime20 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime30 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime60 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemAutoRestTime120 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemViewCommand = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemChangeList = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemVersion = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->listBoxMember = (gcnew System::Windows::Forms::ListBox());
			this->contextMenuStripMember = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItemVS = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemWatch = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemSeek = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItemPing = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator12 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuItemKick = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->richTextBoxLog = (gcnew System::Windows::Forms::RichTextBox());
			this->contextMenuStripLog = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->contextMenuItemCopy = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->contxtMenuItemSaveLog = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBoxInput = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->toolTipMember = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripDropDownButtonProfile = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->toolStripStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			ReloadListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->contextMenuStripMember->SuspendLayout();
			this->contextMenuStripLog->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ReloadListToolStripMenuItem
			// 
			ReloadListToolStripMenuItem->Name = L"ReloadListToolStripMenuItem";
			ReloadListToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F5;
			ReloadListToolStripMenuItem->Size = System::Drawing::Size(310, 22);
			ReloadListToolStripMenuItem->Text = L"メンバーリストの更新(&R)";
			ReloadListToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ReloadListToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->toolStripMenuItemFile, 
				this->toolStripMenuItemBookMarkMenu, this->CommandToolStripMenuItem, this->toolStripMenuItemOption, this->toolStripMenuItemHelp});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(528, 26);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItemFile
			// 
			this->toolStripMenuItemFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripMenuItemReplay, 
				this->toolStripMenuItemSaveLog, this->toolStripSeparator1, this->toolStripMenuItemExit});
			this->toolStripMenuItemFile->Name = L"toolStripMenuItemFile";
			this->toolStripMenuItemFile->Size = System::Drawing::Size(85, 22);
			this->toolStripMenuItemFile->Text = L"ファイル(&F)";
			// 
			// toolStripMenuItemReplay
			// 
			this->toolStripMenuItemReplay->Name = L"toolStripMenuItemReplay";
			this->toolStripMenuItemReplay->Size = System::Drawing::Size(226, 22);
			this->toolStripMenuItemReplay->Text = L"リプレイファイルの再生(&R)";
			this->toolStripMenuItemReplay->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemReplay_Click);
			// 
			// toolStripMenuItemSaveLog
			// 
			this->toolStripMenuItemSaveLog->Name = L"toolStripMenuItemSaveLog";
			this->toolStripMenuItemSaveLog->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->toolStripMenuItemSaveLog->Size = System::Drawing::Size(226, 22);
			this->toolStripMenuItemSaveLog->Text = L"ログの保存(&S)";
			this->toolStripMenuItemSaveLog->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemSaveLog_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(223, 6);
			// 
			// toolStripMenuItemExit
			// 
			this->toolStripMenuItemExit->Name = L"toolStripMenuItemExit";
			this->toolStripMenuItemExit->Size = System::Drawing::Size(226, 22);
			this->toolStripMenuItemExit->Text = L"終了(&X)";
			this->toolStripMenuItemExit->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemExit_Click);
			// 
			// toolStripMenuItemBookMarkMenu
			// 
			this->toolStripMenuItemBookMarkMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItemAddBookMark, 
				this->toolStripSeparator8});
			this->toolStripMenuItemBookMarkMenu->Name = L"toolStripMenuItemBookMarkMenu";
			this->toolStripMenuItemBookMarkMenu->Size = System::Drawing::Size(110, 22);
			this->toolStripMenuItemBookMarkMenu->Text = L"ブックマーク(&B)";
			// 
			// toolStripMenuItemAddBookMark
			// 
			this->toolStripMenuItemAddBookMark->Name = L"toolStripMenuItemAddBookMark";
			this->toolStripMenuItemAddBookMark->Size = System::Drawing::Size(166, 22);
			this->toolStripMenuItemAddBookMark->Text = L"サーバの追加(&A)";
			this->toolStripMenuItemAddBookMark->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAddBookMark_Click);
			// 
			// toolStripSeparator8
			// 
			this->toolStripSeparator8->Name = L"toolStripSeparator8";
			this->toolStripSeparator8->Size = System::Drawing::Size(163, 6);
			// 
			// CommandToolStripMenuItem
			// 
			this->CommandToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {this->GameStartToolStripMenuItem, 
				this->GameStartNoReplayToolStripMenuItem, this->toolStripSeparator9, this->RestartToolStripMenuItem, this->LeaveToolStripMenuItem, 
				this->RestToolStripMenuItem, this->SeekToolStripMenuItem, ReloadListToolStripMenuItem, this->toolStripSeparator10, this->ClearToolStripMenuItem, 
				this->ToggleHitJudgeToolStripMenuItem, this->toolStripSeparator11, this->GetIPToolStripMenuItem});
			this->CommandToolStripMenuItem->Name = L"CommandToolStripMenuItem";
			this->CommandToolStripMenuItem->Size = System::Drawing::Size(86, 22);
			this->CommandToolStripMenuItem->Text = L"コマンド(&C)";
			// 
			// GameStartToolStripMenuItem
			// 
			this->GameStartToolStripMenuItem->BackColor = System::Drawing::SystemColors::Control;
			this->GameStartToolStripMenuItem->Name = L"GameStartToolStripMenuItem";
			this->GameStartToolStripMenuItem->Size = System::Drawing::Size(310, 22);
			this->GameStartToolStripMenuItem->Text = L"ゲームの起動(&G)";
			this->GameStartToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::GameStartToolStripMenuItem_Click);
			// 
			// GameStartNoReplayToolStripMenuItem
			// 
			this->GameStartNoReplayToolStripMenuItem->Name = L"GameStartNoReplayToolStripMenuItem";
			this->GameStartNoReplayToolStripMenuItem->Size = System::Drawing::Size(310, 22);
			this->GameStartNoReplayToolStripMenuItem->Text = L"ゲームの起動（リプレイを保存しない）(&T)";
			this->GameStartNoReplayToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::GameStartNoReplayToolStripMenuItem_Click);
			// 
			// toolStripSeparator9
			// 
			this->toolStripSeparator9->Name = L"toolStripSeparator9";
			this->toolStripSeparator9->Size = System::Drawing::Size(307, 6);
			// 
			// RestartToolStripMenuItem
			// 
			this->RestartToolStripMenuItem->Name = L"RestartToolStripMenuItem";
			this->RestartToolStripMenuItem->Size = System::Drawing::Size(310, 22);
			this->RestartToolStripMenuItem->Text = L"再起動(&R)";
			this->RestartToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::RestartToolStripMenuItem_Click);
			// 
			// LeaveToolStripMenuItem
			// 
			this->LeaveToolStripMenuItem->Name = L"LeaveToolStripMenuItem";
			this->LeaveToolStripMenuItem->Size = System::Drawing::Size(310, 22);
			this->LeaveToolStripMenuItem->Text = L"退室(&L)";
			this->LeaveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::LeaveToolStripMenuItem_Click);
			// 
			// RestToolStripMenuItem
			// 
			this->RestToolStripMenuItem->Name = L"RestToolStripMenuItem";
			this->RestToolStripMenuItem->Size = System::Drawing::Size(310, 22);
			this->RestToolStripMenuItem->Text = L"休憩状態の切り替え(&M)";
			this->RestToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::RestToolStripMenuItem_Click);
			// 
			// SeekToolStripMenuItem
			// 
			this->SeekToolStripMenuItem->Name = L"SeekToolStripMenuItem";
			this->SeekToolStripMenuItem->Size = System::Drawing::Size(310, 22);
			this->SeekToolStripMenuItem->Text = L"対戦募集状態の切り替え(&S)";
			this->SeekToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::SeekToolStripMenuItem_Click);
			// 
			// toolStripSeparator10
			// 
			this->toolStripSeparator10->Name = L"toolStripSeparator10";
			this->toolStripSeparator10->Size = System::Drawing::Size(307, 6);
			// 
			// ClearToolStripMenuItem
			// 
			this->ClearToolStripMenuItem->Name = L"ClearToolStripMenuItem";
			this->ClearToolStripMenuItem->Size = System::Drawing::Size(310, 22);
			this->ClearToolStripMenuItem->Text = L"ログの削除(&C)";
			this->ClearToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ClearToolStripMenuItem_Click);
			// 
			// ToggleHitJudgeToolStripMenuItem
			// 
			this->ToggleHitJudgeToolStripMenuItem->Name = L"ToggleHitJudgeToolStripMenuItem";
			this->ToggleHitJudgeToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->ToggleHitJudgeToolStripMenuItem->Size = System::Drawing::Size(310, 22);
			this->ToggleHitJudgeToolStripMenuItem->Text = L"当たり判定の表示切替(&H)";
			this->ToggleHitJudgeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ToggleHitJudgeToolStripMenuItem_Click);
			// 
			// toolStripSeparator11
			// 
			this->toolStripSeparator11->Name = L"toolStripSeparator11";
			this->toolStripSeparator11->Size = System::Drawing::Size(307, 6);
			// 
			// GetIPToolStripMenuItem
			// 
			this->GetIPToolStripMenuItem->Name = L"GetIPToolStripMenuItem";
			this->GetIPToolStripMenuItem->Size = System::Drawing::Size(310, 22);
			this->GetIPToolStripMenuItem->Text = L"IPアドレスの取得(&I)";
			this->GetIPToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::GetIPToolStripMenuItem_Click);
			// 
			// toolStripMenuItemOption
			// 
			this->toolStripMenuItemOption->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {this->toolStripMenuItemSetting, 
				this->toolStripSeparator2, this->toolStripMenuItemDelay, this->toolStripSeparator3, this->toolStripMenuItemRecordReplay, this->toolStripMenuItemAllowSpectator, 
				this->toolStripMenuItemWordWrap, this->LogLockToolStripMenuItem, this->toolStripSeparator7, this->toolStripMenuItemAfterRest, 
				this->toolStripMenuItemAutoRest});
			this->toolStripMenuItemOption->Name = L"toolStripMenuItemOption";
			this->toolStripMenuItemOption->Size = System::Drawing::Size(99, 22);
			this->toolStripMenuItemOption->Text = L"オプション(&O)";
			// 
			// toolStripMenuItemSetting
			// 
			this->toolStripMenuItemSetting->Name = L"toolStripMenuItemSetting";
			this->toolStripMenuItemSetting->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemSetting->Text = L"設定(&S)";
			this->toolStripMenuItemSetting->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemSetting_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(244, 6);
			// 
			// toolStripMenuItemDelay
			// 
			this->toolStripMenuItemDelay->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(13) {this->toolStripMenuItemDelayAuto, 
				this->toolStripSeparator4, this->toolStripMenuItemDelay2, this->toolStripMenuItemDelay3, this->toolStripMenuItemDelay4, this->toolStripMenuItemDelay5, 
				this->toolStripMenuItemDelay6, this->toolStripMenuItemDelay7, this->toolStripMenuItemDelay8, this->toolStripMenuItemDelay9, this->toolStripMenuItemDelay10, 
				this->toolStripMenuItemDelay11, this->toolStripMenuItemDelay12});
			this->toolStripMenuItemDelay->Name = L"toolStripMenuItemDelay";
			this->toolStripMenuItemDelay->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemDelay->Text = L"ディレイ(&D)";
			// 
			// toolStripMenuItemDelayAuto
			// 
			this->toolStripMenuItemDelayAuto->Checked = true;
			this->toolStripMenuItemDelayAuto->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolStripMenuItemDelayAuto->Name = L"toolStripMenuItemDelayAuto";
			this->toolStripMenuItemDelayAuto->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItemDelayAuto->Text = L"Auto";
			this->toolStripMenuItemDelayAuto->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelayAuto_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(100, 6);
			// 
			// toolStripMenuItemDelay2
			// 
			this->toolStripMenuItemDelay2->Name = L"toolStripMenuItemDelay2";
			this->toolStripMenuItemDelay2->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItemDelay2->Text = L"2";
			this->toolStripMenuItemDelay2->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay2_Click);
			// 
			// toolStripMenuItemDelay3
			// 
			this->toolStripMenuItemDelay3->Name = L"toolStripMenuItemDelay3";
			this->toolStripMenuItemDelay3->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItemDelay3->Text = L"3";
			this->toolStripMenuItemDelay3->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay3_Click);
			// 
			// toolStripMenuItemDelay4
			// 
			this->toolStripMenuItemDelay4->Name = L"toolStripMenuItemDelay4";
			this->toolStripMenuItemDelay4->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItemDelay4->Text = L"4";
			this->toolStripMenuItemDelay4->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay4_Click);
			// 
			// toolStripMenuItemDelay5
			// 
			this->toolStripMenuItemDelay5->Name = L"toolStripMenuItemDelay5";
			this->toolStripMenuItemDelay5->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItemDelay5->Text = L"5";
			this->toolStripMenuItemDelay5->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay5_Click);
			// 
			// toolStripMenuItemDelay6
			// 
			this->toolStripMenuItemDelay6->Name = L"toolStripMenuItemDelay6";
			this->toolStripMenuItemDelay6->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItemDelay6->Text = L"6";
			this->toolStripMenuItemDelay6->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay6_Click);
			// 
			// toolStripMenuItemDelay7
			// 
			this->toolStripMenuItemDelay7->Name = L"toolStripMenuItemDelay7";
			this->toolStripMenuItemDelay7->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItemDelay7->Text = L"7";
			this->toolStripMenuItemDelay7->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay7_Click);
			// 
			// toolStripMenuItemDelay8
			// 
			this->toolStripMenuItemDelay8->Name = L"toolStripMenuItemDelay8";
			this->toolStripMenuItemDelay8->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItemDelay8->Text = L"8";
			this->toolStripMenuItemDelay8->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay8_Click);
			// 
			// toolStripMenuItemDelay9
			// 
			this->toolStripMenuItemDelay9->Name = L"toolStripMenuItemDelay9";
			this->toolStripMenuItemDelay9->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItemDelay9->Text = L"9";
			this->toolStripMenuItemDelay9->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay9_Click);
			// 
			// toolStripMenuItemDelay10
			// 
			this->toolStripMenuItemDelay10->Name = L"toolStripMenuItemDelay10";
			this->toolStripMenuItemDelay10->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItemDelay10->Text = L"10";
			this->toolStripMenuItemDelay10->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay10_Click);
			// 
			// toolStripMenuItemDelay11
			// 
			this->toolStripMenuItemDelay11->Name = L"toolStripMenuItemDelay11";
			this->toolStripMenuItemDelay11->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItemDelay11->Text = L"11";
			this->toolStripMenuItemDelay11->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay11_Click);
			// 
			// toolStripMenuItemDelay12
			// 
			this->toolStripMenuItemDelay12->Name = L"toolStripMenuItemDelay12";
			this->toolStripMenuItemDelay12->Size = System::Drawing::Size(103, 22);
			this->toolStripMenuItemDelay12->Text = L"12";
			this->toolStripMenuItemDelay12->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelay12_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(244, 6);
			// 
			// toolStripMenuItemRecordReplay
			// 
			this->toolStripMenuItemRecordReplay->Checked = true;
			this->toolStripMenuItemRecordReplay->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolStripMenuItemRecordReplay->Name = L"toolStripMenuItemRecordReplay";
			this->toolStripMenuItemRecordReplay->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemRecordReplay->Text = L"リプレイファイルの保存(&R)";
			this->toolStripMenuItemRecordReplay->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemRecordReplay_Click);
			// 
			// toolStripMenuItemAllowSpectator
			// 
			this->toolStripMenuItemAllowSpectator->Checked = true;
			this->toolStripMenuItemAllowSpectator->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolStripMenuItemAllowSpectator->Name = L"toolStripMenuItemAllowSpectator";
			this->toolStripMenuItemAllowSpectator->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemAllowSpectator->Text = L"観戦の許可(&A)";
			this->toolStripMenuItemAllowSpectator->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAllowSpectator_Click);
			// 
			// toolStripMenuItemWordWrap
			// 
			this->toolStripMenuItemWordWrap->Name = L"toolStripMenuItemWordWrap";
			this->toolStripMenuItemWordWrap->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemWordWrap->Text = L"ログのテキストを折り返す(&W)";
			this->toolStripMenuItemWordWrap->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemWordWrap_Click);
			// 
			// LogLockToolStripMenuItem
			// 
			this->LogLockToolStripMenuItem->Checked = true;
			this->LogLockToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->LogLockToolStripMenuItem->Name = L"LogLockToolStripMenuItem";
			this->LogLockToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F3;
			this->LogLockToolStripMenuItem->Size = System::Drawing::Size(247, 22);
			this->LogLockToolStripMenuItem->Text = L"ログのスクロールを固定(&L)";
			this->LogLockToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::LogLockToolStripMenuItem_Click);
			// 
			// toolStripSeparator7
			// 
			this->toolStripSeparator7->Name = L"toolStripSeparator7";
			this->toolStripSeparator7->Size = System::Drawing::Size(244, 6);
			// 
			// toolStripMenuItemAfterRest
			// 
			this->toolStripMenuItemAfterRest->Name = L"toolStripMenuItemAfterRest";
			this->toolStripMenuItemAfterRest->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemAfterRest->Text = L"ネット対戦後に一息入れる(&N)";
			this->toolStripMenuItemAfterRest->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAfterRest_Click);
			// 
			// toolStripMenuItemAutoRest
			// 
			this->toolStripMenuItemAutoRest->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {this->toolStripMenuItemAutoRestEnable, 
				this->toolStripSeparator13, this->toolStripMenuItemAutoRestTime5, this->toolStripMenuItemAutoRestTime10, this->toolStripMenuItemAutoRestTime15, 
				this->toolStripMenuItemAutoRestTime20, this->toolStripMenuItemAutoRestTime30, this->toolStripMenuItemAutoRestTime60, this->toolStripMenuItemAutoRestTime120});
			this->toolStripMenuItemAutoRest->Name = L"toolStripMenuItemAutoRest";
			this->toolStripMenuItemAutoRest->Size = System::Drawing::Size(247, 22);
			this->toolStripMenuItemAutoRest->Text = L"自動で休憩状態にする(&I)";
			// 
			// toolStripMenuItemAutoRestEnable
			// 
			this->toolStripMenuItemAutoRestEnable->Name = L"toolStripMenuItemAutoRestEnable";
			this->toolStripMenuItemAutoRestEnable->Size = System::Drawing::Size(109, 22);
			this->toolStripMenuItemAutoRestEnable->Text = L"有効";
			this->toolStripMenuItemAutoRestEnable->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestEnable_Click);
			// 
			// toolStripSeparator13
			// 
			this->toolStripSeparator13->Name = L"toolStripSeparator13";
			this->toolStripSeparator13->Size = System::Drawing::Size(106, 6);
			// 
			// toolStripMenuItemAutoRestTime5
			// 
			this->toolStripMenuItemAutoRestTime5->Name = L"toolStripMenuItemAutoRestTime5";
			this->toolStripMenuItemAutoRestTime5->Size = System::Drawing::Size(109, 22);
			this->toolStripMenuItemAutoRestTime5->Text = L"5分";
			this->toolStripMenuItemAutoRestTime5->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime5_Click);
			// 
			// toolStripMenuItemAutoRestTime10
			// 
			this->toolStripMenuItemAutoRestTime10->Name = L"toolStripMenuItemAutoRestTime10";
			this->toolStripMenuItemAutoRestTime10->Size = System::Drawing::Size(109, 22);
			this->toolStripMenuItemAutoRestTime10->Text = L"10分";
			this->toolStripMenuItemAutoRestTime10->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime10_Click);
			// 
			// toolStripMenuItemAutoRestTime15
			// 
			this->toolStripMenuItemAutoRestTime15->Name = L"toolStripMenuItemAutoRestTime15";
			this->toolStripMenuItemAutoRestTime15->Size = System::Drawing::Size(109, 22);
			this->toolStripMenuItemAutoRestTime15->Text = L"15分";
			this->toolStripMenuItemAutoRestTime15->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime15_Click);
			// 
			// toolStripMenuItemAutoRestTime20
			// 
			this->toolStripMenuItemAutoRestTime20->Name = L"toolStripMenuItemAutoRestTime20";
			this->toolStripMenuItemAutoRestTime20->Size = System::Drawing::Size(109, 22);
			this->toolStripMenuItemAutoRestTime20->Text = L"20分";
			this->toolStripMenuItemAutoRestTime20->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime20_Click);
			// 
			// toolStripMenuItemAutoRestTime30
			// 
			this->toolStripMenuItemAutoRestTime30->Name = L"toolStripMenuItemAutoRestTime30";
			this->toolStripMenuItemAutoRestTime30->Size = System::Drawing::Size(109, 22);
			this->toolStripMenuItemAutoRestTime30->Text = L"30分";
			this->toolStripMenuItemAutoRestTime30->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime30_Click);
			// 
			// toolStripMenuItemAutoRestTime60
			// 
			this->toolStripMenuItemAutoRestTime60->Name = L"toolStripMenuItemAutoRestTime60";
			this->toolStripMenuItemAutoRestTime60->Size = System::Drawing::Size(109, 22);
			this->toolStripMenuItemAutoRestTime60->Text = L"60分";
			this->toolStripMenuItemAutoRestTime60->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime60_Click);
			// 
			// toolStripMenuItemAutoRestTime120
			// 
			this->toolStripMenuItemAutoRestTime120->Name = L"toolStripMenuItemAutoRestTime120";
			this->toolStripMenuItemAutoRestTime120->Size = System::Drawing::Size(109, 22);
			this->toolStripMenuItemAutoRestTime120->Text = L"120分";
			this->toolStripMenuItemAutoRestTime120->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemAutoRestTime120_Click);
			// 
			// toolStripMenuItemHelp
			// 
			this->toolStripMenuItemHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->toolStripMenuItemViewCommand, 
				this->toolStripMenuItemChangeList, this->toolStripSeparator5, this->toolStripMenuItemVersion});
			this->toolStripMenuItemHelp->Name = L"toolStripMenuItemHelp";
			this->toolStripMenuItemHelp->ShortcutKeyDisplayString = L"Ctrl+L";
			this->toolStripMenuItemHelp->Size = System::Drawing::Size(75, 22);
			this->toolStripMenuItemHelp->Text = L"ヘルプ(&H)";
			// 
			// toolStripMenuItemViewCommand
			// 
			this->toolStripMenuItemViewCommand->Name = L"toolStripMenuItemViewCommand";
			this->toolStripMenuItemViewCommand->Size = System::Drawing::Size(211, 22);
			this->toolStripMenuItemViewCommand->Text = L"コマンドの一覧(&C)";
			this->toolStripMenuItemViewCommand->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemViewCommand_Click);
			// 
			// toolStripMenuItemChangeList
			// 
			this->toolStripMenuItemChangeList->Name = L"toolStripMenuItemChangeList";
			this->toolStripMenuItemChangeList->ShortcutKeys = System::Windows::Forms::Keys::F2;
			this->toolStripMenuItemChangeList->Size = System::Drawing::Size(211, 22);
			this->toolStripMenuItemChangeList->Text = L"リストの切り替え(&L)";
			this->toolStripMenuItemChangeList->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemChangeList_Click);
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(208, 6);
			// 
			// toolStripMenuItemVersion
			// 
			this->toolStripMenuItemVersion->Name = L"toolStripMenuItemVersion";
			this->toolStripMenuItemVersion->Size = System::Drawing::Size(211, 22);
			this->toolStripMenuItemVersion->Text = L"バージョン情報(&A)";
			this->toolStripMenuItemVersion->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemVersion_Click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitContainer1->Location = System::Drawing::Point(0, 26);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->listBoxMember);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->richTextBoxLog);
			this->splitContainer1->Panel2->Controls->Add(this->textBoxInput);
			this->splitContainer1->Size = System::Drawing::Size(528, 297);
			this->splitContainer1->SplitterDistance = 90;
			this->splitContainer1->TabIndex = 2;
			this->splitContainer1->TabStop = false;
			// 
			// listBoxMember
			// 
			this->listBoxMember->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBoxMember->ContextMenuStrip = this->contextMenuStripMember;
			this->listBoxMember->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBoxMember->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawFixed;
			this->listBoxMember->FormattingEnabled = true;
			this->listBoxMember->ItemHeight = 12;
			this->listBoxMember->Location = System::Drawing::Point(0, 0);
			this->listBoxMember->Name = L"listBoxMember";
			this->listBoxMember->Size = System::Drawing::Size(88, 288);
			this->listBoxMember->TabIndex = 2;
			this->listBoxMember->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::listBoxMember_MouseDoubleClick);
			this->listBoxMember->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &MainForm::listBoxMember_DrawItem);
			this->listBoxMember->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::listBoxMember_MouseClick);
			// 
			// contextMenuStripMember
			// 
			this->contextMenuStripMember->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->toolStripMenuItemVS, 
				this->toolStripMenuItemWatch, this->toolStripMenuItemSeek, this->toolStripMenuItemPing, this->toolStripSeparator12, this->toolStripMenuItemKick});
			this->contextMenuStripMember->Name = L"contextMenuStrip1";
			this->contextMenuStripMember->ShowImageMargin = false;
			this->contextMenuStripMember->Size = System::Drawing::Size(124, 120);
			this->contextMenuStripMember->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::contextMenuStripMember_Opening);
			// 
			// toolStripMenuItemVS
			// 
			this->toolStripMenuItemVS->Name = L"toolStripMenuItemVS";
			this->toolStripMenuItemVS->Size = System::Drawing::Size(123, 22);
			this->toolStripMenuItemVS->Text = L"対戦する";
			this->toolStripMenuItemVS->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemVS_Click);
			// 
			// toolStripMenuItemWatch
			// 
			this->toolStripMenuItemWatch->Name = L"toolStripMenuItemWatch";
			this->toolStripMenuItemWatch->Size = System::Drawing::Size(123, 22);
			this->toolStripMenuItemWatch->Text = L"観戦する";
			this->toolStripMenuItemWatch->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemWatch_Click);
			// 
			// toolStripMenuItemSeek
			// 
			this->toolStripMenuItemSeek->Name = L"toolStripMenuItemSeek";
			this->toolStripMenuItemSeek->Size = System::Drawing::Size(123, 22);
			this->toolStripMenuItemSeek->Text = L"対戦募集する";
			this->toolStripMenuItemSeek->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemSeek_Click);
			// 
			// toolStripMenuItemPing
			// 
			this->toolStripMenuItemPing->Name = L"toolStripMenuItemPing";
			this->toolStripMenuItemPing->Size = System::Drawing::Size(123, 22);
			this->toolStripMenuItemPing->Text = L"PING";
			this->toolStripMenuItemPing->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemPing_Click);
			// 
			// toolStripSeparator12
			// 
			this->toolStripSeparator12->Name = L"toolStripSeparator12";
			this->toolStripSeparator12->Size = System::Drawing::Size(120, 6);
			// 
			// toolStripMenuItemKick
			// 
			this->toolStripMenuItemKick->Name = L"toolStripMenuItemKick";
			this->toolStripMenuItemKick->Size = System::Drawing::Size(123, 22);
			this->toolStripMenuItemKick->Text = L"KICK";
			this->toolStripMenuItemKick->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemKick_Click);
			// 
			// richTextBoxLog
			// 
			this->richTextBoxLog->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBoxLog->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBoxLog->ContextMenuStrip = this->contextMenuStripLog;
			this->richTextBoxLog->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBoxLog->Location = System::Drawing::Point(0, 0);
			this->richTextBoxLog->Name = L"richTextBoxLog";
			this->richTextBoxLog->ReadOnly = true;
			this->richTextBoxLog->Size = System::Drawing::Size(432, 276);
			this->richTextBoxLog->TabIndex = 0;
			this->richTextBoxLog->TabStop = false;
			this->richTextBoxLog->Text = L"";
			this->richTextBoxLog->WordWrap = false;
			this->richTextBoxLog->LinkClicked += gcnew System::Windows::Forms::LinkClickedEventHandler(this, &MainForm::richTextBoxLog_LinkClicked);
			// 
			// contextMenuStripLog
			// 
			this->contextMenuStripLog->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->contextMenuItemCopy, 
				this->toolStripSeparator6, this->contxtMenuItemSaveLog});
			this->contextMenuStripLog->Name = L"contextMenuStrip2";
			this->contextMenuStripLog->ShowImageMargin = false;
			this->contextMenuStripLog->Size = System::Drawing::Size(177, 54);
			// 
			// contextMenuItemCopy
			// 
			this->contextMenuItemCopy->Name = L"contextMenuItemCopy";
			this->contextMenuItemCopy->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->contextMenuItemCopy->Size = System::Drawing::Size(176, 22);
			this->contextMenuItemCopy->Text = L"コピー(&C)";
			this->contextMenuItemCopy->Click += gcnew System::EventHandler(this, &MainForm::contextMenuItemCopy_Click);
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(173, 6);
			// 
			// contxtMenuItemSaveLog
			// 
			this->contxtMenuItemSaveLog->Name = L"contxtMenuItemSaveLog";
			this->contxtMenuItemSaveLog->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->contxtMenuItemSaveLog->Size = System::Drawing::Size(176, 22);
			this->contxtMenuItemSaveLog->Text = L"ログの保存(&S)";
			this->contxtMenuItemSaveLog->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemSaveLog_Click);
			// 
			// textBoxInput
			// 
			this->textBoxInput->BackColor = System::Drawing::SystemColors::Window;
			this->textBoxInput->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->textBoxInput->Location = System::Drawing::Point(0, 276);
			this->textBoxInput->MaxLength = 127;
			this->textBoxInput->Name = L"textBoxInput";
			this->textBoxInput->Size = System::Drawing::Size(432, 19);
			this->textBoxInput->TabIndex = 0;
			this->textBoxInput->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::textBoxInput_KeyDown);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"MT Replay file (*.mtr)|*.mtr";
			this->openFileDialog1->Title = L"LilithPort用のリプレイファイル";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripDropDownButtonProfile, 
				this->toolStripStatusLabel});
			this->statusStrip1->Location = System::Drawing::Point(0, 328);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->statusStrip1->Size = System::Drawing::Size(528, 22);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripDropDownButtonProfile
			// 
			this->toolStripDropDownButtonProfile->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->toolStripDropDownButtonProfile->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripDropDownButtonProfile->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
			this->toolStripDropDownButtonProfile->Name = L"toolStripDropDownButtonProfile";
			this->toolStripDropDownButtonProfile->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->toolStripDropDownButtonProfile->Size = System::Drawing::Size(13, 20);
			// 
			// toolStripStatusLabel
			// 
			this->toolStripStatusLabel->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Left;
			this->toolStripStatusLabel->BorderStyle = System::Windows::Forms::Border3DStyle::Raised;
			this->toolStripStatusLabel->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripStatusLabel->Margin = System::Windows::Forms::Padding(5, 3, 0, 2);
			this->toolStripStatusLabel->Name = L"toolStripStatusLabel";
			this->toolStripStatusLabel->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
			this->toolStripStatusLabel->Size = System::Drawing::Size(9, 17);
			// 
			// MainForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 350);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"LilithPort";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Shown += gcnew System::EventHandler(this, &MainForm::MainForm_Shown);
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::MainForm_DragDrop);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MainForm::MainForm_DragEnter);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			this->splitContainer1->ResumeLayout(false);
			this->contextMenuStripMember->ResumeLayout(false);
			this->contextMenuStripLog->ResumeLayout(false);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		static OptionForm^ Option;

		static bool IsFormClosing;
		static SERVER_MODE ServerMode;
		static LIST_VIEW ListView;
		static String^ ReplayFilePath;

		// ブックマーク
		Object^ tmpIP;
		IntPtr BookMarkServerName;
		IntPtr BookMarkConnectIP;

		// チャット履歴
		static int ChatHistoryNumber;
		static Generic::List<String^>^ ChatHistory;

		// 各色
		static array<Color>^ NameColor;
		static array<Color>^ StateRectColor;
		static Color TalkMessageColor;
		static Color SystemMessageColor;
		static Color ErrorMessageColor;
		static Color DebugMessageColor;
		static Color NoticeBackColor;
		static Color CommentBackColor;
		static Color SecretColor;

		delegate void WriteMessageDelegate(String^ msg, Color color);

		// MemberInfoさんはstdafx.hにお引越ししました
		static Generic::List<MemberInfo^>^ MemberList;
		static Generic::List<MemberInfoBackUp^>^ MemberListBackUp;
		static UINT16 IDCounter; // Max 3FFF(16383)
		static DWORD Ping;

		static Thread^ GameThread;
		static UdpClient^ UDP;
		static String^ ServerName;
		static String^ ConnectIP;
		static bool AfterCloseUDP; // 対戦中の鯖落ちに巻き込まれないように

		// IP取得用
		static WebClient^ GetIPClient;
		static Uri^ GetIPUri = gcnew Uri("http://checkip.dyndns.org/");
		static Thread^ TimerGetIPThread;
		static bool    GetIPCancelled;
		static bool    GetIPSleeping;

		// チームHP持ち越し用
		static Thread^ SetTeamHPThread;
		static UINT P_HP;
		static UINT Winner;

		// 回線の生死判定
		static Thread^ SonarThread;
		static bool    Ranging;
		static bool    SonarSleeping;

		// ネット対戦関連
		ref struct VersusInfo
		{
			UINT           SEQUENCE;  // やり取り同期用
			bool           SLEEPING;  // スレッド待機用
			int            WAITING;   // パケ受信待機用 1-:Wait ON 2:Sleep
			DWORD          START_UP;  // 起動時間
			IPEndPoint^    IP_EP;
			array<UINT>^   PING;
			array<UINT>^   PONG;
			UINT           DELAY;     // ディレイは大きい方に合わせる
			UINT           INTERVAL;  // 送信間隔 小:1fあたりの入力データ送信回数を4に 中:3回 大:2回
			UINT           INTERVAL2; // 送信間隔計算用
			array<BYTE>^   SEND;      // 送信用バッファ
			array<UINT16>^ LOCAL;     // リングバッファ
			UINT32         L_FRAME;   // 総フレーム数
			int            L_READ;    // 読み取り位置
			array<UINT16>^ REMOTE;    // この２つはキーの履歴を保持する
			UINT32         R_FRAME;   // 総フレーム数
			int            R_READ;    // 読み取り位置
		};

		static Thread^ VersusThread;
		static VersusInfo^ NetVS;

		// 観戦関連
		ref struct SpectatorInfo
		{
			UINT16      ID;
			IPEndPoint^ IP_EP;
			UINT32      FRAME;
		};

		static Thread^ SpectacleThread;
		static Generic::List<SpectatorInfo^>^ SpectatorList;
		static bool           AllowWatch;      // スレッド制御
		static UINT           WaitingWatch;    // パケット待ち 1:開始待ち 2:データ待ち
		static IPEndPoint^    WatchTarget;     // 観戦対象
		static UINT16         TargetID;
		static UINT16         P1ID, P2ID;      // P2が0xFFFFで一人プレイ
		static UINT32         WatchFrame;      // 読み取り位置
		static array<UINT16>^ WatchHistory;    // バッファ TIME_OUT/5 * 3 = 1800の900フレーム分
		static UINT32         InputFrame;      // 書き込み位置
		static array<UINT16>^ InputHistory;    // バッファ

		// 自動休憩
		static Thread^ AutoRestThread;
		static bool AutoRestRanging;
		static bool AutoRestSleeping;

		// MainForm.cppに記述
		void Begin();
		void TimerGetIP();
		void SetTeamHP();
		void RunSonar();
		void RunGame(Object^ obj);
		void RunVersus();
		void RunSpectacle();
		UINT16 LocalInput(UINT16 eax);
		UINT16 RemoteInput();
		UINT16 ReadReplayData(BinaryReader^ br, REPLAY_INFO& ri);
		void RecordInput(UINT16 eax, BinaryWriter^ bw, REPLAY_INFO& ri, bool as);
		void RunAutoRest();
		void ChangeSeek();
		void ChangeLogWordWrap();
		void ClearLog();

		void PacketSendAllMember(array<BYTE>^% datagram, UINT received_id);
		static void SendPackets(IAsyncResult^ asyncResult);
		static void ReceivePackets(IAsyncResult^ asyncResult);

	protected:
		void StartGame(UINT type){
			// 格ツクじゃないよ
			try{
				FileVersionInfo^ info = FileVersionInfo::GetVersionInfo(gcnew String(MTOPTION.GAME_EXE));

				if(info->FileDescription != "２Ｄ格闘ツクール2nd." && info->FileDescription != "２Ｄ格闘ツクール９５"){
					throw gcnew Exception;
				}
				else{
					if(info->FileDescription == "２Ｄ格闘ツクール2nd."){
						MTINFO.KGT2K = true;
					}
					else{
						MTINFO.KGT2K = false;
					}
				}
			}
			catch(Exception^){
				WriteMessage("格闘ツクールの実行ファイルではありません。\n", ErrorMessageColor);
				WriteMessage("オプションで実行ファイルのパスを設定してください。\n", ErrorMessageColor);
				return;
			}

			if(MemberList[0]->STATE == MS_SEEK){
				QuitGame();
				GameThread = nullptr;
				//Thread::Sleep(1000);
			}

			if(GameThread != nullptr && GameThread->IsAlive == false){
				GameThread = nullptr;
			}

			if(VersusThread != nullptr && VersusThread->IsAlive == false){
				VersusThread = nullptr;
			}

			if(NetVS != nullptr && MemberList[0]->STATE == MS_READY){
				if((timeGetTime() - NetVS->START_UP) > TIME_OUT*2 + 1000){
					MemberList[0]->STATE = MS_FREE;
					delete NetVS;
					NetVS = nullptr;
				}
			}

			if(GameThread == nullptr){
				ZeroMemory(MTINFO.P1_NAME, sizeof(MTINFO.P1_NAME));
				ZeroMemory(MTINFO.P2_NAME, sizeof(MTINFO.P2_NAME));

				if(type == RT_FREE){
					MTINFO.SEED          = XorShift();
					MTINFO.MAX_STAGE     = MTOPTION.MAX_STAGE;
					MTINFO.STAGE_SELECT  = MTOPTION.STAGE_SELECT;
					MTINFO.ROUND         = MTOPTION.ROUND;
					MTINFO.TIMER         = MTOPTION.TIMER;
					MTINFO.TEAM_ROUND_HP = MTOPTION.TEAM_ROUND_HP;

					P1ID = MemberList[0]->ID;
					P2ID = 0xFFFF;

					_tcscpy_s(MTINFO.P1_NAME, MTOPTION.NAME);
					MTINFO.CONTROL = 0;
				}
				else if(type == RT_VS){
					Monitor::Enter(MemberList);
					try{
						MemberList[0]->STATE = MS_READY;

						NetVS = gcnew VersusInfo;
						NetVS->SEQUENCE = VS_REQ;
						NetVS->SLEEPING = false;
						NetVS->WAITING  = false;
						NetVS->START_UP = timeGetTime();
						NetVS->IP_EP    = MemberList[listBoxMember->SelectedIndex]->IP_EP;
						NetVS->PING     = gcnew array<UINT>(5){ 0, 0, 0, 0, 0 };
						NetVS->PONG     = gcnew array<UINT>(5){ 0, 0, 0, 0, 0 };
						NetVS->SEND     = gcnew array<BYTE>(32){ PH_VS_DATA };
						NetVS->L_FRAME  = 0;
						NetVS->L_READ   = 0;
						NetVS->R_FRAME  = 0;
						NetVS->L_READ   = 0;

						// 観戦用ID
						P1ID = MemberList[listBoxMember->SelectedIndex]->ID;
						P2ID = MemberList[0]->ID;

						// 名前
						ZeroMemory(MTINFO.P1_NAME, sizeof(MTINFO.P1_NAME));
						ZeroMemory(MTINFO.P2_NAME, sizeof(MTINFO.P2_NAME));

						if(ListView != LV_BLIND){
							IntPtr mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(MemberList[listBoxMember->SelectedIndex]->NAME);
							_tcscpy_s(MTINFO.P1_NAME, static_cast<PTCHAR>(mp.ToPointer()));
							Runtime::InteropServices::Marshal::FreeHGlobal(mp);

							_tcscpy_s(MTINFO.P2_NAME, MTOPTION.NAME);
						}

						// 対戦回数
						MemberList[listBoxMember->SelectedIndex]->NUM_VS++;

						// ネット対戦準備用スレッドの起動
						MTINFO.CONTROL = 1;
						VersusThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::RunVersus));
						VersusThread->Start();
					}
					finally{
						Monitor::Exit(MemberList);
					}
					return;
				}
				else if(type == RT_PLAYBACK){
					if(ReplayFilePath == String::Empty){
						openFileDialog1->InitialDirectory = gcnew String(MTOPTION.REPLAY_FOLDER);

						if(openFileDialog1->ShowDialog() == ::DialogResult::OK){
							ReplayFilePath = openFileDialog1->FileName;
						}
						else{
							return;
						}
					}

					// フォーマットの確認
					TCHAR ver;
					array<TCHAR>^ header = gcnew array<TCHAR>{'T', 'Y', 'M', 'T', 'R'};
					BinaryReader^ br = gcnew BinaryReader(File::OpenRead(ReplayFilePath));

					try{
						// ヘッダ
						array<TCHAR>^ h = br->ReadChars(header->Length);
						for(int i = 0; i < h->Length; i++){
							if(h[i] != header[i]){
								WriteMessage("有効なリプレイファイルではありません。\n", ErrorMessageColor);
								return;
							}
						}

						ver = br->ReadChar();

						if(ver < _T('1') || ver > _T('4')){
							WriteMessage("有効なリプレイのバージョンではありません。\n", ErrorMessageColor);
							return;
						}
					}
					finally{
						br->Close();
					}
				}

				GameThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &MainForm::RunGame));
				GameThread->Start(type);
			}
			else{
				if(_tcslen(MTINFO.ORIGINAL_TITLE) > 0){
					WriteMessage(String::Format("{0}が起動中です。\n", gcnew String(MTINFO.ORIGINAL_TITLE)), SystemMessageColor);
				}
				else{
					WriteMessage("他のゲームが起動中です。\n", SystemMessageColor);
				}
			}
		}

		void QuitGame(){
			if(GameThread != nullptr && GameThread->IsAlive){
				if(MTINFO.DEBUG){
					WriteMessage("ゲームプロセスを停止します。\n", DebugMessageColor);
				}
				try{
					Process::GetProcessById(MTINFO.PROCESS_ID)->CloseMainWindow();
				}
				catch(ArgumentException^){
					if(MTINFO.DEBUG){
						WriteMessage("例外 > ArgumentException\n", DebugMessageColor);
					}
					GameThread->Abort();
					GameThread = nullptr;
				}
			}
			/*
			if(GameThread == nullptr){
				try{
					String^ game = Path::GetFileNameWithoutExtension(gcnew String(MTOPTION.GAME_EXE));
					array<Process^>^ ps = Process::GetProcessesByName(game);
					if(ps->Length > 0){
						for(int i=0; i < ps->Length; i++){
							if(ps[0]->MainWindowTitle == game){
								WriteMessage(String::Format("{0}を終了します。\n", ps[0]->MainWindowTitle), SystemMessageColor);
								ps[0]->CloseMainWindow();
							}
						}
					}else{
						WriteMessage(String::Format("終了するゲーム\"{0}\"が見つかりませんでした。\nオプションの実行ファイルのパス、またはプロファイルが合っているか確認してください。\n", game), ErrorMessageColor);
						return;
					}
				}
				catch(Exception^ e){
					WriteMessage("ゲームを終了できませんでした。\n", ErrorMessageColor);
					if(MTINFO.DEBUG){
						WriteMessage(String::Format("{0}\n", e->ToString()), DebugMessageColor);
					}
				}
			}
			*/
		}

		void QuitWatch(bool send_packet){
			if(WaitingWatch > 0 && GameThread != nullptr && GameThread->IsAlive){
				bool w = WaitingWatch == 2 ? true : false;
				WaitingWatch = 0;

				if(w){
					Monitor::Enter(WatchHistory);
					try{
						Monitor::Pulse(WatchHistory);
					}
					finally{
						Monitor::Exit(WatchHistory);
					}
				}

				QuitGame();
			}

			if(WatchTarget != nullptr && UDP != nullptr){
				if(send_packet){
					array<BYTE>^ quit = gcnew array<BYTE>(3){ PH_WATCH_END };
					Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, quit, 1, 2);
					UDP->BeginSend(quit, quit->Length, WatchTarget, gcnew AsyncCallback(SendPackets), UDP);
				}

				delete WatchTarget;
				WatchTarget = nullptr;
			}

			int state = MemberList[0]->STATE;

			if(state == MS_WATCH) ChangeState((BYTE)MS_FREE);
			if(state == MS_COUCH) ChangeState((BYTE)MS_REST);

			toolStripMenuItemWatch->Text = gcnew String("観戦する");
		}

		void Restart(){
			// フリープレイだけど対戦中
			if(AfterCloseUDP) return;

			CloseUdp(true);

			MemberList->Clear();
			listBoxMember->Items->Clear();

			// IP取得のキャンセル
			if(GetIPClient != nullptr){
				GetIPClient->CancelAsync();
			}
			if(TimerGetIPThread != nullptr && TimerGetIPThread->IsAlive){
				if(GetIPSleeping){
					TimerGetIPThread->Interrupt();
				}
				TimerGetIPThread->Join();
			}
			
			this->Text = gcnew String("LilithPort");

			StartupForm^ s = gcnew StartupForm;
			s->ShowDialog(this);

			ListView = LV_NAME;

			Begin();
		}

		void Leave(bool send_packet){
			CloseUdp(send_packet);

			Monitor::Enter(MemberList);
			try{
				listBoxMember->BeginUpdate();

				while(MemberList->Count > 1){
					MemberList->RemoveAt(1);
					listBoxMember->Items->RemoveAt(1);
				}

				listBoxMember->EndUpdate();
			}
			finally{
				Monitor::Exit(MemberList);
			}

			MTOPTION.CONNECTION_TYPE = CT_FREE;
			MemberList[0]->TYPE  = CT_FREE;
			MemberList[0]->STATE = MS_FREE;
			this->Text = gcnew String("LilithPort  [Free Play]");
			listBoxMember->Refresh();
		}

		void ChangeState(Object^ obj){
			if(MTOPTION.CONNECTION_TYPE == CT_FREE || UDP == nullptr) return;

			BYTE state = (BYTE)obj;

			array<BYTE>^ send = gcnew array<BYTE>(4){ PH_CHANGE_STATE, 0, 0, state };
			MemberList[0]->STATE = state;
			listBoxMember->Refresh();
			if(MemberList[0]->STATE == MS_FREE){
				if(MTOPTION.AUTO_REST){
					AutoRestThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::RunAutoRest));
					AutoRestThread->Start();
				}
			}
			if(MemberList[0]->STATE == MS_REST){
				if(AutoRestThread != nullptr){
					AutoRestRanging = false;
					AutoRestThread->Abort();
					AutoRestThread = nullptr;
				}
			}
			

			if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
				PacketSendAllMember(send, 0);
			}
			else{
				Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, send, 1, 2);
				UDP->BeginSend(send, send->Length, MemberList[1]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
			}
		}

		void CloseUdp(bool send_packet){
			if(UDP != nullptr){
				array<BYTE>^ quit;

				// ソナー停止
				if(SonarThread != nullptr && SonarThread->IsAlive && Ranging){
					Ranging = false;

					if(SonarSleeping){
						SonarThread->Interrupt();
					}

					SonarThread->Join();
				}
				// 自動休憩スレッド停止
				if(AutoRestThread != nullptr && AutoRestThread->IsAlive && AutoRestRanging){
					AutoRestRanging = false;
					AutoRestThread->Abort();
					AutoRestThread = nullptr;
				}

				if(send_packet){
					// 退室メッセージを送信
					if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
						quit = gcnew array<BYTE>(3){ PH_QUIT, 0, 0 };
						PacketSendAllMember(quit, 0);
						IDCounter = 0;
					}
					else if(MemberList->Count > 1){
						array<BYTE>^ quit = gcnew array<BYTE>(3){ PH_QUIT };
						Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, quit, 1, 2);
						UDP->BeginSend(quit, quit->Length, MemberList[1]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
					}
				}

				if(GameThread != nullptr && GameThread->IsAlive){
					AfterCloseUDP = true;
				}
				else{
					UDP->Close();
				}
			}
		}

		void TalkMessage(UINT16 id, array<BYTE>^ msg){
			int i;
			String^ name;
			Color col;

			// 送受信
			if(UDP != nullptr && MemberList->Count > 1){
				if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
					// 本人と発信者以外に送信
					PacketSendAllMember(msg, id);
				}
				else{
					// 受信でなければ、サーバに送信
					if(id != 0xFFFF){
						UDP->BeginSend(msg, msg->Length, MemberList[1]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
					}
					else{
						// 受信フラグをクリア
						id = BitConverter::ToUInt16(msg, 1);
					}
				}
			}

			// メンバー検索
			Monitor::Enter(MemberList);
			try{
				for(i = 0; i < MemberList->Count; i++){
					if(id == MemberList[i]->ID){
						name = MemberList[i]->NAME;
						col  = NameColor[MemberList[i]->TYPE];
						break;
					}
				}

				if(i >= MemberList->Count && MTOPTION.CONNECTION_TYPE != CT_SERVER){
					name = gcnew String(String::Format("Unknown(ID:{0})", id));
					col  = ErrorMessageColor;

					// メンバーリスト外のIDがいたので問い合わせ
					array<BYTE>^ send = gcnew array<BYTE>(3){ PH_REQ_LIST };
					Array::Copy(BitConverter::GetBytes(id), 0, send, 1, 2);
					UDP->Send(send, 3, MemberList[1]->IP_EP);
				}
			}
			finally{
				Monitor::Exit(MemberList);
			}

			// 音声優先度: ニックネーム > キーワード > 発言
			// ニックネーム音声再生
			String ^tmpMsg = Encoding::Unicode->GetString(msg, 4, msg[3]);
			bool inname = 0;
			if(tmpMsg->Contains(gcnew String(MTOPTION.NAME))) {
				// 名前が呼ばれたらウィンドウ点滅
				if(MTOPTION.NAME_FLASH) {
					WindowFlash();
				}
				if(MTOPTION.NAME_SOUND_ENABLE){
					inname = 1;
					try{
						Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.NAME_SOUND));
						wav->Play();
					}
					catch(Exception^){
					}
				}
			}
			// キーワード反応
			bool inkeyword = 0;
			if(MTOPTION.KEYWORD_SOUND_ENABLE && !inname){
				// 分割バッファ
				TCHAR *tok, *next;
				TCHAR s1[MAX_KEYWORD];
				_tcscpy_s(s1, MTOPTION.KEYWORD);
				tok = wcstok_s(s1, _T(","), &next);
				while(tok != NULL){
					if(tmpMsg->Contains(gcnew String(tok))) {
						inkeyword = 1;
						try{
							Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.KEYWORD_SOUND));
							wav->Play();
						}
						catch(Exception^){
						}
						break;
					}
					tok = wcstok_s(NULL, _T(","), &next);
				}
			}
			// 発言でウィンドウ点滅
			if(MemberList[0]->ID != id && !inname) {
				if(MTOPTION.TALK_FLASH) {
					WindowFlash();
				}
				// 発言で音を再生
				if(MTOPTION.TALK_SOUND_ENABLE && !inkeyword){
					try{
						Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.TALK_SOUND));
						wav->Play();
					}
					catch(Exception^){
					}
				}
			}

			// 時間
			if(inname||inkeyword){
				WriteTime(1, DebugMessageColor);
			}else{
				WriteTime(1, SystemMessageColor);
			}
			// 表示
			WriteMessage(String::Format("[ {0} ] ", name), col);
			WriteMessage(String::Format("{0}\n", tmpMsg), TalkMessageColor);
		}

		void WriteMessage(String^ msg, Color color){
			if(richTextBoxLog->InvokeRequired){
				WriteMessageDelegate^ wmd = gcnew WriteMessageDelegate(this, &MainForm::WriteMessage);
				richTextBoxLog->Invoke(wmd, msg, color);
			}
			else{
				Monitor::Enter(richTextBoxLog);
				try{
					richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;

					richTextBoxLog->SelectionColor = color;
					richTextBoxLog->AppendText(msg);

					richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;

					if(!MTOPTION.LOG_LOCK) {
						richTextBoxLog->ScrollToCaret();
					}
				}
				finally{
					Monitor::Exit(richTextBoxLog);
				}
			}	
		}
		void WriteTime(bool f, Color color){
			if(f){
				WriteMessage(String::Format("[{0}]", DateTime::Now.ToString("HH:mm")), color);
			}else{
				WriteMessage(String::Format("[{0}] ", DateTime::Now.ToString("HH:mm")), color);
			}
		}
		void WriteNotice(String^ msg){
			// 音でお知らせ
			if(MTOPTION.CONNECTION_TYPE != CT_SERVER){
				if(MTOPTION.NOTICE_SOUND_ENABLE){
					try{
						Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.NOTICE_SOUND));
						wav->Play();
					}
					catch(Exception^){
					}
				}
			}

			// \nで改行
			msg = msg->Replace("\\n", "\n");

			Monitor::Enter(richTextBoxLog);
			try{
				richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;

				richTextBoxLog->SelectionFont = gcnew Drawing::Font(richTextBoxLog->Font->FontFamily, richTextBoxLog->Font->Size + 2);
				richTextBoxLog->SelectionColor = TalkMessageColor;
				richTextBoxLog->SelectionBackColor = NoticeBackColor;
				richTextBoxLog->AppendText(msg + "\n");

				richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;

				if(!MTOPTION.LOG_LOCK) {
					richTextBoxLog->ScrollToCaret();
				}
			}
			catch(Exception ^e){
				WriteErrorLog(e->ToString(), "RichTextBox");
			}
			finally{
				Monitor::Exit(richTextBoxLog);
			}

		}

		void WriteComment(String^ name, int type, String^ comment){
			if(ListView == LV_BLIND){
				return;
			}

			// 音でお知らせ
			if(MTOPTION.ENTER_SOUND_ENABLE){
				try{
					Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.ENTER_SOUND));
					wav->Play();
				}
				catch(Exception^){
				}
			}

			if(comment->Length > 0){
				// 時間
				WriteTime(1, SystemMessageColor);
				Monitor::Enter(richTextBoxLog);
				try{
					richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;
					richTextBoxLog->SelectionColor = NameColor[type];
					richTextBoxLog->SelectionBackColor = CommentBackColor;
					richTextBoxLog->AppendText(String::Format("[ {0} ] ", name));

					richTextBoxLog->SelectionColor = TalkMessageColor;
					richTextBoxLog->SelectionBackColor = CommentBackColor;
					richTextBoxLog->AppendText(String::Format("{0}\n", comment));

					richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;
					if(!MTOPTION.LOG_LOCK) {
						richTextBoxLog->ScrollToCaret();
					}
				}
				catch(Exception ^e){
					WriteErrorLog(e->ToString(), "RichTextBox");
				}
				finally{
					Monitor::Exit(richTextBoxLog);
				}
			}
			else{
				WriteTime(0, SystemMessageColor);
				WriteMessage(String::Format("{0}が入室しました。\n", name), SystemMessageColor);
			}
		}

		void WriteCommandList(){
			WriteMessage(
				"/help ： コマンド一覧の表示\n"
				"/clear ： ログの削除\n"
				"/log ： RTF形式でログの保存\n"
				"/debug ： デバッグモードの切り替え\n"
				"/vs ： ランダムに対戦を挑む\n"
				"/game ： ゲームの起動\n"
				"/replay ： リプレイファイルの再生\n"
				"/quit ： 起動中のゲームを終了\n"
				"/reload ： メンバーリストの更新\n"
				"/restart ： フリープレイから新規に回線接続\n"
				"/rest ： 休憩状態の切り替え\n"
				"/seek ： 対戦募集状態の切り替え\n"
				"/list ： リストの表示を切り替え\n"
				"/leave ： 退室＆フリープレイに移行\n"
				"/exit ： プログラムの終了\n", SystemMessageColor);
		}

		void RandomVersus(){
			if(ServerMode == SM_MIX){
				return;
			}

			if(MTOPTION.CONNECTION_TYPE != CT_FREE && MemberList[0]->STATE == MS_FREE){
				UINT n = 0;
				Generic::List<int>^ list = gcnew Generic::List<int>;

				Monitor::Enter(MemberList);
				try{
					for(int i = 1; i < MemberList->Count; i++){
						if(MemberList[i]->STATE == MS_FREE && MemberList[i]->TYPE != CT_CLIENT){
							list->Add(i);
						}
					}

					if(list->Count > 0){
						n = list[XorShift() % list->Count];
					}
				}
				finally{
					Monitor::Exit(MemberList);
				}

				if(n > 0){
					listBoxMember->SelectedIndex = n;
					StartGame(RT_VS);
				}
				else{
					WriteMessage("対戦できる相手がいませんでした。\n", SystemMessageColor);
				}
			}
		}

		void AnalyzeCommand(){
			if(textBoxInput->Text->StartsWith("/help", StringComparison::OrdinalIgnoreCase)){
				WriteCommandList();
			}
			else if(textBoxInput->Text->StartsWith("/clear", StringComparison::OrdinalIgnoreCase)){
				ClearLog();
			}
			else if(textBoxInput->Text->StartsWith("/log", StringComparison::OrdinalIgnoreCase)){
				String^ path = gcnew String(MTOPTION.PATH);
				String^ file = String::Format("MT_{0}.rtf", DateTime::Now.ToString("yyMMdd-HHmmss"));
				path += file;

				Monitor::Enter(richTextBoxLog);
				try{
					richTextBoxLog->SaveFile(path, RichTextBoxStreamType::RichText);
				}
				catch(Exception ^e){
					WriteErrorLog(e->ToString(), "SaveLog");
				}
				finally{
					Monitor::Exit(richTextBoxLog);
				}

				WriteMessage(String::Format("\"{0}\"にログを保存しました。\n", file), SystemMessageColor);
			}
			else if(textBoxInput->Text->StartsWith("/debug", StringComparison::OrdinalIgnoreCase)){
				MTINFO.DEBUG ^= 1;
				if(MTINFO.DEBUG){
					WriteMessage("デバッグモード > オン\n", SystemMessageColor);
				}
				else{
					WriteMessage("デバッグモード > オフ\n", SystemMessageColor);
				}
			}
			else if(textBoxInput->Text->StartsWith("/vs", StringComparison::OrdinalIgnoreCase)){
				RandomVersus();
			}
			else if(textBoxInput->Text->StartsWith("/game", StringComparison::OrdinalIgnoreCase)){
				StartGame(RT_FREE);
			}
			else if(textBoxInput->Text->StartsWith("/replay", StringComparison::OrdinalIgnoreCase)){
				ReplayFilePath = String::Empty;
				StartGame(RT_PLAYBACK);
			}
			else if(textBoxInput->Text->StartsWith("/quit", StringComparison::OrdinalIgnoreCase)){
				QuitGame();
			}
			else if(textBoxInput->Text->StartsWith("/restart", StringComparison::OrdinalIgnoreCase)){
				Restart();
			}
			else if(textBoxInput->Text->StartsWith("/rest", StringComparison::OrdinalIgnoreCase)){
				if(MTOPTION.CONNECTION_TYPE == CT_FREE) return;

				if(MemberList[0]->STATE == MS_FREE){
					ChangeState((BYTE)MS_REST);
					WriteMessage("休憩状態を変更しました。 > オン\n", SystemMessageColor);
				}
				else if(MemberList[0]->STATE == MS_REST){
					ChangeState((BYTE)MS_FREE);
					WriteMessage("休憩状態を変更しました。 > オフ\n", SystemMessageColor);
				}
			}
			else if(textBoxInput->Text->StartsWith("/seek", StringComparison::OrdinalIgnoreCase)){
				ChangeSeek();
			}
			else if(textBoxInput->Text->StartsWith("/list", StringComparison::OrdinalIgnoreCase)){
				ChangeListView(true);	
			}
			else if(textBoxInput->Text->StartsWith("/time", StringComparison::OrdinalIgnoreCase)){
				WriteMessage(String::Format("{0} {1}\n", DateTime::Now.ToLongDateString(), DateTime::Now.ToLongTimeString()), SecretColor);
			}
			else if(textBoxInput->Text->StartsWith("/dice", StringComparison::OrdinalIgnoreCase)){
				if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
					BYTE dice = (BYTE)(XorShift() % 101);

					array<BYTE>^ send = gcnew array<BYTE>(2){ PH_DICE, dice };
					PacketSendAllMember(send, 0);

					Monitor::Enter(richTextBoxLog);
					try{
						richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;

						richTextBoxLog->SelectionColor = TalkMessageColor;
						richTextBoxLog->SelectionBackColor = NoticeBackColor;
						richTextBoxLog->AppendText(Byte(dice).ToString() + "\n");

						richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;
						if(!MTOPTION.LOG_LOCK) {
							richTextBoxLog->ScrollToCaret();
						}
					}
					catch(Exception ^e){
						WriteErrorLog(e->ToString(), "RichTextBox");
					}
					finally{
						Monitor::Exit(richTextBoxLog);
					}
				}
			}
			else if(textBoxInput->Text->StartsWith("/leave", StringComparison::OrdinalIgnoreCase)){
				Leave(true);
			}
			else if(textBoxInput->Text->StartsWith("/exit", StringComparison::OrdinalIgnoreCase)){
				this->Close();
			}
			else if(textBoxInput->Text->StartsWith("/memberlist", StringComparison::OrdinalIgnoreCase)){
				// デバッグ用コマンド
				if(UDP == nullptr){
					return;
				}
				if(MTINFO.DEBUG){
					WriteMessage("NAME / ID / IP_EP / TYPE\n", DebugMessageColor);
					for(int i = 0; i < MemberList->Count; i++){
						// TYPE 0:Server 1:Host 2:Client	
						WriteMessage(String::Format("{0} / {1} / {2} / {3}\n", MemberList[i]->NAME, MemberList[i]->ID, MemberList[i]->IP_EP, MemberList[i]->TYPE), DebugMessageColor);
					}
				}
			}
			else if(textBoxInput->Text->StartsWith("/memberhistory", StringComparison::OrdinalIgnoreCase)){
				// デバッグ用コマンド
				if(MTOPTION.CONNECTION_TYPE != CT_SERVER || UDP == nullptr){
					return;
				}
				if(MTINFO.DEBUG){
					WriteMessage("ID / IP_EP\n", DebugMessageColor);
					for(int i = 0; i < MemberListBackUp->Count; i++){
						WriteMessage(String::Format("{0} / {1}\n", MemberListBackUp[i]->ID, MemberListBackUp[i]->IP_EP), DebugMessageColor);
					}
				}
			}
			else if(textBoxInput->Text->StartsWith("/reload")){
				ReloadList();
			}
			else if(textBoxInput->Text->StartsWith("/test", StringComparison::OrdinalIgnoreCase)){
				// デバッグ用コマンド

				//Debug::WriteLine("test");
				//Thread::Sleep(100 * 1000);

				//ChangeState((BYTE)MS_FREE);

				/*
				richTextBoxLog->SelectionStart = richTextBoxLog->Text->Length;
				richTextBoxLog->SelectionColor = ErrorMessageColor;
				richTextBoxLog->AppendText("hogehoge\n");
				*/
				
				

				
				// 強制キック
				//array<BYTE>^ send = gcnew array<BYTE>(3){ PH_LOST, 0xFF, 0xFF };
				//IPEndPoint^ ep = gcnew IPEndPoint(IPAddress::Parse("221.79.20.188")->Address, 7500);
				//UDP->BeginSend(send, send->Length, ep, gcnew AsyncCallback(SendPackets), UDP);

				// ping
				//IPEndPoint^ ep = gcnew IPEndPoint(IPAddress::Parse("220.147.87.48")->Address, 4040);
				//array<BYTE>^ ping = gcnew array<BYTE>(1){ PH_PING };
				//Ping = timeGetTime();
				//UDP->BeginSend(ping, 1, ep, gcnew AsyncCallback(SendPackets), UDP);

				// なりきり
				/*
				IPEndPoint^ ep = gcnew IPEndPoint(IPAddress::Parse("220.147.87.48")->Address, 4040);
				BYTE len = (BYTE)(16);
				array<BYTE>^ msg = gcnew array<BYTE>(4 + len);

				msg[0] = PH_MESSAGE;
				Array::Copy(BitConverter::GetBytes(207), 0, msg, 1, 2);
				msg[3] = len;
				Array::Copy(Encoding::Unicode->GetBytes("それほどでもない"), 0, msg, 4, len);

				UDP->BeginSend(msg, msg->Length, ep, gcnew AsyncCallback(SendPackets), UDP);
				*/
				
				
				/*// MTSPアドレスデコード
				IPEndPoint^ ep = gcnew IPEndPoint(MTDecryptionIP(""), 7500);
				WriteMessage(String::Format("{0}", ep), DebugMessageColor);
				//*/

				/*// LilithPortアドレスデコード
				IPEndPoint^ ep = gcnew IPEndPoint(DecryptionIP("", true), 7500);
				WriteMessage(String::Format("{0}", ep), DebugMessageColor);
				//*/

				/*// メンバーリスト手動削除
				MemberList->RemoveAt(listBoxMember->SelectedIndex);
				listBoxMember->Items->RemoveAt(listBoxMember->SelectedIndex);
				//*/
			}
		}

		void AddListView(MemberInfo^% info){
			switch(ListView){
			case LV_NAME:
				listBoxMember->Items->Add(info->NAME);
				break;

			case LV_COMMENT:
				if(info->COMMENT->Length > 0){
					listBoxMember->Items->Add(info->COMMENT);
				}
				else{
					listBoxMember->Items->Add(gcnew String("◆"));
				}
				break;

			case LV_BLIND:
				listBoxMember->Items->Add(gcnew String("◆"));
				break;
			}
		}

		void ChangeListView(bool auto_change){
			listBoxMember->SelectedIndex = -1;

			if(ListView == LV_BLIND){
				return;
			}

			// 名前とコメントの自動切り替え
			if(auto_change){
				switch(ListView){
				case LV_NAME:
					ListView = LV_COMMENT;
					break;

				case LV_COMMENT:
					ListView = LV_NAME;
					break;

				case LV_BLIND:
					break;
				}
			}

			Monitor::Enter(MemberList);
			try{
				for(int i = 0; i < listBoxMember->Items->Count; i++){
					switch(ListView){
					case LV_NAME:
						listBoxMember->Items[i] = MemberList[i]->NAME;
						break;

					case LV_COMMENT:
						if(MemberList[i]->COMMENT->Length > 0){
							listBoxMember->Items[i] = MemberList[i]->COMMENT;
						}
						else{
							listBoxMember->Items[i] = gcnew String("◆");
						}
						break;

					case LV_BLIND:
						listBoxMember->Items[i] = gcnew String("◆");
						break;
					}
				}
			}
			finally{
				Monitor::Exit(MemberList);
			}
		}

		void ResetDelay(UINT value){
			toolStripMenuItemDelayAuto->Checked = false;
			toolStripMenuItemDelay2->Checked    = false;
			toolStripMenuItemDelay3->Checked    = false;
			toolStripMenuItemDelay4->Checked    = false;
			toolStripMenuItemDelay5->Checked    = false;
			toolStripMenuItemDelay6->Checked    = false;
			toolStripMenuItemDelay7->Checked    = false;
			toolStripMenuItemDelay8->Checked    = false;
			toolStripMenuItemDelay9->Checked    = false;
			toolStripMenuItemDelay10->Checked   = false;
			toolStripMenuItemDelay11->Checked   = false;
			toolStripMenuItemDelay12->Checked   = false;

			switch(value){
			case 0:
			default:
				toolStripMenuItemDelayAuto->Checked = true;
				MTOPTION.DELAY = 0;
				break;
			case 2:
				toolStripMenuItemDelay2->Checked = true;
				MTOPTION.DELAY = 2;
				break;
			case 3:
				toolStripMenuItemDelay3->Checked = true;
				MTOPTION.DELAY = 3;
				break;
			case 4:
				toolStripMenuItemDelay4->Checked = true;
				MTOPTION.DELAY = 4;
				break;
			case 5:
				toolStripMenuItemDelay5->Checked = true;
				MTOPTION.DELAY = 5;
				break;
			case 6:
				toolStripMenuItemDelay6->Checked = true;
				MTOPTION.DELAY = 6;
				break;
			case 7:
				toolStripMenuItemDelay7->Checked = true;
				MTOPTION.DELAY = 7;
				break;
			case 8:
				toolStripMenuItemDelay8->Checked = true;
				MTOPTION.DELAY = 8;
				break;
			case 9:
				toolStripMenuItemDelay9->Checked = true;
				MTOPTION.DELAY = 9;
				break;
			case 10:
				toolStripMenuItemDelay10->Checked = true;
				MTOPTION.DELAY = 10;
				break;
			case 11:
				toolStripMenuItemDelay11->Checked = true;
				MTOPTION.DELAY = 11;
				break;
			case 12:
				toolStripMenuItemDelay12->Checked = true;
				MTOPTION.DELAY = 12;
				break;
			}
		}


		void ReloadList(){
			// メンバーリスト更新
			if(MTOPTION.CONNECTION_TYPE == CT_SERVER || UDP == nullptr){
				return;
			}
			int count = MemberList->Count;
			if(count > 1){
				for(int i = 2; i < count; i++){
					MemberList->RemoveAt(2);
					listBoxMember->Items->RemoveAt(2);
				}
			}
			array<BYTE>^ send = gcnew array<BYTE>(3){ PH_REQ_LIST };
			Array::Copy(BitConverter::GetBytes(0), 0, send, 1, 2);
			UDP->Send(send, 3, MemberList[1]->IP_EP);

			WriteMessage("メンバーリストを更新しました。(連続しての更新はサーバーに負荷がかかるため、注意してください。)\n", SystemMessageColor);
		}
		void WriteStatus(String^ msg){
			toolStripStatusLabel->Text = msg;
		}
	public:
		// IP取得完了
		void GetIPOpenReadCompleted(System::Object^ sender, System::Net::OpenReadCompletedEventArgs^ e) {

			// 終了用
			if(GetIPClient == nullptr) return;
			if(GetIPCancelled == true) {
				GetIPCancelled = false;
				GetIPClient = nullptr;
				return;
			}
			// TimerGetIPタイムアウト
			if(e->Cancelled) {
				WriteMessage("IPアドレス取得の要求がタイムアウトによりキャンセルされました。\n", ErrorMessageColor);
				if(MTINFO.DEBUG){
					WriteMessage(e->ToString() + "\n", DebugMessageColor);
				}
				GetIPClient = nullptr;
				return;
			}
			// アドレスの抽出
			String^ html;
			_int64 Global_address;
			array<String^> ^s1, ^s2, ^s3;
			Stream^ reply = nullptr;
			StreamReader^ sr = nullptr;
			try{
				reply = dynamic_cast<Stream^>(e->Result);
				sr = gcnew StreamReader(reply);
				html = sr->ReadToEnd();
				s1 = html->Split(':');
				s2 = s1[1]->Split('<');
				s3 = s2[0]->Split(' ');
				Global_address = Int64(Net::IPAddress::Parse(s3[1])->Address);
			}
			catch(Exception^ e) {
				Global_address = 0;
				WriteMessage("IPアドレス情報の抽出に失敗しました。\nLilithPortのバージョンが古い可能性があります。\n", ErrorMessageColor);

				if(MTINFO.DEBUG){
					WriteMessage(e->ToString() + "\n", DebugMessageColor);
				}
			}
			finally{
				// Streamはしっかり開放
				if(sr != nullptr) sr->Close();
				if(reply != nullptr) reply->Close();
			}
			if(Global_address > 0) {
				WriteMessage(String::Format("IPアドレスを取得しました。 > {0}\n", s3[1]), SystemMessageColor);
				WriteMessage("[変換アドレス:ポート]\nLilithPort用 > ", SystemMessageColor);

				richTextBoxLog->SelectionColor = TalkMessageColor;
				richTextBoxLog->SelectionBackColor = NoticeBackColor;
				richTextBoxLog->AppendText(String::Format("{0}:{1}\n", EncryptionIP(s3[1]), MTOPTION.OPEN_PORT));
				
				WriteMessage("MTSP用 > ", SystemMessageColor);
				richTextBoxLog->SelectionColor = TalkMessageColor;
				richTextBoxLog->SelectionBackColor = NoticeBackColor;
				richTextBoxLog->AppendText(String::Format("{0}:{1}\n", MTEncryptionIP(s3[1]), MTOPTION.OPEN_PORT));


				WriteMessage("-------------------------------\n", SystemMessageColor);
			}
			GetIPClient = nullptr;
		}

		void ChangeComment(String^ comment){
			if(UDP == nullptr || (MTOPTION.CONNECTION_TYPE != CT_FREE && ServerMode >= SM_MATCH)){
				return;
			}

			MemberList[0]->COMMENT = comment;

			if(ListView == LV_COMMENT){
				if(comment->Length > 0){
					listBoxMember->Items[0] = comment;
				}
				else{
					listBoxMember->Items[0] = gcnew String("◆");
				}
			}

			BYTE len = (BYTE)(comment->Length * 2);
			array<BYTE>^ send = gcnew array<BYTE>(4 + len);

			send[0] = PH_CHANGE_COMMENT;
			Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, send, 1, 2);
			send[3] = len;
			Array::Copy(Encoding::Unicode->GetBytes(comment), 0, send, 4, len);

			if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
				PacketSendAllMember(send, 0);
			}
			else{
				UDP->BeginSend(send, send->Length, MemberList[1]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
			}
		}

		void ResetColor(){
			NameColor = gcnew array<Color>{
				Color::FromArgb(MTCOLOR.SERVER_NAME),
				Color::FromArgb(MTCOLOR.HOST_NAME),
				Color::FromArgb(MTCOLOR.CLIENT_NAME),
				SystemColors::WindowText,
			};

			StateRectColor = gcnew array<Color>{
				Color::FromArgb(MTCOLOR.REST_STATE),
				Color::FromArgb(MTCOLOR.VS_STATE),
				Color::FromArgb(MTCOLOR.WATCH_STATE),
				Color::FromArgb(MTCOLOR.SEEK_STATE),
			};

			TalkMessageColor   = SystemColors::WindowText;
			SystemMessageColor = Color::FromArgb(MTCOLOR.SYSTEM_MESSAGE);
			ErrorMessageColor  = Color::FromArgb(MTCOLOR.ERROR_MESSAGE);
			DebugMessageColor  = Color::FromArgb(MTCOLOR.DEBUG_MESSAGE);
			NoticeBackColor    = Color::FromArgb(MTCOLOR.NOTICE_BACK);
			CommentBackColor   = Color::FromArgb(MTCOLOR.COMMENT_BACK);
			SecretColor        = Color::FromArgb(MTCOLOR.SECRET);
		}

		void GetIPAddress(){
			if(GetIPClient == nullptr){
				// グローバルIPの取得
				GetIPClient = gcnew WebClient();
				GetIPClient->OpenReadCompleted += gcnew OpenReadCompletedEventHandler(this, &MainForm::GetIPOpenReadCompleted);

				// タイムアウトタイマー
				WriteMessage("IPアドレスを取得中です...\n", SystemMessageColor);
				TimerGetIPThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::TimerGetIP));
				TimerGetIPThread->Start();
				try{
					GetIPClient->OpenReadAsync(GetIPUri);
				}
				catch(WebException^ e) {
					WriteMessage("IPアドレスの取得に失敗しました。\n", ErrorMessageColor);

					if(MTINFO.DEBUG){
						WriteMessage(e->ToString() + "\n", DebugMessageColor);
					}
				}
			}
		}
		void ChangeProfileEnabled(){
			// プロファイルドロップダウン更新
			toolStripDropDownButtonProfile->DropDownItems->Clear();
			for(int i=0; i < Profile::ProfileList->Count; i++){
				if(Profile::ProfileList[i] == gcnew String(MTOPTION.PROFILE)){
					toolStripDropDownButtonProfile->Text = Profile::ProfileList[i];			
				}
				toolStripDropDownButtonProfile->DropDownItems->Add(Profile::ProfileList[i]);
				toolStripDropDownButtonProfile->DropDownItems[i]->Click += gcnew System::EventHandler(this, &MainForm::toolStripDropDownItemProfile_Click);
			}
			toolStripDropDownButtonProfile->Enabled = true;
		}
		void SetAutoRestTime(UINT time){
			MTOPTION.AUTO_REST_TIME = time;
			toolStripMenuItemAutoRestTime5->Checked = 0;
			toolStripMenuItemAutoRestTime10->Checked = 0;
			toolStripMenuItemAutoRestTime15->Checked = 0;
			toolStripMenuItemAutoRestTime20->Checked = 0;
			toolStripMenuItemAutoRestTime30->Checked = 0;
			toolStripMenuItemAutoRestTime60->Checked = 0;
			toolStripMenuItemAutoRestTime120->Checked = 0;
		}
	private:
		System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
			// 行間を詰める
			richTextBoxLog->LanguageOption = RichTextBoxLanguageOptions::UIFonts;

			// スレッド間の呼び出し確認を無効にする
			Control::CheckForIllegalCrossThreadCalls = false;

			if(MTWS.LEFT > 0 && MTWS.TOP > 0){
				this->StartPosition = FormStartPosition::Manual;
				this->Location = System::Drawing::Point(MTWS.LEFT, MTWS.TOP);
			}

			if(MTWS.WIDTH > 0 && MTWS.HEIGHT > 0){
				this->ClientSize = System::Drawing::Size(MTWS.WIDTH, MTWS.HEIGHT);
			}

			if(MTWS.SPLITTER > 0){
				splitContainer1->SplitterDistance = MTWS.SPLITTER;
			}

			ResetDelay(MTOPTION.DELAY);
			ResetColor();

			toolStripMenuItemRecordReplay->Checked   = MTOPTION.RECORD_REPLAY;
			toolStripMenuItemAllowSpectator->Checked = MTOPTION.ALLOW_SPECTATOR;
			LogLockToolStripMenuItem->Checked        = MTOPTION.LOG_LOCK;
			toolStripMenuItemWordWrap->Checked       = MTOPTION.LOG_WORDWRAP;
			richTextBoxLog->WordWrap				 = MTOPTION.LOG_WORDWRAP;
			toolStripMenuItemAfterRest->Checked      = MTOPTION.AFTER_REST;
			toolStripMenuItemAutoRestEnable->Checked = MTOPTION.AUTO_REST;
			switch(MTOPTION.AUTO_REST_TIME){
				case 5:
					toolStripMenuItemAutoRestTime5->Checked = 1;
					break;
				case 10:
					toolStripMenuItemAutoRestTime10->Checked = 1;
					break;
				case 15:
					toolStripMenuItemAutoRestTime15->Checked = 1;
					break;
				case 20:
					toolStripMenuItemAutoRestTime20->Checked = 1;
					break;
				case 30:
					toolStripMenuItemAutoRestTime30->Checked = 1;
					break;
				case 60:
					toolStripMenuItemAutoRestTime60->Checked = 1;
					break;
				case 120:
					toolStripMenuItemAutoRestTime120->Checked = 1;
					break;
			}

			IsFormClosing = false;
			ListView = LV_NAME;

			ChatHistoryNumber = 0;
			ChatHistory = gcnew Generic::List<String^>;

			UDP = nullptr;

			MemberList          = gcnew Generic::List<MemberInfo^>;
			MemberListBackUp    = gcnew Generic::List<MemberInfoBackUp^>;
			SpectatorList       = gcnew Generic::List<SpectatorInfo^>;
			WatchHistory        = gcnew array<UINT16>(TIME_OUT/5 * 3);
			InputHistory        = gcnew array<UINT16>(TIME_OUT/5 * 3);

			// richtextboxのデフォルトfalseバグ対策
			richTextBoxLog->AutoWordSelection = true;
			richTextBoxLog->AutoWordSelection = false;

			timeBeginPeriod(1);
		}

		System::Void MainForm_Shown(System::Object^  sender, System::EventArgs^  e) {
			textBoxInput->Focus();

			this->toolStripMenuItemVersion_Click(nullptr, nullptr);

			if(MTINFO.SERVER_MODE){
				// サーバモード起動
				MTOPTION.CONNECTION_TYPE = CT_SERVER;
				if(MTINFO.SERVER_MODE_PORT > 0){
					MTOPTION.OPEN_PORT = MTINFO.SERVER_MODE_PORT;
				}
			}else{
				StartupForm^ s = gcnew StartupForm;
				s->ShowDialog(this);

				if(!File::Exists(gcnew String(MTOPTION.GAME_EXE))){
					MessageBox::Show("実行ファイルのパスを設定してください。", "ゲームがありません");

					OptionForm^ o = gcnew OptionForm;
					o->GameExePathError = true;
					o->ShowDialog(this);
				}
			}

			Begin();
		}

		System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			if(IsFormClosing == false && GameThread != nullptr && GameThread->IsAlive){
				IsFormClosing = true;

				QuitGame();

				e->Cancel = true;
				return;
			}

			if(MTOPTION.CONNECTION_TYPE == CT_SERVER && MTINFO.ERRORED == false){
				if(MessageBox::Show("サーバを落としますか？", "終了の確認", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::No){
					IsFormClosing = false;
					e->Cancel = true;
					return;
				}
			}

			QuitWatch(true);
			CloseUdp(true);

			// IP取得のキャンセル
			if(GetIPClient != nullptr){
				GetIPCancelled = true;
				GetIPClient->CancelAsync();
			}
			if(TimerGetIPThread != nullptr && TimerGetIPThread->IsAlive){
				if(GetIPSleeping){
					TimerGetIPThread->Interrupt();
				}
				TimerGetIPThread->Join();
			}

			if(MTINFO.DEBUG){
				String^ path = gcnew String(MTOPTION.PATH);
				path += "log.rtf";

				Monitor::Enter(richTextBoxLog);
				try{
					richTextBoxLog->SaveFile(path, RichTextBoxStreamType::RichText);
				}
				catch(Exception ^e){
					WriteErrorLog(e->ToString(), "SaveLog");
				}
				finally{
					Monitor::Exit(richTextBoxLog);
				}
			}
		}

		System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			MTWS.LEFT     = this->Location.X;
			MTWS.TOP      = this->Location.Y;
			MTWS.WIDTH    = this->ClientSize.Width;
			MTWS.HEIGHT   = this->ClientSize.Height;
			MTWS.SPLITTER = splitContainer1->SplitterDistance;

			timeEndPeriod(1);
		}

		System::Void textBoxInput_KeyDown( Object^ sender, System::Windows::Forms::KeyEventArgs^ e ) {
			// チャット履歴から選択
			if(ChatHistory->Count > 0){
				if(e->KeyCode == Keys::Up){
					ChatHistoryNumber--;
					if(ChatHistoryNumber < 0){
						ChatHistoryNumber = 0;
					}

					textBoxInput->Text = ChatHistory[ChatHistoryNumber];
					textBoxInput->SelectAll();
					e->SuppressKeyPress = true;
				}
				else if(e->KeyCode == Keys::Down){
					ChatHistoryNumber++;
					if(ChatHistoryNumber > ChatHistory->Count){
						ChatHistoryNumber = ChatHistory->Count;
					}

					if(ChatHistoryNumber == ChatHistory->Count){
						textBoxInput->Clear();
					}
					else{
						textBoxInput->Text = ChatHistory[ChatHistoryNumber];
						textBoxInput->SelectAll();
						e->SuppressKeyPress = true;
					}
				}
			}

			// メッセージ送信
			if(e->KeyCode == Keys::Enter && textBoxInput->Text->Length > 0){
				// チャット履歴更新
				if(ChatHistoryNumber < ChatHistory->Count){
					if(ChatHistory[ChatHistoryNumber] != textBoxInput->Text){
						ChatHistory->Add(textBoxInput->Text);
					}
				}
				else{
					ChatHistory->Add(textBoxInput->Text);
				}

				if(MTOPTION.CHAT_HISTORY > 0 && (UINT)ChatHistory->Count > MTOPTION.CHAT_HISTORY){
					ChatHistory->RemoveAt(0);
				}
				ChatHistoryNumber = ChatHistory->Count;

				try{
					if(e->Control && MTOPTION.CONNECTION_TYPE == CT_SERVER){
						// 告知
						BYTE len = (BYTE)(textBoxInput->Text->Length * 2);
						array<BYTE>^ msg = gcnew array<BYTE>(2 + len);

						msg[0] = PH_NOTICE;
						msg[1] = len;
						Array::Copy(Encoding::Unicode->GetBytes(textBoxInput->Text), 0, msg, 2, len);

						PacketSendAllMember(msg, 0);
	
						WriteMessage("[サーバー告知]-------------------\n", SystemMessageColor);
						WriteNotice(textBoxInput->Text);
						WriteMessage("-------------------------------\n", SystemMessageColor);
					}
					else if(textBoxInput->Text[0] == '/'){
						AnalyzeCommand();
					}
					else if(UDP != nullptr && ServerMode >= SM_MATCH){
						WriteMessage("チャットは禁止されています。\n", SystemMessageColor);
					}
					else if(UDP != nullptr){
						// チャット発言
						BYTE len = (BYTE)(textBoxInput->Text->Length * 2);
						array<BYTE>^ msg = gcnew array<BYTE>(4 + len);

						msg[0] = PH_MESSAGE;
						Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, msg, 1, 2);
						msg[3] = len;
						Array::Copy(Encoding::Unicode->GetBytes(textBoxInput->Text), 0, msg, 4, len);

						TalkMessage(MemberList[0]->ID, msg);
					}
					else{
						WriteMessage(textBoxInput->Text + "\n", TalkMessageColor);
					}
				}
				catch(Exception^ e){
					if(MTINFO.DEBUG){
						WriteMessage(String::Format("{0}\n", e->ToString()), DebugMessageColor);
					}
				}

				textBoxInput->Clear();
				e->SuppressKeyPress = true;
			}
		}

		System::Void listBoxMember_DrawItem(System::Object^  sender, System::Windows::Forms::DrawItemEventArgs^  e) {
			if(e->Index == -1) return;
			try{
				UINT state = MemberList[e->Index]->STATE;
				Brush^ b = gcnew SolidBrush(NameColor[MemberList[e->Index]->TYPE]);

				switch(state){
				case MS_REST:
					e->Graphics->FillRectangle(gcnew SolidBrush(StateRectColor[0]), e->Bounds);
					break;

				case MS_VS:
					e->Graphics->FillRectangle(gcnew SolidBrush(StateRectColor[1]), e->Bounds);
					break;

				case MS_WATCH:
				case MS_COUCH:
					e->Graphics->FillRectangle(gcnew SolidBrush(StateRectColor[2]), e->Bounds);
					break;
				case MS_SEEK:
					e->Graphics->FillRectangle(gcnew SolidBrush(StateRectColor[3]), e->Bounds);
					break;
				default:
					e->DrawBackground();
				}

				e->Graphics->DrawString(listBoxMember->Items[e->Index]->ToString(), e->Font, b, e->Bounds);
				e->DrawFocusRectangle();
			}
			catch(ArgumentOutOfRangeException^){
			}
		}

		System::Void listBoxMember_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			int index = listBoxMember->IndexFromPoint(e->X, e->Y);

			if(index == -1){
				ChangeListView(true);
			}

			if(MTOPTION.CONNECTION_TYPE == CT_FREE){
				return;
			}

			if(index == 0){
				int state = MemberList[0]->STATE;

				// 休憩状態の変更
				if(state == MS_FREE){
					ChangeState((BYTE)MS_REST);
					WriteMessage("休憩状態を変更しました。 > オン\n", SystemMessageColor);
				}
				else if(state == MS_REST){
					ChangeState((BYTE)MS_FREE);
					WriteMessage("休憩状態を変更しました。 > オフ\n", SystemMessageColor);
				}
				else if(state == MS_VS){
					WriteMessage("対戦を中止します。\n", SystemMessageColor);
					QuitGame();
				}
				else if(state == MS_WATCH || state == MS_COUCH){
					WriteMessage("観戦を中止します。\n", SystemMessageColor);
					QuitWatch(true);
				}
			}
			else if(index > 0 && UDP != nullptr){
				// 状態の再取得
				array<BYTE>^ send = gcnew array<BYTE>(3){ PH_REQ_STATE };
				Array::Copy(BitConverter::GetBytes(MemberList[index]->ID), 0, send, 1, 2);

				if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
					UDP->BeginSend(send, send->Length, MemberList[index]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
				}
				else{
					UDP->BeginSend(send, send->Length, MemberList[1]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
				}

				// Ping
				this->toolStripMenuItemPing_Click(nullptr, nullptr);
			}
		}

		System::Void listBoxMember_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			int index = listBoxMember->IndexFromPoint(e->X, e->Y);

			if(index == -1 || MTOPTION.CONNECTION_TYPE == CT_FREE || ListView == LV_BLIND){
				toolTipMember->Active = false;
				return;
			}
			else{
				toolTipMember->Active = true;
			}
			String^ cap = String::Format("ID = {0}", MemberList[index]->ID);
			if(index > 0){
				cap += String::Format(", VS = {0}", MemberList[index]->NUM_VS);
			}
			if(ListView == LV_NAME){
				if(MemberList[index]->COMMENT->Length > 0){
					cap += "\n" + MemberList[index]->COMMENT;
				}
			}
			else if(ListView == LV_COMMENT){
				cap += "\n" + MemberList[index]->NAME;
			}
			toolTipMember->SetToolTip(listBoxMember, cap);
		}
		System::Void toolStripMenuItemSetting_Click(System::Object^  sender, System::EventArgs^  e) {
			if(Option == nullptr || Option->IsDisposed){
				toolStripDropDownButtonProfile->Enabled = false;
				Option = gcnew OptionForm;
				Option->Show(this);
			}
			else{
				Option->Activate();
			}
		}

		System::Void toolStripMenuItemViewCommand_Click(System::Object^  sender, System::EventArgs^  e) {
			WriteCommandList();
		}

		System::Void toolStripMenuItemChangeList_Click(System::Object^  sender, System::EventArgs^  e) {
			ChangeListView(true);
		}

		System::Void toolStripMenuItemVersion_Click(System::Object^  sender, System::EventArgs^  e) {
			WriteMessage("LilithPort v1.07\n", SystemMessageColor);
		}

		System::Void toolStripMenuItemExit_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}

		// ブックマーク追加
		System::Void toolStripMenuItemAddBookMark_Click(System::Object^  sender, System::EventArgs^  e) {
			if((MTOPTION.BOOKMARK_COUNT - MTOPTION.BOOKMARK_DELETED_COUNT) > 9) {
				MessageBox::Show("これ以上ブックマークを追加できません。\nブックマークは最大10個まで登録できます。\n\n追加するには、ブックマークの削除を行ってください。", "ブックマークの追加", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return;
			}
			if(MTOPTION.CONNECTION_TYPE == CT_SERVER || MTOPTION.CONNECTION_TYPE == CT_FREE ){
				MessageBox::Show("SERVERモード、\nFREEモードはブックマークに追加できません。", "ブックマークの追加", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return;
			}

			String^ tmpName = ServerName;
			String^ tmpIP = ConnectIP;
			UINT tmpInt = MTOPTION.BOOKMARK_COUNT;

			toolStripMenuItemBookMark = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripMenuItemBookMarkMenu->DropDownItems->Add(toolStripMenuItemBookMark);
			toolStripMenuItemBookMark->Text = ServerName;
			toolStripMenuItemBookMark->Name = L"toolStripMenuItemBookMark" + MTOPTION.BOOKMARK_COUNT;
			toolStripMenuItemBookMark->Tag = MTOPTION.BOOKMARK_COUNT;
			toolStripMenuItemBookMark->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemBookMark_Click);

			// 削除メニュー
			toolStripMenuItemDelBookMark = (gcnew System::Windows::Forms::ToolStripMenuItem());
			toolStripMenuItemBookMark->DropDownItems->Add(toolStripMenuItemDelBookMark);
			toolStripMenuItemDelBookMark->Text = L"削除(&D)";
			toolStripMenuItemDelBookMark->Tag = L"toolStripMenuItemBookMark" + MTOPTION.BOOKMARK_COUNT;
			toolStripMenuItemDelBookMark->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItemDelBookMark_Click);
			
			BookMarkServerName = Runtime::InteropServices::Marshal::StringToHGlobalAuto(tmpName);
			_tcscpy_s(MTOPTION.BOOKMARK_SERVER_NAME[tmpInt], static_cast<PTCHAR>(BookMarkServerName.ToPointer()));
			Runtime::InteropServices::Marshal::FreeHGlobal(BookMarkServerName);

			BookMarkConnectIP = Runtime::InteropServices::Marshal::StringToHGlobalAuto(tmpIP);
			_tcscpy_s(MTOPTION.BOOKMARK_CONNECTION_IP[tmpInt], static_cast<PTCHAR>(BookMarkConnectIP.ToPointer()));
			Runtime::InteropServices::Marshal::FreeHGlobal(BookMarkConnectIP);

			_itot_s(MTOPTION.CONNECTION_TYPE, MTOPTION.BOOKMARK_CONNECTION_TYPE[tmpInt], 10);
			_itot_s(MTOPTION.OPEN_PORT,       MTOPTION.BOOKMARK_PORT[tmpInt],            10);

			MTOPTION.BOOKMARK_COUNT++;

			SaveMTOption();
		}
		// ブックマーク接続
		System::Void toolStripMenuItemBookMark_Click(System::Object^ sender, System::EventArgs^ e) {
			UINT tmpInt = (UINT)((ToolStripMenuItem^)sender)->Tag;

			if(MessageBox::Show(((ToolStripMenuItem^)sender)->Text+" に接続します。\nよろしいですか？", "ブックマーク接続", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
			}else{
				return;
			}

			_tcscpy_s(MTOPTION.CONNECTION_IP,   MTOPTION.BOOKMARK_CONNECTION_IP[tmpInt]);
			MTOPTION.CONNECTION_TYPE = (UINT)_ttoi(MTOPTION.BOOKMARK_CONNECTION_TYPE[tmpInt]);
			MTOPTION.OPEN_PORT       = (UINT)_ttoi(MTOPTION.BOOKMARK_PORT[tmpInt]);

			Restart();
		}
		// ブックマーク削除
		System::Void toolStripMenuItemDelBookMark_Click(System::Object^ sender, System::EventArgs^ e) {
			Object^ tmpTag;
			tmpTag = ((ToolStripMenuItem^)sender)->Tag;
			UINT tmpInt = (UINT)toolStripMenuItemBookMarkMenu->DropDownItems[(String^)tmpTag]->Tag;
			if(MessageBox::Show((String^)toolStripMenuItemBookMarkMenu->DropDownItems[(String^)tmpTag]->Text+" をブックマークから削除します。\nよろしいですか？", "ブックマークの削除", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
				toolStripMenuItemBookMarkMenu->DropDownItems->Remove(toolStripMenuItemBookMarkMenu->DropDownItems[(String^)tmpTag]);
				MTOPTION.BOOKMARK_DELETED_COUNT++;

				ZeroMemory(MTOPTION.BOOKMARK_SERVER_NAME[tmpInt], sizeof(MTOPTION.BOOKMARK_SERVER_NAME[tmpInt]));
				ZeroMemory(MTOPTION.BOOKMARK_CONNECTION_IP[tmpInt], sizeof(MTOPTION.BOOKMARK_CONNECTION_IP[tmpInt]));
				ZeroMemory(MTOPTION.BOOKMARK_CONNECTION_TYPE[tmpInt], sizeof(MTOPTION.BOOKMARK_CONNECTION_TYPE[tmpInt]));
				ZeroMemory(MTOPTION.BOOKMARK_PORT[tmpInt], sizeof(MTOPTION.BOOKMARK_PORT[tmpInt]));

				SaveMTOption();
			}
		}

		// ゲームの起動
		System::Void GameStartToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			StartGame(RT_FREE);			
		}
		// ゲームの起動(リプレイを保存しない)
		System::Void GameStartNoReplayToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			bool primary = 0;
			// リプレイ保存ONなら一時的無効化
			if(toolStripMenuItemRecordReplay->Checked == 1) {
				primary = 1;
				MTOPTION.RECORD_REPLAY = 0;
			}
			
			StartGame(RT_FREE);
			
			if(primary == 1) {
				// 起動前に戻してしまうの防止
				Thread::Sleep(100);
				MTOPTION.RECORD_REPLAY = toolStripMenuItemRecordReplay->Checked;
			}
		}
		// 再起動
		System::Void RestartToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if(MTOPTION.CONNECTION_TYPE == CT_SERVER) {
				if(MessageBox::Show("サーバを落とします。\nよろしいですか？", "再起動", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
				}else{
					return;
				}
			}

			if(MTOPTION.CONNECTION_TYPE == CT_HOST || MTOPTION.CONNECTION_TYPE == CT_CLIENT){
				if(MessageBox::Show("回線を切断します。\nよろしいですか？", "再起動", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
				}else{
					return;
				}
			}

			Restart();
		}

		// 退室
		System::Void LeaveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if(MTOPTION.CONNECTION_TYPE == CT_SERVER) {
				if(MessageBox::Show("サーバを落とします。\nよろしいですか？", "退室", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
				}else{
					return;
				}
			}

			if(MTOPTION.CONNECTION_TYPE == CT_HOST || MTOPTION.CONNECTION_TYPE == CT_CLIENT){
				if(MessageBox::Show("回線を切断します。\nよろしいですか？", "退室", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
				}else{
					return;
				}
			}

			Leave(true);
		}

		// 休憩状態の切り替え
		System::Void RestToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			if(MTOPTION.CONNECTION_TYPE == CT_FREE) return;

			if(MemberList[0]->STATE == MS_FREE){
				ChangeState((BYTE)MS_REST);
				WriteMessage("休憩状態を変更しました。 > オン\n", SystemMessageColor);
			}
			else if(MemberList[0]->STATE == MS_REST){
				ChangeState((BYTE)MS_FREE);
				WriteMessage("休憩状態を変更しました。 > オフ\n", SystemMessageColor);
			}
		}

		// 対戦募集状態の切り替え
		System::Void SeekToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ChangeSeek();
		}

		// ログの全削除
		System::Void ClearToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ClearLog();
		}

		// 当たり判定の表示切替
		System::Void ToggleHitJudgeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			// ゲーム起動中なら即時変更
			MTOPTION.HIT_JUDGE ^= 1;
			if(MTINFO.INITIALIZED && MTINFO.PROCESS != NULL){
				DWORD b = MTOPTION.HIT_JUDGE;

				if(MTINFO.KGT2K){
					WriteProcessMemory(MTINFO.PROCESS, (LPVOID)HIT_JUDGE, &b, 4, NULL);
				}
				else{
					WriteProcessMemory(MTINFO.PROCESS, (LPVOID)HIT_JUDGE_95, &b, 4, NULL);
				}
			}
		}

		System::Void toolStripMenuItemSaveLog_Click(System::Object^  sender, System::EventArgs^  e) {
			String^ path = gcnew String(MTOPTION.PATH);
			String^ file = String::Format("LilithPort_{0}.log", DateTime::Now.ToString("yyMMdd-HHmmss"));
			path += file;

			Monitor::Enter(richTextBoxLog);
			try{
				richTextBoxLog->SaveFile(path, RichTextBoxStreamType::PlainText);
			}
			catch(Exception ^e){
				WriteErrorLog(e->ToString(), "SaveLog");
			}
			finally{
				Monitor::Exit(richTextBoxLog);
			}

			WriteMessage(String::Format("\"{0}\"にログを保存しました。\n", file), SystemMessageColor);
		}

		System::Void toolStripMenuItemReplay_Click(System::Object^  sender, System::EventArgs^  e) {
			ReplayFilePath = String::Empty;
			StartGame(RT_PLAYBACK);
		}

		System::Void toolStripMenuItemRecordReplay_Click(System::Object^  sender, System::EventArgs^  e) {
			toolStripMenuItemRecordReplay->Checked ^= 1;

			MTOPTION.RECORD_REPLAY = toolStripMenuItemRecordReplay->Checked;
		}

		System::Void toolStripMenuItemAllowSpectator_Click(System::Object^  sender, System::EventArgs^  e) {
			toolStripMenuItemAllowSpectator->Checked ^= 1;

			MTOPTION.ALLOW_SPECTATOR = toolStripMenuItemAllowSpectator->Checked;

			if(toolStripMenuItemAllowSpectator->Checked == false && UDP != nullptr){
				array<BYTE>^ send = gcnew array<BYTE>(3){ PH_WATCH_END };

				Monitor::Enter(InputHistory);
				try{
					for(int i = 0; i < SpectatorList->Count; i++){
						Array::Copy(BitConverter::GetBytes(SpectatorList[i]->ID), 0, send, 1, 2);
						UDP->BeginSend(send, send->Length, SpectatorList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
					}

					SpectatorList->Clear();
				}
				finally{
					Monitor::Exit(InputHistory);
				}
			}
		}

		// IPアドレスの取得コマンド
		System::Void GetIPToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			GetIPAddress();
		}
		// ログのスクロールを固定
		System::Void LogLockToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			LogLockToolStripMenuItem->Checked ^= 1;
			MTOPTION.LOG_LOCK = LogLockToolStripMenuItem->Checked;
		}
		// メンバーリストの更新コマンド
		System::Void ReloadListToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			ReloadList();
		}

		System::Void toolStripMenuItemAfterRest_Click(System::Object^  sender, System::EventArgs^  e) {
			toolStripMenuItemAfterRest->Checked ^= 1;
			MTOPTION.AFTER_REST = toolStripMenuItemAfterRest->Checked;
		}

		System::Void toolStripMenuItemDelayAuto_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(0);
		}

		System::Void toolStripMenuItemDelay2_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(2);
		}

		System::Void toolStripMenuItemDelay3_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(3);
		}

		System::Void toolStripMenuItemDelay4_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(4);
		}

		System::Void toolStripMenuItemDelay5_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(5);
		}

		System::Void toolStripMenuItemDelay6_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(6);
		}

		System::Void toolStripMenuItemDelay7_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(7);
		}

		System::Void toolStripMenuItemDelay8_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(8);
		}

		System::Void toolStripMenuItemDelay9_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(9);
		}

		System::Void toolStripMenuItemDelay10_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(10);
		}

		System::Void toolStripMenuItemDelay11_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(11);
		}

		System::Void toolStripMenuItemDelay12_Click(System::Object^  sender, System::EventArgs^  e) {
			ResetDelay(12);
		}

		System::Void contextMenuItemCopy_Click(System::Object^  sender, System::EventArgs^  e) {
			richTextBoxLog->Copy();
		}

		System::Void richTextBoxLog_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkClickedEventArgs^  e) {
			// 強制終了対策
			try{
				Process::Start(e->LinkText);
			}
			catch(Exception^){
				WriteMessage("不正な文字列リンクです。\n", ErrorMessageColor);
			}
		}

		System::Void toolStripMenuItemVS_Click(System::Object^  sender, System::EventArgs^  e) {
			if(listBoxMember->SelectedIndex == -1){
				return;
			}

			if(ListView == LV_BLIND){
				RandomVersus();
			}
			else if(MTOPTION.CONNECTION_TYPE == CT_FREE || listBoxMember->SelectedIndex == 0){
				StartGame(RT_FREE);
			}
			else{
				StartGame(RT_VS);
			}

		}

		// 点滅関数
		System::Void WindowFlash() {
			// ウィンドウ点滅
			FLASHWINFO stfi;
			ZeroMemory(&stfi, sizeof(FLASHWINFO));
			stfi.cbSize = sizeof(FLASHWINFO);
			stfi.hwnd = reinterpret_cast<HWND&>(this->Handle);
			stfi.dwFlags = FLASHW_ALL;
			stfi.uCount = 3;
			stfi.dwTimeout = 0;
			FlashWindowEx(&stfi);
		}

		System::Void toolStripMenuItemWatch_Click(System::Object^  sender, System::EventArgs^  e) {
			if(listBoxMember->SelectedIndex == -1){
				return;
			}

			int state = MemberList[0]->STATE;
			array<BYTE>^ send = gcnew array<BYTE>(3);

			if(state == MS_FREE || state == MS_REST){
				// 観戦開始
				if(state == MS_FREE) ChangeState((BYTE)MS_WATCH);
				if(state == MS_REST) ChangeState((BYTE)MS_COUCH);

				WatchTarget = MemberList[listBoxMember->SelectedIndex]->IP_EP;
				TargetID    = MemberList[listBoxMember->SelectedIndex]->ID;
				WatchFrame  = 0;

				send[0] = PH_REQ_WATCH;
				Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, send, 1, 2);
				UDP->BeginSend(send, send->Length, WatchTarget, gcnew AsyncCallback(SendPackets), UDP);

				toolStripMenuItemWatch->Text = gcnew String("観戦をやめる");
			}
			else{
				QuitWatch(true);
			}
		}

		System::Void toolStripMenuItemPing_Click(System::Object^  sender, System::EventArgs^  e) {
			if(listBoxMember->SelectedIndex == -1){
				return;
			}

			int si = listBoxMember->SelectedIndex;
			array<BYTE>^ ping = gcnew array<BYTE>(1){ PH_PING };

			Ping = timeGetTime();
			UDP->BeginSend(ping, 1, MemberList[si]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
		}

		// キック
		System::Void toolStripMenuItemKick_Click(System::Object^  sender, System::EventArgs^  e) {
			if(listBoxMember->SelectedIndex == -1 || MTOPTION.CONNECTION_TYPE != CT_SERVER){
				return;
			}

			int index = listBoxMember->SelectedIndex;
			int id = MemberList[index]->ID;

			if(MessageBox::Show(String::Format("[ {0} ](ID:{1})をキックします。\nよろしいですか？", MemberList[index]->NAME, MemberList[index]->ID), "KICK", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
			}else{
				return;
			}
			
			try{
				// 本人に通知
				array<BYTE>^ send = gcnew array<BYTE>(3){ PH_LOST, 0xFF, 0xFF };
				UDP->BeginSend(send, send->Length, MemberList[index]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);

				if(ListView != LV_BLIND){
					WriteTime(0, SystemMessageColor);
					WriteMessage(String::Format("{0}(ID:{1})をキックしました。\n", MemberList[index]->NAME, MemberList[index]->ID), SystemMessageColor);
				}
				if(MemberList[0]->STATE == MS_WATCH || MemberList[0]->STATE == MS_COUCH){
					if(TargetID == MemberList[index]->ID){
						QuitWatch(false);
					}
				}

				// グッバイ
				MemberList->RemoveAt(index);
				listBoxMember->Items->RemoveAt(index);

				// 他のメンバーに通知
				array<BYTE>^ quit = gcnew array<BYTE>(3){ PH_QUIT };
				Array::Copy(BitConverter::GetBytes(id), 0, quit, 1, 2);

				for(int i = 1; i < MemberList->Count; i++){
					UDP->BeginSend(quit, quit->Length, MemberList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
					if(MTINFO.DEBUG){
						WriteMessage(String::Format("{0}に通知\n", MemberList[i]->ID), DebugMessageColor);
					}
				}
			}
			catch(Exception^ e){
				if(MTINFO.DEBUG){
					WriteMessage(String::Format("{0}\n", e->ToString()), DebugMessageColor);
				}
			}
			
		}

		System::Void contextMenuStripMember_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			
			toolStripMenuItemKick->Enabled     = false;

			if(listBoxMember->SelectedIndex == -1){
				toolStripMenuItemVS->Enabled       = false;
				toolStripMenuItemWatch->Enabled    = false;
				toolStripMenuItemPing->Enabled     = false;
				return;
			}

			int state = MemberList[listBoxMember->SelectedIndex]->STATE;

			toolStripMenuItemVS->Enabled       = false;
			toolStripMenuItemWatch->Enabled    = true;
			toolStripMenuItemPing->Enabled     = true;

			if(( ( state == MS_FREE || state == MS_SEEK) && ( MemberList[0]->STATE == MS_FREE || MemberList[0]->STATE == MS_SEEK )) || ListView == LV_BLIND){
				toolStripMenuItemVS->Enabled       = true;
			}
			if(listBoxMember->SelectedIndex == 0){
				if(state != MS_WATCH && state != MS_COUCH){
					toolStripMenuItemWatch->Enabled = false;
				}
				toolStripMenuItemPing->Enabled = false;
				toolStripMenuItemKick->Enabled = false;
			}else if(MemberList[listBoxMember->SelectedIndex]->TYPE == CT_SERVER || MTOPTION.CONNECTION_TYPE != CT_SERVER){
				toolStripMenuItemKick->Enabled = false;
			}else {
				toolStripMenuItemKick->Enabled = true;
			}

		}

		System::Void MainForm_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			e->Effect = DragDropEffects::None;

			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				array<String^>^ file = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false));
				String^ extension = Path::GetExtension(file[0])->ToLower();
				FileVersionInfo^ info = FileVersionInfo::GetVersionInfo(file[0]);

				if(extension == ".mtr" || (extension == ".exe" && (info->FileDescription == "２Ｄ格闘ツクール2nd." || info->FileDescription == "２Ｄ格闘ツクール９５"))){
					e->Effect = DragDropEffects::All;
				}
			}
		}

		System::Void MainForm_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				array<String^>^ file = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false));
				String^ extension = Path::GetExtension(file[0])->ToLower();

				if(extension == ".mtr"){
					ReplayFilePath = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false))[0];
					StartGame(RT_PLAYBACK);
				}
				else if(extension == ".exe"){
					if(Option == nullptr || Option->IsDisposed){
						FileVersionInfo^ info = FileVersionInfo::GetVersionInfo(file[0]);
						bool b2nd;

						IntPtr mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(file[0]);
						_tcscpy_s(MTOPTION.GAME_EXE, static_cast<PTCHAR>(mp.ToPointer()));
						Runtime::InteropServices::Marshal::FreeHGlobal(mp);

						// iniのパスを調べる
						TCHAR ini[_MAX_PATH], dir[_MAX_PATH], drive[_MAX_DRIVE];

						_tsplitpath_s(MTOPTION.GAME_EXE, drive, _MAX_DRIVE, dir, _MAX_DIR, NULL, 0, NULL, 0);

						if(info->FileDescription == "２Ｄ格闘ツクール2nd."){
							b2nd = true;
							_stprintf_s(ini, _T("%s%sgame.ini"), drive, dir);
						}
						else{
							b2nd = false;
							_stprintf_s(ini, _T("%s%s２Ｄ格闘ツクール９５.ini"), drive, dir);
						}

						if(File::Exists(gcnew String(ini))){
							if(b2nd){
								MTOPTION.MAX_STAGE = GetPrivateProfileInt(_T("GamePlay"), _T("Editor.TestPlay.StageNb"), 0, ini) + 1;
								MTOPTION.ROUND     = GetPrivateProfileInt(_T("GamePlay"), _T("Editor.TestPlay.VSSinglePlay"), 0, ini);
								MTOPTION.TIMER     = GetPrivateProfileInt(_T("GamePlay"), _T("Editor.TestPlay.time"), 0, ini);
							}
							else{
								MTOPTION.MAX_STAGE = GetPrivateProfileInt(_T("ゲーム設定"), _T("Editer.TestPlay.BackGroundNb"), 0, ini) + 1;
								MTOPTION.ROUND     = 2;
								MTOPTION.TIMER     = GetPrivateProfileInt(_T("ゲーム設定"), _T("Editer.TestPlay.time"), 0, ini);
							}

							MTOPTION.STAGE_SELECT = MTOPTION.MAX_STAGE == 1 ? 1 : 0;
						}

						WriteMessage(String::Format("プレイするゲームを\"{0}\"に変更しました。\n", Path::GetFileNameWithoutExtension(file[0])), SystemMessageColor);
					}
					else{
						Option->SetGameExePath(file[0]);
					}
				}
			}
		}

		// プロファイル変更
		System::Void toolStripDropDownItemProfile_Click(System::Object^ sender, System::EventArgs^ e) {
			if(((ToolStripDropDownItem^)sender)->Text == gcnew String(MTOPTION.PROFILE)){
				return;
			}
			String^ buf = ((ToolStripDropDownItem^)sender)->Text;

			IntPtr mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(buf);
			_tcscpy_s(MTOPTION.PROFILE, static_cast<PTCHAR>(mp.ToPointer()));
			Runtime::InteropServices::Marshal::FreeHGlobal(mp);

			toolStripDropDownButtonProfile->Text = buf;

			LoadMTOption();
		}
		System::Void toolStripMenuItemSeek_Click(System::Object^ sender, System::EventArgs^ e) {
			this->SeekToolStripMenuItem_Click(nullptr, nullptr);
		}
		// 自動休憩有効
		System::Void toolStripMenuItemAutoRestEnable_Click(System::Object^  sender, System::EventArgs^  e) {
			toolStripMenuItemAutoRestEnable->Checked ^= 1;
			MTOPTION.AUTO_REST = toolStripMenuItemAutoRestEnable->Checked;
			if(MTOPTION.AUTO_REST){
				if(UDP != nullptr && AutoRestThread == nullptr && MemberList[0]->STATE == MS_FREE){
					AutoRestThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::RunAutoRest));
					AutoRestThread->Start();
				}
			}else{
				if(AutoRestThread != nullptr && AutoRestThread->IsAlive){
					AutoRestRanging = false;
					AutoRestThread->Abort();
					AutoRestThread = nullptr;
				}
			}
		}
		System::Void toolStripMenuItemAutoRestTime5_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(5);
			toolStripMenuItemAutoRestTime5->Checked = 1;
		}
		System::Void toolStripMenuItemAutoRestTime10_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(10);
			toolStripMenuItemAutoRestTime10->Checked = 1;
		}
		System::Void toolStripMenuItemAutoRestTime15_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(15);
			toolStripMenuItemAutoRestTime15->Checked = 1;
		}
		System::Void toolStripMenuItemAutoRestTime20_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(20);
			toolStripMenuItemAutoRestTime20->Checked = 1;
		}
		System::Void toolStripMenuItemAutoRestTime30_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(30);
			toolStripMenuItemAutoRestTime30->Checked = 1;
		}
		System::Void toolStripMenuItemAutoRestTime60_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(60);
			toolStripMenuItemAutoRestTime60->Checked = 1;
		}
		System::Void toolStripMenuItemAutoRestTime120_Click(System::Object^  sender, System::EventArgs^  e) {
			SetAutoRestTime(120);
			toolStripMenuItemAutoRestTime120->Checked = 1;
		}
		// ログのテキストを折り返す
		System::Void toolStripMenuItemWordWrap_Click(System::Object^ sender, System::EventArgs^  e) {
			ChangeLogWordWrap();
		}
	};
}
