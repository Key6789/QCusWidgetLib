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

		// 设置
		void setAppBtnVisible(bool visible);
		void setCanBtnVisible(bool visible);

		void setAppBtnEnabled(bool enabled);
		void setCanBtnEnabled(bool enabled);
	signals:
		void appBtnClicked();
		void canBtnClicked();

	private:
		QPushButton* m_appBtn = nullptr;
		QPushButton* m_canBtn = nullptr;
	};

	class QCUSWIDGETLIB_EXPORT CBtnsHBox : public QWidget
	{
		Q_OBJECT
	public:
		CBtnsHBox(QWidget* parent = nullptr);
		~CBtnsHBox() {}

		// 添加按钮
		void addBtn(int index, const QString& text);
		void setBtnText(int index, const QString& text);

		QPushButton* getBtn(int index);

		// 设置颜色
		void setBtnColor(int index, const QColor& color);

		// 设置图片
		void setBtnIcon(int index, const QIcon& icon);

		// 设置 连接信号槽
		void setBtnClicked(int index, const std::function<void()>& func);

		// 设置
		void setBtnVisible(int index, bool visible);
		void setBtnEnabled(int index, bool enabled);

		void clearBtns();

		void setConnect(int index, const std::function<void()>& func);
		void setStyleSheet(int index, const QString& styleSheet);

		void addStretch();

		void setLayMargin(int left, int top, int right, int bottom);

		void setLaySpacing(int spacing);


	signals:
		void btnClicked(int index);

	private:
		QMap<int, QPushButton*> m_btns = QMap<int, QPushButton*>();
		QHBoxLayout* m_layout = nullptr;
	};
	class QCUSWIDGETLIB_EXPORT CBtnsVBox : public QWidget
	{
		Q_OBJECT
	public:
		CBtnsVBox(QWidget* parent = nullptr);
		~CBtnsVBox() {}

		void addBtn(int index, const QString& text);
		QPushButton* getBtn(int index);
		void setBtnText(int index, const QString& text);

		// 设置颜色
		void setBtnColor(int index, const QColor& color);

		// 设置图片
		void setBtnIcon(int index, const QIcon& icon);

		// 设置 连接信号槽
		void setBtnClicked(int index, const std::function<void()>& func);

		// 设置
		void setBtnVisible(int index, bool visible);
		void setBtnEnabled(int index, bool enabled);

		void clearBtns();

		void setConnect(int index, const std::function<void()>& func);
		void setStyleSheet(int index, const QString& styleSheet);

		void setBtnClicked(int index, bool clicked);
		bool getBtnClicked(int index);

		// 设置间距
		void addStretch();

		// 设置尺寸
		void setSize(int width, int height);

		void setBtnFixSize(int index, int width, int height);
		void setBtnResize(int index, int width, int height);

		void setBtnSizePolicy(int index, QSizePolicy policy);
		void setObjectName(int index, const QString& name);
		void setBtnStyle(int index, const QString& styleSheet);
		void setBtnFont(int index, const QFont& font);

		QString getObjectName(int index);


	signals:
		void btnClicked(int index);


	private:
		QMap<int, QPushButton*> m_btns = QMap<int, QPushButton*>();
		QVBoxLayout* m_layout = nullptr;
	};

}
#endif // CLABLINEEDIT_H