#include "encdeclogic.h"
#include <cstdio>
#include <fstream>
#define MAXLINES 1000
using std::ifstream;
using std::ios;
using std::ofstream;
using std::streampos;

EncryptionDecryption::EncryptionDecryption() : m_strCheck("`i^]jn`o"), m_iCountLines(0) {}

int EncryptionDecryption::create_file(const string strFileName)
{
    if (strFileName == "")
        return -1;  // enter the file name

    if (is_exists(strFileName))
        return -2; // file already exists

    ofstream fcreate(strFileName);
    fcreate.close();

    return 0;
}

int EncryptionDecryption::write_file(const string strFileName, const string strData, const int iAppend, const int iNewLine)
{
    if (strFileName == "")
        return -1;  // enter the file name
    if (strData == "")
        return -2;  //enter the data
    if (!is_exists(strFileName))
        return -3; // file does not exists

    ofstream write;

    if (iAppend == 0)
        write.open(strFileName);
    else
        write.open(strFileName, ios::app);

    if (!write.is_open())
    {
        write.close();
        return -4; // file could not be opened
    }

    streampos currentpos = write.tellp();

    if (iNewLine == 0)
        write << strData + " ";
    else
        write << strData << endl;

    streampos finalpos = write.tellp();

    write.flush();
    write.close();

    return static_cast<int>(finalpos - currentpos - 1);
}

int EncryptionDecryption::encrypt_data(const string strFileName, string strPassword)
{
    int iCnt1 = 0, iCnt2 = 0;
    string* strData = NULL;
    string strLine = "";

    if (strFileName == "")
        return -1; // enter the file name

    if (strPassword == "")
        return -2; //enter the password

    if (strPassword.length() != 8)   //password should contains strictly 8 characters
        return -3;

    if (!is_exists(strFileName))
        return -4; // file does not exists

    if (check_enc_dec(strFileName))
        return -5; // file already encrypted

    set_password(strPassword);

    strData = read_file(strFileName);

    for (iCnt1 = 0; iCnt1 < m_iCountLines; iCnt1++)
    {
        strLine = strData[iCnt1];

        for (iCnt2 = 0; iCnt2 < strLine.length(); iCnt2 += 2)
            strLine[iCnt2] -= 5;
        for (iCnt2 = 1; iCnt2 < strLine.length(); iCnt2 += 2)
            strLine[iCnt2] += 3;

        if (iCnt1 == 0)
        {
            write_file(strFileName, m_strCheck + strPassword + strLine, 0, 1);
            continue;
        }
        write_file(strFileName, strLine, 1, 1);
    }
    return 0;
}

int EncryptionDecryption::decrypt_data(const string strFileName, const string strPassword)
{
    int iCnt1 = 0, iCnt2 = 0;
    string* strData = NULL;
    string strLine = "";

    if (strFileName == "")
        return -1; // enter the file name

    if (strPassword == "")
        return -2; //enter the password

    if (!is_exists(strFileName))
        return -3; // file does not exists

    if (!check_enc_dec(strFileName))
        return -4; // file already decrypted

    if (!check_password(strFileName, strPassword))
        return -5; // wrong password

    strData = read_file(strFileName);

    for (iCnt1 = 0; iCnt1 < m_iCountLines; iCnt1++)
    {
        strLine = strData[iCnt1];

        for (iCnt2 = 0; iCnt2 < strLine.length(); iCnt2 += 2)
            strLine[iCnt2] += 5;
        for (iCnt2 = 1; iCnt2 < strLine.length(); iCnt2 += 2)
            strLine[iCnt2] -= 3;

        if (iCnt1 == 0)
        {
            write_file(strFileName, strLine.substr(18), 0, 1);
            continue;
        }

        write_file(strFileName, strLine, 1, 1);
    }
    return 0;
}

string EncryptionDecryption::set_password(string& strPassword)
{
    int iCnt = 0;

    for (iCnt = 0; iCnt < strPassword.length(); iCnt += 2)
        strPassword[iCnt] += 3;
    for (iCnt = 1; iCnt < strPassword.length(); iCnt += 2)
        strPassword[iCnt] -= 3;

    return strPassword;
}

bool EncryptionDecryption::check_password(const string strFileName, const string strPassword)
{
    int iCnt = 0;
    string strCheckPass = "";

    ifstream checkpass(strFileName);
    getline(checkpass, strCheckPass);
    checkpass.close();

    strCheckPass = strCheckPass.substr(10, 8);

    for (iCnt = 0; iCnt < strCheckPass.length(); iCnt += 2)
        strCheckPass[iCnt] -= 3;
    for (iCnt = 1; iCnt < strCheckPass.length(); iCnt += 2)
        strCheckPass[iCnt] += 3;

    if (strCheckPass == strPassword)
        return true;
    return false;
}

bool EncryptionDecryption::check_enc_dec(const string strFileName)
{
    string strCheckEncDec = "";

    ifstream checkencdec(strFileName);
    getline(checkencdec, strCheckEncDec);
    checkencdec.close();

    strCheckEncDec = strCheckEncDec.substr(0, 10);

    if (strCheckEncDec == m_strCheck)
        return true;
    return false;
}

string* EncryptionDecryption::read_file(const string strFileName)
{
    int iCnt = 0;

    static string strReadFile[MAXLINES];

    ifstream readfile(strFileName);

    while (getline(readfile, strReadFile[iCnt]))
        iCnt++;

    m_iCountLines = iCnt;

    readfile.close();

    return strReadFile;
}

bool EncryptionDecryption::is_exists(const string strFileName)
{
    ifstream fcheck(strFileName);

    if (fcheck.is_open())
    {
        fcheck.close();
        return true;
    }
    fcheck.close();
    return false;
}

int EncryptionDecryption::delete_file(const string strFileName)
{
    if (strFileName == "")
        return -1; //enter the file name

    if (!is_exists(strFileName))
        return -2; // file does not exists

    if (remove(strFileName.c_str()))
        return -3; // can't delete file
    return 0;
}