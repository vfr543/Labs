#include <iostream>

int main()
{
    double t;
    setlocale(LC_ALL, "");
    std::wcout << L"������� ������� �����������: ";
    std::cin >> t;
    if (t < 0) {
        std::wcout << L"�������� ������ ������" << std::endl;
    }
    else if (t >= 0 && t <= 10) {
        std::wcout << L"�������� ����� ������" << std::endl;
    }
    else if (t > 10 && t <= 20) {
        std::wcout << L"�������� ����� ������" << std::endl;
    }
    else {
        std::wcout << L"�������� ������ ������" << std::endl;
    }
    return 0;
}