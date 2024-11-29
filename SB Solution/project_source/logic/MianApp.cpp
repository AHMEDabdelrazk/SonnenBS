#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include "QtManger.h"




int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	QtManger window;
	window.start_ui();
	//window.show();

	return app.exec();
}