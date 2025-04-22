#include <iostream>
#include <string>

using namespace std;

struct Pet {
    int hunger;    
    int happiness;  
    int hp;
    string name;
};

void displayPetState(const Pet& pet) {
    cout << "Состояние питомца " << pet.name << ":\n";
    cout << "Сытость: " << pet.hunger << "/100\n";
    cout << "Счастье: " << pet.happiness << "/100\n";
    cout << "Здоровье: " << pet.hp << "/100\n";
    cout << std::endl;
}

void feedPet(Pet& pet) {
    pet.hunger += 15;
    if (pet.hunger > 100) {
        pet.hunger = 100;
    }
    pet.happiness += 5;
    if (pet.happiness > 100) {
        pet.happiness = 100;
    }
    std::cout << "Вы покормили " << pet.name << "!\n";
    displayPetState(pet);
}

void playWithPet(Pet& pet) {
    pet.happiness += 15;
    if (pet.happiness > 100) {
        pet.happiness = 100;
    }
    pet.hunger -= 10;
    if (pet.hunger < 0) {
        pet.hunger = 0;
    }
    cout << "Вы поиграли с " << pet.name << "!\n";
    displayPetState(pet);
}

void ZhahnutPet(Pet& pet) {
    pet.hp = 0;
    pet.happiness = 0;
    pet.hunger = 0;
    cout << pet.name << " умер...";
}

int main() {
    Pet myPet = {50, 50, 100, "Пушистик"};
    
    int choice;
    
    cout << "Добро пожаловать в симулятор виртуального питомца!\n";
    cout << "У вас есть питомец по имени " << myPet.name << ".\n";
    
    while (true) {
        displayPetState(myPet);
        cout << "Что вы хотите сделать?\n";
        cout << "1. Покормить " << myPet.name << endl;
        cout << "2. Поиграть с " << myPet.name << endl;
        cout << "3. Прописать вертуху " << myPet.name << endl;
        cout << "4. Выйти\n";
        cout << "Ваш выбор: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                feedPet(myPet);
                break;
            case 2:
                playWithPet(myPet);
                break;
            case 3:
                ZhahnutPet(myPet);
                return 0;
            case 4:
                cout << "До свидания!\n";
                return 0;
            default:
                cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    }
    
    return 0;
}
