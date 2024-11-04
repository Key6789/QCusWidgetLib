#pragma once
#ifndef CLABSPINBOX_H
#define CLABSPINBOX_H

#include <QWidget>
#include "QCusWidgetLib_global.h"

namespace QCUSWIDGETLIB
{
	class QCUSWIDGETLIB_EXPORT CLabSpinBox : public QWidget
	{
		Q_OBJECT

	public:
		CLabSpinBox(QWidget* parent);
		~CLabSpinBox();

		// ���÷�Χ����Сֵ�����ֵ
		void setRange(int min, int max);
		// ���õ�ǰֵ
		void setValue(int value);
		// ��ȡ��ǰֵ
		int value() const;

		// ���ñ�ǩ�ı�
		void setLabelText(const QString& text);
		// ���ñ�ǩ���뷽ʽ
		void setLabelAlignment(Qt::Alignment alignment);

		// ����ֻ��״̬
		void setReadOnly(bool readOnly);
		// ��ȡ�Ƿ�Ϊֻ��״̬
		bool isReadOnly() const;

		// ���ÿؼ��Ƿ�����
		void setEnabled(bool enabled);
		// ��ȡ�ؼ��Ƿ�����
		bool isEnabled() const;

		// ���õ�������
		void setSingleStep(int step);
		// ��ȡ��������
		int singleStep() const;

		// ����ǰ׺
		void setPrefix(const QString& prefix);
		// ��ȡǰ׺
		QString prefix() const;

		// ���ú�׺
		void setSuffix(const QString& suffix);
		// ��ȡ��׺
		QString suffix() const;

	signals:
		void valueChanged(int value);

	private:
		void initUI();
		void initConnections();

		QSpinBox* m_spinIntBox = nullptr;
		QLabel* m_labIntBox = nullptr;
	};


}

#endif // CLABSPINBOX_H
