#pragma once
#include <cctype>
#include <cmath>
#include <iostream>
#include <vector>
#include <locale>
using namespace std;

class Cipher
{
private:
    int key;

public:
    Cipher() = delete; // Запрет на создание объекта без ключа
    Cipher(int key)
        : key(key)
    {
    }

    wstring encrypt(const wstring& text);
    wstring decrypt(const wstring& text);
};