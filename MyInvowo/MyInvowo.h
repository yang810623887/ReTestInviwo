#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MyInvowo.h"
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qaction.h>
#include <unordered_map>
#include <QDockWidget>

namespace myviwo {
	class Mysettingswidget;

	class MyInvowo : public QMainWindow
	{
		Q_OBJECT

	public:
		static const unsigned int maxNumRecentFiles_ = 10;
		MyInvowo(QWidget *parent = Q_NULLPTR);

	private:
		Ui::MyInvowoClass ui;

	public slots:
		void newWorkspace();
		void openWorkSpace();
		void openRecentWorkspace();
		///**
		//* \brief clear the recent file list in the menu
		//*/
		void clearRecentWorkspaceMenu();
		//void openExampleWorkspace();
		void saveWorkspace();
		void saveWorkspaceAs();
		///*
		//* Save the current workspace into a new workspace file,
		//* leaves the current workspace file as current workspace
		//*/
		void saveWorkspaceAsCopy();
		//void exitInviwo(bool saveIfModified = true);
		//void showAboutBox();


		void fillExampleWorkspaceMenu();
		void fillTestWorkspaceMenu();

	private:
		void openWorkspace(QString workspaceFileName, bool exampleWorkspace);
		void saveWorkspace(QString workspaceFileName);

		void addActions();

		void closeEvent();

		bool askToSaveWorkspaceChanges();

		// toolbar
		QToolBar* basicToolbar_;

		// dock widgets
		Mysettingswidget* settingsWidget_;

		// menu actions
		std::unordered_map<std::string, QAction*> actions_;

		std::vector<QAction*> workspaceActionRecent_;
		QAction* clearRecentWorkspaces_;


		QMenu* exampleMenu_ = nullptr;
		QMenu* testMenu_ = nullptr;

		//setting

		//paths
		QString currentWorkspaceFileName_;


		//UndoManager undoManager_;

	};
}