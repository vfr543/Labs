#include <iostream>
#include <vector>
#include <string>
using namespace std;
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
    
    int x = 0;
    int y = 0;
    int mxlen = 0;
    int mxcount = 0;
    int temp = 0;
    char mxch[50];
    char tmpch[50];
    for (int i = 0; i < 9; i++) {
        for (int j = i+1; j < 10; j++) {
            y = 0;
            x = 0;
            while (x < strlen(words[i])) {
                while (y < strlen(words[j])) {
                    if (words[i][x] == words[j][y]) {
                        tmpch[mxcount] = words[i][x];
                        mxcount++;
                        x++;
                        temp++;
                    }
                    else {
                        x -= temp;
                        temp = 0;
                        if (mxlen < mxcount) {
                            for (int r = 0; r < mxcount; r++) {
                                mxch[r] = tmpch[r];
                            }
                            mxlen = mxcount;
                        }
                        mxcount = 0;
                    }
                    y++;
                }
                x++;
            }
        }
    }
    cout << "Самая длинная общая подстрока между двумя словами в предложении: ";
    for (int n = 0; n < mxlen; n++) { cout << mxch[n] << ' '; }
    return 0;
}