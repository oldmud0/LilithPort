#include "stdafx.h"
#include "MainForm.h"

using namespace LilithPort;

void MainForm::Begin()
{
	ServerName = gcnew String(MTOPTION.SERVER_NAME);
	ConnectIP = gcnew String(MTOPTION.CONNECTION_IP);
	
	ServerMode = SM_NORMAL;
	MTINFO.VERSION_CHECKED = false;

	MemberInfo^ me = gcnew MemberInfo;
	me->IP_EP    = gcnew IPEndPoint(0, 0);
	me->ID       = 0;
	me->NAME     = gcnew String(MTOPTION.NAME);
	me->COMMENT  = gcnew String(MTOPTION.COMMENT);
	me->TYPE     = MTOPTION.CONNECTION_TYPE;
	me->STATE    = MS_FREE;
	me->RESPONSE = timeGetTime();

	if(MTOPTION.CONNECTION_TYPE == CT_SERVER && ServerName->Length > 0){

		MemberInfoBackUp^ bk = gcnew MemberInfoBackUp;
		bk->IP_EP    = gcnew IPEndPoint(0, 0);
		bk->ID       = 0;

		// 特殊サーバモード判定
		if(ServerName[0] == '#'){
			ServerMode = SM_NORA;
			ListView = LV_BLIND;
			me->NAME = gcnew String(L"◆");
			me->COMMENT = String::Empty;

			MemberList->Add(me);
			MemberListBackUp->Add(bk);
			listBoxMember->Items->Add(gcnew String(L"Server host"));
		}
		else{
			MemberList->Add(me);
			MemberListBackUp->Add(bk);
			listBoxMember->Items->Add(me->NAME);

			if(ServerName[0] == '+'){
				ServerMode = SM_MIX;
			}
			else if(ServerName[0] == '@'){
				ServerMode = SM_MATCH;
			}
		}
	}
	else{
		MemberList->Add(me);
		listBoxMember->Items->Add(me->NAME);
	}

	try{
		// 回線設定
        //Here is where you can force in IPv6 support, however it's not recommended since then you can ONLY connect to IPv6 addresses.
		if(MTOPTION.CONNECTION_TYPE == CT_SERVER || MTOPTION.CONNECTION_TYPE == CT_HOST){
			UDP = gcnew UdpClient(MTOPTION.OPEN_PORT);
		}
		else if(MTOPTION.CONNECTION_TYPE == CT_CLIENT){
			UDP = gcnew UdpClient();
		}
	}
	catch(SocketException^ e){
		UDP = nullptr;

		if(e->ErrorCode == WSAEADDRINUSE){
			WriteMessage(L"ERROR: This port is already in use by another program.\n", ErrorMessageColor);
		}
		else{
			WriteMessage(String::Format(L"ERROR: UDP initialiation failed. ({0})\n", e->ErrorCode), ErrorMessageColor);
			if(MTINFO.DEBUG){
				WriteMessage(e->ToString() + L"\n", DebugMessageColor);
			}
		}
	}

	// ネットに接続
	if(UDP != nullptr){

		// 設定を保存
		SaveMTOption();

		if(MTOPTION.AUTO_REST && MemberList[0]->STATE == MS_FREE){
			AutoRestThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::RunAutoRest));
			AutoRestThread->Start();
		}

		if(MTOPTION.CONNECTION_TYPE == CT_SERVER){

			// 鯖受信開始
			UDP->BeginReceive(gcnew AsyncCallback(ReceivePackets), this);

			// ソナー軌道
			Ranging = true;
			SonarThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::RunSonar));
			SonarThread->Start();

			this->Text += String::Format(L" ({0}) (Server Port: {1})", ServerName, MTOPTION.OPEN_PORT);
			WriteTime(0, SystemMessageColor);
			WriteMessage(L"Server initialization complete.\n[MOTD]-------------------\n", SystemMessageColor);

			// Welcomeメッセージの表示
			int len = _tcslen(MTOPTION.WELCOME);
			for(int i = 0; i < len; i++){
				if(MTOPTION.WELCOME[i] == _T('\t')){
					MTOPTION.WELCOME[i] = _T('\n');
				}
			}
			richTextBoxLog->SelectionFont = gcnew Drawing::Font(richTextBoxLog->Font->FontFamily, richTextBoxLog->Font->Size + 2);
			richTextBoxLog->SelectionColor = TalkMessageColor;
			richTextBoxLog->SelectionBackColor = NoticeBackColor;
			richTextBoxLog->AppendText(gcnew String(MTOPTION.WELCOME)+"\n");

			WriteMessage(L"-------------------------------\n", SystemMessageColor);
			
			// IPアドレスを取得して表示
			if(MTOPTION.GET_IP_ENABLE){
				GetIPAddress();
			}

		}
		else{
			// クライアント
            IPAddress^ address = IPAddress::None;
			int port = MTOPTION.PORT;
			array<String^>^ host = ConnectIP->Split(gcnew array<wchar_t>{':'}, 2, StringSplitOptions::RemoveEmptyEntries);

			// ポート":"指定
			if(host->Length > 1){
				try{
					port = Convert::ToInt32(host[1]);
				}
				catch(Exception^){
					port = MTOPTION.PORT;
				}
			}

			try{
				// MTSPアドレス接続
				if(host[0]->Length == 5){
					try{
						if(MTINFO.DEBUG){
							WriteMessage(L"Converting MTSP address...\n", DebugMessageColor);
						}
                        address = gcnew IPAddress(MTDecryptionIP(host[0]));
					}
					catch(Exception^ e){
						if(MTINFO.DEBUG){
							WriteMessage(L"MTSP address conversion failed!\n", ErrorMessageColor);
							WriteMessage(e->ToString() + L"\n", DebugMessageColor);
						}
					}
				}

				// 変換アドレス接続(ASCII)
                if (address->Equals(IPAddress::None)){
					try{
						if(MTINFO.DEBUG){
							WriteMessage(L"Converting ASCII address...\n", DebugMessageColor);
						}
                        address = gcnew IPAddress(DecryptionIP(host[0], true));
					}
					catch(Exception^ e){
						if(MTINFO.DEBUG){
							WriteMessage(L"ASCII address conversion failed!\n", ErrorMessageColor);
							WriteMessage(e->ToString() + L"\n", DebugMessageColor);
						}
					}
				}

				// DNS接続
                if (address->Equals(IPAddress::None)){
					try{
						if(MTINFO.DEBUG){
							WriteMessage(L"Resolving DNS...\n", DebugMessageColor);
						}
                        IPAddress^ addr;
                        auto addrList = Dns::GetHostEntry(host[0])->AddressList; //screw it, I'm using auto

                        //Find the first IP address that is IPv4
                        for (int i = 0; i < addrList->Length; i++)
                            if (addrList[i]->AddressFamily == AddressFamily::InterNetwork)
                                addr = addrList[i];

                        if (MTINFO.DEBUG)
                            WriteMessage("Got DNS address " + addr->ToString() + L"\n", DebugMessageColor);
                        address = addr;
                        //address = BitConverter::ToInt64(addr->GetAddressBytes(), 0);
					}
					catch(Exception^ e){
						if(MTINFO.DEBUG){
							WriteMessage(L"DNS resolution failed!\n", ErrorMessageColor);
							WriteMessage(e->ToString() + L"\n", DebugMessageColor);
						}
                        address = IPAddress::None;
					}
				}

				// 変換アドレス接続(Unicode)
                if (address->Equals(IPAddress::None)){
					try{
						if(MTINFO.DEBUG){
							WriteMessage(L"Converting Unicode address...\n", DebugMessageColor);
						}
                        address = gcnew IPAddress(DecryptionIP(host[0], false));
					}
					catch(Exception^ e){
						if(MTINFO.DEBUG){
							WriteMessage(L"Unicode address conversion failed!\n", ErrorMessageColor);
							WriteMessage(e->ToString() + L"\n", DebugMessageColor);
						}
					}
				}

				// ローカル接続用
				/*
				if(address == 0){
					try{
						if((host[0]->StartsWith("192.168.", StringComparison::OrdinalIgnoreCase))) {
							address = IPAddress::Parse(host[0])->Address;
						}
					}
					catch(Exception^ e){
						if(MTINFO.DEBUG){
							WriteMessage(L"ローカル接続失敗\n", ErrorMessageColor);
							WriteMessage(e->ToString() + L"\n", DebugMessageColor);
						}
						address = 0;
					}
				}
				*/
				

				if(address->Equals(IPAddress::None)){
					WriteMessage(L"ERROR: Could not find destination address.\n", ErrorMessageColor);
					throw gcnew SocketException;
				}

				IPEndPoint^ ep = gcnew IPEndPoint(address, port);
				if(MTINFO.DEBUG){
					WriteMessage(String::Format(L"Connecting to {0}...\n", ep), DebugMessageColor);
				}
				
				PacketPacker^ pp = gcnew PacketPacker;
				array<BYTE>^ name = Encoding::Unicode->GetBytes(me->NAME);
				array<BYTE>^ cmnt = Encoding::Unicode->GetBytes(me->COMMENT);

				pp->Pack(MTOPTION.CONNECTION_TYPE == CT_CLIENT ? (BYTE)PH_REQ_CONNECTION : (BYTE)PH_REQ_CONNECTION_H);
				pp->Pack(TYMT_VERSION);
				pp->Pack((BYTE)name->Length);
				pp->Pack(name);
				pp->Pack((BYTE)cmnt->Length);
				pp->Pack(cmnt);

				// サーバに接続要求
				UDP->Send(pp->Packet, pp->Length, ep);

				// 返信待ち
				UDP->Client->ReceiveTimeout = TIME_OUT;
				array<BYTE>^ rcv = UDP->Receive(ep);
				UDP->Client->ReceiveTimeout = 0;

				PacketDivider^ pd = gcnew PacketDivider(rcv);

				// 接続OK
				if(pd->Divide() == PH_RES_CONNECTION){
					int len = pd->Divide();

					ServerName = Encoding::Unicode->GetString(pd->Divide(len));
					MemberList[0]->ID = BitConverter::ToUInt16(pd->Divide(2), 0);

					if(MemberList[0]->ID > MAX_ID){
						throw gcnew SocketException;
					}

					MemberInfo^ mi = gcnew MemberInfo;
					mi->IP_EP    = ep;
					mi->ID       = 0;
					mi->TYPE     = CT_SERVER;
					mi->NUM_VS   = 0;
					mi->RESPONSE = timeGetTime();

					// 名前
					len = pd->Divide();
					mi->NAME = Encoding::Unicode->GetString(pd->Divide(len));

					// コメント
					len = pd->Divide();
					mi->COMMENT = Encoding::Unicode->GetString(pd->Divide(len));

					// 状態
					mi->STATE = pd->Divide();

					MemberList->Add(mi);
					AddListView(mi);

					// バージョン確認
					UINT ServerVersion;
					try{
						// 1.03以上なら来る
						ServerVersion = pd->Divide();
						MTINFO.VERSION_CHECKED = true;
					}
					catch(Exception^){
						MTINFO.VERSION_CHECKED = false;
					}
					if(MTINFO.VERSION_CHECKED) {
						WriteMessage(String::Format(L"Server version: v{0}\n", ServerVersion), SystemMessageColor);
						if(LP_VERSION > ServerVersion){
							WriteMessage(L"WARNING: Your client is newer than the server. Some functions may be incompatible.\n", ErrorMessageColor);
						}
						else if(LP_VERSION < ServerVersion) {
							WriteMessage(L"WARNING: Your client is older than the server. Some functions may be incompatible.\n", ErrorMessageColor);
						}
					}
					else{
						WriteMessage(L"WARNING: You are connecting to an MTSP server or a very old LilithPort server. Some functions will be incompatible.\n", ErrorMessageColor);
					}

					// 蔵受信開始
					UDP->BeginReceive(gcnew AsyncCallback(ReceivePackets), this);


					if(MTOPTION.CONNECTION_TYPE == CT_HOST){
						this->Text += String::Format(L" ({0}) (Host Port: {1})", ServerName, MTOPTION.OPEN_PORT);
					}
					else{
						this->Text += String::Format(L" ({0}) (Client)", ServerName);
					}
					WriteMessage(String::Format(L"Connected to {0}. (ID = {1})\n", ServerName, me->ID), SystemMessageColor);

					if(ServerName->Length > 0){
						if(ServerName[0] == '+'){
							ServerMode = SM_MIX;
							WriteMessage(L"Server is in mixed mode.\n", SystemMessageColor);
						}
						if(ServerName[0] == '@'){
							ServerMode = SM_MATCH;
							WriteMessage(L"Chat is disabled on this server.\n", SystemMessageColor);
						}
						else if(ServerName[0] == '#'){
							ServerMode = SM_NORA;
							WriteMessage(L"Whoa! A Nora server!\n", SystemMessageColor); //fixme: hard translation (野良サーバ)

							ListView = LV_BLIND;
							listBoxMember->Items[0] = gcnew String(L"Open Match"); //fixme: hard translation (野試合会場)
						}
					}

					// メンバーリストを要求
					pp->Clear();
					pp->Pack(PH_REQ_LIST);
					pp->Pack(0);
					pp->Pack(0);
					UDP->Send(pp->Packet, pp->Length, ep);

					// ソナー起動
					Ranging = true;
					SonarThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::RunSonar));
					SonarThread->Start();
				}
				else{
					throw gcnew SocketException;
				}
			}
			catch(SocketException^ e){
				Leave(false);

				if(e->ErrorCode == 0){
					if(me->ID == 0xFFFF){
						WriteMessage(String::Format(L"ERROR: {0} is full!\n", ServerName), ErrorMessageColor);
					}
					else if(me->ID == 0xFFFE){
						WriteMessage(L"ERROR: Program version is different.\n", ErrorMessageColor);
					}
					else if(me->ID > MAX_ID){
						WriteMessage(String::Format(L"ERROR: {0} could not issue any more player IDs.\n", ServerName), ErrorMessageColor);
					}
                    else if (!address->Equals(IPAddress::None)){
						WriteMessage(L"ERROR: Could not connect to the server.\nThe connection may be busy.\n", ErrorMessageColor);
					}
				}
				else{
					if(e->ErrorCode == WSAECONNRESET){
						WriteMessage(L"ERROR: The connection was reset. \n", ErrorMessageColor);
					}
					else if(e->ErrorCode == WSAETIMEDOUT){
						WriteMessage(L"ERROR: The connection timed out.\nThis could be due to many reasons: the server is not running, or the address may be incorrect.\n", ErrorMessageColor);
					}
					else if(e->ErrorCode != WSAHOST_NOT_FOUND){
						WriteMessage(String::Format(L"Unknown socket error: {0}\n", e->ErrorCode), ErrorMessageColor);
					}
					if(MTINFO.DEBUG){
						WriteMessage(e->ToString() + L"\n", DebugMessageColor);
					}
				}
			}
		}
	}
	else if(MTOPTION.CONNECTION_TYPE != CT_FREE){
		Leave(false);
	}
	else{
		this->Text += "  [Free Play]";
	}
}

