#include "../include/CBtnAppCan.h"
namespace QCUSWIDGETLIB
{
	CBtnAppCan::CBtnAppCan(QWidget* parent)
	{
		QHBoxLayout* layout = new QHBoxLayout(this);
		m_appBtn = new QPushButton(this);
		m_canBtn = new QPushButton(this);
		m_appBtn->setText("应用");
		m_canBtn->setText("取消");
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
}