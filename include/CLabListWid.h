#pragma once
#ifndef CLABLISTWID_H
#define CLABLISTWID_H

#include "QCusWidgetLib_global.h"
#include <QWidget>

namespace QCUSWIDGETLIB
{
	class QCUSWIDGETLIB_EXPORT CLabListWid : public QWidget
	{
		Q_OBJECT

	public:
		CLabListWid(QWidget* parent);
		~CLabListWid();

		// 设置标签的文本
		void setLabelText(const QString& text);
		// 设置列表项
		void setListItems(const QStringList& items);
		// 设置列表当前行
		void setListCurrentRow(int row);
		// 设置列表当前项
		void setListCurrentItem(const QString& item);
		// 设置列表当前项
		void setListCurrentItem(int row);
		// 设置列表当前项
		void setListCurrentItem(const QString& item, int row);

		// 获取标签的文本
		QString getLabelText() const;
		// 获取列表项
		QStringList getListItems() const;
		// 获取列表当前行
		int getListCurrentRow() const;
		// 获取列表当前项
		QString getListCurrentItem() const;
		// 获取当前项的行号
		int getListCurrentItemRow() const;

		// 
		void addListItem(const QString& item);
		void addListItem(const QString& item, int value);
		void addListItem(const QString& item, QString value);

		QVariant getListItemValue(const QString& item) const;
		QVariant getCurrentListItemValue() const;

		void RemoveListItem(const QString& item);
		void RemoveListItem(int row);
		void ClearListItems();
		void RemoveSelectedListItems();
		// 添加多个列表项
		void addListItems(const QStringList& items);
		// 在指定行插入列表项
		void insertListItem(int row, const QString& item);
		// 删除指定的列表项
		void removeListItem(const QString& item);
		// 根据行删除列表项
		void removeListItem(int row);
		// 清空列表项
		void clearListItems();
	private:
		// 主布局指针
		QVBoxLayout* m_pMainLayout = nullptr;
		// 标签指针
		QLabel* m_pLabel = nullptr;
		// 列表控件指针
		QListWidget* m_pList = nullptr;

		QMap<QString, QVariant> m_mapListItemValue;

	};
}
#endif // CLABLISTWID_H
