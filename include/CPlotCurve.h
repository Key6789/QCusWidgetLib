#pragma once
#ifndef CPLOTCURVE_H
#define CPLOTCURVE_H

#include <QObject>
#include "QCusWidgetLib_global.h"

#define LINEDISTANCE 5 //��������ĳ���
namespace QCUSWIDGETLIB
{
	struct QCUSWIDGETLIB_EXPORT gateLine
	{
		QPointF startPoint = QPointF(10, 10); // ���
		QPointF endPoint = QPointF(40, 10); // �յ�
		QColor color = QColor(0, 255, 0);
		bool isSelected = false; // �Ƿ�ѡ��
		QCPItemLine* line = nullptr; // ������
		// ��ഹֱ�������Ҳഹֱ��������ֱ�������ĵ�
		QCPItemLine* leftLine = nullptr;
		QCPItemLine* rightLine = nullptr;

		bool drawing = false;
		bool draggingStart = false;
		bool draggingEnd = false;
		bool draggingCenter = false;

		bool isHorizontal = true; // �Ƿ�̶�
		bool isVertical = false; // �Ƿ�̶�

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
		{// ��������
			if (line && leftLine && rightLine)
			{
				line->start->setCoords(startPoint);
				line->end->setCoords(endPoint);

				// ������ഹֱ���� Ϊline����ഹֱ����
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
					// ����߶� ��ʱ����
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

		// ����X������
		void setxAxisName(QString name);
		// ����Y������
		void setyAxisName(QString name);
		// ����X�᷶Χ
		void setxAxisRange(double lower, double upper);
		// ����Y�᷶Χ
		void setyAxisRange(double lower, double upper);
		// ����ͼ������
		void setGraphName(QString name);
		// �����Ƿ�ѡ��ͼ��
		void setSelectLegend(bool enabled);
		// ����ͼ������
		void setLegendFont(QFont font);

		// ������������
		void setData(QVector<double> x, QVector<double> y);
		void addPointData(double x, double y);
		

		QCustomPlot* getPlot() const;

	public slots:
		void setTraceStyle(bool isOpen = true);
		void myMouseMoveEvent(QMouseEvent* event);//����¼�
		void myMousePressEvent(QMouseEvent* event);// ��갴���¼�
		void myMouseReleaseEvent(QMouseEvent* event); // ����ͷ��¼�
		void rescaleAxes();//�Զ�����
		void clearCurve();//�������
		void clearAllCurves();//�����������
		void contextMenuRequestForce(QPoint pos);
		// ����բ����
		void drawGateLine(double x1, double y1, double x2, double y2, QColor color);

		void setPlotMoveStatus(bool status); // ����ͼ���Ƿ�����ƶ�

		void TraceMouseMove(QMouseEvent* event); // ����ƶ��¼�
		void GateLineMouseMove(QMouseEvent* event); // բ��������ƶ��¼�

		QPointF getGateLineStart() const;
		QPointF getGateLineEnd() const;

		void updatePoint();
	signals:
		void signalGateLineStartChanged(double x, double y);
		void signalGateLineEndChanged(double x, double y);
	private:
		/*************��������*************/
		int curIndex;//��ǰ���ߺ� = 0, = 1, = -1ʱδѡ������
		//0������(Ŀ������)
		QVector<double> x0;//�洢x���������
		QVector<double> y0;//�洢y���������
		QList<QList<QVariant>> x_y0;
		bool m_tracerEnable = true; // �α�key�Ƿ�����

		gateLine m_gateLine; // բ����
	private:
		QCustomPlot* m_plot = nullptr;

		/*************�α�*************/
		QCPItemTracer* tracer0 = nullptr; // 0�������α�
		QCPItemText* tracer0Label = nullptr; // 0������X�α��ǩ
		void setVisibleTracer(bool trueorfalse);//�α�ɼ�/���ɼ� true/false
		/*********����X�᷶Χ**********/
		QCPRange QrangeX0;//0������X�᷶Χ
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

		// ������ɫ����
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

	// ֱ��ͼ�ؼ�
	class QCUSWIDGETLIB_EXPORT HistogramWidget : public QWidget {
		Q_OBJECT
			// ���ƶ���С��
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
		// ���ڷŴ�
		void plotScaleMax(double zoomFactor);

		// ������С
		void plotScaleMin(double zoomFactor);

		// ����ֱ��ͼ����
		void setHistogramData(QVector<double> xData, QVector<double> yData);

		// ����¼��иı�X�᷶Χ
		void xAxisRangeChangedMouse(QMouseEvent* event);

		// �ƶ��ؼ������¼�
		void MoveBollPress(QMouseEvent* event);

		// �ƶ��ؼ��ͷ��¼�
		void MoveBollRelease(QMouseEvent* event);

		// �ƶ��ؼ��ƶ��¼�
		void MoveBollMove(QMouseEvent* event);

		// �����������¼�
		void mouseWheelZoom(QWheelEvent* event);

		// X�ᰴ���¼�
		void xAxisPressed(QMouseEvent* event);

		// ��ʼ���ƶ��ؼ�
		void initMoveBoll();

		// �����ƶ��ؼ���λ��
		void setMoveBoll(QPointF pointFirst, QPointF pointSecond);

		// ��������ƶ��¼�
		void traceMouseMove(QMouseEvent* event);

		// ����ͼ���������Xֵ
		void setImageTracer(double xValue);

		// ����ͼ��������Ŀɼ���
		void setImageTracerVisible(bool visible);

		// ���õ�һ��С���
		void setBollFirstPoint(QPointF point);

		// ���õڶ���С���
		void setBollSecondPoint(QPointF point);

		// �������X��Χ
		void setMaxRangX(double maxRangX);
		// ������СX��Χ
		void setMinRangX(double minRangX);

		// �������Y��Χ
		void setMaxRangY(double maxRangY);
		// ������СY��Χ
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
