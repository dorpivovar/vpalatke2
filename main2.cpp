
#include <iostream>
using namespace std;

int main() {
    int choice;
    double temperature, result;
    
    cout << "Конвертер температуры" << endl;
    cout << "1. Цельсий -> Фаренгейт" << endl;
    cout << "2. Фаренгейт -> Цельсий" << endl;
    cout << "Выберите действие (введите 1 или 2): ";
    cin >> choice;
    
    if (choice == 1) {
        cout << "Введите температуру в градусах Цельсия: ";
        cin >> temperature;
        result = temperature * 9.0/5.0 + 32;
        cout << temperature << " °C = " << result << " °F" << endl;
    }
    else if (choice == 2) {
        cout << "Введите температуру в градусах Фаренгейта: ";
        cin >> temperature;
        result = (temperature - 32) * 5.0/9.0;
        cout << temperature << " °F = " << result << " °C" << endl;
    }
    else {
        cout << "Ошибка: неверный выбор действия" << endl;
    }
    
    return 0;
}