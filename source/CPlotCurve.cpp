#include "../include/CPlotCurve.h"
namespace QCUSWIDGETLIB
{
	CPlotCurve::CPlotCurve(QWidget* parent)
	{
		// 初始化 QCustomPlot
		m_plot = new QCustomPlot(parent);

		/*************绘图模块***************/
		//设置坐标轴字体
		QFont YHfont("Microsoft YaHei", 10, QFont::Normal);
		m_plot->setFont(YHfont);
		m_plot->xAxis->setLabelFont(YHfont);
		m_plot->xAxis->setTickLabelFont(YHfont);
		m_plot->yAxis->setLabelFont(YHfont);
		m_plot->yAxis->setTickLabelFont(YHfont);
		//设定右上角图例标注的字体
		m_plot->legend->setFont(YHfont);
		//设定右上角图例标注可见
		m_plot->legend->setVisible(true);

		//添加图形
		m_plot->addGraph();
		//曲线全部可见
		m_plot->graph(0)->rescaleAxes(true);
		//设置画笔
		QPen pen0(Qt::blue, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

		m_plot->graph(0)->setPen(pen0);
		//设置线型
		m_plot->graph(0)->setLineStyle(QCPGraph::lsLine);
		//设置线上点的风格
		m_plot->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
		//右键菜单自定义
		m_plot->setContextMenuPolicy(Qt::CustomContextMenu);
		/**********鼠标操作图像模块************/
		m_plot->selectionRect()->setPen(QPen(Qt::black, 1, Qt::DashLine));//设置选框的样式：虚线
		m_plot->selectionRect()->setBrush(QBrush(QColor(0, 0, 100, 50)));//设置选框的样式：半透明浅蓝
		m_plot->setInteraction(QCP::iRangeDrag, true); //鼠标单击拖动 QCPAxisRect::mousePressEvent() 左键拖动
		m_plot->setInteraction(QCP::iRangeZoom, true); //滚轮滑动缩放
		m_plot->setInteraction(QCP::iSelectAxes, true);
		m_plot->setInteraction(QCP::iSelectLegend, true); //图例可选
		m_plot->selectionRect()->setPen(QPen(Qt::black, 1, Qt::DashLine));
		m_plot->selectionRect()->setBrush(QBrush(QColor(0, 0, 100, 50)));
		m_plot->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);
		setTraceStyle(true);
		drawGateLine(10, 10, 40, 10, QColor(0, 255, 0));

		connect(m_plot, &QCustomPlot::customContextMenuRequested, this, &CPlotCurve::contextMenuRequestForce);
		connect(m_plot, &QCustomPlot::mouseMove, this, &CPlotCurve::myMouseMoveEvent);
		connect(m_plot, &QCustomPlot::mousePress, this, &CPlotCurve::myMousePressEvent);
		connect(m_plot, &QCustomPlot::mouseRelease, this, &CPlotCurve::myMouseReleaseEvent);
		
		
		QVBoxLayout* layout = new QVBoxLayout(parent);
		layout->addWidget(m_plot);
		setLayout(layout);
	}

