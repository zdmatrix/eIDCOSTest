#pragma once


namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;

	using namespace System::Runtime::InteropServices;

	using namespace System::Windows::Forms;
	using namespace System::Security::Permissions;
	using namespace System::Management;

	using namespace System::Security::Cryptography;
	using namespace System::Security::Cryptography::X509Certificates;

	using namespace System::IO;
	
	

	/// <summary>
	/// Form1 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		const static int	P3 = 4;
		const static int	DBT_DEVICEREMOVECOMPLETE = 0x8004;
		const static int	CLA = 0;
		const static int	INS = 1;
		const static int	P1 = 2;
		const static int	P2 = 3;

		const static int	SM2SIGNDATALEN = 0x20;
		const static int	SM2SIGNDDATALEN = 0x40;
		const static int	SM2PRIKEYLEN = 0x20;
		const static int	SM2PUBKEYLEN = 0x40;
		const static int	LOOPCOUNTER = 10;
		const static int	ARRAYALLIGNMENT = 38;
		const static int	ARRAYLENGTH = 0x10;
		const static int	CERTNUM = 20;
		const static int	MAXREADER = 0x10;

		const static int	DBT_DEVICEARRIVAL = 0x8000;

		const static int	SELECT_EID_APP = 0x1000;
		const static int	SELECT_FILE = 0x1001;
		const static int	READ_LOADER_CAPACITY = 0x1002;
		const static int	READ_CONTAINER_MAX_NUM = 0x1003;
		const static int	GET_CHALLENGE = 0x1004;
		const static int	READ_FILE_INDEX = 0x1005;
		const static int	READ_CONTAINER_INDEX = 0x1006;
		const static int	READ_CONTAINER_INFO = 0x1007;
		const static int	READ_PRIVATE_CERT_RSA1024 = 0x1008;
		const static int	DATA_COMPRESS = 0x1009;
		
		HANDLE handle;

		int nReaderCounter;
		int nResponseLength;
		int nBtnClickedTimes;
		int nProcessStep;
		int nCurrentStep;

		UINT64 nTimes; 

		LONG ret;

		bool bGeneratedSM2Key;

		array<String^>^ ReaderName;
		array<String^>^ CertNames;

		String^ ErrorDescription;
		String^ SelectReader;
		String^ TextInput;
		String^ TextBoxMsg;
		String^ SignDate;
		String^ SelectCert;
		String^ SelectCertPin;
		
//		String^ RSALOADDATA;
		
		String^ ENABLETIMER;
		String^ DISENABLETIMER;
		String^ GETCYCLE;

		String^ SM2PRIKEYADD;
		String^ SM2PUBKEYADD;
		String^ SM2SIGNEDDATAADD;
		String^ ELIPTICCRUVEPAR;

		String^ GENERATESM2KEYCMD;
		String^ SM2SIGNLOADDATA;
		String^ SM2SIGNDATAADD;
		String^ SM2SIGNDATA;
		String^ SM2SIGNCMD;
		String^ SM2VERIFYCMD;
		String^ LOADAID;
		String^ AIDADD;
		String^ SM2ZAVALUEADD;
		String^ GENERATESM2ZAVALUE;
//		String^ SM2VERIFYLOADPUBLICKEY;
//		String^ SM2VERIFYLOADMESSAGE;
//		String^ SM2VERIFYLOADRESAULT;

		String^ GETDATA;
		String^ GETSM2PUBKEYDATA;
		String^ GETZAVALUE;
		String^ SELECTFILE;
		String^ READBINARYFILE;
		String^ GETCHALLENGE;
		String^ DATACOMPRESS1;
		String^ DATACOMPRESS2;

		array<BYTE>^ bAPDUCmd;
		array<BYTE>^ bResponseData;

		array<BYTE>^ bSM2PriKey;
		array<BYTE>^ bSM2PubKey;
		array<BYTE>^ bSM2SignData;
		array<BYTE>^ bSM2SigndData;

		String^ TmpAPDU;
		String^ FileAdd;
		String^ BinaryFileLen;

		ManagementEventWatcher^ w; 
		X509Certificate2^ certHandle;

		DateTime^ Tstart;
		DateTime^ Tend;

	private: System::Windows::Forms::TextBox^  textBoxAppTest;
	public: 
		//		FileStream^ filestream;


	private: System::Windows::Forms::Button^  btnApplicationTest;



	private: System::Windows::Forms::TabPage^  certstoretest;



		

	


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBoxCert;

	private: System::Windows::Forms::Button^  btnExportAll;
	private: System::Windows::Forms::Button^  btnExportSigle;
	private: System::Windows::Forms::TextBox^  textBoxPin;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBoxCertStore;


	private: System::Windows::Forms::TabControl^  tabControl1;


	private: System::Windows::Forms::TabPage^  performanceTest;
	private: System::Windows::Forms::TabPage^  applicateTest;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxSM2Performence;

	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Button^  btnSM2Verify;
	private: System::Windows::Forms::Button^  btnSM2Sign;
	private: System::Windows::Forms::Button^  btnGeneralSM2Key;
private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
private: System::Windows::Forms::Button^  btnCancel;
	private: System::Windows::Forms::ComboBox^  comboBoxDevice;
			 
