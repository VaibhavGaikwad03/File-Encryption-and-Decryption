#ifndef DELETEPAGE_H
#define DELETEPAGE_H

#include "createdeletetemplate.h"
#include "menupage.h"

class MenuPage;

class DeletePage : public CreateDeleteTemplate
{
	Q_OBJECT

public:
	DeletePage(QWidget* parent = nullptr);
	~DeletePage();

private slots:
	void delete_event();
	void back_event();

private:
	QPushButton* m_deleteb;
	MenuPage* menupage;
};

#endif // !DELETEPAGE_H
