#pragma once

namespace GECBIR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	int addcuda();

	/// <summary>
	/// Main window of the GECBIR Program 
	/// </summary>
	public ref class mainWindow : public System::Windows::Forms::Form
	{
		//// Initialization region start
		////..........................................................................................................................................
		////..........................................................................................................................................
		////..........................................................................................................................................
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  mainPanel;
	protected: 
	private: System::Windows::Forms::Button^  imageBtn;
	private: System::Windows::Forms::Label^  imageBtnLabel;
	private: System::Windows::Forms::Label^  relatedBtnLabel;

	private: System::Windows::Forms::Label^  duplicatesBtnLabel;
	private: System::Windows::Forms::Button^  relatedBtn;

	private: System::Windows::Forms::Button^  duplicatesBtn;
	private: System::Windows::Forms::Label^  foldersbtnLabel;

	private: System::Windows::Forms::Button^  foldersBtn;
	private: System::Windows::Forms::Panel^  titleBarPanel;
	private: System::Windows::Forms::Panel^  optionsPanel;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  settingsBtnLabel;
	private: System::Windows::Forms::Button^  settingsBtn;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Panel^  imagesDisplayPanel;
	private: System::Windows::Forms::Panel^  imageOptionsPanel;

















	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mainWindow::typeid));
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->titleBarPanel = (gcnew System::Windows::Forms::Panel());
			this->optionsPanel = (gcnew System::Windows::Forms::Panel());
			this->foldersbtnLabel = (gcnew System::Windows::Forms::Label());
			this->foldersBtn = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->relatedBtnLabel = (gcnew System::Windows::Forms::Label());
			this->relatedBtn = (gcnew System::Windows::Forms::Button());
			this->duplicatesBtnLabel = (gcnew System::Windows::Forms::Label());
			this->duplicatesBtn = (gcnew System::Windows::Forms::Button());
			this->imageBtnLabel = (gcnew System::Windows::Forms::Label());
			this->imageBtn = (gcnew System::Windows::Forms::Button());
			this->settingsBtnLabel = (gcnew System::Windows::Forms::Label());
			this->settingsBtn = (gcnew System::Windows::Forms::Button());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->imagesDisplayPanel = (gcnew System::Windows::Forms::Panel());
			this->imageOptionsPanel = (gcnew System::Windows::Forms::Panel());
			this->mainPanel->SuspendLayout();
			this->titleBarPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainPanel
			// 
			this->mainPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->mainPanel->Controls->Add(this->splitContainer1);
			this->mainPanel->Controls->Add(this->settingsBtnLabel);
			this->mainPanel->Controls->Add(this->imageBtn);
			this->mainPanel->Controls->Add(this->settingsBtn);
			this->mainPanel->Controls->Add(this->imageBtnLabel);
			this->mainPanel->Controls->Add(this->relatedBtnLabel);
			this->mainPanel->Controls->Add(this->duplicatesBtnLabel);
			this->mainPanel->Controls->Add(this->relatedBtn);
			this->mainPanel->Controls->Add(this->duplicatesBtn);
			this->mainPanel->Controls->Add(this->foldersbtnLabel);
			this->mainPanel->Controls->Add(this->foldersBtn);
			this->mainPanel->Controls->Add(this->titleBarPanel);
			this->mainPanel->Location = System::Drawing::Point(2, 1);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Size = System::Drawing::Size(967, 531);
			this->mainPanel->TabIndex = 0;
			// 
			// titleBarPanel
			// 
			this->titleBarPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->titleBarPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->titleBarPanel->Controls->Add(this->optionsPanel);
			this->titleBarPanel->Controls->Add(this->textBox1);
			this->titleBarPanel->Location = System::Drawing::Point(3, 3);
			this->titleBarPanel->Name = L"titleBarPanel";
			this->titleBarPanel->Size = System::Drawing::Size(961, 55);
			this->titleBarPanel->TabIndex = 0;
			// 
			// optionsPanel
			// 
			this->optionsPanel->Location = System::Drawing::Point(3, 57);
			this->optionsPanel->Name = L"optionsPanel";
			this->optionsPanel->Size = System::Drawing::Size(61, 428);
			this->optionsPanel->TabIndex = 1;
			// 
			// foldersbtnLabel
			// 
			this->foldersbtnLabel->AutoSize = true;
			this->foldersbtnLabel->Location = System::Drawing::Point(16, 188);
			this->foldersbtnLabel->Name = L"foldersbtnLabel";
			this->foldersbtnLabel->Size = System::Drawing::Size(41, 13);
			this->foldersbtnLabel->TabIndex = 7;
			this->foldersbtnLabel->Text = L"Folders";
			// 
			// foldersBtn
			// 
			this->foldersBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"foldersBtn.Image")));
			this->foldersBtn->Location = System::Drawing::Point(10, 137);
			this->foldersBtn->Name = L"foldersBtn";
			this->foldersBtn->Size = System::Drawing::Size(52, 51);
			this->foldersBtn->TabIndex = 5;
			this->foldersBtn->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->textBox1->Location = System::Drawing::Point(281, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(450, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"Search Images";
			// 
			// relatedBtnLabel
			// 
			this->relatedBtnLabel->AutoSize = true;
			this->relatedBtnLabel->Location = System::Drawing::Point(14, 352);
			this->relatedBtnLabel->Name = L"relatedBtnLabel";
			this->relatedBtnLabel->Size = System::Drawing::Size(44, 13);
			this->relatedBtnLabel->TabIndex = 9;
			this->relatedBtnLabel->Text = L"Related";
			// 
			// relatedBtn
			// 
			this->relatedBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"relatedBtn.Image")));
			this->relatedBtn->Location = System::Drawing::Point(10, 301);
			this->relatedBtn->Name = L"relatedBtn";
			this->relatedBtn->Size = System::Drawing::Size(52, 51);
			this->relatedBtn->TabIndex = 8;
			this->relatedBtn->UseVisualStyleBackColor = true;
			// 
			// duplicatesBtnLabel
			// 
			this->duplicatesBtnLabel->AutoSize = true;
			this->duplicatesBtnLabel->Location = System::Drawing::Point(8, 269);
			this->duplicatesBtnLabel->Name = L"duplicatesBtnLabel";
			this->duplicatesBtnLabel->Size = System::Drawing::Size(57, 13);
			this->duplicatesBtnLabel->TabIndex = 11;
			this->duplicatesBtnLabel->Text = L"Duplicates";
			// 
			// duplicatesBtn
			// 
			this->duplicatesBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"duplicatesBtn.Image")));
			this->duplicatesBtn->Location = System::Drawing::Point(10, 218);
			this->duplicatesBtn->Name = L"duplicatesBtn";
			this->duplicatesBtn->Size = System::Drawing::Size(52, 51);
			this->duplicatesBtn->TabIndex = 10;
			this->duplicatesBtn->UseVisualStyleBackColor = true;
			// 
			// imageBtnLabel
			// 
			this->imageBtnLabel->AutoSize = true;
			this->imageBtnLabel->Location = System::Drawing::Point(15, 112);
			this->imageBtnLabel->Name = L"imageBtnLabel";
			this->imageBtnLabel->Size = System::Drawing::Size(41, 13);
			this->imageBtnLabel->TabIndex = 13;
			this->imageBtnLabel->Text = L"Images";
			// 
			// imageBtn
			// 
			this->imageBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"imageBtn.Image")));
			this->imageBtn->Location = System::Drawing::Point(10, 61);
			this->imageBtn->Name = L"imageBtn";
			this->imageBtn->Size = System::Drawing::Size(52, 51);
			this->imageBtn->TabIndex = 12;
			this->imageBtn->UseVisualStyleBackColor = true;
			// 
			// settingsBtnLabel
			// 
			this->settingsBtnLabel->AutoSize = true;
			this->settingsBtnLabel->Location = System::Drawing::Point(15, 430);
			this->settingsBtnLabel->Name = L"settingsBtnLabel";
			this->settingsBtnLabel->Size = System::Drawing::Size(45, 13);
			this->settingsBtnLabel->TabIndex = 11;
			this->settingsBtnLabel->Text = L"Settings";
			// 
			// settingsBtn
			// 
			this->settingsBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"settingsBtn.Image")));
			this->settingsBtn->Location = System::Drawing::Point(11, 379);
			this->settingsBtn->Name = L"settingsBtn";
			this->settingsBtn->Size = System::Drawing::Size(52, 51);
			this->settingsBtn->TabIndex = 10;
			this->settingsBtn->UseVisualStyleBackColor = true;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->Location = System::Drawing::Point(71, 61);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->imagesDisplayPanel);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &mainWindow::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->imageOptionsPanel);
			this->splitContainer1->Size = System::Drawing::Size(893, 467);
			this->splitContainer1->SplitterDistance = 687;
			this->splitContainer1->TabIndex = 14;
			// 
			// imagesDisplayPanel
			// 
			this->imagesDisplayPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->imagesDisplayPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->imagesDisplayPanel->Location = System::Drawing::Point(3, 3);
			this->imagesDisplayPanel->Name = L"imagesDisplayPanel";
			this->imagesDisplayPanel->Size = System::Drawing::Size(681, 464);
			this->imagesDisplayPanel->TabIndex = 0;
			// 
			// imageOptionsPanel
			// 
			this->imageOptionsPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->imageOptionsPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->imageOptionsPanel->Location = System::Drawing::Point(3, 3);
			this->imageOptionsPanel->Name = L"imageOptionsPanel";
			this->imageOptionsPanel->Size = System::Drawing::Size(196, 461);
			this->imageOptionsPanel->TabIndex = 0;
			// 
			// mainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(971, 533);
			this->Controls->Add(this->mainPanel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"mainWindow";
			this->Text = L"Image Finder";
			this->mainPanel->ResumeLayout(false);
			this->mainPanel->PerformLayout();
			this->titleBarPanel->ResumeLayout(false);
			this->titleBarPanel->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		//// Initialization region end
		////..........................................................................................................................................
		////..........................................................................................................................................
		////..........................................................................................................................................




	public:
		mainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 addcuda();
			 }

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
};

}
