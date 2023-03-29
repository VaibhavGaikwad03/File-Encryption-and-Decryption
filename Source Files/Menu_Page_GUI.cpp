#include "menupage.h"
#include "createpage.h"
#include <QMessageBox>
#include <string>
using std::string;

MenuPage::MenuPage(QWidget *parent) : Page(parent)
{
    string strLabel = "Hello Welcome, Select one of the following options : ";
    m_label = new QLabel(strLabel.c_str(), this);
    m_createb = new QPushButton("Create File", this);
    m_writeb = new QPushButton("Write File", this);
    m_encryptb = new QPushButton("Encrypt File", this);
    m_decryptb = new QPushButton("Decrypt File", this);
    m_deleteb = new QPushButton("Delete File", this);
    m_exitb = new QPushButton("Exit", this);
    QFont font("Verdana", 10);
    QFontMetrics metrics(font);
    m_label->setFont(font);

    m_label->setGeometry(125, 150, metrics.horizontalAdvance(strLabel.c_str()), metrics.height());
    m_createb->setGeometry(175, 200, 100, 30);
    m_writeb->setGeometry(325, 200, 100, 30);
    m_encryptb->setGeometry(175, 250, 100, 30);
    m_decryptb->setGeometry(325, 250, 100, 30);
    m_deleteb->setGeometry(175, 300, 100, 30);
    m_exitb->setGeometry(325, 300, 100, 30);

    connect(m_createb, &QPushButton::clicked, this, &MenuPage::create_event);
    connect(m_writeb, &QPushButton::clicked, this, &MenuPage::write_event);
    connect(m_encryptb, &QPushButton::clicked, this, &MenuPage::encrypt_event);
    connect(m_decryptb, &QPushButton::clicked, this, &MenuPage::decrypt_event);
    connect(m_deleteb, &QPushButton::clicked, this, &MenuPage::delete_event);
    connect(m_exitb, &QPushButton::clicked, this, &MenuPage::exit_event);
}

void MenuPage::create_event()
{
    createpage = new CreatePage();
    createpage->show();
    this->hide();
}
void MenuPage::write_event()
{
    writepage = new WritePage();
    writepage->show();
    this->hide();
}

void MenuPage::encrypt_event()
{
    encryptpage = new EncryptPage();
    encryptpage->show();
    this->hide();
}

void MenuPage::decrypt_event()
{
    decryptpage = new DecryptPage();
    decryptpage->show();
    this->hide();
}

void MenuPage::delete_event()
{
    deletepage = new DeletePage();
    deletepage->show();
    this->hide();
}

void MenuPage::exit_event()
{
    QMessageBox::StandardButton response;
    response = QMessageBox::question(this, "Confirmation", "Are you sure you want to exit ?", QMessageBox::Yes | QMessageBox::No);
    if (response == QMessageBox::Yes)
        exit(0);
}

MenuPage::~MenuPage()
{/*
    delete m_label;
    delete m_createb;
    delete m_writeb;
    delete m_encryptb;
    delete m_decryptb;
    delete m_deleteb;
    delete m_exitb;*/
}