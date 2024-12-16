#include "../include/CMainWindow.h"
namespace QCUSWIDGETLIB
{
	CMainWindow::CMainWindow(QWidget* parent)
		: QMainWindow(parent)
	{
		// �����ڲ� �ؼ� �϶�����
		setAcceptDrops(true);
		// ����������
		setMouseTracking(true);
		// ���ô��ڱ���
		// ��ʼ�����ڲ���
		QWidget* pWidget = new QWidget(this);
		m_pLayout = new QGridLayout(pWidget);
		pWidget->setLayout(m_pLayout);
		setCentralWidget(pWidget);
		pWidget->setStyleSheet("background-color: #00ff00;");

		addWidget(new CWidgetTest(this), 0, 0, 1, 1);
		addWidget(new CWidgetTest(this), 0, 1, 1, 1);
		addWidget(new CWidgetTest(this), 1, 0, 1, 1);
		addWidget(new CWidgetTest(this), 1, 1, 1, 1);

		update();

		setStyleSheet("border: 1px solid #ff0000; ");
	}

	CMainWindow::~CMainWindow()
	{}
	void CMainWindow::addWidget(QWidget * pWidget, int row, int col, int rowSpan, int colSpan)
	{
		m_pLayout->addWidget(pWidget, row, col, rowSpan, colSpan);
		// ��¼�ؼ���Ϣ
		WidgetInfo widgetInfo;
		widgetInfo.pWidget = pWidget;
		widgetInfo.row = row;
		widgetInfo.col = col;
		widgetInfo.rowSpan = rowSpan;
		widgetInfo.colSpan = colSpan;
		m_vecWidgetInfo.push_back(widgetInfo);
	}
	void CMainWindow::dragEnterEvent(QDragEnterEvent* event)
	{
		if (event->mimeData()->hasFormat("application/x-dnditemdata")) 
		{
			event->acceptProposedAction();
			// ��ȡ������Ŀؼ�
			QWidget* pWidget = static_cast<QWidget*>(event->source());
			// ��ȡ�ؼ�����QGridLayout��λ��
			if (pWidget) {
				for (int i = 0; i < m_vecWidgetInfo.size(); i++) {
					if (m_vecWidgetInfo[i].pWidget == pWidget) {

						break;
					}
				}
			}
		}
		else {
			event->ignore();
		}
	}
	void CMainWindow::dragMoveEvent(QDragMoveEvent* event)
	{
		if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
			event->acceptProposedAction();
		}
		else {
			event->ignore();
		}
	}


	void CMainWindow::dropEvent(QDropEvent* event)
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

			// ��̬��������
			int row, col;
			m_pLayout->addWidget(label, row, col); // ��Ҫ����ʵ��λ�ü��� row �� col

			event->acceptProposedAction();
		}
		else {
			event->ignore();
		}
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
}
