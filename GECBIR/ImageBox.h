#pragma once
#include "Workspace.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



namespace GECBIR {


	public ref class ImageBox : public System::Windows::Forms::UserControl
	{
	public:


		ImageBox(String^imgName, String^imgPath )
		{
			//InitializeComponent();
			/*	int imageSize = 50;
			pictureBox1 = gcnew PictureBox();
			pictureBox1->Size = System::Drawing::Size(imageSize, imageSize);
			pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
			pictureBox1->ImageLocation = imgPath ; 
			pictureBox1->SizeMode = PictureBoxSizeMode::Normal;*/
			InitializeComponent();
			AddPicture(imgName, imgPath);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ImageBox()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  imgName;
	private: Boolean isSelected;


	protected: 

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->imgName = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(7, 7);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(184, 174);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &ImageBox::ImageBox_Click);
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &ImageBox::ImageBox_MouseLeave);
			this->pictureBox1->MouseHover += gcnew System::EventHandler(this, &ImageBox::ImageBox_MouseHover);
			// 
			// imgName
			// 
			this->imgName->AutoSize = true;
			this->imgName->Location = System::Drawing::Point(15, 184);
			this->imgName->Name = L"imgName";
			this->imgName->Size = System::Drawing::Size(0, 13);
			this->imgName->TabIndex = 1;
			// 
			// ImageBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->imgName);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"ImageBox";
			this->Size = System::Drawing::Size(194, 204);
			this->Click += gcnew System::EventHandler(this, &ImageBox::ImageBox_Click);
			this->MouseLeave += gcnew System::EventHandler(this, &ImageBox::ImageBox_MouseLeave);
			this->MouseHover += gcnew System::EventHandler(this, &ImageBox::ImageBox_MouseHover);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	public:
		void AddPicture(String^ imgName, String^ imgPath)
		{
			this->pictureBox1->Size = System::Drawing::Size(170, 170);
			this->pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
			this->pictureBox1->ImageLocation = imgPath ; 
			this->pictureBox1->Text = imgPath;
			this->pictureBox1->SizeMode = PictureBoxSizeMode::Normal;
			this->imgName->Text = imgName;
		}



	private: System::Void ImageBox_Click(System::Object^  sender, System::EventArgs^  e) {
				 if( this->isSelected )
				 {
					 this->isSelected = false;
					 this->BackColor=SystemColors::Control;
				 }
				 
				 else
				 {
					 this->isSelected = true;
					 this->BackColor=System::Drawing::Color::LightBlue;
				 } 

			 }
	private: System::Void ImageBox_MouseHover(System::Object^  sender, System::EventArgs^  e) {
				 this->BackColor=System::Drawing::Color::LightBlue;
			 }


	private: System::Void ImageBox_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
				 if(! this->isSelected)
					 this->BackColor=SystemColors::Control;
			 }
	};
}