//		const static int	WM_DEVICECHANGE = 0x219;
	public:

		Form1(void)
		{
			handle = nullptr;

			nReaderCounter = 0;
			nResponseLength = 0;
			nBtnClickedTimes = 0;
			nTimes = 0;
			nProcessStep = 0;
			nCurrentStep = 0;

			bGeneratedSM2Key = false;

			ReaderName = gcnew array<String^>(MAXREADER);
			CertNames = gcnew array<String^>(CERTNUM);

			ErrorDescription = nullptr;
			SelectReader = nullptr;
			TmpAPDU = nullptr;
			TextInput = nullptr;
			TextBoxMsg = nullptr;
			SignDate = nullptr;
			SelectCert = nullptr;
			SelectCertPin = nullptr;
			FileAdd = nullptr;
			BinaryFileLen = nullptr;
/*
			GENERATESM2KEYCMD = gcnew String("80F20200080CC00C6000000001");
			ENABLETIMER = gcnew String("80D3010000");
			DISENABLETIMER = gcnew String("80D30F0000");
			GETCYCLE = gcnew String("80D4000004");
			
			SM2SIGNLOADDATA = gcnew String("80D10000220CC45D586EE2374803232DB3F0C848F9B7DFFF593F01EF59AB5CD8737902D903D872");
			SM2SIGNLOADSIGNDATA = gcnew String("80D10000220C64EFCCBBBEB8855BFEE6CACCFA9D9F5BD14C449A8E6AA1343273F411001FB9AD09");
			SM2SIGNCMD = gcnew String("80F204000A0CC40C640C8400000001");	

			SM2VERIFYCMD = gcnew String("80F205000A0C600CA00CC000000001");
			SM2VERIFYLOADPUBLICKEY = gcnew String("80D10000420C604DDEE1E42A9C1ED09BBE8BA3A44E797AAF4C7E21AB900AB60CEBCE91F19E5F7016668E794BF512E0567BE038BC1F9C42E6495E01D49E614B9862E62E94B949D3");
			SM2VERIFYLOADMESSAGE = gcnew String("80D10000220CA0FC512883F0BBA23B0B71583582C62761D54A319A8A36B2B12D1520B985B58894");
			SM2VERIFYLOADRESAULT = gcnew String("80D10000420CC004F2322C96F99FE0865BB315221A5C145221BAE8F136A75FF47412E96370313953CC07A16E2B3EB92F40F804633C02513A469552D16AAE3D500DCFC49983454C");
		    
			GETSM2PUBKEYDATA = gcnew String("80D00C6020");
			GETSM2PRIKEYDATA = gcnew String("80D00CC020");
  */
			ENABLETIMER = gcnew String("80D3010000");
			DISENABLETIMER = gcnew String("80D30F0000");
			GETCYCLE = gcnew String("80D4000004");
			
			SM2PRIKEYADD = gcnew String("0CE0");
			SM2PUBKEYADD = gcnew String("0CA0");
			SM2SIGNDATAADD = gcnew String("0D40");
			SM2SIGNEDDATAADD = gcnew String("0D60");
			AIDADD = gcnew String("0DA0");
			SM2ZAVALUEADD = gcnew String("0E40");
			ELIPTICCRUVEPAR = gcnew String("00000001");

			GENERATESM2KEYCMD = gcnew String("80F2020008");
			SM2SIGNLOADDATA = gcnew String("80D1000022");
			SM2SIGNDATA = gcnew String("EFCCBBBEB8855BFEE6CACCFA9D9F5BD14C449A8E6AA1343273F411001FB9AD09");
			SM2SIGNCMD = gcnew String("80F204000A");

			SM2VERIFYCMD = gcnew String("80F205000A");

			LOADAID = gcnew String("80D1000009");
			GENERATESM2ZAVALUE = gcnew String("80F203000A");
			
//			SM2VERIFYLOADMESSAGE = gcnew String("80D10000220CA0FC512883F0BBA23B0B71583582C62761D54A319A8A36B2B12D1520B985B58894");
//			SM2VERIFYLOADRESAULT = gcnew String("80D10000420CC004F2322C96F99FE0865BB315221A5C145221BAE8F136A75FF47412E96370313953CC07A16E2B3EB92F40F804633C02513A469552D16AAE3D500DCFC49983454C");

			GETDATA = gcnew String("80D0");

			SELECTFILE = gcnew String("00A40400");
			READBINARYFILE = gcnew String("00B0");
			GETCHALLENGE = gcnew String("0084000008");
			DATACOMPRESS1 = gcnew String("80C4410104C0023000");
			DATACOMPRESS2 = gcnew String("80C481011BC0023000C181140BE9EB7F21A1FD176A5B1BAF554B9288A025310F");

			bAPDUCmd = gcnew array<BYTE>(MAX_APDU_LENGTH); 
			bResponseData = gcnew array<BYTE>(MAX_RESPDATA_LENGTH);

			bSM2PriKey = gcnew array<BYTE>(SM2PRIKEYLEN);
			bSM2PubKey = gcnew array<BYTE>(SM2PUBKEYLEN);
			bSM2SignData = gcnew array<BYTE>(SM2SIGNDATALEN);
			bSM2SigndData = gcnew array<BYTE>(SM2SIGNDDATALEN);

			w = gcnew ManagementEventWatcher();
			certHandle = gcnew X509Certificate2;
			Tstart = gcnew DateTime;
			Tend = gcnew DateTime;
//			filestream = gcnew FileStream();

			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}








	protected: 

