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

		// ���� connects
		void setConnect(int radInt, std::function<void()> func);

		// �����ı�
		void setText(int id, const QString& text);

		// ����Ĭ��ѡ��
		void setDefaultChecked(int id);

		// ��ȡѡ�а�ť��ID
		int getCheckedId();

		// ������ѡ��ť
		void createRadioBtn(const QString& text, int id);

		// ɾ����ѡ��ť
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

		// ���� connects
		void setConnect(int radInt, std::function<void()> func);

		// �����ı�
		void setText(int id, const QString& text);

		// ����Ĭ��ѡ��
		void setDefaultChecked(int id);

		// ��ȡѡ�а�ť��ID
		int getCheckedId();

		// ������ѡ��ť
		void createRadioBtn(const QString& text, int id);

		// ɾ����ѡ��ť
		void removeRadioBtn(int id);

		void addStretch();

	private:
		QVBoxLayout* m_pLayout = nullptr;
		QButtonGroup* m_pGroup = nullptr;
		QMap<int, QRadioButton*> m_connectMap = QMap<int, QRadioButton*>();
	};
}
#endif // !