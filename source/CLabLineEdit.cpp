#include "../include/CLabLineEdit.h"
namespace QCUSWIDGETLIB
{
	CLabLineEdit::CLabLineEdit(QWidget* parent)
	{
		QHBoxLayout* layout = new QHBoxLayout(this);
		m_label = new QLabel(this);
		m_lineEdit = new QLineEdit(this);
		layout->addWidget(m_label);
		layout->addWidget(m_lineEdit);
		setLayout(layout);
	}
	void CLabLineEdit::setLabelText(QString text)
	{
		m_label->setText(text);
	}
	void CLabLineEdit::setLineEditText(QString text)
	{
		m_lineEdit->setText(text);
	}

	void CLabLineEdit::setReadOnly(bool isReadOnly)
	{
		m_lineEdit->setReadOnly(isReadOnly);
	}

	void CLabLineEdit::setPlaceholderText(QString text)
	{
		m_lineEdit->setPlaceholderText(text);
	}

	void CLabLineEdit::setUnitText(QString text)
	{
		m_label->setText(m_label->text() + " " + text);
	}

	QString CLabLineEdit::getLineEditText()
	{
		return m_lineEdit->text();
	}

	QLineEdit* CLabLineEdit::getLineEdit()
	{
		return m_lineEdit;
	}

	CLabLineEditBtn::CLabLineEditBtn(QWidget* parent)
	{
		QHBoxLayout* layout = new QHBoxLayout(this);
		m_label = new QLabel(this);
		m_lineEdit = new QLineEdit(this);
		m_btn = new QPushButton(this);
		layout->addWidget(m_label);
		layout->addWidget(m_lineEdit);
		layout->addWidget(m_btn);
		setLayout(layout);


		connect(m_lineEdit, &QLineEdit::textChanged, [=]() {emit signalLineEditChanged(m_lineEdit->text()); });
	}
	void CLabLineEditBtn::setLineEditReadOnly(bool isReadOnly)
	{
		m_lineEdit->setReadOnly(isReadOnly);
	}
	void CLabLineEditBtn::setLabelText(QString text)
	{
		m_label->setText(text);
	}
	void CLabLineEditBtn::setLineEditText(QString text)
	{
		m_lineEdit->setText(text);
	}

	void CLabLineEditBtn::setReadOnly(bool isReadOnly)
	{
		m_lineEdit->setReadOnly(isReadOnly);
	}

	void CLabLineEditBtn::setPlaceholderText(QString text)
	{
		m_lineEdit->setPlaceholderText(text);
	}

	void CLabLineEditBtn::setUnitText(QString text)
	{
		m_label->setText(m_label->text() + " " + text);
	}

	void CLabLineEditBtn::setBtnText(QString text)
	{
		m_btn->setText(text);
	}

	void CLabLineEditBtn::setBtnIcon(QIcon icon)
	{
		m_btn->setIcon(icon);
	}

	void CLabLineEditBtn::setBtnVisible(bool isVisible)
	{
		m_btn->setVisible(isVisible);
	}

	void CLabLineEditBtn::connectBtnClicked(const std::function<void()>& func)
	{
			QObject::connect(m_btn, &QPushButton::clicked, func);
	}

	void CLabLineEditBtn::connectBtnClicked(void(*func)())
	{
		QObject::connect(m_btn, &QPushButton::clicked, func);
	}

	void CLabLineEditBtn::setPathFilter(const QString& filter)
	{
		m_pathFilter = filter;
	}

	void CLabLineEditBtn::btnClickedPath()
	{
		// ��ȡ .tiff 
		QFileDialog dialog(this);
		dialog.setFileMode(QFileDialog::ExistingFile);  // ѡ�񵥸��ļ�
		if (!m_pathFilter.isEmpty())
		{
			dialog.setNameFilter(m_pathFilter);  // �����ļ�������
		}
		 // �����ļ�������
		dialog.setWindowTitle(__CSTRING_UTF8("ѡ���ļ�"));
		dialog.setLabelText(QFileDialog::Accept, __CSTRING_UTF8("ѡ��"));
		dialog.setLabelText(QFileDialog::Reject, __CSTRING_UTF8("ȡ��"));

		if (dialog.exec())
		{
			QString fileName = dialog.selectedFiles().first();  // ��ȡѡ�е��ļ���
			if (!fileName.isEmpty())
			{
				m_lineEdit->setText(fileName);  // ���ļ�����ʾ�� QLineEdit ��
			}
		}
	}

	void CLabLineEditBtn::btnClickedColor()
	{
		QColor color = QColorDialog::getColor(Qt::white, this);
		if (color.isValid())
		{
			m_lineEdit->setText(color.name());
		}
	}

	QString CLabLineEditBtn::getLineEditText()
	{
		return m_lineEdit->text();
	}

	QLineEdit* CLabLineEditBtn::getLineEdit()
	{
		return m_lineEdit;
	}

	QPushButton* CLabLineEditBtn::getBtn()
	{
		return m_btn;
	}

}