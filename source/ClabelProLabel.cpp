#include "../include/ClabelProLabel.h"

namespace QCUSWIDGETLIB
{
	ClabelProLabel::ClabelProLabel(QWidget* parent)
		: QWidget(parent)
	{
		QHBoxLayout* layout = new QHBoxLayout(this);
		m_firstLabel = new QLabel(this);
		layout->addWidget(m_firstLabel);
		m_progressBar = new QProgressBar(this);
		m_progressBar->setMinimum(0);
		m_progressBar->setMaximum(100);
		layout->addWidget(m_progressBar);

		m_endLabel = new QLabel(this);
		layout->addWidget(m_endLabel);

		setLayout(layout);
	
	}

	ClabelProLabel::~ClabelProLabel()
	{}

	void ClabelProLabel::setFirstLabel(const QString & text)
	{
		m_firstLabel->setText(text);
	}

	void ClabelProLabel::setEndLabel(const QString& text)
	{
		m_endLabel->setText(text);
	}

	void ClabelProLabel::setProgressValue(int value)
	{
		m_progressBar->setValue(value);
	}

	int ClabelProLabel::getProgressValue()
	{
		return m_progressBar->value();
	}

	void ClabelProLabel::setFirstLabelVisible(bool visible)
	{
		m_firstLabel->setVisible(visible);
	}

	void ClabelProLabel::setEndLabelVisible(bool visible)
	{
		m_endLabel->setVisible(visible);
	}

	void ClabelProLabel::setProgressBarVisible(bool visible)
	{
		m_progressBar->setVisible(visible);
	}

	void ClabelProLabel::setRange(int min, int max)
	{
		m_progressBar->setRange(min, max);
	}

	void ClabelProLabel::setMaximum(int max)
	{
		m_progressBar->setMaximum(max);
	}

	void ClabelProLabel::setMinimum(int min)
	{
		m_progressBar->setMinimum(min);
	}

	int ClabelProLabel::getMaximum()
	{
		return m_progressBar->maximum();
	}

	int ClabelProLabel::getMinimum()
	{
		return m_progressBar->minimum();
	}

	void ClabelProLabel::setProgressBarColor(const QColor& color)
	{
		m_progressBar->setStyleSheet("QProgressBar::chunk {background-color: " + color.name() + ";}");
	}

}