/*
		[SecurityPermission(SecurityAction::Demand, Flags=SecurityPermissionFlag::UnmanagedCode)]
		virtual void WndProc( Message% m ) override
		{

			// Listen for operating system messages.
			switch ( m.Msg )
			{
			case WM_DEVICECHANGE:

				switch (safe_cast<int>(m.WParam)){
			case DBT_DEVICEREMOVECOMPLETE:
				MessageBox::Show("Device Removed!");
					break;
			case DBT_DEVICEARRIVAL:
				MessageBox::Show("Device Insert!");
				break;
				}

				// The WParam value identifies what is occurring.

				// Invalidate to get new text painted.
				this->Invalidate();
				break;
			}
			Form::WndProc( m );
		}

*/




	protected: 

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->performanceTest = (gcnew System::Windows::Forms::TabPage());
			this->btnSM2Verify = (gcnew System::Windows::Forms::Button());
			this->btnSM2Sign = (gcnew System::Windows::Forms::Button());
			this->btnGeneralSM2Key = (gcnew System::Windows::Forms::Button());
			this->textBoxSM2Performence = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->applicateTest = (gcnew System::Windows::Forms::TabPage());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnApplicationTest = (gcnew System::Windows::Forms::Button());
			this->textBoxAppTest = (gcnew System::Windows::Forms::TextBox());
			this->certstoretest = (gcnew System::Windows::Forms::TabPage());
			this->textBoxCertStore = (gcnew System::Windows::Forms::TextBox());
			this->btnExportAll = (gcnew System::Windows::Forms::Button());
			this->btnExportSigle = (gcnew System::Windows::Forms::Button());
			this->textBoxPin = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBoxCert = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxDevice = (gcnew System::Windows::Forms::ComboBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->tabControl1->SuspendLayout();
			this->performanceTest->SuspendLayout();
			this->applicateTest->SuspendLayout();
			this->certstoretest->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->performanceTest);
			this->tabControl1->Controls->Add(this->applicateTest);
			this->tabControl1->Controls->Add(this->certstoretest);
			this->tabControl1->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->tabControl1->Location = System::Drawing::Point(12, 39);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(448, 275);
			this->tabControl1->TabIndex = 0;
			// 
			// performanceTest
			// 
			this->performanceTest->BackColor = System::Drawing::Color::LightGray;
			this->performanceTest->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->performanceTest->Controls->Add(this->btnSM2Verify);
			this->performanceTest->Controls->Add(this->btnSM2Sign);
			this->performanceTest->Controls->Add(this->btnGeneralSM2Key);
			this->performanceTest->Controls->Add(this->textBoxSM2Performence);
			this->performanceTest->Controls->Add(this->label2);
			this->performanceTest->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->performanceTest->ForeColor = System::Drawing::SystemColors::MenuText;
			this->performanceTest->Location = System::Drawing::Point(4, 21);
			this->performanceTest->Name = L"performanceTest";
			this->performanceTest->Padding = System::Windows::Forms::Padding(3);
			this->performanceTest->Size = System::Drawing::Size(440, 250);
			this->performanceTest->TabIndex = 0;
			this->performanceTest->Text = L"芯片SM2性能测试";
			this->performanceTest->UseVisualStyleBackColor = true;
			// 
			// btnSM2Verify
			// 
			this->btnSM2Verify->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSM2Verify->Location = System::Drawing::Point(323, 25);
			this->btnSM2Verify->Name = L"btnSM2Verify";
			this->btnSM2Verify->Size = System::Drawing::Size(107, 23);
			this->btnSM2Verify->TabIndex = 4;
			this->btnSM2Verify->Text = L"SM2验签";
			this->btnSM2Verify->UseVisualStyleBackColor = true;
			this->btnSM2Verify->Click += gcnew System::EventHandler(this, &Form1::btnSM2Verify_Click);
			// 
			// btnSM2Sign
			// 
			this->btnSM2Sign->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSM2Sign->Location = System::Drawing::Point(176, 25);
			this->btnSM2Sign->Name = L"btnSM2Sign";
			this->btnSM2Sign->Size = System::Drawing::Size(107, 23);
			this->btnSM2Sign->TabIndex = 3;
			this->btnSM2Sign->Text = L"SM2签名";
			this->btnSM2Sign->UseVisualStyleBackColor = true;
			this->btnSM2Sign->Click += gcnew System::EventHandler(this, &Form1::btnSM2Sign_Click);
			// 
			// btnGeneralSM2Key
			// 
			this->btnGeneralSM2Key->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnGeneralSM2Key->BackColor = System::Drawing::Color::LightGray;
			this->btnGeneralSM2Key->Location = System::Drawing::Point(9, 25);
			this->btnGeneralSM2Key->Name = L"btnGeneralSM2Key";
			this->btnGeneralSM2Key->Size = System::Drawing::Size(130, 23);
			this->btnGeneralSM2Key->TabIndex = 2;
			this->btnGeneralSM2Key->Text = L"生成SM2公私钥";
			this->btnGeneralSM2Key->UseVisualStyleBackColor = true;
			this->btnGeneralSM2Key->Click += gcnew System::EventHandler(this, &Form1::btnGeneralSM2Key_Click);
			// 
			// textBoxSM2Performence
			// 
			this->textBoxSM2Performence->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxSM2Performence->BackColor = System::Drawing::SystemColors::Control;
			this->textBoxSM2Performence->ForeColor = System::Drawing::Color::Blue;
			this->textBoxSM2Performence->Location = System::Drawing::Point(7, 61);
			this->textBoxSM2Performence->Multiline = true;
			this->textBoxSM2Performence->Name = L"textBoxSM2Performence";
			this->textBoxSM2Performence->ReadOnly = true;
			this->textBoxSM2Performence->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxSM2Performence->Size = System::Drawing::Size(427, 183);
			this->textBoxSM2Performence->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::LightGray;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(6, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 16);
			this->label2->TabIndex = 0;
			// 
			// applicateTest
			// 
			this->applicateTest->Controls->Add(this->btnCancel);
			this->applicateTest->Controls->Add(this->btnApplicationTest);
			this->applicateTest->Controls->Add(this->textBoxAppTest);
			this->applicateTest->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->applicateTest->Location = System::Drawing::Point(4, 21);
			this->applicateTest->Name = L"applicateTest";
			this->applicateTest->Padding = System::Windows::Forms::Padding(3);
			this->applicateTest->Size = System::Drawing::Size(440, 250);
			this->applicateTest->TabIndex = 1;
			this->applicateTest->Text = L"eID应用验证测试";
			this->applicateTest->UseVisualStyleBackColor = true;
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(243, 6);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 4;
			this->btnCancel->Text = L"取消测试";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &Form1::btnCancel_Click);
			// 
			// btnApplicationTest
			// 
			this->btnApplicationTest->Location = System::Drawing::Point(89, 6);
			this->btnApplicationTest->Name = L"btnApplicationTest";
			this->btnApplicationTest->Size = System::Drawing::Size(75, 23);
			this->btnApplicationTest->TabIndex = 3;
			this->btnApplicationTest->Text = L"开始测试";
			this->btnApplicationTest->UseVisualStyleBackColor = true;
			this->btnApplicationTest->Click += gcnew System::EventHandler(this, &Form1::btnApplicationTest_Click);
			// 
			// textBoxAppTest
			// 
			this->textBoxAppTest->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBoxAppTest->Location = System::Drawing::Point(7, 35);
			this->textBoxAppTest->Multiline = true;
			this->textBoxAppTest->Name = L"textBoxAppTest";
			this->textBoxAppTest->ReadOnly = true;
			this->textBoxAppTest->Size = System::Drawing::Size(427, 209);
			this->textBoxAppTest->TabIndex = 0;
			// 
			// certstoretest
			// 
			this->certstoretest->Controls->Add(this->textBoxCertStore);
			this->certstoretest->Controls->Add(this->btnExportAll);
			this->certstoretest->Controls->Add(this->btnExportSigle);
			this->certstoretest->Controls->Add(this->textBoxPin);
			this->certstoretest->Controls->Add(this->label5);
			this->certstoretest->Controls->Add(this->comboBoxCert);
			this->certstoretest->Controls->Add(this->label4);
			this->certstoretest->Location = System::Drawing::Point(4, 21);
			this->certstoretest->Name = L"certstoretest";
			this->certstoretest->Size = System::Drawing::Size(440, 250);
			this->certstoretest->TabIndex = 2;
			this->certstoretest->Text = L"证书存储测试";
			this->certstoretest->UseVisualStyleBackColor = true;
			// 
			// textBoxCertStore
			// 
			this->textBoxCertStore->Location = System::Drawing::Point(3, 86);
			this->textBoxCertStore->Multiline = true;
			this->textBoxCertStore->Name = L"textBoxCertStore";
			this->textBoxCertStore->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxCertStore->Size = System::Drawing::Size(434, 161);
			this->textBoxCertStore->TabIndex = 6;
			// 
			// btnExportAll
			// 
			this->btnExportAll->Location = System::Drawing::Point(266, 45);
			this->btnExportAll->Name = L"btnExportAll";
			this->btnExportAll->Size = System::Drawing::Size(115, 23);
			this->btnExportAll->TabIndex = 5;
			this->btnExportAll->Text = L"导入所有证书";
			this->btnExportAll->UseVisualStyleBackColor = true;
			// 
			// btnExportSigle
			// 
			this->btnExportSigle->Location = System::Drawing::Point(57, 45);
			this->btnExportSigle->Name = L"btnExportSigle";
			this->btnExportSigle->Size = System::Drawing::Size(112, 23);
			this->btnExportSigle->TabIndex = 4;
			this->btnExportSigle->Text = L"导入选中证书";
			this->btnExportSigle->UseVisualStyleBackColor = true;
			this->btnExportSigle->Click += gcnew System::EventHandler(this, &Form1::btnExportSigle_Click);
			// 
			// textBoxPin
			// 
			this->textBoxPin->Location = System::Drawing::Point(284, 8);
			this->textBoxPin->Name = L"textBoxPin";
			this->textBoxPin->PasswordChar = '*';
			this->textBoxPin->Size = System::Drawing::Size(120, 21);
			this->textBoxPin->TabIndex = 3;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(249, 12);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 12);
			this->label5->TabIndex = 2;
			this->label5->Text = L"密码";
			// 
			// comboBoxCert
			// 
			this->comboBoxCert->FormattingEnabled = true;
			this->comboBoxCert->Items->AddRange(gcnew cli::array< System::Object^  >(20) {L"eIDCertTest1", L"eIDCertTest2", L"eIDCertTest3", 
				L"eIDCertTest4", L"eIDCertTest5", L"eIDCertTest6", L"eIDCertTest7", L"eIDCertTest8", L"eIDCertTest9", L"eIDCertTest10", L"eIDCertTest11", 
				L"eIDCertTest12", L"eIDCertTest13", L"eIDCertTest14", L"eIDCertTest15", L"eIDCertTest16", L"eIDCertTest17", L"eIDCertTest18", 
				L"eIDCertTest19", L"eIDCertTest20"});
			this->comboBoxCert->Location = System::Drawing::Point(67, 9);
			this->comboBoxCert->Name = L"comboBoxCert";
			this->comboBoxCert->Size = System::Drawing::Size(148, 20);
			this->comboBoxCert->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 12);
			this->label4->TabIndex = 0;
			this->label4->Text = L"选择证书";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(13, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 14);
			this->label1->TabIndex = 1;
			this->label1->Text = L"选择设备";
			// 
			// comboBoxDevice
			// 
			this->comboBoxDevice->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->comboBoxDevice->FormattingEnabled = true;
			this->comboBoxDevice->Location = System::Drawing::Point(83, 13);
			this->comboBoxDevice->Name = L"comboBoxDevice";
			this->comboBoxDevice->Size = System::Drawing::Size(377, 20);
			this->comboBoxDevice->TabIndex = 2;
			this->comboBoxDevice->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBoxDevice_SelectedIndexChanged);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::backgroundWorker1_DoWork);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::backgroundWorker1_RunWorkerCompleted);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Form1::backgroundWorker1_ProgressChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(472, 326);
			this->Controls->Add(this->comboBoxDevice);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"eID载体测试系统";
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->tabControl1->ResumeLayout(false);
			this->performanceTest->ResumeLayout(false);
			this->performanceTest->PerformLayout();
			this->applicateTest->ResumeLayout(false);
			this->applicateTest->PerformLayout();
			this->certstoretest->ResumeLayout(false);
			this->certstoretest->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

			 private:System::Void Form1_Shown(System::Object^ sender, System::EventArgs^ s){

						 nBtnClickedTimes = 0;
						 textBoxSM2Performence->Text = gcnew String("");
						 textBoxAppTest->Text = gcnew String("");
						 

						 cli::pin_ptr<int> pReaderCounter = &nReaderCounter;
						 char readernametemp[MAX_READER_NAME];
						 int offset = 0;

						 while((ret = PCSC_GetReaderList(pReaderCounter, readernametemp)) != EXCUTE_SUC){
							 ShowErrorDescription(ret);
//							 return;
						 }
						 
						 for(int i = 0; i < nReaderCounter; i ++){
							 ReaderName[i] = String(readernametemp + offset).ToString();
							 offset += strlen(readernametemp);
							 offset += 1;
							 comboBoxDevice->Items->Add(ReaderName[i]);
						 }
						
						 						 
					 }

			private: System::Void comboBoxDevice_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
						 SelectReader = comboBoxDevice->SelectedItem->ToString();
						 
					 }

		 
