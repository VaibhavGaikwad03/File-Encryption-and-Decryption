#include "menupage.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	MenuPage window;
	window.show();

	return a.exec();
}