#pragma once
#ifndef CBTNAPPCAN_H_
#define CBTNAPPCAN_H_
#include <QWidget>
#include "QCusWidgetLib_global.h"
namespace QCUSWIDGETLIB
{
	// 建立一个模板类，用于继承QWidget，并添加一些共用的属性和方法
	class QCUSWIDGETLIB_EXPORT CBtnAppCan : public QWidget
	{
		Q_OBJECT
	public:
		CBtnAppCan(QWidget* parent = nullptr);
		~CBtnAppCan() {}

		QPushButton* getAppBtn();
		QPushButton* getCanBtn();
		void setAppBtnText(const QString& text);
		void setCanBtnText(const QString& text);

		// 设置颜色
		void setAppBtnColor(const QColor& color);
		void setCanBtnColor(const QColor& color);

		// 设置 连接信号槽
		void setAppBtnClicked(const std::function<void()>& func);
		void setCanBtnClicked(const std::function<void()>& func);

	signals:
		void appBtnClicked();
		void canBtnClicked();

	private:
		QPushButton* m_appBtn = nullptr;
		QPushButton* m_canBtn = nullptr;
	};
}
#endif // CLABLINEEDIT_H