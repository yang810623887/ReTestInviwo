#pragma once

#include <QDockWidget>
#include <QKeyEvent>
#include <qlayout.h>

class MyDockWidget : public QDockWidget
{
	Q_OBJECT

public:
	MyDockWidget(QString title, QWidget *parent);
	~MyDockWidget();
	//ÖØÐ´
	virtual void showEvent(QShowEvent *showEvent) override;
	virtual void keyPressEvent(QKeyEvent *keyEvent) override;

	//Í£¿¿´°¿ÚÕ³Ìù
	void setSticky(bool sticky);
	bool isSticky() const;

	void setContents(QWidget *widget);
	void serContents(QLayout *layout);

signals:
	void stickyFlagChanged(bool sticky);
private:


};
