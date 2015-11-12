#pragma once

#include "stdafx.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace LilithPort {

	/// <summary>
	/// StartupForm の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class StartupForm : public System::Windows::Forms::Form
	{
	public:
		StartupForm(void)
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
		~StartupForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^  radioButtonServer;
	private: System::Windows::Forms::RadioButton^  radioButtonHost;
	private: System::Windows::Forms::RadioButton^  radioButtonClient;
	private: System::Windows::Forms::Label^  labelServerName;
	private: System::Windows::Forms::TextBox^  textBoxIP;
	private: System::Windows::Forms::Label^  labelOpenPort;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownOpenPort;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::Label^  labelName;
	private: System::Windows::Forms::TextBox^  textBoxName;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownPort;
	private: System::Windows::Forms::Label^  labelMaxConnection;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownMaxConnection;
	private: System::Windows::Forms::Label^  labelComment;
	private: System::Windows::Forms::TextBox^  textBoxComment;
	private: System::Windows::Forms::GroupBox^  groupBoxStartMode;
	private: System::Windows::Forms::TextBox^  textBoxServerName;
	private: System::Windows::Forms::GroupBox^  groupBoxConnection;
	private: System::Windows::Forms::Label^  labelIP;
	private: System::Windows::Forms::Label^  labelAccessPort;
	private: System::Windows::Forms::GroupBox^  groupBoxProfile;
	private: System::Windows::Forms::GroupBox^  groupBoxWelcome;
	private: System::Windows::Forms::RichTextBox^  textBoxWelcome;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(StartupForm::typeid));
			this->radioButtonServer = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonHost = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonClient = (gcnew System::Windows::Forms::RadioButton());
			this->labelServerName = (gcnew System::Windows::Forms::Label());
			this->textBoxIP = (gcnew System::Windows::Forms::TextBox());
			this->labelOpenPort = (gcnew System::Windows::Forms::Label());
			this->numericUpDownOpenPort = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->textBoxComment = (gcnew System::Windows::Forms::TextBox());
			this->labelComment = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->numericUpDownPort = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownMaxConnection = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelMaxConnection = (gcnew System::Windows::Forms::Label());
			this->groupBoxStartMode = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxServerName = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxConnection = (gcnew System::Windows::Forms::GroupBox());
			this->labelAccessPort = (gcnew System::Windows::Forms::Label());
			this->labelIP = (gcnew System::Windows::Forms::Label());
			this->groupBoxProfile = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxWelcome = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxWelcome = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownOpenPort))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownPort))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownMaxConnection))->BeginInit();
			this->groupBoxStartMode->SuspendLayout();
			this->groupBoxConnection->SuspendLayout();
			this->groupBoxProfile->SuspendLayout();
			this->groupBoxWelcome->SuspendLayout();
			this->SuspendLayout();
			// 
			// radioButtonServer
			// 
			this->radioButtonServer->AutoSize = true;
			this->radioButtonServer->Location = System::Drawing::Point(8, 18);
			this->radioButtonServer->Name = L"radioButtonServer";
			this->radioButtonServer->Size = System::Drawing::Size(56, 16);
			this->radioButtonServer->TabIndex = 1;
			this->radioButtonServer->Text = L"Server";
			this->radioButtonServer->UseVisualStyleBackColor = true;
			this->radioButtonServer->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::radioButtonServer_CheckedChanged);
			// 
			// radioButtonHost
			// 
			this->radioButtonHost->AutoSize = true;
			this->radioButtonHost->Location = System::Drawing::Point(70, 18);
			this->radioButtonHost->Name = L"radioButtonHost";
			this->radioButtonHost->Size = System::Drawing::Size(47, 16);
			this->radioButtonHost->TabIndex = 1;
			this->radioButtonHost->Text = L"Host";
			this->radioButtonHost->UseVisualStyleBackColor = true;
			this->radioButtonHost->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::radioButtonHost_CheckedChanged);
			// 
			// radioButtonClient
			// 
			this->radioButtonClient->AutoSize = true;
			this->radioButtonClient->Location = System::Drawing::Point(123, 18);
			this->radioButtonClient->Name = L"radioButtonClient";
			this->radioButtonClient->Size = System::Drawing::Size(53, 16);
			this->radioButtonClient->TabIndex = 1;
			this->radioButtonClient->Text = L"Client";
			this->radioButtonClient->UseVisualStyleBackColor = true;
			this->radioButtonClient->CheckedChanged += gcnew System::EventHandler(this, &StartupForm::radioButtonClient_CheckedChanged);
			// 
			// labelServerName
			// 
			this->labelServerName->AutoSize = true;
			this->labelServerName->Location = System::Drawing::Point(6, 41);
			this->labelServerName->Name = L"labelServerName";
			this->labelServerName->Size = System::Drawing::Size(49, 12);
			this->labelServerName->TabIndex = 0;
			this->labelServerName->Text = L"サーバ名:";
			// 
			// textBoxIP
			// 
			this->textBoxIP->Location = System::Drawing::Point(70, 18);
			this->textBoxIP->Name = L"textBoxIP";
			this->textBoxIP->Size = System::Drawing::Size(116, 19);
			this->textBoxIP->TabIndex = 2;
			// 
			// labelOpenPort
			// 
			this->labelOpenPort->AutoSize = true;
			this->labelOpenPort->Location = System::Drawing::Point(7, 65);
			this->labelOpenPort->Name = L"labelOpenPort";
			this->labelOpenPort->Size = System::Drawing::Size(59, 12);
			this->labelOpenPort->TabIndex = 0;
			this->labelOpenPort->Text = L"待受ポート:";
			// 
			// numericUpDownOpenPort
			// 
			this->numericUpDownOpenPort->Location = System::Drawing::Point(133, 63);
			this->numericUpDownOpenPort->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65535, 0, 0, 0});
			this->numericUpDownOpenPort->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1024, 0, 0, 0});
			this->numericUpDownOpenPort->Name = L"numericUpDownOpenPort";
			this->numericUpDownOpenPort->Size = System::Drawing::Size(53, 19);
			this->numericUpDownOpenPort->TabIndex = 4;
			this->numericUpDownOpenPort->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {7500, 0, 0, 0});
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(274, 205);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(58, 24);
			this->buttonOK->TabIndex = 6;
			this->buttonOK->Text = L"起動";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &StartupForm::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(338, 205);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(57, 24);
			this->buttonCancel->TabIndex = 7;
			this->buttonCancel->Text = L"閉じる";
			this->buttonCancel->UseVisualStyleBackColor = true;
			this->buttonCancel->Click += gcnew System::EventHandler(this, &StartupForm::buttonCancel_Click);
			// 
			// textBoxComment
			// 
			this->textBoxComment->Location = System::Drawing::Point(80, 43);
			this->textBoxComment->Name = L"textBoxComment";
			this->textBoxComment->Size = System::Drawing::Size(94, 19);
			this->textBoxComment->TabIndex = 2;
			// 
			// labelComment
			// 
			this->labelComment->AutoSize = true;
			this->labelComment->Location = System::Drawing::Point(7, 46);
			this->labelComment->Name = L"labelComment";
			this->labelComment->Size = System::Drawing::Size(40, 12);
			this->labelComment->TabIndex = 4;
			this->labelComment->Text = L"コメント:";
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(80, 18);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(94, 19);
			this->textBoxName->TabIndex = 1;
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Location = System::Drawing::Point(6, 21);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(61, 12);
			this->labelName->TabIndex = 0;
			this->labelName->Text = L"ニックネーム:";
			// 
			// numericUpDownPort
			// 
			this->numericUpDownPort->Location = System::Drawing::Point(133, 40);
			this->numericUpDownPort->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65535, 0, 0, 0});
			this->numericUpDownPort->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1024, 0, 0, 0});
			this->numericUpDownPort->Name = L"numericUpDownPort";
			this->numericUpDownPort->Size = System::Drawing::Size(53, 19);
			this->numericUpDownPort->TabIndex = 4;
			this->numericUpDownPort->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {7500, 0, 0, 0});
			// 
			// numericUpDownMaxConnection
			// 
			this->numericUpDownMaxConnection->Location = System::Drawing::Point(146, 88);
			this->numericUpDownMaxConnection->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDownMaxConnection->Name = L"numericUpDownMaxConnection";
			this->numericUpDownMaxConnection->Size = System::Drawing::Size(40, 19);
			this->numericUpDownMaxConnection->TabIndex = 3;
			this->numericUpDownMaxConnection->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// labelMaxConnection
			// 
			this->labelMaxConnection->AutoSize = true;
			this->labelMaxConnection->Location = System::Drawing::Point(7, 90);
			this->labelMaxConnection->Name = L"labelMaxConnection";
			this->labelMaxConnection->Size = System::Drawing::Size(79, 12);
			this->labelMaxConnection->TabIndex = 0;
			this->labelMaxConnection->Text = L"最大接続者数:";
			// 
			// groupBoxStartMode
			// 
			this->groupBoxStartMode->Controls->Add(this->textBoxServerName);
			this->groupBoxStartMode->Controls->Add(this->radioButtonServer);
			this->groupBoxStartMode->Controls->Add(this->labelOpenPort);
			this->groupBoxStartMode->Controls->Add(this->labelServerName);
			this->groupBoxStartMode->Controls->Add(this->labelMaxConnection);
			this->groupBoxStartMode->Controls->Add(this->numericUpDownMaxConnection);
			this->groupBoxStartMode->Controls->Add(this->numericUpDownOpenPort);
			this->groupBoxStartMode->Controls->Add(this->radioButtonHost);
			this->groupBoxStartMode->Controls->Add(this->radioButtonClient);
			this->groupBoxStartMode->Location = System::Drawing::Point(201, 12);
			this->groupBoxStartMode->Name = L"groupBoxStartMode";
			this->groupBoxStartMode->Size = System::Drawing::Size(194, 115);
			this->groupBoxStartMode->TabIndex = 8;
			this->groupBoxStartMode->TabStop = false;
			this->groupBoxStartMode->Text = L"起動モード";
			// 
			// textBoxServerName
			// 
			this->textBoxServerName->Location = System::Drawing::Point(70, 38);
			this->textBoxServerName->Name = L"textBoxServerName";
			this->textBoxServerName->Size = System::Drawing::Size(116, 19);
			this->textBoxServerName->TabIndex = 5;
			// 
			// groupBoxConnection
			// 
			this->groupBoxConnection->Controls->Add(this->labelAccessPort);
			this->groupBoxConnection->Controls->Add(this->labelIP);
			this->groupBoxConnection->Controls->Add(this->textBoxIP);
			this->groupBoxConnection->Controls->Add(this->numericUpDownPort);
			this->groupBoxConnection->Location = System::Drawing::Point(201, 133);
			this->groupBoxConnection->Name = L"groupBoxConnection";
			this->groupBoxConnection->Size = System::Drawing::Size(194, 66);
			this->groupBoxConnection->TabIndex = 9;
			this->groupBoxConnection->TabStop = false;
			this->groupBoxConnection->Text = L"接続先";
			// 
			// labelAccessPort
			// 
			this->labelAccessPort->AutoSize = true;
			this->labelAccessPort->Location = System::Drawing::Point(7, 42);
			this->labelAccessPort->Name = L"labelAccessPort";
			this->labelAccessPort->Size = System::Drawing::Size(71, 12);
			this->labelAccessPort->TabIndex = 5;
			this->labelAccessPort->Text = L"接続先ポート:";
			// 
			// labelIP
			// 
			this->labelIP->AutoSize = true;
			this->labelIP->Location = System::Drawing::Point(7, 21);
			this->labelIP->Name = L"labelIP";
			this->labelIP->Size = System::Drawing::Size(43, 12);
			this->labelIP->TabIndex = 3;
			this->labelIP->Text = L"アドレス:";
			// 
			// groupBoxProfile
			// 
			this->groupBoxProfile->Controls->Add(this->labelComment);
			this->groupBoxProfile->Controls->Add(this->textBoxComment);
			this->groupBoxProfile->Controls->Add(this->textBoxName);
			this->groupBoxProfile->Controls->Add(this->labelName);
			this->groupBoxProfile->Location = System::Drawing::Point(12, 12);
			this->groupBoxProfile->Name = L"groupBoxProfile";
			this->groupBoxProfile->Size = System::Drawing::Size(183, 67);
			this->groupBoxProfile->TabIndex = 10;
			this->groupBoxProfile->TabStop = false;
			this->groupBoxProfile->Text = L"プロフィール";
			// 
			// groupBoxWelcome
			// 
			this->groupBoxWelcome->Controls->Add(this->textBoxWelcome);
			this->groupBoxWelcome->Location = System::Drawing::Point(12, 85);
			this->groupBoxWelcome->Name = L"groupBoxWelcome";
			this->groupBoxWelcome->Size = System::Drawing::Size(183, 113);
			this->groupBoxWelcome->TabIndex = 11;
			this->groupBoxWelcome->TabStop = false;
			this->groupBoxWelcome->Text = L"サーバメッセージ";
			// 
			// textBoxWelcome
			// 
			this->textBoxWelcome->Location = System::Drawing::Point(8, 19);
			this->textBoxWelcome->MaxLength = 254;
			this->textBoxWelcome->Name = L"textBoxWelcome";
			this->textBoxWelcome->Size = System::Drawing::Size(167, 86);
			this->textBoxWelcome->TabIndex = 0;
			this->textBoxWelcome->Text = L"";
			this->textBoxWelcome->WordWrap = false;
			// 
			// StartupForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(407, 241);
			this->ControlBox = false;
			this->Controls->Add(this->groupBoxWelcome);
			this->Controls->Add(this->groupBoxProfile);
			this->Controls->Add(this->groupBoxConnection);
			this->Controls->Add(this->groupBoxStartMode);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonCancel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"StartupForm";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"スタートアップ";
			this->Load += gcnew System::EventHandler(this, &StartupForm::StartupForm_Load);
			this->Shown += gcnew System::EventHandler(this, &StartupForm::StartupForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownOpenPort))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownPort))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDownMaxConnection))->EndInit();
			this->groupBoxStartMode->ResumeLayout(false);
			this->groupBoxStartMode->PerformLayout();
			this->groupBoxConnection->ResumeLayout(false);
			this->groupBoxConnection->PerformLayout();
			this->groupBoxProfile->ResumeLayout(false);
			this->groupBoxProfile->PerformLayout();
			this->groupBoxWelcome->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Void StartupForm_Load(System::Object^  sender, System::EventArgs^  e) {
			textBoxServerName->MaxLength      = MAX_NAME;
			textBoxIP->MaxLength              = MAX_ARRAY;
			textBoxName->MaxLength            = MAX_NAME;
			textBoxComment->MaxLength         = MAX_NAME;

			switch(MTOPTION.CONNECTION_TYPE){
			case CT_SERVER:
			default:
				radioButtonServer->Checked = true;

				numericUpDownPort->Enabled = false;
				break;
			case CT_HOST:
				radioButtonHost->Checked = true;

				break;
			case CT_CLIENT:
				radioButtonClient->Checked = true;

				numericUpDownOpenPort->Enabled = false;
				break;
			}

			textBoxServerName->Text = gcnew String(MTOPTION.SERVER_NAME);
			textBoxIP->Text = gcnew String(MTOPTION.CONNECTION_IP);
			

			numericUpDownOpenPort->Value = MTOPTION.OPEN_PORT;

			textBoxName->Text = gcnew String(MTOPTION.NAME);
			numericUpDownPort->Value = MTOPTION.PORT;
			numericUpDownMaxConnection->Value = MTOPTION.MAX_CONNECTION;

			textBoxComment->Text = gcnew String(MTOPTION.COMMENT);
			textBoxWelcome->Text = gcnew String(MTOPTION.WELCOME);
		}

		System::Void StartupForm_Shown(System::Object^  sender, System::EventArgs^  e) {
			buttonOK->Focus();
		}

		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			IntPtr mp;
			TCHAR p1[MAX_ARRAY];
			TCHAR *p2;

			if(radioButtonServer->Checked){
				MTOPTION.CONNECTION_TYPE = CT_SERVER;

				// サーバ名チェック
				if(textBoxServerName->Text->Length == 0){
					MessageBox::Show("サーバ名を入力してください。\n\nSERVERモードで起動するには、\nサーバ名を入力する必要があります。", "SERVERモードエラー", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					return;
				}
				mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxServerName->Text);
				_tcscpy_s(p1, static_cast<PTCHAR>(mp.ToPointer()));
				Runtime::InteropServices::Marshal::FreeHGlobal(mp);
				p2 = _tcschr(p1, _T(','));
				if (p2 != NULL){
					MessageBox::Show("サーバ名に使用できない文字(,)があります。\nサーバ名を確認してください。", "SERVERモードエラー", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					return;
				}
			}
			else if(radioButtonHost->Checked){
				MTOPTION.CONNECTION_TYPE = CT_HOST;
			}
			else if(radioButtonClient->Checked){
				MTOPTION.CONNECTION_TYPE = CT_CLIENT;
			}
			else{
				MTOPTION.CONNECTION_TYPE = CT_FREE;
			}


			// サーバ名
			mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxServerName->Text);
			_tcscpy_s(MTOPTION.SERVER_NAME, static_cast<PTCHAR>(mp.ToPointer()));
			Runtime::InteropServices::Marshal::FreeHGlobal(mp);

			// IPチェック
			if(MTOPTION.CONNECTION_TYPE == CT_HOST || MTOPTION.CONNECTION_TYPE == CT_CLIENT) {
				if(textBoxIP->Text->Length == 0){
					MessageBox::Show("接続先アドレスを入力してください。\n\nHOST, CLIENTモードで起動するには、\n接続先のアドレスを入力する必要があります。", "HOST, CLIENTモードエラー", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					return;
				}
				mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxIP->Text);
				_tcscpy_s(p1, static_cast<PTCHAR>(mp.ToPointer()));
				p2 = _tcschr(p1, _T(','));
				if (p2 != NULL){
					MessageBox::Show("接続先アドレスに使用できない文字(,)があります。\n接続先アドレスを確認してください。", "HOST, CLIENTモードエラー", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					return;
				}
			}

			mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxIP->Text);
			_tcscpy_s(MTOPTION.CONNECTION_IP, static_cast<PTCHAR>(mp.ToPointer()));
			Runtime::InteropServices::Marshal::FreeHGlobal(mp);

			// 名前チェック
			if(textBoxName->Text->Length == 0){
				textBoxName->Text = gcnew String(MTOPTION.NAME);

				if(textBoxName->Text->Length == 0){
					textBoxName->Text = gcnew String("名無しさん");
				}
			}

			mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxName->Text);
			_tcscpy_s(MTOPTION.NAME, static_cast<PTCHAR>(mp.ToPointer()));
			Runtime::InteropServices::Marshal::FreeHGlobal(mp);

			MTOPTION.OPEN_PORT      = (UINT)numericUpDownOpenPort->Value;
			MTOPTION.PORT           = (UINT)numericUpDownPort->Value;
			MTOPTION.MAX_CONNECTION = (UINT)numericUpDownMaxConnection->Value;

			mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxComment->Text);
			_tcscpy_s(MTOPTION.COMMENT, static_cast<PTCHAR>(mp.ToPointer()));
			Runtime::InteropServices::Marshal::FreeHGlobal(mp);

			mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(textBoxWelcome->Text);
			_tcscpy_s(MTOPTION.WELCOME, static_cast<PTCHAR>(mp.ToPointer()));
			Runtime::InteropServices::Marshal::FreeHGlobal(mp);

			this->Close();
		}

		System::Void buttonCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			MTOPTION.CONNECTION_TYPE = CT_FREE;
			
			this->Close();
		}

		System::Void radioButtonServer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			numericUpDownOpenPort->Enabled = true;
			numericUpDownPort->Enabled     = false;
			labelOpenPort->Enabled         = true;
			labelServerName->Enabled       = true;
			textBoxServerName->Enabled     = true;
			textBoxIP->Enabled             = false;
			groupBoxConnection->Enabled    = false;
			groupBoxWelcome->Enabled       = true;

			buttonOK->Enabled = true;
		}

		System::Void radioButtonHost_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			numericUpDownOpenPort->Enabled = true;
			numericUpDownPort->Enabled     = true;
			labelOpenPort->Enabled         = true;
			labelServerName->Enabled       = false;
			textBoxServerName->Enabled     = false;
			textBoxIP->Enabled             = true;
			groupBoxConnection->Enabled    = true;
			groupBoxWelcome->Enabled       = false;
		}

		System::Void radioButtonClient_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			numericUpDownOpenPort->Enabled = false;
			numericUpDownPort->Enabled     = true;
			labelOpenPort->Enabled         = false;
			labelServerName->Enabled       = false;
			textBoxServerName->Enabled     = false;
			textBoxIP->Enabled             = true;
			groupBoxConnection->Enabled    = true;
			groupBoxWelcome->Enabled       = false;
		}
		System::Void buttonEnd_Click(System::Object^  sender, System::EventArgs^  e) {
			 exit(0);
		}
	};
}
