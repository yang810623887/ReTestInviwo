#include "MyInvowo.h"
#include "Mysettingswidget.h"
#include <QDockwidget>
namespace myviwo {
	MyInvowo::MyInvowo(QWidget *parent)
		: QMainWindow(parent)
	{
		ui.setupUi(this);
		this->setAttribute(Qt::WA_AlwaysShowToolTips, true);

		//init
		currentWorkspaceFileName_ = "";

		settingsWidget_ = new Mysettingswidget(this);
		addDockWidget(Qt::LeftDockWidgetArea, settingsWidget_);
		settingsWidget_->hide();


		addActions();
	}

	void MyInvowo::newWorkspace()
	{
		if (currentWorkspaceFileName_ != "")
		{
			if (!askToSaveWorkspaceChanges())
			{
				return;
			}
		}
	}

	void MyInvowo::openWorkSpace()
	{
	}

	void MyInvowo::openRecentWorkspace()
	{
	}

	void MyInvowo::clearRecentWorkspaceMenu()
	{
	}

	void MyInvowo::saveWorkspace()
	{
	}

	void MyInvowo::saveWorkspaceAs()
	{
	}

	void MyInvowo::saveWorkspaceAsCopy()
	{
	}

	void MyInvowo::fillExampleWorkspaceMenu()
	{
	}

	void MyInvowo::fillTestWorkspaceMenu()
	{
	}

	void MyInvowo::addActions()
	{
		auto menu = menuBar();
		auto fileMenuItem = menu->addMenu(tr("&File"));
		auto editMenuItem = menu->addMenu(tr("&Edit"));
		auto viewMenuItem = menu->addMenu(tr("&View"));
		auto evalMenuItem = menu->addMenu(tr("&Evaluation"));
		auto helpMenuItem = menu->addMenu(tr("&Help"));

		auto workspaceToolBar = addToolBar("File");
		workspaceToolBar->setObjectName("fileToolBar");
		auto viewModeToolBar = addToolBar("View");
		viewModeToolBar->setObjectName("viewModeToolBar");
		auto evalToolBar = addToolBar("Evaluation");
		evalToolBar->setObjectName("evalToolBar");

		{
			auto newAction = new QAction(QIcon(":/icons/Resources/icons/new.png"), tr("&New Workspace"), this);
			actions_["New"] = newAction;
			newAction->setShortcut(QKeySequence::New);
			newAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);

			//this->addAction(newAction);
			connect(newAction, &QAction::triggered, this, &MyInvowo::newWorkspace);

			fileMenuItem->addAction(newAction);
			workspaceToolBar->addAction(newAction);
		}

		{
			auto openAction = new QAction(QIcon(":/icons/Resources/icons/open.png"), tr("&Open Workspace"), this);
			openAction->setShortcut(QKeySequence::Open);
			openAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
			this->addAction(openAction);
			actions_["Open"] = openAction;
			connect(openAction, &QAction::triggered, this,
				static_cast<void (MyInvowo::*)()>(&MyInvowo::openWorkSpace));

			fileMenuItem->addAction(openAction);
			workspaceToolBar->addAction(openAction);
		}

		{
			auto saveAction = new QAction(QIcon(":/icons/Resources/icons/save.png"), tr("&Save Workspace"), this);
			saveAction->setShortcut(QKeySequence::Save);
			saveAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
			this->addAction(saveAction);
			actions_["Save"] = saveAction;
			connect(saveAction, &QAction::triggered, this,
				static_cast<void (MyInvowo::*)()>(&MyInvowo::saveWorkspace));

			fileMenuItem->addAction(saveAction);
			workspaceToolBar->addAction(saveAction);
		}

		{
			auto saveAsAction =
				new QAction(QIcon(":/icons/Resources/icons/saveas.png"), tr("&Save Workspace As"), this);
			saveAsAction->setShortcut(QKeySequence::SaveAs);
			saveAsAction->setShortcutContext(Qt::WidgetWithChildrenShortcut);
			this->addAction(saveAsAction);
			actions_["Save As"] = saveAsAction;

			connect(saveAsAction, &QAction::triggered, this, &MyInvowo::saveWorkspaceAs);

			fileMenuItem->addAction(saveAsAction);
			workspaceToolBar->addAction(saveAsAction);
		}

		{
			auto workspaceActionSaveAsCopy =
				new QAction(QIcon(":/icons/Resources/icons/saveas.png"), tr("&Save Workspace As Copy"), this);

			connect(workspaceActionSaveAsCopy, &QAction::triggered, this,
				&MyInvowo::saveWorkspaceAsCopy);

			fileMenuItem->addAction(workspaceActionSaveAsCopy);
		}

		{
			connect(fileMenuItem->addAction("Save Network Image"), &QAction::triggered,
				[&](bool /*state*/) {
				//保存网页信息
			});
		}

