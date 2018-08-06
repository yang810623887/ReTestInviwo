#include "MyInvowo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	myviwo::MyInvowo w;
	w.show();
	return a.exec();
}
