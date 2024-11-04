#pragma once
#ifndef CBTNAPPCAN_H_
#define CBTNAPPCAN_H_
#include <QWidget>
#include "QCusWidgetLib_global.h"
namespace QCUSWIDGETLIB
{
	// ����һ��ģ���࣬���ڼ̳�QWidget�������һЩ���õ����Ժͷ���
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

		// ������ɫ
		void setAppBtnColor(const QColor& color);
		void setCanBtnColor(const QColor& color);

		// ���� �����źŲ�
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