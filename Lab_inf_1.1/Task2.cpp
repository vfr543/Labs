#include <iostream>

int main() {
    int stop, sum = 0;
    setlocale(LC_ALL, "");
    std::wcout << L"¬ведите кол-во остановок на маршруте: ";
    std::cin >> stop;
    for (int i = 0; i < stop; i++) {
        sum += 5;
    }
    std::wcout << L"—умма за поездку: ";
    std::cout << sum << std::endl;
    return 0;
}