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
		void addWidget(QWidget* pWidget, int stretch);
		void removeWidget(QWidget* pWidget);
		void clearLayout();
		void addLayout(QLayout* pLayout);
		void addStretch();

		void setLayMargin(int left, int top, int right, int bottom);
		void setLayMargin(int margin);
		void setLaySpacing(int spacing);
		void setLayContentsMargins(int left, int top, int right, int bottom);


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
		void addWidget(QWidget* pWidget, int stretch);
		void removeWidget(QWidget* pWidget);
		void clearLayout();
		void addLayout(QLayout* pLayout);
		void addStretch();

		void setLayMargin(int left, int top, int right, int bottom);
		void setLayMargin(int margin);
		void setLaySpacing(int spacing);
		void setLayContentsMargins(int left, int top, int right, int bottom);

	private:
		QHBoxLayout* m_pLayout = nullptr;
	};
	// Íø¸ñ
	class QCUSWIDGETLIB_EXPORT CWidgetGridLayout : public QWidget
	{
		Q_OBJECT

	public:
		CWidgetGridLayout(QWidget* parent);
		~CWidgetGridLayout();

		void addWidget(QWidget* pWidget, int row, int col, int rowSpan = 1, int colSpan = 1, Qt::Alignment alignment = Qt::Alignment());
		void removeWidget(QWidget* pWidget);
		void clearLayout();
		void addLayout(QLayout* pLayout, int row, int col, int rowSpan = 1, int colSpan = 1, Qt::Alignment alignment = Qt::Alignment());
		void addStretch(int row, int col, int rowSpan = 1, int colSpan = 1);

		void setLayMargin(int left, int top, int right, int bottom);
		void setLayMargin(int margin);
		void setLaySpacing(int spacing);
		void setLayContentsMargins(int left, int top, int right, int bottom);

	private:
		QGridLayout* m_pLayout = nullptr;
	};
}


#endif // !