private: System::Void btnGeneralSM2Key_Click(System::Object^  sender, System::EventArgs^  e) {

			 cli::pin_ptr<BYTE> pAPDUCmd = &bAPDUCmd[0];
			 cli::pin_ptr<BYTE>	pResponseData = &bResponseData[0];
			 cli::pin_ptr<int> pResponseLength = &nResponseLength;
			 cli::pin_ptr<BYTE> pSM2PriKey = &bSM2PriKey[0];
			 cli::pin_ptr<BYTE> pSM2PubKey = &bSM2PubKey[0];
			 
			 nBtnClickedTimes ++;
			 String^ tmp = gcnew String("");
			 char* str = (char*)(void*)Marshal::StringToHGlobalAnsi(SelectReader);
			 cli::pin_ptr<HANDLE> pHandle = &handle;

			 if((ret = PCSC_OpenReader(pHandle, (const char*)str)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;

			 }

			 //for(int i = 0; i < LOOPCOUNTER; i ++){
				 
				 GetAPDUCmd(ENABLETIMER, bAPDUCmd);
				 if((ret = PCSC_ApduT0(handle, pAPDUCmd, ENABLETIMER->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
					 ShowErrorDescription(ret);
					 return;
				 }
				 
				 TextBoxMsg = String::Format("{0, 3:D3}#: SM2 Pri&&Pub Key Generate Start...", nBtnClickedTimes);
				 ShowTextBox(TextBoxMsg, textBoxSM2Performence);
				 TmpAPDU = GENERATESM2KEYCMD + (SM2PRIKEYADD + SM2PUBKEYADD + ELIPTICCRUVEPAR);
				 GetAPDUCmd(TmpAPDU, bAPDUCmd);
				 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
					 ShowErrorDescription(ret);
					 return;
				 }
				 bGeneratedSM2Key = true;

				 TextBoxMsg = String::Format("{0,-18}", "  SM2 Private Key:");
				 ShowTextBox(TextBoxMsg, textBoxSM2Performence);

				 TmpAPDU = GETDATA + SM2PRIKEYADD + SM2PRIKEYLEN.ToString("X2");
				 
				 GetAPDUCmd(TmpAPDU, bAPDUCmd);
				 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pSM2PriKey, pResponseLength)) != EXCUTE_SUC){
					 ShowErrorDescription(ret);
					 return;
				 }

				 ShowArrayDate(pSM2PriKey, nResponseLength, ARRAYLENGTH);

				 TextBoxMsg = String::Format("{0, -18}", "  SM2 Public Key:");
				 ShowTextBox(TextBoxMsg, textBoxSM2Performence);

				 TmpAPDU = GETDATA + SM2PUBKEYADD + SM2PUBKEYLEN.ToString("X2");
				 GetAPDUCmd(TmpAPDU, bAPDUCmd);
				 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pSM2PubKey, pResponseLength)) != EXCUTE_SUC){
					 ShowErrorDescription(ret);
					 return;
				 }

				 ShowArrayDate(pSM2PubKey, nResponseLength, ARRAYLENGTH);

				 GetAPDUCmd(GETCYCLE, bAPDUCmd);
				 if((ret = PCSC_ApduT0(handle, pAPDUCmd, GETCYCLE->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
					 ShowErrorDescription(ret);
					 return;
				 }

				
				 for(int j = 0; j < nResponseLength; j ++){

					 tmp += bResponseData[j].ToString("X2");
				 }

				 nTimes = Convert::ToUInt64(tmp, 16);   

				 Double dtimes = safe_cast<Double>(nTimes) / 20000000;

				 TextBoxMsg = String::Format("{0,-18}{1, 12}", "  Total Cycle: " , Convert::ToString(safe_cast<Int64>(nTimes), 10));
				 ShowTextBox(TextBoxMsg, textBoxSM2Performence);

				 TextBoxMsg = String::Format("{0,-18}{1, 12}", "  Total Times: " , Convert::ToString(dtimes) + "s");
				 ShowTextBox(TextBoxMsg + Environment::NewLine, textBoxSM2Performence);
			 

				 GetAPDUCmd(DISENABLETIMER, bAPDUCmd);
				 if((ret = PCSC_ApduT0(handle, pAPDUCmd, DISENABLETIMER->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
					 ShowErrorDescription(ret);
					 return;
				 }

				 
			 //}

				 
			 
			
		 }


		  
private: System::Void btnSM2Sign_Click(System::Object^  sender, System::EventArgs^  e) {

			 String^ tmp = gcnew String("");
			 SignDate = "";
			 cli::pin_ptr<BYTE> pAPDUCmd = &bAPDUCmd[0];
			 cli::pin_ptr<BYTE>	pResponseData = &bResponseData[0];
			 cli::pin_ptr<int> pResponseLength = &nResponseLength;
			 cli::pin_ptr<BYTE> pSM2PriKey = &bSM2PriKey[0];
			 cli::pin_ptr<BYTE> pSM2PubKey = &bSM2PubKey[0];
			 cli::pin_ptr<BYTE>	pSM2SigndData = &bSM2SigndData[0];

			 nBtnClickedTimes ++;

			 char* str = (char*)(void*)Marshal::StringToHGlobalAnsi(SelectReader);
			 cli::pin_ptr<HANDLE> pHandle = &handle;

			 if((ret = PCSC_OpenReader(pHandle, (const char*)str)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;

			 }

			 if(!bGeneratedSM2Key){
				 
				 TmpAPDU = GENERATESM2KEYCMD + (SM2PRIKEYADD + SM2PUBKEYADD + ELIPTICCRUVEPAR);
				 GetAPDUCmd(TmpAPDU, bAPDUCmd);
				 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
					 ShowErrorDescription(ret);
					 return;
				 }

				 TmpAPDU = GETDATA + SM2PUBKEYADD + SM2PUBKEYLEN.ToString("X2");
				 GetAPDUCmd(TmpAPDU, bAPDUCmd);
				 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pSM2PubKey, pResponseLength)) != EXCUTE_SUC){
					 ShowErrorDescription(ret);
					 return;
				 }

				 TmpAPDU = GETDATA + SM2PRIKEYADD + SM2PRIKEYLEN.ToString("X2");

				 GetAPDUCmd(TmpAPDU, bAPDUCmd);
				 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pSM2PriKey, pResponseLength)) != EXCUTE_SUC){
					 ShowErrorDescription(ret);
					 return;
				 }

				 bGeneratedSM2Key = true;

			 }		 
			 
			 TextBoxMsg = String::Format("{0, 3:D3}#: SM2 Sign Start...", nBtnClickedTimes);
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);
			 TextBoxMsg = String::Format("{0, -18}", "  Be Signed Date:");
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);

			 SignDate = GenerateSM2SignData();

			 TextBoxMsg = String::Format("{0,38}", SignDate->Substring(0,ARRAYLENGTH * 2));
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);
			 TextBoxMsg = String::Format("{0,38}", SignDate->Substring(ARRAYLENGTH,ARRAYLENGTH * 2));
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);

			 TextBoxMsg = String::Format("{0,-18}", "  SM2 Private Key:");
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);
			 ShowArrayDate(pSM2PriKey, SM2PRIKEYLEN, ARRAYLENGTH);

			 TmpAPDU =SM2SIGNLOADDATA + (SM2SIGNDATAADD + SignDate);
			 GetAPDUCmd(TmpAPDU, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }

			 GetAPDUCmd(ENABLETIMER, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, ENABLETIMER->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }

			 

			 TmpAPDU = SM2SIGNCMD + (SM2PRIKEYADD + SM2SIGNDATAADD + SM2SIGNEDDATAADD + ELIPTICCRUVEPAR);
			 GetAPDUCmd(TmpAPDU, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }

			 TmpAPDU = GETDATA + SM2SIGNEDDATAADD + SM2SIGNDDATALEN.ToString("X2");

			 GetAPDUCmd(TmpAPDU, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pSM2SigndData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }
			 TextBoxMsg = String::Format("{0,-18}", "  SM2 Signed Date:");
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);
			 ShowArrayDate(pSM2SigndData, nResponseLength, ARRAYLENGTH);

			 GetAPDUCmd(GETCYCLE, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, GETCYCLE->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }

			 for(int j = 0; j < nResponseLength; j ++){

				 tmp += bResponseData[j].ToString("X2");
			 }

			 nTimes = Convert::ToUInt64(tmp, 16);   

			 Double dtimes = safe_cast<Double>(nTimes) / 20000000;

			 TextBoxMsg = String::Format("{0,-18}{1, 12}", "  Total Cycle: " , Convert::ToString(safe_cast<Int64>(nTimes), 10));
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);

			 TextBoxMsg = String::Format("{0,-18}{1, 12}", "  Total Times: " , Convert::ToString(dtimes) + "s");
			 ShowTextBox(TextBoxMsg + Environment::NewLine, textBoxSM2Performence);

			 GetAPDUCmd(DISENABLETIMER, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, DISENABLETIMER->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }

			 
			 
		 }