		{
			fileMenuItem->addSeparator();
			auto recentWorkspaceMenu = fileMenuItem->addMenu(tr("&Recent Workspaces"));
			workspaceActionRecent_.resize(maxNumRecentFiles_);
			for (auto& action : workspaceActionRecent_)
			{
				action = new QAction(this);
				action->setVisible(false);
				recentWorkspaceMenu->addAction(action);
				QObject::connect(action, &QAction::triggered, this,
					&MyInvowo::openRecentWorkspace);
			}
			clearRecentWorkspaces_ = recentWorkspaceMenu->addAction("Clear Recent Workspace List");
			clearRecentWorkspaces_->setEnabled(false);
			QObject::connect(clearRecentWorkspaces_, &QAction::triggered, this,
				&MyInvowo::clearRecentWorkspaceMenu);
		}

		{
			exampleMenu_ = fileMenuItem->addMenu(tr("&Example Workspaces"));
			fillExampleWorkspaceMenu();
		}

		{
			testMenu_ = fileMenuItem->addMenu(tr("&Test Workspaces"));
			fillTestWorkspaceMenu();
		}

		{
			fileMenuItem->addSeparator();
			auto exitAction = new QAction(QIcon(":/icons/button_cancel.png"), tr("&Exit"), this);
			exitAction->setShortcut(QKeySequence::Close);
			connect(exitAction, &QAction::triggered, this, &MyInvowo::close);
			fileMenuItem->addAction(exitAction);
		}

		//Edit
		{
			//undoAction 需要引入外部功能
			auto undoAction = new QAction(tr("undo"), this);
			editMenuItem->addAction(undoAction);
		}
		{
			//redoAction需要引入外部功能
			auto redoAction = new QAction(tr("undo"), this);
			editMenuItem->addAction(redoAction);
		}

		editMenuItem->addSeparator();
		{
			auto cutAction = new QAction(tr("Cu&t"), this);
			actions_["Cut"] = cutAction;
			cutAction->setShortcut(QKeySequence::Cut);
			editMenuItem->addAction(cutAction);
			cutAction->setEnabled(false);
		}

		{
			auto copyAction = new QAction(tr("&Copy"), this);
			actions_["Copy"] = copyAction;
			copyAction->setShortcut(QKeySequence::Copy);
			editMenuItem->addAction(copyAction);
			//外部文件功能
		}

		{
			auto pasteAction = new QAction(tr("&Paste"), this);
			actions_["Paste"] = pasteAction;
			pasteAction->setShortcut(QKeySequence::Paste);
			editMenuItem->addAction(pasteAction);
		}

		{
			auto deleteAction = new QAction(tr("&Delete"), this);
			actions_["Delete"] = deleteAction;
			deleteAction->setShortcuts(QList<QKeySequence>(
				{ QKeySequence::Delete, QKeySequence(Qt::ControlModifier + Qt::Key_Backspace) }));
			editMenuItem->addAction(deleteAction);
			deleteAction->setEnabled(false);
		}

		editMenuItem->addSeparator();

		{
			auto selectAlllAction = new QAction(tr("&Select All"), this);
			actions_["Select All"] = selectAlllAction;
			selectAlllAction->setShortcut(QKeySequence::SelectAll);
			editMenuItem->addAction(selectAlllAction);
			//connect 外部功能
		}

		editMenuItem->addSeparator();

		{
			auto findAction = new QAction(tr("&Find Processor"), this);
			actions_["Find Processor"] = findAction;
			findAction->setShortcut(QKeySequence::Find);
			editMenuItem->addAction(findAction);
			//connect 外部功能
		}

		{
			auto addProcessorAction = new QAction(tr("&Add Processor"), this);
			actions_["Add Processor"] = addProcessorAction;
			addProcessorAction->setShortcut(Qt::ControlModifier + Qt::Key_D);
			editMenuItem->addAction(addProcessorAction);
			//connect 外部功能
		}

		editMenuItem->addSeparator();

		{
			//控制页面的清除
			auto clearLogAction = new QAction(tr("&Clear"), this);//consoleWidget_->getClearAction();
			actions_["Clear Log"] = clearLogAction;
			editMenuItem->addAction(clearLogAction);
		}

		// View
		{
			// dock widget visibility menu entries
			viewMenuItem->addAction(settingsWidget_->toggleViewAction());
			QDockWidget *processorTreeWidget_ = new QDockWidget(this);
			processorTreeWidget_->toggleViewAction()->setText(tr("&Processor List"));
			viewMenuItem->addAction(processorTreeWidget_->toggleViewAction());
			//propertyListWidget_->toggleViewAction()->setText(tr("&Property List"));
			//viewMenuItem->addAction(propertyListWidget_->toggleViewAction());
			//consoleWidget_->toggleViewAction()->setText(tr("&Output Console"));
			//viewMenuItem->addAction(consoleWidget_->toggleViewAction());
			//helpWidget_->toggleViewAction()->setText(tr("&Help"));
			//viewMenuItem->addAction(helpWidget_->toggleViewAction());
			//// Disabled until we figure out what we want to use it for //Peter
			//// viewMenuItem->addAction(resourceManagerWidget_->toggleViewAction());
		}
	}

	bool MyInvowo::askToSaveWorkspaceChanges()
	{
		return false;
	}
}