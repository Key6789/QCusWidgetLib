#pragma once
#ifndef QCWIDGETVLAY_H
#define QCWIDGETVLAY_H
#include <QWidget>
#include "QCusWidgetLib_global.h"

namespace QCUSWIDGETLIB
{
	class QCUSWIDGETLIB_EXPORT CWidgetVLay : public QWidget
	{
		Q_OBJECT

	public:
		CWidgetVLay(QWidget* parent);
		~CWidgetVLay();

		void addWidget(QWidget* pWidget);
		void removeWidget(QWidget* pWidget);
		void clearLayout();
		void addLayout(QLayout* pLayout);
		void addStretch();

	private:
		QVBoxLayout* m_pLayout = nullptr;
	};
	class QCUSWIDGETLIB_EXPORT CWidgetHLay : public QWidget
	{
		Q_OBJECT

	public:
		CWidgetHLay(QWidget* parent);
		~CWidgetHLay();

		void addWidget(QWidget* pWidget);
		void removeWidget(QWidget* pWidget);
		void clearLayout();
		void addLayout(QLayout* pLayout);
		void addStretch();

	private:
		QHBoxLayout* m_pLayout = nullptr;
	};
}


#endif // !

