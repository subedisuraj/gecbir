#include "mainWindow.h"



namespace GECBIR {

	using namespace System;

	[STAThread]
	void main(array<String^>^ arg) {
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		mainWindow form;
		Application::Run(%form);
	}
}