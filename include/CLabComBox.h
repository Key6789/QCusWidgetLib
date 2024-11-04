#pragma once

#include <QWidget>
#include "QCusWidgetLib_global.h"
namespace QCUSWIDGETLIB
{
	//��ǩ����Ͽ�ؼ�
	class QCUSWIDGETLIB_EXPORT CLabComBox : public QWidget
	{
		Q_OBJECT
	public:
		CLabComBox(QWidget* parent);
		~CLabComBox();
		QComboBox* getComBox();
		// ������Ŀ�ĺ���������Ϊ��Ŀ�ַ����б�
		void addItems(const QStringList& items);
		void addItems(QMap<QString, QString>& items);

		QString getKeyFromValue(const QString& value);
		QString getValueFromKey(const QString& key);

		// ���ñ�ǩ�ĺ���������Ϊ��ǩ�ַ���
		void setLabel(const QString& strLabel);

		// ������Ŀ�ĺ���������Ϊ��Ŀ�ַ���
		void addItem(const QString& strItem);
		void addItem(const QString& key, const QString& value);

		// ���õ�ǰ�����ĺ���������Ϊ��������
		void setCurIndex(int nIndex);

		// ��ȡ��ǰ�����ĺ��������ص�ǰ��������
		int getCurIndex();

		// ��ȡ��ǰ�ı��ĺ��������ص�ǰ�ı��ַ���
		QString getCurText();

		// ���������Ŀ�ĺ���
		void clear();

	signals:
		void currentIndexChanged(int index);
		void currentTextChanged(const QString& text);

	private:
		void initUI();

		QLabel* m_labLabel = nullptr;
		QComboBox* m_comBox = nullptr;
	};

}