	CPlotCurve::~CPlotCurve()
	{
		if (m_plot)
		{
			delete m_plot;
			m_plot = nullptr;
		}
	}
	//X轴名称
	void CPlotCurve::setxAxisName(QString name)
	{
		m_plot->xAxis->setLabel(name);
		m_plot->replot();
	}
	//Y轴名称
	void CPlotCurve::setyAxisName(QString name)
	{
		m_plot->yAxis->setLabel(name);
		m_plot->replot();
	}
	//X轴范围
	void CPlotCurve::setxAxisRange(double lower, double upper)
	{
		m_plot->xAxis->setRange(lower, upper);
		m_plot->replot();
	}
	//Y轴范围
	void CPlotCurve::setyAxisRange(double lower, double upper)
	{
		m_plot->yAxis->setRange(lower, upper);
		m_plot->replot();
	}
	//曲线图例名称
	void CPlotCurve::setGraphName(QString name)
	{
		//设置右上角图形标注名称
		m_plot->graph(0)->setName(name);
		m_plot->replot();
	}
	void CPlotCurve::setSelectLegend(bool enabled)
	{
		if (enabled)
		{
			m_plot->setInteraction(QCP::iSelectLegend, true); //图例可选
		}
		else
		{
			m_plot->setInteraction(QCP::iSelectLegend, false); //图例可选
		}
		m_plot->replot();
	}
	void CPlotCurve::setLegendFont(QFont font)
	{
		m_plot->legend->setFont(font);
		m_plot->replot();
	}
	void CPlotCurve::setData(QVector<double> x, QVector<double> y)
	{
		// 清除之前的数据
		// 设置新的数据
		// 获取 X 轴范围
		double x_min = *std::min_element(x.begin(), x.end());
		double x_max = *std::max_element(x.begin(), x.end());
		// 设置 X 轴范围
		m_plot->xAxis->setRange(x_min, x_max);
		// 设置 Y 轴范围
		double y_min = *std::min_element(y.begin(), y.end());
		double y_max = *std::max_element(y.begin(), y.end());
		m_plot->yAxis->setRange(y_min, y_max);
		// 设置曲线数据
		m_plot->graph(0)->setData(x, y);
		m_plot->graph(0)->rescaleAxes(true);
		m_plot->replot();
	}
	void CPlotCurve::addPointData(double x, double y)
	{
		m_plot->graph(0)->addData(x, y);
		// 重新设置X轴范围
		if (x > m_plot->xAxis->range().upper)
		{
			m_plot->xAxis->setRange(m_plot->xAxis->range().lower, x);
		}
		if (y > m_plot->yAxis->range().upper)
		{
			m_plot->yAxis->setRange(m_plot->yAxis->range().lower, y);
		}
		m_plot->replot();
	}
	QCustomPlot* CPlotCurve::getPlot() const
	{
		return m_plot;
	}

