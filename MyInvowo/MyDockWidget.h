#pragma once

#include <QDockWidget>
#include <QKeyEvent>
#include <qlayout.h>

namespace myviwo {

	class MyDockWidgetTitleBar;


class MyDockWidget : public QDockWidget
{
	Q_OBJECT

public:
	MyDockWidget(QString title, QWidget *parent);
	virtual ~MyDockWidget();
	//��д
	virtual void showEvent(QShowEvent *showEvent) override;
	virtual void keyPressEvent(QKeyEvent *keyEvent) override;

	//ͣ������ճ��
	void setSticky(bool sticky);
	bool isSticky() const;

	void setContents(QWidget *widget);
	void serContents(QLayout *layout);

signals:
	void stickyFlagChanged(bool sticky);
private:
	MyDockWidgetTitleBar * dockWidgetTitleBar_;

};

}