private: System::Void btnSM2Verify_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 String^ tmp = gcnew String("");
			 cli::pin_ptr<BYTE> pAPDUCmd = &bAPDUCmd[0];
			 cli::pin_ptr<BYTE>	pResponseData = &bResponseData[0];
			 cli::pin_ptr<int> pResponseLength = &nResponseLength;
			 cli::pin_ptr<BYTE> pSM2PriKey = &bSM2PriKey[0];
			 cli::pin_ptr<BYTE> pSM2PubKey = &bSM2PubKey[0];
			 cli::pin_ptr<BYTE>	pSM2SigndData = &bSM2SigndData[0];

			 nBtnClickedTimes ++;

			 char* str = (char*)(void*)Marshal::StringToHGlobalAnsi(SelectReader);
			 cli::pin_ptr<HANDLE> pHandle = &handle;

			 if((ret = PCSC_OpenReader(pHandle, (const char*)str)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;

			 }

			 if(!bGeneratedSM2Key){

				 TmpAPDU = GENERATESM2KEYCMD + (SM2PRIKEYADD + SM2PUBKEYADD + ELIPTICCRUVEPAR);
				 GetAPDUCmd(TmpAPDU, bAPDUCmd);
				 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
					 ShowErrorDescription(ret);
					 return;
				 }

				 TmpAPDU = GETDATA + SM2PUBKEYADD + SM2PUBKEYLEN.ToString("X2");
				 GetAPDUCmd(TmpAPDU, bAPDUCmd);
				 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pSM2PubKey, pResponseLength)) != EXCUTE_SUC){
					 ShowErrorDescription(ret);
					 return;
				 }

				 TmpAPDU = GETDATA + SM2PRIKEYADD + SM2PRIKEYLEN.ToString("X2");

				 GetAPDUCmd(TmpAPDU, bAPDUCmd);
				 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pSM2PriKey, pResponseLength)) != EXCUTE_SUC){
					 ShowErrorDescription(ret);
					 return;
				 }

				 bGeneratedSM2Key = true;
				 

			 }

			 TextBoxMsg = String::Format("{0, 3:D3}#: SM2 Verify Start...", nBtnClickedTimes);
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);
			 TextBoxMsg = String::Format("{0, -18}", "  Original Date:");
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);

			 TextBoxMsg = String::Format("{0,38}", SignDate->Substring(0,ARRAYLENGTH * 2));
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);
			 TextBoxMsg = String::Format("{0,38}", SignDate->Substring(ARRAYLENGTH,ARRAYLENGTH * 2));
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);

			 TextBoxMsg = String::Format("{0, -18}", "  SM2 Signed Date:");
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);
			 ShowArrayDate(pSM2SigndData, SM2SIGNDDATALEN, ARRAYLENGTH);

			 TextBoxMsg = String::Format("{0,-18}", "  SM2 Publick Key:");
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);
			 ShowArrayDate(pSM2PubKey, SM2PUBKEYLEN, ARRAYLENGTH);

			 GetAPDUCmd(ENABLETIMER, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, ENABLETIMER->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }


			 TmpAPDU = SM2VERIFYCMD + (SM2PUBKEYADD + SM2SIGNDATAADD + SM2SIGNEDDATAADD + ELIPTICCRUVEPAR);
			 GetAPDUCmd(TmpAPDU, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }

			 GetAPDUCmd(GETCYCLE, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, GETCYCLE->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }

			 for(int j = 0; j < nResponseLength; j ++){

				 tmp += bResponseData[j].ToString("X2");
			 }

			 nTimes = Convert::ToUInt64(tmp, 16);   

			 Double dtimes = safe_cast<Double>(nTimes) / 20000000;

			 TextBoxMsg = String::Format("{0,-18}{1, 12}", "  Total Cycle: " , Convert::ToString(safe_cast<Int64>(nTimes), 10));
			 ShowTextBox(TextBoxMsg, textBoxSM2Performence);

			 TextBoxMsg = String::Format("{0,-18}{1, 12}", "  Total Times: " , Convert::ToString(dtimes) + "s");
			 ShowTextBox(TextBoxMsg + Environment::NewLine, textBoxSM2Performence);

			 GetAPDUCmd(DISENABLETIMER, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, DISENABLETIMER->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }

		 }

		 private:System::String^ GenerateSM2SignData(){
					 String^ ret = gcnew String("");
					 int random = 0;
					 Random^ r = gcnew Random(DateTime::Now.Millisecond);
					 for(int i = 0; i < SM2SIGNDATALEN; i ++){
						random = r->Next(0x100);
						ret += random.ToString("X2");
					 }
					 return ret;
				 }



		 private: System::Void GetAPDUCmd(String^ strAPDU, array<BYTE>^ apdu){

					  int length = strAPDU->Length / 2;

					  for(int i = 0; i < length; i ++){
						  apdu[i] = safe_cast<BYTE>(Convert::ToSByte(strAPDU->Substring(i * 2, 2), 16));					 
					  }

				  } 

		 private: System::Void ShowErrorDescription(LONG ret){
					  LPVOID lpMsgBuf = NULL;
					  DWORD retval = 0;

					  retval = FormatMessage(
						  FORMAT_MESSAGE_ALLOCATE_BUFFER | 
						  FORMAT_MESSAGE_FROM_SYSTEM |
						  FORMAT_MESSAGE_IGNORE_INSERTS,
						  NULL,
						  (DWORD)ret,
						  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
						  (LPTSTR) &lpMsgBuf,
						  0, NULL );

					  if(!retval){
						  switch (ret){
							case 0x6A82: ErrorDescription = "操作失败";
								break;
							default: 
								break;
						  }
					  }else{
						  ErrorDescription = String((LPTSTR)lpMsgBuf).ToString();
					  }
					  
					  String^ str = String::Format("错误代码： 0x{0, 8:X8}", ret);
					  str += ("\n错误原因： " + ErrorDescription);
					  MessageBox::Show(str);

				  }


		  private: System::Void ShowTextBox(String^ str, TextBox^ textBoxName){

					   textBoxName->AppendText(str + Environment::NewLine);
					   textBoxName->ScrollToCaret();
				   }




		  private: System::Void ShowArrayDate(BYTE* date, int arraylength, int linelength){
					   String^ tmp = gcnew String("");
					   for(int j = 0; j < arraylength; j ++){
						   if((j + 1) % linelength == 0){
							   tmp += date[j].ToString("X2");
							   TextBoxMsg = String::Format("{0,38}", tmp);
							   ShowTextBox(TextBoxMsg, textBoxSM2Performence);
							   tmp = "";
						   }else{
							   tmp += date[j].ToString("X2");
						   }

					   }
				   }






