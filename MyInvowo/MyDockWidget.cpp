#include "MyDockWidget.h"
#include "MyDockWidgetTitleBar.h"
#include <QDockWidget>

namespace myviwo {

MyDockWidget::MyDockWidget(QString title, QWidget *parent)
	: QDockWidget(title, parent)
{
	setObjectName(title);
#ifdef __APPLE__
	setStyleSheet("QDockWidget::title {padding-left: 45px; }");
#endif

	dockWidgetTitleBar_ = new MyDockWidgetTitleBar(this);
	setTitleBarWidget(dockWidgetTitleBar_);//dockwodget里面的内容

	QObject::connect(this, &QDockWidget::topLevelChanged, dockWidgetTitleBar_, &MyDockWidgetTitleBar::floating);
	QObject::connect(this, &QDockWidget::windowTitleChanged, [&](const QString &str) {dockWidgetTitleBar_->setLabel(str);  });
	QObject::connect(dockWidgetTitleBar_, &MyDockWidgetTitleBar::stickyFlagChanged, this, &MyDockWidget::stickyFlagChanged);
	QObject::connect(this, &QDockWidget::allowedAreasChanged, dockWidgetTitleBar_, &MyDockWidgetTitleBar::allowedAreasChanged);
}

MyDockWidget::~MyDockWidget() = default;

void MyDockWidget::showEvent(QShowEvent * showEvent)
{
	raise();
	QDockWidget::showEvent(showEvent);
}

void MyDockWidget::keyPressEvent(QKeyEvent * keyEvent)
{
	if (keyEvent->key() == Qt::Key_Escape && isFloating())
	{
		hide();
	}
	else
	{
		keyEvent->ignore();
	}
	QDockWidget::keyPressEvent(keyEvent);
}

void MyDockWidget::setSticky(bool sticky)
{
	dockWidgetTitleBar_->setSticky(sticky);
}

bool MyDockWidget::isSticky() const
{
	return dockWidgetTitleBar_->isSticky();
}

void MyDockWidget::setContents(QWidget * widget)
{
	QWidget *oldWidget = this->widget();
	if (oldWidget)
	{
		this->setWidget(nullptr);
		delete oldWidget;
	}
	this->setWidget(widget);
}

void MyDockWidget::serContents(QLayout * layout)
{
	QWidget *oldWidget = this->widget();
	if (oldWidget)
	{
		this->setWidget(nullptr);
		delete oldWidget;
	}

	QWidget *centralWidget = new QWidget();
	centralWidget->setLayout(layout);
	this->setWidget(centralWidget);
}

}