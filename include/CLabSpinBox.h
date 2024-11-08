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

		// ���� decimal ����

		// s��������
		void setConnect(std::function<void(int)> func);

		// ���ñ�ǩ ��Vis
		void setLabelVis(bool vis);

		int getIntValue() const;

	signals:
		void valueChanged(int value);

	private:
		void initUI();
		void initConnections();

		QSpinBox* m_spinIntBox = nullptr;
		QLabel* m_labIntBox = nullptr;
	};

	// double�汾��spinbox
	class QCUSWIDGETLIB_EXPORT CLabDoubleSpinBox : public QWidget
	{
		Q_OBJECT

	public:
		CLabDoubleSpinBox(QWidget* parent);
		~CLabDoubleSpinBox();

		// ���÷�Χ����Сֵ�����ֵ
		void setRange(double min, double max);
		// ���õ�ǰֵ
		void setValue(double value);
		// ��ȡ��ǰֵ
		double value() const;

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
		void setSingleStep(double step);
		// ��ȡ��������
		double singleStep() const;

		// ����ǰ׺
		void setPrefix(const QString& prefix);
		// ��ȡǰ׺
		QString prefix() const;

		// ���ú�׺
		void setSuffix(const QString& suffix);
		// ��ȡ��׺
		QString suffix() const;

		void setConnect(std::function<void(double)> func);

	signals:
		void valueChanged(double value);

	private:
		void initUI();
		void initConnections();

		QDoubleSpinBox* m_spinDoubleBox = nullptr;
		QLabel* m_labDoubleBox = nullptr;
	};
}

#endif // CLABSPINBOX_H
