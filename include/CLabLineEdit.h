#pragma once
#ifndef CLABLINEEDIT_H
#define CLABLINEEDIT_H
#include <QWidget>
#include <QLineEdit>
#include "QCusWidgetLib_global.h"
namespace QCUSWIDGETLIB
{
	// ����һ��ģ���࣬���ڼ̳�QWidget�������һЩ���õ����Ժͷ���
	class QCUSWIDGETLIB_EXPORT CLabLineEdit : public QWidget
	{
		Q_OBJECT
	public:
		CLabLineEdit(QWidget* parent = nullptr);

		// ���ñ�ǩ�ı�
		void setLabelText(QString text);
		// �����б༭�ı�
		void setLineEditText(QString text);
		// ����ֻ��״̬
		void setReadOnly(bool isReadOnly);
		// ����ռλ���ı�
		void setPlaceholderText(QString text);
		// ���õ�λ�ı�
		void setUnitText(QString text);
		// ��ȡ�б༭�ı�
		QString getLineEditText();
		// ��ȡ�б༭�ؼ�
		QLineEdit* getLineEdit();


	private:
		QLabel* m_label = nullptr;
		QLineEdit* m_lineEdit = nullptr;
	};

	class QCUSWIDGETLIB_EXPORT CLabLineEditBtn : public QWidget
	{
		Q_OBJECT
	public:
		CLabLineEditBtn(QWidget* parent = nullptr);

		void setLineEditReadOnly(bool isReadOnly);
		// ���ñ�ǩ�ı�
		void setLabelText(QString text);
		// �����б༭�ı�
		void setLineEditText(QString text);
		// ����ֻ��״̬
		void setReadOnly(bool isReadOnly);
		// ����ռλ���ı�
		void setPlaceholderText(QString text);
		// ���õ�λ�ı�
		void setUnitText(QString text);
		// ���ð�ť�ı�
		void setBtnText(QString text);
		// ���ð�ťͼ��
		void setBtnIcon(QIcon icon);
		// ��ȡ�б༭�ı�
		QString getLineEditText();
		// ��ȡ�б༭�ؼ�
		QLineEdit* getLineEdit();
		// ��ȡ��ť�ؼ�
		QPushButton* getBtn();

		// ���ð�ť�ɼ���
		void setBtnVisible(bool isVisible);

		void connectBtnClicked(const std::function<void()>& func);
		void connectBtnClicked(void(*func)());
		void setPathFilter(const QString& filter);
		void btnClickedPath();
		void btnClickedColor();

	signals:
		void signalLineEditChanged(QString text);

	private:
		QLabel* m_label = nullptr;
		QLineEdit* m_lineEdit = nullptr;
		QPushButton* m_btn = nullptr;

		QString m_pathFilter = "";
	};
}
#endif // CLABLINEEDIT_H