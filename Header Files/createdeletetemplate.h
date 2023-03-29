#ifndef CREATEDELETETEMPLATE_H
#define CREATEDELETETEMPLATE_H

#include "page.h"
#include <QLineEdit>

class CreateDeleteTemplate : public Page
{
public:
	CreateDeleteTemplate(QWidget* parent = nullptr);
	~CreateDeleteTemplate();

protected:
	QLabel* m_label;
	QLineEdit* m_textbox;
	QPushButton* m_backb;
};

#endif // !CREATEDELETETEMPLATE_H
