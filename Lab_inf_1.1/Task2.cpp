#include <iostream>

int main() {
    int stop, sum = 0;
    setlocale(LC_ALL, "");
    std::wcout << L"������� ���-�� ��������� �� ��������: ";
    std::cin >> stop;
    for (int i = 0; i < stop; i++) {
        sum += 5;
    }
    std::wcout << L"����� �� �������: ";
    std::cout << sum << std::endl;
    return 0;
}