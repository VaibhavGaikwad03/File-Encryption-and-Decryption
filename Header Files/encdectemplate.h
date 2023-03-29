#ifndef ENCDECTEMPLATE_H
#define ENCDECTEMPLATE_H

#include "page.h"
#include <QLineEdit>

class EncDecTemplate : public Page
{
public:
	EncDecTemplate(QWidget* parent = nullptr);
	~EncDecTemplate();

protected:
	QLabel* m_label1;
	QLabel* m_label2;
	QLineEdit* m_textbox1;
	QLineEdit* m_passbox2;
	QPushButton* m_backb;
};

#endif // !ENCDECTEMPLATE_H
