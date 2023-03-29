#ifndef DECRYPTPAGE_H
#define DECRYPTPAGE_H

#include "page.h"
#include "encdectemplate.h"
#include <QLineEdit>

class MenuPage;

class DecryptPage : public EncDecTemplate
{
	Q_OBJECT

public:
	DecryptPage(QWidget* parent = nullptr);
	~DecryptPage();

private slots:
	void decrypt_event();
	void back_event();
private:
	QPushButton* m_decryptb;
	MenuPage* menupage;
};

#endif//DECRYPTPAGE_H