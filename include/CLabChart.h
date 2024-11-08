#pragma once
#ifndef CLABCHART_H
#define CLABCHART_H

#include <QWidget>
#include <QChart>

#include "QCusWidgetLib_global.h"
namespace QCUSWIDGETLIB
{
	class QCUSWIDGETLIB_EXPORT CLabChart : public QWidget
	{
		Q_OBJECT

	public:
		CLabChart(QWidget* parent = nullptr);
		~CLabChart();

		// ���� QChart�ı���
		void setChartTitle(const QString& title);

		// ���� QChart��X���ǩ
		void setChartXAxisLabel(const QString& labels);
		void setChartXAxisLabelAngle(double angle);
		void setChartXAxisRange(double min, double max);

		// ���� QChart��Y���ǩ
		void setChartYAxisLabel(const QString& labels);
		void setChartYAxisLabelAngle(double angle);
		void setChartYAxisRange(double min, double max);

		// ���� QChart valeus
		void addLineSeries(int index);
		void addLineSeries(int index, const QString& name);
		void setLineSeriesName(int index, const QString& name);
		void setLineSeriesValue(int index, int x, double y);
		void setLineSeriesValues(int index, const QVector<double>& XValues, const QVector<double>& YValues);
		void updateSeries(int index, QVector<QPointF> points);
	private:
		QChart * m_chart = nullptr;	
		QValueAxis * m_xAxis = nullptr;
		QValueAxis * m_yAxis = nullptr;
		QMap<int, QLineSeries*> m_lineSeriesMap = QMap<int, QLineSeries*>();
	};

}
#endif // !
