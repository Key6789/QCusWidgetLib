#pragma once
#ifndef CLABELPROLABEL_H
#define CLABELPROLABEL_H
#include <QWidget>
#include "QCusWidgetLib_global.h"

namespace QCUSWIDGETLIB
{
	class QCUSWIDGETLIB_EXPORT ClabelProLabel : public QWidget
	{
		Q_OBJECT

	public:
		ClabelProLabel(QWidget* parent);
		~ClabelProLabel();
		// ���ý������ĵ�һ����ǩ�ı�
		void setFirstLabel(const QString& text);
		// ���ý����������һ����ǩ�ı�
		void setEndLabel(const QString& text);
		// ���ý������ĵ�ǰ����
		void setProgressValue(int value);
		int getProgressValue();

		// ���õ�һ����ǩ�Ŀɼ���
		void setFirstLabelVisible(bool visible);
		// �������һ����ǩ�Ŀɼ���
		void setEndLabelVisible(bool visible);
		// ���ý������Ŀɼ���
		void setProgressBarVisible(bool visible);

		// ���ý������ķ�Χ
		void setRange(int min, int max);
		// ���ý����������ֵ
		void setMaximum(int max);
		// ���ý���������Сֵ
		void setMinimum(int min);

		// ��ȡ�����������ֵ
		int getMaximum();
		// ��ȡ����������Сֵ
		int getMinimum();

		// ���ý�������ɫ
		void setProgressBarColor(const QColor& color);

	private:
		QProgressBar* m_progressBar = nullptr;
		QLabel* m_firstLabel = nullptr;
		QLabel* m_endLabel = nullptr;
	};
}

#endif // CLABELPROLABEL_H

