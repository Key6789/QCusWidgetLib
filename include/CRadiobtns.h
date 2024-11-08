#pragma once
#ifndef CRADIOBTNTWO_H
#define CRADIOBTNTWO_H
#include "QCusWidgetLib_global.h"



#include <QWidget>
namespace QCUSWIDGETLIB
{
	class QCUSWIDGETLIB_EXPORT CRadioHLay : public QWidget
	{
		Q_OBJECT

	public:
		CRadioHLay(QWidget* parent);
		~CRadioHLay();

		// 设置 connects
		void setConnect(int radInt, std::function<void()> func);

		// 设置文本
		void setText(int id, const QString& text);

		// 设置默认选中
		void setDefaultChecked(int id);

		// 获取选中按钮的ID
		int getCheckedId();

		// 创建单选按钮
		void createRadioBtn(const QString& text, int id);

		// 删除单选按钮
		void removeRadioBtn(int id);
		void addWidget(QWidget* widget);

	private:
		QHBoxLayout* m_pLayout = nullptr;
		QButtonGroup* m_pGroup = nullptr;
		QMap<int, QRadioButton*> m_connectMap = QMap<int, QRadioButton*>();
	};

	class QCUSWIDGETLIB_EXPORT CRadioVLay : public QWidget
	{
		Q_OBJECT

	public:
		CRadioVLay(QWidget* parent);
		~CRadioVLay();

		void addWidget(QWidget* widget);

		// 设置 connects
		void setConnect(int radInt, std::function<void()> func);

		// 设置文本
		void setText(int id, const QString& text);

		// 设置默认选中
		void setDefaultChecked(int id);

		// 获取选中按钮的ID
		int getCheckedId();

		// 创建单选按钮
		void createRadioBtn(const QString& text, int id);

		// 删除单选按钮
		void removeRadioBtn(int id);

		void addStretch();

	private:
		QVBoxLayout* m_pLayout = nullptr;
		QButtonGroup* m_pGroup = nullptr;
		QMap<int, QRadioButton*> m_connectMap = QMap<int, QRadioButton*>();
	};
}
#endif // !