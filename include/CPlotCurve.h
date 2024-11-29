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

		QPointF getGateLineStart() const;
		QPointF getGateLineEnd() const;

		void updatePoint();
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
		void updatePoint();
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

	// 直方图控件
	class QCUSWIDGETLIB_EXPORT HistogramWidget : public QWidget {
		Q_OBJECT
			// 可移动的小球
			struct MoveBoll {
			QPointF pointFirst = QPointF(0, 100);
			QPointF pointSecond = QPointF(20, 100);

			bool isFirstMoving = false;
			bool isSecondMoving = false;

			QCPItemLine* firstLine = nullptr;
			QCPItemLine* secondLine = nullptr;
			QCPItemLine* thirdLine = nullptr;
		};

	public:
		HistogramWidget(QWidget* parent = nullptr);
		~HistogramWidget();
		//
		// 用于放大
		void plotScaleMax(double zoomFactor);

		// 用于缩小
		void plotScaleMin(double zoomFactor);

		// 设置直方图数据
		void setHistogramData(QVector<double> xData, QVector<double> yData);

		// 鼠标事件中改变X轴范围
		void xAxisRangeChangedMouse(QMouseEvent* event);

		// 移动控件按下事件
		void MoveBollPress(QMouseEvent* event);

		// 移动控件释放事件
		void MoveBollRelease(QMouseEvent* event);

		// 移动控件移动事件
		void MoveBollMove(QMouseEvent* event);

		// 鼠标滚轮缩放事件
		void mouseWheelZoom(QWheelEvent* event);

		// X轴按下事件
		void xAxisPressed(QMouseEvent* event);

		// 初始化移动控件
		void initMoveBoll();

		// 设置移动控件的位置
		void setMoveBoll(QPointF pointFirst, QPointF pointSecond);

		// 跟踪鼠标移动事件
		void traceMouseMove(QMouseEvent* event);

		// 设置图像跟踪器的X值
		void setImageTracer(double xValue);

		// 设置图像跟踪器的可见性
		void setImageTracerVisible(bool visible);

		// 设置第一个小球点
		void setBollFirstPoint(QPointF point);

		// 设置第二个小球点
		void setBollSecondPoint(QPointF point);

		// 设置最大X范围
		void setMaxRangX(double maxRangX);
		// 设置最小X范围
		void setMinRangX(double minRangX);

		// 设置最大Y范围
		void setMaxRangY(double maxRangY);
		// 设置最小Y范围
		void setMinRangY(double minRangY);

		//
		QCustomPlot* getPlot() const;

	private:
		QCustomPlot* m_plot = nullptr;
		QCPBars* m_bars;
		MoveBoll m_moveBoll;
		QPointF m_mousePressPosition = QPointF(0, 0);

		QCPItemLine* m_tracer = nullptr;
		QCPItemLine* m_imageTracer = nullptr;

		QCPRange m_RangeX = QCPRange(0, 65536);
		QCPRange m_RangeY = QCPRange(0, 65536);

		bool m_dragging = false;
	};
}
#endif // CPLOTCURVE_H
