#pragma once

#include "Workspace.h"
#include <msclr\marshal_cppstd.h>



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
	private: System::Windows::Forms::FlowLayoutPanel^  displayPanel;





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
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->imagesDisplayPanel = (gcnew System::Windows::Forms::Panel());
			this->displayPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->imageOptionsPanel = (gcnew System::Windows::Forms::Panel());
			this->settingsBtnLabel = (gcnew System::Windows::Forms::Label());
			this->imageBtn = (gcnew System::Windows::Forms::Button());
			this->settingsBtn = (gcnew System::Windows::Forms::Button());
			this->imageBtnLabel = (gcnew System::Windows::Forms::Label());
			this->relatedBtnLabel = (gcnew System::Windows::Forms::Label());
			this->duplicatesBtnLabel = (gcnew System::Windows::Forms::Label());
			this->relatedBtn = (gcnew System::Windows::Forms::Button());
			this->duplicatesBtn = (gcnew System::Windows::Forms::Button());
			this->foldersbtnLabel = (gcnew System::Windows::Forms::Label());
			this->foldersBtn = (gcnew System::Windows::Forms::Button());
			this->titleBarPanel = (gcnew System::Windows::Forms::Panel());
			this->optionsPanel = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->mainPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->imagesDisplayPanel->SuspendLayout();
			this->titleBarPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// mainPanel
			// 
			this->mainPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->mainPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
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
			this->mainPanel->Size = System::Drawing::Size(1178, 712);
			this->mainPanel->TabIndex = 0;
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
			this->splitContainer1->Size = System::Drawing::Size(1104, 648);
			this->splitContainer1->SplitterDistance = 849;
			this->splitContainer1->TabIndex = 14;
			// 
			// imagesDisplayPanel
			// 
			this->imagesDisplayPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->imagesDisplayPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->imagesDisplayPanel->Controls->Add(this->displayPanel);
			this->imagesDisplayPanel->Location = System::Drawing::Point(3, 3);
			this->imagesDisplayPanel->Name = L"imagesDisplayPanel";
			this->imagesDisplayPanel->Size = System::Drawing::Size(843, 645);
			this->imagesDisplayPanel->TabIndex = 0;
			// 
			// displayPanel
			// 
			this->displayPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->displayPanel->AutoScroll = true;
			this->displayPanel->AutoScrollMinSize = System::Drawing::Size(10, 10);
			this->displayPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->displayPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->displayPanel->Location = System::Drawing::Point(3, 3);
			this->displayPanel->Name = L"displayPanel";
			this->displayPanel->Size = System::Drawing::Size(835, 637);
			this->displayPanel->TabIndex = 0;
			this->displayPanel->WrapContents = false;
			// 
			// imageOptionsPanel
			// 
			this->imageOptionsPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->imageOptionsPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->imageOptionsPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->imageOptionsPanel->Location = System::Drawing::Point(3, 3);
			this->imageOptionsPanel->Name = L"imageOptionsPanel";
			this->imageOptionsPanel->Size = System::Drawing::Size(245, 642);
			this->imageOptionsPanel->TabIndex = 0;
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
			// imageBtn
			// 
			this->imageBtn->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->imageBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"imageBtn.Image")));
			this->imageBtn->Location = System::Drawing::Point(10, 61);
			this->imageBtn->Name = L"imageBtn";
			this->imageBtn->Size = System::Drawing::Size(52, 51);
			this->imageBtn->TabIndex = 12;
			this->imageBtn->UseVisualStyleBackColor = true;
			// 
			// settingsBtn
			// 
			this->settingsBtn->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->settingsBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"settingsBtn.Image")));
			this->settingsBtn->Location = System::Drawing::Point(11, 379);
			this->settingsBtn->Name = L"settingsBtn";
			this->settingsBtn->Size = System::Drawing::Size(52, 51);
			this->settingsBtn->TabIndex = 10;
			this->settingsBtn->UseVisualStyleBackColor = true;
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
			// relatedBtnLabel
			// 
			this->relatedBtnLabel->AutoSize = true;
			this->relatedBtnLabel->Location = System::Drawing::Point(14, 352);
			this->relatedBtnLabel->Name = L"relatedBtnLabel";
			this->relatedBtnLabel->Size = System::Drawing::Size(44, 13);
			this->relatedBtnLabel->TabIndex = 9;
			this->relatedBtnLabel->Text = L"Related";
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
			// relatedBtn
			// 
			this->relatedBtn->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->relatedBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"relatedBtn.Image")));
			this->relatedBtn->Location = System::Drawing::Point(10, 301);
			this->relatedBtn->Name = L"relatedBtn";
			this->relatedBtn->Size = System::Drawing::Size(52, 51);
			this->relatedBtn->TabIndex = 8;
			this->relatedBtn->UseVisualStyleBackColor = true;
			// 
			// duplicatesBtn
			// 
			this->duplicatesBtn->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->duplicatesBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"duplicatesBtn.Image")));
			this->duplicatesBtn->Location = System::Drawing::Point(10, 218);
			this->duplicatesBtn->Name = L"duplicatesBtn";
			this->duplicatesBtn->Size = System::Drawing::Size(52, 51);
			this->duplicatesBtn->TabIndex = 10;
			this->duplicatesBtn->UseVisualStyleBackColor = true;
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
			this->foldersBtn->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->foldersBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"foldersBtn.Image")));
			this->foldersBtn->Location = System::Drawing::Point(10, 137);
			this->foldersBtn->Name = L"foldersBtn";
			this->foldersBtn->Size = System::Drawing::Size(52, 51);
			this->foldersBtn->TabIndex = 5;
			this->foldersBtn->UseVisualStyleBackColor = true;
			// 
			// titleBarPanel
			// 
			this->titleBarPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->titleBarPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->titleBarPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->titleBarPanel->Controls->Add(this->optionsPanel);
			this->titleBarPanel->Controls->Add(this->textBox1);
			this->titleBarPanel->Location = System::Drawing::Point(3, 3);
			this->titleBarPanel->Name = L"titleBarPanel";
			this->titleBarPanel->Size = System::Drawing::Size(1172, 55);
			this->titleBarPanel->TabIndex = 0;
			// 
			// optionsPanel
			// 
			this->optionsPanel->Location = System::Drawing::Point(3, 57);
			this->optionsPanel->Name = L"optionsPanel";
			this->optionsPanel->Size = System::Drawing::Size(61, 428);
			this->optionsPanel->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->ForeColor = System::Drawing::SystemColors::ScrollBar;
			this->textBox1->Location = System::Drawing::Point(117, 17);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(661, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"Search Images";
			// 
			// mainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1182, 714);
			this->Controls->Add(this->mainPanel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"mainWindow";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Image Finder";
			this->ResizeEnd += gcnew System::EventHandler(this, &mainWindow::mainWindow_ResizeEnd);
			this->mainPanel->ResumeLayout(false);
			this->mainPanel->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->imagesDisplayPanel->ResumeLayout(false);
			this->titleBarPanel->ResumeLayout(false);
			this->titleBarPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		//// Initialization region end
		////..........................................................................................................................................
		////..........................................................................................................................................
		////..........................................................................................................................................


	public:
		FlowLayoutPanel^ flowImagesDisplayPanel ;




		enum class modes {IMAGES_MODE,FOLDERS_MODE,DUPLICATES_MODE,RELATED_MODE}; 
		modes currentmode; 
		Workspace * currentWorkspace; 






	public:
		mainWindow(void)
		{
			InitializeComponent();
			InitializeSettings();
			InitializeDisplayPanel();
			
			//TODO: Add the constructor code here
			//
		}


		void InitializeSettings()
		{
			currentmode = modes::IMAGES_MODE; 
			currentWorkspace = new Workspace();
		}

		void InitializeDisplayPanel()
		{
			LoadImagesDisplayPanel();
		}


		void LoadImagesDisplayPanel()
		{
		//	flowImagesDisplayPanel = gcnew FlowLayoutPanel();
		//	flowImagesDisplayPanel->BorderStyle = BorderStyle::FixedSingle;
		//	flowImagesDisplayPanel->Size = displayPanel->Size;
		////	flowImagesDisplayPanel->MinimumSize = System::Drawing::Size( 200, 200 );
		////	flowImagesDisplayPanel->Anchor = displayPanel->Anchor;
		//	flowImagesDisplayPanel->AutoScroll = TRUE;
		//	flowImagesDisplayPanel->AutoScrollMinSize = System::Drawing::Size(200,200 );
		////	flowImagesDisplayPanel->AutoScrollMinSize = flowImagesDisplayPanel->GetPreferredSize(new Size(1, 1));
		//	//flowImagesDisplayPanel->AutoScrollMinSize = displayPanel->Size;
		//	flowImagesDisplayPanel->FlowDirection = FlowDirection::TopDown ;
		//	flowImagesDisplayPanel->WrapContents = FALSE;
		//	flowImagesDisplayPanel->Anchor = displayPanel->Anchor;
		////	flowImagesDisplayPanel->Dock = DockStyle::Fill;
		//	//flowImagesDisplayPanel->AutoSize = TRUE;
		////	flowImagesDisplayPanel->AutoSizeMode =  AutoSizeMode->GrowAndShrink;
			
		
			for(int i =0; i<=100; i++)
			{
				Label^ galleryPath = createLabel(currentWorkspace->galleryPath);
				displayPanel->Controls->Add(galleryPath);
			}
			//this->displayPanel->Controls->Add(imageDisplayGroup);

		}

		Label^ createLabel(string labelString)
		{
			System::String^ managedlabelString = msclr::interop::marshal_as<System::String^>(labelString);
			Label^ newLabel = gcnew Label();
			newLabel->Text = managedlabelString;
			return newLabel;
		}

		void LoadFoldersDisplayPanel()
		{

		}

		void LoadDuplicatesDisplayPaenel()
		{

		}

		void LoadRelatedDisplayPanel()
		{

		}








	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 addcuda();
			 }

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

	private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
	private: System::Void flowDisplayPanel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

				 FlowLayoutPanel^ f1 = (gcnew FlowLayoutPanel());
				 Button^ b1 = (gcnew Button());



			 }









	private: System::Void mainWindow_ResizeEnd(System::Object^  sender, System::EventArgs^  e) {
			//	 flowImagesDisplayPanel->Size = displayPanel->Size;
			 }
};

}
