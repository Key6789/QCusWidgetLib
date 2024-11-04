#pragma once
#ifndef CLABLINEEDIT_H
#define CLABLINEEDIT_H
#include <QWidget>
#include <QLineEdit>
#include "QCusWidgetLib_global.h"
namespace QCUSWIDGETLIB
{
	// 建立一个模板类，用于继承QWidget，并添加一些共用的属性和方法
	class QCUSWIDGETLIB_EXPORT CLabLineEdit : public QWidget
	{
		Q_OBJECT
	public:
		CLabLineEdit(QWidget* parent = nullptr);

		// 设置标签文本
		void setLabelText(QString text);
		// 设置行编辑文本
		void setLineEditText(QString text);
		// 设置只读状态
		void setReadOnly(bool isReadOnly);
		// 设置占位符文本
		void setPlaceholderText(QString text);
		// 设置单位文本
		void setUnitText(QString text);
		// 获取行编辑文本
		QString getLineEditText();
		// 获取行编辑控件
		QLineEdit* getLineEdit();


	private:
		QLabel* m_label = nullptr;
		QLineEdit* m_lineEdit = nullptr;
	};

	class QCUSWIDGETLIB_EXPORT CLabLineEditBtn : public QWidget
	{
		Q_OBJECT
	public:
		CLabLineEditBtn(QWidget* parent = nullptr);

		void setLineEditReadOnly(bool isReadOnly);
		// 设置标签文本
		void setLabelText(QString text);
		// 设置行编辑文本
		void setLineEditText(QString text);
		// 设置只读状态
		void setReadOnly(bool isReadOnly);
		// 设置占位符文本
		void setPlaceholderText(QString text);
		// 设置单位文本
		void setUnitText(QString text);
		// 设置按钮文本
		void setBtnText(QString text);
		// 设置按钮图标
		void setBtnIcon(QIcon icon);
		// 获取行编辑文本
		QString getLineEditText();
		// 获取行编辑控件
		QLineEdit* getLineEdit();
		// 获取按钮控件
		QPushButton* getBtn();

		// 设置按钮可见性
		void setBtnVisible(bool isVisible);

		void connectBtnClicked(const std::function<void()>& func);
		void connectBtnClicked(void(*func)());
		void setPathFilter(const QString& filter);
		void btnClickedPath();
		void btnClickedColor();

	signals:
		void signalLineEditChanged(QString text);

	private:
		QLabel* m_label = nullptr;
		QLineEdit* m_lineEdit = nullptr;
		QPushButton* m_btn = nullptr;

		QString m_pathFilter = "";
	};
}
#endif // CLABLINEEDIT_H