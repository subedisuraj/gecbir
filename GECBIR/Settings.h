#pragma once

namespace GECBIR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{

	String^ galleryLocation; 
		
	public:
		Settings(void)
		{
			InitializeComponent();
	
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Okbtn;
	private: System::Windows::Forms::Button^  cancelbtn;

	private: System::Windows::Forms::Label^  SettingsPrompt;
	private: System::Windows::Forms::TextBox^  galleryPath;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;

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
			this->Okbtn = (gcnew System::Windows::Forms::Button());
			this->cancelbtn = (gcnew System::Windows::Forms::Button());
			this->SettingsPrompt = (gcnew System::Windows::Forms::Label());
			this->galleryPath = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->SuspendLayout();
			// 
			// Okbtn
			// 
			this->Okbtn->Location = System::Drawing::Point(106, 119);
			this->Okbtn->Name = L"Okbtn";
			this->Okbtn->Size = System::Drawing::Size(75, 23);
			this->Okbtn->TabIndex = 0;
			this->Okbtn->Text = L"OK";
			this->Okbtn->UseVisualStyleBackColor = true;
			this->Okbtn->Click += gcnew System::EventHandler(this, &Settings::button1_Click);
			// 
			// cancelbtn
			// 
			this->cancelbtn->Location = System::Drawing::Point(214, 118);
			this->cancelbtn->Name = L"cancelbtn";
			this->cancelbtn->Size = System::Drawing::Size(75, 23);
			this->cancelbtn->TabIndex = 1;
			this->cancelbtn->Text = L"Cancel";
			this->cancelbtn->UseVisualStyleBackColor = true;
			this->cancelbtn->Click += gcnew System::EventHandler(this, &Settings::cancelbtn_Click);
			// 
			// SettingsPrompt
			// 
			this->SettingsPrompt->AutoSize = true;
			this->SettingsPrompt->Location = System::Drawing::Point(47, 32);
			this->SettingsPrompt->Name = L"SettingsPrompt";
			this->SettingsPrompt->Size = System::Drawing::Size(265, 13);
			this->SettingsPrompt->TabIndex = 2;
			this->SettingsPrompt->Text = L"Please select the gallery folder to load the images from.";
			this->SettingsPrompt->Click += gcnew System::EventHandler(this, &Settings::label1_Click);
			// 
			// galleryPath
			// 
			this->galleryPath->Location = System::Drawing::Point(51, 57);
			this->galleryPath->Name = L"galleryPath";
			this->galleryPath->Size = System::Drawing::Size(185, 20);
			this->galleryPath->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(253, 55);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Browse";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Settings::button2_Click);
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(395, 154);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->galleryPath);
			this->Controls->Add(this->SettingsPrompt);
			this->Controls->Add(this->cancelbtn);
			this->Controls->Add(this->Okbtn);
			this->Name = L"Settings";
			this->Text = L"Settings";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 this->Hide();			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 FolderBrowserDialog^ fd = gcnew FolderBrowserDialog();
				 if((bool)fd->ShowDialog())
				 {
				
				 galleryPath->Text = fd->SelectedPath;
				 galleryLocation = galleryPath->Text;
				 }
    
			 }
			
private: System::Void cancelbtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 galleryPath->Text = galleryLocation;
			 this->Hide();
		 
		 }
};
}
