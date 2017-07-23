#pragma once

#include "Workspace.h"
#include <msclr\marshal_cppstd.h>
#include "Settings.h"
#include "ImageBox.h"
#include "ImageAnalyser.h"
#include <stdio.h>

namespace GECBIR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using std::string;
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
	private: System::Windows::Forms::Label^  similarBtnLabel;


	private: System::Windows::Forms::Label^  duplicatesBtnLabel;
	private: System::Windows::Forms::Button^  similarBtn;


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
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Button^  deleteBtn;
	private: System::Windows::Forms::Button^  findSimilarBtn;

	private: System::Windows::Forms::Button^  findduplicateBtn;

	private: System::Windows::Forms::FlowLayoutPanel^  auxDisplayPanel;
	private: System::Windows::Forms::Label^  loadDuplicatesLabel;












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
			this->auxDisplayPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->loadDuplicatesLabel = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->deleteBtn = (gcnew System::Windows::Forms::Button());
			this->findduplicateBtn = (gcnew System::Windows::Forms::Button());
			this->findSimilarBtn = (gcnew System::Windows::Forms::Button());
			this->settingsBtnLabel = (gcnew System::Windows::Forms::Label());
			this->imageBtn = (gcnew System::Windows::Forms::Button());
			this->settingsBtn = (gcnew System::Windows::Forms::Button());
			this->imageBtnLabel = (gcnew System::Windows::Forms::Label());
			this->similarBtnLabel = (gcnew System::Windows::Forms::Label());
			this->duplicatesBtnLabel = (gcnew System::Windows::Forms::Label());
			this->similarBtn = (gcnew System::Windows::Forms::Button());
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
			this->imageOptionsPanel->SuspendLayout();
			this->auxDisplayPanel->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
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
			this->mainPanel->Controls->Add(this->similarBtnLabel);
			this->mainPanel->Controls->Add(this->duplicatesBtnLabel);
			this->mainPanel->Controls->Add(this->similarBtn);
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
			this->splitContainer1->SplitterDistance = 692;
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
			this->imagesDisplayPanel->Size = System::Drawing::Size(686, 645);
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
			this->displayPanel->Size = System::Drawing::Size(678, 637);
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
			this->imageOptionsPanel->Controls->Add(this->auxDisplayPanel);
			this->imageOptionsPanel->Controls->Add(this->flowLayoutPanel1);
			this->imageOptionsPanel->Location = System::Drawing::Point(3, 3);
			this->imageOptionsPanel->Name = L"imageOptionsPanel";
			this->imageOptionsPanel->Size = System::Drawing::Size(402, 642);
			this->imageOptionsPanel->TabIndex = 0;
			// 
			// auxDisplayPanel
			// 
			this->auxDisplayPanel->AutoScroll = true;
			this->auxDisplayPanel->Controls->Add(this->loadDuplicatesLabel);
			this->auxDisplayPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->auxDisplayPanel->Location = System::Drawing::Point(0, 59);
			this->auxDisplayPanel->Name = L"auxDisplayPanel";
			this->auxDisplayPanel->Size = System::Drawing::Size(400, 581);
			this->auxDisplayPanel->TabIndex = 1;
			
			// 
			// loadDuplicatesLabel
			// 
			this->loadDuplicatesLabel->AutoSize = true;
			this->loadDuplicatesLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->loadDuplicatesLabel->Location = System::Drawing::Point(3, 0);
			this->loadDuplicatesLabel->Name = L"loadDuplicatesLabel";
			this->loadDuplicatesLabel->Padding = System::Windows::Forms::Padding(120, 20, 50, 5);
			this->loadDuplicatesLabel->Size = System::Drawing::Size(170, 38);
			this->loadDuplicatesLabel->TabIndex = 0;
			this->loadDuplicatesLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoSize = true;
			this->flowLayoutPanel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->flowLayoutPanel1->Controls->Add(this->deleteBtn);
			this->flowLayoutPanel1->Controls->Add(this->findduplicateBtn);
			this->flowLayoutPanel1->Controls->Add(this->findSimilarBtn);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(15);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Padding = System::Windows::Forms::Padding(15);
			this->flowLayoutPanel1->Size = System::Drawing::Size(400, 59);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// deleteBtn
			// 
			this->deleteBtn->Location = System::Drawing::Point(18, 18);
			this->deleteBtn->Name = L"deleteBtn";
			this->deleteBtn->Size = System::Drawing::Size(82, 23);
			this->deleteBtn->TabIndex = 3;
			this->deleteBtn->Text = L"Delete";
			this->deleteBtn->UseVisualStyleBackColor = true;
			this->deleteBtn->Click += gcnew System::EventHandler(this, &mainWindow::deleteBtn_Click);
			// 
			// findduplicateBtn
			// 
			this->findduplicateBtn->Location = System::Drawing::Point(106, 18);
			this->findduplicateBtn->Name = L"findduplicateBtn";
			this->findduplicateBtn->Size = System::Drawing::Size(97, 23);
			this->findduplicateBtn->TabIndex = 4;
			this->findduplicateBtn->Text = L"Find Duplicates";
			this->findduplicateBtn->UseVisualStyleBackColor = true;
			this->findduplicateBtn->Click += gcnew System::EventHandler(this, &mainWindow::findduplicateBtn_Click);
			// 
			// findSimilarBtn
			// 
			this->findSimilarBtn->Location = System::Drawing::Point(209, 18);
			this->findSimilarBtn->Name = L"findSimilarBtn";
			this->findSimilarBtn->Size = System::Drawing::Size(82, 23);
			this->findSimilarBtn->TabIndex = 5;
			this->findSimilarBtn->Text = L"Find Similar";
			this->findSimilarBtn->UseVisualStyleBackColor = true;
			this->findSimilarBtn->Click += gcnew System::EventHandler(this, &mainWindow::findSimilarBtn_Click);
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
			this->imageBtn->Click += gcnew System::EventHandler(this, &mainWindow::imageBtn_Click);
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
			this->settingsBtn->Click += gcnew System::EventHandler(this, &mainWindow::settingsBtn_Click);
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
			// similarBtnLabel
			// 
			this->similarBtnLabel->AutoSize = true;
			this->similarBtnLabel->Location = System::Drawing::Point(14, 352);
			this->similarBtnLabel->Name = L"similarBtnLabel";
			this->similarBtnLabel->Size = System::Drawing::Size(37, 13);
			this->similarBtnLabel->TabIndex = 9;
			this->similarBtnLabel->Text = L"Similar";
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
			// similarBtn
			// 
			this->similarBtn->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->similarBtn->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"similarBtn.Image")));
			this->similarBtn->Location = System::Drawing::Point(10, 301);
			this->similarBtn->Name = L"similarBtn";
			this->similarBtn->Size = System::Drawing::Size(52, 51);
			this->similarBtn->TabIndex = 8;
			this->similarBtn->UseVisualStyleBackColor = true;
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
			this->duplicatesBtn->Click += gcnew System::EventHandler(this, &mainWindow::duplicatesBtn_Click);
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
			this->foldersBtn->Click += gcnew System::EventHandler(this, &mainWindow::foldersBtn_Click);
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
			this->imageOptionsPanel->ResumeLayout(false);
			this->imageOptionsPanel->PerformLayout();
			this->auxDisplayPanel->ResumeLayout(false);
			this->auxDisplayPanel->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
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




		enum class modes {IMAGES_MODE,FOLDERS_MODE,DUPLICATES_MODE,SIMILAR_MODE}; 
		modes currentmode; 
		static Workspace * currentWorkspace; 
		Settings^ settingsWindow ;





	public:
		mainWindow(void)
		{
			InitializeComponent();
			refreshMainWindow();
			//TODO: Add the constructor code here
			//
		}

		void refreshMainWindow()
		{

			settingsWindow = gcnew Settings();
			InitializeSettings();
			InitializeDisplayPanel();
			
		}


		void InitializeSettings()
		{
			currentmode = modes::IMAGES_MODE; 
			currentWorkspace = new Workspace();
		}

		void InitializeDisplayPanel()
		{
			displayPanel->Controls->Clear();
			vector<ImageInfo> allImages = currentWorkspace->getAllImageLists();
			Dir d = Dir(currentWorkspace->galleryFolderName,currentWorkspace->galleryPath);
			d.imagePaths = allImages;
			LoadImagesDisplayPanel(d);

		}


		void LoadImagesDisplayPanel(Dir d)
		{
			//for folder path
			Label^ galleryPath = createLabel(d.path);
			galleryPath->AutoSize = true;
			galleryPath->ForeColor = Color::Gray;

			//change label font size
			float currentSize = galleryPath->Font->Size;
			currentSize += 5.0F;
			galleryPath->Font = gcnew System::Drawing::Font(galleryPath->Font->Name,currentSize, galleryPath->Font->Style);
			displayPanel->Controls->Add(galleryPath);

			//for border line
			Label^ borderline = gcnew Label();
			borderline->BorderStyle = BorderStyle::Fixed3D;
			borderline-> Width = displayPanel->Width;
			borderline-> Height = 2; 
			displayPanel->Controls->Add(borderline);


			FlowLayoutPanel^ fp = gcnew FlowLayoutPanel();
			fp->Width = displayPanel -> Width;
			fp->AutoSize = true;


			for(int i =0; i < d.imagePaths.size(); i++)
			{
				String^ imageName = getManagedString(d.imagePaths[i].ImageName);
				String^ imagePath = getManagedString (d.imagePaths[i].ImagePath);
				ImageBox^ ib = gcnew ImageBox(imageName, imagePath);
				fp->Controls->Add(ib);
			}
			displayPanel->Controls->Add(fp);

		}

		void LoadDuplicateImages(string ImagePath, vector<ImageInfo > dupImages, FlowLayoutPanel^  imagePanel )
		{
			//Label^ galleryPath = createLabel("Duplicate Images of " + ImagePath);
			//galleryPath->AutoSize = true;

			//change label font size
			/*float currentSize = galleryPath->Font->Size;
			currentSize += 5.0F;
			galleryPath->Font = gcnew System::Drawing::Font(galleryPath->Font->Name,currentSize, galleryPath->Font->Style);*/
			//auxDisplayPanel->Controls->Add(galleryPath);

			//for border line
			Label^ borderline = gcnew Label();
			borderline->BorderStyle = BorderStyle::Fixed3D;
			borderline-> Width = imagePanel->Width;
			borderline-> Height = 2; 
			imagePanel->Controls->Add(borderline);

			FlowLayoutPanel^ fp = gcnew FlowLayoutPanel();
			fp->Width = displayPanel -> Width;
			fp->AutoSize = true;


			for(int i =0; i < dupImages.size(); i++)
			{
				String^ imageName = getManagedString( dupImages[i].ImageName);
				String^ imagePath = getManagedString (dupImages[i].ImagePath);
				ImageBox^ ib = gcnew ImageBox(imageName, imagePath);
				fp->Controls->Add(ib);
			}
			imagePanel->Controls->Add(fp);

		}


		String^ getManagedString(string unmanagedString)
		{
			return msclr::interop::marshal_as<System::String^>(unmanagedString);
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

		void LoadSimilarDisplayPanel()
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


	private: System::Void settingsBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				 settingsWindow->Show();
			 }



	private: System::Void foldersBtn_Click(System::Object^  sender, System::EventArgs^  e) {

				 displayPanel->Controls->Clear();
				 for(int i=0; i<currentWorkspace->directoryList.size(); i++)
				 {
					 if(currentWorkspace->directoryList[i].imagePaths.size() > 0)
						 LoadImagesDisplayPanel(currentWorkspace->directoryList[i]);
				 }
			 }


	private: System::Void imageBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				 currentWorkspace->InitializeGalleryPath();
				 refreshMainWindow();
				 displayPanel->Controls->Clear();
				 vector<ImageInfo > allImages = currentWorkspace->getAllImageLists();
				 Dir d = Dir(currentWorkspace->galleryFolderName,currentWorkspace->galleryPath);
				 d.imagePaths = allImages;
				 LoadImagesDisplayPanel(d);

			 }

	private: System::Void deleteBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				
				 vector<string> selectedImagesList = ImageBox::getSelectionListVector(ImageBox::auxselectionList);
				 for(int i =0; i< selectedImagesList.size(); i++)
				 {
					 //auxDisplayPanel->Controls->RemoveByKey(getManagedString(selectedImagesList[i])); 
					 DeleteFile(selectedImagesList[i].c_str());
				 }
				 refreshMainWindow();
				 auxDisplayPanel->Controls->Clear();
				 
			 }


	private: System::Void findduplicateBtn_Click(System::Object^  sender, System::EventArgs^  e) {

				 vector<string> selectedImagesList = ImageBox::getSelectionListVector(ImageBox::selectionList);
				 auxDisplayPanel->Controls->Clear();
				 int dupImageCount = 0;
				 for(int i=0; i<selectedImagesList.size(); i++)
				 {
					 ImageInfo imginf = ImageInfo("",selectedImagesList[i]);
					 ImageAnalyser selectedImage = ImageAnalyser(imginf);
					 vector<ImageInfo > dupImages = selectedImage.findDuplicates();
					 if(dupImages.size()>0)
					 {
						 LoadDuplicateImages(selectedImage.imagefile.ImagePath, dupImages, auxDisplayPanel);
					 }
					
					 dupImageCount += dupImages.size();
					
				 }
				 if(!dupImageCount)
				 {
					 loadDuplicatesLabel->Text = "No duplicate images found.";
					 auxDisplayPanel->Controls->Add(loadDuplicatesLabel);
				 }

			 }

	private: System::Void duplicatesBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				 //vector<ImageInfo > allImagesList = currentWorkspace->getAllImageLists();
				 //displayPanel->Controls->Clear();
				 //for(int i=0; i<allImagesList.size(); i++)
				 //{
					// ImageAnalyser selectedImage = ImageAnalyser(allImagesList[i]);
					// vector<ImageInfo > dupImages = selectedImage.findDuplicates();
					// //make a list of duplicate images using hash table image->list of duplicate image locations 
					// if(dupImages.size()>0)
					// {
					//	 LoadDuplicateImages(selectedImage.imagefile.ImagePath, dupImages, displayPanel);
					// }
				 //}
			 }


private: System::Void findSimilarBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			  vector<string> selectedImagesList = ImageBox::getSelectionListVector(ImageBox::selectionList);
				 auxDisplayPanel->Controls->Clear();
				 int dupImageCount = 0;
				 for(int i=0; i<selectedImagesList.size(); i++)
				 {
					 ImageInfo imginf = ImageInfo("",selectedImagesList[i]);
					 ImageAnalyser selectedImage = ImageAnalyser(imginf);
					 vector<ImageInfo > dupImages = selectedImage.findSimilarImages();
					 if(dupImages.size()>0)
					 {
						 LoadDuplicateImages(selectedImage.imagefile.ImagePath, dupImages, auxDisplayPanel);
					 }
					
					 dupImageCount += dupImages.size();
					
				 }
				 if(!dupImageCount)
				 {
					 loadDuplicatesLabel->Text = "No similar images found.";
					 auxDisplayPanel->Controls->Add(loadDuplicatesLabel);
				 }

		 }
};

}