private: System::Void btnApplicationTest_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 nCurrentStep = 0;
			 nProcessStep = 0;

			 char* str = (char*)(void*)Marshal::StringToHGlobalAnsi(SelectReader);
			 cli::pin_ptr<HANDLE> pHandle = &handle;

			 if((ret = PCSC_OpenReader(pHandle, (const char*)str)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;

			 }

			 btnApplicationTest->Enabled = false;
			 btnCancel->Enabled = true;

			 backgroundWorker1->RunWorkerAsync();

			 
/*
			 TextInput = nullptr;
			 String^ tmp = textBox3->Text;

				 array<WCHAR>^ ctmp = gcnew array<WCHAR>(tmp->Length);
				 for(int i = 0; i < tmp->Length; i ++){
					 ctmp = tmp->ToCharArray();
					 TextInput += Convert::ToUInt32(Convert::ToChar(tmp[i])).ToString("X2");
				 }
  
		 
			 TmpAPDU = LOADAID + AIDADD + TextInput->Length.ToString("X2") + TextInput;
			 GetAPDUCmd(TmpAPDU, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }

			 TmpAPDU = GENERATESM2ZAVALUE + AIDADD + SM2PUBKEYADD + SM2ZAVALUEADD + ELIPTICCRUVEPAR;
			 GetAPDUCmd(TmpAPDU, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }
			 
			 TmpAPDU = GETZAVALUE + SM2ZAVALUEADD + TextInput->Length.ToString("X2");
			 GetAPDUCmd(TmpAPDU, bAPDUCmd);
			 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
				 ShowErrorDescription(ret);
				 return;
			 }

*/			 
			 
		 }	  
				  
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 
			 BackgroundWorker^ work = dynamic_cast<BackgroundWorker^>(sender);
			 VerifyApplicationThread(work, e);

				  }

