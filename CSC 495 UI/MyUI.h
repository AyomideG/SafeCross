#pragma once

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/videoio/videoio.hpp>
#include<opencv2/video/video.hpp>
#include<opencv2/video/tracking.hpp>
#include<opencv2/video/background_segm.hpp>

#include<iostream>
#include<conio.h>           // it may be necessary to change or remove this line if not using Windows
#include <exception>
#include <msclr\marshal_cppstd.h>
#include <fstream>

#include "Blob.h"
#include "Header.h"

const cv::Scalar SCALAR_BLACK = cv::Scalar(0.0, 0.0, 0.0);
const cv::Scalar SCALAR_WHITE = cv::Scalar(255.0, 255.0, 255.0);
const cv::Scalar SCALAR_YELLOW = cv::Scalar(0.0, 255.0, 255.0);
const cv::Scalar SCALAR_GREEN = cv::Scalar(0.0, 200.0, 0.0);
const cv::Scalar SCALAR_RED = cv::Scalar(0.0, 0.0, 255.0);

namespace CSC495UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace cams;
	using namespace std;

	/// <summary>
	/// Summary for MyUI

	cv::VideoCapture capVideo(0);
	cv::VideoCapture capVideo2(1);

	Camera cam;

	std::vector<Blob> blobs;
	std::vector<Blob> blobs2;

	cv::Point crossingLine[2];
	cv::Point crossingLine2[2];

	int carCount = 0;

	/// </summary>
	public ref class MyUI : public System::Windows::Forms::Form
	{
	public:
		MyUI(void)
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
		~MyUI()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:

	protected:


	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  btnSelect;
	private: System::Windows::Forms::TextBox^  txtInput;
	private: System::Windows::Forms::Button^  btnReset;
	private: System::Windows::Forms::Button^  btnPlay;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtSpeeds;
	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;


	private: System::Windows::Forms::Button^  btnStop;

	private: System::Windows::Forms::Panel^  panel1;

	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::Button^  btnPlay2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  txtCount;





	private: System::ComponentModel::IContainer^  components;









	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->btnSelect = (gcnew System::Windows::Forms::Button());
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtSpeeds = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnPlay2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->txtCount = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// btnSelect
			// 
			this->btnSelect->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnSelect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnSelect->Location = System::Drawing::Point(465, 43);
			this->btnSelect->Name = L"btnSelect";
			this->btnSelect->Size = System::Drawing::Size(417, 53);
			this->btnSelect->TabIndex = 0;
			this->btnSelect->Text = L"Select a Video";
			this->btnSelect->UseVisualStyleBackColor = false;
			this->btnSelect->Click += gcnew System::EventHandler(this, &MyUI::btnSelect_Click);
			// 
			// txtInput
			// 
			this->txtInput->Location = System::Drawing::Point(925, 46);
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(801, 38);
			this->txtInput->TabIndex = 1;
			// 
			// btnReset
			// 
			this->btnReset->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btnReset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnReset->Location = System::Drawing::Point(28, 68);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(310, 72);
			this->btnReset->TabIndex = 3;
			this->btnReset->Text = L"Reset Video";
			this->btnReset->UseVisualStyleBackColor = false;
			this->btnReset->Click += gcnew System::EventHandler(this, &MyUI::btnReset_Click);
			// 
			// btnPlay
			// 
			this->btnPlay->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btnPlay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnPlay->ForeColor = System::Drawing::Color::DarkGreen;
			this->btnPlay->Location = System::Drawing::Point(1605, 182);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(421, 61);
			this->btnPlay->TabIndex = 4;
			this->btnPlay->Text = L"Start Vehicle View";
			this->btnPlay->UseVisualStyleBackColor = false;
			this->btnPlay->Click += gcnew System::EventHandler(this, &MyUI::btnPlay_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(48, 320);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(224, 36);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Vehicle Count:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(48, 400);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(246, 36);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Vehicle Speeds:";
			// 
			// txtSpeeds
			// 
			this->txtSpeeds->Location = System::Drawing::Point(28, 452);
			this->txtSpeeds->Multiline = true;
			this->txtSpeeds->Name = L"txtSpeeds";
			this->txtSpeeds->Size = System::Drawing::Size(404, 561);
			this->txtSpeeds->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(459, 128);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(455, 36);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Select View To Load Video To:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(459, 194);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(246, 36);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Pedestrian View";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(1317, 194);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(200, 36);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Vehicle View";
			// 
			// btnStop
			// 
			this->btnStop->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnStop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnStop->ForeColor = System::Drawing::Color::DarkRed;
			this->btnStop->Location = System::Drawing::Point(54, 192);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(258, 61);
			this->btnStop->TabIndex = 19;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = false;
			this->btnStop->Click += gcnew System::EventHandler(this, &MyUI::btnStop_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(465, 276);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1985, 766);
			this->panel1->TabIndex = 21;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(764, 20);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(1207, 720);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(17, 20);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(741, 720);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btnPlay2
			// 
			this->btnPlay2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btnPlay2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnPlay2->ForeColor = System::Drawing::Color::DarkGreen;
			this->btnPlay2->Location = System::Drawing::Point(793, 182);
			this->btnPlay2->Name = L"btnPlay2";
			this->btnPlay2->Size = System::Drawing::Size(507, 61);
			this->btnPlay2->TabIndex = 22;
			this->btnPlay2->Text = L"Start Pedestrian View";
			this->btnPlay2->UseVisualStyleBackColor = false;
			this->btnPlay2->Click += gcnew System::EventHandler(this, &MyUI::btnPlay2_Click_1);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(79, 1114);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(335, 36);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Pedestrian Instruction:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(567, 1082);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1293, 101);
			this->textBox1->TabIndex = 24;
			// 
			// txtCount
			// 
			this->txtCount->BackColor = System::Drawing::SystemColors::Menu;
			this->txtCount->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtCount->ForeColor = System::Drawing::SystemColors::WindowText;
			this->txtCount->Location = System::Drawing::Point(341, 317);
			this->txtCount->Name = L"txtCount";
			this->txtCount->Size = System::Drawing::Size(91, 34);
			this->txtCount->TabIndex = 25;
			// 
			// MyUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->ClientSize = System::Drawing::Size(2462, 1195);
			this->Controls->Add(this->txtCount);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnPlay2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnStop);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtSpeeds);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnPlay);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->txtInput);
			this->Controls->Add(this->btnSelect);
			this->Name = L"MyUI";
			this->Text = L"SafeCross +";
			this->Load += gcnew System::EventHandler(this, &MyUI::MyUI_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyUI_Load(System::Object^  sender, System::EventArgs^  e) {
		disable1();
		txtCount->Text = nullptr;
	}

	private: System::Void btnReset_Click(System::Object^  sender, System::EventArgs^  e) {
		disable1();
		txtInput->Text = "";
		txtSpeeds->Text = "";
		txtCount->Text = "";
		textBox1->Text = "";
		System::Drawing::Image^ img = pictureBox1->Image;
		pictureBox2->Image = nullptr;
		delete img;
		System::Drawing::Image^ img2 = pictureBox1->Image;
		pictureBox1->Image = nullptr;
		delete img2;
	}

	private: Void disable1() {
		btnPlay->Enabled = false;
		btnPlay2->Enabled = false;
		btnStop->Enabled = false;
		txtCount->Text = nullptr;
	}

	private: Void enable1() {
		btnPlay->Enabled = true;
		btnPlay2->Enabled = true;
		btnStop->Enabled = true;
		txtCount->Text = nullptr;
	}

	private: System::Void btnPlay_Click(System::Object^  sender, System::EventArgs^  e) {
		//"C:\\Users\mide_\\source\\repos\\CSC 495 UI Project\\data\\CarsDrivingUnderBridge.mp4"
		System::String^ videoName = txtInput->Text;
		std::string standardString = msclr::interop::marshal_as<std::string>(videoName);

		capVideo.open(standardString);
		if (!capVideo.isOpened()) {
			MessageBox::Show("error reading video file");
			_getch();
		}

		if (capVideo.get(cv::CAP_PROP_FRAME_COUNT) < 2) {
			MessageBox::Show("error: video file must have at least two frames");
			_getch();
		}
		
		loadVehicleVideo();
		/*Thread^ t = gcnew Thread(gcnew ThreadStart(this, &MyUI::loadVehicleVideo));
		t->Start();
		t->Join(10);*/
	}

	private: System::Void btnPlay2_Click_1(System::Object^  sender, System::EventArgs^  e) {
		//"C:\\Users\mide_\\source\\repos\\CSC 495 UI Project\\data\\CarsDrivingUnderBridge.mp4"
		System::String^ videoName = txtInput->Text;
		std::string standardString = msclr::interop::marshal_as<std::string>(videoName);

		capVideo2.open(standardString);
		if (!capVideo2.isOpened()) {
			MessageBox::Show("error reading video file");
			_getch();
		}

		if (capVideo2.get(cv::CAP_PROP_FRAME_COUNT) < 2) {
			MessageBox::Show("error: video file must have at least two frames");
			_getch();
		}

		//loadPedestrianVideo();
		Thread^ t = gcnew Thread(gcnew ThreadStart(this, &MyUI::loadPedestrianVideo));
		t->Start();
		t->Join(10);

	}

	private: System::Void btnStop_Click(System::Object^  sender, System::EventArgs^  e) {
		if (capVideo.isOpened() || capVideo2.isOpened()) {
			capVideo.release();
			capVideo2.release();
			cv::waitKey(0);
		}
	}

	private: System::Void btnSelect_Click(System::Object^  sender, System::EventArgs^  e) {

		System::String^ myStream;
		openFileDialog1->InitialDirectory = "C:\\Users\mide_\\source\\repos\\CSC 495 UI Project\\data";
		openFileDialog1->Title = "Open Video File";
		openFileDialog1->ShowDialog();
		myStream = openFileDialog1->FileName;
		txtInput->Text = myStream;
		enable1();
	}

	void loadPedestrianVideo() {
		Mat frame;
		Mat frame2;

		capVideo2 >> frame;
		capVideo2 >> frame2;

		bool blnFirstFrame = true;

		int frameCount = 2;

		while (capVideo2.isOpened()) {

			std::vector<Blob> currentFrameBlobs;

			cv::Mat imgFrame1Copy = frame.clone();
			cv::Mat imgFrame2Copy = frame2.clone();

			cv::Mat imgDifference;
			cv::Mat imgThresh;

			cv::cvtColor(imgFrame1Copy, imgFrame1Copy, cv::COLOR_BGR2GRAY);
			cv::cvtColor(imgFrame2Copy, imgFrame2Copy, cv::COLOR_BGR2GRAY);

			cv::GaussianBlur(imgFrame1Copy, imgFrame1Copy, cv::Size(5, 5), 0);
			cv::GaussianBlur(imgFrame2Copy, imgFrame2Copy, cv::Size(5, 5), 0);
			try {
				cv::absdiff(imgFrame1Copy, imgFrame2Copy, imgDifference);
			}
			catch (std::exception& e) {
			}

			cv::threshold(imgDifference, imgThresh, 30, 255.0, cv::THRESH_BINARY);

			//cv::imshow("imgThresh", imgThresh);

			cv::Mat structuringElement3x3 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
			cv::Mat structuringElement5x5 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
			cv::Mat structuringElement7x7 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7));
			cv::Mat structuringElement9x9 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(9, 9));

			/*
			cv::dilate(imgThresh, imgThresh, structuringElement7x7);
			cv::erode(imgThresh, imgThresh, structuringElement3x3);
			*/
			try {
			cv::dilate(imgThresh, imgThresh, structuringElement5x5);
			cv::dilate(imgThresh, imgThresh, structuringElement5x5);
			cv::erode(imgThresh, imgThresh, structuringElement5x5);
			}
			catch (std::exception& e) {
			}


			cv::Mat imgThreshCopy = imgThresh.clone();

			std::vector<std::vector<cv::Point> > contours;

			cv::findContours(imgThreshCopy, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

			//drawAndShowContours(imgThresh.size(), contours, "imgContours");

			std::vector<std::vector<cv::Point> > convexHulls(contours.size());

			for (unsigned int i = 0; i < contours.size(); i++) {
				cv::convexHull(contours[i], convexHulls[i]);
			}

			//drawAndShowContours(imgThresh.size(), convexHulls, "imgConvexHulls");

			for (auto &convexHull : convexHulls) {
				Blob possibleBlob(convexHull);

				if (possibleBlob.currentBoundingRect.area() > 100 &&
					possibleBlob.dblCurrentAspectRatio >= 0.2 &&
					possibleBlob.dblCurrentAspectRatio <= 1.25 &&
					possibleBlob.currentBoundingRect.width > 20 &&
					possibleBlob.currentBoundingRect.height > 20 &&
					possibleBlob.dblCurrentDiagonalSize > 30.0 &&
					(cv::contourArea(possibleBlob.currentContour) / (double)possibleBlob.currentBoundingRect.area()) > 0.40) {
					currentFrameBlobs.push_back(possibleBlob);
				}
			}

			//drawAndShowContours(imgThresh.size(), currentFrameBlobs, "imgCurrentFrameBlobs");

			if (blnFirstFrame == true) {
				for (auto &currentFrameBlob : currentFrameBlobs) {
					blobs2.push_back(currentFrameBlob);
				}
			}
			else {
				matchCurrentFrameBlobsToExistingBlobs(blobs2, currentFrameBlobs);
			}

			//drawAndShowContours(imgThresh.size(), blobs, "imgBlobs");

			imgFrame2Copy = frame2.clone();          // get another copy of frame 2 since we changed the previous frame 2 copy in the processing above

			drawBlobInfoOnImage2(blobs2, imgFrame2Copy);

			//cv::imshow("imgFrame2Copy", imgFrame2Copy);
			//pictureBox1->Image = cam2.Show(imgFrame2Copy);
			DrawCVImage(pictureBox1, imgFrame2Copy);

			currentFrameBlobs.clear();

			frame = frame2.clone();           // move frame 1 up to where frame 2 is

			if ((capVideo2.get(cv::CAP_PROP_POS_FRAMES) + 1) < capVideo2.get(cv::CAP_PROP_FRAME_COUNT)) {
				capVideo2.read(frame2);
			}
			else {
				std::cout << "end of video\n";
			}

			blnFirstFrame = false;
			frameCount++;
			// Press  ESC on keyboard to exit
			char c = (char)waitKey(1);
			if (c == 27)
				break;
		}
	}

	void loadVehicleVideo() {
		Mat imgFrame1;
		Mat imgFrame2;

		capVideo >> imgFrame1;
		capVideo >> imgFrame2;

		int intHorizontalLinePosition = (int)std::round((double)imgFrame1.rows * 0.65);
		int intHorizontalLinePosition2 = (int)std::round((double)imgFrame1.rows * 0.35);

		crossingLine[0].x = 0;
		crossingLine[0].y = intHorizontalLinePosition;

		crossingLine[1].x = imgFrame1.cols - 1;
		crossingLine[1].y = intHorizontalLinePosition;

		crossingLine2[0].x = 0;
		crossingLine2[0].y = intHorizontalLinePosition2;

		crossingLine2[1].x = imgFrame1.cols - 1;
		crossingLine2[1].y = intHorizontalLinePosition2;

		bool blnFirstFrame = true;

		int frameCount = 2;

		while (capVideo.isOpened()) {

			std::vector<Blob> currentFrameBlobs;

			cv::Mat imgFrame1Copy = imgFrame1.clone();
			cv::Mat imgFrame2Copy = imgFrame2.clone();

			cv::Mat imgDifference;
			cv::Mat imgThresh;

			cv::cvtColor(imgFrame1Copy, imgFrame1Copy, cv::COLOR_BGR2GRAY);
			cv::cvtColor(imgFrame2Copy, imgFrame2Copy, cv::COLOR_BGR2GRAY);

			cv::GaussianBlur(imgFrame1Copy, imgFrame1Copy, cv::Size(5, 5), 0);
			cv::GaussianBlur(imgFrame2Copy, imgFrame2Copy, cv::Size(5, 5), 0);

			cv::absdiff(imgFrame1Copy, imgFrame2Copy, imgDifference);

			cv::threshold(imgDifference, imgThresh, 30, 255.0, cv::THRESH_BINARY);

			//cv::imshow("imgThresh", imgThresh);

			cv::Mat structuringElement3x3 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
			cv::Mat structuringElement5x5 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
			cv::Mat structuringElement7x7 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7));
			cv::Mat structuringElement15x15 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));

			for (unsigned int i = 0; i < 2; i++) {
				cv::dilate(imgThresh, imgThresh, structuringElement5x5);
				cv::dilate(imgThresh, imgThresh, structuringElement5x5);
				cv::erode(imgThresh, imgThresh, structuringElement5x5);
			}

			cv::Mat imgThreshCopy = imgThresh.clone();

			std::vector<std::vector<cv::Point> > contours;

			cv::findContours(imgThreshCopy, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

			//drawAndShowContours(imgThresh.size(), contours, "imgContours");

			std::vector<std::vector<cv::Point> > convexHulls(contours.size());

			for (unsigned int i = 0; i < contours.size(); i++) {
				cv::convexHull(contours[i], convexHulls[i]);
			}

			//drawAndShowContours(imgThresh.size(), convexHulls, "imgConvexHulls");

			for (auto &convexHull : convexHulls) {
				Blob possibleBlob(convexHull);

				if (possibleBlob.currentBoundingRect.area() > 400 &&
					possibleBlob.dblCurrentAspectRatio > 0.2 &&
					possibleBlob.dblCurrentAspectRatio < 4.0 &&
					possibleBlob.currentBoundingRect.width > 30 &&
					possibleBlob.currentBoundingRect.height > 30 &&
					possibleBlob.dblCurrentDiagonalSize > 60.0 &&
					(cv::contourArea(possibleBlob.currentContour) / (double)possibleBlob.currentBoundingRect.area()) > 0.50) {
					currentFrameBlobs.push_back(possibleBlob);
				}
			}

			//drawAndShowContours(imgThresh.size(), currentFrameBlobs, "imgCurrentFrameBlobs");

			if (blnFirstFrame == true) {
				for (auto &currentFrameBlob : currentFrameBlobs) {
					blobs.push_back(currentFrameBlob);
				}
			}
			else {
				matchCurrentFrameBlobsToExistingBlobs(blobs, currentFrameBlobs);
			}

			//drawAndShowContours(imgThresh.size(), blobs, "imgBlobs");

			imgFrame2Copy = imgFrame2.clone();          // get another copy of frame 2 since we changed the previous frame 2 copy in the processing above

			drawBlobInfoOnImage(blobs, imgFrame2Copy);

			//Get the count of the car
			bool blnAtLeastOneBlobCrossedTheLine = checkIfBlobsCrossedTheLine(blobs, intHorizontalLinePosition, carCount);

			//Get the speed of each car
			bool blnAtLeastOneBlobCrossedTheLine2 = checkIfBlobsCrossedTheLine2(blobs, intHorizontalLinePosition2, imgFrame2Copy);

			//Collision Prediction
			bool blnAtLeastOneBlobCrossedTheLineCP = collisionPrediction(blobs, intHorizontalLinePosition2, imgFrame2Copy);

			if (blnAtLeastOneBlobCrossedTheLine == true) {
				cv::line(imgFrame2Copy, crossingLine[0], crossingLine[1], SCALAR_GREEN, 2);
			}
			else if (blnAtLeastOneBlobCrossedTheLine == false) {
				cv::line(imgFrame2Copy, crossingLine[0], crossingLine[1], SCALAR_RED, 2);
			}

			if (blnAtLeastOneBlobCrossedTheLine2 == true) {
				cv::line(imgFrame2Copy, crossingLine2[0], crossingLine2[1], SCALAR_RED, 2);
			}
			else if (blnAtLeastOneBlobCrossedTheLine2 == false) {
				cv::line(imgFrame2Copy, crossingLine2[0], crossingLine2[1], SCALAR_YELLOW, 2);
			}

			if (blnAtLeastOneBlobCrossedTheLineCP == true) {
				cv::line(imgFrame2Copy, crossingLine2[0], crossingLine2[1], SCALAR_RED, 2);
			}
			else if (blnAtLeastOneBlobCrossedTheLineCP == false) {
				cv::line(imgFrame2Copy, crossingLine2[0], crossingLine2[1], SCALAR_YELLOW, 2);
			}

			//drawCarCountOnImage(carCount, imgFrame2Copy);

			//cv::imshow("imgFrame2Copy", imgFrame2Copy);
			pictureBox2->Image = cam.Show(imgFrame2Copy);

			currentFrameBlobs.clear();

			imgFrame1 = imgFrame2.clone();           // move frame 1 up to where frame 2 is

			if ((capVideo.get(cv::CAP_PROP_POS_FRAMES) + 1) < capVideo.get(cv::CAP_PROP_FRAME_COUNT)) {
				capVideo.read(imgFrame2);
			}
			else {
				std::cout << "end of video\n";
			}

			blnFirstFrame = false;
			frameCount++;
			char c = (char)waitKey(1);
			if (c == 27)
				break;
		}
	}

	void matchCurrentFrameBlobsToExistingBlobs(std::vector<Blob> &existingBlobs, std::vector<Blob> &currentFrameBlobs) {

		for (auto &existingBlob : existingBlobs) {

			existingBlob.blnCurrentMatchFoundOrNewBlob = false;

			existingBlob.predictNextPosition();
		}

		for (auto &currentFrameBlob : currentFrameBlobs) {

			int intIndexOfLeastDistance = 0;
			double dblLeastDistance = 100000.0;

			for (unsigned int i = 0; i < existingBlobs.size(); i++) {

				if (existingBlobs[i].blnStillBeingTracked == true) {

					double dblDistance = distanceBetweenPoints(currentFrameBlob.centerPositions.back(), existingBlobs[i].predictedNextPosition);

					if (dblDistance < dblLeastDistance) {
						dblLeastDistance = dblDistance;
						intIndexOfLeastDistance = i;
					}
				}
			}

			if (dblLeastDistance < currentFrameBlob.dblCurrentDiagonalSize * 0.5) {
				addBlobToExistingBlobs(currentFrameBlob, existingBlobs, intIndexOfLeastDistance);
			}
			else {
				addNewBlob(currentFrameBlob, existingBlobs);
			}

		}

		for (auto &existingBlob : existingBlobs) {

			if (existingBlob.blnCurrentMatchFoundOrNewBlob == false) {
				existingBlob.intNumOfConsecutiveFramesWithoutAMatch++;
			}

			if (existingBlob.intNumOfConsecutiveFramesWithoutAMatch >= 5) {
				existingBlob.blnStillBeingTracked = false;
			}

		}

	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	void addBlobToExistingBlobs(Blob &currentFrameBlob, std::vector<Blob> &existingBlobs, int &intIndex) {

		existingBlobs[intIndex].currentContour = currentFrameBlob.currentContour;
		existingBlobs[intIndex].currentBoundingRect = currentFrameBlob.currentBoundingRect;

		existingBlobs[intIndex].centerPositions.push_back(currentFrameBlob.centerPositions.back());

		existingBlobs[intIndex].dblCurrentDiagonalSize = currentFrameBlob.dblCurrentDiagonalSize;
		existingBlobs[intIndex].dblCurrentAspectRatio = currentFrameBlob.dblCurrentAspectRatio;

		existingBlobs[intIndex].blnStillBeingTracked = true;
		existingBlobs[intIndex].blnCurrentMatchFoundOrNewBlob = true;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	void addNewBlob(Blob &currentFrameBlob, std::vector<Blob> &existingBlobs) {

		currentFrameBlob.blnCurrentMatchFoundOrNewBlob = true;

		existingBlobs.push_back(currentFrameBlob);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	double distanceBetweenPoints(cv::Point point1, cv::Point point2) {

		int intX = abs(point1.x - point2.x);
		int intY = abs(point1.y - point2.y);

		return(sqrt(pow(intX, 2) + pow(intY, 2)));
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	void drawAndShowContours(cv::Size imageSize, std::vector<std::vector<cv::Point> > contours, std::string strImageName) {
		cv::Mat image(imageSize, CV_8UC3, SCALAR_BLACK);

		cv::drawContours(image, contours, -1, SCALAR_WHITE, -1);

		cv::imshow(strImageName, image);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	void drawAndShowContours(cv::Size imageSize, std::vector<Blob> blobs, std::string strImageName) {

		cv::Mat image(imageSize, CV_8UC3, SCALAR_BLACK);

		std::vector<std::vector<cv::Point> > contours;

		for (auto &blob : blobs) {
			if (blob.blnStillBeingTracked == true) {
				contours.push_back(blob.currentContour);
			}
		}

		cv::drawContours(image, contours, -1, SCALAR_WHITE, -1);

		cv::imshow(strImageName, image);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	bool checkIfBlobsCrossedTheLine(std::vector<Blob> &blobs, int &intHorizontalLinePosition, int &carCount) {
		bool blnAtLeastOneBlobCrossedTheLine = false;

		for (auto blob : blobs) {

			if (blob.blnStillBeingTracked == true && blob.centerPositions.size() >= 2) {
				int prevFrameIndex = (int)blob.centerPositions.size() - 2;
				int currFrameIndex = (int)blob.centerPositions.size() - 1;

				if (blob.centerPositions[prevFrameIndex].y > intHorizontalLinePosition && blob.centerPositions[currFrameIndex].y <= intHorizontalLinePosition) {
					string val = std::to_string(carCount + 1);
					System::String^ vals = msclr::interop::marshal_as<System::String^>(val);
					txtCount->Text = vals + "\r\n";
						carCount++;
					blnAtLeastOneBlobCrossedTheLine = true;
				}
			}

		}

		return blnAtLeastOneBlobCrossedTheLine;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	bool checkIfBlobsCrossedTheLine2(std::vector<Blob> &blobs, int &intHorizontalLinePosition2, cv::Mat &imgFrame2Copy) {
		bool blnAtLeastOneBlobCrossedTheLine2 = false;

		for (auto blob : blobs) {

			if (blob.blnStillBeingTracked == true && blob.centerPositions.size() >= 2) {
				int prevFrameIndex = (int)blob.centerPositions.size() - 2;
				int currFrameIndex = (int)blob.centerPositions.size() - 1;



				if ((blob.centerPositions[prevFrameIndex].y > intHorizontalLinePosition2 && blob.centerPositions[currFrameIndex].y <= intHorizontalLinePosition2)) {
					try {
						int distance = (blob.centerPositions[0].y - blob.centerPositions[currFrameIndex].y);
						int tickCount = cv::getTickCount();
						int time = (tickCount - blob.firstTickCount) / cv::getTickFrequency();
						if (time <= 0) {
							time = 5;
						}
						float speed = (distance / time) / 1.609;
						int v;
						unsigned int i = assignID(v, blobs);
						string strSpeed = std::to_string(speed);
						string strID = std::to_string(i);
						string strDistance = std::to_string(distance);
						string strTime = std::to_string(time);
						System::String^ vals = msclr::interop::marshal_as<System::String^>("ID: " + strID + "  " + + "Distance: " + strDistance + "  " + "Time: " + strTime + " " + "Speed: " + strSpeed + "\r\n");
						txtSpeeds->SelectedText = vals + "\r\n";

						ofstream outfile("vehicleinfo.txt");
						if(outfile.is_open()){
						string val = "ID: " + std::to_string(i) + "  " + "Distance: " + std::to_string(distance) + "  " + "Time: " + std::to_string(time) + "  " + "Speed: " + std::to_string(speed) + "mph";
						outfile << val << "\r\n" << endl;
						}
						outfile.close();

						//drawCarSpeedOnImage(speed, imgFrame2Copy);
						blnAtLeastOneBlobCrossedTheLine2 = true;
					}
					catch (int  e) {
						std::cout << "Exception Caught \n " << e << std::endl;
					}
				}

			}

		}
		return blnAtLeastOneBlobCrossedTheLine2;
	}

	bool collisionPrediction(std::vector<Blob> &blobs, int &intHorizontalLinePosition2, cv::Mat &imgFrame2Copy) {
		int personCrossTime = 7; //average time it takes a person to crose a lane. multiply based on # of lane (e.g if lane is 4 personCrossTime = personCrossTime * 4).
		double safeDistance = 0.151515; //safe distance between person and vehicle in ft coverted to mi by dividing by 5280
		bool blnAtLeastOneBlobCrossedTheLineCP = false;

		for (auto blob : blobs) {

			if (blob.blnStillBeingTracked == true && blob.centerPositions.size() >= 2) {
				int prevFrameIndex = (int)blob.centerPositions.size() - 2;
				int currFrameIndex = (int)blob.centerPositions.size() - 1;

				if ((blob.centerPositions[prevFrameIndex].y > intHorizontalLinePosition2 && blob.centerPositions[currFrameIndex].y <= intHorizontalLinePosition2)) {
					int distance = (blob.centerPositions[0].y - blob.centerPositions[currFrameIndex].y);
					int tickCount = cv::getTickCount();
					int time = (tickCount - blob.firstTickCount) / cv::getTickFrequency();
					if (time <= 0) {
						time = 5;
					}
					float speed = (distance / time) / 1.609;
					string strSpeed = std::to_string(speed);
					string strsafeDistance = std::to_string(safeDistance);

					float collisionTime = (safeDistance / speed) * 3600;

					string ct = std::to_string(collisionTime);
					string pct = std::to_string(personCrossTime * 1);
					System::String^ vals = msclr::interop::marshal_as<System::String^>("Collision Time: " + ct + " " + "Pedestrian Cross Time: " + pct + " " + "Message: ");

					if (capVideo2.isOpened()) {
						if ((personCrossTime * 1) >= collisionTime) {
							System::String^ message = vals + "Dont Cross!!! Potential Collision" + "\r\n";
							textBox1->SelectedText = message;
						}
						else if ((personCrossTime * 1) < collisionTime)
						{
							System::String^ message2 = vals + "Cross!!! No Vehicle Approaching" + "\r\n";
							textBox1->SelectedText = message2;
						}
					}
					else {

					}
					blnAtLeastOneBlobCrossedTheLineCP = true;
				}
			}
		}
		return blnAtLeastOneBlobCrossedTheLineCP = false;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	void drawBlobInfoOnImage(std::vector<Blob> &blobs, cv::Mat &imgFrame2Copy) {

		for (unsigned int i = 0; i < blobs.size(); i++) {

			if (blobs[i].blnStillBeingTracked == true) {
				cv::rectangle(imgFrame2Copy, blobs[i].currentBoundingRect, SCALAR_RED, 2);

				int intFontFace = cv::FONT_HERSHEY_SIMPLEX;
				double dblFontScale = blobs[i].dblCurrentDiagonalSize / 60.0;
				int intFontThickness = (int)std::round(dblFontScale * 1.0);

				cv::putText(imgFrame2Copy, std::to_string(i), blobs[i].centerPositions.back(), intFontFace, dblFontScale, SCALAR_GREEN, intFontThickness);
			}
		}
	}


	///////////////////////////////////////////////////////////////////////////////////////////////////
	void drawBlobInfoOnImage2(std::vector<Blob> &blobs2, cv::Mat &imgFrame2Copy) {

		for (unsigned int i = 0; i < blobs2.size(); i++) {

			if (blobs2[i].blnStillBeingTracked == true) {
				cv::rectangle(imgFrame2Copy, blobs2[i].currentBoundingRect, SCALAR_GREEN, 2);

				int intFontFace = cv::FONT_HERSHEY_SIMPLEX;
				double dblFontScale = blobs2[i].dblCurrentDiagonalSize / 60.0;
				int intFontThickness = (int)std::round(dblFontScale * 1.0);

				cv::putText(imgFrame2Copy, std::to_string(i), blobs2[i].centerPositions.back(), intFontFace, dblFontScale, SCALAR_RED, intFontThickness);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	unsigned int assignID(int &i, std::vector<Blob> &blobs) {
		unsigned int v;
		for (i = 0; i < blobs.size(); i++) {
			v = i;
		}
		return v;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	void drawCarCountOnImage(int &carCount, cv::Mat &imgFrame2Copy) {

		int intFontFace = cv::FONT_HERSHEY_SIMPLEX;
		double dblFontScale = (imgFrame2Copy.rows * imgFrame2Copy.cols) / 450000.0;
		int intFontThickness = (int)std::round(dblFontScale * 2.0);

		cv::Size textSize = cv::getTextSize(std::to_string(carCount), intFontFace, dblFontScale, intFontThickness, 0);
		cv::putText(imgFrame2Copy, std::to_string(carCount), cv::Point(1200, 50), intFontFace, dblFontScale, SCALAR_RED, intFontThickness);
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////
	void drawCarSpeedOnImage(float &speed, cv::Mat &imgFrame2Copy) {

		int intFontFace = cv::FONT_HERSHEY_SIMPLEX;
		double dblFontScale = (imgFrame2Copy.rows * imgFrame2Copy.cols) / 450000.0;
		int intFontThickness = (int)std::round(dblFontScale * 2.0);

		cv::Size textSize = cv::getTextSize(std::to_string(speed), intFontFace, dblFontScale, intFontThickness, 0);
		cv::putText(imgFrame2Copy, std::to_string(speed), cv::Point(20, 50), intFontFace, dblFontScale, SCALAR_YELLOW, intFontThickness);
	}

	void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage) {
		System::Drawing::Graphics^ graphics = control->CreateGraphics();
		System::IntPtr ptr(colorImage.ptr());
		System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
		System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
		graphics->DrawImage(b, rect);
		delete graphics;
	}
};
}