#include "../include/CBtnAppCan.h"
namespace QCUSWIDGETLIB
{
	CBtnAppCan::CBtnAppCan(QWidget* parent)
	{
		QHBoxLayout* layout = new QHBoxLayout(this);
		layout->setContentsMargins(0, 0, 0, 0);
		layout->setSpacing(0);
		layout->setMargin(0);

		m_appBtn = new QPushButton(this);
		m_canBtn = new QPushButton(this);
		m_appBtn->setText("Ӧ��");
		m_canBtn->setText("ȡ��");
		layout->addWidget(m_appBtn);
		layout->addWidget(m_canBtn);
		setLayout(layout);

		connect(m_appBtn, &QPushButton::clicked, [=]() { emit appBtnClicked(); });
		connect(m_canBtn, &QPushButton::clicked, [=]() { emit canBtnClicked(); });
	}
	QPushButton* CBtnAppCan::getAppBtn()
	{
		return m_appBtn;
	}
	QPushButton* CBtnAppCan::getCanBtn()
	{
		return m_canBtn;
	}
	void CBtnAppCan::setAppBtnText(const QString& text)
	{
		m_appBtn->setText(text);
	}
	void CBtnAppCan::setCanBtnText(const QString& text)
	{
		m_canBtn->setText(text);
	}
	void CBtnAppCan::setAppBtnColor(const QColor& color)
	{
		m_appBtn->setStyleSheet("background-color: " + color.name() + ";");
	}
	void CBtnAppCan::setCanBtnColor(const QColor& color)
	{
		m_canBtn->setStyleSheet("background-color: " + color.name() + ";");
	}
	void CBtnAppCan::setAppBtnClicked(const std::function<void()>& func)
	{
		connect(m_appBtn, &QPushButton::clicked, func);
	}
	void CBtnAppCan::setCanBtnClicked(const std::function<void()>& func)
	{
		connect(m_canBtn, &QPushButton::clicked, func);
	}
	void CBtnAppCan::setAppBtnVisible(bool visible)
	{
		m_appBtn->setVisible(visible);
	}
	void CBtnAppCan::setCanBtnVisible(bool visible)
	{
		m_canBtn->setVisible(visible);
	}
	void CBtnAppCan::setAppBtnEnabled(bool enabled)
	{
		m_appBtn->setEnabled(enabled);
	}
	void CBtnAppCan::setCanBtnEnabled(bool enabled)
	{
		m_canBtn->setEnabled(enabled);
	}
	CBtnsHBox::CBtnsHBox(QWidget* parent)
	{
		m_layout = new QHBoxLayout(this);
		setLayout(m_layout);
	}

	void CBtnsHBox::addBtn(int index, const QString& text)
	{
		QPushButton* btn = new QPushButton(text, this);
		m_layout->addWidget(btn);
		m_btns.insert(index, btn);
	}

