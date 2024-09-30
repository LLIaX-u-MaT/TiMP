#include "modCipherBeta.h"

// проверка, чтобы строка состояла только из прописных букв
bool isValid(const wstring& s)
{
    for(auto c : s)
        if(!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int key;
    wstring text;
    unsigned op;
    do {
        wcout << L"Выберите операцию (0-выход, 1-шифрование, 2-расшифрование): ";
        wcin >> op;
        if(op > 2) {
            wcout << L"Неправильная операция\n";
        } else if(op > 0) {
            wcout << L"Введите текст: ";
            wcin >> text;
            wcout << L"Введите ключ: ";
            wcin >> key;
            if(key <= ceil(text.length() / 1)) {
                Cipher cipher(key);
                if(op == 1) {
                    wcout << L"Зашифрованный текст: " << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << endl;
                }
            } else {
                wcout << L"Неправильный ключ" << endl;
            }
        }
    } while(op != 0);
    return 0;
}