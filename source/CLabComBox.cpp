#include "../include/CLabComBox.h"
namespace QCUSWIDGETLIB
{
	CLabComBox::CLabComBox(QWidget* parent)
		: QWidget(parent)
	{
		initUI();
	}

	CLabComBox::~CLabComBox()
	{}

	QComboBox* CLabComBox::getComBox()
	{
		return m_comBox;
	}

	void CLabComBox::addItems(const QStringList & items)
	{
		m_comBox->addItems(items);
	}

	void CLabComBox::addItems(QMap<QString, QString>& items)
	{
		QMapIterator<QString, QString> it(items);
		while (it.hasNext())
		{
			it.next();
			m_comBox->addItem(it.key(), it.value());
		}
	}

	QString CLabComBox::getKeyFromValue(const QString& value)
	{
		return m_comBox->itemData(m_comBox->findData(value)).toString();
	}

	QString CLabComBox::getValueFromKey(const QString& key)
	{
		return m_comBox->itemData(m_comBox->findText(key)).toString();
	}

	void CLabComBox::setLabel(const QString & strLabel)
	{
		m_labLabel->setText(strLabel);
	}

	void CLabComBox::addItem(const QString& strItem)
	{
		m_comBox->addItem(strItem);
	}

	void CLabComBox::addItem(const QString& key, const QString& value)
	{
		m_comBox->addItem(key, value);
	}

	void CLabComBox::addItem(const QString& key, const int& value)
	{
		m_comBox->addItem(key, value);
	}

	void CLabComBox::addItem(const QString& key, const QVariant& value)
	{
		m_comBox->addItem(key, value);
	}

	void CLabComBox::setCurIndex(int nIndex)
	{
		m_comBox->setCurrentIndex(nIndex);
	}

	int CLabComBox::getCurIndex()
	{
		return m_comBox->currentIndex();
	}

	QString CLabComBox::getCurText()
	{
		return m_comBox->currentText();
	}

	void CLabComBox::clear()
	{
		m_comBox->clear();
	}

	void CLabComBox::setConnect(std::function<void(QString)> func)
	{
		connect(m_comBox, &QComboBox::currentTextChanged, func);
	}

	void CLabComBox::initUI()
	{
		this->setContentsMargins(0, 0, 0, 0);
		QHBoxLayout* layout = new QHBoxLayout(this);
		layout->setContentsMargins(0, 0, 0, 0);
		layout->setSpacing(0);
		layout->setMargin(0);
		layout->setAlignment(Qt::AlignLeft);
		m_labLabel = new QLabel(this);
		m_comBox = new QComboBox(this);
		layout->addWidget(m_labLabel);
		layout->addWidget(m_comBox);
		setLayout(layout);

		connect(m_comBox, &QComboBox::currentTextChanged, [=](const QString& text) {emit currentTextChanged(text); });
	}
}