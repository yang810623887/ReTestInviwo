#pragma once

#include "MyDockWidget.h"
#include "MyInvowo.h"
#include <QVBoxLayout>
#include <QScrollArea>

namespace myviwo {
	//class PropertyWidgetQt;
class Mysettingswidget : public MyDockWidget
{
	Q_OBJECT

public:
	Mysettingswidget(MyInvowo *parent);
	Mysettingswidget(QString title, MyInvowo *parent);
	~Mysettingswidget();

//	virtual void updateSettingsWidget();
//	virtual void saveSettings();

public slots:
	//void updatePropertyWidgetSemantics(PropertyWidgetQt*);
	//virtual void closeEvent(QCloseEvent *event) override;
protected:
	MyInvowo * mainwindow_;
	QVBoxLayout* layout_ = nullptr;
	QWidget* mainWidget_ = nullptr;
	QScrollArea* scrollArea_ = nullptr;
};

}
