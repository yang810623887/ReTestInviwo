#include "MyInvowo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyInvowo w;
	w.show();
	return a.exec();
}