private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 
			 String^ str = gcnew String("");
			 if ( e->Error != nullptr ){
					ShowTextBox(e->Error->Message, textBoxAppTest);
			 }else if ( e->Cancelled ){
				// Next, handle the case where the user cancelled 
				// the operation.
				// Note that due to a race condition in 
				// the DoWork event handler, the Cancelled
				// flag may not have been set, even though
				// CancelAsync was called.
				 ShowTextBox("  Cancelled by User!" + Environment::NewLine, textBoxAppTest);
			 }else{
				// Finally, handle the case where the operation 
				// succeeded.
//						str = String::Format("Total Coast {0, 2:D2}", Tend->Hour - Tstart->Hour);
				str = String::Format("Multi Thread Total Coast {0, 2:D2}h, {1, 2:D2}m, {2, 2:D2}s, {3, 4:D4}ms",
					Tend->Hour - Tstart->Hour, Tend->Minute - Tstart->Minute, Tend->Second - Tstart->Second, Tend->Millisecond - Tstart->Millisecond);
				ShowTextBox(str, textBoxAppTest);
				str = String::Format("******All Process Done!******");
				ShowTextBox(str + Environment::NewLine, textBoxAppTest);
			 }
			 btnApplicationTest->Enabled = true;
			 btnCancel->Enabled = false;
			 
		 }


