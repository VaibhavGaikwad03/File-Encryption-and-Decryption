#ifndef ENCDECLOGIC_H
#define ENCDECLOGIC_H

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

class EncryptionDecryption
{
    int m_iCountLines;
    const string m_strCheck;

public:
    EncryptionDecryption();
    int create_file(const string strFileName);
    int write_file(const string strFileName, const string strData, const int iAppend = 0, const int iNewLine = 0);
    int encrypt_data(const string strFileName, string strPassword);
    int decrypt_data(const string strFileName, const string strPassword);
    int delete_file(const string strFileName);
    bool is_exists(const string strFileName);

private:
    string set_password(string &strPassword);
    bool check_enc_dec(const string strFileName);
    bool check_password(const string strFileName, const string strPassword);
    string *read_file(const string strFileName);
};

#endif // !ENCDECLOGIC_H
