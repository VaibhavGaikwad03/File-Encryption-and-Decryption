#ifndef PAGE_H
#define PAGE_H


#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushbutton>

class Page : public QWidget
{
	Q_OBJECT

public:
	Page(QWidget* parent = nullptr);

protected:
	QLabel* m_imagelabel;
};

#endif //PAGE_H