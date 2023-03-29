#ifndef WRITEPAGE_H
#define WRITEPAGE_H

#include <QLineEdit>
#include "page.h"
#include "menupage.h"
#include <QLabel>

class MenuPage;

class WritePage : public Page
{
	Q_OBJECT
public:
	WritePage(QWidget *parent = nullptr);
	~WritePage();
private slots:
	void write_event();
	void back_event();

private:
	QLabel* m_label1;
	QLabel* m_label2;
	QLineEdit* m_textbox1;
	QLineEdit* m_textbox2;
	QPushButton* m_writefileb;
	QPushButton* m_backb;
	MenuPage* menupage;
};

#endif // !WRITEPAGE_H
