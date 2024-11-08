#include "../include/CLabChart.h"

namespace QCUSWIDGETLIB
{
	CLabChart::CLabChart(QWidget* parent)
		: QWidget(parent)
	{
		m_chart = new QChart();
		QChartView *chartView = new QChartView(m_chart);
		chartView->setRenderHint(QPainter::Antialiasing);
		chartView->setRubberBandSelectionMode(Qt::IntersectsItemShape);

		m_xAxis = new QValueAxis();
		m_xAxis->setRange(0, 1000);
		m_xAxis->setTitleText("µçÑ¹KV");
		m_xAxis->setLabelsAngle(90);
		m_xAxis->setGridLineVisible(false);
		m_chart->addAxis(m_xAxis, Qt::AlignBottom);

		m_yAxis = new QValueAxis();
		m_yAxis->setRange(0, 1000);
		m_yAxis->setTitleText("µçÁ÷A");
		m_yAxis->setLabelsAngle(0);
		m_yAxis->setGridLineVisible(false);
		m_chart->addAxis(m_yAxis, Qt::AlignLeft);

		QHBoxLayout* layout = new QHBoxLayout();
		layout->addWidget(chartView);
		setLayout(layout);

	}
	CLabChart::~CLabChart()
	{
		if (m_chart)
		{
			delete m_chart;
			m_chart = nullptr;
		}
	}
	void CLabChart::setChartTitle(const QString& title)
	{
		m_chart->setTitle(title);
	}
	void CLabChart::setChartXAxisLabel(const QString& labels)
	{
		m_xAxis->setTitleText(labels);
	}
	void CLabChart::setChartXAxisLabelAngle(double angle)
	{
		m_xAxis->setLabelsAngle(angle);
	}
	void CLabChart::setChartYAxisLabel(const QString& labels)
	{
		m_yAxis->setTitleText(labels);
	}
	void CLabChart::setChartYAxisLabelAngle(double angle)
	{
		m_yAxis->setLabelsAngle(angle);
	}
	void CLabChart::setChartXAxisRange(double min, double max)
	{
		m_xAxis->setRange(min, max);
	}
	void CLabChart::setChartYAxisRange(double min, double max)
	{
		m_yAxis->setRange(min, max);
	}
	void CLabChart::addLineSeries(int index)
	{
		QLineSeries *series = new QLineSeries();
		m_chart->addSeries(series);
		m_chart->setAxisX(m_xAxis, series);
		m_chart->setAxisY(m_yAxis, series);
		m_lineSeriesMap.insert(index, series);

	}
	void CLabChart::addLineSeries(int index, const QString& name)
	{
		QLineSeries *series = new QLineSeries();
		series->setName(name);
		m_chart->addSeries(series);
		m_chart->setAxisX(m_xAxis, series);
		m_chart->setAxisY(m_yAxis, series);
		m_lineSeriesMap.insert(index, series);
	}
	void CLabChart::setLineSeriesName(int index, const QString& name)
	{
		if (m_lineSeriesMap.contains(index))
		{
			m_lineSeriesMap[index]->setName(name);
		}
	}
	void CLabChart::setLineSeriesValue(int index, int x, double y)
	{
		if (m_lineSeriesMap.contains(index))
		{
			m_lineSeriesMap[index]->append(x, y);
		}
	}
	void CLabChart::setLineSeriesValues(int index, const QVector<double>& XValues, const QVector<double>& YValues)
	{
		if (m_lineSeriesMap.contains(index))
		{
			m_lineSeriesMap[index]->clear();
			for (int i = 0; i < XValues.size(); i++)
			{
				m_lineSeriesMap[index]->append(XValues[i], YValues[i]);
			}
		}
	}
	void CLabChart::updateSeries(int index, QVector<QPointF> points)
	{
		if (m_lineSeriesMap.contains(index))
		{
			m_lineSeriesMap[index]->replace(points);
		}
	}
}