#include "MyUI.h"

using namespace System;
using namespace System::Threading;
using namespace System::Windows::Forms;

[STAThread]

void main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CSC495UI::MyUI form;
	form.Size = System::Drawing::Size(1080, 580);
	Application::Run(%form);
	Application::ExitThread();
}