#pragma once


namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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

		HANDLE handle;

		int ReaderCounter;
		LONG ret;

		array<String^>^ ReaderName;

		Form1(void)
		{
			handle = NULL;

			ReaderCounter = 0;
			ReaderName = gcnew array<String^>(16);

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
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 

	protected: 

	private: System::Windows::Forms::TabPage^  performanceTest;
	private: System::Windows::Forms::TabPage^  applicateTest;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Button^  btnSM2Verify;
	private: System::Windows::Forms::Button^  btnSM2Sign;
	private: System::Windows::Forms::Button^  btnGeneralRSAKey;
	private: System::Windows::Forms::ComboBox^  comboBox1;




	protected: 









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
			this->btnGeneralRSAKey = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->applicateTest = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->tabControl1->SuspendLayout();
			this->performanceTest->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->performanceTest);
			this->tabControl1->Controls->Add(this->applicateTest);
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
			this->performanceTest->Controls->Add(this->btnGeneralRSAKey);
			this->performanceTest->Controls->Add(this->textBox1);
			this->performanceTest->Controls->Add(this->label2);
			this->performanceTest->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->performanceTest->ForeColor = System::Drawing::SystemColors::MenuText;
			this->performanceTest->Location = System::Drawing::Point(4, 21);
			this->performanceTest->Name = L"performanceTest";
			this->performanceTest->Padding = System::Windows::Forms::Padding(3);
			this->performanceTest->Size = System::Drawing::Size(440, 250);
			this->performanceTest->TabIndex = 0;
			this->performanceTest->Text = L"载体性能测试";
			// 
			// btnSM2Verify
			// 
			this->btnSM2Verify->Location = System::Drawing::Point(308, 25);
			this->btnSM2Verify->Name = L"btnSM2Verify";
			this->btnSM2Verify->Size = System::Drawing::Size(107, 23);
			this->btnSM2Verify->TabIndex = 4;
			this->btnSM2Verify->Text = L"SM2验签";
			this->btnSM2Verify->UseVisualStyleBackColor = true;
			// 
			// btnSM2Sign
			// 
			this->btnSM2Sign->Location = System::Drawing::Point(165, 25);
			this->btnSM2Sign->Name = L"btnSM2Sign";
			this->btnSM2Sign->Size = System::Drawing::Size(107, 23);
			this->btnSM2Sign->TabIndex = 3;
			this->btnSM2Sign->Text = L"SM2签名";
			this->btnSM2Sign->UseVisualStyleBackColor = true;
			// 
			// btnGeneralRSAKey
			// 
			this->btnGeneralRSAKey->BackColor = System::Drawing::Color::LightGray;
			this->btnGeneralRSAKey->Location = System::Drawing::Point(27, 25);
			this->btnGeneralRSAKey->Name = L"btnGeneralRSAKey";
			this->btnGeneralRSAKey->Size = System::Drawing::Size(107, 23);
			this->btnGeneralRSAKey->TabIndex = 2;
			this->btnGeneralRSAKey->Text = L"生成RSA公私钥";
			this->btnGeneralRSAKey->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->ForeColor = System::Drawing::Color::Blue;
			this->textBox1->Location = System::Drawing::Point(7, 80);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(427, 164);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::LightGray;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(6, 61);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"测试结果";
			// 
			// applicateTest
			// 
			this->applicateTest->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->applicateTest->Location = System::Drawing::Point(4, 21);
			this->applicateTest->Name = L"applicateTest";
			this->applicateTest->Padding = System::Windows::Forms::Padding(3);
			this->applicateTest->Size = System::Drawing::Size(440, 250);
			this->applicateTest->TabIndex = 1;
			this->applicateTest->Text = L"应用检测";
			this->applicateTest->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
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
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(83, 13);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(377, 20);
			this->comboBox1->TabIndex = 2;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(472, 326);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"eID应用";
			this->Shown += gcnew System::EventHandler(this, &Form1::From1_Shown);
			this->tabControl1->ResumeLayout(false);
			this->performanceTest->ResumeLayout(false);
			this->performanceTest->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

			 private:System::Void From1_Shown(System::Object^ sender, System::EventArgs^ s){

						 cli::pin_ptr<int> pReaderCounter = &ReaderCounter;
						 char readernametemp[MAX_READER_NAME];
						 int offset = 0;

						 ret = PCSC_GetReaderList(handle, pReaderCounter, readernametemp);
						 if(ret == 0x9000){
							 for(int i = 0; i < ReaderCounter; i ++){
								 ReaderName[i] = String(readernametemp + offset).ToString();
								 offset += strlen(readernametemp);
								 offset += 1;
								 comboBox1->Items->Add(ReaderName[i]);
							 }
							 
						 }

					 }

private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(comboBox1->SelectedItem->Equals((String^)"Item 1")){
				textBox1->Text = "测试成功";
			 }

		 }
};
}

