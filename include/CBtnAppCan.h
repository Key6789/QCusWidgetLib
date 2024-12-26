#pragma once
#ifndef CBTNAPPCAN_H_
#define CBTNAPPCAN_H_
#include "QCusWidgetLib_global.h"
#include <QWidget>
namespace QCUSWIDGETLIB
{
	// 建立一个模板类，用于继承QWidget，并添加一些共用的属性和方法
	// CBtnAppCan 类用于创建具有应用按钮和取消按钮的自定义控件
	class QCUSWIDGETLIB_EXPORT CBtnAppCan : public QWidget
	{
		Q_OBJECT
	public:
		// 构造函数，初始化父组件
		CBtnAppCan(QWidget* parent = nullptr);
		// 析构函数
		~CBtnAppCan() {}

		// 获取应用按钮
		QPushButton* getAppBtn();
		// 获取取消按钮
		QPushButton* getCanBtn();
		
		// 设置互斥属性
		void setMutualExclusive(bool mutual);

		// 设置应用按钮和取消按钮的顺序
	
		// 设置应用按钮文字
		void setAppBtnText(const QString& text);
		// 设置取消按钮文字
		void setCanBtnText(const QString& text);

		// 设置应用按钮颜色
		// 设置颜色
		void setAppBtnColor(const QColor& color);
		// 设置取消按钮颜色
		void setCanBtnColor(const QColor& color);

		// 设置应用按钮点击事件的信号槽
		// 设置 连接信号槽
		void setAppBtnClicked(const std::function<void()>& func);
		// 设置取消按钮点击事件的信号槽
		void setCanBtnClicked(const std::function<void()>& func);

		// 设置应用按钮的可见性
		void setAppBtnVisible(bool visible);
		// 设置取消按钮的可见性
		void setCanBtnVisible(bool visible);

		// 设置应用按钮的启用状态
		void setAppBtnEnabled(bool enabled);
		// 设置取消按钮的启用状态
		void setCanBtnEnabled(bool enabled);
	signals:
		// 应用按钮被点击时的信号
		void appBtnClicked();
		// 取消按钮被点击时的信号
		void canBtnClicked();

	private:
		QPushButton* m_appBtn = nullptr; // 应用按钮指针
		QPushButton* m_canBtn = nullptr; // 取消按钮指针

		
	};


	class QCUSWIDGETLIB_EXPORT CBtnsHBox : public QWidget
	{
		Q_OBJECT
	public:
		// 定义一个自定义的水平布局按钮容器类
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

		// 设置按钮可见性
		void setBtnVisible(int index, bool visible);
		void setBtnEnabled(int index, bool enabled);

		// 清空所有按钮
		void clearBtns();

		// 设置信号连接
		void setConnect(int index, const std::function<void()>& func);
		void setStyleSheet(int index, const QString& styleSheet);

		// 添加弹性空间
		void addStretch();

		// 设置布局边距
		void setLayMargin(int left, int top, int right, int bottom);

		// 设置布局间距
		void setLaySpacing(int spacing);


	signals:
		// 按钮被点击的信号
		void btnClicked(int index);

	private:
		// 存储按钮的映射
		QMap<int, QPushButton*> m_btns = QMap<int, QPushButton*>();
		// 水平布局指针
		QHBoxLayout* m_layout = nullptr;

	};

	// CBtnsVBox类用于管理垂直排列的按钮
	class QCUSWIDGETLIB_EXPORT CBtnsVBox : public QWidget
	{
		Q_OBJECT
	public:
		// 构造函数，初始化CBtnsVBox对象
		CBtnsVBox(QWidget* parent = nullptr);
		~CBtnsVBox() {}

		// 添加按钮
		void addBtn(int index, const QString& text);
		// 获取按钮
		QPushButton* getBtn(int index);
		// 设置按钮文本
		void setBtnText(int index, const QString& text);


		// 设置布局边距
		void setLayMargin(int left, int top, int right, int bottom);
		// 设置布局间距
		void setLaySpacing(int spacing);

		// 设置颜色
		// 设置按钮颜色
		void setBtnColor(int index, const QColor& color);

		// 设置图片
		// 设置按钮图标
		void setBtnIcon(int index, const QIcon& icon);

		// 设置 连接信号槽
		// 设置按钮点击时的回调函数
		void setBtnClicked(int index, const std::function<void()>& func);

		// 设置
		// 设置按钮的可见性
		void setBtnVisible(int index, bool visible);
		// 设置按钮的可用状态
		void setBtnEnabled(int index, bool enabled);

		// 清除所有按钮
		void clearBtns();

		// 设置连接
		void setConnect(int index, const std::function<void()>& func);
		// 设置样式表
		void setStyleSheet(int index, const QString& styleSheet);

		// 设置按钮点击状态
		void setBtnClicked(int index, bool clicked);
		// 获取按钮点击状态
		bool getBtnClicked(int index);

		// 设置间距
		void addStretch();

		// 设置尺寸
		// 设置CBtnsVBox的固定尺寸
		void setSize(int width, int height);

		// 设置按钮的固定大小
		void setBtnFixSize(int index, int width, int height);
		// 设置按钮的调整大小
		void setBtnResize(int index, int width, int height);

		// 设置按钮的大小策略
		void setBtnSizePolicy(int index, QSizePolicy policy);
		// 设置按钮的对象名称
		void setObjectName(int index, const QString& name);
		// 设置按钮的样式
		void setBtnStyle(int index, const QString& styleSheet);
		// 设置按钮的字体
		void setBtnFont(int index, const QFont& font);

		// 获取按钮的对象名称
		QString getObjectName(int index);


	signals:
		// 按钮点击信号
		void btnClicked(int index);


	private:
		// 存储按钮的映射
		QMap<int, QPushButton*> m_btns = QMap<int, QPushButton*>();
		// 垂直布局
		QVBoxLayout* m_layout = nullptr;
	};


}
#endif // CLABLINEEDIT_H