	void CPlotCurve::setTraceStyle(bool arg1)
	{
		qDebug() << "act_tracer is on!";
		if (arg1)
		{
			tracer0 = new QCPItemTracer(m_plot);
			tracer0->setStyle(QCPItemTracer::tsCrosshair);//游标样式：十字星、圆圈、方框
			tracer0->setPen(QPen(Qt::green));//设置tracer的颜色绿色
			tracer0->setPen(QPen(Qt::DashLine));//虚线游标
			tracer0->setBrush(QBrush(Qt::red));
			tracer0->setSize(10);
			tracer0->setInterpolating(true);//false禁用插值

			tracer0Label = new QCPItemText(m_plot);
			tracer0Label->setClipToAxisRect(false);
			tracer0Label->setLayer("overlay");
			tracer0Label->setPen(QPen(Qt::green));
			tracer0Label->setFont(QFont("Microsoft YaHei", 10));
			tracer0Label->setPadding(QMargins(2, 2, 2, 2));
			tracer0Label->setPositionAlignment(Qt::AlignLeft | Qt::AlignTop);
			//下面这个语句很重要，它将游标说明锚固在tracer位置处，实现自动跟随
			tracer0Label->position->setType(QCPItemPosition::ptAxisRectRatio);//位置类型（当前轴范围的比例为单位/实际坐标为单位）
			tracer0Label->position->setParentAnchor(tracer0->position);
		}
		else
		{
			m_tracerEnable = false;
			setVisibleTracer(false);
		}


	}
	void CPlotCurve::myMouseMoveEvent(QMouseEvent* event)//鼠标移动事件
	{
		// 鼠标移动事件处理
		// 游标跟随鼠标移动
		TraceMouseMove(event);
		// 闸门线拖动事件处理
		GateLineMouseMove(event);
	}
	void CPlotCurve::TraceMouseMove(QMouseEvent* event)
	{
		if (m_tracerEnable)//游标使能判断
		{
			double x = m_plot->xAxis->pixelToCoord(event->pos().x());//鼠标点的像素坐标转plot坐标
			foundRange = true;
			QrangeX0 = m_plot->graph(0)->getKeyRange(foundRange, QCP::sdBoth);//获取0号曲线X轴坐标范围
			QrangeX0_lower = QrangeX0.lower;
			QrangeX0_upper = QrangeX0.upper;

			//如果鼠标移动超出0号曲线X轴范围，则0号曲线隐藏游标
			if (x < QrangeX0_upper && x > QrangeX0_lower)
			{
				tracer0->setGraph(m_plot->graph(0));//设置游标吸附在traceGraph这条曲线上
				tracer0->setGraphKey(x);//将游标横坐标（key）设置成刚获得的横坐标数据x （这就是游标随动的关键代码）
				tracer0->updatePosition(); //使得刚设置游标的横纵坐标位置生效
				double traceX0 = tracer0->position->key();
				double traceY0 = tracer0->position->value();

				tracer0Label->setText(QString::number(traceX0, 'f', 3));//游标文本框，指示游标的X值
				tracer0Label->setText(QString("x = %1\ny = %2").arg(QString::number(traceX0, 'f', 3)).arg(QString::number(traceY0, 'f', 3)));
				tracer0->setVisible(true);
				tracer0Label->setVisible(true);
			}
			else
			{
				tracer0->setVisible(false);
				tracer0Label->setVisible(false);
			}
			m_plot->replot(QCustomPlot::rpQueuedReplot); //刷新图标，不能省略
		}
	}
	void CPlotCurve::GateLineMouseMove(QMouseEvent* event)
	{
		if (m_gateLine.draggingStart)
		{
			double x = m_plot->xAxis->pixelToCoord(event->pos().x());
			double y = m_plot->yAxis->pixelToCoord(event->pos().y());
			m_gateLine.startPoint = QPointF(x, y);
			m_gateLine.line->start->setCoords(m_gateLine.startPoint.x(), m_gateLine.startPoint.y());
			m_gateLine.updateLine();
			update();

			emit signalGateLineStartChanged(m_gateLine.startPoint.x(), m_gateLine.startPoint.y());
		}
		if (m_gateLine.draggingEnd)
		{
			double x = m_plot->xAxis->pixelToCoord(event->pos().x());
			double y = m_plot->yAxis->pixelToCoord(event->pos().y());
			m_gateLine.endPoint = QPointF(x, y);
			m_gateLine.line->end->setCoords(m_gateLine.endPoint.x(), m_gateLine.endPoint.y());
			m_gateLine.updateLine();

			emit signalGateLineEndChanged(m_gateLine.endPoint.x(), m_gateLine.endPoint.y());
			
			update();
		}
		if (m_gateLine.draggingCenter)
		{
			double x = m_plot->xAxis->pixelToCoord(event->pos().x());
			double y = m_plot->yAxis->pixelToCoord(event->pos().y());
			// 计算中心点
			QPointF center = (m_gateLine.startPoint + m_gateLine.endPoint) / 2;
			// 计算偏移量
			QPointF offset = QPointF(x - center.x(), y - center.y());
			// 计算新的起点和终点
			m_gateLine.startPoint = m_gateLine.startPoint + offset;
			m_gateLine.endPoint = m_gateLine.endPoint + offset;
			m_gateLine.line->start->setCoords(m_gateLine.startPoint.x(), m_gateLine.startPoint.y());
			m_gateLine.line->end->setCoords(m_gateLine.endPoint.x(), m_gateLine.endPoint.y());
			m_gateLine.updateLine();

			emit signalGateLineStartChanged(m_gateLine.startPoint.x(), m_gateLine.startPoint.y());
			emit signalGateLineEndChanged(m_gateLine.endPoint.x(), m_gateLine.endPoint.y());
			
			update();
		}
		m_plot->replot(); //刷新图标，不能省略
	}
	void CPlotCurve::myMousePressEvent(QMouseEvent* event)
	{
		if (event->button() == Qt::LeftButton)
		{
			// 获取 
			if (m_gateLine.line->selectTest(event->pos(), false) < LINEDISTANCE)
			{
				// 保证 Move拖动事件 将坐标切换为 
				setPlotMoveStatus(false);
				double x = m_plot->xAxis->coordToPixel(m_gateLine.startPoint.x());
				double y = m_plot->yAxis->coordToPixel(m_gateLine.startPoint.y());

				double x1 = m_plot->xAxis->coordToPixel(m_gateLine.endPoint.x());
				double y1 = m_plot->yAxis->coordToPixel(m_gateLine.endPoint.y());
				if (QLineF(QPointF(x,y), event->pos()).length() < LINEDISTANCE)
				{
					m_gateLine.draggingStart = true;
					// 修改鼠标样式向右的箭头
					setCursor(Qt::SizeHorCursor);
				}
				else if (QLineF(QPointF(x1, y1), event->pos()).length() < LINEDISTANCE)
				{
					m_gateLine.draggingEnd = true;
					// 修改鼠标样式向左的箭头
					setCursor(Qt::SizeHorCursor);
				}
				else
				{
					m_gateLine.draggingCenter = true;
					// 修改为手型
					setCursor(Qt::ClosedHandCursor);
				}
			}
			update();
		}
	}

