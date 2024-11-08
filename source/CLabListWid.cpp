#include "../include/CLabListWid.h"
namespace QCUSWIDGETLIB
{
	CLabListWid::CLabListWid(QWidget* parent)
		: QWidget(parent)
	{
		m_pLabel = new QLabel(this);
		m_pList = new QListWidget(this);

		m_pMainLayout = new QVBoxLayout(this);
		m_pMainLayout->addWidget(m_pLabel);
		m_pMainLayout->addWidget(m_pList);
		setLayout(m_pMainLayout);
		
	}

	CLabListWid::~CLabListWid()
	{}
	void CLabListWid::setLabelText(const QString & text)
	{
		m_pLabel->setText(text);
	}
	void CLabListWid::setListItems(const QStringList& items)
	{
		m_pList->clear();
		m_pList->addItems(items);
	}
	void CLabListWid::setListCurrentRow(int row)
	{
		m_pList->setCurrentRow(row);
	}
	void CLabListWid::setListCurrentItem(const QString& item)
	{
		m_pList->setCurrentItem(m_pList->findItems(item, Qt::MatchExactly)[0]);
	}
	void CLabListWid::setListCurrentItem(int row)
	{
		m_pList->setCurrentRow(row);
	}
	void CLabListWid::setListCurrentItem(const QString& item, int row)
	{
		m_pList->setCurrentItem(m_pList->findItems(item, Qt::MatchExactly)[row]);
	}
	QString CLabListWid::getLabelText() const
	{
		return m_pLabel->text();
	}
	QStringList CLabListWid::getListItems() const
	{
		QStringList items;
		for (int i = 0; i < m_pList->count(); i++)
		{
			items.append(m_pList->item(i)->text());
		}
		return items;
	}
	int CLabListWid::getListCurrentRow() const
	{
		return m_pList->currentRow();
	}
	QString CLabListWid::getListCurrentItem() const
	{
		if (m_pList->currentItem() == nullptr)
		{
			return "";
		}
		return m_pList->currentItem()->text();
	}
	int CLabListWid::getListCurrentItemRow() const
	{
		if (m_pList->currentItem() == nullptr)
		{
			return -1;
		}
		return m_pList->currentRow();
	}
	void CLabListWid::addListItem(const QString& item)
	{
		m_pList->addItem(item);
	}
	void CLabListWid::addListItem(const QString& item, int value)
	{
		m_pList->addItem(item);
		m_mapListItemValue.insert(item, value);
	}
	void CLabListWid::addListItem(const QString& item, QString value)
	{
		m_pList->addItem(item);
		m_mapListItemValue.insert(item, value);
	}
	QVariant CLabListWid::getListItemValue(const QString& item) const
	{
		if (m_mapListItemValue.contains(item))
		{
			return m_mapListItemValue.value(item);
		}
		return QVariant();
	}
	QVariant CLabListWid::getCurrentListItemValue() const
	{
		if (m_pList->currentItem() == nullptr)
		{
			return QVariant();
		}
		return getListItemValue(m_pList->currentItem()->text());
	}
	void CLabListWid::RemoveListItem(const QString& item)
	{
		for (int i = 0; i < m_pList->count(); i++)
		{
			if (m_pList->item(i)->text() == item)
			{
				m_pList->takeItem(i);
				break;
			}
		}
	}
	void CLabListWid::RemoveListItem(int row)
	{
		m_pList->takeItem(row);
	}
	void CLabListWid::ClearListItems()
	{
		m_pList->clear();
	}
	void CLabListWid::RemoveSelectedListItems()
	{
		m_pList->selectedItems();
		for (int i = 0; i < m_pList->count(); i++)
		{
			m_pList->takeItem(i);
		}
	}
	void CLabListWid::addListItems(const QStringList& items)
	{
		m_pList->addItems(items);
	}
	void CLabListWid::insertListItem(int row, const QString& item)
	{
		m_pList->insertItem(row, item);
	}
	void CLabListWid::removeListItem(const QString& item)
	{
		m_pList->selectedItems();
		for (int i = 0; i < m_pList->count(); i++)
		{
			if (m_pList->item(i)->text() == item)
			{
				m_pList->takeItem(i);
				break;
			}
		}
	}
	void CLabListWid::removeListItem(int row)
	{
		m_pList->takeItem(row);
	}
	void CLabListWid::clearListItems()
	{
		m_pList->clear();
	}
}
