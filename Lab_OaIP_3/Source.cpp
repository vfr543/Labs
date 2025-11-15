#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

void toOut(const string& message) {
    ofstream outputFile("output.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << message << endl;
        outputFile.close();
    }
}

vector<Product> readFrFile() {
    vector<Product> products;
    ifstream inputFile("products.txt");

    if (inputFile.is_open()) {
        Product product;
        while (inputFile >> product.name >> product.price >> product.quantity) {
            products.push_back(product);
        }
        inputFile.close();
    }

    return products;
}

void writeToFile(const vector<Product>& products) {
    ofstream outputFile("products.txt");

    if (outputFile.is_open()) {
        for (const auto& product : products) {
            outputFile << product.name << " " << product.price << " " << product.quantity << endl;
        }
        outputFile.close();
    }
}

void fillFile() {
    ofstream file("products.txt");
    vector<Product> products;

    cout << "Введите данные о продуктах (для завершения введите пустую строку в названии):" << endl;
    toOut("Создание и заполнение файла продуктами:");

    while (true) {
        Product product;

        cout << "Название продукта: ";
        getline(cin, product.name);

        if (product.name.empty()) {
            break;
        }

        cout << "Цена: ";
        cin >> product.price;
        cout << "Количество: ";
        cin >> product.quantity;
        cin.ignore();
        products.push_back(product);
        string message = "Добавлен продукт: " + product.name + ", цена: " +
            to_string(product.price) + ", количество: " +
            to_string(product.quantity);
        toOut(message);

        cout << "Продукт добавлен!" << endl;
    }

    writeToFile(products);
    toOut("Файл products.txt успешно создан и заполнен.");
    cout << "Файл products.txt успешно создан и заполнен." << endl;
}

void searchByName() {
    string searchName;
    cout << "Введите название продукта для поиска: ";
    getline(cin, searchName);
    vector<Product> products = readFrFile();
    bool found = false;
    toOut("Поиск продукта по названию: " + searchName);

    for (const auto& product : products) {
        if (product.name == searchName) {
            cout << "Найден продукт: " << product.name
                << ", цена: " << product.price
                << ", количество: " << product.quantity << endl;

            string message = "Найден продукт: " + product.name +
                ", цена: " + to_string(product.price) +
                ", количество: " + to_string(product.quantity);
            toOut(message);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Продукт с названием '" << searchName << "' не найден." << endl;
        toOut("Продукт не найден.");
    }
}

bool byPr(const Product& a, const Product& b) {
    return a.price < b.price;
}

bool byQu(const Product& a, const Product& b) {
    return a.quantity < b.quantity;
}

void sortProducts() {
    int choice;
    cout << "Выберите критерий сортировки:" << endl;
    cout << "1 - по цене" << endl;
    cout << "2 - по количеству" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;
    cin.ignore();

    vector<Product> products = readFrFile();

    if (choice == 1) {
        sort(products.begin(), products.end(), byPr);
        toOut("Сортировка продуктов по цене.");
        cout << "Продукты отсортированы по цене." << endl;
    }
    else if (choice == 2) {
        sort(products.begin(), products.end(), byQu);
        toOut("Сортировка продуктов по количеству.");
        cout << "Продукты отсортированы по количеству." << endl;
    }
    else {
        cout << "Неверный выбор!" << endl;
        toOut("Неверный выбор сортировки.");
        return;
    }

    writeToFile(products);
    cout << "Отсортированный список:" << endl;
    toOut("Отсортированный список продуктов:");
    for (const auto& product : products) {
        cout << product.name << " - Цена: " << product.price
            << " Количество: " << product.quantity << endl;

        string message = product.name + " - Цена: " + to_string(product.price) +
            " Количество: " + to_string(product.quantity);
        toOut(message);
    }
}

void addToFile() {
    Product product;

    cout << "Введите данные о новом продукте:" << endl;
    cout << "Название: ";
    getline(cin, product.name);
    cout << "Цена: ";
    cin >> product.price;
    cout << "Количество: ";
    cin >> product.quantity;
    cin.ignore();
    vector<Product> products = readFrFile();
    products.push_back(product);
    writeToFile(products);
    string message = "Добавлен новый продукт: " + product.name +
        ", цена: " + to_string(product.price) +
        ", количество: " + to_string(product.quantity);
    toOut(message);

    cout << "Продукт успешно добавлен!" << endl;
}

void showByPrice() {
    double maxPrice;
    cout << "Введите максимальную цену: ";
    cin >> maxPrice;
    cin.ignore();

    vector<Product> products = readFrFile();
    bool found = false;

    string message = "Поиск продуктов с ценой не более: " + to_string(maxPrice);
    toOut(message);

    cout << "Продукты с ценой не более " << maxPrice << ":" << endl;

    for (const auto& product : products) {
        if (product.price <= maxPrice) {
            cout << product.name << " - Цена: " << product.price
                << " Количество: " << product.quantity << endl;

            string outputMsg = product.name + " - Цена: " + to_string(product.price) +
                " Количество: " + to_string(product.quantity);
            toOut(outputMsg);
            found = true;
        }
    }

    if (!found) {
        cout << "Продукты с ценой не более " << maxPrice << " не найдены." << endl;
        toOut("Продукты не найдены.");
    }
}

void writeAllPr() {
    vector<Product> products = readFrFile();

    if (products.empty()) {
        cout << "Файл products.txt пуст или не существует." << endl;
        toOut("Попытка вывода всех продуктов: файл пуст или не существует.");
        return;
    }

    cout << "Все продукты:" << endl;
    toOut("Вывод всех продуктов:");

    for (const auto& product : products) {
        cout << product.name << " - Цена: " << product.price
            << " Количество: " << product.quantity << endl;

        string message = product.name + " - Цена: " + to_string(product.price) +
            " Количество: " + to_string(product.quantity);
        toOut(message);
    }
}

void showMenu() {
    cout << "\n=== Меню управления продуктами ===" << endl;
    cout << "1 - Создание и заполнение файла продуктами" << endl;
    cout << "2 - Поиск продукта по названию" << endl;
    cout << "3 - Сортировка продуктов" << endl;
    cout << "4 - Добавление нового продукта" << endl;
    cout << "5 - Вывод продуктов по максимальной цене" << endl;
    cout << "6 - Вывод всех продуктов" << endl;
    cout << "0 - Выход" << endl;
    cout << "Выберите действие: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    ofstream clearFile("output.txt");
    clearFile.close();

    toOut("Программа запущена.");

    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            fillFile();
            break;
        case 2:
            searchByName();
            break;
        case 3:
            sortProducts();
            break;
        case 4:
            addToFile();
            break;
        case 5:
            showByPrice();
            break;
        case 6:
            writeAllPr();
            break;
        case 0:
            toOut("Программа завершена.");
            break;
        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
            toOut("Неверный выбор в меню.");
            break;
        }

    } while (choice != 0);

    return 0;
}