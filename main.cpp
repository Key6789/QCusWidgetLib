#include <iostream>
#include <windows.h>
#include "include/QCusWidgetLib.h"

using namespace std;
using namespace QCUSWIDGETLIB;

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    AllocConsole();
    freopen("CONOUT$", "w", stdout);
    std::cout << "Hello, World!" << std::endl;
    CDialogVLay* pDlg = new CDialogVLay(nullptr);
    pDlg->addWidget(new QLabel("Hello, World!"));
    pDlg->show();
    return a.exec();
}