void MainForm::PacketSendAllMember(array<BYTE>^% datagram, UINT received_id)
{
	Monitor::Enter(MemberList);
	try{
		for(int i = 1; i < MemberList->Count; i++){
			if(received_id != MemberList[i]->ID){
				UDP->BeginSend(datagram, datagram->Length, MemberList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
			}
		}
	}
	finally{
		Monitor::Exit(MemberList);
	}
}

void MainForm::SendPackets(IAsyncResult^ asyncResult)
{
	UdpClient^ udp = (UdpClient^)asyncResult->AsyncState;

	try{
		udp->EndSend(asyncResult);
	}
	catch(ObjectDisposedException^){
	}
}

void MainForm::ReceivePackets(IAsyncResult^ asyncResult)
{
	int i;
	UINT16 id;
	array<BYTE> ^send;

	MainForm^ form = safe_cast<MainForm^>(asyncResult->AsyncState);
	IPEndPoint^ ep = gcnew IPEndPoint(IPAddress::Any, 0);

	try{
		array<BYTE>^ rcv = UDP->EndReceive(asyncResult, ep);
		UDP->BeginReceive(gcnew AsyncCallback(ReceivePackets), form);

		if(rcv->Length > MAX_PACKET){
			if(MTINFO.DEBUG){
				form->WriteMessage(String::Format(L"Got very large packet > {0} from {1}\n", rcv[0], ep->ToString()), DebugMessageColor);
			}
			return;
		}

		switch(rcv[0]){
		case PH_PING:
			rcv[0] = PH_PONG;
			UDP->Send(rcv, rcv->Length, ep);
			break;

		case PH_PONG:
			if(rcv->Length == 1 && Ping > 0){
				form->WriteMessage(String::Format(L"Ping: {0}ms\n", timeGetTime() - Ping), SystemMessageColor);
				Ping = 0;
			}
			break;

		case PH_REQ_CONNECTION:
		case PH_REQ_CONNECTION_H:
			// 鯖じゃないのに接続要求が来た
			if(MTOPTION.CONNECTION_TYPE != CT_SERVER){
				break;
			}

			Monitor::Enter(MemberList);
			try{
				array<BYTE>^ a_id;
				array<BYTE>^ saba = Encoding::Unicode->GetBytes(ServerName);
				array<BYTE>^ name = Encoding::Unicode->GetBytes(MemberList[0]->NAME);
				array<BYTE>^ cmnt = Encoding::Unicode->GetBytes(MemberList[0]->COMMENT);

				MemberInfo^ mi;
				PacketPacker^  pp = gcnew PacketPacker;
				PacketDivider^ pd = gcnew PacketDivider(rcv);

				i = pd->Divide() == PH_REQ_CONNECTION ? CT_CLIENT : CT_HOST;

				// サーバ名
				pp->Pack(PH_RES_CONNECTION);
				pp->Pack((BYTE)saba->Length);
				pp->Pack(saba);

				// IDの発行
				if(MemberList->Count > (int)MTOPTION.MAX_CONNECTION){
					// 満室
					a_id = gcnew array<BYTE>{ 0xFF, 0xFF };
				}
				else if(pd->Divide() != TYMT_VERSION){
					// バージョン違い
					a_id = gcnew array<BYTE>{ 0xFE, 0xFF };
				}
				else{
					a_id = BitConverter::GetBytes(++IDCounter);

					if(IDCounter <= MAX_ID){
						if(IDCounter == MAX_ID){
							form->WriteMessage(L"ERROR: issued ID is above the max ID!\n", ErrorMessageColor);
						}

						// メンバー登録
						mi = gcnew MemberInfo;
						mi->IP_EP    = ep;
						mi->ID       = IDCounter;
						mi->TYPE     = i;
						mi->STATE    = MS_FREE;
						mi->NUM_VS   = 0;
						mi->RESPONSE = timeGetTime();

						// 名前
						i = pd->Divide();
						mi->NAME = Encoding::Unicode->GetString(pd->Divide(i));

						// コメント
						i = pd->Divide();
						mi->COMMENT = Encoding::Unicode->GetString(pd->Divide(i));

						if(ListView == LV_BLIND){
							mi->NAME = gcnew String(L"◆");
							mi->COMMENT = String::Empty;
						}

						MemberList->Add(mi);
						form->AddListView(mi);

						// バックアップ
						MemberInfoBackUp^ mibk = gcnew MemberInfoBackUp;
						mibk->IP_EP = ep;
						mibk->ID    = IDCounter;
						MemberListBackUp->Add(mibk);
						

						form->WriteComment(mi->NAME, mi->TYPE, mi->COMMENT);

						if(MTINFO.DEBUG){
							form->WriteMessage(String::Format(L"Connect from {0}:{1}\n", ep->Address, ep->Port), DebugMessageColor);
						}
					}
					else if(IDCounter > MAX_ID){
						IDCounter = MAX_ID;
					}
				}

				// ID
				pp->Pack(a_id);

				// 鯖主のニックネーム
				pp->Pack((BYTE)name->Length);
				pp->Pack(name);

				// 鯖主のコメント
				pp->Pack((BYTE)cmnt->Length);
				pp->Pack(cmnt);

				// 状態
				pp->Pack((BYTE)MemberList[0]->STATE);

				// バージョン情報送信
				pp->Pack((BYTE)LP_VERSION);

				// 登録完了
				UDP->Send(pp->Packet, pp->Length, ep);

				if(mi != nullptr){
					pp->Clear();

					// 全員に入室を通知
					name = Encoding::Unicode->GetBytes(mi->NAME);
					cmnt = Encoding::Unicode->GetBytes(mi->COMMENT);
					array<BYTE>^ address = ep->Address->GetAddressBytes();
					array<BYTE>^ port = BitConverter::GetBytes((UINT16)ep->Port);

					a_id[1] |= mi->TYPE << 6;

					pp->Pack(PH_NEW_MEMBER);
					pp->Pack(a_id);
					pp->Pack((BYTE)name->Length);
					pp->Pack(name);
					pp->Pack((BYTE)cmnt->Length);
					pp->Pack(cmnt);
					pp->Pack(MS_FREE);
					pp->Pack(address);
					pp->Pack(port);

					// 簡易暗号
					Monitor::Enter(ServerName);
					try{
						CipherRand(ServerName->GetHashCode());

						for(i = 1; i < pp->Length; i++){
							pp->Packet[i] ^= CipherRand();
						}
					}
					finally{
						Monitor::Exit(ServerName);
					}

					for(i = 1; i < MemberList->Count - 1; i++){
						UDP->BeginSend(pp->Packet, pp->Length, MemberList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
					}
				}
			}
			finally{
				Monitor::Exit(MemberList);
			}

			// Welcomeメッセージ
			for(UINT j = 0; j < _tcslen(MTOPTION.WELCOME); j++){
				if(MTOPTION.WELCOME[j] == _T('\t')){
					MTOPTION.WELCOME[j] = _T('\n');
				}
			}
			i = _tcslen(MTOPTION.WELCOME)*2;


			if(i > 0){
				Thread::Sleep(50);

				PacketPacker^ pp = gcnew PacketPacker;

				pp->Pack(PH_NOTICE);
				pp->Pack((BYTE)i);
				pp->Pack(Encoding::Unicode->GetBytes(gcnew String(MTOPTION.WELCOME)));
				UDP->Send(pp->Packet, pp->Length, ep);
			}
			break;

		case PH_MESSAGE:
			if(ServerMode >= SM_MATCH){
				break;
			}

			if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
				form->TalkMessage(BitConverter::ToUInt16(rcv, 1), rcv);
			}
			else{
				// 受信ONLY
				form->TalkMessage(0xFFFF, rcv);
			}
			break;

		case PH_NOTICE:
			if(UDP != nullptr){
				form->WriteMessage(L"[Notice]-------------------\n", SystemMessageColor);
				form->WriteNotice(Encoding::Unicode->GetString(rcv, 2, (rcv->Length)-2));
				form->WriteMessage(L"-------------------------------\n", SystemMessageColor);
			}
			break;

		case PH_REQ_LIST:
			if(MTOPTION.CONNECTION_TYPE != CT_SERVER){
				return;
			}
			else{
				id = BitConverter::ToUInt16(rcv, 1);
				array<BYTE> ^a_id, ^name, ^cmnt, ^address, ^port;
				PacketPacker^ pp = gcnew PacketPacker;

				Monitor::Enter(MemberList);
				try{
					for(i = 1; i < MemberList->Count; i++){
						// id == 0で全員分
						if(id == 0 || id == MemberList[i]->ID){
							a_id = BitConverter::GetBytes((UINT16)(MemberList[i]->ID | MemberList[i]->TYPE << 14));
							name = Encoding::Unicode->GetBytes(MemberList[i]->NAME);
							cmnt = Encoding::Unicode->GetBytes(MemberList[i]->COMMENT);
							address = MemberList[i]->IP_EP->Address->GetAddressBytes();
							port = BitConverter::GetBytes((UINT16)MemberList[i]->IP_EP->Port);

							pp->Clear();
							pp->Pack(PH_RES_LIST);
							pp->Pack(a_id);
							pp->Pack((BYTE)name->Length);
							pp->Pack(name);
							pp->Pack((BYTE)cmnt->Length);
							pp->Pack(cmnt);
							pp->Pack((BYTE)MemberList[i]->STATE);
							pp->Pack(address);
							pp->Pack(port);

							// 簡易暗号
							Monitor::Enter(ServerName);
							try{
								CipherRand(ServerName->GetHashCode());

								for(int j = 1; j < pp->Length; j++){
									pp->Packet[j] ^= CipherRand();
								}
							}
							finally{
								Monitor::Exit(ServerName);
							}

							UDP->BeginSend(pp->Packet, pp->Length, ep, gcnew AsyncCallback(SendPackets), UDP);

							if(id > 0){
								break;
							}
						}
					}
					if(MTINFO.DEBUG){
						if(id == 0){
							form->WriteMessage(L"Replied to player list request.\n", DebugMessageColor);
						}
					}

					if(id > 0 && i >= MemberList->Count){
						// サーバでもクラでも見えない状態
						if(MTINFO.DEBUG){
							form->WriteMessage(String::Format(L"Unknown ({0}) search!\n", id), ErrorMessageColor);
						}

						// バックアップ検索
						if(id <= MemberListBackUp->Count){
							try{
								// Unknown通知
								array<BYTE>^ send = gcnew array<BYTE>(3){ PH_LOST, 0xFF, 0xFF };
								UDP->BeginSend(send, send->Length, MemberListBackUp[id]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
								form->WriteMessage(String::Format(L"Sent notice to Unknown ({0}).\n", id), SystemMessageColor);
							}
							catch(Exception^){
								if(MTINFO.DEBUG){
									form->WriteMessage(String::Format(L"Failed to send notice to Unknown ({0})!\n", id), ErrorMessageColor);
								}
							}
						}else{
							// バックアップリスト以上のID
							form->WriteMessage(String::Format(L"This ID is not present in the log. Shut down and restart the server after waiting a while.\n", id), ErrorMessageColor);
						}
					}
				}
				finally{
					Monitor::Exit(MemberList);
				}
			}
			break;

		case PH_RES_LIST:
		case PH_NEW_MEMBER:
			// 簡易復号
			Monitor::Enter(ServerName);
			try{
				CipherRand(ServerName->GetHashCode());

				for(i = 1; i < rcv->Length; i++){
					rcv[i] ^= CipherRand();
				}
			}
			finally{
				Monitor::Exit(ServerName);
			}

			id = BitConverter::ToUInt16(rcv, 1);

			if((id & 0x3FFF) != MemberList[0]->ID){
				int len;
				PacketDivider^ pd = gcnew PacketDivider(rcv);
				pd->Length = 3;

				Monitor::Enter(MemberList);
				try{
					MemberInfo^ mi = gcnew MemberInfo;
					mi->IP_EP  = gcnew IPEndPoint(0, 0);
					mi->ID     = id & 0x3FFF;
					mi->TYPE   = id >> 14;
					mi->NUM_VS = 0;

					// 名前
					len = pd->Divide();
					mi->NAME = Encoding::Unicode->GetString(pd->Divide(len));

					// コメント
					len = pd->Divide();
					mi->COMMENT = Encoding::Unicode->GetString(pd->Divide(len));

					// 状態
					mi->STATE = pd->Divide();

					// エンドポイント
					mi->IP_EP->Address = gcnew IPAddress(pd->Divide(4));
					mi->IP_EP->Port    = BitConverter::ToUInt16(pd->Divide(2), 0);

					MemberList->Add(mi);
					form->AddListView(mi);

					// 挨拶代わり
					UDP->Send(gcnew array<BYTE>{PH_PING}, 1, mi->IP_EP);

					if(rcv[0] == PH_NEW_MEMBER){
						form->WriteComment(mi->NAME, mi->TYPE, mi->COMMENT);
					}
				}
				finally{
					Monitor::Exit(MemberList);
				}
			}
			break;

		case PH_QUIT:
		case PH_LOST:
			id = BitConverter::ToUInt16(rcv, 1);

			Monitor::Enter(MemberList);
			try{
				if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
					int member = 0;
					// 全員に通達
					for(i = 1; i < MemberList->Count; i++){
						if(id != MemberList[i]->ID){
							UDP->BeginSend(rcv, rcv->Length, MemberList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
						}
						else{
							member = i;
						}
					}

					if(member > 0){
						if(ListView != LV_BLIND){
							form->WriteTime(0, SystemMessageColor);
							form->WriteMessage(MemberList[member]->NAME + L" has left.\n", SystemMessageColor);
						}

						// 観戦中止
						if(MemberList[0]->STATE == MS_WATCH || MemberList[0]->STATE == MS_COUCH){
							if(TargetID == MemberList[member]->ID){
								form->QuitWatch(false);
							}
						}
						MemberList->RemoveAt(member);
						form->listBoxMember->Items->RemoveAt(member);
					}
				}
				else{
					if(id == 0){
						form->WriteTime(0, SystemMessageColor);
						form->WriteMessage(ServerName + L" was shut down.\n", SystemMessageColor);
						MemberList[0]->STATE = 0xFF;
					}
					else if(id == 0xFFFF){
						form->WriteMessage(ServerName + L" is not registered. Please try to connect at a later time.\n", ErrorMessageColor);
						MemberList[0]->STATE = 0xFF;
					}
					else{
						for(i = 0; i < MemberList->Count; i++){
							if(id == MemberList[i]->ID){
								if(i == 0){
									form->WriteTime(0, SystemMessageColor);
									form->WriteMessage(L"ERROR: Connection to the server lost.\n", ErrorMessageColor);
									MemberList[0]->STATE = 0xFF;
								}
								else{
									if(ListView != LV_BLIND){
										if(rcv[0] == PH_QUIT){
											form->WriteTime(0, SystemMessageColor);
											form->WriteMessage(MemberList[i]->NAME + L" has left.\n", SystemMessageColor);
										}
										else{
											form->WriteTime(0, SystemMessageColor);
											form->WriteMessage(L"Connection with "+ MemberList[i]->NAME + L" was interrupted.\n", ErrorMessageColor);
											if(MTINFO.DEBUG){
												form->WriteMessage(String::Format(L"ID = {0}\n", MemberList[i]->ID), DebugMessageColor);
												form->WriteMessage(String::Format(L"IP_EP = {0}\n", MemberList[i]->IP_EP), DebugMessageColor);
											}
										}
									}

									// 観戦中止
									if(MemberList[0]->STATE == MS_WATCH || MemberList[0]->STATE == MS_COUCH){
										if(TargetID == MemberList[i]->ID){
											form->QuitWatch(false);
										}
									}

									MemberList->RemoveAt(i);
									form->listBoxMember->Items->RemoveAt(i);
								}

								break;
							}
						}
					}
				}
			}
			finally{
				Monitor::Exit(MemberList);
			}

			if(MemberList[0]->STATE == 0xFF){
				form->Leave(false);
			}
			break;

		case PH_CHANGE_STATE:
			id = BitConverter::ToUInt16(rcv, 1);

			Monitor::Enter(MemberList);
			try{
				for(i = 0; i < MemberList->Count; i++){
					if(id == MemberList[i]->ID){

						if(MemberList[i]->STATE == MS_SEEK && rcv[3] != MS_SEEK){
							form->WriteTime(0, SystemMessageColor);
							form->WriteMessage(String::Format(L"{0} is now in seek mode.\n", MemberList[i]->NAME), SystemMessageColor);
						}

						MemberList[i]->STATE = rcv[3];
						form->listBoxMember->Refresh();

						if(MemberList[i]->STATE == MS_SEEK){
							form->WriteTime(0, SystemMessageColor);
							form->WriteMessage(String::Format(L"{0} is now in seek mode.\n", MemberList[i]->NAME), SystemMessageColor);
							if(MTOPTION.SEEK_SOUND_ENABLE){
								try{
									Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.SEEK_SOUND));
									wav->Play();
								}
								catch(Exception^){
								}
							}
						}

						if(MTOPTION.CONNECTION_TYPE != CT_SERVER){
							break;
						}
					}
					else if(i != 0 && MTOPTION.CONNECTION_TYPE == CT_SERVER){
						UDP->BeginSend(rcv, rcv->Length, MemberList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
					}
				}
			}
			finally{
				Monitor::Exit(MemberList);
			}
			break;

		case PH_REQ_STATE:
			id = BitConverter::ToUInt16(rcv, 1);

			Monitor::Enter(MemberList);
			try{
				send = gcnew array<BYTE>(4){ PH_RES_STATE, rcv[1], rcv[2], 0xFF };
				BYTE state;

				if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
					for(i = 0; i < MemberList->Count; i++){
						if(id == MemberList[i]->ID){
							state = (BYTE)MemberList[i]->STATE;

							if(state == MS_READY){
								state = MS_FREE;
							}

							send[3] = state;
							break;
						}
					}
				}
				else if(id == MemberList[0]->ID){
					state = (BYTE)MemberList[0]->STATE;

					if(state == MS_READY){
						state = MS_FREE;
					}

					send[3] = state;
				}

				UDP->Send(send, send->Length, ep);
			}
			finally{
				Monitor::Exit(MemberList);
			}
			break;

		case PH_RES_STATE:
			id = BitConverter::ToUInt16(rcv, 1);

			Monitor::Enter(MemberList);
			try{
				for(i = 1; i < MemberList->Count; i++){
					if(id == MemberList[i]->ID){
						MemberList[i]->RESPONSE = timeGetTime();

						if(rcv[3] == 0xFF){
							// そんな人いなかった
							form->WriteTime(0, SystemMessageColor);
							form->WriteMessage(L"We didn't have "+MemberList[i]->NAME + L" before.\n", SystemMessageColor);

							if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
								// 全員に通達
								rcv[0] = PH_LOST;

								for(int j = 1; j < MemberList->Count; j++){
									if(id != MemberList[j]->ID){
										UDP->BeginSend(rcv, 3, MemberList[j]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
									}
								}
							}
							else{
								// いなかった通知 応急処置Ver
								// 蔵からのみ見えている状態
								// サーバには情報がないので間接的に通知してもらう
								rcv[0] = PH_LOST;
								rcv[1] = 0xFF;
								rcv[2] = 0xFF;
								UDP->Send(rcv, 3, MemberList[i]->IP_EP);
							}

							MemberList->RemoveAt(i);
							form->listBoxMember->Items->RemoveAt(i);
						}
						else if(MemberList[i]->STATE != rcv[3]){
							if(MTINFO.DEBUG){
								form->WriteMessage(String::Format(MemberList[i]->NAME + L" > state:{0}\n", rcv[3]), DebugMessageColor);
							}
							form->WriteTime(0, SystemMessageColor);
							form->WriteMessage(L"Updated state for " + MemberList[i]->NAME + L".\n", SystemMessageColor);
							if(MTOPTION.CONNECTION_TYPE != CT_SERVER && MemberList[i]->ID == 0){
								form->WriteMessage(L"Connection to the server may have been lost. Please try to reconnect.\n", ErrorMessageColor);
							}
							MemberList[i]->STATE = rcv[3];
							form->listBoxMember->Refresh();
						}
						break;
					}
				}
			}
			finally{
				Monitor::Exit(MemberList);
			}
			break;

		case PH_CHANGE_COMMENT:
			if(ServerMode >= SM_MATCH){
				break;
			}

			id = BitConverter::ToUInt16(rcv, 1);

			Monitor::Enter(MemberList);
			try{
				for(i = 1; i < MemberList->Count; i++){
					if(id == MemberList[i]->ID){
						MemberList[i]->COMMENT = Encoding::Unicode->GetString(rcv, 4, rcv[3]);
						break;
					}
				}

				if(i < MemberList->Count && ListView == LV_COMMENT){
					if(MemberList[i]->COMMENT->Length > 0){
						form->listBoxMember->Items[i] = MemberList[i]->COMMENT;
					}
					else{
						form->listBoxMember->Items[i] = gcnew String(L"◆");
					}
				}
			}
			finally{
				Monitor::Exit(MemberList);
			}

			if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
				form->PacketSendAllMember(rcv, id);
			}
			break;

		case PH_DICE:
			if(MTOPTION.CONNECTION_TYPE != CT_SERVER){
				Monitor::Enter(form->richTextBoxLog);
				try{
					form->richTextBoxLog->SelectionStart = form->richTextBoxLog->Text->Length;

					form->richTextBoxLog->SelectionColor = TalkMessageColor;
					form->richTextBoxLog->SelectionBackColor = NoticeBackColor;
					form->richTextBoxLog->AppendText(Byte(rcv[1]).ToString() + L"\n");

					form->richTextBoxLog->SelectionStart = form->richTextBoxLog->Text->Length;
					if(!MTOPTION.LOG_LOCK) {
						form->richTextBoxLog->ScrollToCaret();
					}
				}
				catch(Exception ^e){
					WriteErrorLog(e->ToString(), "RichTextBox");
				}
				finally{
					Monitor::Exit(form->richTextBoxLog);
				}
			}
			break;

		case PH_REQ_VS:

			// 準備時間が長すぎた場合は新規接続受付
			if(NetVS != nullptr && MemberList[0]->STATE == MS_READY){
				if((timeGetTime() - NetVS->START_UP) > TIME_OUT*2 + 1000){
					MemberList[0]->STATE = MS_FREE;
					delete NetVS;
					NetVS = nullptr;
				}
			}

			if(MemberList[0]->STATE == MS_SEEK && GameThread != nullptr){
				form->QuitGame();
				GameThread = nullptr;
				Thread::Sleep(500);
			}

			send = gcnew array<BYTE>(2);
			send[0] = PH_RES_VS;
			send[1] = (BYTE)MemberList[0]->STATE;

			// 格ツクじゃないよ
			try{
				String^ exe = gcnew String(MTOPTION.GAME_EXE);
				FileVersionInfo^ info = FileVersionInfo::GetVersionInfo(exe);

				if(!IsCompatibleFMExecutable(info->FileDescription)){
					throw gcnew Exception;
				}
				/*
				else if(ServerMode == SM_MIX){
					// 混在サーバモードなので、実行ファイルのチェック
					if((INT32)(Path::GetFileNameWithoutExtension(exe)->GetHashCode()) != BitConverter::ToInt32(rcv, 3)){
						send[1] = 0xFE;
					}
				}
				*/
				else{
					if((INT32)(Path::GetFileNameWithoutExtension(exe)->GetHashCode()) != BitConverter::ToInt32(rcv, 3)){
						send[1] = 0xFE;
					}
					if(IsCompatibleFM2KExecutable(info->FileDescription)){
						MTINFO.KGT2K = true;
					}
					else{
						MTINFO.KGT2K = false;
					}
				}
			}
			catch(Exception^){
				send[1] = 0xFF;
				form->WriteMessage(L"ERROR: This is not a valid 2D Fighter Maker executable.\n", ErrorMessageColor);
				form->WriteMessage(L"Please go to the settings menu and set the path to a compatible game executable.\n", ErrorMessageColor);
			}

			UDP->BeginSend(send, send->Length, ep, gcnew AsyncCallback(SendPackets), UDP);

			if((send[1] == MS_FREE)||(send[1] == MS_SEEK)){
				MemberList[0]->STATE = MS_READY;

				id = BitConverter::ToUInt16(rcv, 1);

				Monitor::Enter(MemberList);
				try{
					for(i = 0; i < MemberList->Count; i++){
						if(id == MemberList[i]->ID) break;
					}

					if(i >= MemberList->Count){
						form->WriteMessage(L"ERROR: A match request was received from someone not on the list.\n", ErrorMessageColor);
						MemberList[0]->STATE = MS_FREE;

						if(MTOPTION.CONNECTION_TYPE != CT_SERVER){
							// 知らない人がいたのでサーバに問い合わせ
							array<BYTE>^ send = gcnew array<BYTE>(3){ PH_REQ_LIST };
							Array::Copy(BitConverter::GetBytes(id), 0, send, 1, 2);
							UDP->Send(send, 3, MemberList[1]->IP_EP);
						}
						break;
					}

					NetVS = gcnew VersusInfo;
					NetVS->SEQUENCE = VS_SETTING;
					NetVS->SLEEPING = false;
					NetVS->WAITING  = false;
					NetVS->START_UP = timeGetTime();
					NetVS->IP_EP    = ep;
					NetVS->PING     = gcnew array<UINT>(5){ 0, 0, 0, 0, 0 };
					NetVS->PONG     = gcnew array<UINT>(5){ 0, 0, 0, 0, 0 };
					NetVS->SEND     = gcnew array<BYTE>(32){ PH_VS_DATA };
					NetVS->L_FRAME  = 0;
					NetVS->L_READ   = 0;
					NetVS->R_FRAME  = 0;
					NetVS->R_READ   = 0;

					// 観戦用ID
					P1ID = MemberList[0]->ID;
					P2ID = id;

					// 名前
					ZeroMemory(MTINFO.P1_NAME, sizeof(MTINFO.P1_NAME));
					ZeroMemory(MTINFO.P2_NAME, sizeof(MTINFO.P2_NAME));

					if(ListView != LV_BLIND){
						_tcscpy_s(MTINFO.P1_NAME, MTOPTION.NAME);

						IntPtr mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(MemberList[i]->NAME);
						_tcscpy_s(MTINFO.P2_NAME, static_cast<PTCHAR>(mp.ToPointer()));
						Runtime::InteropServices::Marshal::FreeHGlobal(mp);
					}

					// 対戦回数
					MemberList[i]->NUM_VS++;

					if(ListView != LV_BLIND){
						form->WriteTime(0, SystemMessageColor);
						form->WriteMessage(MemberList[i]->NAME, NameColor[MemberList[i]->TYPE]);
						form->WriteMessage(L"A new challenger!\n", SystemMessageColor);
					}
				}
				finally{
					Monitor::Exit(MemberList);
				}
			}
			break;

		case PH_RES_VS:
			if((rcv[1] != MS_FREE)&&(rcv[1] != MS_SEEK)){
				switch(rcv[1]){
				case MS_REST:
					form->WriteMessage(L"Challenger is currently on break.\n", SystemMessageColor);
					break;
				case MS_VS:
					form->WriteMessage(L"Challenger is currently playing.\n", SystemMessageColor);
					break;
				case MS_WATCH:
				case MS_COUCH:
					form->WriteMessage(L"Challenger is currently spectating.\n", SystemMessageColor);
					break;
				case MS_SEEK:
					break;
				case MS_READY:
					form->WriteMessage(L"Challenger is currently preparing for battle against another person.\n", SystemMessageColor);
					break;
				case 0xFE:
					form->WriteMessage(L"ERROR: You and your challenger have a different game or game version. Make sure your game executable's file name is the same as that of your opponent.\n", ErrorMessageColor);
					break;
				default:
					form->WriteMessage(L"Challenger is currently not in a state for matchmaking.\n", SystemMessageColor);
					break;
				}

				NetVS->SEQUENCE = VS_ERROR;

				if(VersusThread != nullptr && VersusThread->IsAlive && NetVS->SLEEPING){
					VersusThread->Interrupt();
				}
			}
			else if(NetVS != nullptr){
				NetVS->SEQUENCE = VS_PING;

				if(VersusThread != nullptr && VersusThread->IsAlive && NetVS->SLEEPING){
					VersusThread->Interrupt();
				}
			}
			break;

		case PH_REQ_VS_PING:
			rcv[0] = PH_RES_VS_PONG;
			UDP->Send(rcv, rcv->Length, ep);
			break;

		case PH_RES_VS_PONG:
			if(NetVS != nullptr){
				NetVS->PONG[rcv[1]] = timeGetTime();

				for(id = 0, i = 0; id < 5; id++){
					if(NetVS->PONG[id] > 0){
						i++;

						if(i == 4){
							if(NetVS->SEQUENCE == VS_PING){
								NetVS->SEQUENCE = VS_SETTING;
							
								if(VersusThread != nullptr && VersusThread->IsAlive && NetVS->SLEEPING){
									VersusThread->Interrupt();
								}
							}
							break;
						}
					}
				}
			}
			break;

		case PH_REQ_VS_SETTING:
			if(NetVS != nullptr && NetVS->SEQUENCE == VS_SETTING){
				send = gcnew array<BYTE>(11){ PH_RES_VS_SETTING };

				// 対戦設定
				MTINFO.SEED          = XorShift();
				MTINFO.MAX_STAGE     = MTOPTION.MAX_STAGE;
				MTINFO.STAGE_SELECT  = MTOPTION.STAGE_SELECT;
				MTINFO.ROUND         = MTOPTION.ROUND;
				MTINFO.TIMER         = MTOPTION.TIMER;
				MTINFO.TEAM_ROUND_HP = MTOPTION.TEAM_ROUND_HP;

				// ディレイ
				if(MTOPTION.DELAY == 0 || rcv[1] > MTOPTION.DELAY){
					send[1] = rcv[1];
				}
				else{
					send[1] = (BYTE)MTOPTION.DELAY;
				}

				NetVS->SEQUENCE = VS_DATA;
				NetVS->DELAY    = send[1];
				NetVS->LOCAL    = gcnew array<UINT16>(NetVS->DELAY*4);
				NetVS->REMOTE   = gcnew array<UINT16>(NetVS->DELAY*4);

				for(i = 0; i < NetVS->LOCAL->Length; i++){
					NetVS->LOCAL[i]  = 0xFFFF;
					NetVS->REMOTE[i] = 0xFFFF;
				}

				for(UINT i = 0; i < NetVS->DELAY; i++){
					NetVS->LOCAL[i] = 0x0000;
				}

				Array::Copy(BitConverter::GetBytes(MTINFO.SEED), 0, send, 2, 4);
				send[6]  = (BYTE)MTINFO.MAX_STAGE;
				send[7]  = (BYTE)MTINFO.STAGE_SELECT;
				send[8]  = (BYTE)MTINFO.ROUND;
				send[9]  = (BYTE)MTINFO.TIMER;
				send[10] = (BYTE)MTINFO.TEAM_ROUND_HP;
				UDP->Send(send, send->Length, ep);

				MTINFO.CONTROL = 0;

				// 対戦開始
				form->WriteTime(0, SystemMessageColor);
				form->WriteMessage(String::Format(L"Starting match... (Delay: {0})\n", NetVS->DELAY), SystemMessageColor);

				// 音でお知らせ
				if(MTOPTION.VS_SOUND_ENABLE){
					try{
						Media::SoundPlayer^ wav = gcnew Media::SoundPlayer(gcnew String(MTOPTION.VS_SOUND));
						wav->Play();
					}
					catch(Exception^){
					}
				}

				// 待ち受け用ちょっとスリープ
				Thread::Sleep(1000);

				GameThread = gcnew Thread(gcnew ParameterizedThreadStart(form, &MainForm::RunGame));
				GameThread->Start((UINT)RT_VS);
			}
			break;

		case PH_RES_VS_SETTING:
			if(NetVS != nullptr){
				NetVS->DELAY  = rcv[1];
				NetVS->LOCAL  = gcnew array<UINT16>(NetVS->DELAY*4);
				NetVS->REMOTE = gcnew array<UINT16>(NetVS->DELAY*4);

				for(i = 0; i < NetVS->LOCAL->Length; i++){
					NetVS->LOCAL[i]  = 0xFFFF;
					NetVS->REMOTE[i] = 0xFFFF;
				}

				for(UINT i = 0; i < NetVS->DELAY; i++){
					NetVS->LOCAL[i] = 0x0000;
				}

				MTINFO.SEED         = BitConverter::ToUInt32(rcv, 2);
				MTINFO.MAX_STAGE    = rcv[6];
				MTINFO.STAGE_SELECT = rcv[7];
				MTINFO.ROUND        = rcv[8];
				MTINFO.TIMER        = rcv[9];
				// v1.04以上互換
				try{
					if(rcv[10]){
						MTINFO.TEAM_ROUND_HP = true;
					}else{
						MTINFO.TEAM_ROUND_HP = false;
					}
				}
				catch(Exception^){
					MTINFO.TEAM_ROUND_HP = false;
					form->WriteMessage(L"ERROR: Opponent is using an old version of LilithPort or MTSP!\n", ErrorMessageColor);
				}
				

				if(VersusThread != nullptr && VersusThread->IsAlive && NetVS->SEQUENCE == VS_SETTING && NetVS->SLEEPING){
					NetVS->SEQUENCE = VS_STANDBY;
					VersusThread->Interrupt();
				}
			}
			break;

		case PH_VS_END:
			if(NetVS != nullptr){
				form->WriteMessage(L"The match was ended.\n", SystemMessageColor);

				NetVS->SEQUENCE = VS_END;
				form->QuitGame();

				Monitor::Enter(NetVS->REMOTE);
				try{
					if(NetVS->WAITING == 2){
						NetVS->WAITING = 1;
						Monitor::Pulse(NetVS->REMOTE);
					}
				}
				finally{
					Monitor::Exit(NetVS->REMOTE);
				}

				if(MTINFO.DEBUG){
					form->WriteMessage(String::Format(L"Frame > {0}\n", NetVS->L_FRAME), DebugMessageColor);
				}
			}
			break;

		case PH_VS_DATA:
			if(NetVS != nullptr && NetVS->SEQUENCE == VS_DATA){
				UINT f = BitConverter::ToUInt32(rcv, 1);

				Monitor::Enter(NetVS->REMOTE);
				try{
					if(NetVS->R_FRAME > f + NetVS->DELAY){
						if(MTINFO.DEBUG){
							form->WriteMessage(String::Format(L"Invalid packet (delay): {0}/{1}\n", f, NetVS->R_FRAME), DebugMessageColor);
						}
						break;
					}
					else if(f > NetVS->R_FRAME + NetVS->DELAY){
						// まずこない
						if(MTINFO.DEBUG){
							form->WriteMessage(String::Format(L"Invalid packet (preceding): {0}/{1}\n", f, NetVS->R_FRAME), DebugMessageColor);
						}
						break;
					}

					for(UINT i = 0; i <= NetVS->DELAY; i++){
						if((f + i) < NetVS->R_FRAME){
							continue;
						}

						NetVS->REMOTE[(f + i) % NetVS->REMOTE->Length] = BitConverter::ToUInt16(rcv, 5 + i*2);

						if((f + i) == NetVS->R_FRAME && NetVS->WAITING == 2){
							NetVS->WAITING = 1;
							Monitor::Pulse(NetVS->REMOTE);
						}
					}
				}
				finally{
					Monitor::Exit(NetVS->REMOTE);
				}
			}
			break;

		case PH_REQ_VS_DATA:
			if(NetVS != nullptr && NetVS->SEQUENCE == VS_DATA){
				send = gcnew array<BYTE>(7);
				send[0] = PH_RES_VS_DATA;
				Array::Copy(rcv, 1, send, 1, 4);
				send[5] = 0xFF;
				send[6] = 0xFF;

				UINT f = BitConverter::ToUInt32(rcv, 1);

				Monitor::Enter(NetVS->LOCAL);
				try{
					if(f >= NetVS->L_FRAME + NetVS->DELAY){
						if(MTINFO.DEBUG){
							form->WriteMessage(String::Format(L"Invalid packet (prior request): {0}/{1}\n", f, NetVS->L_FRAME), DebugMessageColor);
						}
						UDP->BeginSend(send, send->Length, ep, gcnew AsyncCallback(SendPackets), UDP);
						break;
					}
					else if(NetVS->L_FRAME > f + NetVS->DELAY*2){
						// 既にデータがないのでこれがくるとゲームにならない
						if(MTINFO.DEBUG){
							form->WriteMessage(String::Format(L"Invalid packet (delayed request): {0}/{1}\n", f, NetVS->L_FRAME), DebugMessageColor);
						}
						break;
					}

					if(MTINFO.DEBUG){
						form->WriteMessage(String::Format(L"Request packet: {0}/{1}\n", f, NetVS->L_FRAME), DebugMessageColor);
					}

					Array::Copy(BitConverter::GetBytes(NetVS->LOCAL[f % NetVS->LOCAL->Length]), 0, send, 5, 2);
					UDP->BeginSend(send, send->Length, ep, gcnew AsyncCallback(SendPackets), UDP);
				}
				finally{
					Monitor::Exit(NetVS->LOCAL);
				}
			}
			break;

		case PH_RES_VS_DATA:
			if(NetVS != nullptr && NetVS->WAITING > 0){
				UINT32 f = BitConverter::ToUInt32(rcv, 1);

				Monitor::Enter(NetVS->REMOTE);
				try{
					if(f != NetVS->R_FRAME) break;

					UINT16 w = BitConverter::ToUInt16(rcv, 5);

					NetVS->REMOTE[NetVS->R_READ] = w;

					if(MTINFO.DEBUG){
						form->WriteMessage(String::Format(L"Reply packet: {0} : {1}\n", f, w), DebugMessageColor);
					}

					if(NetVS->WAITING == 2){
						NetVS->WAITING = 1;
						Monitor::Pulse(NetVS->REMOTE);
					}
				}
				finally{
					Monitor::Exit(NetVS->REMOTE);
				}
			}
			break;

		case PH_REQ_WATCH:
			rcv[0] = PH_RES_WATCH;
			id = BitConverter::ToUInt16(rcv, 1);

			if(MTOPTION.ALLOW_SPECTATOR == false){
				// 観戦不許可
				rcv[1] = 1;
				UDP->Send(rcv, 2, ep);
				break;
			}
			else if(SpectatorList->Count >= (int)MTOPTION.MAX_CONNECTION){
				// 満席
				rcv[1] = 2;
				UDP->Send(rcv, 2, ep);
				break;
			}
			else if(InputFrame > (UINT)InputHistory->Length - 200){
				// 遅刻
				rcv[1] = 3;
				UDP->Send(rcv, 2, ep);
				break;
			}
			else if(WatchTarget != nullptr && id == TargetID){
				// 相互観戦
				rcv[1] = 4;
				UDP->Send(rcv, 2, ep);
				break;
			}
			else{
				SpectatorInfo^ si = gcnew SpectatorInfo;
				si->ID    = id;
				si->IP_EP = ep;
				si->FRAME = 0;

				if(SpectacleThread != nullptr && SpectacleThread->IsAlive && AllowWatch){
					// 既にはじめてる
					send = gcnew array<BYTE>(14);
					send[0] = PH_RES_WATCH;
					send[1] = 0;
					Array::Copy(BitConverter::GetBytes(P1ID), 0, send, 2, 2);
					Array::Copy(BitConverter::GetBytes(P2ID), 0, send, 4, 2);
					Array::Copy(BitConverter::GetBytes(MTINFO.SEED), 0, send, 6, 4);
					send[10] = MTINFO.MAX_STAGE;
					send[11] = MTINFO.STAGE_SELECT;
					send[12] = MTINFO.ROUND;
					send[13] = MTINFO.TIMER;

					UDP->Send(send, send->Length, ep);

					// なかなかデンジャラスなSleep
					Thread::Sleep(100);
				}

				Monitor::Enter(InputHistory);
				try{
					SpectatorList->Add(si);
				}
				finally{
					Monitor::Exit(InputHistory);
				}

				if(ListView != LV_BLIND){
					Monitor::Enter(MemberList);
					try{
						for(i = 0 ; i < MemberList->Count; i++){
							if(id == MemberList[i]->ID){
								break;
							}
						}

						if(i >= MemberList->Count){
							// 外来客
							form->WriteMessage(L"A spectator has joined.\n", SystemMessageColor);
						}
						else{
							form->WriteMessage(MemberList[i]->NAME + L" has joined the match as a spectator.\n", SystemMessageColor);
						}
					}
					finally{
						Monitor::Exit(MemberList);
					}
				}
			}
			break;

		case PH_RES_WATCH:
			if(rcv[1] > 0){
				switch(rcv[1]){
				case 1:
					form->WriteMessage(L"Spectating is disabled for this match.\n", SystemMessageColor);
					break;

				case 2:
					form->WriteMessage(L"All spectator seats are taken!\n", SystemMessageColor);
					break;

				case 3:
					form->WriteMessage(L"You did not join in time to spectate.\n", SystemMessageColor);
					break;

				case 4:
					form->WriteMessage(L"You are already watching the opponent!\n", SystemMessageColor); //fixme: hard translation: 既に相手がこちらを観戦対象にしていました。
					break;
				}

				form->QuitWatch(false);
			}
			else{
				if(MemberList[0]->STATE == MS_WATCH || MemberList[0]->STATE == MS_COUCH){
					ZeroMemory(MTINFO.P1_NAME, sizeof(MTINFO.P1_NAME));
					ZeroMemory(MTINFO.P2_NAME, sizeof(MTINFO.P2_NAME));

					P1ID = BitConverter::ToUInt16(rcv, 2);
					P2ID = BitConverter::ToUInt16(rcv, 4);
					MTINFO.SEED = BitConverter::ToUInt32(rcv, 6);

					MTINFO.MAX_STAGE    = rcv[10];
					MTINFO.STAGE_SELECT = rcv[11];
					MTINFO.ROUND        = rcv[12];
					MTINFO.TIMER        = rcv[13];

					IntPtr mp;
					int c = 0;

					if(ListView != LV_BLIND){
						Monitor::Enter(MemberList);
						try{
							// 名前
							for(i = 0; i < MemberList->Count; i++){
								if(MemberList[i]->ID == P1ID){
									mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(MemberList[i]->NAME);
									_tcscpy_s(MTINFO.P1_NAME, static_cast<PTCHAR>(mp.ToPointer()));
									Runtime::InteropServices::Marshal::FreeHGlobal(mp);

									c++;
								}
								else if(MemberList[i]->ID == P2ID){
									mp = Runtime::InteropServices::Marshal::StringToHGlobalAuto(MemberList[i]->NAME);
									_tcscpy_s(MTINFO.P2_NAME, static_cast<PTCHAR>(mp.ToPointer()));
									Runtime::InteropServices::Marshal::FreeHGlobal(mp);

									c++;
								}

								if(c == 2) break;
							}
						}
						finally{
							Monitor::Exit(MemberList);
						}
					}

					for(i = 0; i < WatchHistory->Length; i++){
						WatchHistory[i] = 0xFFFF;
					}
					WaitingWatch = 1;

					GameThread = gcnew Thread(gcnew ParameterizedThreadStart(form, &MainForm::RunGame));
					GameThread->Start((UINT)RT_WATCH);

					form->WriteMessage(L"Now spectating. Starting game...\n", SystemMessageColor);
				}
			}
			break;

		case PH_WATCH_DATA:
			if(WatchTarget != nullptr && WaitingWatch > 0){
				UINT32 f = BitConverter::ToUInt32(rcv, 1);

				if(f > WatchFrame + WatchHistory->Length - 20){
                    form->WriteMessage(L"ERROR: Could not synchronize; leaving spectator mode...\n", ErrorMessageColor); //fixme: hard translation: 同期が取れなくなったため観戦を中止します。
					form->QuitWatch(true);
				}

				Monitor::Enter(WatchHistory);
				try{
					if(WatchFrame > f + 20){
						if(MTINFO.DEBUG){
							form->WriteMessage(String::Format(L"Spectator packet (delay): {0}/{1}\n", f, WatchFrame), DebugMessageColor);
						}
						break;
					}

					for(UINT i = 0; i < 20; i++){
						if((f + i) < WatchFrame){
							continue;
						}

						WatchHistory[(f + i) % WatchHistory->Length] = BitConverter::ToUInt16(rcv, 5 + i*2);

						if((f + i) == WatchFrame && WaitingWatch == 2){
							WaitingWatch = 1;
							Monitor::Pulse(WatchHistory);
						}
					}
				}
				finally{
					Monitor::Exit(WatchHistory);
				}
			}
			break;

		case PH_WATCH_END:
			id = BitConverter::ToUInt16(rcv, 1);

			if(id == MemberList[0]->ID){
				// 閉幕のお知らせ
				form->WriteMessage(L"The match was ended. Leaving spectator mode...\n", SystemMessageColor);
				form->QuitWatch(false);
			}
			else{
				// 観戦中止のお知らせ
				Monitor::Enter(InputHistory);
				try{
					if(MTINFO.DEBUG){
						form->WriteMessage(String::Format(L"Spectator end: {0}\n", id), DebugMessageColor);
					}

					for(i = 0; i < SpectatorList->Count; i++){
						if(id == SpectatorList[i]->ID){
							SpectatorList->RemoveAt(i);
							break;
						}
					}
				}
				finally{
					Monitor::Exit(InputHistory);
				}
			}
			break;

		case PH_SECRET:
			// 隠しコマンド
			switch(rcv[1]){
			case ST_PING:
				rcv[1] = ST_PONG;
				UDP->Send(rcv, rcv->Length, ep);
				break;

			case ST_PONG:
				{
					id = BitConverter::ToUInt16(rcv, 2);
					UINT32 time = timeGetTime() - BitConverter::ToUInt32(rcv, 4);

					Monitor::Enter(MemberList);
					try{
						for(i = 0; i < MemberList->Count; i++){
							if(id == MemberList[i]->ID){
								Monitor::Enter(form->richTextBoxLog);
								try{
									form->richTextBoxLog->SelectionStart = form->richTextBoxLog->Text->Length;

                                    form->richTextBoxLog->SelectionColor = SecretColor;
                                    form->richTextBoxLog->AppendText(L"Inflicted DAMAGE on ");

									form->richTextBoxLog->SelectionColor = NameColor[MemberList[i]->TYPE];
									form->richTextBoxLog->AppendText(MemberList[i]->NAME);

									form->richTextBoxLog->SelectionColor = SecretColor;
									form->richTextBoxLog->AppendText(L" at ");

									form->richTextBoxLog->SelectionColor = TalkMessageColor;
                                    form->richTextBoxLog->AppendText(UInt32(time).ToString());
                                    
                                    form->richTextBoxLog->SelectionColor = SecretColor;
                                    form->richTextBoxLog->AppendText(L"!!\n");

									form->richTextBoxLog->SelectionStart = form->richTextBoxLog->Text->Length;
									if(!MTOPTION.LOG_LOCK) {
										form->richTextBoxLog->ScrollToCaret();
									}
								}
								catch(Exception ^e){
									WriteErrorLog(e->ToString(), "RichTextBox");
								}
								finally{
									Monitor::Exit(form->richTextBoxLog);
								}
								break;
							}
						}
					}
					finally{
						Monitor::Exit(MemberList);
					}
				}
				break;

			default:
				break;
			}
			break;

		default:
			if(MTINFO.DEBUG){
				form->WriteMessage(String::Format(L"Unknown Packet > {0} from {1}\n", rcv[0], ep->ToString()), DebugMessageColor);
			}
			break;
		}
	}
	catch(ObjectDisposedException^){
		// UDP接続終了
		if(UDP != nullptr){
			UDP = nullptr;
			form->WriteMessage(L"Connection was interrupted!\n", SystemMessageColor);
		}
	}
	catch(SocketException^ e){
		UDP->BeginReceive(gcnew AsyncCallback(ReceivePackets), form);

		if(e->ErrorCode == WSAECONNRESET){
			// パケットが弾かれた
			if(MTINFO.DEBUG){
				form->WriteMessage(L"ERROR: WSAECONNRESET\n", DebugMessageColor);
			}
		}
		else{
			form->WriteMessage(String::Format(L"SOCKET ERROR: {0}\n", e->ErrorCode), ErrorMessageColor);
			if(MTINFO.DEBUG){
				form->WriteMessage(e->ToString() + L"\n", DebugMessageColor);
			}
		}
	}
	catch(Exception^ e){
		form->WriteMessage(e->ToString() + L"\n", ErrorMessageColor);
	}
}
// IP取得タイムアウト用タイマー
void MainForm::TimerGetIP()
{
	GetIPSleeping = true;
	try{
		// 15秒ぐらいでタイムアウト
		Thread::Sleep(1000*15);
	}
	catch(ThreadInterruptedException^){
	}
	GetIPSleeping = false;

	try{
		if(GetIPClient != nullptr){
			GetIPClient->CancelAsync();
		}
	}
	catch(Exception^ e) {
		WriteMessage(e->ToString() + L"\n", ErrorMessageColor);
	}
}

