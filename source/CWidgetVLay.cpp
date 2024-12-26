#include "../include/CWidgetVLay.h"
namespace QCUSWIDGETLIB
{
	CWidgetVLay::CWidgetVLay(QWidget* parent)
	{
		m_pLayout = new QVBoxLayout(parent);
		setLayout(m_pLayout);
	}

	CWidgetVLay::~CWidgetVLay()
	{}
	void CWidgetVLay::addWidget(QWidget* pWidget)
	{
		m_pLayout->addWidget(pWidget);
	}
	void CWidgetVLay::addWidget(QWidget* pWidget, int stretch)
	{
		m_pLayout->addWidget(pWidget, stretch);
	}
	void CWidgetVLay::removeWidget(QWidget* pWidget)
	{
		m_pLayout->removeWidget(pWidget);
	}
	void CWidgetVLay::clearLayout()
	{
		for (int i = 0; i < m_pLayout->count(); i++)
		{
			QWidget* pWidget = m_pLayout->itemAt(i)->widget();
			if (pWidget)
			{
				m_pLayout->removeWidget(pWidget);
				delete pWidget;
			}
		}
	}
	void CWidgetVLay::addLayout(QLayout* pLayout)
	{
		m_pLayout->addLayout(pLayout);
	}
	void CWidgetVLay::addStretch()
	{
		m_pLayout->addStretch();
	}

	void CWidgetVLay::setLayMargin(int left, int top, int right, int bottom)
	{
		m_pLayout->setContentsMargins(left, top, right, bottom);
	}

	void CWidgetVLay::setLayMargin(int margin)
	{
		m_pLayout->setMargin(margin);
	}

	void CWidgetVLay::setLaySpacing(int spacing)
	{
		m_pLayout->setSpacing(spacing);
	}

	void CWidgetVLay::setLayContentsMargins(int left, int top, int right, int bottom)
	{
		m_pLayout->setContentsMargins(left, top, right, bottom);
	}



	CWidgetHLay::CWidgetHLay(QWidget* parent)
	{
		m_pLayout = new QHBoxLayout(parent);
		setLayout(m_pLayout);
	}

	CWidgetHLay::~CWidgetHLay()
	{}
	void CWidgetHLay::addWidget(QWidget* pWidget)
	{
		m_pLayout->addWidget(pWidget);
	}
	void CWidgetHLay::addWidget(QWidget* pWidget, int stretch)
	{
		m_pLayout->addWidget(pWidget, stretch);
	}
	void CWidgetHLay::removeWidget(QWidget* pWidget)
	{
		m_pLayout->removeWidget(pWidget);
	}
	void CWidgetHLay::clearLayout()
	{
		for (int i = 0; i < m_pLayout->count(); i++)
		{
			QWidget* pWidget = m_pLayout->itemAt(i)->widget();
			if (pWidget)
			{
				m_pLayout->removeWidget(pWidget);
				delete pWidget;
			}
		}
	}
	void CWidgetHLay::addLayout(QLayout* pLayout)
	{
		m_pLayout->addLayout(pLayout);
	}
	void CWidgetHLay::addStretch()
	{
		m_pLayout->addStretch();
	}

	void CWidgetHLay::setLayMargin(int left, int top, int right, int bottom)
	{
		m_pLayout->setContentsMargins(left, top, right, bottom);
	}
	void CWidgetHLay::setLayMargin(int margin)
	{
		m_pLayout->setMargin(margin);
	}
	void CWidgetHLay::setLaySpacing(int spacing)
	{
		m_pLayout->setSpacing(spacing);
	}
	void CWidgetHLay::setLayContentsMargins(int left, int top, int right, int bottom)
	{
		m_pLayout->setContentsMargins(left, top, right, bottom);
	}



	CWidgetGridLayout::CWidgetGridLayout(QWidget* parent)
	{
		m_pLayout = new QGridLayout(parent);
		setLayout(m_pLayout);
	}

	CWidgetGridLayout::~CWidgetGridLayout()
	{}
	void CWidgetGridLayout::addWidget(QWidget* pWidget, int row, int col, int rowSpan, int colSpan, Qt::Alignment alignment)
	{
		m_pLayout->addWidget(pWidget, row, col, rowSpan, colSpan, alignment);
	}
	void CWidgetGridLayout::removeWidget(QWidget* pWidget)
	{
		m_pLayout->removeWidget(pWidget);
	}
	void CWidgetGridLayout::clearLayout()
	{
		for (int i = 0; i < m_pLayout->count(); i++)
		{
			QWidget* pWidget = m_pLayout->itemAt(i)->widget();
			if (pWidget)
			{
				m_pLayout->removeWidget(pWidget);
				delete pWidget;
			}
		}
	}
	void CWidgetGridLayout::addLayout(QLayout* pLayout, int row, int col, int rowSpan, int colSpan, Qt::Alignment alignment)
	{
		m_pLayout->addLayout(pLayout, row, col, rowSpan, colSpan, alignment);
	}
	
	void CWidgetGridLayout::addStretch(int row, int col, int rowSpan, int colSpan)
	{
		m_pLayout->addItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Expanding), row, col, rowSpan, colSpan);
	}

	void CWidgetGridLayout::setLayMargin(int left, int top, int right, int bottom)
	{
		m_pLayout->setContentsMargins(left, top, right, bottom);
	}
	void CWidgetGridLayout::setLayMargin(int margin)
	{
		m_pLayout->setMargin(margin);
	}
	void CWidgetGridLayout::setLaySpacing(int spacing)
	{
		m_pLayout->setSpacing(spacing);
	}
	void CWidgetGridLayout::setLayContentsMargins(int left, int top, int right, int bottom)
	{
		m_pLayout->setContentsMargins(left, top, right, bottom);
	}

	void CWidgetGridLayout::setRowStretch(int row, int stretch)
	{
		m_pLayout->setRowStretch(row, stretch);
	}

	void CWidgetGridLayout::setColumnStretch(int column, int stretch)
	{
		m_pLayout->setColumnStretch(column, stretch);
	}



}
