#include "../include/CDialogHLay.h"

namespace QCUSWIDGETLIB
{
	CDialogHLay::CDialogHLay(QWidget* parent)
		: QDialog(parent)
	{
		initUI();
	}

	CDialogHLay::~CDialogHLay()
	{}
	void CDialogHLay::addWidget(QWidget * widget, int stretch)
	{
		m_hLayout->addWidget(widget, stretch);
	}
	void CDialogHLay::initUI()
	{
		m_hLayout = new QHBoxLayout(this);
		setLayout(m_hLayout);
	}
	CDialogVLay::CDialogVLay(QWidget* parent)
	{
		initUI();
	}
	CDialogVLay::~CDialogVLay()
	{}
	void CDialogVLay::addWidget(QWidget * widget, int stretch)
	{
		m_vLayout->addWidget(widget, stretch);
	}
	void CDialogVLay::initUI()
	{
		m_vLayout = new QVBoxLayout(this);
		setLayout(m_vLayout);
	}
}