	void CBtnsHBox::setBtnText(int index, const QString& text)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setText(text);
		}
	}

	QPushButton* CBtnsHBox::getBtn(int index)
	{
		if (m_btns.contains(index))
		{
			return m_btns.value(index);
		}
		else
		{
			return nullptr;
		}
	}
	void CBtnsHBox::setBtnColor(int index, const QColor& color)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setStyleSheet("background-color: " + color.name() + ";");
		}
	}
	void CBtnsHBox::setBtnIcon(int index, const QIcon& icon)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setIcon(icon);
		}
	}
	void CBtnsHBox::setBtnClicked(int index, const std::function<void()>& func)
	{
		if (m_btns.contains(index))
		{
			connect(m_btns.value(index), &QPushButton::clicked, func);
		}
	}
	void CBtnsHBox::setBtnVisible(int index, bool visible)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setVisible(visible);
		}
	}
	void CBtnsHBox::setBtnEnabled(int index, bool enabled)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setEnabled(enabled);
		}
	}
	void CBtnsHBox::clearBtns()
	{
		m_layout->removeWidget(m_btns.value(0));
		m_btns.clear();
	}

	void CBtnsHBox::setConnect(int index, const std::function<void()>& func)
	{
		if (m_btns.contains(index))
		{
			connect(m_btns.value(index), &QPushButton::clicked, func);
		}
	}

	void CBtnsHBox::setStyleSheet(int index, const QString& styleSheet)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setStyleSheet(styleSheet);
		}
	}

	void CBtnsHBox::addStretch()
	{
		m_layout->addStretch();
	}

	void CBtnsHBox::setLayMargin(int left, int top, int right, int bottom)
	{
		m_layout->setContentsMargins(left, top, right, bottom);
	}

	void CBtnsHBox::setLaySpacing(int spacing)
	{
		m_layout->setSpacing(spacing);
	}

	CBtnsVBox::CBtnsVBox(QWidget* parent)
	{
		m_layout = new QVBoxLayout(this);
		setLayout(m_layout);
	}
	void CBtnsVBox::addBtn(int index, const QString& text) {
		QPushButton* btn = new QPushButton(text, this);
		m_layout->addWidget(btn);
		m_btns.insert(index, btn);
	}
	QPushButton* CBtnsVBox::getBtn(int index) {
		if (m_btns.contains(index))
		{
			return m_btns.value(index);
		}
		else
		{
			return nullptr;
		}
	}
	void CBtnsVBox::setBtnText(int index, const QString& text)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setText(text);
		}
	}
	void CBtnsVBox::setLayMargin(int left, int top, int right, int bottom)
	{
		m_layout->setContentsMargins(left, top, right, bottom);
	}
	void CBtnsVBox::setLaySpacing(int spacing)
	{
		m_layout->setSpacing(spacing);
	}
	void CBtnsVBox::setBtnColor(int index, const QColor& color) {
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setStyleSheet("background-color: " + color.name() + ";");
		}
	}
	void CBtnsVBox::setBtnIcon(int index, const QIcon& icon)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setIcon(icon);
		}
	}
	void CBtnsVBox::setBtnClicked(int index, const std::function<void()>& func) {
		if (m_btns.contains(index))
		{
			connect(m_btns.value(index), &QPushButton::clicked, func);
		}
	}
	void CBtnsVBox::setBtnVisible(int index, bool visible) {
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setVisible(visible);
		}
	}
	void CBtnsVBox::setBtnEnabled(int index, bool enabled) {
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setEnabled(enabled);
		}
	}
	void CBtnsVBox::clearBtns() {
		m_layout->removeWidget(m_btns.value(0));
		m_btns.clear();
	}
	void CBtnsVBox::setConnect(int index, const std::function<void()>& func) {
		if (m_btns.contains(index))
		{
			connect(m_btns.value(index), &QPushButton::clicked, func);
		}
	}
	void CBtnsVBox::setStyleSheet(int index, const QString& styleSheet) {
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setStyleSheet(styleSheet);
		}
	}

	void CBtnsVBox::setBtnClicked(int index, bool clicked)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setChecked(clicked);
		}
	}

	bool CBtnsVBox::getBtnClicked(int index)
	{
		if (m_btns.contains(index))
		{
			return m_btns.value(index)->isChecked();
		}
		else
		{
			return false;
		}
	}

	void CBtnsVBox::addStretch()
	{
		m_layout->addStretch();
	}

	void CBtnsVBox::setSize(int width, int height)
	{
		setFixedSize(width, height);
	}

	void CBtnsVBox::setBtnFixSize(int index, int width, int height)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setFixedSize(width, height);
		}
	}

	void CBtnsVBox::setBtnResize(int index, int width, int height)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->resize(width, height);
		}
	}

	void CBtnsVBox::setBtnSizePolicy(int index, QSizePolicy policy)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setSizePolicy(policy);
		}
	}

	void CBtnsVBox::setObjectName(int index, const QString& name)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setObjectName(name);
		}
	}

	void CBtnsVBox::setBtnStyle(int index, const QString& styleSheet)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setStyleSheet(styleSheet);
		}
	}

	void CBtnsVBox::setBtnFont(int index, const QFont& font)
	{
		if (m_btns.contains(index))
		{
			m_btns.value(index)->setFont(font);
		}
	}

	QString CBtnsVBox::getObjectName(int index)
	{
		if (m_btns.contains(index))
		{
			return m_btns.value(index)->objectName();
		}
		else
		{
			return "";
		}
	}



}