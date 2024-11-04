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
	}
}

