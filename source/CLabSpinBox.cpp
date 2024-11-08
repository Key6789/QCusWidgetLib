#include "../include/CLabSpinBox.h"
namespace QCUSWIDGETLIB
{
	CLabSpinBox::CLabSpinBox(QWidget* parent)
		: QWidget(parent)
	{
		this->setContentsMargins(0, 0, 0, 0);
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

	void CLabSpinBox::setConnect(std::function<void(int)> func)
	{
		connect(m_spinIntBox, qOverload<int>(&QSpinBox::valueChanged), func);
	}

	void CLabSpinBox::setLabelVis(bool vis)
	{
		m_labIntBox->setVisible(vis);
	}

	int CLabSpinBox::getIntValue() const
	{
		return m_spinIntBox->value();
	}



	void CLabSpinBox::initUI()
	{
		QHBoxLayout* layout = new QHBoxLayout(this);
		layout->setMargin(0);
		layout->setContentsMargins(0, 0, 0, 0);
		layout->setSpacing(0);
		m_labIntBox = new QLabel(this);
		m_spinIntBox = new QSpinBox(this);
		m_labIntBox->setText("Integer:");
		m_spinIntBox->setMinimum(INT_MIN);
		m_spinIntBox->setMaximum(INT_MAX);
		m_spinIntBox->setSingleStep(1);
		layout->addWidget(m_labIntBox,1);
		layout->addWidget(m_spinIntBox, 5);
		
		setLayout(layout);
		
	}
	void CLabSpinBox::initConnections()
	{
		connect(m_spinIntBox, qOverload<int>(&QSpinBox::valueChanged), [=](int value) {emit valueChanged(value);});
	}


	CLabDoubleSpinBox::CLabDoubleSpinBox(QWidget* parent)
	{
		initUI();
		initConnections();
	}

	CLabDoubleSpinBox::~CLabDoubleSpinBox()
	{}

	void CLabDoubleSpinBox::setRange(double min, double max)
	{
		m_spinDoubleBox->setMinimum(min);
		m_spinDoubleBox->setMaximum(max);
	}

	void CLabDoubleSpinBox::setValue(double value)
	{
		m_spinDoubleBox->setValue(value);
	}

	double CLabDoubleSpinBox::value() const
	{
		return m_spinDoubleBox->value();
	}

	void CLabDoubleSpinBox::setLabelText(const QString& text)
	{
		m_labDoubleBox->setText(text);
	}

	void CLabDoubleSpinBox::setLabelAlignment(Qt::Alignment alignment)
	{
		m_labDoubleBox->setAlignment(alignment);
	}

	void CLabDoubleSpinBox::setReadOnly(bool readOnly)
	{
		m_spinDoubleBox->setReadOnly(readOnly);
	}

	bool CLabDoubleSpinBox::isReadOnly() const
	{
		return m_spinDoubleBox->isReadOnly();
	}

	void CLabDoubleSpinBox::setEnabled(bool enabled)
	{
		m_spinDoubleBox->setEnabled(enabled);
		m_labDoubleBox->setEnabled(enabled);
	}

	bool CLabDoubleSpinBox::isEnabled() const
	{
		return m_spinDoubleBox->isEnabled();
	}

	void CLabDoubleSpinBox::setSingleStep(double step)
	{
		m_spinDoubleBox->setSingleStep(step);
	}

	double CLabDoubleSpinBox::singleStep() const
	{
		return m_spinDoubleBox->singleStep();
	}

	void CLabDoubleSpinBox::setPrefix(const QString& prefix)
	{
		m_spinDoubleBox->setPrefix(prefix);
	}

	QString CLabDoubleSpinBox::prefix() const
	{
		return m_spinDoubleBox->prefix();
	}

	void CLabDoubleSpinBox::setSuffix(const QString& suffix)
	{
		m_spinDoubleBox->setSuffix(suffix);
	}

	QString CLabDoubleSpinBox::suffix() const
	{
		return m_spinDoubleBox->suffix();
	}

	void CLabDoubleSpinBox::setConnect(std::function<void(double)> func)
	{
		connect(m_spinDoubleBox, qOverload<double>(&QDoubleSpinBox::valueChanged), func);
	}

	void CLabDoubleSpinBox::initUI()
	{
		this->setContentsMargins(0, 0, 0, 0);
		QHBoxLayout* layout = new QHBoxLayout(this);
		layout->setMargin(0);
		layout->setContentsMargins(0, 0, 0, 0);
		m_labDoubleBox = new QLabel(this);
		m_spinDoubleBox = new QDoubleSpinBox(this);
		m_labDoubleBox->setText("Double:");
		m_spinDoubleBox->setMinimum(DBL_MIN);
		m_spinDoubleBox->setMaximum(DBL_MAX);
		m_spinDoubleBox->setSingleStep(1.0);
		layout->addWidget(m_labDoubleBox, 1);
		
		layout->addWidget(m_spinDoubleBox, 5);

		// 

		
		//m_labDoubleBox->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
		setLayout(layout);
	}

	void CLabDoubleSpinBox::initConnections()
	{
		connect(m_spinDoubleBox, qOverload<double>(&QDoubleSpinBox::valueChanged), [=](double value) {emit valueChanged(value);});
	}

}