#ifndef CREATEPAGE_H
#define CREATEPAGE_H
#include "page.h"
#include "createdeletetemplate.h"
#include <QLineEdit>

class CreatePage : public CreateDeleteTemplate
{
	Q_OBJECT;
public:
	CreatePage(QWidget* parent = nullptr);
	~CreatePage();

private slots:
	void create_event();
	void back_event();

private:
	QPushButton* m_createb;
};

#endif // !CREATEPAGE_H