// HP持ち越しタイマー
void MainForm::SetTeamHP(){
	if(MTINFO.DEBUG){
		WriteMessage(L"EVENT: SET_TEAM_HP\n", DebugMessageColor);
		WriteMessage(String::Format(L"PROCESS: {0}, WINNER: P{1}, HP: {2}\n", (UINT)MTINFO.PROCESS, ((UINT)MTINFO.WINNER)+1, MTINFO.P_HP), DebugMessageColor);
	}
	Thread::Sleep(1000);
	try {
		if(MTINFO.WINNER){
			WriteProcessMemory(MTINFO.PROCESS, (LPVOID)P2_HP, &MTINFO.P_HP, 4, NULL);
		}else{
			WriteProcessMemory(MTINFO.PROCESS, (LPVOID)P1_HP, &MTINFO.P_HP, 4, NULL);
		}
	}
	catch(Exception^ e){
		if(MTINFO.DEBUG){
			WriteMessage(String::Format(L"{0}\n", e->ToString()), DebugMessageColor);
		}
	}
}
void MainForm::RunSonar()
{
	int i, j;
	bool leave = false;
	array<BYTE>^ send = gcnew array<BYTE>(3){ PH_REQ_STATE, 0x00, 0x00 };

	SonarSleeping = false;

	// 20sに一度パケットを送り、100s以上応答がなかったら切断する
	while(Ranging){
		SonarSleeping = true;
		try{
			Thread::Sleep(20*1000);
		}
		catch(ThreadInterruptedException^){
		}
		SonarSleeping = false;

		// ログの自動保存
		if(MTOPTION.AUTO_SAVE){
			if(((timeGetTime() - MemberList[0]->RESPONSE) / 60000) >= MTOPTION.AUTO_SAVE){
				String^ path = gcnew String(MTOPTION.PATH);
				path += "auto.log";

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

				MemberList[0]->RESPONSE = timeGetTime();
			}
		}

		if(!Ranging) return;

		Monitor::Enter(MemberList);
		try{
			if(MTOPTION.CONNECTION_TYPE == CT_SERVER){
				listBoxMember->BeginUpdate();

				for(i = 1; i < MemberList->Count; i++){
					Array::Copy(BitConverter::GetBytes(MemberList[i]->ID), 0, send, 1, 2);

					if((timeGetTime() - MemberList[i]->RESPONSE) > 100*1000){
						WriteTime(0, SystemMessageColor);
						WriteMessage("Connection with " + MemberList[i]->NAME + L" was interrupted.\n", ErrorMessageColor);

						send[0] = PH_LOST;

						for(j = 1; j < MemberList->Count; j++){
							UDP->BeginSend(send, send->Length, MemberList[j]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
						}

						MemberList->RemoveAt(i);
						listBoxMember->Items->RemoveAt(i);

						send[0] = PH_REQ_STATE;
						i--;
					}
					else{
						// 確認パケ
						UDP->BeginSend(send, send->Length, MemberList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
					}
				}

				listBoxMember->EndUpdate();
			}
			else{
				if((timeGetTime() - MemberList[1]->RESPONSE) > 100*1000){
					WriteMessage(L"Connection with the server timed out.\n", ErrorMessageColor);
					leave   = true;
					Ranging = false;
				}
				else{
					UDP->Send(send, send->Length, MemberList[1]->IP_EP);
				}
			}
		}
		catch(Exception^){
			WriteMessage(L"An exception was thrown in the sonar thread.\n", ErrorMessageColor);
		}
		finally{
			Monitor::Exit(MemberList);
		}
	}

	if(leave){
		Leave(false);
	}
}

void MainForm::RunGame(Object^ obj)
{
	UINT run_type = (UINT)obj;
	bool record_replay   = MTOPTION.RECORD_REPLAY;
	bool allow_spectator = MTOPTION.ALLOW_SPECTATOR;
	UINT sim_delay       = MTOPTION.SIMULATE_DELAY;

	// 送信間隔を計算
	if(run_type == RT_VS){
		NetVS->INTERVAL  = 0;
		NetVS->INTERVAL2 = 0;

		if(MTOPTION.INTERVAL > 0){
			if(MTOPTION.INTERVAL == 1){
				// Low
				NetVS->INTERVAL = (NetVS->DELAY + 1) / 4;

				if(NetVS->INTERVAL == 1){
					switch(NetVS->DELAY){
					case 3:
						NetVS->INTERVAL = 0;
						break;
					case 4:
						NetVS->INTERVAL2 = 5;
						break;
					case 5:
					case 6:
						NetVS->INTERVAL2 = 3;
						break;
					}
				}
			}
			else if(MTOPTION.INTERVAL == 2){
				// Middle
				NetVS->INTERVAL = (NetVS->DELAY + 1) / 3;

				if(NetVS->INTERVAL == 1){
					switch(NetVS->DELAY){
					case 2:
						NetVS->INTERVAL = 0;
						break;
					case 3:
					case 4:
						NetVS->INTERVAL2 = 4;
						break;
					}
				}
			}
			else if(MTOPTION.INTERVAL == 3){
				// High
				NetVS->INTERVAL = (NetVS->DELAY + 1) / 2;

				if(NetVS->INTERVAL == 1){
					// Delay:2 のみ
					NetVS->INTERVAL2 = 3;
				}
			}
		}
	}

	TCHAR wdir[_MAX_PATH], buf[_MAX_PATH], drive[_MAX_DRIVE];
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DEBUG_EVENT de;
	CONTEXT c;
	HANDLE thread = NULL;
	DWORD thread_id = 0;
	DWORD state, e_code, e_address, mem;
	DWORD stage_loop = 0, blt_count = 0, input_count = 0, rand_count = 0, now_time, last_time = 0;
	int i, append_cap, last_cap = 0, num_vs = 0, p1_win = 0, p2_win = 0, timer = 0, p1_round = 0, p2_round = 0;
	bool vs_end = true, single_p = 0;

	MTINFO.INITIALIZED = false;
	MTINFO.SHOW_TOP = false;
	ZeroMemory(MTINFO.ORIGINAL_TITLE, sizeof(MTINFO.ORIGINAL_TITLE));
	ZeroMemory(MTINFO.TITLE, sizeof(MTINFO.TITLE));

	// リプレイファイル
	BinaryWriter^ bw = nullptr;
	BinaryReader^ br = nullptr;

	REPLAY_INFO ri;
	// dequeがあるため初期化は手動で
	ri.CONTROL = 0;
	ri.KEY[0] = ri.KEY[1] = 0xFFFF;
	ri.COUNT[0] = ri.COUNT[1] = 0;

	// ディレイシミュレート
	std::deque<UINT16> sim_que;
	std::deque<UINT16> sim_que_p2;

	if(run_type == RT_FREE && sim_delay > 0){
		for(UINT i = 0; i < sim_delay; i++){
			sim_que.push_back(0);
			sim_que_p2.push_back(0);
		}
	}

	try{
		String ^path, ^file;
		array<TCHAR>^ header = gcnew array<TCHAR>{'T', 'Y', 'M', 'T', 'R'};
		BYTE len;

		if(run_type == RT_PLAYBACK){
			br = gcnew BinaryReader(File::OpenRead(ReplayFilePath));

			// ヘッダ
			br->ReadChars(header->Length);
			ri.VERSION = br->ReadChar();

			// P1ネーム
			len = br->ReadByte();
			for(i = 0; i < len; i++){
				MTINFO.P1_NAME[i] = br->ReadChar();
			}

			// P2ネーム
			len = br->ReadByte();
			for(i = 0; i < len; i++){
				MTINFO.P2_NAME[i] = br->ReadChar();
			}

			// 乱数シード
			MTINFO.SEED = br->ReadUInt32();
			MTINFO.TEAM_ROUND_HP = MTOPTION.TEAM_ROUND_HP;

			if(ri.VERSION >= _T('3')){
				MTINFO.MAX_STAGE     = br->ReadByte();
				MTINFO.STAGE_SELECT  = br->ReadByte();
				MTINFO.ROUND         = br->ReadByte();
				MTINFO.TIMER         = br->ReadByte();
			}
			else{
				MTINFO.MAX_STAGE     = MTOPTION.MAX_STAGE;
				MTINFO.STAGE_SELECT  = MTOPTION.STAGE_SELECT;
				MTINFO.ROUND         = MTOPTION.ROUND;
				MTINFO.TIMER         = MTOPTION.TIMER;
			}
		}
		else if(record_replay){
			path = gcnew String(MTOPTION.REPLAY_FOLDER);

			// ゲーム別にリプレイを振り分け
			if(MTOPTION.REPLAY_DIVIDE){
				path += "\\" + Path::GetFileNameWithoutExtension(gcnew String(MTOPTION.GAME_EXE));
			}

			if(!Directory::Exists(path)){
				Directory::CreateDirectory(path);
			}

			if(run_type == RT_VS){
				if(ListView == LV_BLIND){
					file = String::Format(L"vs_{0}.mtr", DateTime::Now.ToString("yyMMdd-HHmmss"));
				}
				else{
					file = String::Format(L"{0}_vs_{1}_{2}.mtr", gcnew String(MTINFO.P1_NAME), gcnew String(MTINFO.P2_NAME), DateTime::Now.ToString("yyMMdd-HHmmss"));
				}
			}
			else{
				file = String::Format(L"{0}_{1}.mtr", gcnew String(MTINFO.P1_NAME), DateTime::Now.ToString("yyMMdd-HHmmss"));
			}

			path += "\\" + file;
			bw = gcnew BinaryWriter(File::Create(path));

			WriteMessage(String::Format(L"Replay file will be created: \"{0}\"\n", file), SystemMessageColor);

			// ヘッダ
			bw->Write(header);

			switch(MTOPTION.REPLAY_VERSION){
			case 1:
				ri.VERSION = _T('3');
				break;

			case 2:
			default:
				ri.VERSION = _T('4');
				break;
			}

			bw->Write(ri.VERSION);

			// P1ネーム
			len = (BYTE)_tcslen(MTINFO.P1_NAME);
			bw->Write(len);
			for(i = 0; i < len; i++){
				bw->Write(MTINFO.P1_NAME[i]);
			}

			// P2ネーム
			len = (BYTE)_tcslen(MTINFO.P2_NAME);
			bw->Write(len);
			for(i = 0; i < len; i++){
				bw->Write(MTINFO.P2_NAME[i]);
			}

			// 乱数シード
			bw->Write(MTINFO.SEED);

			// 各種設定
			bw->Write((BYTE)MTINFO.MAX_STAGE);
			bw->Write((BYTE)MTINFO.STAGE_SELECT);
			bw->Write((BYTE)MTINFO.ROUND);
			bw->Write((BYTE)MTINFO.TIMER);
		}
	}
	catch(IOException^ e){
		WriteMessage(String::Format(L"Error writing to replay file:\n{0}\n", e->ToString()), ErrorMessageColor);

		if(bw != nullptr){
			bw->Close();
			bw = nullptr;
		}
	}

	// 名前表示用
	int is_p1 = _tcslen(MTINFO.P1_NAME);
	int is_p2 = _tcslen(MTINFO.P2_NAME);

	// ランダムステージ用
	RandomStage(MTINFO.SEED);

	// ステージループ用
	if(MTINFO.STAGE_SELECT > MTINFO.MAX_STAGE){
		stage_loop = MTINFO.MAX_STAGE;
	}

	// 観戦パケ送信準備
	if(allow_spectator){
		AllowWatch = false;
		InputFrame = 0;

		SpectacleThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::RunSpectacle));
		SpectacleThread->Start();
	}

	// 対戦中通知
	if(run_type != RT_WATCH){
		if(MemberList[0]->STATE == MS_SEEK && run_type == RT_FREE){
			//WriteMessage(L"aiueo\n", ErrorMessageColor);
		}else{
			ChangeState((BYTE)MS_VS);
		}
	}

	try{
		ZeroMemory(&si, sizeof(STARTUPINFO));
		si.cb = sizeof(STARTUPINFO);

		// 作業ディレクトリ
		_tsplitpath_s(MTOPTION.GAME_EXE, drive, _MAX_DRIVE, buf, _MAX_DIR, NULL, 0, NULL, 0);
		//_stprintf_s(wdir, _countof(drive)+_countof(buf), _T("%s%s"), drive, buf);
		PathCombine(wdir, drive, buf);
		
		if(CreateProcess(MTOPTION.GAME_EXE, NULL, NULL, NULL, false, DEBUG_PROCESS, NULL, wdir, &si, &pi)){
			if(run_type == RT_PLAYBACK){
				WriteMessage(String::Format(L"Opening \"{0}\" for playback...\n", Path::GetFileName(ReplayFilePath)), SystemMessageColor);
			}
			else{
				WriteMessage(String::Format(L"Starting \"{0}\"...\n", Path::GetFileNameWithoutExtension(gcnew String(MTOPTION.GAME_EXE))), SystemMessageColor);
			}
		}
		else{
			WriteMessage(String::Format(L"ERROR ({0}): Could not run \"{1}\".\n", GetLastError(), gcnew String(MTOPTION.GAME_EXE)), ErrorMessageColor);
			return;
		}

		if(MTOPTION.SHOW_GAME_OPTION){
			WriteMessage(String::Format(L"[Current settings]----------------------\n"
				L"Max stages: {0} / "
				L"Random stage: {1} / "
                L"# of rounds: {2} / "
				L"Round timer: {3}\n"
				L"Carry over HP between rounds: {4}\n"
				L"-------------------------------\n"
				, MTINFO.MAX_STAGE, MTINFO.STAGE_SELECT, MTINFO.ROUND, MTINFO.TIMER, MTINFO.TEAM_ROUND_HP == true ? "ON" : "OFF"), SystemMessageColor);
		}

		// 起動待ち
		Thread::Sleep(300);

		MTINFO.PROCESS    = pi.hProcess;
		MTINFO.PROCESS_ID = pi.dwProcessId;

		while(WaitForDebugEvent(&de, INFINITE)){
			state = DBG_CONTINUE;

			switch(de.dwDebugEventCode){
			case EXCEPTION_DEBUG_EVENT:
				e_code    = de.u.Exception.ExceptionRecord.ExceptionCode;
				e_address = (DWORD)de.u.Exception.ExceptionRecord.ExceptionAddress;

				if (e_code == ERROR_NOACCESS) {
					if(MTINFO.DEBUG){
						WriteMessage(String::Format(L"ERROR_NOACCESS > {0} : {1}\n", e_code, e_address), DebugMessageColor);
					}
					state = DBG_EXCEPTION_NOT_HANDLED;
				}

				if(e_code == EXCEPTION_ACCESS_VIOLATION){
					ULONG_PTR info0 = de.u.Exception.ExceptionRecord.ExceptionInformation[0];
					ULONG_PTR info1 = de.u.Exception.ExceptionRecord.ExceptionInformation[1];

					if(MTINFO.DEBUG){
						WriteMessage(String::Format(L"EXCEPTION_ACCESS_VIOLATION > {0:X8}@{1:X8} : {2}@{3:X8}\n", e_code, e_address, info0 ? "read" : "write", info1), DebugMessageColor);
					}

					state = DBG_EXCEPTION_NOT_HANDLED;
				}

				if(e_code == EXCEPTION_BREAKPOINT){
					if(de.dwThreadId != thread_id){
						break;
					}

					switch(e_address){
					case VS_ROUND:
						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);
						c.Eax++;
						SetThreadContext(thread, &c);

						if(MTINFO.DEBUG){
							WriteMessage(L"EVENT:VS_ROUND\n", DebugMessageColor);
						}

						if(vs_end){
							num_vs++;
							vs_end = false;
						}
						break;

					case VS_ROUND_95:
						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);
						c.Edx = 0;
						SetThreadContext(thread, &c);

						if(vs_end){
							num_vs++;
							vs_end = false;
						}
						break;

					case ROUND_END:
						ReadProcessMemory(pi.hProcess, (LPVOID)ROUND_ESI, &mem, 4, NULL);

						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);
						c.Esi = mem;

						if(vs_end == false){

							// HP持ち越し  Edx:1P_ROUND  Esi:2P_ROUND  Eax:ROUND
							if(MTINFO.TEAM_ROUND_HP){
								if(c.Edx > (UINT)p1_round && c.Esi > (UINT)p2_round){
									// 相打ち
								}else{
									if(c.Edx > (UINT)p1_round){
										p1_round = c.Edx;
										ReadProcessMemory(pi.hProcess, (LPVOID)P1_HP, &MTINFO.P_HP, 4, NULL);
										MTINFO.WINNER = 0;
										SetTeamHPThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::SetTeamHP));
										SetTeamHPThread->Start();
									}
									if(c.Esi > (UINT)p2_round){
										p2_round = c.Esi;
										ReadProcessMemory(pi.hProcess, (LPVOID)P2_HP, &MTINFO.P_HP, 4, NULL);
										MTINFO.WINNER = 1;
										SetTeamHPThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::SetTeamHP));
										SetTeamHPThread->Start();
									}
								}
							}
							
							// 対戦終了時は２回飛んでくる
							if(c.Eax == c.Edx){
								p1_win++;
								vs_end = true;
							}
							if(c.Eax == c.Esi){
								p2_win++;
								vs_end = true;
							}

							if(vs_end){
								timer = 0;
								p1_round = 0;
								p2_round = 0;
							}
						}

						SetThreadContext(thread, &c);
						break;

					case ROUND_END_95:
						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);
						c.Ebx = 0;
						SetThreadContext(thread, &c);

						if(vs_end == false){
							// 対戦終了時は３回飛んでくる
							ReadProcessMemory(pi.hProcess, (LPVOID)P1_WIN_95, &mem, 4, NULL);
							if(mem == 2){
								p1_win++;
								vs_end = true;
							}
							ReadProcessMemory(pi.hProcess, (LPVOID)P2_WIN_95, &mem, 4, NULL);
							if(mem == 2){
								p2_win++;
								vs_end = true;
							}
						}
						break;

					case RAND_FUNC:
						rand_count++;
						ReadProcessMemory(pi.hProcess, (LPVOID)RANDOM_SEED, &mem, 4, NULL);

						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);
						c.Eax = mem;
						SetThreadContext(thread, &c);
						break;

					case RAND_FUNC_95:
						rand_count++;
						ReadProcessMemory(pi.hProcess, (LPVOID)RANDOM_SEED_95, &mem, 4, NULL);

						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);
						c.Eax = mem;
						SetThreadContext(thread, &c);
						break;

					case STAGE_SELECT:
					case STAGE_SELECT_95:
						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);

						if(MTINFO.DEBUG){
							WriteMessage(L"EVENT:STAGE_SELECT\n", DebugMessageColor);
						}

						if(MTINFO.RAND_SEARCH){
							stage_loop = 0;

							MTINFO.MAX_STAGE    = MTOPTION.MAX_STAGE;
							MTINFO.STAGE_SELECT = MTOPTION.STAGE_SELECT;
						}

						if(stage_loop > 0){
							i = stage_loop - 1;

							stage_loop++;

							if(stage_loop > MTINFO.STAGE_SELECT){
								stage_loop = MTINFO.MAX_STAGE;
							}
						}
						else{
							if(MTINFO.STAGE_SELECT == 0){
								i = RandomStage() % MTINFO.MAX_STAGE;
							}
							else{
								i = MTINFO.STAGE_SELECT - 1;
							}
						}

						if(e_address == STAGE_SELECT){
							c.Eax = i;
						}
						else{
							c.Ecx = i;
						}

						SetThreadContext(thread, &c);
						break;

					case SINGLE_CONTROL_HOOK:
						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);
						c.Ecx = 0;
						SetThreadContext(thread, &c);
						break;

					case STORY_KEY:
					case VS_P2_KEY:
						input_count++;

					case VS_P1_KEY:
						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);

						if(run_type == RT_VS){
							if(e_address == STORY_KEY){
								c.Eax = LocalInput((UINT16)c.Eax);
								c.Eax |= RemoteInput();
							}
							else if((e_address == VS_P1_KEY && MTINFO.CONTROL == 0) || (e_address == VS_P2_KEY && MTINFO.CONTROL == 1)){
								c.Eax = LocalInput((UINT16)c.Eax);
							}
							else{
								c.Eax = RemoteInput();
							}
						}
						else if(run_type == RT_WATCH && WaitingWatch > 0){
							// 観戦バッファから読み込み
							c.Eax = WatchHistory[WatchFrame % WatchHistory->Length];

							if(c.Eax == 0xFFFF){
								Monitor::Enter(WatchHistory);
								try{
									WaitingWatch = 2;
									Monitor::Wait(WatchHistory, TIME_OUT*2);
								}
								finally{
									Monitor::Exit(WatchHistory);
								}

								c.Eax = WatchHistory[WatchFrame % WatchHistory->Length];

								if(c.Eax == 0xFFFF && WaitingWatch == 2){
									WriteMessage(L"Stopped spectating due to timeout.\n", ErrorMessageColor);
									QuitWatch(true);
								}
							}

							Monitor::Enter(WatchHistory);
							try{
								WatchHistory[WatchFrame % WatchHistory->Length] = 0xFFFF;
								WatchFrame++;
							}
							finally{
								Monitor::Exit(WatchHistory);
							}
						}
						else if(run_type == RT_PLAYBACK){
							c.Eax = ReadReplayData(br, ri);
						}
						else if(run_type == RT_FREE && sim_delay > 0){
							// ディレイシミュレート
							if(e_address != VS_P2_KEY){
								sim_que.push_back((UINT16)c.Eax);
								c.Eax = sim_que.front();
								sim_que.pop_front();
							}else{
								sim_que_p2.push_back((UINT16)c.Eax);
								c.Eax = sim_que_p2.front();
								sim_que_p2.pop_front();
							}
						}

						if(record_replay || allow_spectator){
							RecordInput((UINT16)c.Eax, bw, ri, allow_spectator);
						}

						// メモリに書き込み
						if(e_address == VS_P2_KEY){
							WriteProcessMemory(pi.hProcess, (LPVOID)P2_INPUT, &c.Eax, 4, NULL);
						}
						else{
							WriteProcessMemory(pi.hProcess, (LPVOID)P1_INPUT, &c.Eax, 4, NULL);
						}

						SetThreadContext(thread, &c);
						break;

					case UNCHECK_JOYSTICK_95:
						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);
						c.Eax = 0;
						SetThreadContext(thread, &c);
						break;

					case STORY_P2_KEY_95:
					case VS_P2_KEY_95:
						input_count++;

					case STORY_P1_KEY_95:
					case VS_P1_KEY_95:
						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);

						if(e_address == STORY_P1_KEY_95){
							ReadProcessMemory(pi.hProcess, (LPVOID)INPUT_COUNTER_95, &mem, 4, NULL);
							c.Ecx = mem;
						}
						else if(e_address == STORY_P2_KEY_95){
							ReadProcessMemory(pi.hProcess, (LPVOID)INPUT_COUNTER_95, &mem, 4, NULL);
							c.Edx = mem;
						}

						// キー入力あれこれ 95Ver
						if(run_type == RT_VS){
							if((e_address == STORY_P1_KEY_95 && MTINFO.CONTROL == 0) || (e_address == STORY_P2_KEY_95 && MTINFO.CONTROL == 1) ||
								(e_address == VS_P1_KEY_95 && MTINFO.CONTROL == 0) || (e_address == VS_P2_KEY_95 && MTINFO.CONTROL == 1)){
								c.Eax = LocalInput((UINT16)c.Eax);
							}
							else{
								c.Eax = RemoteInput();
							}
						}
						else if(run_type == RT_WATCH && WaitingWatch > 0){
							// 観戦バッファから読み込み
							c.Eax = WatchHistory[WatchFrame % WatchHistory->Length];

							if(c.Eax == 0xFFFF){
								Monitor::Enter(WatchHistory);
								try{
									WaitingWatch = 2;
									Monitor::Wait(WatchHistory, TIME_OUT*2);
								}
								finally{
									Monitor::Exit(WatchHistory);
								}

								c.Eax = WatchHistory[WatchFrame % WatchHistory->Length];

								if(c.Eax == 0xFFFF && WaitingWatch == 2){
									WriteMessage(L"Stopped spectating due to timeout.\n", ErrorMessageColor);
									QuitWatch(true);
								}
							}

							Monitor::Enter(WatchHistory);
							try{
								WatchHistory[WatchFrame % WatchHistory->Length] = 0xFFFF;
								WatchFrame++;
							}
							finally{
								Monitor::Exit(WatchHistory);
							}
						}
						else if(run_type == RT_PLAYBACK){
							c.Eax = ReadReplayData(br, ri);
						}
						else if(run_type == RT_FREE && sim_delay > 0){
							// 2P入力のシミュレートはしない
							
							if(e_address != STORY_P2_KEY_95 && e_address != VS_P2_KEY_95){
								sim_que.push_back((UINT16)c.Eax);
								c.Eax = sim_que.front();
								sim_que.pop_front();
							}
							
						}

						if(record_replay || allow_spectator){
							RecordInput((UINT16)c.Eax, bw, ri, allow_spectator);
						}

						if(e_address == VS_P1_KEY_95){
							WriteProcessMemory(pi.hProcess, (LPVOID)P1_INPUT_95, &c.Eax, 4, NULL);
						}
						else if(e_address == VS_P2_KEY_95){
							WriteProcessMemory(pi.hProcess, (LPVOID)P2_INPUT_95, &c.Eax, 4, NULL);
						}

						SetThreadContext(thread, &c);
						break;

					case FRAME_RATE:
					case FRAME_RATE_95:
						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);
						c.Esi = c.Eax;
						SetThreadContext(thread, &c);

						blt_count++;
						now_time = timeGetTime();

						if(now_time - last_time >= 1000){
							last_time = now_time;

							append_cap = 0;
							_tcscpy_s(MTINFO.TITLE, MTINFO.ORIGINAL_TITLE);

							if(MTOPTION.DISPLAY_NAME){
								if(is_p1 == 0 && is_p2 == 0){
									append_cap = _stprintf_s(MTINFO.TITLE, _T("%s [Free Play]"), MTINFO.TITLE); //fixme: hard translation: 野試合中
								}
								else if(is_p2 == 0){
									append_cap = _stprintf_s(MTINFO.TITLE, _T("%s [%s]"), MTINFO.TITLE, MTINFO.P1_NAME);
								}
								else{
									append_cap = _stprintf_s(MTINFO.TITLE, _T("%s [%s vs %s]"), MTINFO.TITLE, MTINFO.P1_NAME, MTINFO.P2_NAME);
								}
							}
							if(MTOPTION.DISPLAY_VERSUS){
								if(MTOPTION.SHOW_RESULT){
									append_cap = _stprintf_s(MTINFO.TITLE, _T("%s  Match: %d (%d - %d)"), MTINFO.TITLE, num_vs, p1_win, p2_win);
								}else{
									append_cap = _stprintf_s(MTINFO.TITLE, _T("%s  Match: %d"), MTINFO.TITLE, num_vs);
								}
							}
							if(MTOPTION.DISPLAY_FRAMERATE){
								append_cap = _stprintf_s(MTINFO.TITLE, _T("%s  FPS: %3d(%d％)"), MTINFO.TITLE, blt_count, input_count);
							}
							if(MTOPTION.DISPLAY_RAND){
								append_cap = _stprintf_s(MTINFO.TITLE, _T("%s  Rand: %d"), MTINFO.TITLE, rand_count);
							}

							blt_count   = 0;
							input_count = 0;
							rand_count  = 0;

							if(append_cap > 0 || last_cap > 0 || MTINFO.HWND == NULL){
								last_cap = append_cap;

								Thread^ cap = gcnew Thread(gcnew ThreadStart(&SetCaption));
								cap->Start();
							}
						}
						break;

					case BGM_VOLUME:
					case BGM_VOLUME_95:
						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);
						c.Edx = MTINFO.VOLUME[MTOPTION.BGM_VOLUME/5];
						SetThreadContext(thread, &c);
						break;

					case SE_VOLUME:
					case SE_VOLUME_95:
						c.ContextFlags = CONTEXT_INTEGER;
						GetThreadContext(thread, &c);
						c.Edx = MTINFO.VOLUME[MTOPTION.SE_VOLUME/5];
						SetThreadContext(thread, &c);
						break;
					}

					// デバッグ:イベント表示
					if(MTINFO.DEBUG){
						/*
						if (e_address != VS_P1_KEY && e_address != RAND_FUNC && e_address != VS_P2_KEY
							 && e_address != FRAME_RATE && e_address != SE_VOLUME && e_address != ROUND_END
							 && e_address != STAGE_SELECT && e_address != VS_ROUND) {
							int nValue = e_address;
							char pszText[32];
							_itoa_s(nValue, pszText, 32 * sizeof(char), 16);
							WriteMessage(String::Format(L"EVENT:{0}\n", gcnew String(pszText)), DebugMessageColor);
						}
						*/
						// 解析用
						if (e_address != VS_P1_KEY && e_address != RAND_FUNC && e_address != VS_P2_KEY
							 && e_address != FRAME_RATE && e_address != SE_VOLUME && e_address != VS_ROUND) {
							int nValue = e_address;
							char pszText[32];
							_itoa_s(nValue, pszText, 32 * sizeof(char), 16);
							WriteMessage(String::Format(L"EVENT: {0}\n", gcnew String(pszText)), DebugMessageColor);
						}
						
					}
				}
				break;

			case CREATE_THREAD_DEBUG_EVENT:
				if(MTINFO.DEBUG){
					WriteMessage(L"CREATE_THREAD_DEBUG_EVENT\n", DebugMessageColor);
				}
				break;

			case CREATE_PROCESS_DEBUG_EVENT:
				if(MTINFO.DEBUG){
					WriteMessage(L"CREATE_PROCESS_DEBUG_EVENT\n", DebugMessageColor);
					WriteMessage(String::Format(L"{0}\n", MTINFO.SEED), DebugMessageColor);
				}

				thread    = de.u.CreateProcessInfo.hThread;
				thread_id = de.dwThreadId;

				// ここから書き換えゾーン
				if(MTINFO.KGT2K){
					// 2nd.用
					mem = MTOPTION.HIT_JUDGE;
					WriteProcessMemory(pi.hProcess, (LPVOID)HIT_JUDGE, &mem, 4, NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)HIT_JUDGE_SET, HIT_JUDGE_SET_CODE, sizeof(HIT_JUDGE_SET_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)RANDOM_SEED, &MTINFO.SEED, 4, NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)STAGE_SELECT, STAGE_SELECT_CODE, sizeof(STAGE_SELECT_CODE), NULL);

					WriteProcessMemory(pi.hProcess, (LPVOID)ROUND_SET, ROUND_SET_CODE, sizeof(ROUND_SET_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)TIMER_SET, TIMER_SET_CODE, sizeof(TIMER_SET_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)DEFAULT_ROUND, &MTINFO.ROUND, 4, NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)DEFAULT_TIMER, &MTINFO.TIMER, 4, NULL);

					// チームプレイラウンド数
					WriteProcessMemory(pi.hProcess, (LPVOID)TEAM_ROUND_SET, TEAM_ROUND_SET_CODE, sizeof(TEAM_ROUND_SET_CODE), NULL);
					if(MTINFO.ROUND > 4) {
						WriteProcessMemory(pi.hProcess, (LPVOID)TEAM_ROUND, &MAX_TEAM_ROUND, 4, NULL);
					}else{
						WriteProcessMemory(pi.hProcess, (LPVOID)TEAM_ROUND, &MTINFO.ROUND, 4, NULL);
					}


					// タイトルバー表示用
					WriteProcessMemory(pi.hProcess, (LPVOID)VS_ROUND, VS_ROUND_CODE, sizeof(VS_ROUND_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)ROUND_END, ROUND_END_CODE, sizeof(ROUND_END_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)FRAME_RATE, FRAME_RATE_CODE, sizeof(FRAME_RATE_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)RAND_FUNC, RAND_FUNC_CODE, sizeof(RAND_FUNC_CODE), NULL);

					// 音量
					WriteProcessMemory(pi.hProcess, (LPVOID)VOLUME_SET_1, VOLUME_SET_1_CODE, sizeof(VOLUME_SET_1_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)VOLUME_SET_2, VOLUME_SET_2_CODE, sizeof(VOLUME_SET_2_CODE), NULL);

					// 熱帯中は常に1P入力
					if(run_type == RT_VS){
						WriteProcessMemory(pi.hProcess, (LPVOID)SINGLE_CONTROL_HOOK, SINGLE_CONTROL_HOOK_CODE, sizeof(SINGLE_CONTROL_HOOK_CODE), NULL);
						WriteProcessMemory(pi.hProcess, (LPVOID)VS_CONTROL_HOOK, VS_CONTROL_HOOK_CODE, sizeof(VS_CONTROL_HOOK_CODE), NULL);
					}

					// キー情報を取得
					WriteProcessMemory(pi.hProcess, (LPVOID)STORY_KEY, STORY_KEY_CODE, sizeof(STORY_KEY_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)VS_P1_KEY, VS_P1_KEY_CODE, sizeof(VS_P1_KEY_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)VS_P2_KEY, VS_P2_KEY_CODE, sizeof(VS_P2_KEY_CODE), NULL);

					// ウィンドウサイズを640x480に
					if(MTOPTION.CHANGE_WINDOW_SIZE){
						TCHAR val[32];

						//_stprintf_s(buf, _T("%sgame.ini"), wdir);
						PathCombine(buf, wdir, L"game.ini");

						if(File::Exists(gcnew String(buf))){
							_itot_s(640, val, 10);
							WritePrivateProfileString(_T("GamePlay"), _T("GameWindowSize_x"), val, buf);
							_itot_s(480, val, 10);
							WritePrivateProfileString(_T("GamePlay"), _T("GameWindowSize_y"), val, buf);
						}
					}
				}
				else{
					// 95用
					mem = MTOPTION.HIT_JUDGE;
					WriteProcessMemory(pi.hProcess, (LPVOID)HIT_JUDGE_95, &mem, 4, NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)HIT_JUDGE_SET_95, HIT_JUDGE_SET_95_CODE, sizeof(HIT_JUDGE_SET_95_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)RANDOM_SEED_95, &MTINFO.SEED, 4, NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)STAGE_SELECT_95, STAGE_SELECT_95_CODE, sizeof(STAGE_SELECT_95_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)TIMER_SET_95, TIMER_SET_95_CODE, sizeof(TIMER_SET_95_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)DEFAULT_TIMER_95, &MTINFO.TIMER, 4, NULL);

					// タイトルバー表示用
					WriteProcessMemory(pi.hProcess, (LPVOID)VS_ROUND_95, VS_ROUND_95_CODE, sizeof(VS_ROUND_95_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)ROUND_END_95, ROUND_END_95_CODE, sizeof(ROUND_END_95_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)FRAME_RATE_95, FRAME_RATE_95_CODE, sizeof(FRAME_RATE_95_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)RAND_FUNC_95, RAND_FUNC_95_CODE, sizeof(RAND_FUNC_95_CODE), NULL);

					// 音量
					WriteProcessMemory(pi.hProcess, (LPVOID)VOLUME_SET_1_95, VOLUME_SET_1_95_CODE, sizeof(VOLUME_SET_1_95_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)VOLUME_SET_2_95, VOLUME_SET_2_95_CODE, sizeof(VOLUME_SET_2_95_CODE), NULL);

					// JoyStickはエラー起こすのでオフにする
					WriteProcessMemory(pi.hProcess, (LPVOID)UNCHECK_JOYSTICK_95, UNCHECK_JOYSTICK_95_CODE, sizeof(UNCHECK_JOYSTICK_95_CODE), NULL);

					// 熱帯中は常に1P入力
					if(run_type == RT_VS){
						WriteProcessMemory(pi.hProcess, (LPVOID)CONTROL_HOOK1_95, CONTROL_HOOK1_95_CODE, sizeof(CONTROL_HOOK1_95_CODE), NULL);
						WriteProcessMemory(pi.hProcess, (LPVOID)CONTROL_HOOK2_95, CONTROL_HOOK2_95_CODE, sizeof(CONTROL_HOOK2_95_CODE), NULL);
					}

					// キー情報を取得
					WriteProcessMemory(pi.hProcess, (LPVOID)STORY_P1_KEY_95, STORY_P1_KEY_95_CODE, sizeof(STORY_P1_KEY_95_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)STORY_P2_KEY_95, STORY_P2_KEY_95_CODE, sizeof(STORY_P2_KEY_95_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)VS_P1_KEY_95, VS_P1_KEY_95_CODE, sizeof(VS_P1_KEY_95_CODE), NULL);
					WriteProcessMemory(pi.hProcess, (LPVOID)VS_P2_KEY_95, VS_P2_KEY_95_CODE, sizeof(VS_P2_KEY_95_CODE), NULL);
				}

				FlushInstructionCache(pi.hProcess, NULL, 0);
				MTINFO.INITIALIZED = true;
				break;

			case EXIT_THREAD_DEBUG_EVENT:
				if(MTINFO.DEBUG){
					WriteMessage(L"EXIT_THREAD_DEBUG_EVENT\n", DebugMessageColor);
				}
				break;

			case EXIT_PROCESS_DEBUG_EVENT:
				if(MTINFO.DEBUG){
					WriteMessage(L"EXIT_PROCESS_DEBUG_EVENT\n", DebugMessageColor);
				}
				break;

			case LOAD_DLL_DEBUG_EVENT:
				if(MTINFO.DEBUG){
					TCHAR buf[MAX_PATH];
					LONG_PTR data;

					ReadProcessMemory(pi.hProcess, de.u.LoadDll.lpImageName, &data, sizeof(LONG_PTR), NULL);
					ReadProcessMemory(pi.hProcess, (LPVOID)data, buf, sizeof(TCHAR)*MAX_PATH, NULL);

					WriteMessage(String::Format(L"LOAD_DLL_DEBUG_EVENT > \"{0}\"\n", gcnew String(buf)), DebugMessageColor);
				}
				break;

			case UNLOAD_DLL_DEBUG_EVENT:
				if(MTINFO.DEBUG){
					WriteMessage(L"UNLOAD_DLL_DEBUG_EVENT\n", DebugMessageColor);
				}
				break;

			case OUTPUT_DEBUG_STRING_EVENT:
				if(MTINFO.DEBUG){
					int size = de.u.DebugString.nDebugStringLength;
					char *str = (char *)malloc(size);
					ReadProcessMemory(pi.hProcess, de.u.DebugString.lpDebugStringData, str, size, NULL);

					if(str[size-2] == '\n'){
						str[size-2] = '\0';
					}

					WriteMessage(String::Format(L"OUTPUT_DEBUG_STRING_EVENT > {0}\n", gcnew String(str)), DebugMessageColor);
					free(str);
				}
				break;

			case RIP_EVENT:
				if(MTINFO.DEBUG){
					WriteMessage(L"RIP_EVENT\n", DebugMessageColor);
				}
				break;
			}

			ContinueDebugEvent(de.dwProcessId, de.dwThreadId, state);
			if(de.dwDebugEventCode == EXIT_PROCESS_DEBUG_EVENT) break;
		}
	}
	catch(Exception^ e){
		WriteMessage(e->ToString() + L"\n", ErrorMessageColor);
	}
	finally{
		AllowWatch = false;
		InputFrame = 0;

		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
		

		if(br != nullptr){
			br->Close();
		}
		if(bw != nullptr){
			bw->Write(ri.KEY[0]);
			bw->Write(ri.COUNT[0]);
			bw->Write((UINT16)(ri.KEY[1] | 0x0800));
			bw->Write(ri.COUNT[1]);

			bw->Close();
		}
		

		if(MTINFO.INITIALIZED){
			if(WaitingWatch > 0){
				WaitingWatch = 0;
				WriteMessage(L"Stopped watching.\n", SystemMessageColor);
			}
			else if(_tcslen(MTINFO.ORIGINAL_TITLE) > 0){
				WriteMessage(String::Format(L"Ended \"{0}\".\n", gcnew String(MTINFO.ORIGINAL_TITLE)), SystemMessageColor);

				if(run_type == RT_VS){
					if(MTINFO.CONTROL == 1){
						i = p1_win;
						p1_win = p2_win;
						p2_win = i;
					}
					WriteTime(0, SystemMessageColor);
					WriteMessage(String::Format(L"Score: {0} matches, {1} wins (P1), {2} wins (P2)\n", num_vs, p1_win, p2_win), SecretColor);
				}
			}
			else{
				WriteMessage(L"Ended the game.\n", SystemMessageColor);
			}
		}

		if(NetVS != nullptr && NetVS->SEQUENCE == VS_DATA){
			NetVS->SEQUENCE = VS_END;
			UDP->Send(gcnew array<BYTE>{ PH_VS_END }, 1, NetVS->IP_EP);

			// ロック開放待ち
			Monitor::Enter(NetVS->LOCAL);
			Monitor::Exit(NetVS->LOCAL);
			Monitor::Enter(NetVS->REMOTE);
			Monitor::Exit(NetVS->REMOTE);

			delete NetVS;
			NetVS = nullptr;
		}

		if(allow_spectator){
			AllowWatch = false;
			SpectacleThread->Join();
		}

		if(AfterCloseUDP){
			AfterCloseUDP = false;
			UDP->Close();
		}
		else if(run_type == RT_WATCH){
			QuitWatch(true);
		}
		else{
			// 対戦終了を通知
			if(MTOPTION.AFTER_REST && run_type == RT_VS){
				ChangeState((BYTE)MS_REST);
			}
			else{
				ChangeState((BYTE)MS_FREE);
			}
		}

		MTINFO.INITIALIZED = false;
		MTINFO.SHOW_TOP    = false;
		MTINFO.PROCESS     = NULL;
		MTINFO.PROCESS_ID  = 0;
		MTINFO.HWND        = NULL;
		ZeroMemory(MTINFO.ORIGINAL_TITLE, sizeof(MTINFO.ORIGINAL_TITLE));
		ZeroMemory(MTINFO.TITLE, sizeof(MTINFO.TITLE));

		if(IsFormClosing){
			this->Close();
		}
	}
}

