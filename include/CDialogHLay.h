#pragma once
#ifndef ADIALOGHLAY_H
#define ADIALOGHLAY_H

#include <QDialog>
#include "QCusWidgetLib_global.h"
namespace QCUSWIDGETLIB 
{
	class QCUSWIDGETLIB_EXPORT CDialogHLay : public QDialog
	{
		Q_OBJECT

	public:
		CDialogHLay(QWidget* parent);
		~CDialogHLay();

	public:
		void addWidget(QWidget* widget, int stretch = 0);

	private:
		void initUI();

		QHBoxLayout* m_hLayout = nullptr;

	};
	class QCUSWIDGETLIB_EXPORT CDialogVLay : public QDialog
	{
		Q_OBJECT

	public:
		CDialogVLay(QWidget* parent);
		~CDialogVLay();

	public:
		void addWidget(QWidget* widget, int stretch = 0);

	private:
		void initUI();

		QVBoxLayout* m_vLayout = nullptr;

	};



}

#endif // !