	void CPlotCurve::myMouseReleaseEvent(QMouseEvent* event)
	{
		m_gateLine.draggingStart = false;
		m_gateLine.draggingEnd = false;
		m_gateLine.drawing = false;
		m_gateLine.draggingCenter = false;
		setCursor(Qt::ArrowCursor);
		setPlotMoveStatus(true);
	}

	void CPlotCurve::rescaleAxes()//曲线全部显示
	{
		//给第一个graph设置rescaleAxes()，后续所有graph都设置rescaleAxes(true)即可实现显示所有曲线。
		//rescaleAxes(true)时如果plot的X或Y轴本来能容纳下本graph的X或Y数据点，
		//那么plot的X或Y轴的可视范围就无需调整，只有plot容纳不下本graph时，才扩展plot两个轴的显示范围。
		//见博客https://www.csdn.net/gather_26/MtTaYg2sMzgxNDgtYmxvZwO0O0OO0O0O.html
		m_plot->graph(0)->rescaleAxes(true);
		m_plot->replot();
	}

	void CPlotCurve::clearCurve()
	{
		switch (this->curIndex)
		{
		case 0:
			this->x0.clear();
			this->y0.clear();
			this->x_y0.clear();
			m_plot->graph(0)->setData(this->x0, this->y0);
			break;
		case -1:
			qDebug() << "未选中曲线！";
			break;
		}
		m_plot->replot(QCustomPlot::rpQueuedReplot);
	}

	void CPlotCurve::clearAllCurves()
	{
		this->x0.clear();
		this->y0.clear();
		this->x_y0.clear();
		m_plot->graph(0)->setData(this->x0, this->y0);
		m_plot->replot(QCustomPlot::rpQueuedReplot);
	}

	void CPlotCurve::contextMenuRequestForce(QPoint pos)
	{
		QMenu* menu = new QMenu(this);
		menu->setStyleSheet("font:11pt;font-family:Microsoft YaHei");
		menu->setAttribute(Qt::WA_DeleteOnClose);
		menu->popup(m_plot->mapToGlobal(pos));
		QAction* action = new QAction(__CSTRING_UTF8("调整范围"), menu);
		connect(action, &QAction::triggered, this, &CPlotCurve::rescaleAxes);
		QAction* actionMoveEnabel = new QAction(__CSTRING_UTF8("游标锁定"), menu);
		connect(actionMoveEnabel, &QAction::triggered, [=](
			) {m_tracerEnable = false; });
		QAction* actionMoveDisabel = new QAction(__CSTRING_UTF8("游标解锁"), menu);
		connect(actionMoveDisabel, &QAction::triggered, [=](
			) {m_tracerEnable = true; });
		QAction* actionGateEnabel = new QAction(__CSTRING_UTF8("闸门显示"), menu);
		connect(actionGateEnabel, &QAction::triggered, [=](
			) {
				m_gateLine.line->setVisible(true);
			});
		QAction* actionGateDisabel = new QAction(__CSTRING_UTF8("闸门删除"), menu);
		connect(actionGateDisabel, &QAction::triggered, [=](
			) {
				m_gateLine.line->setVisible(false);
			});

		menu->addAction(action);
		menu->addAction(actionMoveEnabel);
		menu->addAction(actionMoveDisabel);
		menu->addAction(actionGateEnabel);
		menu->addAction(actionGateDisabel);
		//menu->addAction(__CSTRING_UTF8("清除选中曲线"), m_plot, &CPlotCurve::clearCurve);

	}