void MainForm::RunVersus()
{
	array<BYTE>^ send = gcnew array<BYTE>(7);

	try{
		// 対戦要求
		send[0] = PH_REQ_VS;
		Array::Copy(BitConverter::GetBytes(MemberList[0]->ID), 0, send, 1, 2);
		Array::Copy(BitConverter::GetBytes((INT32)(Path::GetFileNameWithoutExtension(gcnew String(MTOPTION.GAME_EXE))->GetHashCode())), 0, send, 3, 4);
		UDP->Send(send, 7, NetVS->IP_EP);

		NetVS->SLEEPING = true;
		try{
			Thread::Sleep(TIME_OUT);
		}
		catch(ThreadInterruptedException^){
		}
		NetVS->SLEEPING = false;

		if(NetVS->SEQUENCE != VS_PING){
			if(NetVS->SEQUENCE != VS_ERROR){
				WriteMessage(L"ERROR: There was no response from the opponent.\n", ErrorMessageColor);
			}
			return;
		}

		// PINGで帯域調査
		send[0] = PH_REQ_VS_PING;

		for(BYTE i = 0; i < 5; i++){
			NetVS->PING[i] = timeGetTime();
			send[1] = i;
			UDP->Send(send, 2, NetVS->IP_EP);

			Thread::Sleep(10);
		}

		if(NetVS->SEQUENCE == VS_PING){
			NetVS->SLEEPING = true;
			try{
				// 最低でも１秒間にパケ４つは欲しいところ
				Thread::Sleep(1000);
			}
			catch(ThreadInterruptedException^){
			}
			NetVS->SLEEPING = false;
		}

		if(NetVS->SEQUENCE != VS_SETTING){
			WriteMessage(L"ERROR: The connection to the opponent is unstable.\n", ErrorMessageColor);
			return;
		}

		// DELAYの設定
		send[0] = PH_REQ_VS_SETTING;

		if(MTOPTION.DELAY == 0){
			// オート設定
			int d = 0, c = 0;

			for(int i = 0; i < 5; i++){
				if(NetVS->PONG[i] > 0){
					d += NetVS->PONG[i] - NetVS->PING[i];
					c++;

					if(c == 4) break;
				}
			}

			if(c < 4){
				WriteMessage(L"ERROR: Could not determine the delay from the opponent's ping.\n", ErrorMessageColor);
				return;
			}

			c = d/40 + 2;  // Delay = PING/10 + 2

			if(c > 12) c = 12;

			NetVS->DELAY = c;
		}
		else{
			NetVS->DELAY = MTOPTION.DELAY;
		}

		send[1] = (BYTE)NetVS->DELAY;
		UDP->Send(send, 2, NetVS->IP_EP);

		NetVS->SLEEPING = true;
		try{
			Thread::Sleep(TIME_OUT);
		}
		catch(ThreadInterruptedException^){
		}
		NetVS->SLEEPING = false;

		if(NetVS->SEQUENCE != VS_STANDBY){
			WriteMessage(L"ERROR: The match initialization process could not be completed.\n", ErrorMessageColor);
			return;
		}

		NetVS->SEQUENCE = VS_DATA;

		// 対戦開始
		WriteMessage(String::Format(L"Match starting! (Delay: {0})\n", NetVS->DELAY), SystemMessageColor);

		GameThread = gcnew Thread(gcnew ParameterizedThreadStart(this, &MainForm::RunGame));
		GameThread->Start((UINT)RT_VS);
	}
	finally{
		if(NetVS->SEQUENCE < VS_DATA || NetVS->SEQUENCE == VS_ERROR){
			MemberList[0]->STATE = MS_FREE;

			delete NetVS;
			NetVS = nullptr;
		}
	}
}

