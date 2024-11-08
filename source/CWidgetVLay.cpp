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
	void CWidgetVLay::addWidget(QWidget * pWidget)
	{
		m_pLayout->addWidget(pWidget);
	}
	void CWidgetVLay::removeWidget(QWidget* pWidget)
	{
		m_pLayout->removeWidget(pWidget);
	}
	void CWidgetVLay::clearLayout()
	{
		for(int i = 0; i < m_pLayout->count(); i++)
		{
			QWidget* pWidget = m_pLayout->itemAt(i)->widget();
			if(pWidget)
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



	CWidgetHLay::CWidgetHLay(QWidget* parent)
	{
		m_pLayout = new QHBoxLayout(parent);
		setLayout(m_pLayout);
	}

	CWidgetHLay::~CWidgetHLay()
	{}
	void CWidgetHLay::addWidget(QWidget * pWidget)
	{
		m_pLayout->addWidget(pWidget);
	}
	void CWidgetHLay::removeWidget(QWidget* pWidget)
	{
		m_pLayout->removeWidget(pWidget);
	}
	void CWidgetHLay::clearLayout()
	{
		for(int i = 0; i < m_pLayout->count(); i++)
		{
			QWidget* pWidget = m_pLayout->itemAt(i)->widget();
			if(pWidget)
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

}