	void CPlotCurve::drawGateLine(double x1, double y1, double x2, double y2, QColor color)
	{
		m_gateLine.line = new QCPItemLine(m_plot);
		m_gateLine.line->setPen(QPen(color));
		m_gateLine.startPoint = QPointF(x1, y1);
		m_gateLine.endPoint = QPointF(x2, y2);
		
		// 在左右两侧各画一条垂直线
		m_gateLine.leftLine = new QCPItemLine(m_plot);
		m_gateLine.leftLine->setPen(QPen(color));

		m_gateLine.rightLine = new QCPItemLine(m_plot);
		m_gateLine.rightLine->setPen(QPen(color));
		// 获取当前坐标
		m_gateLine.line->start->setCoords(m_gateLine.startPoint.x(), m_gateLine.startPoint.y());
		m_gateLine.line->end->setCoords(m_gateLine.endPoint.x(), m_gateLine.endPoint.y());
		m_gateLine.setVisible(true);
		m_gateLine.updateLine();


		m_plot->replot();

	}

	void CPlotCurve::setPlotMoveStatus(bool status)
	{
		if (status)
		{
			m_plot->setInteraction(QCP::iRangeDrag, true);
			m_plot->setInteraction(QCP::iRangeZoom, true);
			m_plot->setInteraction(QCP::iSelectAxes, true);
			m_plot->setInteraction(QCP::iSelectLegend, true); //图例可选
			m_plot->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);
		}
		else
		{
			m_plot->setInteraction(QCP::iNone, true);
			m_plot->setSelectionRectMode(QCP::SelectionRectMode::srmNone);
			// 禁止拖动
			m_plot->setInteraction(QCP::iRangeDrag, false);
		}
	}



	void CPlotCurve::setVisibleTracer(bool trueorfalse)
	{
		tracer0->setVisible(trueorfalse);
		tracer0Label->setVisible(trueorfalse);
		m_plot->replot(QCustomPlot::rpQueuedReplot); //刷新图标，不能省略
	}


	CPlotColorMap::CPlotColorMap(QWidget* parent)
	{
		// 创建 QCustomPlot 对象并初始化
		m_plot = new QCustomPlot(parent);
		// 创建颜色映射对象
		m_colorMap = new QCPColorMap(m_plot->xAxis, m_plot->yAxis);
		// 设置颜色梯度为热图
		m_colorGradient = QCPColorGradient(QCPColorGradient::gpHot);
		// 创建颜色比例尺
		m_colorScale = new QCPColorScale(m_plot);

		m_plot->selectionRect()->setPen(QPen(Qt::black, 1, Qt::DashLine));//设置选框的样式：虚线
		m_plot->selectionRect()->setBrush(QBrush(QColor(0, 0, 100, 50)));//设置选框的样式：半透明浅蓝
		//m_plot->setInteraction(QCP::iRangeDrag, true); //鼠标单击拖动 QCPAxisRect::mousePressEvent() 左键拖动
		m_plot->setInteraction(QCP::iRangeZoom, true); //滚轮滑动缩放
		m_plot->setInteraction(QCP::iSelectAxes, true);
		m_plot->setInteraction(QCP::iSelectLegend, true); //图例可选
		//m_plot->selectionRect()->setPen(QPen(Qt::black, 1, Qt::DashLine));
		//m_plot->selectionRect()->setBrush(QBrush(QColor(0, 0, 100, 50)));
		//m_plot->setSelectionRectMode(QCP::SelectionRectMode::srmZoom);

		// 将颜色梯度应用于颜色映射



		// 将颜色映射与颜色比例尺关联
		m_colorMap->setColorScale(m_colorScale);
		// 设置颜色比例尺类型为底部
		m_colorScale->setType(QCPAxis::atBottom);

		// 将颜色比例尺添加到绘图布局中
		m_plot->plotLayout()->addElement(1, 0, m_colorScale);


		initIntegrate();

		m_colorScale->setGradient(m_colorGradient);
		m_colorMap->setGradient(m_colorGradient);

		connect(m_plot, &QCustomPlot::mouseMove, this, &CPlotColorMap::slotLineMouseMove);
		connect(m_plot, &QCustomPlot::mousePress, this, &CPlotColorMap::slotLineMousePress);
		connect(m_plot, &QCustomPlot::mouseRelease, this, &CPlotColorMap::slotLineMouseRelease);

		QVBoxLayout* layout = new QVBoxLayout(parent);
		layout->addWidget(m_plot);
		setLayout(layout);


		m_plot->replot(); //刷新图标，不能省略


	}

	CPlotColorMap::~CPlotColorMap()
	{
	}

	void CPlotColorMap::setXRange(double lower, double upper)
	{
		m_plot->xAxis->setRange(lower, upper);

		// 获取 Y 轴范围
		QCPRange rangex = m_plot->xAxis->range();
		QCPRange rangeY = m_plot->yAxis->range();
		m_colorMap->data()->setSize(rangex.size(), rangeY.size());
		m_colorMap->data()->setRange(rangex, rangeY);
		m_colorMap->setDataRange(rangeY);

		// 色卡
		m_colorScale->setDataRange(rangeY);
	}

	void CPlotColorMap::setYRange(double lower, double upper)
	{
		m_plot->yAxis->setRange(lower, upper);
		// 获取 X 轴范围
		QCPRange rangex = m_plot->xAxis->range();
		QCPRange rangeY = m_plot->yAxis->range();
		m_colorMap->data()->setSize(rangex.size(), rangeY.size());
		m_colorMap->data()->setRange(rangex, rangeY);
		m_colorMap->setDataRange(rangeY);

		// 色卡
		m_colorScale->setDataRange(rangeY);

		m_plot->replot();
	}
	void CPlotColorMap::setColorStops(QMap<double, QColor> stops)
	{
		m_colorGradient.clearColorStops();
		m_colorGradient.setColorStops(stops);
		m_plot->replot();
	}

	void CPlotColorMap::setLineHVisible(bool visible)
	{
		m_lineH->setVisible(visible);
		m_plot->replot(); //刷新图标，不能省略

	}

	void CPlotColorMap::setLineVVisible(bool visible)
	{
		m_lineV->setVisible(visible);
		m_plot->replot(); //刷新图标，不能省略
	}

	void CPlotColorMap::setColorMapValues(double x, double y, double color)
	{
		m_colorMap->data()->setCell(x, y, color);
	}

	QCPColorMap* CPlotColorMap::getColorMap() const
	{
		return m_colorMap;
	}

	QCustomPlot* CPlotColorMap::getPlot() const
	{
		return m_plot;
	}

	QCPColorScale* CPlotColorMap::getColorScale() const
	{
		return m_colorScale;
	}

	QCPColorGradient CPlotColorMap::getColorGradient() const
	{
		return m_colorGradient;
	}

	QCPItemStraightLine* CPlotColorMap::getLineH() const
	{
		return m_lineH;
	}

	QCPItemStraightLine* CPlotColorMap::getLineV() const
	{
		return m_lineV;
	}
	void CPlotColorMap::slotLineMousePress(QMouseEvent* event)
	{
		if (event->button() == Qt::LeftButton)
		{

			// 计算与水平和垂直线的距离
			double distanceH = m_lineH->selectTest(event->pos(), false);
			double distanceV = m_lineV->selectTest(event->pos(), false);

			// 判断显示
			if (m_lineH->visible() && distanceH < LINEDISTANCE)
			{
				m_lineHMoveable = true;
				m_plot->setCursor(Qt::ClosedHandCursor);
			}
			if (m_lineV->visible() && distanceV < LINEDISTANCE)
			{
				m_lineVMoveable = true;
				m_plot->setCursor(Qt::ClosedHandCursor);
			}

		}
	}
	void CPlotColorMap::slotLineMouseMove(QMouseEvent* event)
	{
		if (1)
		{
			//当前鼠标位置（像素坐标）
			double x_pos = event->pos().x();
			double y_pos = event->pos().y();

			//像素坐标转成实际的x,y轴的坐标
			double x_val = m_plot->xAxis->pixelToCoord(x_pos);
			double y_val = m_plot->yAxis->pixelToCoord(y_pos);

			if (m_lineHMoveable && m_lineH->visible())
			{
				// 横轴
				// 获取 Y值
				//double y_val = m_lineH->point1->value();
				// 设置 Y值
				m_lineH->point1->setCoords(m_plot->xAxis->range().lower, y_val);
				m_lineH->point2->setCoords(m_plot->xAxis->range().upper, y_val);
				m_plot->replot(); //刷新图标，不能省略

				emit signalHLinePositionChanged(y_val);
			}
			if (m_lineVMoveable && m_lineV->visible())
			{
				// 纵轴
				// 获取 X值
				//double x_val = m_lineV->point1->key();
				// 设置 X值
				m_lineV->point1->setCoords(x_val, m_plot->yAxis->range().lower);
				m_lineV->point2->setCoords(x_val, m_plot->yAxis->range().upper);
				m_plot->replot(); //刷新图标，不能省略
				emit signalVLinePositionChanged(x_val);
			}
		}
	}

	void CPlotColorMap::slotLineMouseRelease(QMouseEvent* event)
	{
		m_plot->setCursor(Qt::ArrowCursor);
		m_lineHMoveable = false;
		m_lineVMoveable = false;
	}

	void CPlotColorMap::setHlinePostion(double y)
	{
		qDebug() << "setHlinePostion:" << y;
		if (m_lineH->visible())
		{
			m_lineH->point1->setCoords(m_plot->xAxis->range().lower, y);
			m_lineH->point2->setCoords(m_plot->xAxis->range().upper, y);
			m_plot->replot(); //刷新图标，不能省略
		}
	}

	void CPlotColorMap::setVlinePostion(double x)
	{
		if (m_lineV->visible())
		{
			m_lineV->point1->setCoords(x, m_plot->yAxis->range().lower);
			m_lineV->point2->setCoords(x, m_plot->yAxis->range().upper);
			m_plot->replot(); //刷新图标，不能省略
			qDebug() << "setVlinePostion:" << x;
		}
	}

	void CPlotColorMap::initIntegrate()
	{
		QPen pen(Qt::red, 1.5, Qt::SolidLine); //颜色 、宽度、样式（直线）
		m_lineH = new QCPItemStraightLine(m_plot);
		m_lineH->setLayer("overlay");
		m_lineH->setPen(pen);//设置游标线的样式
		m_lineH->setClipToAxisRect(true);//自适应范围
		m_lineH->point1->setCoords(m_plot->xAxis->range().lower, 1);//起点坐标
		m_lineH->point2->setCoords(m_plot->xAxis->range().upper, 1);//终点坐标
		m_lineH->setVisible(false);

		m_lineV = new QCPItemStraightLine(m_plot);
		m_lineV->setLayer("overlay");
		m_lineV->setPen(pen);
		m_lineV->setClipToAxisRect(true);
		m_lineV->point1->setCoords(1, m_plot->yAxis->range().lower);
		m_lineV->point2->setCoords(1, m_plot->yAxis->range().upper);
		m_lineV->setVisible(false);

	}

}
