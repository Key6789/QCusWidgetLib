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
    CMainWindow * pDlg = new CMainWindow(nullptr);
    CBtnAppCan * pBtn = new CBtnAppCan(pDlg);
    pDlg->addWidget(pBtn, 0, 7);
    pBtn->setAppBtnColor(QColor(255, 0, 0));

    pDlg->show();
    return a.exec();
}