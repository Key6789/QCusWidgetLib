#pragma once
#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include <QMainWindow>
#include "QCusWidgetLib_global.h"
#include "CPlotCurve.h"
namespace QCUSWIDGETLIB
{
	class CWidgetTest;
	class QCUSWIDGETLIB_EXPORT CMainWindow : public QMainWindow
	{
		Q_OBJECT

		// 用于存储控件信息
		struct WidgetInfo 
		{
			QWidget* pWidget;
			int row;
			int col;
			int rowSpan;
			int colSpan;
		};

	public:
		CMainWindow(QWidget* parent = nullptr);
		~CMainWindow();

		void addWidget(QWidget* pWidget, int row, int col, int rowSpan = 1, int colSpan = 1);

	protected:
		void dragEnterEvent(QDragEnterEvent* event) override;
		void dropEvent(QDropEvent* event) override;
		void dragMoveEvent(QDragMoveEvent* event) override;


	private:
		QGridLayout* m_pLayout = nullptr;

		QVector<WidgetInfo> m_vecWidgetInfo = QVector<WidgetInfo>();

	};

	class QCUSWIDGETLIB_EXPORT CWidgetTest : public QWidget
	{
		Q_OBJECT

	public:
		CWidgetTest(QWidget* parent = nullptr) {
			setStyleSheet("background-color:red;");
			setAcceptDrops(true);
			setMouseTracking(true);
			setWindowTitle("CWidgetTest");

			QVBoxLayout* pLayout = new QVBoxLayout(this);
			pLayout->setContentsMargins(0, 0, 0, 0);
			pLayout->addWidget(new QLabel("CWidgetTest"));

		}
		~CWidgetTest() {};

	protected:
		void mousePressEvent(QMouseEvent* event) override;

	private:
	};
} // namespace QCUSWIDGETLIB
#endif // CMAINWINDOW_H
