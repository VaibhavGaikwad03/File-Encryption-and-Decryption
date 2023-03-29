#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushbutton>
#include "page.h"
#include "createpage.h"
#include "writepage.h"
#include "encryptpage.h"
#include "decryptpage.h"
#include "deletepage.h"

class WritePage;
class EncryptPage;
class DecryptPage;
class DeletePage;

class MenuPage : public Page
{
	Q_OBJECT;

public:
	MenuPage(QWidget* parent = nullptr);
	~MenuPage();

private slots:
	void create_event();
	void write_event();
	void encrypt_event();
	void decrypt_event();
	void delete_event();
	void exit_event();

private:
	QLabel *m_label;
	QPushButton *m_createb;
	QPushButton *m_writeb;
	QPushButton *m_encryptb;
	QPushButton *m_decryptb;
	QPushButton *m_deleteb;
	QPushButton *m_exitb;
	CreatePage *createpage;
	WritePage* writepage;
	EncryptPage* encryptpage;
	DecryptPage* decryptpage;
	DeletePage* deletepage;
};

#endif //MENUPAGE_H