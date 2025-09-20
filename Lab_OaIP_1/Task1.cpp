#include <iostream>
int minEl(int a[], int n);
int main() {
	int mas[10], sum = 0;
	setlocale(LC_ALL, "Rus");


	for (int i = 0; i < 10; i++) {
		std::cout << L"Ââåäèòå ýëåìåíò " << i + 1 << ":";
		std::cin >> mas[i];
		sum += mas[i];
	}
	std::cout << L"Ìàññèâ: ";
	for (int i = 0; i < 10; i++) {
		std::cout << mas[i] << ' ';
	}
	std::cout << std::endl << L"Ñóììà: " << sum << std::endl;
	std::cout << L"Ìèíèìàëüíûé ýëåìåíò: " << minEl(mas, 0) << std::endl;
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 9; j++) {
			if (minEl(mas, i) == mas[j + 1]) {
				std::swap(mas[i], mas[j + 1]);
			}
		}
	}
	std::cout << L"Îòñîðòèðîâàííûé ìàññèâ: ";
	for (int i = 0; i < 10; i++) {
		std::cout << mas[i] << ' ';
	}
	return 0;
}
int minEl(int a[], int n) {
	int min = a[0];
	for (int i = n; i < 10; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;

}

