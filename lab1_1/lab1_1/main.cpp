#include "modAlphaCipher.h"
#include <iostream>
#include <locale>
using namespace std;
void check(const wstring& Text, const wstring& key)
{
    wstring cipherText;
    wstring decryptedText;
    modAlphaCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    wcout << L"ключ=" << key << endl;
    wcout << Text << endl;
    wcout << cipherText << endl;
    wcout << decryptedText << endl;
    if(Text == decryptedText)
        wcout << L"Ок\n";
    else
        wcout << L"Ошибка\n";
}
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    check(L"БЫСТРОНОГАЯЛИСИЦАПРЫГАЕТНАЛЕНИВОГОПСА", L"ПРОСТО");
    check(L"БЫСТРОНОГАЯЛИСИЦАПРЫГАЕТНАЛЕНИВОГОПСА", L"ПРИМЕР");
    check(L"БЫСТРОНОГАЯЛИСИЦАПРЫГАЕТНАЛЕНИВОГОПСА", L"АБВГ");
    return 0;
}