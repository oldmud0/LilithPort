#pragma once

#include "stdafx.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Diagnostics;

namespace LilithPort {

	/// <summary>
	/// OptionForm の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class OptionForm : public System::Windows::Forms::Form
	{
	public:
		OptionForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~OptionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonApply;
	private: System::Windows::Forms::Button^  buttonCancel;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;

	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::TabPage^  tabPageSound;
	private: System::Windows::Forms::TabPage^  tabPagePath;
	private: System::Windows::Forms::TextBox^  textBoxGameExe;
	private: System::Windows::Forms::Button^  buttonReplayFolder;
	private: System::Windows::Forms::Button^  buttonGameExe;
	private: System::Windows::Forms::TextBox^  textBoxReplayFolder;
	private: System::Windows::Forms::TextBox^  textBoxVSSound;
	private: System::Windows::Forms::Button^  buttonNoticeSound;
	private: System::Windows::Forms::Button^  buttonVSSound;
	private: System::Windows::Forms::TextBox^  textBoxNoticeSound;
	private: System::Windows::Forms::TabControl^  tabControlOption;
	private: System::Windows::Forms::TabPage^  tabPageGame;





	private: System::Windows::Forms::GroupBox^  groupBoxRun;
	private: System::Windows::Forms::CheckBox^  checkBoxWindowSize;
	private: System::Windows::Forms::CheckBox^  checkBoxHitJudge;
	private: System::Windows::Forms::GroupBox^  groupBoxNet;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownMaxConnection;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::GroupBox^  groupBoxView;
	private: System::Windows::Forms::CheckBox^  checkBoxVersus;
	private: System::Windows::Forms::CheckBox^  checkBoxName;
	private: System::Windows::Forms::CheckBox^  checkBoxFramerate;
	private: System::Windows::Forms::CheckBox^  checkBoxRand;
	private: System::Windows::Forms::GroupBox^  groupBoxSetting;

	private: System::Windows::Forms::NumericUpDown^  numericUpDownMaxStage;
	private: System::Windows::Forms::Label^  labelMaxStage;
	private: System::Windows::Forms::Label^  labelStageSelect;

	private: System::Windows::Forms::NumericUpDown^  numericUpDownStageSelect;

	private: System::Windows::Forms::CheckBox^  checkBoxDivide;
	private: System::Windows::Forms::RadioButton^  radioButtonReplayVersion2;
	private: System::Windows::Forms::RadioButton^  radioButtonReplayVersion1;
	private: System::Windows::Forms::TabPage^  tabPageColor;
	private: System::Windows::Forms::GroupBox^  groupBoxMessageColor;
	private: System::Windows::Forms::Button^  buttonDebugMessage;
	private: System::Windows::Forms::Button^  buttonErrorMessage;
	private: System::Windows::Forms::Button^  buttonSystemMessage;
	private: System::Windows::Forms::GroupBox^  groupBoxOthersColor;
	private: System::Windows::Forms::Button^  buttonSecret;
	private: System::Windows::Forms::Button^  buttonCommentBack;
	private: System::Windows::Forms::Button^  buttonNoticeBack;
	private: System::Windows::Forms::GroupBox^  groupBoxStateColor;
	private: System::Windows::Forms::Button^  buttonWatchState;
	private: System::Windows::Forms::Button^  buttonVSState;
	private: System::Windows::Forms::Button^  buttonRestState;
	private: System::Windows::Forms::Button^  buttonSeekState;
	private: System::Windows::Forms::GroupBox^  groupBoxNameColor;
	private: System::Windows::Forms::Button^  buttonClientName;
	private: System::Windows::Forms::Button^  buttonHostName;
	private: System::Windows::Forms::Button^  buttonServerName;
	private: System::Windows::Forms::GroupBox^  groupBoxNoticeSound;
	private: System::Windows::Forms::GroupBox^  groupBoxVSSound;
	private: System::Windows::Forms::GroupBox^  groupBoxEnterSound;
	private: System::Windows::Forms::TextBox^  textBoxEnterSound;
	private: System::Windows::Forms::Button^  buttonEnterSound;
	private: System::Windows::Forms::GroupBox^  groupBoxReplayFolder;
	private: System::Windows::Forms::GroupBox^  groupBoxGameExe;
	private: System::Windows::Forms::GroupBox^  groupBoxSimulate;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownSimDelay;
	private: System::Windows::Forms::Label^  labelSimDelay;


	private: System::Windows::Forms::TextBox^  textBoxComment;
	private: System::Windows::Forms::Label^  labelComment;
	private: System::Windows::Forms::GroupBox^  groupBoxSave;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownRound;
	private: System::Windows::Forms::Label^  labelRound;
	private: System::Windows::Forms::Label^  labelTimer;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownTimer;

	private: System::Windows::Forms::TabPage^  tabPageVolume;
	private: System::Windows::Forms::GroupBox^  groupBoxSE;
	private: System::Windows::Forms::Label^  labelSE;
	private: System::Windows::Forms::TrackBar^  trackBarSE;
	private: System::Windows::Forms::GroupBox^  groupBoxBGM;
	private: System::Windows::Forms::Label^  labelBGM;
	private: System::Windows::Forms::TrackBar^  trackBarBGM;
	private: System::Windows::Forms::GroupBox^  groupBoxMidi;
	private: System::Windows::Forms::Label^  labelMidi;
	private: System::Windows::Forms::TrackBar^  trackBarMidi;
private: System::Windows::Forms::TabPage^  tabPageIP;
private: System::Windows::Forms::GroupBox^  Base64groupBox;
private: System::Windows::Forms::TextBox^  Base64textBox;

private: System::Windows::Forms::GroupBox^  IPgroupBox;
private: System::Windows::Forms::Button^  Convertbutton;
private: System::Windows::Forms::TextBox^  IPtextBox;
private: System::Windows::Forms::Label^  discriptionlabel;
private: System::Windows::Forms::Button^  AddPortbutton;
private: System::Windows::Forms::GroupBox^  groupBoxName;
private: System::Windows::Forms::Button^  buttonNameSound;



private: System::Windows::Forms::TextBox^  textBoxNameSound;
private: System::Windows::Forms::TabPage^  tabPageDetails;
private: System::Windows::Forms::GroupBox^  groupBoxDetails;
private: System::Windows::Forms::CheckBox^  checkBoxTalkFlash;

private: System::Windows::Forms::CheckBox^  checkBoxNameFlash;
private: System::Windows::Forms::GroupBox^  groupBoxTalkSound;
private: System::Windows::Forms::CheckBox^  checkBoxNameSound;
private: System::Windows::Forms::CheckBox^  checkBoxEnterSound;
private: System::Windows::Forms::CheckBox^  checkBoxNoticeSound;
private: System::Windows::Forms::CheckBox^  checkBoxVSSound;
private: System::Windows::Forms::CheckBox^  checkBoxTalkSound;
private: System::Windows::Forms::Button^  buttonTalkSound;
private: System::Windows::Forms::TextBox^  textBoxTalkSound;
private: System::Windows::Forms::CheckBox^  checkBoxGetIP;
private: System::Windows::Forms::Button^  buttonNoticeSoundPlay;

private: System::Windows::Forms::Button^  buttonVSSoundPlay;
private: System::Windows::Forms::Button^  buttonEnterSoundPlay;
private: System::Windows::Forms::Button^  buttonTalkSoundPlay;
private: System::Windows::Forms::Button^  buttonNameSoundPlay;
private: System::Windows::Forms::GroupBox^  groupBoxSeekSound;
private: System::Windows::Forms::Button^  buttonSeekSound;

private: System::Windows::Forms::TextBox^  textBoxSeekSound;
private: System::Windows::Forms::Button^  buttonSeekSoundPlay;
private: System::Windows::Forms::CheckBox^  checkBoxSeekSound;
private: System::Windows::Forms::GroupBox^  groupBoxKeywordSound;
private: System::Windows::Forms::TextBox^  textBoxKeywordSoundPath;

private: System::Windows::Forms::Label^  labelKeywordSound;
private: System::Windows::Forms::TextBox^  textBoxKeyword;

private: System::Windows::Forms::Button^  buttonKeywordSound;
private: System::Windows::Forms::Button^  buttonKeywordSoundPlay;
private: System::Windows::Forms::CheckBox^  checkBoxKeywordSound;
private: System::Windows::Forms::GroupBox^  groupBoxTeamOption;
private: System::Windows::Forms::CheckBox^  checkBoxTeamRoundHP;
private: System::Windows::Forms::Label^  labelTeamRoundHP;
private: System::Windows::Forms::CheckBox^  checkBoxShowGameOption;
private: System::Windows::Forms::GroupBox^  groupBoxProfile;
private: System::Windows::Forms::ComboBox^  comboBoxProfile;
private: System::Windows::Forms::Button^  buttonCopyProfile;
private: System::Windows::Forms::Button^  buttonDeleteProfile;
private: System::Windows::Forms::TextBox^  textBoxProfileName;

private: System::Windows::Forms::Button^  buttonAddProfile;
private: System::Windows::Forms::Label^  labelProfileName;
private: System::Windows::Forms::Button^  buttonSaveProfile;
private: System::Windows::Forms::TextBox^  textBoxMTAddr;

private: System::Windows::Forms::Label^  labelAddrBase64;
private: System::Windows::Forms::Label^  labelAddrMT;
private: System::Windows::Forms::CheckBox^  checkBoxShowResult;




	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(OptionForm::typeid));
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonApply = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->tabPageSound = (gcnew System::Windows::Forms::TabPage());
			this->groupBoxKeywordSound = (gcnew System::Windows::Forms::GroupBox());
			this->buttonKeywordSoundPlay = (gcnew System::Windows::Forms::Button());
			this->checkBoxKeywordSound = (gcnew System::Windows::Forms::CheckBox());
			this->buttonKeywordSound = (gcnew System::Windows::Forms::Button());
			this->textBoxKeywordSoundPath = (gcnew System::Windows::Forms::TextBox());
			this->labelKeywordSound = (gcnew System::Windows::Forms::Label());
			this->textBoxKeyword = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxSeekSound = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSeekSoundPlay = (gcnew System::Windows::Forms::Button());
			this->checkBoxSeekSound = (gcnew System::Windows::Forms::CheckBox());
			this->buttonSeekSound = (gcnew System::Windows::Forms::Button());
			this->textBoxSeekSound = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxTalkSound = (gcnew System::Windows::Forms::GroupBox());
			this->buttonTalkSoundPlay = (gcnew System::Windows::Forms::Button());
			this->checkBoxTalkSound = (gcnew System::Windows::Forms::CheckBox());
			this->buttonTalkSound = (gcnew System::Windows::Forms::Button());
			this->textBoxTalkSound = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxName = (gcnew System::Windows::Forms::GroupBox());
			this->buttonNameSoundPlay = (gcnew System::Windows::Forms::Button());
			this->checkBoxNameSound = (gcnew System::Windows::Forms::CheckBox());
			this->buttonNameSound = (gcnew System::Windows::Forms::Button());
			this->textBoxNameSound = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxEnterSound = (gcnew System::Windows::Forms::GroupBox());
			this->buttonEnterSoundPlay = (gcnew System::Windows::Forms::Button());
			this->checkBoxEnterSound = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxEnterSound = (gcnew System::Windows::Forms::TextBox());
			this->buttonEnterSound = (gcnew System::Windows::Forms::Button());
			this->groupBoxNoticeSound = (gcnew System::Windows::Forms::GroupBox());
			this->buttonNoticeSoundPlay = (gcnew System::Windows::Forms::Button());
			this->checkBoxNoticeSound = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxNoticeSound = (gcnew System::Windows::Forms::TextBox());
			this->buttonNoticeSound = (gcnew System::Windows::Forms::Button());
			this->groupBoxVSSound = (gcnew System::Windows::Forms::GroupBox());
			this->buttonVSSoundPlay = (gcnew System::Windows::Forms::Button());
			this->checkBoxVSSound = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxVSSound = (gcnew System::Windows::Forms::TextBox());
			this->buttonVSSound = (gcnew System::Windows::Forms::Button());
			this->tabPagePath = (gcnew System::Windows::Forms::TabPage());
			this->groupBoxProfile = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSaveProfile = (gcnew System::Windows::Forms::Button());
			this->buttonAddProfile = (gcnew System::Windows::Forms::Button());
			this->labelProfileName = (gcnew System::Windows::Forms::Label());
			this->buttonDeleteProfile = (gcnew System::Windows::Forms::Button());
			this->textBoxProfileName = (gcnew System::Windows::Forms::TextBox());
			this->buttonCopyProfile = (gcnew System::Windows::Forms::Button());
			this->comboBoxProfile = (gcnew System::Windows::Forms::ComboBox());
			this->groupBoxReplayFolder = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxReplayFolder = (gcnew System::Windows::Forms::TextBox());
			this->buttonReplayFolder = (gcnew System::Windows::Forms::Button());
			this->checkBoxDivide = (gcnew System::Windows::Forms::CheckBox());
			this->groupBoxNet = (gcnew System::Windows::Forms::GroupBox());
			this->labelComment = (gcnew System::Windows::Forms::Label());
			this->numericUpDownMaxConnection = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBoxComment = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBoxGameExe = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxGameExe = (gcnew System::Windows::Forms::TextBox());
			this->buttonGameExe = (gcnew System::Windows::Forms::Button());
			this->groupBoxSave = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonReplayVersion1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonReplayVersion2 = (gcnew System::Windows::Forms::RadioButton());
			this->tabControlOption = (gcnew System::Windows::Forms::TabControl());
			this->tabPageGame = (gcnew System::Windows::Forms::TabPage());
			this->groupBoxTeamOption = (gcnew System::Windows::Forms::GroupBox());
			this->labelTeamRoundHP = (gcnew System::Windows::Forms::Label());
			this->checkBoxTeamRoundHP = (gcnew System::Windows::Forms::CheckBox());
			this->groupBoxSimulate = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDownSimDelay = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelSimDelay = (gcnew System::Windows::Forms::Label());
			this->groupBoxRun = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxWindowSize = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxHitJudge = (gcnew System::Windows::Forms::CheckBox());
			this->groupBoxView = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxVersus = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxName = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxFramerate = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxRand = (gcnew System::Windows::Forms::CheckBox());
			this->groupBoxSetting = (gcnew System::Windows::Forms::GroupBox());
			this->numericUpDownRound = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelRound = (gcnew System::Windows::Forms::Label());
			this->labelTimer = (gcnew System::Windows::Forms::Label());
			this->numericUpDownTimer = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownMaxStage = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelMaxStage = (gcnew System::Windows::Forms::Label());
			this->labelStageSelect = (gcnew System::Windows::Forms::Label());
			this->numericUpDownStageSelect = (gcnew System::Windows::Forms::NumericUpDown());
			this->tabPageColor = (gcnew System::Windows::Forms::TabPage());
			this->groupBoxMessageColor = (gcnew System::Windows::Forms::GroupBox());
			this->buttonDebugMessage = (gcnew System::Windows::Forms::Button());
			this->buttonErrorMessage = (gcnew System::Windows::Forms::Button());
			this->buttonSystemMessage = (gcnew System::Windows::Forms::Button());
			this->groupBoxOthersColor = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSecret = (gcnew System::Windows::Forms::Button());
			this->buttonCommentBack = (gcnew System::Windows::Forms::Button());
			this->buttonNoticeBack = (gcnew System::Windows::Forms::Button());
			this->groupBoxStateColor = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSeekState = (gcnew System::Windows::Forms::Button());
			this->buttonWatchState = (gcnew System::Windows::Forms::Button());
			this->buttonVSState = (gcnew System::Windows::Forms::Button());
			this->buttonRestState = (gcnew System::Windows::Forms::Button());
			this->groupBoxNameColor = (gcnew System::Windows::Forms::GroupBox());
			this->buttonClientName = (gcnew System::Windows::Forms::Button());
			this->buttonHostName = (gcnew System::Windows::Forms::Button());
			this->buttonServerName = (gcnew System::Windows::Forms::Button());
			this->tabPageVolume = (gcnew System::Windows::Forms::TabPage());
			this->groupBoxMidi = (gcnew System::Windows::Forms::GroupBox());
			this->labelMidi = (gcnew System::Windows::Forms::Label());
			this->trackBarMidi = (gcnew System::Windows::Forms::TrackBar());
			this->groupBoxSE = (gcnew System::Windows::Forms::GroupBox());
			this->labelSE = (gcnew System::Windows::Forms::Label());
			this->trackBarSE = (gcnew System::Windows::Forms::TrackBar());
			this->groupBoxBGM = (gcnew System::Windows::Forms::GroupBox());
			this->labelBGM = (gcnew System::Windows::Forms::Label());
			this->trackBarBGM = (gcnew System::Windows::Forms::TrackBar());
			this->tabPageIP = (gcnew System::Windows::Forms::TabPage());
			this->AddPortbutton = (gcnew System::Windows::Forms::Button());
			this->discriptionlabel = (gcnew System::Windows::Forms::Label());
			this->Convertbutton = (gcnew System::Windows::Forms::Button());
			this->Base64groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->labelAddrMT = (gcnew System::Windows::Forms::Label());
			this->textBoxMTAddr = (gcnew System::Windows::Forms::TextBox());
			this->labelAddrBase64 = (gcnew System::Windows::Forms::Label());
			this->Base64textBox = (gcnew System::Windows::Forms::TextBox());
			this->IPgroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->IPtextBox = (gcnew System::Windows::Forms::TextBox());
			this->tabPageDetails = (gcnew System::Windows::Forms::TabPage());
			this->groupBoxDetails = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxShowGameOption = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxNameFlash = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxGetIP = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxTalkFlash = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxShowResult = (gcnew System::Windows::Forms::CheckBox());
			this->tabPageSound->SuspendLayout();
			this->groupBoxKeywordSound->SuspendLayout();
			this->groupBoxSeekSound->SuspendLayout();
			this->groupBoxTalkSound->SuspendLayout();
			this->groupBoxName->SuspendLayout();
			this->groupBoxEnterSound->SuspendLayout();
			this->groupBoxNoticeSound->SuspendLayout();
			this->groupBoxVSSound->SuspendLayout();
			this->tabPagePath->SuspendLayout();
			this->groupBoxProfile->SuspendLayout();
			this->groupBoxReplayFolder->SuspendLayout();
			this->groupBoxNet->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownMaxConnection))->BeginInit();
			this->groupBoxGameExe->SuspendLayout();
			this->groupBoxSave->SuspendLayout();
			this->tabControlOption->SuspendLayout();
			this->tabPageGame->SuspendLayout();
			this->groupBoxTeamOption->SuspendLayout();
			this->groupBoxSimulate->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownSimDelay))->BeginInit();
			this->groupBoxRun->SuspendLayout();
			this->groupBoxView->SuspendLayout();
			this->groupBoxSetting->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownRound))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownTimer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownMaxStage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownStageSelect))->BeginInit();
			this->tabPageColor->SuspendLayout();
			this->groupBoxMessageColor->SuspendLayout();
			this->groupBoxOthersColor->SuspendLayout();
			this->groupBoxStateColor->SuspendLayout();
			this->groupBoxNameColor->SuspendLayout();
			this->tabPageVolume->SuspendLayout();
			this->groupBoxMidi->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarMidi))->BeginInit();
			this->groupBoxSE->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarSE))->BeginInit();
			this->groupBoxBGM->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarBGM))->BeginInit();
			this->tabPageIP->SuspendLayout();
			this->Base64groupBox->SuspendLayout();
			this->IPgroupBox->SuspendLayout();
			this->tabPageDetails->SuspendLayout();
			this->groupBoxDetails->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(160, 327);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(64, 24);
			this->buttonOK->TabIndex = 7;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &OptionForm::buttonOK_Click);
			// 
			// buttonApply
			// 
			this->buttonApply->Location = System::Drawing::Point(230, 327);
			this->buttonApply->Name = L"buttonApply";
			this->buttonApply->Size = System::Drawing::Size(64, 24);
			this->buttonApply->TabIndex = 8;
			this->buttonApply->Text = L"適用";
			this->buttonApply->UseVisualStyleBackColor = true;
			this->buttonApply->Click += gcnew System::EventHandler(this, &OptionForm::buttonApply_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->Location = System::Drawing::Point(300, 327);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(64, 24);
			this->buttonCancel->TabIndex = 9;
			this->buttonCancel->Text = L"キャンセル";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &OptionForm::buttonCancel_Click);
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->Description = L"リプレイ保存フォルダ";
			// 
			// colorDialog1
			// 
			this->colorDialog1->FullOpen = true;
			// 
			// tabPageSound
			// 
			this->tabPageSound->AutoScroll = true;
			this->tabPageSound->AutoScrollMinSize = System::Drawing::Size(0, 460);
			this->tabPageSound->Controls->Add(this->groupBoxKeywordSound);
			this->tabPageSound->Controls->Add(this->groupBoxSeekSound);
			this->tabPageSound->Controls->Add(this->groupBoxTalkSound);
			this->tabPageSound->Controls->Add(this->groupBoxName);
			this->tabPageSound->Controls->Add(this->groupBoxEnterSound);
			this->tabPageSound->Controls->Add(this->groupBoxNoticeSound);
			this->tabPageSound->Controls->Add(this->groupBoxVSSound);
			this->tabPageSound->Location = System::Drawing::Point(4, 22);
			this->tabPageSound->Name = L"tabPageSound";
			this->tabPageSound->Padding = System::Windows::Forms::Padding(3);
			this->tabPageSound->Size = System::Drawing::Size(369, 295);
			this->tabPageSound->TabIndex = 3;
			this->tabPageSound->Text = L"音声";
			this->tabPageSound->UseVisualStyleBackColor = true;
			// 
			// groupBoxKeywordSound
			// 
			this->groupBoxKeywordSound->Controls->Add(this->buttonKeywordSoundPlay);
			this->groupBoxKeywordSound->Controls->Add(this->checkBoxKeywordSound);
			this->groupBoxKeywordSound->Controls->Add(this->buttonKeywordSound);
			this->groupBoxKeywordSound->Controls->Add(this->textBoxKeywordSoundPath);
			this->groupBoxKeywordSound->Controls->Add(this->labelKeywordSound);
			this->groupBoxKeywordSound->Controls->Add(this->textBoxKeyword);
			this->groupBoxKeywordSound->Location = System::Drawing::Point(9, 346);
			this->groupBoxKeywordSound->Name = L"groupBoxKeywordSound";
			this->groupBoxKeywordSound->Size = System::Drawing::Size(335, 96);
			this->groupBoxKeywordSound->TabIndex = 7;
			this->groupBoxKeywordSound->TabStop = false;
			this->groupBoxKeywordSound->Text = L"キーワードで再生";
			// 
			// buttonKeywordSoundPlay
			// 
			this->buttonKeywordSoundPlay->Location = System::Drawing::Point(260, 62);
			this->buttonKeywordSoundPlay->Name = L"buttonKeywordSoundPlay";
			this->buttonKeywordSoundPlay->Size = System::Drawing::Size(65, 20);
			this->buttonKeywordSoundPlay->TabIndex = 5;
			this->buttonKeywordSoundPlay->Text = L"再生";
			this->buttonKeywordSoundPlay->UseVisualStyleBackColor = true;
			this->buttonKeywordSoundPlay->Click += gcnew System::EventHandler(this, &OptionForm::buttonKeywordSoundPlay_Click);
			// 
			// checkBoxKeywordSound
			// 
			this->checkBoxKeywordSound->AutoSize = true;
			this->checkBoxKeywordSound->Location = System::Drawing::Point(197, 65);
			this->checkBoxKeywordSound->Name = L"checkBoxKeywordSound";
			this->checkBoxKeywordSound->Size = System::Drawing::Size(48, 16);
			this->checkBoxKeywordSound->TabIndex = 4;
			this->checkBoxKeywordSound->Text = L"有効";
			this->checkBoxKeywordSound->UseVisualStyleBackColor = true;
			this->checkBoxKeywordSound->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// buttonKeywordSound
			// 
			this->buttonKeywordSound->Location = System::Drawing::Point(166, 62);
			this->buttonKeywordSound->Name = L"buttonKeywordSound";
			this->buttonKeywordSound->Size = System::Drawing::Size(24, 20);
			this->buttonKeywordSound->TabIndex = 3;
			this->buttonKeywordSound->Text = L"...";
			this->buttonKeywordSound->UseVisualStyleBackColor = true;
			this->buttonKeywordSound->Click += gcnew System::EventHandler(this, &OptionForm::buttonKeywordSound_Click);
			// 
			// textBoxKeywordSoundPath
			// 
			this->textBoxKeywordSoundPath->AllowDrop = true;
			this->textBoxKeywordSoundPath->Location = System::Drawing::Point(10, 63);
			this->textBoxKeywordSoundPath->Name = L"textBoxKeywordSoundPath";
			this->textBoxKeywordSoundPath->Size = System::Drawing::Size(150, 19);
			this->textBoxKeywordSoundPath->TabIndex = 2;
			this->textBoxKeywordSoundPath->TextChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->textBoxKeywordSoundPath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxKeywordSound_DragDrop);
			this->textBoxKeywordSoundPath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxSound_DragEnter);
			// 
			// labelKeywordSound
			// 
			this->labelKeywordSound->AutoSize = true;
			this->labelKeywordSound->Location = System::Drawing::Point(10, 16);
			this->labelKeywordSound->Name = L"labelKeywordSound";
			this->labelKeywordSound->Size = System::Drawing::Size(141, 12);
			this->labelKeywordSound->TabIndex = 1;
			this->labelKeywordSound->Text = L"コンマ( , )で複数登録が可能";
			// 
			// textBoxKeyword
			// 
			this->textBoxKeyword->Location = System::Drawing::Point(10, 35);
			this->textBoxKeyword->Name = L"textBoxKeyword";
			this->textBoxKeyword->Size = System::Drawing::Size(315, 19);
			this->textBoxKeyword->TabIndex = 0;
			this->textBoxKeyword->TextChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// groupBoxSeekSound
			// 
			this->groupBoxSeekSound->Controls->Add(this->buttonSeekSoundPlay);
			this->groupBoxSeekSound->Controls->Add(this->checkBoxSeekSound);
			this->groupBoxSeekSound->Controls->Add(this->buttonSeekSound);
			this->groupBoxSeekSound->Controls->Add(this->textBoxSeekSound);
			this->groupBoxSeekSound->Location = System::Drawing::Point(8, 287);
			this->groupBoxSeekSound->Name = L"groupBoxSeekSound";
			this->groupBoxSeekSound->Size = System::Drawing::Size(336, 52);
			this->groupBoxSeekSound->TabIndex = 6;
			this->groupBoxSeekSound->TabStop = false;
			this->groupBoxSeekSound->Text = L"対戦募集で再生";
			// 
			// buttonSeekSoundPlay
			// 
			this->buttonSeekSoundPlay->Location = System::Drawing::Point(261, 19);
			this->buttonSeekSoundPlay->Name = L"buttonSeekSoundPlay";
			this->buttonSeekSoundPlay->Size = System::Drawing::Size(65, 20);
			this->buttonSeekSoundPlay->TabIndex = 3;
			this->buttonSeekSoundPlay->Text = L"再生";
			this->buttonSeekSoundPlay->UseVisualStyleBackColor = true;
			this->buttonSeekSoundPlay->Click += gcnew System::EventHandler(this, &OptionForm::buttonSeekSoundPlay_Click);
			// 
			// checkBoxSeekSound
			// 
			this->checkBoxSeekSound->AutoSize = true;
			this->checkBoxSeekSound->Location = System::Drawing::Point(197, 21);
			this->checkBoxSeekSound->Name = L"checkBoxSeekSound";
			this->checkBoxSeekSound->Size = System::Drawing::Size(48, 16);
			this->checkBoxSeekSound->TabIndex = 2;
			this->checkBoxSeekSound->Text = L"有効";
			this->checkBoxSeekSound->UseVisualStyleBackColor = true;
			this->checkBoxSeekSound->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// buttonSeekSound
			// 
			this->buttonSeekSound->Location = System::Drawing::Point(167, 18);
			this->buttonSeekSound->Name = L"buttonSeekSound";
			this->buttonSeekSound->Size = System::Drawing::Size(24, 20);
			this->buttonSeekSound->TabIndex = 1;
			this->buttonSeekSound->Text = L"...";
			this->buttonSeekSound->UseVisualStyleBackColor = true;
			this->buttonSeekSound->Click += gcnew System::EventHandler(this, &OptionForm::buttonSeekSound_Click);
			// 
			// textBoxSeekSound
			// 
			this->textBoxSeekSound->AllowDrop = true;
			this->textBoxSeekSound->Location = System::Drawing::Point(10, 19);
			this->textBoxSeekSound->Name = L"textBoxSeekSound";
			this->textBoxSeekSound->Size = System::Drawing::Size(151, 19);
			this->textBoxSeekSound->TabIndex = 0;
			this->textBoxSeekSound->TextChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->textBoxSeekSound->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxSeekSound_DragDrop);
			this->textBoxSeekSound->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxSound_DragEnter);
			// 
			// groupBoxTalkSound
			// 
			this->groupBoxTalkSound->Controls->Add(this->buttonTalkSoundPlay);
			this->groupBoxTalkSound->Controls->Add(this->checkBoxTalkSound);
			this->groupBoxTalkSound->Controls->Add(this->buttonTalkSound);
			this->groupBoxTalkSound->Controls->Add(this->textBoxTalkSound);
			this->groupBoxTalkSound->Location = System::Drawing::Point(8, 228);
			this->groupBoxTalkSound->Name = L"groupBoxTalkSound";
			this->groupBoxTalkSound->Size = System::Drawing::Size(336, 52);
			this->groupBoxTalkSound->TabIndex = 5;
			this->groupBoxTalkSound->TabStop = false;
			this->groupBoxTalkSound->Text = L"発言で再生";
			// 
			// buttonTalkSoundPlay
			// 
			this->buttonTalkSoundPlay->Location = System::Drawing::Point(261, 19);
			this->buttonTalkSoundPlay->Name = L"buttonTalkSoundPlay";
			this->buttonTalkSoundPlay->Size = System::Drawing::Size(65, 20);
			this->buttonTalkSoundPlay->TabIndex = 3;
			this->buttonTalkSoundPlay->Text = L"再生";
			this->buttonTalkSoundPlay->UseVisualStyleBackColor = true;
			this->buttonTalkSoundPlay->Click += gcnew System::EventHandler(this, &OptionForm::buttonTalkSoundPlay_Click);
			// 
			// checkBoxTalkSound
			// 
			this->checkBoxTalkSound->AutoSize = true;
			this->checkBoxTalkSound->Location = System::Drawing::Point(197, 21);
			this->checkBoxTalkSound->Name = L"checkBoxTalkSound";
			this->checkBoxTalkSound->Size = System::Drawing::Size(48, 16);
			this->checkBoxTalkSound->TabIndex = 2;
			this->checkBoxTalkSound->Text = L"有効";
			this->checkBoxTalkSound->UseVisualStyleBackColor = true;
			this->checkBoxTalkSound->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// buttonTalkSound
			// 
			this->buttonTalkSound->Location = System::Drawing::Point(167, 18);
			this->buttonTalkSound->Name = L"buttonTalkSound";
			this->buttonTalkSound->Size = System::Drawing::Size(24, 20);
			this->buttonTalkSound->TabIndex = 1;
			this->buttonTalkSound->Text = L"...";
			this->buttonTalkSound->UseVisualStyleBackColor = true;
			this->buttonTalkSound->Click += gcnew System::EventHandler(this, &OptionForm::buttonTalkSound_Click);
			// 
			// textBoxTalkSound
			// 
			this->textBoxTalkSound->AllowDrop = true;
			this->textBoxTalkSound->Location = System::Drawing::Point(10, 19);
			this->textBoxTalkSound->Name = L"textBoxTalkSound";
			this->textBoxTalkSound->Size = System::Drawing::Size(151, 19);
			this->textBoxTalkSound->TabIndex = 0;
			this->textBoxTalkSound->TextChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->textBoxTalkSound->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxTalkSound_DragDrop);
			this->textBoxTalkSound->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxSound_DragEnter);
			// 
			// groupBoxName
			// 
			this->groupBoxName->Controls->Add(this->buttonNameSoundPlay);
			this->groupBoxName->Controls->Add(this->checkBoxNameSound);
			this->groupBoxName->Controls->Add(this->buttonNameSound);
			this->groupBoxName->Controls->Add(this->textBoxNameSound);
			this->groupBoxName->Location = System::Drawing::Point(8, 173);
			this->groupBoxName->Name = L"groupBoxName";
			this->groupBoxName->Size = System::Drawing::Size(336, 52);
			this->groupBoxName->TabIndex = 4;
			this->groupBoxName->TabStop = false;
			this->groupBoxName->Text = L"ニックネームが呼ばれたら再生";
			// 
			// buttonNameSoundPlay
			// 
			this->buttonNameSoundPlay->Location = System::Drawing::Point(261, 19);
			this->buttonNameSoundPlay->Name = L"buttonNameSoundPlay";
			this->buttonNameSoundPlay->Size = System::Drawing::Size(65, 20);
			this->buttonNameSoundPlay->TabIndex = 5;
			this->buttonNameSoundPlay->Text = L"再生";
			this->buttonNameSoundPlay->UseVisualStyleBackColor = true;
			this->buttonNameSoundPlay->Click += gcnew System::EventHandler(this, &OptionForm::buttonNameSoundPlay_Click);
			// 
			// checkBoxNameSound
			// 
			this->checkBoxNameSound->AutoSize = true;
			this->checkBoxNameSound->Location = System::Drawing::Point(197, 21);
			this->checkBoxNameSound->Name = L"checkBoxNameSound";
			this->checkBoxNameSound->Size = System::Drawing::Size(48, 16);
			this->checkBoxNameSound->TabIndex = 4;
			this->checkBoxNameSound->Text = L"有効";
			this->checkBoxNameSound->UseVisualStyleBackColor = true;
			this->checkBoxNameSound->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// buttonNameSound
			// 
			this->buttonNameSound->Location = System::Drawing::Point(167, 18);
			this->buttonNameSound->Name = L"buttonNameSound";
			this->buttonNameSound->Size = System::Drawing::Size(24, 20);
			this->buttonNameSound->TabIndex = 3;
			this->buttonNameSound->Text = L"...";
			this->buttonNameSound->UseVisualStyleBackColor = true;
			this->buttonNameSound->Click += gcnew System::EventHandler(this, &OptionForm::buttonNameSound_Click);
			// 
			// textBoxNameSound
			// 
			this->textBoxNameSound->AllowDrop = true;
			this->textBoxNameSound->Location = System::Drawing::Point(11, 19);
			this->textBoxNameSound->Name = L"textBoxNameSound";
			this->textBoxNameSound->Size = System::Drawing::Size(150, 19);
			this->textBoxNameSound->TabIndex = 2;
			this->textBoxNameSound->TextChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->textBoxNameSound->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxNameSound_DragDrop);
			this->textBoxNameSound->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxSound_DragEnter);
			// 
			// groupBoxEnterSound
			// 
			this->groupBoxEnterSound->Controls->Add(this->buttonEnterSoundPlay);
			this->groupBoxEnterSound->Controls->Add(this->checkBoxEnterSound);
			this->groupBoxEnterSound->Controls->Add(this->textBoxEnterSound);
			this->groupBoxEnterSound->Controls->Add(this->buttonEnterSound);
			this->groupBoxEnterSound->Location = System::Drawing::Point(8, 118);
			this->groupBoxEnterSound->Name = L"groupBoxEnterSound";
			this->groupBoxEnterSound->Size = System::Drawing::Size(336, 52);
			this->groupBoxEnterSound->TabIndex = 3;
			this->groupBoxEnterSound->TabStop = false;
			this->groupBoxEnterSound->Text = L"入室のお知らせ";
			// 
			// buttonEnterSoundPlay
			// 
			this->buttonEnterSoundPlay->Location = System::Drawing::Point(261, 20);
			this->buttonEnterSoundPlay->Name = L"buttonEnterSoundPlay";
			this->buttonEnterSoundPlay->Size = System::Drawing::Size(65, 20);
			this->buttonEnterSoundPlay->TabIndex = 4;
			this->buttonEnterSoundPlay->Text = L"再生";
			this->buttonEnterSoundPlay->UseVisualStyleBackColor = true;
			this->buttonEnterSoundPlay->Click += gcnew System::EventHandler(this, &OptionForm::buttonEnterSoundPlay_Click);
			// 
			// checkBoxEnterSound
			// 
			this->checkBoxEnterSound->AutoSize = true;
			this->checkBoxEnterSound->Location = System::Drawing::Point(197, 22);
			this->checkBoxEnterSound->Name = L"checkBoxEnterSound";
			this->checkBoxEnterSound->Size = System::Drawing::Size(48, 16);
			this->checkBoxEnterSound->TabIndex = 3;
			this->checkBoxEnterSound->Text = L"有効";
			this->checkBoxEnterSound->UseVisualStyleBackColor = true;
			this->checkBoxEnterSound->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// textBoxEnterSound
			// 
			this->textBoxEnterSound->AllowDrop = true;
			this->textBoxEnterSound->Location = System::Drawing::Point(11, 20);
			this->textBoxEnterSound->Name = L"textBoxEnterSound";
			this->textBoxEnterSound->Size = System::Drawing::Size(150, 19);
			this->textBoxEnterSound->TabIndex = 1;
			this->textBoxEnterSound->TextChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->textBoxEnterSound->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxEnterSound_DragDrop);
			this->textBoxEnterSound->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxSound_DragEnter);
			// 
			// buttonEnterSound
			// 
			this->buttonEnterSound->Location = System::Drawing::Point(167, 19);
			this->buttonEnterSound->Name = L"buttonEnterSound";
			this->buttonEnterSound->Size = System::Drawing::Size(24, 20);
			this->buttonEnterSound->TabIndex = 2;
			this->buttonEnterSound->Text = L"...";
			this->buttonEnterSound->UseVisualStyleBackColor = true;
			this->buttonEnterSound->Click += gcnew System::EventHandler(this, &OptionForm::buttonEnterSound_Click);
			// 
			// groupBoxNoticeSound
			// 
			this->groupBoxNoticeSound->Controls->Add(this->buttonNoticeSoundPlay);
			this->groupBoxNoticeSound->Controls->Add(this->checkBoxNoticeSound);
			this->groupBoxNoticeSound->Controls->Add(this->textBoxNoticeSound);
			this->groupBoxNoticeSound->Controls->Add(this->buttonNoticeSound);
			this->groupBoxNoticeSound->Location = System::Drawing::Point(8, 63);
			this->groupBoxNoticeSound->Name = L"groupBoxNoticeSound";
			this->groupBoxNoticeSound->Size = System::Drawing::Size(336, 52);
			this->groupBoxNoticeSound->TabIndex = 2;
			this->groupBoxNoticeSound->TabStop = false;
			this->groupBoxNoticeSound->Text = L"告知のお知らせ";
			// 
			// buttonNoticeSoundPlay
			// 
			this->buttonNoticeSoundPlay->Location = System::Drawing::Point(261, 20);
			this->buttonNoticeSoundPlay->Name = L"buttonNoticeSoundPlay";
			this->buttonNoticeSoundPlay->Size = System::Drawing::Size(65, 20);
			this->buttonNoticeSoundPlay->TabIndex = 4;
			this->buttonNoticeSoundPlay->Text = L"再生";
			this->buttonNoticeSoundPlay->UseVisualStyleBackColor = true;
			this->buttonNoticeSoundPlay->Click += gcnew System::EventHandler(this, &OptionForm::buttonNoticeSoundPlay_Click);
			// 
			// checkBoxNoticeSound
			// 
			this->checkBoxNoticeSound->AutoSize = true;
			this->checkBoxNoticeSound->Location = System::Drawing::Point(197, 22);
			this->checkBoxNoticeSound->Name = L"checkBoxNoticeSound";
			this->checkBoxNoticeSound->Size = System::Drawing::Size(48, 16);
			this->checkBoxNoticeSound->TabIndex = 3;
			this->checkBoxNoticeSound->Text = L"有効";
			this->checkBoxNoticeSound->UseVisualStyleBackColor = true;
			this->checkBoxNoticeSound->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// textBoxNoticeSound
			// 
			this->textBoxNoticeSound->AllowDrop = true;
			this->textBoxNoticeSound->Location = System::Drawing::Point(11, 20);
			this->textBoxNoticeSound->Name = L"textBoxNoticeSound";
			this->textBoxNoticeSound->Size = System::Drawing::Size(150, 19);
			this->textBoxNoticeSound->TabIndex = 1;
			this->textBoxNoticeSound->TextChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->textBoxNoticeSound->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxNoticeSound_DragDrop);
			this->textBoxNoticeSound->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxSound_DragEnter);
			// 
			// buttonNoticeSound
			// 
			this->buttonNoticeSound->Location = System::Drawing::Point(167, 19);
			this->buttonNoticeSound->Name = L"buttonNoticeSound";
			this->buttonNoticeSound->Size = System::Drawing::Size(24, 20);
			this->buttonNoticeSound->TabIndex = 2;
			this->buttonNoticeSound->Text = L"...";
			this->buttonNoticeSound->UseVisualStyleBackColor = true;
			this->buttonNoticeSound->Click += gcnew System::EventHandler(this, &OptionForm::buttonNoticeSound_Click);
			// 
			// groupBoxVSSound
			// 
			this->groupBoxVSSound->Controls->Add(this->buttonVSSoundPlay);
			this->groupBoxVSSound->Controls->Add(this->checkBoxVSSound);
			this->groupBoxVSSound->Controls->Add(this->textBoxVSSound);
			this->groupBoxVSSound->Controls->Add(this->buttonVSSound);
			this->groupBoxVSSound->Location = System::Drawing::Point(8, 8);
			this->groupBoxVSSound->Name = L"groupBoxVSSound";
			this->groupBoxVSSound->Size = System::Drawing::Size(336, 52);
			this->groupBoxVSSound->TabIndex = 1;
			this->groupBoxVSSound->TabStop = false;
			this->groupBoxVSSound->Text = L"対戦のお知らせ";
			// 
			// buttonVSSoundPlay
			// 
			this->buttonVSSoundPlay->Location = System::Drawing::Point(261, 19);
			this->buttonVSSoundPlay->Name = L"buttonVSSoundPlay";
			this->buttonVSSoundPlay->Size = System::Drawing::Size(65, 20);
			this->buttonVSSoundPlay->TabIndex = 4;
			this->buttonVSSoundPlay->Text = L"再生";
			this->buttonVSSoundPlay->UseVisualStyleBackColor = true;
			this->buttonVSSoundPlay->Click += gcnew System::EventHandler(this, &OptionForm::buttonVSSoundPlay_Click);
			// 
			// checkBoxVSSound
			// 
			this->checkBoxVSSound->AutoSize = true;
			this->checkBoxVSSound->Location = System::Drawing::Point(197, 22);
			this->checkBoxVSSound->Name = L"checkBoxVSSound";
			this->checkBoxVSSound->Size = System::Drawing::Size(48, 16);
			this->checkBoxVSSound->TabIndex = 3;
			this->checkBoxVSSound->Text = L"有効";
			this->checkBoxVSSound->UseVisualStyleBackColor = true;
			this->checkBoxVSSound->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// textBoxVSSound
			// 
			this->textBoxVSSound->AllowDrop = true;
			this->textBoxVSSound->Location = System::Drawing::Point(11, 20);
			this->textBoxVSSound->Name = L"textBoxVSSound";
			this->textBoxVSSound->Size = System::Drawing::Size(150, 19);
			this->textBoxVSSound->TabIndex = 1;
			this->textBoxVSSound->TextChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->textBoxVSSound->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxVSSound_DragDrop);
			this->textBoxVSSound->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxSound_DragEnter);
			// 
			// buttonVSSound
			// 
			this->buttonVSSound->Location = System::Drawing::Point(167, 19);
			this->buttonVSSound->Name = L"buttonVSSound";
			this->buttonVSSound->Size = System::Drawing::Size(24, 20);
			this->buttonVSSound->TabIndex = 2;
			this->buttonVSSound->Text = L"...";
			this->buttonVSSound->UseVisualStyleBackColor = true;
			this->buttonVSSound->Click += gcnew System::EventHandler(this, &OptionForm::buttonVSSound_Click);
			// 
			// tabPagePath
			// 
			this->tabPagePath->AutoScroll = true;
			this->tabPagePath->AutoScrollMinSize = System::Drawing::Size(0, 330);
			this->tabPagePath->Controls->Add(this->groupBoxProfile);
			this->tabPagePath->Controls->Add(this->groupBoxReplayFolder);
			this->tabPagePath->Controls->Add(this->groupBoxNet);
			this->tabPagePath->Controls->Add(this->groupBoxGameExe);
			this->tabPagePath->Location = System::Drawing::Point(4, 22);
			this->tabPagePath->Name = L"tabPagePath";
			this->tabPagePath->Padding = System::Windows::Forms::Padding(3);
			this->tabPagePath->Size = System::Drawing::Size(369, 295);
			this->tabPagePath->TabIndex = 0;
			this->tabPagePath->Text = L"基本";
			this->tabPagePath->UseVisualStyleBackColor = true;
			// 
			// groupBoxProfile
			// 
			this->groupBoxProfile->Controls->Add(this->buttonSaveProfile);
			this->groupBoxProfile->Controls->Add(this->buttonAddProfile);
			this->groupBoxProfile->Controls->Add(this->labelProfileName);
			this->groupBoxProfile->Controls->Add(this->buttonDeleteProfile);
			this->groupBoxProfile->Controls->Add(this->textBoxProfileName);
			this->groupBoxProfile->Controls->Add(this->buttonCopyProfile);
			this->groupBoxProfile->Controls->Add(this->comboBoxProfile);
			this->groupBoxProfile->Location = System::Drawing::Point(8, 8);
			this->groupBoxProfile->Name = L"groupBoxProfile";
			this->groupBoxProfile->Size = System::Drawing::Size(330, 85);
			this->groupBoxProfile->TabIndex = 4;
			this->groupBoxProfile->TabStop = false;
			this->groupBoxProfile->Text = L"プロファイル";
			// 
			// buttonSaveProfile
			// 
			this->buttonSaveProfile->Location = System::Drawing::Point(275, 50);
			this->buttonSaveProfile->Name = L"buttonSaveProfile";
			this->buttonSaveProfile->Size = System::Drawing::Size(45, 22);
			this->buttonSaveProfile->TabIndex = 7;
			this->buttonSaveProfile->Text = L"保存";
			this->buttonSaveProfile->UseVisualStyleBackColor = true;
			this->buttonSaveProfile->Click += gcnew System::EventHandler(this, &OptionForm::buttonSaveProfile_Click);
			// 
			// buttonAddProfile
			// 
			this->buttonAddProfile->Location = System::Drawing::Point(223, 50);
			this->buttonAddProfile->Name = L"buttonAddProfile";
			this->buttonAddProfile->Size = System::Drawing::Size(45, 22);
			this->buttonAddProfile->TabIndex = 6;
			this->buttonAddProfile->Text = L"追加";
			this->buttonAddProfile->UseVisualStyleBackColor = true;
			this->buttonAddProfile->Click += gcnew System::EventHandler(this, &OptionForm::buttonAddProfile_Click);
			// 
			// labelProfileName
			// 
			this->labelProfileName->AutoSize = true;
			this->labelProfileName->Location = System::Drawing::Point(10, 55);
			this->labelProfileName->Name = L"labelProfileName";
			this->labelProfileName->Size = System::Drawing::Size(69, 12);
			this->labelProfileName->TabIndex = 5;
			this->labelProfileName->Text = L"プロファイル名";
			// 
			// buttonDeleteProfile
			// 
			this->buttonDeleteProfile->Location = System::Drawing::Point(275, 18);
			this->buttonDeleteProfile->Name = L"buttonDeleteProfile";
			this->buttonDeleteProfile->Size = System::Drawing::Size(45, 22);
			this->buttonDeleteProfile->TabIndex = 4;
			this->buttonDeleteProfile->Text = L"削除";
			this->buttonDeleteProfile->UseVisualStyleBackColor = true;
			this->buttonDeleteProfile->Click += gcnew System::EventHandler(this, &OptionForm::buttonDeleteProfile_Click);
			// 
			// textBoxProfileName
			// 
			this->textBoxProfileName->Location = System::Drawing::Point(85, 52);
			this->textBoxProfileName->MaxLength = 63;
			this->textBoxProfileName->Name = L"textBoxProfileName";
			this->textBoxProfileName->Size = System::Drawing::Size(127, 19);
			this->textBoxProfileName->TabIndex = 3;
			this->textBoxProfileName->TextChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// buttonCopyProfile
			// 
			this->buttonCopyProfile->Location = System::Drawing::Point(223, 18);
			this->buttonCopyProfile->Name = L"buttonCopyProfile";
			this->buttonCopyProfile->Size = System::Drawing::Size(45, 22);
			this->buttonCopyProfile->TabIndex = 2;
			this->buttonCopyProfile->Text = L"複製";
			this->buttonCopyProfile->UseVisualStyleBackColor = true;
			this->buttonCopyProfile->Click += gcnew System::EventHandler(this, &OptionForm::buttonCopyProfile_Click);
			// 
			// comboBoxProfile
			// 
			this->comboBoxProfile->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxProfile->FormattingEnabled = true;
			this->comboBoxProfile->ItemHeight = 12;
			this->comboBoxProfile->Location = System::Drawing::Point(12, 19);
			this->comboBoxProfile->MaxDropDownItems = 64;
			this->comboBoxProfile->Name = L"comboBoxProfile";
			this->comboBoxProfile->Size = System::Drawing::Size(200, 20);
			this->comboBoxProfile->TabIndex = 0;
			this->comboBoxProfile->SelectedIndexChanged += gcnew System::EventHandler(this, &OptionForm::comboBoxProfile_SelectedIndexChanged);
			// 
			// groupBoxReplayFolder
			// 
			this->groupBoxReplayFolder->Controls->Add(this->textBoxReplayFolder);
			this->groupBoxReplayFolder->Controls->Add(this->buttonReplayFolder);
			this->groupBoxReplayFolder->Controls->Add(this->checkBoxDivide);
			this->groupBoxReplayFolder->Location = System::Drawing::Point(8, 157);
			this->groupBoxReplayFolder->Name = L"groupBoxReplayFolder";
			this->groupBoxReplayFolder->Size = System::Drawing::Size(330, 80);
			this->groupBoxReplayFolder->TabIndex = 2;
			this->groupBoxReplayFolder->TabStop = false;
			this->groupBoxReplayFolder->Text = L"リプレイ保存フォルダ";
			// 
			// textBoxReplayFolder
			// 
			this->textBoxReplayFolder->AllowDrop = true;
			this->textBoxReplayFolder->Location = System::Drawing::Point(12, 20);
			this->textBoxReplayFolder->Name = L"textBoxReplayFolder";
			this->textBoxReplayFolder->Size = System::Drawing::Size(278, 19);
			this->textBoxReplayFolder->TabIndex = 1;
			this->textBoxReplayFolder->TextChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->textBoxReplayFolder->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxReplayFolder_DragDrop);
			this->textBoxReplayFolder->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxReplayFolder_DragEnter);
			// 
			// buttonReplayFolder
			// 
			this->buttonReplayFolder->Location = System::Drawing::Point(296, 20);
			this->buttonReplayFolder->Name = L"buttonReplayFolder";
			this->buttonReplayFolder->Size = System::Drawing::Size(24, 20);
			this->buttonReplayFolder->TabIndex = 2;
			this->buttonReplayFolder->Text = L"...";
			this->buttonReplayFolder->UseVisualStyleBackColor = true;
			this->buttonReplayFolder->Click += gcnew System::EventHandler(this, &OptionForm::buttonReplayFolder_Click);
			// 
			// checkBoxDivide
			// 
			this->checkBoxDivide->AutoSize = true;
			this->checkBoxDivide->Location = System::Drawing::Point(12, 51);
			this->checkBoxDivide->Name = L"checkBoxDivide";
			this->checkBoxDivide->Size = System::Drawing::Size(168, 16);
			this->checkBoxDivide->TabIndex = 3;
			this->checkBoxDivide->Text = L"リプレイファイルの自動振り分け";
			this->checkBoxDivide->UseVisualStyleBackColor = true;
			this->checkBoxDivide->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// groupBoxNet
			// 
			this->groupBoxNet->Controls->Add(this->labelComment);
			this->groupBoxNet->Controls->Add(this->numericUpDownMaxConnection);
			this->groupBoxNet->Controls->Add(this->textBoxComment);
			this->groupBoxNet->Controls->Add(this->label5);
			this->groupBoxNet->Location = System::Drawing::Point(8, 243);
			this->groupBoxNet->Name = L"groupBoxNet";
			this->groupBoxNet->Size = System::Drawing::Size(330, 80);
			this->groupBoxNet->TabIndex = 3;
			this->groupBoxNet->TabStop = false;
			this->groupBoxNet->Text = L"回線設定";
			// 
			// labelComment
			// 
			this->labelComment->AutoSize = true;
			this->labelComment->Location = System::Drawing::Point(10, 51);
			this->labelComment->Name = L"labelComment";
			this->labelComment->Size = System::Drawing::Size(38, 12);
			this->labelComment->TabIndex = 0;
			this->labelComment->Text = L"コメント";
			// 
			// numericUpDownMaxConnection
			// 
			this->numericUpDownMaxConnection->Location = System::Drawing::Point(81, 20);
			this->numericUpDownMaxConnection->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDownMaxConnection->Name = L"numericUpDownMaxConnection";
			this->numericUpDownMaxConnection->Size = System::Drawing::Size(40, 19);
			this->numericUpDownMaxConnection->TabIndex = 1;
			this->numericUpDownMaxConnection->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDownMaxConnection->ValueChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// textBoxComment
			// 
			this->textBoxComment->Location = System::Drawing::Point(81, 48);
			this->textBoxComment->Name = L"textBoxComment";
			this->textBoxComment->Size = System::Drawing::Size(206, 19);
			this->textBoxComment->TabIndex = 2;
			this->textBoxComment->TextChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 12);
			this->label5->TabIndex = 0;
			this->label5->Text = L"最大接続数";
			// 
			// groupBoxGameExe
			// 
			this->groupBoxGameExe->Controls->Add(this->textBoxGameExe);
			this->groupBoxGameExe->Controls->Add(this->buttonGameExe);
			this->groupBoxGameExe->Location = System::Drawing::Point(8, 99);
			this->groupBoxGameExe->Name = L"groupBoxGameExe";
			this->groupBoxGameExe->Size = System::Drawing::Size(330, 52);
			this->groupBoxGameExe->TabIndex = 1;
			this->groupBoxGameExe->TabStop = false;
			this->groupBoxGameExe->Text = L"実行ファイルのパス";
			// 
			// textBoxGameExe
			// 
			this->textBoxGameExe->AllowDrop = true;
			this->textBoxGameExe->Location = System::Drawing::Point(12, 20);
			this->textBoxGameExe->Name = L"textBoxGameExe";
			this->textBoxGameExe->Size = System::Drawing::Size(278, 19);
			this->textBoxGameExe->TabIndex = 1;
			this->textBoxGameExe->TextChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->textBoxGameExe->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxGameExe_DragDrop);
			this->textBoxGameExe->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &OptionForm::textBoxGameExe_DragEnter);
			// 
			// buttonGameExe
			// 
			this->buttonGameExe->Location = System::Drawing::Point(296, 20);
			this->buttonGameExe->Name = L"buttonGameExe";
			this->buttonGameExe->Size = System::Drawing::Size(24, 20);
			this->buttonGameExe->TabIndex = 2;
			this->buttonGameExe->Text = L"...";
			this->buttonGameExe->UseVisualStyleBackColor = true;
			this->buttonGameExe->Click += gcnew System::EventHandler(this, &OptionForm::buttonGameExe_Click);
			// 
			// groupBoxSave
			// 
			this->groupBoxSave->Controls->Add(this->radioButtonReplayVersion1);
			this->groupBoxSave->Controls->Add(this->radioButtonReplayVersion2);
			this->groupBoxSave->Location = System::Drawing::Point(195, 199);
			this->groupBoxSave->Name = L"groupBoxSave";
			this->groupBoxSave->Size = System::Drawing::Size(154, 42);
			this->groupBoxSave->TabIndex = 4;
			this->groupBoxSave->TabStop = false;
			this->groupBoxSave->Text = L"リプレイファイル";
			// 
			// radioButtonReplayVersion1
			// 
			this->radioButtonReplayVersion1->AutoSize = true;
			this->radioButtonReplayVersion1->Location = System::Drawing::Point(88, 17);
			this->radioButtonReplayVersion1->Name = L"radioButtonReplayVersion1";
			this->radioButtonReplayVersion1->Size = System::Drawing::Size(59, 16);
			this->radioButtonReplayVersion1->TabIndex = 2;
			this->radioButtonReplayVersion1->TabStop = true;
			this->radioButtonReplayVersion1->Text = L"無圧縮";
			this->radioButtonReplayVersion1->UseVisualStyleBackColor = true;
			this->radioButtonReplayVersion1->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// radioButtonReplayVersion2
			// 
			this->radioButtonReplayVersion2->AutoSize = true;
			this->radioButtonReplayVersion2->Location = System::Drawing::Point(16, 17);
			this->radioButtonReplayVersion2->Name = L"radioButtonReplayVersion2";
			this->radioButtonReplayVersion2->Size = System::Drawing::Size(66, 16);
			this->radioButtonReplayVersion2->TabIndex = 2;
			this->radioButtonReplayVersion2->TabStop = true;
			this->radioButtonReplayVersion2->Text = L"圧縮する";
			this->radioButtonReplayVersion2->UseVisualStyleBackColor = true;
			this->radioButtonReplayVersion2->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// tabControlOption
			// 
			this->tabControlOption->Controls->Add(this->tabPagePath);
			this->tabControlOption->Controls->Add(this->tabPageSound);
			this->tabControlOption->Controls->Add(this->tabPageGame);
			this->tabControlOption->Controls->Add(this->tabPageColor);
			this->tabControlOption->Controls->Add(this->tabPageVolume);
			this->tabControlOption->Controls->Add(this->tabPageIP);
			this->tabControlOption->Controls->Add(this->tabPageDetails);
			this->tabControlOption->Dock = System::Windows::Forms::DockStyle::Top;
			this->tabControlOption->Location = System::Drawing::Point(0, 0);
			this->tabControlOption->Name = L"tabControlOption";
			this->tabControlOption->SelectedIndex = 0;
			this->tabControlOption->Size = System::Drawing::Size(377, 321);
			this->tabControlOption->TabIndex = 0;
			// 
			// tabPageGame
			// 
			this->tabPageGame->AutoScroll = true;
			this->tabPageGame->Controls->Add(this->groupBoxTeamOption);
			this->tabPageGame->Controls->Add(this->groupBoxSave);
			this->tabPageGame->Controls->Add(this->groupBoxSimulate);
			this->tabPageGame->Controls->Add(this->groupBoxRun);
			this->tabPageGame->Controls->Add(this->groupBoxView);
			this->tabPageGame->Controls->Add(this->groupBoxSetting);
			this->tabPageGame->Location = System::Drawing::Point(4, 22);
			this->tabPageGame->Name = L"tabPageGame";
			this->tabPageGame->Padding = System::Windows::Forms::Padding(3);
			this->tabPageGame->Size = System::Drawing::Size(369, 295);
			this->tabPageGame->TabIndex = 4;
			this->tabPageGame->Text = L"ゲーム";
			this->tabPageGame->UseVisualStyleBackColor = true;
			// 
			// groupBoxTeamOption
			// 
			this->groupBoxTeamOption->Controls->Add(this->labelTeamRoundHP);
			this->groupBoxTeamOption->Controls->Add(this->checkBoxTeamRoundHP);
			this->groupBoxTeamOption->Location = System::Drawing::Point(9, 224);
			this->groupBoxTeamOption->Name = L"groupBoxTeamOption";
			this->groupBoxTeamOption->Size = System::Drawing::Size(167, 68);
			this->groupBoxTeamOption->TabIndex = 6;
			this->groupBoxTeamOption->TabStop = false;
			this->groupBoxTeamOption->Text = L"チームプレイ設定";
			// 
			// labelTeamRoundHP
			// 
			this->labelTeamRoundHP->AutoSize = true;
			this->labelTeamRoundHP->Location = System::Drawing::Point(13, 42);
			this->labelTeamRoundHP->Name = L"labelTeamRoundHP";
			this->labelTeamRoundHP->Size = System::Drawing::Size(138, 12);
			this->labelTeamRoundHP->TabIndex = 1;
			this->labelTeamRoundHP->Text = L"※1vs1ではオフにしてください";
			// 
			// checkBoxTeamRoundHP
			// 
			this->checkBoxTeamRoundHP->AutoSize = true;
			this->checkBoxTeamRoundHP->Location = System::Drawing::Point(15, 21);
			this->checkBoxTeamRoundHP->Name = L"checkBoxTeamRoundHP";
			this->checkBoxTeamRoundHP->Size = System::Drawing::Size(148, 16);
			this->checkBoxTeamRoundHP->TabIndex = 0;
			this->checkBoxTeamRoundHP->Text = L"ラウンド間でHPを持ち越す";
			this->checkBoxTeamRoundHP->UseVisualStyleBackColor = true;
			this->checkBoxTeamRoundHP->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// groupBoxSimulate
			// 
			this->groupBoxSimulate->Controls->Add(this->numericUpDownSimDelay);
			this->groupBoxSimulate->Controls->Add(this->labelSimDelay);
			this->groupBoxSimulate->Location = System::Drawing::Point(195, 149);
			this->groupBoxSimulate->Name = L"groupBoxSimulate";
			this->groupBoxSimulate->Size = System::Drawing::Size(154, 44);
			this->groupBoxSimulate->TabIndex = 5;
			this->groupBoxSimulate->TabStop = false;
			this->groupBoxSimulate->Text = L"シミュレート";
			// 
			// numericUpDownSimDelay
			// 
			this->numericUpDownSimDelay->Location = System::Drawing::Point(88, 18);
			this->numericUpDownSimDelay->Name = L"numericUpDownSimDelay";
			this->numericUpDownSimDelay->Size = System::Drawing::Size(40, 19);
			this->numericUpDownSimDelay->TabIndex = 1;
			this->numericUpDownSimDelay->ValueChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// labelSimDelay
			// 
			this->labelSimDelay->AutoSize = true;
			this->labelSimDelay->Location = System::Drawing::Point(16, 20);
			this->labelSimDelay->Name = L"labelSimDelay";
			this->labelSimDelay->Size = System::Drawing::Size(40, 12);
			this->labelSimDelay->TabIndex = 0;
			this->labelSimDelay->Text = L"ディレイ";
			// 
			// groupBoxRun
			// 
			this->groupBoxRun->Controls->Add(this->checkBoxWindowSize);
			this->groupBoxRun->Controls->Add(this->checkBoxHitJudge);
			this->groupBoxRun->Location = System::Drawing::Point(8, 149);
			this->groupBoxRun->Name = L"groupBoxRun";
			this->groupBoxRun->Size = System::Drawing::Size(168, 68);
			this->groupBoxRun->TabIndex = 3;
			this->groupBoxRun->TabStop = false;
			this->groupBoxRun->Text = L"格ツク";
			// 
			// checkBoxWindowSize
			// 
			this->checkBoxWindowSize->AutoSize = true;
			this->checkBoxWindowSize->Location = System::Drawing::Point(16, 44);
			this->checkBoxWindowSize->Name = L"checkBoxWindowSize";
			this->checkBoxWindowSize->Size = System::Drawing::Size(112, 16);
			this->checkBoxWindowSize->TabIndex = 2;
			this->checkBoxWindowSize->Text = L"640 x 480 で起動";
			this->checkBoxWindowSize->UseVisualStyleBackColor = true;
			this->checkBoxWindowSize->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// checkBoxHitJudge
			// 
			this->checkBoxHitJudge->AutoSize = true;
			this->checkBoxHitJudge->Location = System::Drawing::Point(16, 20);
			this->checkBoxHitJudge->Name = L"checkBoxHitJudge";
			this->checkBoxHitJudge->Size = System::Drawing::Size(111, 16);
			this->checkBoxHitJudge->TabIndex = 1;
			this->checkBoxHitJudge->Text = L"当たり判定の表示";
			this->checkBoxHitJudge->UseVisualStyleBackColor = true;
			this->checkBoxHitJudge->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// groupBoxView
			// 
			this->groupBoxView->Controls->Add(this->checkBoxShowResult);
			this->groupBoxView->Controls->Add(this->checkBoxVersus);
			this->groupBoxView->Controls->Add(this->checkBoxName);
			this->groupBoxView->Controls->Add(this->checkBoxFramerate);
			this->groupBoxView->Controls->Add(this->checkBoxRand);
			this->groupBoxView->Location = System::Drawing::Point(195, 8);
			this->groupBoxView->Name = L"groupBoxView";
			this->groupBoxView->Size = System::Drawing::Size(154, 134);
			this->groupBoxView->TabIndex = 4;
			this->groupBoxView->TabStop = false;
			this->groupBoxView->Text = L"タイトルバー";
			// 
			// checkBoxVersus
			// 
			this->checkBoxVersus->AutoSize = true;
			this->checkBoxVersus->Location = System::Drawing::Point(16, 42);
			this->checkBoxVersus->Name = L"checkBoxVersus";
			this->checkBoxVersus->Size = System::Drawing::Size(60, 16);
			this->checkBoxVersus->TabIndex = 2;
			this->checkBoxVersus->Text = L"対戦数";
			this->checkBoxVersus->UseVisualStyleBackColor = true;
			this->checkBoxVersus->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// checkBoxName
			// 
			this->checkBoxName->AutoSize = true;
			this->checkBoxName->Location = System::Drawing::Point(16, 20);
			this->checkBoxName->Name = L"checkBoxName";
			this->checkBoxName->Size = System::Drawing::Size(78, 16);
			this->checkBoxName->TabIndex = 1;
			this->checkBoxName->Text = L"ニックネーム";
			this->checkBoxName->UseVisualStyleBackColor = true;
			this->checkBoxName->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// checkBoxFramerate
			// 
			this->checkBoxFramerate->AutoSize = true;
			this->checkBoxFramerate->Location = System::Drawing::Point(16, 86);
			this->checkBoxFramerate->Name = L"checkBoxFramerate";
			this->checkBoxFramerate->Size = System::Drawing::Size(88, 16);
			this->checkBoxFramerate->TabIndex = 3;
			this->checkBoxFramerate->Text = L"フレームレート";
			this->checkBoxFramerate->UseVisualStyleBackColor = true;
			this->checkBoxFramerate->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// checkBoxRand
			// 
			this->checkBoxRand->AutoSize = true;
			this->checkBoxRand->Location = System::Drawing::Point(16, 108);
			this->checkBoxRand->Name = L"checkBoxRand";
			this->checkBoxRand->Size = System::Drawing::Size(106, 16);
			this->checkBoxRand->TabIndex = 4;
			this->checkBoxRand->Text = L"乱数の使用回数";
			this->checkBoxRand->UseVisualStyleBackColor = true;
			this->checkBoxRand->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// groupBoxSetting
			// 
			this->groupBoxSetting->Controls->Add(this->numericUpDownRound);
			this->groupBoxSetting->Controls->Add(this->labelRound);
			this->groupBoxSetting->Controls->Add(this->labelTimer);
			this->groupBoxSetting->Controls->Add(this->numericUpDownTimer);
			this->groupBoxSetting->Controls->Add(this->numericUpDownMaxStage);
			this->groupBoxSetting->Controls->Add(this->labelMaxStage);
			this->groupBoxSetting->Controls->Add(this->labelStageSelect);
			this->groupBoxSetting->Controls->Add(this->numericUpDownStageSelect);
			this->groupBoxSetting->Location = System::Drawing::Point(8, 8);
			this->groupBoxSetting->Name = L"groupBoxSetting";
			this->groupBoxSetting->Size = System::Drawing::Size(168, 134);
			this->groupBoxSetting->TabIndex = 1;
			this->groupBoxSetting->TabStop = false;
			this->groupBoxSetting->Text = L"対戦設定";
			// 
			// numericUpDownRound
			// 
			this->numericUpDownRound->Location = System::Drawing::Point(112, 72);
			this->numericUpDownRound->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {9, 0, 0, 0});
			this->numericUpDownRound->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDownRound->Name = L"numericUpDownRound";
			this->numericUpDownRound->Size = System::Drawing::Size(40, 19);
			this->numericUpDownRound->TabIndex = 3;
			this->numericUpDownRound->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDownRound->ValueChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// labelRound
			// 
			this->labelRound->AutoSize = true;
			this->labelRound->Location = System::Drawing::Point(16, 76);
			this->labelRound->Name = L"labelRound";
			this->labelRound->Size = System::Drawing::Size(52, 12);
			this->labelRound->TabIndex = 0;
			this->labelRound->Text = L"ラウンド数";
			// 
			// labelTimer
			// 
			this->labelTimer->AutoSize = true;
			this->labelTimer->Location = System::Drawing::Point(16, 104);
			this->labelTimer->Name = L"labelTimer";
			this->labelTimer->Size = System::Drawing::Size(71, 12);
			this->labelTimer->TabIndex = 0;
			this->labelTimer->Text = L"ゲームタイマー";
			// 
			// numericUpDownTimer
			// 
			this->numericUpDownTimer->Location = System::Drawing::Point(112, 100);
			this->numericUpDownTimer->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {99, 0, 0, 0});
			this->numericUpDownTimer->Name = L"numericUpDownTimer";
			this->numericUpDownTimer->Size = System::Drawing::Size(40, 19);
			this->numericUpDownTimer->TabIndex = 4;
			this->numericUpDownTimer->ValueChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// numericUpDownMaxStage
			// 
			this->numericUpDownMaxStage->Location = System::Drawing::Point(112, 16);
			this->numericUpDownMaxStage->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDownMaxStage->Name = L"numericUpDownMaxStage";
			this->numericUpDownMaxStage->Size = System::Drawing::Size(40, 19);
			this->numericUpDownMaxStage->TabIndex = 1;
			this->numericUpDownMaxStage->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDownMaxStage->ValueChanged += gcnew System::EventHandler(this, &OptionForm::numericUpDownStage_ValueChanged);
			// 
			// labelMaxStage
			// 
			this->labelMaxStage->AutoSize = true;
			this->labelMaxStage->Location = System::Drawing::Point(16, 20);
			this->labelMaxStage->Name = L"labelMaxStage";
			this->labelMaxStage->Size = System::Drawing::Size(79, 12);
			this->labelMaxStage->TabIndex = 0;
			this->labelMaxStage->Text = L"最大ステージ数";
			// 
			// labelStageSelect
			// 
			this->labelStageSelect->AutoSize = true;
			this->labelStageSelect->Location = System::Drawing::Point(16, 48);
			this->labelStageSelect->Name = L"labelStageSelect";
			this->labelStageSelect->Size = System::Drawing::Size(67, 12);
			this->labelStageSelect->TabIndex = 0;
			this->labelStageSelect->Text = L"対戦ステージ";
			// 
			// numericUpDownStageSelect
			// 
			this->numericUpDownStageSelect->Location = System::Drawing::Point(112, 44);
			this->numericUpDownStageSelect->Name = L"numericUpDownStageSelect";
			this->numericUpDownStageSelect->Size = System::Drawing::Size(40, 19);
			this->numericUpDownStageSelect->TabIndex = 2;
			this->numericUpDownStageSelect->ValueChanged += gcnew System::EventHandler(this, &OptionForm::numericUpDownStage_ValueChanged);
			// 
			// tabPageColor
			// 
			this->tabPageColor->Controls->Add(this->groupBoxMessageColor);
			this->tabPageColor->Controls->Add(this->groupBoxOthersColor);
			this->tabPageColor->Controls->Add(this->groupBoxStateColor);
			this->tabPageColor->Controls->Add(this->groupBoxNameColor);
			this->tabPageColor->Location = System::Drawing::Point(4, 22);
			this->tabPageColor->Name = L"tabPageColor";
			this->tabPageColor->Padding = System::Windows::Forms::Padding(3);
			this->tabPageColor->Size = System::Drawing::Size(369, 295);
			this->tabPageColor->TabIndex = 5;
			this->tabPageColor->Text = L"カラー";
			this->tabPageColor->UseVisualStyleBackColor = true;
			// 
			// groupBoxMessageColor
			// 
			this->groupBoxMessageColor->Controls->Add(this->buttonDebugMessage);
			this->groupBoxMessageColor->Controls->Add(this->buttonErrorMessage);
			this->groupBoxMessageColor->Controls->Add(this->buttonSystemMessage);
			this->groupBoxMessageColor->Location = System::Drawing::Point(192, 8);
			this->groupBoxMessageColor->Name = L"groupBoxMessageColor";
			this->groupBoxMessageColor->Size = System::Drawing::Size(168, 108);
			this->groupBoxMessageColor->TabIndex = 3;
			this->groupBoxMessageColor->TabStop = false;
			this->groupBoxMessageColor->Text = L"メッセージ";
			// 
			// buttonDebugMessage
			// 
			this->buttonDebugMessage->BackColor = System::Drawing::SystemColors::Window;
			this->buttonDebugMessage->Location = System::Drawing::Point(16, 76);
			this->buttonDebugMessage->Name = L"buttonDebugMessage";
			this->buttonDebugMessage->Size = System::Drawing::Size(136, 20);
			this->buttonDebugMessage->TabIndex = 3;
			this->buttonDebugMessage->Text = L"デバッグ";
			this->buttonDebugMessage->UseVisualStyleBackColor = false;
			this->buttonDebugMessage->Click += gcnew System::EventHandler(this, &OptionForm::buttonDebugMessage_Click);
			this->buttonDebugMessage->ForeColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// buttonErrorMessage
			// 
			this->buttonErrorMessage->BackColor = System::Drawing::SystemColors::Window;
			this->buttonErrorMessage->Location = System::Drawing::Point(16, 48);
			this->buttonErrorMessage->Name = L"buttonErrorMessage";
			this->buttonErrorMessage->Size = System::Drawing::Size(136, 20);
			this->buttonErrorMessage->TabIndex = 2;
			this->buttonErrorMessage->Text = L"エラー";
			this->buttonErrorMessage->UseVisualStyleBackColor = false;
			this->buttonErrorMessage->Click += gcnew System::EventHandler(this, &OptionForm::buttonErrorMessage_Click);
			this->buttonErrorMessage->ForeColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// buttonSystemMessage
			// 
			this->buttonSystemMessage->BackColor = System::Drawing::SystemColors::Window;
			this->buttonSystemMessage->Location = System::Drawing::Point(16, 20);
			this->buttonSystemMessage->Name = L"buttonSystemMessage";
			this->buttonSystemMessage->Size = System::Drawing::Size(136, 20);
			this->buttonSystemMessage->TabIndex = 1;
			this->buttonSystemMessage->Text = L"システム";
			this->buttonSystemMessage->UseVisualStyleBackColor = false;
			this->buttonSystemMessage->Click += gcnew System::EventHandler(this, &OptionForm::buttonSystemMessage_Click);
			this->buttonSystemMessage->ForeColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// groupBoxOthersColor
			// 
			this->groupBoxOthersColor->Controls->Add(this->buttonSecret);
			this->groupBoxOthersColor->Controls->Add(this->buttonCommentBack);
			this->groupBoxOthersColor->Controls->Add(this->buttonNoticeBack);
			this->groupBoxOthersColor->Location = System::Drawing::Point(192, 128);
			this->groupBoxOthersColor->Name = L"groupBoxOthersColor";
			this->groupBoxOthersColor->Size = System::Drawing::Size(168, 108);
			this->groupBoxOthersColor->TabIndex = 4;
			this->groupBoxOthersColor->TabStop = false;
			this->groupBoxOthersColor->Text = L"その他";
			// 
			// buttonSecret
			// 
			this->buttonSecret->BackColor = System::Drawing::SystemColors::Window;
			this->buttonSecret->Location = System::Drawing::Point(16, 76);
			this->buttonSecret->Name = L"buttonSecret";
			this->buttonSecret->Size = System::Drawing::Size(136, 20);
			this->buttonSecret->TabIndex = 3;
			this->buttonSecret->Text = L"？？？";
			this->buttonSecret->UseVisualStyleBackColor = false;
			this->buttonSecret->Click += gcnew System::EventHandler(this, &OptionForm::buttonSecret_Click);
			this->buttonSecret->ForeColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// buttonCommentBack
			// 
			this->buttonCommentBack->ForeColor = System::Drawing::SystemColors::WindowText;
			this->buttonCommentBack->Location = System::Drawing::Point(16, 48);
			this->buttonCommentBack->Name = L"buttonCommentBack";
			this->buttonCommentBack->Size = System::Drawing::Size(136, 20);
			this->buttonCommentBack->TabIndex = 2;
			this->buttonCommentBack->Text = L"コメントの背景";
			this->buttonCommentBack->UseVisualStyleBackColor = false;
			this->buttonCommentBack->BackColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->buttonCommentBack->Click += gcnew System::EventHandler(this, &OptionForm::buttonCommentBack_Click);
			// 
			// buttonNoticeBack
			// 
			this->buttonNoticeBack->ForeColor = System::Drawing::SystemColors::WindowText;
			this->buttonNoticeBack->Location = System::Drawing::Point(16, 20);
			this->buttonNoticeBack->Name = L"buttonNoticeBack";
			this->buttonNoticeBack->Size = System::Drawing::Size(136, 20);
			this->buttonNoticeBack->TabIndex = 1;
			this->buttonNoticeBack->Text = L"告知メッセージの背景";
			this->buttonNoticeBack->UseVisualStyleBackColor = false;
			this->buttonNoticeBack->BackColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->buttonNoticeBack->Click += gcnew System::EventHandler(this, &OptionForm::buttonNoticeBack_Click);
			// 
			// groupBoxStateColor
			// 
			this->groupBoxStateColor->Controls->Add(this->buttonSeekState);
			this->groupBoxStateColor->Controls->Add(this->buttonWatchState);
			this->groupBoxStateColor->Controls->Add(this->buttonVSState);
			this->groupBoxStateColor->Controls->Add(this->buttonRestState);
			this->groupBoxStateColor->Location = System::Drawing::Point(8, 128);
			this->groupBoxStateColor->Name = L"groupBoxStateColor";
			this->groupBoxStateColor->Size = System::Drawing::Size(168, 137);
			this->groupBoxStateColor->TabIndex = 2;
			this->groupBoxStateColor->TabStop = false;
			this->groupBoxStateColor->Text = L"状態";
			// 
			// buttonSeekState
			// 
			this->buttonSeekState->Location = System::Drawing::Point(16, 103);
			this->buttonSeekState->Name = L"buttonSeekState";
			this->buttonSeekState->Size = System::Drawing::Size(136, 21);
			this->buttonSeekState->TabIndex = 4;
			this->buttonSeekState->Text = L"対戦募集中";
			this->buttonSeekState->UseVisualStyleBackColor = true;
			this->buttonSeekState->BackColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->buttonSeekState->Click += gcnew System::EventHandler(this, &OptionForm::buttonSeekState_Click);
			// 
			// buttonWatchState
			// 
			this->buttonWatchState->ForeColor = System::Drawing::SystemColors::WindowText;
			this->buttonWatchState->Location = System::Drawing::Point(16, 76);
			this->buttonWatchState->Name = L"buttonWatchState";
			this->buttonWatchState->Size = System::Drawing::Size(136, 20);
			this->buttonWatchState->TabIndex = 3;
			this->buttonWatchState->Text = L"観戦中";
			this->buttonWatchState->UseVisualStyleBackColor = false;
			this->buttonWatchState->BackColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->buttonWatchState->Click += gcnew System::EventHandler(this, &OptionForm::buttonWatchState_Click);
			// 
			// buttonVSState
			// 
			this->buttonVSState->ForeColor = System::Drawing::SystemColors::WindowText;
			this->buttonVSState->Location = System::Drawing::Point(16, 48);
			this->buttonVSState->Name = L"buttonVSState";
			this->buttonVSState->Size = System::Drawing::Size(136, 20);
			this->buttonVSState->TabIndex = 2;
			this->buttonVSState->Text = L"対戦中";
			this->buttonVSState->UseVisualStyleBackColor = false;
			this->buttonVSState->BackColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->buttonVSState->Click += gcnew System::EventHandler(this, &OptionForm::buttonVSState_Click);
			// 
			// buttonRestState
			// 
			this->buttonRestState->ForeColor = System::Drawing::SystemColors::WindowText;
			this->buttonRestState->Location = System::Drawing::Point(16, 20);
			this->buttonRestState->Name = L"buttonRestState";
			this->buttonRestState->Size = System::Drawing::Size(136, 20);
			this->buttonRestState->TabIndex = 1;
			this->buttonRestState->Text = L"休憩中";
			this->buttonRestState->UseVisualStyleBackColor = false;
			this->buttonRestState->BackColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			this->buttonRestState->Click += gcnew System::EventHandler(this, &OptionForm::buttonRestState_Click);
			// 
			// groupBoxNameColor
			// 
			this->groupBoxNameColor->Controls->Add(this->buttonClientName);
			this->groupBoxNameColor->Controls->Add(this->buttonHostName);
			this->groupBoxNameColor->Controls->Add(this->buttonServerName);
			this->groupBoxNameColor->Location = System::Drawing::Point(8, 8);
			this->groupBoxNameColor->Name = L"groupBoxNameColor";
			this->groupBoxNameColor->Size = System::Drawing::Size(168, 108);
			this->groupBoxNameColor->TabIndex = 1;
			this->groupBoxNameColor->TabStop = false;
			this->groupBoxNameColor->Text = L"名前";
			// 
			// buttonClientName
			// 
			this->buttonClientName->BackColor = System::Drawing::SystemColors::Window;
			this->buttonClientName->Location = System::Drawing::Point(16, 76);
			this->buttonClientName->Name = L"buttonClientName";
			this->buttonClientName->Size = System::Drawing::Size(136, 20);
			this->buttonClientName->TabIndex = 3;
			this->buttonClientName->Text = L"クライアント";
			this->buttonClientName->UseVisualStyleBackColor = false;
			this->buttonClientName->Click += gcnew System::EventHandler(this, &OptionForm::buttonClientName_Click);
			this->buttonClientName->ForeColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// buttonHostName
			// 
			this->buttonHostName->BackColor = System::Drawing::SystemColors::Window;
			this->buttonHostName->Location = System::Drawing::Point(16, 48);
			this->buttonHostName->Name = L"buttonHostName";
			this->buttonHostName->Size = System::Drawing::Size(136, 20);
			this->buttonHostName->TabIndex = 2;
			this->buttonHostName->Text = L"ホスト";
			this->buttonHostName->UseVisualStyleBackColor = false;
			this->buttonHostName->Click += gcnew System::EventHandler(this, &OptionForm::buttonHostName_Click);
			this->buttonHostName->ForeColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// buttonServerName
			// 
			this->buttonServerName->BackColor = System::Drawing::SystemColors::Window;
			this->buttonServerName->Location = System::Drawing::Point(16, 20);
			this->buttonServerName->Name = L"buttonServerName";
			this->buttonServerName->Size = System::Drawing::Size(136, 20);
			this->buttonServerName->TabIndex = 1;
			this->buttonServerName->Text = L"サーバ";
			this->buttonServerName->UseVisualStyleBackColor = false;
			this->buttonServerName->Click += gcnew System::EventHandler(this, &OptionForm::buttonServerName_Click);
			this->buttonServerName->ForeColorChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// tabPageVolume
			// 
			this->tabPageVolume->Controls->Add(this->groupBoxMidi);
			this->tabPageVolume->Controls->Add(this->groupBoxSE);
			this->tabPageVolume->Controls->Add(this->groupBoxBGM);
			this->tabPageVolume->Location = System::Drawing::Point(4, 22);
			this->tabPageVolume->Name = L"tabPageVolume";
			this->tabPageVolume->Padding = System::Windows::Forms::Padding(3);
			this->tabPageVolume->Size = System::Drawing::Size(369, 295);
			this->tabPageVolume->TabIndex = 6;
			this->tabPageVolume->Text = L"音量";
			this->tabPageVolume->UseVisualStyleBackColor = true;
			// 
			// groupBoxMidi
			// 
			this->groupBoxMidi->Controls->Add(this->labelMidi);
			this->groupBoxMidi->Controls->Add(this->trackBarMidi);
			this->groupBoxMidi->Location = System::Drawing::Point(8, 184);
			this->groupBoxMidi->Name = L"groupBoxMidi";
			this->groupBoxMidi->Size = System::Drawing::Size(352, 52);
			this->groupBoxMidi->TabIndex = 3;
			this->groupBoxMidi->TabStop = false;
			this->groupBoxMidi->Text = L"SW シンセサイザ";
			// 
			// labelMidi
			// 
			this->labelMidi->AutoSize = true;
			this->labelMidi->Location = System::Drawing::Point(8, 24);
			this->labelMidi->Name = L"labelMidi";
			this->labelMidi->Size = System::Drawing::Size(29, 12);
			this->labelMidi->TabIndex = 0;
			this->labelMidi->Text = L"100%";
			// 
			// trackBarMidi
			// 
			this->trackBarMidi->AutoSize = false;
			this->trackBarMidi->LargeChange = 10;
			this->trackBarMidi->Location = System::Drawing::Point(48, 12);
			this->trackBarMidi->Maximum = 100;
			this->trackBarMidi->Name = L"trackBarMidi";
			this->trackBarMidi->Size = System::Drawing::Size(296, 32);
			this->trackBarMidi->TabIndex = 1;
			this->trackBarMidi->TickFrequency = 10;
			this->trackBarMidi->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackBarMidi->Scroll += gcnew System::EventHandler(this, &OptionForm::trackBarMidi_Scroll);
			// 
			// groupBoxSE
			// 
			this->groupBoxSE->Controls->Add(this->labelSE);
			this->groupBoxSE->Controls->Add(this->trackBarSE);
			this->groupBoxSE->Location = System::Drawing::Point(8, 68);
			this->groupBoxSE->Name = L"groupBoxSE";
			this->groupBoxSE->Size = System::Drawing::Size(352, 52);
			this->groupBoxSE->TabIndex = 2;
			this->groupBoxSE->TabStop = false;
			this->groupBoxSE->Text = L"SE";
			// 
			// labelSE
			// 
			this->labelSE->AutoSize = true;
			this->labelSE->Location = System::Drawing::Point(8, 24);
			this->labelSE->Name = L"labelSE";
			this->labelSE->Size = System::Drawing::Size(29, 12);
			this->labelSE->TabIndex = 0;
			this->labelSE->Text = L"100%";
			// 
			// trackBarSE
			// 
			this->trackBarSE->AutoSize = false;
			this->trackBarSE->LargeChange = 2;
			this->trackBarSE->Location = System::Drawing::Point(48, 12);
			this->trackBarSE->Maximum = 20;
			this->trackBarSE->Name = L"trackBarSE";
			this->trackBarSE->Size = System::Drawing::Size(296, 32);
			this->trackBarSE->TabIndex = 1;
			this->trackBarSE->TickFrequency = 2;
			this->trackBarSE->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackBarSE->Scroll += gcnew System::EventHandler(this, &OptionForm::trackBarSE_Scroll);
			// 
			// groupBoxBGM
			// 
			this->groupBoxBGM->Controls->Add(this->labelBGM);
			this->groupBoxBGM->Controls->Add(this->trackBarBGM);
			this->groupBoxBGM->Location = System::Drawing::Point(8, 8);
			this->groupBoxBGM->Name = L"groupBoxBGM";
			this->groupBoxBGM->Size = System::Drawing::Size(352, 52);
			this->groupBoxBGM->TabIndex = 1;
			this->groupBoxBGM->TabStop = false;
			this->groupBoxBGM->Text = L"BGM";
			// 
			// labelBGM
			// 
			this->labelBGM->AutoSize = true;
			this->labelBGM->Location = System::Drawing::Point(8, 24);
			this->labelBGM->Name = L"labelBGM";
			this->labelBGM->Size = System::Drawing::Size(29, 12);
			this->labelBGM->TabIndex = 0;
			this->labelBGM->Text = L"100%";
			// 
			// trackBarBGM
			// 
			this->trackBarBGM->AutoSize = false;
			this->trackBarBGM->LargeChange = 2;
			this->trackBarBGM->Location = System::Drawing::Point(48, 12);
			this->trackBarBGM->Maximum = 20;
			this->trackBarBGM->Name = L"trackBarBGM";
			this->trackBarBGM->Size = System::Drawing::Size(296, 32);
			this->trackBarBGM->TabIndex = 1;
			this->trackBarBGM->TickFrequency = 2;
			this->trackBarBGM->TickStyle = System::Windows::Forms::TickStyle::TopLeft;
			this->trackBarBGM->Scroll += gcnew System::EventHandler(this, &OptionForm::trackBarBGM_Scroll);
			// 
			// tabPageIP
			// 
			this->tabPageIP->Controls->Add(this->AddPortbutton);
			this->tabPageIP->Controls->Add(this->discriptionlabel);
			this->tabPageIP->Controls->Add(this->Convertbutton);
			this->tabPageIP->Controls->Add(this->Base64groupBox);
			this->tabPageIP->Controls->Add(this->IPgroupBox);
			this->tabPageIP->Location = System::Drawing::Point(4, 22);
			this->tabPageIP->Name = L"tabPageIP";
			this->tabPageIP->Padding = System::Windows::Forms::Padding(3);
			this->tabPageIP->Size = System::Drawing::Size(369, 295);
			this->tabPageIP->TabIndex = 7;
			this->tabPageIP->Text = L"IPの変換";
			this->tabPageIP->UseVisualStyleBackColor = true;
			// 
			// AddPortbutton
			// 
			this->AddPortbutton->Location = System::Drawing::Point(169, 233);
			this->AddPortbutton->Name = L"AddPortbutton";
			this->AddPortbutton->Size = System::Drawing::Size(103, 24);
			this->AddPortbutton->TabIndex = 4;
			this->AddPortbutton->Text = L"ポート付き変換";
			this->AddPortbutton->UseVisualStyleBackColor = true;
			this->AddPortbutton->Click += gcnew System::EventHandler(this, &OptionForm::AddPortbutton_Click);
			// 
			// discriptionlabel
			// 
			this->discriptionlabel->AutoSize = true;
			this->discriptionlabel->Location = System::Drawing::Point(8, 8);
			this->discriptionlabel->Name = L"discriptionlabel";
			this->discriptionlabel->Size = System::Drawing::Size(297, 48);
			this->discriptionlabel->TabIndex = 3;
			this->discriptionlabel->Text = L"IPアドレスを変換することで、\r\nサーバを公開する際のリスクを多少軽減できます。\r\n\r\nサーバを公開する際は、変換されたアドレスを公開してください。";
			// 
			// Convertbutton
			// 
			this->Convertbutton->Location = System::Drawing::Point(99, 233);
			this->Convertbutton->Name = L"Convertbutton";
			this->Convertbutton->Size = System::Drawing::Size(64, 24);
			this->Convertbutton->TabIndex = 2;
			this->Convertbutton->Text = L"変換";
			this->Convertbutton->UseVisualStyleBackColor = true;
			this->Convertbutton->Click += gcnew System::EventHandler(this, &OptionForm::Convertbutton_Click);
			// 
			// Base64groupBox
			// 
			this->Base64groupBox->Controls->Add(this->labelAddrMT);
			this->Base64groupBox->Controls->Add(this->textBoxMTAddr);
			this->Base64groupBox->Controls->Add(this->labelAddrBase64);
			this->Base64groupBox->Controls->Add(this->Base64textBox);
			this->Base64groupBox->Location = System::Drawing::Point(7, 130);
			this->Base64groupBox->Name = L"Base64groupBox";
			this->Base64groupBox->Size = System::Drawing::Size(352, 84);
			this->Base64groupBox->TabIndex = 1;
			this->Base64groupBox->TabStop = false;
			this->Base64groupBox->Text = L"変換後のアドレス";
			// 
			// labelAddrMT
			// 
			this->labelAddrMT->AutoSize = true;
			this->labelAddrMT->Location = System::Drawing::Point(22, 53);
			this->labelAddrMT->Name = L"labelAddrMT";
			this->labelAddrMT->Size = System::Drawing::Size(47, 12);
			this->labelAddrMT->TabIndex = 3;
			this->labelAddrMT->Text = L"MTSP用";
			// 
			// textBoxMTAddr
			// 
			this->textBoxMTAddr->Location = System::Drawing::Point(75, 50);
			this->textBoxMTAddr->Name = L"textBoxMTAddr";
			this->textBoxMTAddr->ReadOnly = true;
			this->textBoxMTAddr->Size = System::Drawing::Size(271, 19);
			this->textBoxMTAddr->TabIndex = 2;
			// 
			// labelAddrBase64
			// 
			this->labelAddrBase64->AutoSize = true;
			this->labelAddrBase64->Location = System::Drawing::Point(6, 21);
			this->labelAddrBase64->Name = L"labelAddrBase64";
			this->labelAddrBase64->Size = System::Drawing::Size(63, 12);
			this->labelAddrBase64->TabIndex = 1;
			this->labelAddrBase64->Text = L"LilithPort用";
			// 
			// Base64textBox
			// 
			this->Base64textBox->Location = System::Drawing::Point(75, 18);
			this->Base64textBox->MaxLength = 100;
			this->Base64textBox->Name = L"Base64textBox";
			this->Base64textBox->ReadOnly = true;
			this->Base64textBox->Size = System::Drawing::Size(271, 19);
			this->Base64textBox->TabIndex = 0;
			// 
			// IPgroupBox
			// 
			this->IPgroupBox->Controls->Add(this->IPtextBox);
			this->IPgroupBox->Location = System::Drawing::Point(7, 70);
			this->IPgroupBox->Name = L"IPgroupBox";
			this->IPgroupBox->Size = System::Drawing::Size(352, 52);
			this->IPgroupBox->TabIndex = 0;
			this->IPgroupBox->TabStop = false;
			this->IPgroupBox->Text = L"IPアドレス";
			// 
			// IPtextBox
			// 
			this->IPtextBox->AccessibleDescription = L"";
			this->IPtextBox->Location = System::Drawing::Point(7, 19);
			this->IPtextBox->MaxLength = 20;
			this->IPtextBox->Name = L"IPtextBox";
			this->IPtextBox->Size = System::Drawing::Size(339, 19);
			this->IPtextBox->TabIndex = 0;
			this->IPtextBox->TextChanged += gcnew System::EventHandler(this, &OptionForm::IPtextBox_TextChanged);
			// 
			// tabPageDetails
			// 
			this->tabPageDetails->Controls->Add(this->groupBoxDetails);
			this->tabPageDetails->Location = System::Drawing::Point(4, 22);
			this->tabPageDetails->Name = L"tabPageDetails";
			this->tabPageDetails->Padding = System::Windows::Forms::Padding(3);
			this->tabPageDetails->Size = System::Drawing::Size(369, 295);
			this->tabPageDetails->TabIndex = 8;
			this->tabPageDetails->Text = L"詳細";
			this->tabPageDetails->UseVisualStyleBackColor = true;
			// 
			// groupBoxDetails
			// 
			this->groupBoxDetails->Controls->Add(this->checkBoxShowGameOption);
			this->groupBoxDetails->Controls->Add(this->checkBoxNameFlash);
			this->groupBoxDetails->Controls->Add(this->checkBoxGetIP);
			this->groupBoxDetails->Controls->Add(this->checkBoxTalkFlash);
			this->groupBoxDetails->Location = System::Drawing::Point(9, 7);
			this->groupBoxDetails->Name = L"groupBoxDetails";
			this->groupBoxDetails->Size = System::Drawing::Size(351, 282);
			this->groupBoxDetails->TabIndex = 0;
			this->groupBoxDetails->TabStop = false;
			this->groupBoxDetails->Text = L"詳細設定";
			// 
			// checkBoxShowGameOption
			// 
			this->checkBoxShowGameOption->AutoSize = true;
			this->checkBoxShowGameOption->Location = System::Drawing::Point(8, 85);
			this->checkBoxShowGameOption->Name = L"checkBoxShowGameOption";
			this->checkBoxShowGameOption->Size = System::Drawing::Size(199, 16);
			this->checkBoxShowGameOption->TabIndex = 3;
			this->checkBoxShowGameOption->Text = L"ゲーム起動時に対戦設定を表示する";
			this->checkBoxShowGameOption->UseVisualStyleBackColor = true;
			this->checkBoxShowGameOption->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// checkBoxNameFlash
			// 
			this->checkBoxNameFlash->AutoSize = true;
			this->checkBoxNameFlash->Location = System::Drawing::Point(8, 40);
			this->checkBoxNameFlash->Name = L"checkBoxNameFlash";
			this->checkBoxNameFlash->Size = System::Drawing::Size(203, 16);
			this->checkBoxNameFlash->TabIndex = 1;
			this->checkBoxNameFlash->Text = L"名前が呼ばれたらウィンドウを点滅する";
			this->checkBoxNameFlash->UseVisualStyleBackColor = true;
			this->checkBoxNameFlash->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// checkBoxGetIP
			// 
			this->checkBoxGetIP->AutoSize = true;
			this->checkBoxGetIP->Location = System::Drawing::Point(8, 62);
			this->checkBoxGetIP->Name = L"checkBoxGetIP";
			this->checkBoxGetIP->Size = System::Drawing::Size(200, 16);
			this->checkBoxGetIP->TabIndex = 2;
			this->checkBoxGetIP->Text = L"Server起動時にIPアドレスを取得する";
			this->checkBoxGetIP->UseVisualStyleBackColor = true;
			this->checkBoxGetIP->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// checkBoxTalkFlash
			// 
			this->checkBoxTalkFlash->AutoSize = true;
			this->checkBoxTalkFlash->Location = System::Drawing::Point(8, 18);
			this->checkBoxTalkFlash->Name = L"checkBoxTalkFlash";
			this->checkBoxTalkFlash->Size = System::Drawing::Size(153, 16);
			this->checkBoxTalkFlash->TabIndex = 0;
			this->checkBoxTalkFlash->Text = L"発言でウィンドウを点滅する";
			this->checkBoxTalkFlash->UseVisualStyleBackColor = true;
			this->checkBoxTalkFlash->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// checkBoxShowResult
			// 
			this->checkBoxShowResult->AutoSize = true;
			this->checkBoxShowResult->Location = System::Drawing::Point(16, 64);
			this->checkBoxShowResult->Name = L"checkBoxShowResult";
			this->checkBoxShowResult->Size = System::Drawing::Size(72, 16);
			this->checkBoxShowResult->TabIndex = 5;
			this->checkBoxShowResult->Text = L"対戦勝敗";
			this->checkBoxShowResult->UseVisualStyleBackColor = true;
			this->checkBoxShowResult->CheckedChanged += gcnew System::EventHandler(this, &OptionForm::ApplyButtonEnable);
			// 
			// OptionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(377, 362);
			this->Controls->Add(this->tabControlOption);
			this->Controls->Add(this->buttonApply);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"OptionForm";
			this->ShowInTaskbar = false;
			this->Text = L"オプション";
			this->Load += gcnew System::EventHandler(this, &OptionForm::OptionForm_Load);
			this->Shown += gcnew System::EventHandler(this, &OptionForm::OptionForm_Shown);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &OptionForm::OptionForm_FormClosed);
			this->tabPageSound->ResumeLayout(false);
			this->groupBoxKeywordSound->ResumeLayout(false);
			this->groupBoxKeywordSound->PerformLayout();
			this->groupBoxSeekSound->ResumeLayout(false);
			this->groupBoxSeekSound->PerformLayout();
			this->groupBoxTalkSound->ResumeLayout(false);
			this->groupBoxTalkSound->PerformLayout();
			this->groupBoxName->ResumeLayout(false);
			this->groupBoxName->PerformLayout();
			this->groupBoxEnterSound->ResumeLayout(false);
			this->groupBoxEnterSound->PerformLayout();
			this->groupBoxNoticeSound->ResumeLayout(false);
			this->groupBoxNoticeSound->PerformLayout();
			this->groupBoxVSSound->ResumeLayout(false);
			this->groupBoxVSSound->PerformLayout();
			this->tabPagePath->ResumeLayout(false);
			this->groupBoxProfile->ResumeLayout(false);
			this->groupBoxProfile->PerformLayout();
			this->groupBoxReplayFolder->ResumeLayout(false);
			this->groupBoxReplayFolder->PerformLayout();
			this->groupBoxNet->ResumeLayout(false);
			this->groupBoxNet->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownMaxConnection))->EndInit();
			this->groupBoxGameExe->ResumeLayout(false);
			this->groupBoxGameExe->PerformLayout();
			this->groupBoxSave->ResumeLayout(false);
			this->groupBoxSave->PerformLayout();
			this->tabControlOption->ResumeLayout(false);
			this->tabPageGame->ResumeLayout(false);
			this->groupBoxTeamOption->ResumeLayout(false);
			this->groupBoxTeamOption->PerformLayout();
			this->groupBoxSimulate->ResumeLayout(false);
			this->groupBoxSimulate->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownSimDelay))->EndInit();
			this->groupBoxRun->ResumeLayout(false);
			this->groupBoxRun->PerformLayout();
			this->groupBoxView->ResumeLayout(false);
			this->groupBoxView->PerformLayout();
			this->groupBoxSetting->ResumeLayout(false);
			this->groupBoxSetting->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownRound))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownTimer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownMaxStage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownStageSelect))->EndInit();
			this->tabPageColor->ResumeLayout(false);
			this->groupBoxMessageColor->ResumeLayout(false);
			this->groupBoxOthersColor->ResumeLayout(false);
			this->groupBoxStateColor->ResumeLayout(false);
			this->groupBoxNameColor->ResumeLayout(false);
			this->tabPageVolume->ResumeLayout(false);
			this->groupBoxMidi->ResumeLayout(false);
			this->groupBoxMidi->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarMidi))->EndInit();
			this->groupBoxSE->ResumeLayout(false);
			this->groupBoxSE->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarSE))->EndInit();
			this->groupBoxBGM->ResumeLayout(false);
			this->groupBoxBGM->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBarBGM))->EndInit();
			this->tabPageIP->ResumeLayout(false);
			this->tabPageIP->PerformLayout();
			this->Base64groupBox->ResumeLayout(false);
			this->Base64groupBox->PerformLayout();
			this->IPgroupBox->ResumeLayout(false);
			this->IPgroupBox->PerformLayout();
			this->tabPageDetails->ResumeLayout(false);
			this->groupBoxDetails->ResumeLayout(false);
			this->groupBoxDetails->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	protected:
		HMIXER hMixer;
		DWORD MixerControlID;
		DWORD MixerVolumeMin, MixerVolumeMax;

		void AdviceGameExe(){
			textBoxGameExe->Text = gcnew String("右のボタンを押してパスを設定してください");
			textBoxGameExe->Focus();
		}

		void CheckStageValue(){
			if(numericUpDownStageSelect->Value > numericUpDownMaxStage->Value){
				labelMaxStage->Text    = gcnew String("開始ステージ");
				labelStageSelect->Text = gcnew String("終端ステージ");
			}
			else{
				labelMaxStage->Text    = gcnew String("最大ステージ数");
				labelStageSelect->Text = gcnew String("対戦ステージ");
			}

			if(numericUpDownStageSelect->Value == 0){
				labelStageSelect->Text = gcnew String("ランダムステージ");
			}
		}

		// OptionForm.cpp
		void SaveOption(bool apply);
		void CloseOption();
		void DeleteProfile(String^ buf);
		bool CheckTextProfileName(String^ buf);
		void OverWriteProfile(String^ buf);

	public:
		bool GameExePathError;

		void SetGameExePath(String^% path){
			textBoxGameExe->Text = path;
		}

	private:
		System::Void OptionForm_Load(System::Object^  sender, System::EventArgs^  e) {

			textBoxGameExe->MaxLength          = _MAX_PATH;
			textBoxReplayFolder->MaxLength     = _MAX_PATH;
			textBoxVSSound->MaxLength          = _MAX_PATH;
			textBoxNoticeSound->MaxLength      = _MAX_PATH;
			textBoxEnterSound->MaxLength       = _MAX_PATH;
			textBoxTalkSound->MaxLength        = _MAX_PATH;
			textBoxSeekSound->MaxLength        = _MAX_PATH;
			textBoxKeywordSoundPath->MaxLength = _MAX_PATH;

			textBoxComment->MaxLength = MAX_NAME;

			comboBoxProfile->Items->Clear();
			for(int i=0; i < Profile::ProfileList->Count; i++){
				comboBoxProfile->Items->Add(Profile::ProfileList[i]);
				if(Profile::ProfileList[i] == gcnew String(MTOPTION.PROFILE)){
					comboBoxProfile->SelectedIndex = i;
				}
			}

			textBoxGameExe->Text          = gcnew String(MTOPTION.GAME_EXE);
			textBoxReplayFolder->Text     = gcnew String(MTOPTION.REPLAY_FOLDER);
			textBoxComment->Text          = gcnew String(MTOPTION.COMMENT);
			textBoxVSSound->Text          = gcnew String(MTOPTION.VS_SOUND);
			textBoxNoticeSound->Text      = gcnew String(MTOPTION.NOTICE_SOUND);
			textBoxEnterSound->Text       = gcnew String(MTOPTION.ENTER_SOUND);
			textBoxNameSound->Text        = gcnew String(MTOPTION.NAME_SOUND);
			textBoxTalkSound->Text        = gcnew String(MTOPTION.TALK_SOUND);
			textBoxSeekSound->Text        = gcnew String(MTOPTION.SEEK_SOUND);
			textBoxKeywordSoundPath->Text = gcnew String(MTOPTION.KEYWORD_SOUND);
			textBoxKeyword->Text          = gcnew String(MTOPTION.KEYWORD);

			// パスのセレクションを末尾に
			textBoxGameExe->SelectionStart          = textBoxGameExe->Text->Length;
			textBoxReplayFolder->SelectionStart     = textBoxReplayFolder->Text->Length;
			textBoxComment->SelectionStart          = textBoxComment->Text->Length;
			textBoxVSSound->SelectionStart          = textBoxVSSound->Text->Length;
			textBoxNoticeSound->SelectionStart      = textBoxNoticeSound->Text->Length;
			textBoxEnterSound->SelectionStart       = textBoxEnterSound->Text->Length;
			textBoxNameSound->SelectionStart        = textBoxNameSound->Text->Length;
			textBoxTalkSound->SelectionStart        = textBoxTalkSound->Text->Length;
			textBoxSeekSound->SelectionStart        = textBoxSeekSound->Text->Length;
			textBoxKeywordSoundPath->SelectionStart = textBoxKeywordSoundPath->Text->Length;

			checkBoxVSSound->Checked          = MTOPTION.VS_SOUND_ENABLE;
			checkBoxNoticeSound->Checked      = MTOPTION.NOTICE_SOUND_ENABLE;
			checkBoxEnterSound->Checked       = MTOPTION.ENTER_SOUND_ENABLE;
			checkBoxNameSound->Checked        = MTOPTION.NAME_SOUND_ENABLE;
			checkBoxTalkSound->Checked        = MTOPTION.TALK_SOUND_ENABLE;
			checkBoxSeekSound->Checked        = MTOPTION.SEEK_SOUND_ENABLE;
			checkBoxKeywordSound->Checked     = MTOPTION.KEYWORD_SOUND_ENABLE;

			checkBoxGetIP->Checked            = MTOPTION.GET_IP_ENABLE;
			checkBoxShowGameOption->Checked   = MTOPTION.SHOW_GAME_OPTION;
			checkBoxShowResult->Checked       = MTOPTION.SHOW_RESULT;

			numericUpDownMaxConnection->Value = MTOPTION.MAX_CONNECTION;
			trackBarBGM->Value                = MTOPTION.BGM_VOLUME / 5;
			trackBarSE->Value                 = MTOPTION.SE_VOLUME / 5;
			numericUpDownMaxStage->Value      = MTOPTION.MAX_STAGE;
			numericUpDownStageSelect->Value   = MTOPTION.STAGE_SELECT;
			numericUpDownRound->Value         = MTOPTION.ROUND;
			numericUpDownTimer->Value         = MTOPTION.TIMER;
			numericUpDownSimDelay->Value      = MTOPTION.SIMULATE_DELAY;
			checkBoxHitJudge->Checked         = MTOPTION.HIT_JUDGE;
			checkBoxName->Checked             = MTOPTION.DISPLAY_NAME;
			checkBoxVersus->Checked           = MTOPTION.DISPLAY_VERSUS;
			checkBoxFramerate->Checked        = MTOPTION.DISPLAY_FRAMERATE;
			checkBoxRand->Checked             = MTOPTION.DISPLAY_RAND;
			checkBoxDivide->Checked           = MTOPTION.REPLAY_DIVIDE;
			checkBoxWindowSize->Checked       = MTOPTION.CHANGE_WINDOW_SIZE;
			checkBoxTalkFlash->Checked        = MTOPTION.TALK_FLASH;
			checkBoxNameFlash->Checked        = MTOPTION.NAME_FLASH;
			checkBoxTeamRoundHP->Checked      = MTOPTION.TEAM_ROUND_HP;

			CheckStageValue();

			labelBGM->Text = String::Format("{0,3}%", trackBarBGM->Value * 5);
			labelSE->Text = String::Format("{0,3}%", trackBarSE->Value * 5);

			if(MTOPTION.REPLAY_VERSION == 2){
				radioButtonReplayVersion1->Checked = false;
				radioButtonReplayVersion2->Checked = true;
			}
			else{
				radioButtonReplayVersion1->Checked = true;
				radioButtonReplayVersion2->Checked = false;
			}

			buttonServerName->ForeColor    = Color::FromArgb(MTCOLOR.SERVER_NAME);
			buttonHostName->ForeColor      = Color::FromArgb(MTCOLOR.HOST_NAME);
			buttonClientName->ForeColor    = Color::FromArgb(MTCOLOR.CLIENT_NAME);
			buttonRestState->BackColor     = Color::FromArgb(MTCOLOR.REST_STATE);
			buttonVSState->BackColor       = Color::FromArgb(MTCOLOR.VS_STATE);
			buttonWatchState->BackColor    = Color::FromArgb(MTCOLOR.WATCH_STATE);
			buttonSeekState->BackColor     = Color::FromArgb(MTCOLOR.SEEK_STATE);

			buttonSystemMessage->ForeColor = Color::FromArgb(MTCOLOR.SYSTEM_MESSAGE);
			buttonErrorMessage->ForeColor  = Color::FromArgb(MTCOLOR.ERROR_MESSAGE);
			buttonDebugMessage->ForeColor  = Color::FromArgb(MTCOLOR.DEBUG_MESSAGE);
			buttonNoticeBack->BackColor    = Color::FromArgb(MTCOLOR.NOTICE_BACK);
			buttonCommentBack->BackColor   = Color::FromArgb(MTCOLOR.COMMENT_BACK);
			buttonSecret->ForeColor        = Color::FromArgb(MTCOLOR.SECRET);

			// SWシンセ
			try{
				hMixer = NULL;
				pin_ptr<HMIXER> p_hm = &hMixer;

				if(mixerOpen(p_hm, 0, 0, 0, MIXER_OBJECTF_MIXER) != MMSYSERR_NOERROR){
					throw gcnew Exception;
				}
				else{
					// 準備
					MIXERLINE line;
					MIXERLINECONTROLS lc;
					MIXERCONTROL ctrl;

					line.cbStruct        = sizeof(MIXERLINE);
					line.dwComponentType = MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER;

					if(mixerGetLineInfo((HMIXEROBJ)hMixer, &line, MIXER_OBJECTF_HMIXER | MIXER_GETLINEINFOF_COMPONENTTYPE) != MMSYSERR_NOERROR){
						throw gcnew Exception;
					}

					lc.cbStruct      = sizeof(MIXERLINECONTROLS);
					lc.dwLineID      = line.dwLineID;
					lc.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
					lc.cControls     = 1;
					lc.cbmxctrl      = sizeof(MIXERCONTROL);
					lc.pamxctrl      = &ctrl;

					if(mixerGetLineControls((HMIXEROBJ)hMixer, &lc, MIXER_OBJECTF_HMIXER | MIXER_GETLINECONTROLSF_ONEBYTYPE) != MMSYSERR_NOERROR){
						throw gcnew Exception;
					}

					MixerControlID = ctrl.dwControlID;
					MixerVolumeMin = ctrl.Bounds.dwMinimum;
					MixerVolumeMax = ctrl.Bounds.dwMaximum;

					// 音量取得
					MIXERCONTROLDETAILS mcd;
					MIXERCONTROLDETAILS_UNSIGNED vol;

					mcd.cbStruct       = sizeof(MIXERCONTROLDETAILS);
					mcd.dwControlID    = ctrl.dwControlID;
					mcd.cChannels      = 1;
					mcd.cMultipleItems = 0;
					mcd.cbDetails      = sizeof(MIXERCONTROLDETAILS_UNSIGNED);
					mcd.paDetails      = &vol;

					if(mixerGetControlDetails((HMIXEROBJ)hMixer, &mcd, MIXER_OBJECTF_HMIXER | MIXER_GETCONTROLDETAILSF_VALUE) != MMSYSERR_NOERROR){
						throw gcnew Exception;
					}

					DWORD delta = MixerVolumeMax - MixerVolumeMin;
					trackBarMidi->Value = ((vol.dwValue - MixerVolumeMin)*100 + delta/2)/delta;

					labelMidi->Text = String::Format("{0,3}%", trackBarMidi->Value);
				}
			}
			catch(Exception^){
				if(hMixer != NULL){
					mixerClose(hMixer);
					hMixer = NULL;
				}

				labelMidi->Text = gcnew String("xxx");
				groupBoxMidi->Enabled = false;
			}

			if(MTWS.DIALOG_LEFT > 0 && MTWS.DIALOG_TOP > 0){
				this->StartPosition = FormStartPosition::Manual;
				this->Location = Point(MTWS.DIALOG_LEFT, MTWS.DIALOG_TOP);
			}

			buttonApply->Enabled = false;
		}

		System::Void OptionForm_Shown(System::Object^  sender, System::EventArgs^  e) {
			if(GameExePathError){
				AdviceGameExe();
			}
		}

		System::Void OptionForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			if(hMixer != NULL){
				mixerClose(hMixer);
				hMixer = NULL;
			}

			MTWS.DIALOG_LEFT = this->Location.X;
			MTWS.DIALOG_TOP  = this->Location.Y;

			CloseOption();

			this->Owner->Focus();
		}

		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			if(buttonApply->Enabled){
				buttonApply->Enabled = false;

				SaveOption(false);
			}

			this->Close();
		}

		System::Void buttonApply_Click(System::Object^  sender, System::EventArgs^  e) {
			buttonApply->Enabled = false;

			SaveOption(true);
		}

		System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			this->Close();
		}

		System::Void buttonGameExe_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->Title  = gcnew String("格闘ツクールの実行ファイル");
			openFileDialog1->Filter = gcnew String("exe file (*.exe)|*.exe");

			if(openFileDialog1->ShowDialog() == ::DialogResult::OK){
				FileVersionInfo^ info = FileVersionInfo::GetVersionInfo(openFileDialog1->FileName);

				if(info->FileDescription == "２Ｄ格闘ツクール2nd." || info->FileDescription == "２Ｄ格闘ツクール９５"){
					textBoxGameExe->Text = openFileDialog1->FileName;
				}
				else{
					textBoxGameExe->Text = "格闘ツクールの実行ファイルではありません";
					textBoxGameExe->SelectAll();
					textBoxGameExe->Focus();
				}
			}
		}

		System::Void buttonReplayFolder_Click(System::Object^  sender, System::EventArgs^  e) {
			if(folderBrowserDialog1->ShowDialog() == ::DialogResult::OK){
				textBoxReplayFolder->Text = folderBrowserDialog1->SelectedPath;
			}
		}

		System::Void buttonVSSound_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->Title  = gcnew String("対戦時に鳴らす音声ファイル");
			openFileDialog1->Filter = gcnew String("wav file (*.wav)|*.wav");

			if(openFileDialog1->ShowDialog() == ::DialogResult::OK){
				textBoxVSSound->Text = openFileDialog1->FileName;
			}
		}

		System::Void buttonNoticeSound_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->Title  = gcnew String("告知受信時に鳴らす音声ファイル");
			openFileDialog1->Filter = gcnew String("wav file (*.wav)|*.wav");

			if(openFileDialog1->ShowDialog() == ::DialogResult::OK){
				textBoxNoticeSound->Text = openFileDialog1->FileName;
			}
		}

		System::Void buttonEnterSound_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->Title  = gcnew String("メンバー入室時に鳴らす音声ファイル");
			openFileDialog1->Filter = gcnew String("wav file (*.wav)|*.wav");

			if(openFileDialog1->ShowDialog() == ::DialogResult::OK){
				textBoxEnterSound->Text = openFileDialog1->FileName;
			}
		}

		System::Void buttonNameSound_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->Title  = gcnew String("ニックネームが呼ばれたら鳴らす音声ファイル");
			openFileDialog1->Filter = gcnew String("wav file (*.wav)|*.wav");

			if(openFileDialog1->ShowDialog() == ::DialogResult::OK){
				textBoxNameSound->Text = openFileDialog1->FileName;
			}
		}

		System::Void buttonTalkSound_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->Title  = gcnew String("発言で鳴らす音声ファイル");
			openFileDialog1->Filter = gcnew String("wav file (*.wav)|*.wav");

			if(openFileDialog1->ShowDialog() == ::DialogResult::OK){
				textBoxTalkSound->Text = openFileDialog1->FileName;
			}
		}

		System::Void buttonSeekSound_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->Title  = gcnew String("対戦募集で鳴らす音声ファイル");
			openFileDialog1->Filter = gcnew String("wav file (*.wav)|*.wav");

			if(openFileDialog1->ShowDialog() == ::DialogResult::OK){
				textBoxSeekSound->Text = openFileDialog1->FileName;
			}
		}

		System::Void buttonKeywordSound_Click(System::Object^  sender, System::EventArgs^  e) {
			openFileDialog1->Title  = gcnew String("キーワードで鳴らす音声ファイル");
			openFileDialog1->Filter = gcnew String("wav file (*.wav)|*.wav");

			if(openFileDialog1->ShowDialog() == ::DialogResult::OK){
				textBoxKeywordSoundPath->Text = openFileDialog1->FileName;
			}
		}

		System::Void ApplyButtonEnable(System::Object^  sender, System::EventArgs^  e) {
			buttonApply->Enabled = true;
		}

		System::Void numericUpDownStage_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			buttonApply->Enabled = true;

			CheckStageValue();
		}

		System::Void buttonServerName_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonServerName->ForeColor = colorDialog1->Color;
			}
		}

		System::Void buttonHostName_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonHostName->ForeColor = colorDialog1->Color;
			}
		}

		System::Void buttonClientName_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonClientName->ForeColor = colorDialog1->Color;
			}
		}

		System::Void buttonRestState_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonRestState->BackColor = colorDialog1->Color;
			}
		}

		System::Void buttonVSState_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonVSState->BackColor = colorDialog1->Color;
			}
		}

		System::Void buttonWatchState_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonWatchState->BackColor = colorDialog1->Color;
			}
		}

		System::Void buttonSeekState_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonSeekState->BackColor = colorDialog1->Color;
			}
		}

		System::Void buttonSystemMessage_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonSystemMessage->ForeColor = colorDialog1->Color;
			}
		}

		System::Void buttonErrorMessage_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonErrorMessage->ForeColor = colorDialog1->Color;
			}
		}

		System::Void buttonDebugMessage_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonDebugMessage->ForeColor = colorDialog1->Color;
			}
		}

		System::Void buttonNoticeBack_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonNoticeBack->BackColor = colorDialog1->Color;
			}
		}

		System::Void buttonCommentBack_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonCommentBack->BackColor = colorDialog1->Color;
			}
		}

		System::Void buttonSecret_Click(System::Object^  sender, System::EventArgs^  e) {
			if(colorDialog1->ShowDialog() == ::DialogResult::OK){
				buttonSecret->ForeColor = colorDialog1->Color;
			}
		}

		System::Void trackBarBGM_Scroll(System::Object^  sender, System::EventArgs^  e) {
			buttonApply->Enabled = true;

			labelBGM->Text = String::Format("{0,3}%", trackBarBGM->Value * 5);
		}

		System::Void trackBarSE_Scroll(System::Object^  sender, System::EventArgs^  e) {
			buttonApply->Enabled = true;

			labelSE->Text = String::Format("{0,3}%", trackBarSE->Value * 5);
		}

		System::Void trackBarMidi_Scroll(System::Object^  sender, System::EventArgs^  e) {
			labelMidi->Text = String::Format("{0,3}%", trackBarMidi->Value);

			MIXERCONTROLDETAILS mcd;
			MIXERCONTROLDETAILS_UNSIGNED vol;

			vol.dwValue = trackBarMidi->Value*(MixerVolumeMax - MixerVolumeMin)/100 + MixerVolumeMin;

			mcd.cbStruct       = sizeof(MIXERCONTROLDETAILS);
			mcd.dwControlID    = MixerControlID;
			mcd.cChannels      = 1;
			mcd.cMultipleItems = 0;
			mcd.cbDetails      = sizeof(MIXERCONTROLDETAILS_UNSIGNED);
			mcd.paDetails      = &vol;

			if(mixerSetControlDetails((HMIXEROBJ)hMixer, &mcd, MIXER_OBJECTF_HMIXER | MIXER_SETCONTROLDETAILSF_VALUE) != MMSYSERR_NOERROR){
				if(hMixer != NULL){
					mixerClose(hMixer);
					hMixer = NULL;
				}

				labelMidi->Text = gcnew String("xxx");
				groupBoxMidi->Enabled = false;
			}
		}

		System::Void textBoxGameExe_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			e->Effect = DragDropEffects::None;

			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				array<String^>^ file = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false));
				String^ extension = Path::GetExtension(file[0])->ToLower();
				FileVersionInfo^ info = FileVersionInfo::GetVersionInfo(file[0]);

				if(extension == ".exe" && (info->FileDescription == "２Ｄ格闘ツクール2nd." || info->FileDescription == "２Ｄ格闘ツクール９５")){
					e->Effect = DragDropEffects::All;
				}
			}
		}

		System::Void textBoxGameExe_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				textBoxGameExe->Text = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false))[0];
			}
		}

		System::Void textBoxReplayFolder_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			e->Effect = DragDropEffects::None;

			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				array<String^>^ file = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false));
				String^ extension = Path::GetExtension(file[0]);

				if(extension == String::Empty){
					e->Effect = DragDropEffects::All;
				}
			}
		}

		System::Void textBoxReplayFolder_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				textBoxReplayFolder->Text = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false))[0];
			}
		}

		System::Void textBoxSound_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			e->Effect = DragDropEffects::None;

			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				array<String^>^ file = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false));
				String^ extension = Path::GetExtension(file[0])->ToLower();

				if(extension == ".wav"){
					e->Effect = DragDropEffects::All;
				}
			}
		}

		System::Void textBoxVSSound_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				textBoxVSSound->Text = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false))[0];
			}
		}

		System::Void textBoxNoticeSound_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				textBoxNoticeSound->Text = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false))[0];
			}
		}

		System::Void textBoxEnterSound_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				textBoxEnterSound->Text = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false))[0];
			}
		}

		System::Void textBoxNameSound_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				textBoxNameSound->Text = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false))[0];
			}
		}

		System::Void textBoxTalkSound_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				textBoxTalkSound->Text = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false))[0];
			}
		}

		System::Void textBoxSeekSound_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				textBoxSeekSound->Text = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false))[0];
			}
		}

		System::Void textBoxKeywordSound_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
			if(e->Data->GetDataPresent(DataFormats::FileDrop)){
				textBoxKeywordSoundPath->Text = safe_cast<array<String^>^>(e->Data->GetData(DataFormats::FileDrop, false))[0];
			}
		}

		// 再生ボタン
		System::Void buttonVSSoundPlay_Click(System::Object^  sender, System::EventArgs^  e) {
			try{
				Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.VS_SOUND));
				wav->Play();
			}
			catch(Exception^){
			}
		}
		System::Void buttonEnterSoundPlay_Click(System::Object^  sender, System::EventArgs^  e) {
			try{
				Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.ENTER_SOUND));
				wav->Play();
			}
			catch(Exception^){
			}
		}
		System::Void buttonNoticeSoundPlay_Click(System::Object^  sender, System::EventArgs^  e) {
			try{
				Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.NOTICE_SOUND));
				wav->Play();
			}
			catch(Exception^){
			}
		}
		System::Void buttonNameSoundPlay_Click(System::Object^  sender, System::EventArgs^  e) {
			try{
				Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.NAME_SOUND));
				wav->Play();
			}
			catch(Exception^){
			}
		}
		System::Void buttonTalkSoundPlay_Click(System::Object^  sender, System::EventArgs^  e) {
			try{
				Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.TALK_SOUND));
				wav->Play();
			}
			catch(Exception^){
			}
		}
		System::Void buttonSeekSoundPlay_Click(System::Object^  sender, System::EventArgs^  e) {
			try{
				Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.SEEK_SOUND));
				wav->Play();
			}
			catch(Exception^){
			}
		}
		System::Void buttonKeywordSoundPlay_Click(System::Object^  sender, System::EventArgs^  e) {
			try{
				Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.KEYWORD_SOUND));
				wav->Play();
			}
			catch(Exception^){
			}
		}

		// IP入力チェック
		System::Void IPtextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			if(Net::IPAddress::TryParse(IPtextBox->Text, gcnew Net::IPAddress(0)) == false){
				Convertbutton->Enabled = false;
				AddPortbutton->Enabled = false;
			}
			else{
				Convertbutton->Enabled = true;
				AddPortbutton->Enabled = true;
			}
		}
		// IPの変換
		System::Void Convertbutton_Click(System::Object^  sender, System::EventArgs^  e) {
			Base64textBox->Text = EncryptionIP(IPtextBox->Text);
			textBoxMTAddr->Text = MTEncryptionIP(IPtextBox->Text);
		}
		// ポート付きIPの変換
		System::Void AddPortbutton_Click(System::Object^  sender, System::EventArgs^  e) {
			Base64textBox->Text = String::Format("{0}:{1}", EncryptionIP(IPtextBox->Text), MTOPTION.OPEN_PORT);
			textBoxMTAddr->Text = String::Format("{0}:{1}", MTEncryptionIP(IPtextBox->Text), MTOPTION.OPEN_PORT);
		}
		// プロファイルコンボボックス変更
		System::Void comboBoxProfile_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
			String^ buf = ((ComboBox^)sender)->Text;
			String^ bufProfile = gcnew String(MTOPTION.PROFILE);

			if(buf != bufProfile){
				// 切り替え
				IntPtr mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(buf);
				_tcscpy_s(MTOPTION.PROFILE, static_cast<PTCHAR>(mp.ToPointer()));
				Runtime::InteropServices::Marshal::FreeHGlobal(mp);

				LoadMTOption();

				// プロファイルセクションの設定値を更新
				textBoxGameExe->Text                = gcnew String(MTOPTION.GAME_EXE);
				textBoxReplayFolder->Text           = gcnew String(MTOPTION.REPLAY_FOLDER);
				textBoxGameExe->SelectionStart      = textBoxGameExe->Text->Length;
				textBoxReplayFolder->SelectionStart = textBoxReplayFolder->Text->Length;
				numericUpDownMaxStage->Value        = MTOPTION.MAX_STAGE;
				numericUpDownStageSelect->Value     = MTOPTION.STAGE_SELECT;
				numericUpDownRound->Value           = MTOPTION.ROUND;
				numericUpDownTimer->Value           = MTOPTION.TIMER;
				numericUpDownSimDelay->Value        = MTOPTION.SIMULATE_DELAY;
				checkBoxHitJudge->Checked           = MTOPTION.HIT_JUDGE;
				checkBoxName->Checked               = MTOPTION.DISPLAY_NAME;
				checkBoxVersus->Checked             = MTOPTION.DISPLAY_VERSUS;
				checkBoxFramerate->Checked          = MTOPTION.DISPLAY_FRAMERATE;
				checkBoxRand->Checked               = MTOPTION.DISPLAY_RAND;
				checkBoxDivide->Checked             = MTOPTION.REPLAY_DIVIDE;
				checkBoxWindowSize->Checked         = MTOPTION.CHANGE_WINDOW_SIZE;
				checkBoxTeamRoundHP->Checked        = MTOPTION.TEAM_ROUND_HP;
				CheckStageValue();
				if(MTOPTION.REPLAY_VERSION == 2){
					radioButtonReplayVersion1->Checked = false;
					radioButtonReplayVersion2->Checked = true;
				}
				else{
					radioButtonReplayVersion1->Checked = true;
					radioButtonReplayVersion2->Checked = false;
				}
			}
			textBoxProfileName->Text = buf;
			buttonApply->Enabled = false;
		}
		System::Void buttonCopyProfile_Click(System::Object^ sender, System::EventArgs^ e) {
			// プロファイル複製
			String^ mes;
			String^ buf = comboBoxProfile->Items[comboBoxProfile->SelectedIndex]->ToString();
			String^ bufClone = String::Format("{0}{1}", buf, "_");
			if(buf->Length > MAX_ARRAY-1){
				mes = "プロファイル名が長すぎます。\n複製を行うには、プロファイル名を短くしてください。";
			}
			for(int i=0; i < Profile::ProfileList->Count; i++){
				if(Profile::ProfileList[i] == bufClone){
					mes = "既に複製されたプロファイルが存在します。";
				}
			}
			if(Profile::ProfileList->Count > 31){
				mes = "これ以上プロファイルを作成できません。";
				return;
			}
			if(mes != nullptr){
				MessageBox::Show(mes, "プロファイル複製", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return;
			}
			Profile::ProfileList->Add(bufClone);
			comboBoxProfile->Items->Add(bufClone);

			IntPtr mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(bufClone);
			_tcscpy_s(MTOPTION.PROFILE, static_cast<PTCHAR>(mp.ToPointer()));
			Runtime::InteropServices::Marshal::FreeHGlobal(mp);

			SaveOption(true);

			comboBoxProfile->SelectedIndex = comboBoxProfile->Items->Count-1;
			buttonApply->Enabled = false;

		}
		System::Void buttonDeleteProfile_Click(System::Object^ sender, System::EventArgs^ e) {
			// プロファイル削除
			int index = comboBoxProfile->SelectedIndex;
			String^ buf = comboBoxProfile->Items[index]->ToString();
			if(MessageBox::Show(String::Format("{0}を削除します。\nよろしいですか？", buf), "プロファイル削除", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
				Profile::ProfileList->RemoveAt(index);
				comboBoxProfile->Items->RemoveAt(index);

				DeleteProfile(buf);

				comboBoxProfile->SelectedIndex = 0;
			}else{
				return;
			}
		}
		System::Void buttonAddProfile_Click(System::Object^ sender, System::EventArgs^ e) {
			// プロファイル追加
			String^ bufText = textBoxProfileName->Text;
			if(CheckTextProfileName(bufText)){
				return;
			}
			if(Profile::ProfileList->Count > 31){
				MessageBox::Show("これ以上プロファイルを作成できません。", "プロファイル追加", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return;
			}

			Profile::ProfileList->Add(bufText);
			comboBoxProfile->Items->Add(bufText);

			SaveOption(true);

			buttonApply->Enabled = false;
		}
		System::Void buttonSaveProfile_Click(System::Object^ sender, System::EventArgs^ e) {
			// プロファイル保存
			String^ bufText         = textBoxProfileName->Text;
			String^ bufSelectedItem = comboBoxProfile->SelectedItem->ToString();
			if(CheckTextProfileName(bufText)){
				return;
			}
			// 上書き
			if(bufText != bufSelectedItem){
				for(int i=0; i < Profile::ProfileList->Count; i++){
					if(Profile::ProfileList[i] == gcnew String(MTOPTION.PROFILE)){
						Profile::ProfileList[i] = bufText;
					}
				}
				OverWriteProfile(bufText);

				comboBoxProfile->Items[comboBoxProfile->SelectedIndex] = bufText;
			}
		}
	};
}
