#pragma once
#ifndef CBTNAPPCAN_H_
#define CBTNAPPCAN_H_
#include "QCusWidgetLib_global.h"
#include <QWidget>
namespace QCUSWIDGETLIB
{
	// ����һ��ģ���࣬���ڼ̳�QWidget�������һЩ���õ����Ժͷ���
	// CBtnAppCan �����ڴ�������Ӧ�ð�ť��ȡ����ť���Զ���ؼ�
	class QCUSWIDGETLIB_EXPORT CBtnAppCan : public QWidget
	{
		Q_OBJECT
	public:
		// ���캯������ʼ�������
		CBtnAppCan(QWidget* parent = nullptr);
		// ��������
		~CBtnAppCan() {}

		// ��ȡӦ�ð�ť
		QPushButton* getAppBtn();
		// ��ȡȡ����ť
		QPushButton* getCanBtn();
		
		// ���û�������
		void setMutualExclusive(bool mutual);

		// ����Ӧ�ð�ť��ȡ����ť��˳��
	
		// ����Ӧ�ð�ť����
		void setAppBtnText(const QString& text);
		// ����ȡ����ť����
		void setCanBtnText(const QString& text);

		// ����Ӧ�ð�ť��ɫ
		// ������ɫ
		void setAppBtnColor(const QColor& color);
		// ����ȡ����ť��ɫ
		void setCanBtnColor(const QColor& color);

		// ����Ӧ�ð�ť����¼����źŲ�
		// ���� �����źŲ�
		void setAppBtnClicked(const std::function<void()>& func);
		// ����ȡ����ť����¼����źŲ�
		void setCanBtnClicked(const std::function<void()>& func);

		// ����Ӧ�ð�ť�Ŀɼ���
		void setAppBtnVisible(bool visible);
		// ����ȡ����ť�Ŀɼ���
		void setCanBtnVisible(bool visible);

		// ����Ӧ�ð�ť������״̬
		void setAppBtnEnabled(bool enabled);
		// ����ȡ����ť������״̬
		void setCanBtnEnabled(bool enabled);
	signals:
		// Ӧ�ð�ť�����ʱ���ź�
		void appBtnClicked();
		// ȡ����ť�����ʱ���ź�
		void canBtnClicked();

	private:
		QPushButton* m_appBtn = nullptr; // Ӧ�ð�ťָ��
		QPushButton* m_canBtn = nullptr; // ȡ����ťָ��

		
	};


	class QCUSWIDGETLIB_EXPORT CBtnsHBox : public QWidget
	{
		Q_OBJECT
	public:
		// ����һ���Զ����ˮƽ���ְ�ť������
		CBtnsHBox(QWidget* parent = nullptr);
		~CBtnsHBox() {}

		// ��Ӱ�ť
		void addBtn(int index, const QString& text);
		void setBtnText(int index, const QString& text);

		QPushButton* getBtn(int index);

		// ������ɫ
		void setBtnColor(int index, const QColor& color);

		// ����ͼƬ
		void setBtnIcon(int index, const QIcon& icon);

		// ���� �����źŲ�
		void setBtnClicked(int index, const std::function<void()>& func);

		// ���ð�ť�ɼ���
		void setBtnVisible(int index, bool visible);
		void setBtnEnabled(int index, bool enabled);

		// ������а�ť
		void clearBtns();

		// �����ź�����
		void setConnect(int index, const std::function<void()>& func);
		void setStyleSheet(int index, const QString& styleSheet);

		// ��ӵ��Կռ�
		void addStretch();

		// ���ò��ֱ߾�
		void setLayMargin(int left, int top, int right, int bottom);

		// ���ò��ּ��
		void setLaySpacing(int spacing);


	signals:
		// ��ť��������ź�
		void btnClicked(int index);

	private:
		// �洢��ť��ӳ��
		QMap<int, QPushButton*> m_btns = QMap<int, QPushButton*>();
		// ˮƽ����ָ��
		QHBoxLayout* m_layout = nullptr;

	};

	// CBtnsVBox�����ڹ���ֱ���еİ�ť
	class QCUSWIDGETLIB_EXPORT CBtnsVBox : public QWidget
	{
		Q_OBJECT
	public:
		// ���캯������ʼ��CBtnsVBox����
		CBtnsVBox(QWidget* parent = nullptr);
		~CBtnsVBox() {}

		// ��Ӱ�ť
		void addBtn(int index, const QString& text);
		// ��ȡ��ť
		QPushButton* getBtn(int index);
		// ���ð�ť�ı�
		void setBtnText(int index, const QString& text);


		// ���ò��ֱ߾�
		void setLayMargin(int left, int top, int right, int bottom);
		// ���ò��ּ��
		void setLaySpacing(int spacing);

		// ������ɫ
		// ���ð�ť��ɫ
		void setBtnColor(int index, const QColor& color);

		// ����ͼƬ
		// ���ð�ťͼ��
		void setBtnIcon(int index, const QIcon& icon);

		// ���� �����źŲ�
		// ���ð�ť���ʱ�Ļص�����
		void setBtnClicked(int index, const std::function<void()>& func);

		// ����
		// ���ð�ť�Ŀɼ���
		void setBtnVisible(int index, bool visible);
		// ���ð�ť�Ŀ���״̬
		void setBtnEnabled(int index, bool enabled);

		// ������а�ť
		void clearBtns();

		// ��������
		void setConnect(int index, const std::function<void()>& func);
		// ������ʽ��
		void setStyleSheet(int index, const QString& styleSheet);

		// ���ð�ť���״̬
		void setBtnClicked(int index, bool clicked);
		// ��ȡ��ť���״̬
		bool getBtnClicked(int index);

		// ���ü��
		void addStretch();

		// ���óߴ�
		// ����CBtnsVBox�Ĺ̶��ߴ�
		void setSize(int width, int height);

		// ���ð�ť�Ĺ̶���С
		void setBtnFixSize(int index, int width, int height);
		// ���ð�ť�ĵ�����С
		void setBtnResize(int index, int width, int height);

		// ���ð�ť�Ĵ�С����
		void setBtnSizePolicy(int index, QSizePolicy policy);
		// ���ð�ť�Ķ�������
		void setObjectName(int index, const QString& name);
		// ���ð�ť����ʽ
		void setBtnStyle(int index, const QString& styleSheet);
		// ���ð�ť������
		void setBtnFont(int index, const QFont& font);

		// ��ȡ��ť�Ķ�������
		QString getObjectName(int index);


	signals:
		// ��ť����ź�
		void btnClicked(int index);


	private:
		// �洢��ť��ӳ��
		QMap<int, QPushButton*> m_btns = QMap<int, QPushButton*>();
		// ��ֱ����
		QVBoxLayout* m_layout = nullptr;
	};


}
#endif // CLABLINEEDIT_H