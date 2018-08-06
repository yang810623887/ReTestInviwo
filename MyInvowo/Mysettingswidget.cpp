#include "Mysettingswidget.h"

//Mysettingswidget::Mysettingswidget()
//{
//}
//
//Mysettingswidget::~Mysettingswidget()
//{
//}
namespace myviwo {
	Mysettingswidget::Mysettingswidget(QString title, MyInvowo * mainwindow)
		: MyDockWidget(title, mainwindow), mainwindow_(mainwindow)
	{
		setObjectName("SettingsWidget");
		setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

		scrollArea_ = new QScrollArea();
		scrollArea_->setWidgetResizable(true);
		scrollArea_->setMinimumWidth(300);
		scrollArea_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		scrollArea_->setFrameShape(QFrame::NoFrame);
		scrollArea_->setContentsMargins(0, 0, 0, 0);

		mainWidget_ = new QWidget();
		layout_ = new QVBoxLayout(mainWidget_);
		layout_->setAlignment(Qt::AlignTop);
		layout_->setContentsMargins(0, /*PropertyWidgetQt::spacing*/1, 0,/* PropertyWidgetQt::spacing*/1);
		layout_->setSpacing(7);
		scrollArea_->setWidget(mainWidget_);

		setWidget(scrollArea_);
	}
	Mysettingswidget::Mysettingswidget(MyInvowo *mainwindow) : Mysettingswidget(tr("Settings"), mainwindow){}
	Mysettingswidget::~Mysettingswidget() = default;
}