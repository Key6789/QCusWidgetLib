#include "../include/CLabSpinBox.h"
namespace QCUSWIDGETLIB
{
	CLabSpinBox::CLabSpinBox(QWidget* parent)
		: QWidget(parent)
	{
		initUI();
	
	}

	CLabSpinBox::~CLabSpinBox()
	{}
	void CLabSpinBox::setRange(int min, int max)
	{
		m_spinIntBox->setMinimum(min);
		m_spinIntBox->setMaximum(max);
	}
	void CLabSpinBox::setValue(int value)
	{
		m_spinIntBox->setValue(value);
	}
	int CLabSpinBox::value() const
	{
		return m_spinIntBox->value();
	}
	void CLabSpinBox::setLabelText(const QString& text)
	{
		m_labIntBox->setText(text);
	}
	void CLabSpinBox::setLabelAlignment(Qt::Alignment alignment)
	{
		m_labIntBox->setAlignment(alignment);
	}
	void CLabSpinBox::setReadOnly(bool readOnly)
	{
		m_spinIntBox->setReadOnly(readOnly);
	}
	bool CLabSpinBox::isReadOnly() const
	{
		return m_spinIntBox->isReadOnly();
	}
	void CLabSpinBox::setEnabled(bool enabled)
	{
		m_spinIntBox->setEnabled(enabled);
		m_labIntBox->setEnabled(enabled);
	}
	bool CLabSpinBox::isEnabled() const
	{
		return m_spinIntBox->isEnabled();
	}

	void CLabSpinBox::setSingleStep(int step)
	{
		m_spinIntBox->setSingleStep(step);
	}

	int CLabSpinBox::singleStep() const
	{
		return m_spinIntBox->singleStep();
	}

	void CLabSpinBox::setPrefix(const QString& prefix)
	{
		m_spinIntBox->setPrefix(prefix);
	}

	QString CLabSpinBox::prefix() const
	{
		return m_spinIntBox->prefix();
	}

	void CLabSpinBox::setSuffix(const QString& suffix)
	{
		m_spinIntBox->setSuffix(suffix);
	}

	QString CLabSpinBox::suffix() const
	{
		return m_spinIntBox->suffix();
	}



	void CLabSpinBox::initUI()
	{
		QHBoxLayout* layout = new QHBoxLayout(this);
		m_labIntBox = new QLabel(this);
		m_spinIntBox = new QSpinBox(this);
		m_labIntBox->setText("Integer:");
		m_spinIntBox->setMinimum(INT_MIN);
		m_spinIntBox->setMaximum(INT_MAX);
		m_spinIntBox->setSingleStep(1);
		layout->addWidget(m_labIntBox);
		layout->addWidget(m_spinIntBox);
		m_labIntBox->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
		// 
		setLayout(layout);
		
	}
	void CLabSpinBox::initConnections()
	{
		connect(m_spinIntBox, qOverload<int>(&QSpinBox::valueChanged), [=](int value) {emit valueChanged(value);});
	}
}