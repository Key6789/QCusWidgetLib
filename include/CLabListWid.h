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

		// ���ñ�ǩ���ı�
		void setLabelText(const QString& text);
		// �����б���
		void setListItems(const QStringList& items);
		// �����б�ǰ��
		void setListCurrentRow(int row);
		// �����б�ǰ��
		void setListCurrentItem(const QString& item);
		// �����б�ǰ��
		void setListCurrentItem(int row);
		// �����б�ǰ��
		void setListCurrentItem(const QString& item, int row);

		// ��ȡ��ǩ���ı�
		QString getLabelText() const;
		// ��ȡ�б���
		QStringList getListItems() const;
		// ��ȡ�б�ǰ��
		int getListCurrentRow() const;
		// ��ȡ�б�ǰ��
		QString getListCurrentItem() const;
		// ��ȡ��ǰ����к�
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
		// ��Ӷ���б���
		void addListItems(const QStringList& items);
		// ��ָ���в����б���
		void insertListItem(int row, const QString& item);
		// ɾ��ָ�����б���
		void removeListItem(const QString& item);
		// ������ɾ���б���
		void removeListItem(int row);
		// ����б���
		void clearListItems();
	private:
		// ������ָ��
		QVBoxLayout* m_pMainLayout = nullptr;
		// ��ǩָ��
		QLabel* m_pLabel = nullptr;
		// �б�ؼ�ָ��
		QListWidget* m_pList = nullptr;

		QMap<QString, QVariant> m_mapListItemValue;

	};
}
#endif // CLABLISTWID_H