private: System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {

			 String^ str = gcnew String("");
			 switch (nProcessStep){
				case SELECT_EID_APP:
					str = String::Format("******eID Verify Application Test Start...******");
					ShowTextBox(str, textBoxAppTest);
					str = String::Format("  1# :  {0, -30}", "Select eID Application Done!");
					ShowTextBox(str, textBoxAppTest);
					break;
				case SELECT_FILE:
					str = String::Format("  2# :  {0, -30}", "Select File Done!");
					ShowTextBox(str, textBoxAppTest);
					break;
				case READ_LOADER_CAPACITY:
					str = String::Format("  3# :  {0, -30}", "Read Loader Capacity Done!");
					ShowTextBox(str, textBoxAppTest);
					break;
				case READ_CONTAINER_MAX_NUM:
					str = String::Format("  4# :  {0, -30}", "Read Container Max Number Done!");
					ShowTextBox(str, textBoxAppTest);
					break;
				case GET_CHALLENGE:
					str = String::Format("  5# :  {0, -30}", "Get Challenge Done!");
					ShowTextBox(str, textBoxAppTest);
					break;
				case READ_FILE_INDEX:
					str = String::Format("  6# :  {0, -30}", "Read File Index Done!");
					ShowTextBox(str, textBoxAppTest);
					break;
				case READ_CONTAINER_INDEX:
					str = String::Format("  7# :  {0, -30}", "Read Container Index Done!");
					ShowTextBox(str, textBoxAppTest);
					break;
				case READ_CONTAINER_INFO:
					str = String::Format("  8# :  {0, -30}", "Read Container Info Done!");
					ShowTextBox(str, textBoxAppTest);
					break;
				case READ_PRIVATE_CERT_RSA1024:
					str = String::Format("  9# :  {0, -30}", "Read RSA1024 Private Cert Done!");
					ShowTextBox(str, textBoxAppTest);
					break;
				case DATA_COMPRESS:
					str = String::Format("  10# :  {0, -30}", "Data Compress Done!");
					ShowTextBox(str, textBoxAppTest);
					break;
				default:
					break;
			 }
		 }


		 private:System::Void VerifyApplicationThread(BackgroundWorker^ work, DoWorkEventArgs^ e){
					 
					 String^ tmp = gcnew String("");
					 cli::pin_ptr<BYTE> pAPDUCmd = &bAPDUCmd[0];
					 cli::pin_ptr<BYTE>	pResponseData = &bResponseData[0];
					 cli::pin_ptr<int> pResponseLength = &nResponseLength;
					 cli::pin_ptr<BYTE> pSM2PriKey = &bSM2PriKey[0];
					 cli::pin_ptr<BYTE> pSM2PubKey = &bSM2PubKey[0];
					 cli::pin_ptr<BYTE>	pSM2SigndData = &bSM2SigndData[0];

					 Tstart = DateTime::Now;
 /*
					 for(int i = 0; i < 65535; i ++){
						 for(int j = 0; j < 10000; j ++){
							;
						 }

					 }
*/					 
					 //选中eID应用
					 FileAdd = "A000000003454944";
					 TmpAPDU = SELECTFILE + (FileAdd->Length / 2).ToString("X2") + FileAdd ;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 nProcessStep = SELECT_EID_APP;

					 if(nProcessStep > nCurrentStep){
						 nCurrentStep = nProcessStep;
						 work->ReportProgress(nProcessStep);
					 }
					 
					 //选中“3F00”和“3F01”文件
					 FileAdd = "3F00";
					 TmpAPDU = SELECTFILE + (FileAdd->Length / 2).ToString("X2") + FileAdd ;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 FileAdd = "3F01";
					 TmpAPDU = SELECTFILE + (FileAdd->Length / 2).ToString("X2") + FileAdd ;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 nProcessStep = SELECT_FILE;
					 if(nProcessStep > nCurrentStep){
						 nCurrentStep = nProcessStep;
						 work->ReportProgress(nProcessStep);
					 }
					 
					 //读载体能力
					 FileAdd = "4000";
					 TmpAPDU = SELECTFILE + (FileAdd->Length / 2).ToString("X2") + FileAdd ;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 BinaryFileLen = "000040";
					 TmpAPDU = READBINARYFILE + BinaryFileLen;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 nProcessStep = READ_LOADER_CAPACITY;

					 if(nProcessStep > nCurrentStep){
						 nCurrentStep = nProcessStep;
						 work->ReportProgress(nProcessStep);
					 }

					 //读容器最大个数
					 FileAdd = "3001";
					 TmpAPDU = SELECTFILE + (FileAdd->Length / 2).ToString("X2") + FileAdd ;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 BinaryFileLen = "000001";
					 TmpAPDU = READBINARYFILE + BinaryFileLen;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 nProcessStep = READ_CONTAINER_MAX_NUM;

					 if(nProcessStep > nCurrentStep){
						 nCurrentStep = nProcessStep;
						 work->ReportProgress(nProcessStep);
					 }
					 
					 //生成随机数
					 GetAPDUCmd(GETCHALLENGE, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 
					 nProcessStep = GET_CHALLENGE;

					 if(nProcessStep > nCurrentStep){
						 nCurrentStep = nProcessStep;
						 work->ReportProgress(nProcessStep);
					 }

					 //读文件索引
					 FileAdd = "0FFE";
					 TmpAPDU = SELECTFILE + (FileAdd->Length / 2).ToString("X2") + FileAdd ;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 BinaryFileLen = "000018";
					 TmpAPDU = READBINARYFILE + BinaryFileLen;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 nProcessStep = READ_FILE_INDEX;

					 if(nProcessStep > nCurrentStep){
						 nCurrentStep = nProcessStep;
						 work->ReportProgress(nProcessStep);
					 }

					 //读容器索引
					 FileAdd = "0FFD";
					 TmpAPDU = SELECTFILE + (FileAdd->Length / 2).ToString("X2") + FileAdd ;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 BinaryFileLen = "000002";
					 TmpAPDU = READBINARYFILE + BinaryFileLen;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 nProcessStep = READ_CONTAINER_INDEX;

					 if(nProcessStep > nCurrentStep){
						 nCurrentStep = nProcessStep;
						 work->ReportProgress(nProcessStep);
					 }

					 //读容器信息
					 FileAdd = "0FFF";
					 TmpAPDU = SELECTFILE + (FileAdd->Length / 2).ToString("X2") + FileAdd ;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 BinaryFileLen = "0000F0";
					 TmpAPDU = READBINARYFILE + BinaryFileLen;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 nProcessStep = READ_CONTAINER_INFO;

					 if(nProcessStep > nCurrentStep){
						 nCurrentStep = nProcessStep;
						 work->ReportProgress(nProcessStep);
					 }

					 //读个人RSA1024证书
					 FileAdd = "1011";
					 TmpAPDU = SELECTFILE + (FileAdd->Length / 2).ToString("X2") + FileAdd ;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 BinaryFileLen = "0000F0";
					 TmpAPDU = READBINARYFILE + BinaryFileLen;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 BinaryFileLen = "00F0F0";
					 TmpAPDU = READBINARYFILE + BinaryFileLen;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 BinaryFileLen = "01E0F0";
					 TmpAPDU = READBINARYFILE + BinaryFileLen;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 BinaryFileLen = "02D0E7";
					 TmpAPDU = READBINARYFILE + BinaryFileLen;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 BinaryFileLen = "00F0";
					 TmpAPDU = READBINARYFILE + BinaryFileLen;
					 GetAPDUCmd(TmpAPDU, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }
					 nProcessStep = READ_FILE_INDEX;

					 if(nProcessStep > nCurrentStep){
						 nCurrentStep = nProcessStep;
						 work->ReportProgress(nProcessStep);
					 }

					 //数据压缩认证
					 GetAPDUCmd(DATACOMPRESS1, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }

					 GetAPDUCmd(DATACOMPRESS2, bAPDUCmd);
					 if((ret = PCSC_ApduT0(handle, pAPDUCmd, TmpAPDU->Length / 2, pResponseData, pResponseLength)) != EXCUTE_SUC){
						 ShowErrorDescription(ret);
						 return;
					 }

					 nProcessStep = DATA_COMPRESS;

					 if(nProcessStep > nCurrentStep){
						 nCurrentStep = nProcessStep;
						 work->ReportProgress(nProcessStep);
					 }
				 }


private: System::Void btnExportSigle_Click(System::Object^  sender, System::EventArgs^  e) {

			 array<BYTE>^ pubkey = gcnew array<BYTE>(0x800);
			 cli::pin_ptr<BYTE> pkey = &pubkey[0];

			 SelectCert = comboBoxCert->Text;
			 SelectCertPin = textBoxPin->Text;
			 if(SelectCertPin->Equals("")){
				 MessageBox::Show("Please Enter the Cert's Password...");
				 return;
			 }

			 try{
				 certHandle = gcnew X509Certificate2(".\\cert\\" + SelectCert + ".pfx", SelectCertPin);
			 }catch(CryptographicException^ ex){
				 MessageBox::Show(ex->Message);
			 }
			 
//			 pubkey = certHandle->GetPublicKey();
			 ShowTextBox(certHandle->GetRawCertDataString(), textBoxCertStore);


				 MessageBox::Show("ok");
		 }


private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->backgroundWorker1->CancelAsync();
			 btnCancel->Enabled = false;
		 }
};
}

