#pragma once
#ifndef CPLOTCURVE_H
#define CPLOTCURVE_H

#include <QObject>
#include "QCusWidgetLib_global.h"

#define LINEDISTANCE 5 //鼠标线条的长度
namespace QCUSWIDGETLIB
{
	struct QCUSWIDGETLIB_EXPORT gateLine
	{
		QPointF startPoint = QPointF(10, 10); // 起点
		QPointF endPoint = QPointF(40, 10); // 终点
		QColor color = QColor(0, 255, 0);
		bool isSelected = false; // 是否被选中
		QCPItemLine* line = nullptr; // 线条、
		// 左侧垂直线条、右侧垂直线条、垂直线条中心点
		QCPItemLine* leftLine = nullptr;
		QCPItemLine* rightLine = nullptr;

		bool drawing = false;
		bool draggingStart = false;
		bool draggingEnd = false;
		bool draggingCenter = false;

		bool isHorizontal = true; // 是否固定
		bool isVertical = false; // 是否固定

		void setVisible(bool visible)
		{
			if (line && leftLine && rightLine)
			{
				line->setVisible(visible);
				leftLine->setVisible(visible);
				rightLine->setVisible(visible);
			}
		}
		void updateLine()
		{// 更新线条
			if (line && leftLine && rightLine)
			{
				line->start->setCoords(startPoint);
				line->end->setCoords(endPoint);

				// 更新左侧垂直线条 为line的左侧垂直线条
				if (isHorizontal)
				{
					leftLine->start->setCoords(startPoint.x(), startPoint.y() - LINEDISTANCE);
					leftLine->end->setCoords(startPoint.x(), startPoint.y() + LINEDISTANCE);

					rightLine->start->setCoords(endPoint.x(), endPoint.y() - LINEDISTANCE);
					rightLine->end->setCoords(endPoint.x(), endPoint.y() + LINEDISTANCE);
				}
				else if (isVertical)
				{
					leftLine->start->setCoords(startPoint.x() - LINEDISTANCE, startPoint.y());
					leftLine->end->setCoords(startPoint.x() + LINEDISTANCE, startPoint.y());

					rightLine->start->setCoords(endPoint.x() - LINEDISTANCE, endPoint.y());
					rightLine->end->setCoords(endPoint.x() + LINEDISTANCE, endPoint.y());
				}
				else
				{
					// 随机线段 暂时不用
				}
			}
		}

	};
	class  QCUSWIDGETLIB_EXPORT CPlotCurve : public QWidget
	{
		Q_OBJECT

	public:
		CPlotCurve(QWidget* parent = nullptr);
		virtual ~CPlotCurve();

		// 设置X轴名称
		void setxAxisName(QString name);
		// 设置Y轴名称
		void setyAxisName(QString name);
		// 设置X轴范围
		void setxAxisRange(double lower, double upper);
		// 设置Y轴范围
		void setyAxisRange(double lower, double upper);
		// 设置图形名称
		void setGraphName(QString name);
		// 设置是否选择图例
		void setSelectLegend(bool enabled);
		// 设置图例字体
		void setLegendFont(QFont font);

		// 设置曲线数据
		void setData(QVector<double> x, QVector<double> y);
		void addPointData(double x, double y);

		QCustomPlot* getPlot() const;

	public slots:
		void setTraceStyle(bool isOpen = true);
		void myMouseMoveEvent(QMouseEvent* event);//鼠标事件
		void myMousePressEvent(QMouseEvent* event);// 鼠标按下事件
		void myMouseReleaseEvent(QMouseEvent* event); // 鼠标释放事件
		void rescaleAxes();//自动调整
		void clearCurve();//清除曲线
		void clearAllCurves();//清除所有曲线
		void contextMenuRequestForce(QPoint pos);
		// 绘制闸门线
		void drawGateLine(double x1, double y1, double x2, double y2, QColor color);

		void setPlotMoveStatus(bool status); // 设置图形是否可以移动

		void TraceMouseMove(QMouseEvent* event); // 鼠标移动事件
		void GateLineMouseMove(QMouseEvent* event); // 闸门线鼠标移动事件

	signals:
		void signalGateLineStartChanged(double x, double y);
		void signalGateLineEndChanged(double x, double y);
	private:
		/*************曲线数据*************/
		int curIndex;//当前曲线号 = 0, = 1, = -1时未选中曲线
		//0号曲线(目标曲线)
		QVector<double> x0;//存储x坐标的向量
		QVector<double> y0;//存储y坐标的向量
		QList<QList<QVariant>> x_y0;
		bool m_tracerEnable = true; // 游标key是否启用

		gateLine m_gateLine; // 闸门线
	private:
		QCustomPlot* m_plot = nullptr;

		/*************游标*************/
		QCPItemTracer* tracer0 = nullptr; // 0号曲线游标
		QCPItemText* tracer0Label = nullptr; // 0号曲线X游标标签
		void setVisibleTracer(bool trueorfalse);//游标可见/不可见 true/false
		/*********曲线X轴范围**********/
		QCPRange QrangeX0;//0号曲线X轴范围
		double  QrangeX0_lower;
		double  QrangeX0_upper;
		bool foundRange;
	};

	class QCUSWIDGETLIB_EXPORT CPlotColorMap : public QWidget
	{
		Q_OBJECT

	public:
		CPlotColorMap(QWidget* parent = nullptr);
		virtual ~CPlotColorMap();

		void setXRange(double lower, double upper);
		void setYRange(double lower, double upper);
		void setColorStops(QMap<double, QColor> stops);

		void setLineHVisible(bool visible);
		void setLineVVisible(bool visible);

		// 单点颜色设置
		void setColorMapValues(double x, double y, double color);

		QCPColorMap* getColorMap() const;
		QCustomPlot* getPlot() const;
		QCPColorScale* getColorScale() const;
		QCPColorGradient getColorGradient() const;
		QCPItemStraightLine* getLineH() const;
		QCPItemStraightLine* getLineV() const;

	public slots:
		void slotLineMousePress(QMouseEvent* event);
		void slotLineMouseMove(QMouseEvent* event);
		void slotLineMouseRelease(QMouseEvent* event);

		void setHlinePostion(double y);
		void setVlinePostion(double x);

	signals:
		void signalHLinePositionChanged(double y);
		void signalVLinePositionChanged(double x);

	private:
		void initIntegrate();
	private:
		QCustomPlot* m_plot = nullptr;
		QCPColorMap* m_colorMap = nullptr;
		QCPColorScale* m_colorScale = nullptr;
		QCPColorGradient  m_colorGradient;
		QCPItemStraightLine* m_lineH = nullptr;
		QCPItemStraightLine* m_lineV = nullptr;

		bool m_lineHMoveable = false;
		bool m_lineVMoveable = false;
	};
}
#endif // CPLOTCURVE_H
