#include "MyDockWidgetTitleBar.h"
#include <QDockWidget>
#include <QLabel>
#include <qtoolbutton.h>
#include <qicon.h>
#include <qpixmap.h>
#include <QHBoxLayout>
MyDockWidgetTitleBar::MyDockWidgetTitleBar(QWidget *parent)
	: QWidget(parent)
	, parent_(dynamic_cast<QDockWidget *>(parent))
	, allowedDockAreas_(parent_->allowedAreas())
	, internalStickyFlagUpdate_(false)
{
	label_ = new QLabel(parent);
	label_->setStyleSheet("QWidget { padding-left: 5px; background-color: 'transparent'; }");

	stickyBtn_ = new QToolButton();
	QIcon icon;
	icon.addPixmap(QPixmap(":/stylesheets/Resources/stylesheets/images/dock-unsticky.png"), QIcon::Normal, QIcon::Off);
	icon.addPixmap(QPixmap(":/stylesheets/Resources/stylesheets/images/dock-sticky.png"), QIcon::Normal, QIcon::On);

	stickyBtn_->setIcon(icon);
	stickyBtn_->setCheckable(true);
	stickyBtn_->setChecked(true);
	stickyBtn_->setObjectName("dockBtn");

	floatBtn_ = new QToolButton();
	QIcon icon2;
	icon2.addPixmap(QPixmap(":/stylesheets/Resources/stylesheets/images/dock-docked.png"), QIcon::Normal, QIcon::Off);
	icon2.addPixmap(QPixmap(":/stylesheets/Resources/stylesheets/images/dock-floating.png"), QIcon::Normal, QIcon::On);

	floatBtn_->setIcon(icon2);
	floatBtn_->setCheckable(true);
	floatBtn_->setChecked(parent_->isFloating());
	floatBtn_->setObjectName("dockBtn");

	QToolButton *closeBtn = new QToolButton();
	closeBtn->setIcon(QIcon(":/stylesheets/Resources/stylesheets/images/close.png"));
	closeBtn->setObjectName("dockBtn");

	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->addWidget(label_, 1);
	layout->addWidget(stickyBtn_);
	layout->addWidget(floatBtn_);
	layout->addWidget(closeBtn);
	layout->setSpacing(2);
	layout->setMargin(2);

	this->setLayout(layout);

	QObject::connect(stickyBtn_, &QToolButton::toggled, this, &MyDockWidgetTitleBar::stickyBtnToggled);
}

MyDockWidgetTitleBar::~MyDockWidgetTitleBar()
{
}
void MyDockWidgetTitleBar::showEvent(QShowEvent *event)
{

}
void MyDockWidgetTitleBar::paintEvent(QPaintEvent *)
{
}

void MyDockWidgetTitleBar::stickyBtnToggled(bool toggle)
{
	//此处待开发
	if (toggle) {
		parent_->setAllowedAreas(allowedDockAreas_);
	}
	else
	{
		parent_->setAllowedAreas(Qt::NoDockWidgetArea);
	}
	emit stickyFlagChanged(toggle);
}
