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
		// 设置进度条的第一个标签文本
		void setFirstLabel(const QString& text);
		// 设置进度条的最后一个标签文本
		void setEndLabel(const QString& text);
		// 设置进度条的当前进度
		void setProgressValue(int value);
		int getProgressValue();

		// 设置第一个标签的可见性
		void setFirstLabelVisible(bool visible);
		// 设置最后一个标签的可见性
		void setEndLabelVisible(bool visible);
		// 设置进度条的可见性
		void setProgressBarVisible(bool visible);

		// 设置进度条的范围
		void setRange(int min, int max);
		// 设置进度条的最大值
		void setMaximum(int max);
		// 设置进度条的最小值
		void setMinimum(int min);

		// 获取进度条的最大值
		int getMaximum();
		// 获取进度条的最小值
		int getMinimum();

		// 设置进度条颜色
		void setProgressBarColor(const QColor& color);

	private:
		QProgressBar* m_progressBar = nullptr;
		QLabel* m_firstLabel = nullptr;
		QLabel* m_endLabel = nullptr;
	};
}

#endif // CLABELPROLABEL_H

