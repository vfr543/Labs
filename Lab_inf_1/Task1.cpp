#include <iostream>

int main()
{
    double t;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите температуру: ";
    std::cin >> t;
    if (t < 0) {
        std::cout << "Наденьте зимнюю одежду" << std::endl;
    }
    else if (t >= 0 && t <= 10) {
        std::cout << "Наденьте тёплую одежду" << std::endl;
    }
    else if (t > 10 && t <= 20) {
        std::cout << "Наденьте лёгкую одежду" << std::endl;
    }
    else {
        std::cout << "Наденьте летнюю одежду" << std::endl;
    }
    return 0;

}


