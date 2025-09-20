#include <iostream>
int minEl(int a[], int n);
int main() {
	int mas[10], sum = 0;
	setlocale(LC_ALL, "Russian");


	for (int i = 0; i < 10; i++) {
		std::cout << "Введите элемент " << i + 1 << ":";
		std::cin >> mas[i];
		sum += mas[i];
	}
	std::cout << "Массив: ";
	for (int i = 0; i < 10; i++) {
		std::cout << mas[i] << ' ';
	}
	std::cout << std::endl << "Сумма: " << sum << std::endl;
	std::cout << "Минимальный элемент: " << minEl(mas, 0) << std::endl;
	for (int i = 0; i < 9; i++) {
		for (int j = i; j < 9; j++) {
			if (minEl(mas, i) == mas[j + 1]) {
				std::swap(mas[i], mas[j + 1]);
			}
		}
	}
	std::cout << "Отсортированный массив: ";
	for (int i = 0; i < 10; i++) {
		std::cout << mas[i] << ' ';
	}
	return 0;
}
int minEl(int a[], int n) {
	int min = a[n];
	for (int i = n; i < 10; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;

}


