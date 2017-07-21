#pragma once
#include "Workspace.h"
#include <set>


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using std::set;


namespace GECBIR {


	public ref class ImageBox : public System::Windows::Forms::UserControl
	{
	public:


		ImageBox(String^imgName, String^imgPath )
		{

			InitializeComponent();
			isSelected = false;
			this->imageId = imageId++;
			this->imagePath = imgPath;
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
			 static int imageId = 0;

	public:	String^ imagePath;
	static	 set<string> * selectionList = new set<string>();
			

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
			this->pictureBox1->Size = System::Drawing::Size(180, 180);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &ImageBox::ImageBox_Click);
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &ImageBox::ImageBox_MouseLeave);
			this->pictureBox1->MouseHover += gcnew System::EventHandler(this, &ImageBox::ImageBox_MouseHover);
			// 
			// imgName
			// 
			this->imgName->AutoSize = true;
			this->imgName->Font = (gcnew System::Drawing::Font(L"Century", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->imgName->Location = System::Drawing::Point(6, 190);
			this->imgName->Name = L"imgName";
			this->imgName->Size = System::Drawing::Size(43, 18);
			this->imgName->TabIndex = 1;
			this->imgName->Text = L"hello";
			this->imgName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ImageBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->imgName);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"ImageBox";
			this->Size = System::Drawing::Size(194, 213);
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
			this->pictureBox1->Size = System::Drawing::Size(180, 180);
			this->pictureBox1->ImageLocation = imgPath ; 
			this->pictureBox1->Text = imgPath;
			this->imgName->Text = imgName;
		}

		static vector<string> getSelectionListVector()
		{
			std::set<string>& selectionListValue = *selectionList;
			std::vector<string> selectionListVector(selectionListValue.size());
			std::copy(selectionListValue.begin(), selectionListValue.end(), selectionListVector.begin());
			return selectionListVector;
		}



	private: System::Void ImageBox_Click(System::Object^  sender, System::EventArgs^  e) {
				 if( this->isSelected )
				 {
					 this->isSelected = false;
					 selectionList->erase(getUnmanagedString( this->imagePath));
					 this->BackColor=SystemColors::Control;
				 }
				 
				 else
				 {
					 this->isSelected = true;
					 selectionList->insert(getUnmanagedString( this->imagePath));
					 this->BackColor=System::Drawing::Color::LightBlue;
				 } 

			 }

	private: System::Void ImageBox_MouseHover(System::Object^  sender, System::EventArgs^  e) {
				 ToolTip^ tt = gcnew ToolTip();
				 tt->SetToolTip(this->pictureBox1, this->imagePath);
				 this->BackColor=System::Drawing::Color::LightBlue;
			 }


	private: System::Void ImageBox_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
				 if(! this->isSelected)
					 this->BackColor=SystemColors::Control;
			 }
	};
}
