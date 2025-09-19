#include <iostream>
int minEl(int a[], int n);
int main() {
	int mas[10], sum = 0;
	setlocale(LC_ALL, "");


	for (int i = 0; i < 10; i++) {
		std::wcout << L"������� ������� " << i + 1 << ":";
		std::cin >> mas[i];
		sum += mas[i];
	}
	std::wcout << L"������: ";
	for (int i = 0; i < 10; i++) {
		std::cout << mas[i] << ' ';
	}
	std::wcout << std::endl << L"�����: " << sum << std::endl;
	std::wcout << L"����������� �������: " << minEl(mas, 0) << std::endl;
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 9; j++) {
			if (minEl(mas, i) == mas[j + 1]) {
				std::swap(mas[i], mas[j + 1]);
			}
		}
	}
	std::wcout << L"��������������� ������: ";
	for (int i = 0; i < 10; i++) {
		std::cout << mas[i] << ' ';
	}
	return 0;
}
int minEl(int a[], int n) {
	int min = 1000000;
	for (int i = n; i < 10; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}