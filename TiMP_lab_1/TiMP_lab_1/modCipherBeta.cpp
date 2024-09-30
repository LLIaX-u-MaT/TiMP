#include "modCipherBeta.h"

wstring Cipher::encrypt(const wstring& text)
{
    int k = 0;
    int len = text.length();
    int rows = ceil(static_cast<double>(len) / key); // Учитываем возможный остаток
    vector<vector<wchar_t>> tabl(rows, vector<wchar_t>(key, L'\0'));

    // Заполнение таблицы по горизонтали слева направо
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < key; j++) {
            if(k < len) {
                tabl[i][j] = text[k++];
            }
        }
    }

    wstring result;
    // Считывание зашифрованного текста сверху вниз, справа налево
    for(int j = key - 1; j >= 0; j--) {
        for(int i = 0; i < rows; i++) {
            if(tabl[i][j] != L'\0') { // Игнорируем нулевые символы
                result += tabl[i][j];
            }
        }
    }
    return result;
}

wstring Cipher::decrypt(const wstring& text)
{
    int len = text.length();
    int rows = ceil(static_cast<double>(len) / key); // Количество строк
    vector<vector<wchar_t>> tabl(rows, vector<wchar_t>(key, L'\0'));

    // Заполнение таблицы по вертикали (сначала заполняем столбцы)
    int k = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < key; j++) {
            if(k < len) {
                tabl[i][j] = text[k++];
            }
        }
    }

    wstring result;
    // Считывание расшифрованного текста по горизонтали слева направо
    for(int j = 0; j < key; j++) {
        for(int i = 0; i < rows; i++) {
            if(tabl[i][j] != L'\0') { // Игнорируем нулевые символы
                result += tabl[i][j];
            }
        }
    }
    return result;
}
