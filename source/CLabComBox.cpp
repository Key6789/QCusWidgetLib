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

	void CLabComBox::addItems(const QStringList& items)
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

	void CLabComBox::setLabel(const QString& strLabel)
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

	void CLabComBox::resizeEvent(QResizeEvent* event)
	{
		QWidget::resizeEvent(event);

		//// 设置比例为1:3
		//int nWidth = this->width();
		//int nHeight = this->height();
		//int nLabWidth = nWidth / 4;
		//int nComWidth = nWidth * 3 / 5;
		//m_labLabel->setFixedWidth(nLabWidth);
		//m_comBox->setFixedWidth(nComWidth);
		//m_labLabel->setFixedHeight(nHeight);
		//m_comBox->setFixedHeight(nHeight);

	}

	void CLabComBox::initUI()
	{
		// 设置边距并初始化水平布局
		// 设置内容margins为0
		this->setContentsMargins(0, 0, 0, 0);
		// 初始化水平布局
		m_layoutMain = new QHBoxLayout(this);

		// 设置水平布局的边距和间距为0
		m_layoutMain->setContentsMargins(0, 0, 0, 0);
		m_layoutMain->setSpacing(0);
		m_layoutMain->setMargin(0);
		m_layoutMain->setAlignment(Qt::AlignLeft);

		m_labLabel = new QLabel(this);
		m_comBox = new QComboBox(this);
		m_layoutMain->addWidget(m_labLabel, 1);
		m_layoutMain->addWidget(m_comBox, 3);

		m_labLabel->setMargin(0);
		m_comBox->setContentsMargins(0, 0, 0, 0);
		m_labLabel->setAlignment(Qt::AlignLeft);
		setLayout(m_layoutMain);


		connect(m_comBox, &QComboBox::currentTextChanged, [=](const QString& text) {emit currentTextChanged(text); });
	}
}