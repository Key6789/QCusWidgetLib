#include "../include/CRadiobtns.h"
namespace QCUSWIDGETLIB
{
	CRadioHLay::CRadioHLay(QWidget* parent)
	{
		m_pLayout = new QHBoxLayout(parent);
		setLayout(m_pLayout);
	}

	CRadioHLay::~CRadioHLay()
	{
	}

	void CRadioHLay::setConnect(int radInt, std::function<void()> func)
	{
		if (m_connectMap.find(radInt) != m_connectMap.end())
		{
			connect(m_connectMap[radInt], &QRadioButton::clicked, func);
		}
	}

	void CRadioHLay::setText(int id, const QString& text)
	{
		if (m_connectMap.find(id) != m_connectMap.end())
		{
			m_connectMap[id]->setText(text);
		}
	}

	void CRadioHLay::setDefaultChecked(int id)
	{
		if (m_connectMap.find(id) != m_connectMap.end())
		{
			m_connectMap[id]->setChecked(true);
		}
	}

	int CRadioHLay::getCheckedId()
	{
		for (auto it = m_connectMap.begin(); it!= m_connectMap.end(); ++it)
		{
			if (it.value()->isChecked())
			{
				return it.key();
			}
		}
		return -1;
	}

	void  CRadioHLay::createRadioBtn(const QString& text, int id)
	{
		QRadioButton* pBtn = new QRadioButton(text, this);
		//pBtn->setCheckable(true);
		pBtn->setAutoExclusive(true);
		m_pLayout->addWidget(pBtn);

		m_connectMap.insert(id, pBtn);
	}

	void CRadioHLay::removeRadioBtn(int id)
	{
		if (m_connectMap.find(id) != m_connectMap.end())
		{
			m_pLayout->removeWidget(m_connectMap[id]);
			m_connectMap.remove(id);
		}
	}

	void CRadioHLay::addWidget(QWidget* widget)
	{
		m_pLayout->addWidget(widget);
	}

	CRadioVLay::CRadioVLay(QWidget* parent)
	{
		m_pLayout = new QVBoxLayout(parent);
		setLayout(m_pLayout);
	}

	CRadioVLay::~CRadioVLay()
	{
	}

	void CRadioVLay::addWidget(QWidget* widget)
	{
		m_pLayout->addWidget(widget);
	}

	void CRadioVLay::setConnect(int radInt, std::function<void()> func)
	{
		if (m_connectMap.find(radInt) != m_connectMap.end())
		{
			connect(m_connectMap[radInt], &QRadioButton::clicked, func);
		}
	}

	void CRadioVLay::setText(int id, const QString& text)
	{
		if (m_connectMap.find(id) != m_connectMap.end())
		{
			m_connectMap[id]->setText(text);
		}
	}

	void CRadioVLay::setDefaultChecked(int id)
	{
		if (m_connectMap.find(id) != m_connectMap.end())
		{
			m_connectMap[id]->setChecked(true);
		}
	}

	int CRadioVLay::getCheckedId()
	{
		for (auto it = m_connectMap.begin(); it!= m_connectMap.end(); ++it)
		{
			if (it.value()->isChecked())
			{
				return it.key();
			}
		}
		return -1;	
	}
void  CRadioVLay::createRadioBtn(const QString& text, int id)
{
	QRadioButton* pBtn = new QRadioButton(text, this);
	//pBtn->setCheckable(true);
	pBtn->setAutoExclusive(true);
	m_pLayout->addWidget(pBtn);

	m_connectMap.insert(id, pBtn);
}

void CRadioVLay::removeRadioBtn(int id)
{
	if (m_connectMap.find(id) != m_connectMap.end())
	{
		m_pLayout->removeWidget(m_connectMap[id]);
		m_connectMap.remove(id);
	}
}

void CRadioVLay::addStretch()
{
	m_pLayout->addStretch();
}


}
