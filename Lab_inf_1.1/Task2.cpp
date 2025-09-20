#include <iostream>

int main() {
    int stop, sum = 0;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите количество остановок: ";
    std::cin >> stop;
    for (int i = 0; i < stop; i++) {
        sum += 5;
    }
    std::cout << "Стоимость проезда: ";
    std::cout << sum << std::endl;
    return 0;

}

