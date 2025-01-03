#pragma once

#ifndef QCUSWIDGETLIB_GLOBAL_H
#define QCUSWIDGETLIB_GLOBAL_H

#include <QtCore/qglobal.h>
// 添加QT 控件头文件
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QRadioButton>

#include <QColor>
#include <QButtonGroup>
#include <QChar>
#include <QChart>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtCharts>
#include <QGraphicsScene>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>

#include <QPushButton>
#include <QToolButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QDateTimeEdit>
#include <QProgressBar>
#include <QListWidget>
#include "qcustomplot.h"

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#define __CSTRING_UTF8(x) QString::fromLocal8Bit(x)

// 定义库的导出和导入宏


#  if (defined(BUILD_EXE) && BUILD_EXE == 1 && defined QCUSWIDGETLIB_LIBRARY )
#    define QCUSWIDGETLIB_EXPORT 
#  else
	#if defined(QCUSWIDGETLIB_LIBRARY)
	#  define QCUSWIDGETLIB_EXPORT Q_DECL_EXPORT
	#else
	# define QCUSWIDGETLIB_EXPORT Q_DECL_IMPORT
	#endif  
#  endif

#    define QCUSWIDGETLIB_EXPORT 
//#if defined(QCUSWIDGETLIB_LIBRARY)
//#  define QCUSWIDGETLIB_EXPORT Q_DECL_EXPORT
//#else
//# define QCUSWIDGETLIB_EXPORT Q_DECL_IMPORT
//#endif  

#endif // !


