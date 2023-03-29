#ifndef ENCRYPTPAGE_H
#define ENCRYPTPAGE_H

#include "menupage.h"
#include "encdectemplate.h"
#include <QLineEdit>

class MenuPage;

class EncryptPage : public EncDecTemplate
{
	Q_OBJECT
public:
	EncryptPage(QWidget* parent = nullptr);
	~EncryptPage();
private slots:
	void encrypt_event();
	void back_event();
private:
	QPushButton* m_encryptb;
	MenuPage* menupage;
};

#endif // !ENCRYPTPAGE_H
