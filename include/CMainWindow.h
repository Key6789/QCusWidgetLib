#pragma once
#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include <QMainWindow>
#include "QCusWidgetLib_global.h"
#include "CPlotCurve.h"
namespace QCUSWIDGETLIB
{
	enum CLICK_TYPE
	{
		CLICK_NONE = 0,
		CLICK_DRAG_ENTER,// 初始状态 可以不设置
		CLICK_DRAG_MOVE,
		CLICK_DRAG_LEAVE,
		CLICK_MOUSE_PRESS,
		CLICK_MOUSE_MOVE,
		CLICK_MOUSE_RELEASE
	};

	class CWidgetTest;
	/// <summary>
	/// 主窗口类 核心用于实现控件的拖拽、布局等功能
	/// </summary>
	class QCUSWIDGETLIB_EXPORT CMainWindow : public QMainWindow
	{
		Q_OBJECT
	public:
		
	public:
		CMainWindow(QWidget* parent = nullptr);
		~CMainWindow();
		void addWidget(QWidget* pWidget, int row, int col, int rowSpan = 1, int colSpan = 1);
		void insertWidget(QWidget* pWidget, int row, int col,int rowSpan = 1, int colSpan = 1,bool rowInsert = false, bool colInsert = true);
	protected:
		void dragEnterEvent(QDragEnterEvent* event) override;
		void dropEvent(QDropEvent* event) override;
		void dragMoveEvent(QDragMoveEvent* event) override;
		void mousePressEvent(QMouseEvent* event) override;
		void mouseMoveEvent(QMouseEvent* event) override;
		void mouseReleaseEvent(QMouseEvent* event) override;

	private slots:
		void slotDragEnterEvent(QDragEnterEvent* event);
		void slotDropEvent(QDropEvent* event);
		void slotDragMoveEvent(QDragMoveEvent* event);

		void slotMousePressEvent(QMouseEvent* event);
		void slotMouseMoveEvent(QMouseEvent* event);
		void slotMouseReleaseEvent(QMouseEvent* event);


	signals:
		// 处理拖动进入事件的方法
		void signalDragEnter(QDragEnterEvent* event);
		// 处理拖放事件的方法
		void signalDropEvent(QDropEvent* event);
		// 处理拖动移动事件的方法
		void signalDropMoveEvent(QDragMoveEvent* event);

		// 鼠标点击事件
		void signalMousePressEvent(QMouseEvent* event);
		// 鼠标移动事件
		void signalMouseMoveEvent(QMouseEvent* event);
		// 鼠标释放事件
		void signalMouseReleaseEvent(QMouseEvent* event);



	private:
		void initConnections();
		QGridLayout* m_pLayout = nullptr;

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
			setLayout(pLayout);
			adjustSize();

		}
		~CWidgetTest() {};

	protected:
		void mousePressEvent(QMouseEvent* event) override;

	private:
	};
} // namespace QCUSWIDGETLIB
#endif // CMAINWINDOW_H
