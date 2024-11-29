#pragma once

#include <QWidget>
#include "QCusWidgetLib_global.h"
namespace QCUSWIDGETLIB
{
	//标签与组合框控件
	class QCUSWIDGETLIB_EXPORT CLabComBox : public QWidget
	{
		Q_OBJECT
	public:
		CLabComBox(QWidget* parent);
		~CLabComBox();
		QComboBox* getComBox();
		// 设置项目的函数，参数为项目字符串列表
		void addItems(const QStringList& items);
		void addItems(QMap<QString, QString>& items);

		QString getKeyFromValue(const QString& value);
		QString getValueFromKey(const QString& key);

		// 设置标签的函数，参数为标签字符串
		void setLabel(const QString& strLabel);

		// 添加项目的函数，参数为项目字符串
		void addItem(const QString& strItem);
		void addItem(const QString& key, const QString& value);
		void addItem(const QString& key, const int& value);
		void addItem(const QString& key, const QVariant& value);
		// 设置当前索引的函数，参数为索引整数
		void setCurIndex(int nIndex);

		// 获取当前索引的函数，返回当前索引整数
		int getCurIndex();

		// 获取当前文本的函数，返回当前文本字符串
		QString getCurText();

		// 清空所有项目的函数
		void clear();

		void setConnect(std::function<void(QString)> func);

	protected:
		void resizeEvent(QResizeEvent* event) override;

	signals:
		void currentIndexChanged(int index);
		void currentTextChanged(const QString& text);

	private:
		void initUI();

		QHBoxLayout* m_layoutMain = nullptr;
		QLabel* m_labLabel = nullptr;
		QComboBox* m_comBox = nullptr;
	};

}

