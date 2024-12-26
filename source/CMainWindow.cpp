#include "../include/CMainWindow.h"
#include <iostream>
namespace QCUSWIDGETLIB
{
	CMainWindow::CMainWindow(QWidget* parent)
		: QMainWindow(parent)
	{
		setAcceptDrops(true);
		setMouseTracking(true);

		QWidget* pWidget = new QWidget(this);
		m_pLayout = new QGridLayout(pWidget);
		pWidget->setLayout(m_pLayout);
		setCentralWidget(pWidget);
		pWidget->setStyleSheet("background-color: #00ff00;");
		pWidget->setMouseTracking(true);
		pWidget->setAcceptDrops(true);

		addWidget(new CWidgetTest(this), 0, 0, 1, 1);
		addWidget(new CWidgetTest(this), 0, 1, 1, 1);
		addWidget(new CWidgetTest(this), 1, 0, 1, 1);
		addWidget(new CWidgetTest(this), 1, 1, 1, 1);
		addWidget(new CWidgetTest(this), 2, 0, 1, 1);
		addWidget(new CWidgetTest(this), 2, 1, 1, 1);

		insertWidget(new CWidgetTest(this), 0, 0, 1, 1);


		update();
		initConnections();

		setStyleSheet("border: 1px solid #ff0000; ");
	}

	CMainWindow::~CMainWindow()
	{}
	void CMainWindow::addWidget(QWidget* pWidget, int row, int col, int rowSpan, int colSpan)
	{
		m_pLayout->addWidget(pWidget, row, col, rowSpan, colSpan);
	}
	void CMainWindow::insertWidget(QWidget* pWidget, int row, int col, int rowSpan, int colSpan,bool rowInsert,bool colInsert)
	{
		// 先判断是否有空白区域

		// 判断当前是否有控件
		if (m_pLayout->itemAtPosition(row, col)) {
			QWidget* pOldWidget = m_pLayout->itemAtPosition(row, col)->widget();
			m_pLayout->removeWidget(pOldWidget);
			m_pLayout->addWidget(pWidget, row, col, rowSpan, colSpan);
			if (rowInsert) {
				row++;
			}
			if (colInsert)
			{
				col++;
			}
			if (rowInsert || colInsert) 
			{
				insertWidget(pOldWidget, row, col, rowSpan, colSpan);
			}
			else
			{
				if (pOldWidget)
				{
					pOldWidget->close();
					pOldWidget = nullptr;
				}
			}
		}
		else
		{
			m_pLayout->addWidget(pWidget, row, col, rowSpan, colSpan);
		}

	}
	void CMainWindow::dragEnterEvent(QDragEnterEvent* event)
	{
		emit signalDragEnter(event);
		QMainWindow::dragEnterEvent(event);
	}

	void CMainWindow::dragMoveEvent(QDragMoveEvent* event)
	{
		emit signalDropMoveEvent(event);
		QMainWindow::dragMoveEvent(event);
		
	}
	void CMainWindow::mousePressEvent(QMouseEvent* event)
	{
		emit signalMousePressEvent(event);
		QMainWindow::mousePressEvent(event);
	}
	void CMainWindow::mouseMoveEvent(QMouseEvent* event)
	{
		emit signalMouseMoveEvent(event);
		QMainWindow::mouseMoveEvent(event);
	}
	void CMainWindow::mouseReleaseEvent(QMouseEvent* event)
	{
		emit signalMouseReleaseEvent(event);
		QMainWindow::mouseReleaseEvent(event);
	}
	void CMainWindow::slotDropEvent(QDropEvent* event)
	{
		if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
			QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
			QDataStream dataStream(&itemData, QIODevice::ReadOnly);

			QString text;
			QPoint offset;
			dataStream >> text >> offset;

			QLabel* label = new QLabel(text, this);
			label->move(event->pos() - offset);
			label->show();

			int row = 0, col = 0;
			m_pLayout->addWidget(label, row, col);

			event->acceptProposedAction();
		}
		else {
			event->ignore();
		}
	}

	void CMainWindow::slotDragMoveEvent(QDragMoveEvent* event)
	{
		if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
			event->acceptProposedAction();
			// 检测 当前的的鼠标位置在布局的哪个位置并在 当前布局留出空白区域
			QWidget* pWidget = static_cast<QWidget*>(event->source());
			QPoint pos = event->pos();
			int x = pos.x();
			int y = pos.y();
			std::cout << "drag move event" << " pos: " << x << " " << y << std::endl;
			// 根据当前的鼠标点判断在网格布局的哪个位置
			int row = y / (pWidget->height() / m_pLayout->rowCount());
			int col = x / (pWidget->width() / m_pLayout->columnCount());
			std::cout << "row: " << row << " col: " << col << std::endl;
		}
		else {
			event->ignore();
		}
	}

	void CMainWindow::slotMousePressEvent(QMouseEvent* event)
	{
	}

	void CMainWindow::slotMouseMoveEvent(QMouseEvent* event)
	{
	}

	void CMainWindow::slotMouseReleaseEvent(QMouseEvent* event)
	{
	}
	void CMainWindow::slotDragEnterEvent(QDragEnterEvent* event)
	{
		int x = event->pos().x();
		int y = event->pos().y();
		std::cout << "drag enter event" << x << " " << y << std::endl;

		// 处理拖放事件，检查拖放的数据格式是否为 "application/x-dnditemdata"
		if (event->mimeData()->hasFormat("application/x-dnditemdata"))
		{
			// 如果格式匹配，接受拖放操作
			event->acceptProposedAction();
			
		}
		else {
			// 如果格式不匹配，忽略本次拖放操作

			event->ignore();
		}

	}
	void CMainWindow::dropEvent(QDropEvent* event)
	{
		std::cout << "drop event" << std::endl;
		emit slotDropEvent(event);
		QMainWindow::dropEvent(event);

	}
	void CWidgetTest::mousePressEvent(QMouseEvent* event)
	{
		if (event->button() == Qt::LeftButton) {
			QDrag* drag = new QDrag(this);
			QMimeData* mimeData = new QMimeData();

			QByteArray itemData;
			QDataStream dataStream(&itemData, QIODevice::WriteOnly);
			//dataStream << this->text() << event->pos();
			dataStream << "Hello World" << event->pos();

			mimeData->setData("application/x-dnditemdata", itemData);
			drag->setMimeData(mimeData);

			QPixmap pixmap(this->size());
			this->render(&pixmap);
			drag->setPixmap(pixmap);
			drag->setHotSpot(event->pos());

			if (drag->exec(Qt::CopyAction | Qt::MoveAction) == Qt::MoveAction) {
				this->close();
			}
		}
	}
	void CMainWindow::initConnections()
	{
		// 用于拖拽 与 放置 事件的槽函数
		connect(this, &CMainWindow::signalDragEnter, this, &CMainWindow::slotDragEnterEvent);
		connect(this, &CMainWindow::signalDropMoveEvent, this, &CMainWindow::slotDragMoveEvent);
		connect(this, &CMainWindow::signalDropEvent, this, &CMainWindow::slotDropEvent);
		connect(this, &CMainWindow::signalMousePressEvent, this, &CMainWindow::slotMousePressEvent);
		connect(this, &CMainWindow::signalMouseMoveEvent, this, &CMainWindow::slotMouseMoveEvent);
		connect(this, &CMainWindow::signalMouseReleaseEvent, this, &CMainWindow::slotMouseReleaseEvent);
	}
}
