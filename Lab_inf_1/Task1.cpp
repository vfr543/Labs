#include <iostream>

int main()
{
    double t;
    setlocale(LC_ALL, "Rus");
    std::cout << L"Введите температуру: ";
    std::cin >> t;
    if (t < 0) {
        std::cout << L"Наденьте зимнюю одежду" << std::endl;
    }
    else if (t >= 0 && t <= 10) {
        std::cout << L"Наденьте тёплую одежду" << std::endl;
    }
    else if (t > 10 && t <= 20) {
        std::cout << L"Наденьте лёгкую одежду" << std::endl;
    }
    else {
        std::cout << L"Наденьте летнюю одежду" << std::endl;
    }
    return 0;

}