void MainForm::RunSpectacle()
{
	int i, d;
	UINT32 frame = 0, s_frame;

	// 開始合図
	array<BYTE>^ send = gcnew array<BYTE>(14);
	send[0] = PH_RES_WATCH;
	send[1] = 0;
	Array::Copy(BitConverter::GetBytes(P1ID), 0, send, 2, 2);
	Array::Copy(BitConverter::GetBytes(P2ID), 0, send, 4, 2);
	Array::Copy(BitConverter::GetBytes(MTINFO.SEED), 0, send, 6, 4);
	send[10] = MTINFO.MAX_STAGE;
	send[11] = MTINFO.STAGE_SELECT;
	send[12] = MTINFO.ROUND;
	send[13] = MTINFO.TIMER;

	Monitor::Enter(InputHistory);
	try{
		for(i = 0; i < SpectatorList->Count; i++){
			UDP->BeginSend(send, send->Length, SpectatorList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
		}
	}
	finally{
		Monitor::Exit(InputHistory);
	}

	Thread::Sleep(100);

	// データ送信準備
	send = gcnew array<BYTE>(45){ PH_WATCH_DATA };

	// 準備完了
	AllowWatch = true;

	// データ送信
	while(AllowWatch){
		Monitor::Enter(InputHistory);
		try{
			frame = InputFrame;

			for(i = 0; i < SpectatorList->Count; i++){
				s_frame = SpectatorList[i]->FRAME;
/*
				// データは既にバッファからなくなってる
				if(frame > s_frame && (frame - s_frame) >= (UINT)InputHistory->Length - 20){
					if(MTINFO.DEBUG) WriteMessage(String::Format(L"観戦者の追い出し > {0} / {1}\n", SpectatorList[i]->ID, SpectatorList->Count), DebugMessageColor);

					send[0] = PH_WATCH_END;
					Array::Copy(BitConverter::GetBytes(SpectatorList[i]->ID), 0, send, 1, 2);
					UDP->BeginSend(send, 3, SpectatorList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);

					SpectatorList->RemoveAt(i);
					i--;

					send[0] = PH_WATCH_DATA;
					continue;
				}
*/
				// 5フレームごとに10フレーム分送る
				if(s_frame + 20 < frame){
					Array::Copy(BitConverter::GetBytes(s_frame), 0, send, 1, 4);

					for(d = 0; d < 20; d++){
						Array::Copy(BitConverter::GetBytes(InputHistory[(s_frame + d) % InputHistory->Length]), 0, send, 5 + d*2, 2);
					}

					UDP->BeginSend(send, send->Length, SpectatorList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);

					// 0frameの時は念のため２個送信
					if(s_frame == 0){
						UDP->BeginSend(send, send->Length, SpectatorList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
					}

					SpectatorList[i]->FRAME += 10;
				}
			}
		}
		finally{
			Monitor::Exit(InputHistory);
		}

		// ちょっとだけ休憩
		Thread::Sleep(20);
	}

	// 終了合図
	send[0] = PH_WATCH_END;

	Monitor::Enter(InputHistory);
	try{
		for(i = 0; i < SpectatorList->Count; i++){
			Array::Copy(BitConverter::GetBytes(SpectatorList[i]->ID), 0, send, 1, 2);
			UDP->BeginSend(send, 3, SpectatorList[i]->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
		}

		SpectatorList->Clear();
	}
	finally{
		Monitor::Exit(InputHistory);
	}
}

UINT16 MainForm::LocalInput(UINT16 eax)
{
	// 左右同時押し禁止 if((eax & 3) == 3) eax ^= 2
	if((eax & 0x0003) == 0x0003){
		eax &= 0xFFFD;
	}
	
	Monitor::Enter(NetVS->LOCAL);
	try{
		NetVS->LOCAL[(NetVS->L_READ + NetVS->DELAY) % NetVS->LOCAL->Length] = eax;
		eax = NetVS->LOCAL[NetVS->L_READ];

		bool send = true;

		if(NetVS->INTERVAL > 0){
			if(NetVS->INTERVAL == 1){
				// 間隔１(定期休憩モード)
				if((NetVS->L_FRAME % NetVS->INTERVAL2) == (NetVS->INTERVAL2 - 1)){
					send = false;
				}
			}
			else{
				// 間隔２以上
				if((NetVS->L_FRAME % NetVS->INTERVAL) != 0){
					send = false;
				}
			}
		}

		if(send){
			// 送信開始
			Array::Copy(BitConverter::GetBytes(NetVS->L_FRAME), 0, NetVS->SEND, 1, 4);

			UINT i;
			for(i = 0; i <= NetVS->DELAY; i++){
				Array::Copy(BitConverter::GetBytes(NetVS->LOCAL[(NetVS->L_READ + i) % NetVS->LOCAL->Length]), 0, NetVS->SEND, 5 + i*2, 2);
			}

			UDP->BeginSend(NetVS->SEND, 5 + i*2, NetVS->IP_EP, gcnew AsyncCallback(SendPackets), UDP);
		}

		NetVS->L_FRAME++;
		NetVS->L_READ++;
		NetVS->L_READ %= NetVS->LOCAL->Length;
	}
	finally{
		Monitor::Exit(NetVS->LOCAL);
	}

	return eax;
}

UINT16 MainForm::RemoteInput()
{
	if(NetVS->SEQUENCE != VS_DATA) return 0;

	UINT16 eax;

	eax = NetVS->REMOTE[NetVS->R_READ];

	// パケ来てない
	if(eax == 0xFFFF){
		Monitor::Enter(NetVS->REMOTE);
		try{
			// 今来てるかも
			NetVS->WAITING = 2;
			Monitor::Wait(NetVS->REMOTE, NetVS->DELAY*10);
			eax = NetVS->REMOTE[NetVS->R_READ];
		}
		finally{
			Monitor::Exit(NetVS->REMOTE);
		}
	}

	// ロスった？
	if(eax == 0xFFFF){
		NetVS->WAITING = 1;

		array<BYTE>^ send = gcnew array<BYTE>(5){ PH_REQ_VS_DATA };
		Array::Copy(BitConverter::GetBytes(NetVS->R_FRAME), 0, send, 1, 4);

		UINT i = 0;

		while(NetVS->SEQUENCE == VS_DATA){
			UDP->BeginSend(send, send->Length, NetVS->IP_EP, gcnew AsyncCallback(SendPackets), UDP);

			Monitor::Enter(NetVS->REMOTE);
			try{
				NetVS->WAITING = 2;
				Monitor::Wait(NetVS->REMOTE, NetVS->DELAY*10);
			}
			finally{
				Monitor::Exit(NetVS->REMOTE);
			}

			if(NetVS->WAITING == 2){
				NetVS->WAITING = 1;
				if(++i > 100){
					NetVS->SEQUENCE = VS_TIMEOUT;
				}
				continue;
			}

			eax = NetVS->REMOTE[NetVS->R_READ];

			if(eax != 0xFFFF){
				break;
			}
			else{
				i = 0;
				// ここがかの有名なラグの生産地です
				// Delay*10 / 2   ディレイの半フレーム分は待機してもよさそう？
				Thread::Sleep(NetVS->DELAY*5);
			}
		}

		if(eax == 0xFFFF && NetVS->SEQUENCE == VS_TIMEOUT){
			WriteMessage(L"The match ended due to a timeout.\n", ErrorMessageColor);
			if(MTINFO.DEBUG){
				WriteMessage(String::Format(L"Frame > L: {0} / R: {1} (delay: {2})\n", NetVS->L_FRAME, NetVS->R_FRAME, NetVS->DELAY), DebugMessageColor);
			}

			QuitGame();
			return 0;
		}

		NetVS->WAITING = 0;
	}

	if(NetVS->SEQUENCE != VS_DATA) return 0;

	if((eax & 0x0003) == 0x0003){
		WriteMessage(L"Received illegal packet: press left and right simultaneously\n", ErrorMessageColor); //fixme: dubious translation: 不正パケットの受信 > 左右同時押し
		if(MTINFO.DEBUG){
			WriteMessage(String::Format(L"IP: {0}\n", NetVS->IP_EP->Address), DebugMessageColor);
		}

		QuitGame();
		return 0xFFFF;
	}

	Monitor::Enter(NetVS->REMOTE);
	try{
		NetVS->REMOTE[NetVS->R_READ] = 0xFFFF;

		NetVS->R_FRAME++;
		NetVS->R_READ++;
		NetVS->R_READ %= NetVS->REMOTE->Length;
	}
	finally{
		Monitor::Exit(NetVS->REMOTE);
	}

	return eax;
}

UINT16 MainForm::ReadReplayData(BinaryReader^ br, REPLAY_INFO& ri)
{
	if(br == nullptr){
		return 0;
	}

	UINT16 eax;

	try{
		if(ri.VERSION == _T('1') || ri.VERSION == _T('3')){
			eax = br->ReadUInt16();
		}
		else{
			// リプレイファイルのRLEデコード
			if(ri.COUNT[ri.CONTROL] == 0){
				REPLAY_DATA rd;
				bool ctrl;

				if(ri.DEQUE[ri.CONTROL].size() > 0){
					// キューにデータあり
					rd = ri.DEQUE[ri.CONTROL].front();
					ri.DEQUE[ri.CONTROL].pop_front();
				}
				else{
					rd.KEY   = br->ReadUInt16();
					rd.COUNT = br->ReadByte();
					ctrl     = (rd.KEY & 0x0800) > 0 ? true : false;

					while(ctrl != ri.CONTROL){
						// キューに退避
						ri.DEQUE[ctrl].push_back(rd);

						// 再読み込み
						rd.KEY   = br->ReadUInt16();
						rd.COUNT = br->ReadByte();
						ctrl     = (rd.KEY & 0x0800) > 0 ? true : false;
					}
				}

				ri.KEY[ri.CONTROL]   = rd.KEY & 0x07FF;
				ri.COUNT[ri.CONTROL] = rd.COUNT;
			}
			else{
				ri.COUNT[ri.CONTROL]--;
			}

			eax = ri.KEY[ri.CONTROL];

			ri.CONTROL ^= 1;
		}
	}
	catch(EndOfStreamException^){
		WriteMessage(L"End of replay file.\n", SystemMessageColor);

		br->Close();
		br = nullptr;

		QuitGame();
		return 0;
	}
	catch(ObjectDisposedException^){
		br = nullptr;

		return 0;
	}

	return eax;
}

void MainForm::RecordInput(UINT16 eax, BinaryWriter^ bw, REPLAY_INFO& ri, bool watch)
{
	// リプレイファイルの記録
	if(bw != nullptr){
		if(ri.VERSION == _T('3')){
			bw->Write(eax);
		}
		else{
			// RLE
			if(ri.KEY[ri.CONTROL] == 0xFFFF){
				// 初回
				ri.KEY[ri.CONTROL] = eax;
			}
			else{
				if(eax == ri.KEY[ri.CONTROL]){
					// 一周してきた
					if(ri.COUNT[ri.CONTROL] == 0xFF){
						bw->Write((UINT16)(ri.KEY[ri.CONTROL] | ri.CONTROL << 11));
						bw->Write(ri.COUNT[ri.CONTROL]);

						ri.COUNT[ri.CONTROL] = 0;
					}
					else{
						ri.COUNT[ri.CONTROL]++;
					}
				}
				else{
					bw->Write((UINT16)(ri.KEY[ri.CONTROL] | ri.CONTROL << 11));
					bw->Write(ri.COUNT[ri.CONTROL]);

					ri.KEY[ri.CONTROL]   = eax;
					ri.COUNT[ri.CONTROL] = 0;
				}
			}

			ri.CONTROL ^= 1;
		}
	}

	// 観戦OK
	if(watch && UDP != nullptr){
		Monitor::Enter(InputHistory);
		try{
			InputHistory[InputFrame % InputHistory->Length] = eax;
			InputFrame++;
		}
		finally{
			Monitor::Exit(InputHistory);
		}
	}
}
void MainForm::RunAutoRest() {
	// 自動休憩
	LASTINPUTINFO li;
	li.cbSize = sizeof(LASTINPUTINFO);
	DWORD te;
	int to = MTOPTION.AUTO_REST_TIME;  // タイムアウト指定時間
	AutoRestRanging = true;
	if(MTINFO.DEBUG){
		WriteMessage(String::Format(L"Auto rest thread starts in {0} minute(s)!\n", to), DebugMessageColor);
	}
	while(AutoRestRanging){
		AutoRestSleeping = true;
		try{
			Thread::Sleep(1000*1);
		}
		catch(ThreadInterruptedException^){
		}
		finally{
			AutoRestSleeping = false;
		}
		if(!AutoRestRanging) return;
		GetLastInputInfo(&li);
		te = GetTickCount();
		to = MTOPTION.AUTO_REST_TIME;
		//WriteMessage(String::Format(L"{0}秒経過\n", ((te-li.dwTime)/1000) ), DebugMessageColor);
		if(((te-li.dwTime)/1000) >= UINT(to*60)){
			// フリー状態なら休憩状態にする
			if(UDP != nullptr && MemberList[0]->STATE == MS_FREE){
				ChangeState((BYTE)MS_REST);
				WriteMessage(L"Rest mode set to ON.\n", SystemMessageColor);
			}
			AutoRestRanging = false;
			AutoRestThread = nullptr;
		}
	}
}
void MainForm::ChangeSeek() {
	if(MTOPTION.CONNECTION_TYPE == CT_FREE) return;

	if(MemberList[0]->STATE == MS_FREE){
		ChangeState((BYTE)MS_SEEK);
		WriteMessage(L"Seek mode set to ON.\n", SystemMessageColor);
		WriteTime(0, SystemMessageColor);
		WriteMessage(String::Format(L"{0} is now in seek mode.\n", MemberList[0]->NAME), SystemMessageColor);
	}
	else if(MemberList[0]->STATE == MS_SEEK){
		if(GameThread != nullptr && GameThread->IsAlive){
			ChangeState((BYTE)MS_VS);
		}else{
			ChangeState((BYTE)MS_FREE);
		}
		
		WriteMessage(L"Seek mode set to OFF.\n", SystemMessageColor);
		WriteTime(0, SystemMessageColor);
		WriteMessage(String::Format(L"{0} has left seek mode.\n", MemberList[0]->NAME), SystemMessageColor);
	}
}
void MainForm::ChangeLogWordWrap() {
	MTOPTION.LOG_WORDWRAP ^= 1;
	richTextBoxLog->WordWrap = MTOPTION.LOG_WORDWRAP;
	toolStripMenuItemWordWrap->Checked = MTOPTION.LOG_WORDWRAP;
	if(MTOPTION.LOG_WORDWRAP){
		WriteMessage(L"Text wrap set to ON.\n", SystemMessageColor);
	}else{
		WriteMessage(L"Text wrap set to OFF.\n", SystemMessageColor);
	}
}
void MainForm::ClearLog(){
	if(MessageBox::Show(L"This will remove all but the last 10 lines of the log.\nAre you sure you want to clear the log?", L"Clear Log", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::DialogResult::Yes){
	}else{
		return;
	}
	Monitor::Enter(richTextBoxLog);
	try{
		int len = richTextBoxLog->Lines->Length;	// 全体行数
		if(len > 10){
			int index = richTextBoxLog->GetFirstCharIndexFromLine(len-11);
			richTextBoxLog->SelectionStart=0;
			richTextBoxLog->Select(0, index);
			richTextBoxLog->SelectedText= L"[Deleted]\n";
		}
	}
	catch(Exception ^e){
		WriteErrorLog(e->ToString(), "SaveLog");
	}
	finally{
		Monitor::Exit(richTextBoxLog);
	}
}