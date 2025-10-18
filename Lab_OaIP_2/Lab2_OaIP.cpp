#include <iostream>
#include <vector>
#include <string>
using namespace std;
void longestCommonSubstring(const char* str1, const char* str2, char* result, int resultSize) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int maxLen = 0;
    int startPos = 0;
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {

                int k = 0;
                while (i + k < len1 && j + k < len2 && str1[i + k] == str2[j + k]) {
                    k++;
                }

                if (k > maxLen) {
                    maxLen = k;
                    startPos = i;
                }
            }
        }
    }

    if (maxLen > 0) {
        int copyLen = (maxLen < resultSize - 1) ? maxLen : resultSize - 1;
        strncpy_s(result, resultSize, &str1[startPos], copyLen);
        result[copyLen] = '\0';
    }
    else {
        result[0] = '\0';
    }
}


int splitString(const char* str, char words[][50]) {
    int wCount = 0;
    int charInd = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0' && wCount < 10; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            if (!inWord) {
                inWord = true;
                charInd = 0;
            }
            words[wCount][charInd++] = str[i];
        }
        else {
            if (inWord) {
                words[wCount][charInd] = '\0';
                wCount++;
                inWord = false;
            }
        }
    }
    if (inWord && wCount < 10) {
        words[wCount][charInd] = '\0';
        wCount++;
    }
    return wCount;
}

int main() {
    setlocale(LC_ALL, "Russian");
    char inp[500];
    char words[10][50];
    cout << "Введите 10 слов на латинице ";
    cin.getline(inp, 500);
    int wCount = splitString(inp, words);
    if (wCount < 10) {
        cout << "Слов меньше 10";
    }
    int countb = 0;
    for (int i = 0; i < wCount; i++) {
        int len = strlen(words[i]);
        if (len > 0 && words[i][len - 1] == 'b') {
            countb++;
        }
    }
    cout << "Кол-во слов, оканчивающихся на b: " << countb << endl;
    int maxlen = 0;
    for (int i = 0; i < wCount; i++) {
        int len = strlen(words[i]);
        if (len > maxlen) {
            maxlen = len;
        }
    }
    cout << "Длина самого длинного слова: " << maxlen << endl;
    char* lastWord = words[wCount - 1];
    int countd = 0;
    for (int i = 0; lastWord[i] != '\0'; i++) {
        if (lastWord[i] == 'd') {
            countd++;
        }
    }
    cout << "Количество букв d в последнем слове: " << countd << endl;
    char upwords[500];
    strcpy_s(upwords, inp);
    for (int i = 0; upwords[i] != '\0'; i++) {
        upwords[i] = toupper(upwords[i]);
    }
    cout << "Строка в верхнем регистре: " << upwords << endl;
    int count = 0;
    for (int i = 0; i < wCount; i++) {
        int len = strlen(words[i]);
        if (len >= 4) {
            if (words[i][1] == words[i][len - 2]) {
                count++;
            }
        }
    }
    cout << "Количество слов, у которых совпадает второй и предпоследний символ: " << count << endl;
    char longestCommon[50] = "";
    for (int i = 0; i < wCount; i++) {
        for (int j = i + 1; j < wCount; j++) {
            char common[50];
            longestCommonSubstring(words[i], words[j], common, 50);

            if (strlen(common) > strlen(longestCommon)) {
                strcpy_s(longestCommon, common);
            }
        }
    }
    cout << "Самая длинная общая подстрока между двумя словами в предложении: " << longestCommon << endl;
    return 0;
}
