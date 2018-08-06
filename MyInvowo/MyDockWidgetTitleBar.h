#pragma once

#include <QWidget>

class QPaintEvent;
class QDockWidget;
class QToolButton;
class QLabel;

namespace myviwo {

class MyDockWidgetTitleBar : public QWidget
{
	Q_OBJECT

public:
	MyDockWidgetTitleBar(QWidget *parent = nullptr);
	~MyDockWidgetTitleBar();

	virtual void paintEvent(QPaintEvent *) override;

	void setLabel(const QString &str);
	void setSticky(bool toggle);
	bool isSticky() const;

	void allowedAreasChanged(Qt::DockWidgetAreas areas);
	void floating(bool floating);
signals:
	void stickyFlagChanged(bool sticky);
protected slots:
	virtual void showEvent(QShowEvent *event) override;
private:
	void stickyBtnToggled(bool toggle);

	QDockWidget *parent_;
	QLabel* label_;
	QToolButton *stickyBtn_;
	QToolButton *floatBtn_;
	Qt::DockWidgetAreas allowedDockAreas_;

	bool internalStickyFlagUpdate_;
};

}