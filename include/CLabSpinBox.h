#pragma once
#ifndef CLABSPINBOX_H
#define CLABSPINBOX_H

#include <QWidget>
#include "QCusWidgetLib_global.h"

namespace QCUSWIDGETLIB
{
	class QCUSWIDGETLIB_EXPORT CLabSpinBox : public QWidget
	{
		Q_OBJECT

	public:
		CLabSpinBox(QWidget* parent);
		~CLabSpinBox();

		// 设置范围的最小值和最大值
		void setRange(int min, int max);
		// 设置当前值
		void setValue(int value);
		// 获取当前值
		int value() const;

		// 设置标签文本
		void setLabelText(const QString& text);
		// 设置标签对齐方式
		void setLabelAlignment(Qt::Alignment alignment);

		// 设置只读状态
		void setReadOnly(bool readOnly);
		// 获取是否为只读状态
		bool isReadOnly() const;

		// 设置控件是否启用
		void setEnabled(bool enabled);
		// 获取控件是否被启用
		bool isEnabled() const;

		// 设置单步增量
		void setSingleStep(int step);
		// 获取单步增量
		int singleStep() const;

		// 设置前缀
		void setPrefix(const QString& prefix);
		// 获取前缀
		QString prefix() const;

		// 设置后缀
		void setSuffix(const QString& suffix);
		// 获取后缀
		QString suffix() const;

		// 设置 decimal 精度

		// s设置连接
		void setConnect(std::function<void(int)> func);

		// 设置标签 的Vis
		void setLabelVis(bool vis);

		int getIntValue() const;

	signals:
		void valueChanged(int value);

	private:
		void initUI();
		void initConnections();

		QSpinBox* m_spinIntBox = nullptr;
		QLabel* m_labIntBox = nullptr;
	};

	// double版本的spinbox
	class QCUSWIDGETLIB_EXPORT CLabDoubleSpinBox : public QWidget
	{
		Q_OBJECT

	public:
		CLabDoubleSpinBox(QWidget* parent);
		~CLabDoubleSpinBox();

		// 设置范围的最小值和最大值
		void setRange(double min, double max);
		// 设置当前值
		void setValue(double value);
		// 获取当前值
		double value() const;

		// 设置标签文本
		void setLabelText(const QString& text);
		// 设置标签对齐方式
		void setLabelAlignment(Qt::Alignment alignment);

		// 设置只读状态
		void setReadOnly(bool readOnly);
		// 获取是否为只读状态
		bool isReadOnly() const;

		// 设置控件是否启用
		void setEnabled(bool enabled);
		// 获取控件是否被启用
		bool isEnabled() const;

		// 设置单步增量
		void setSingleStep(double step);
		// 获取单步增量
		double singleStep() const;

		// 设置前缀
		void setPrefix(const QString& prefix);
		// 获取前缀
		QString prefix() const;

		// 设置后缀
		void setSuffix(const QString& suffix);
		// 获取后缀
		QString suffix() const;

		void setConnect(std::function<void(double)> func);

	signals:
		void valueChanged(double value);

	private:
		void initUI();
		void initConnections();

		QDoubleSpinBox* m_spinDoubleBox = nullptr;
		QLabel* m_labDoubleBox = nullptr;
	};
}

#endif // CLABSPINBOX_H
