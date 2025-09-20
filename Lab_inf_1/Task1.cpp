#include <iostream>

int main()
{
    double t;
    setlocale(LC_ALL, "");
    std::wcout << L"Введите температуру: ";
    std::cin >> t;
    if (t < 0) {
        std::wcout << L"Наденьте зимнюю одежду" << std::endl;
    }
    else if (t >= 0 && t <= 10) {
        std::wcout << L"Наденьте тёплую одежду" << std::endl;
    }
    else if (t > 10 && t <= 20) {
        std::wcout << L"Наденьте лёгкую одежду" << std::endl;
    }
    else {
        std::wcout << L"Наденьте летнюю одежду" << std::endl;
    }
    return 0;

}

