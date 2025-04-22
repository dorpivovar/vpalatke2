#include <iostream>
#include <string>
#include <fstream> 

using namespace std;



struct Pet {
    int hunger;    
    int happiness;  
    int hp;        
    int level;     
    int experience; 
    string mood;   
    string name = "Пушистик";  
};

void updateMood(Pet& pet) {
    if (pet.hunger < 20 || pet.happiness < 20) {
        pet.mood = "Несчастный";
    } else if (pet.hunger < 50 || pet.happiness < 50) {
        pet.mood = "Грустный";
    } else if (pet.hunger >= 80 && pet.happiness >= 80) {
        pet.mood = "Восторженный";
    } else {
        pet.mood = "Довольный";
    }
}

void developPet(Pet& pet) {
    int expGain = (pet.hunger + pet.happiness) / 10;
    pet.experience += expGain;
    
    if (pet.experience >= 100) {
        pet.level++;
        pet.experience -= 100;
        cout << pet.name << " достиг уровня " << pet.level << "!" << endl;
    }
}

void savePetToFile(const Pet& pet, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << pet.name << endl;
        file << pet.hunger << endl;
        file << pet.happiness << endl;
        file << pet.hp << endl;
        file << pet.level << endl;
        file << pet.experience << endl;
        file << pet.mood << endl;
        file.close();
        cout << "Питомец сохранен в файл " << filename << endl;
    } else {
        cout << "Ошибка при сохранении файла" << endl;
    }
}


void displayPetState(const Pet& pet) {
    cout << "Состояние питомца " << pet.name << ":" << endl;
    cout << "Сытость: " << pet.hunger << "/100"<< endl;
    cout << "Счастье: " << pet.happiness << "/100" << endl;
    cout << "Здоровье: " << pet.hp << "/100" << endl;
    cout << "Уровень: " << pet.level << endl;
    cout << "Настроение: " << pet.mood << endl;
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
    updateMood(pet);
    developPet(pet);
    std::cout << "Вы покормили " << pet.name << "!" << endl;
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
    updateMood(pet);
    developPet(pet);
    cout << "Вы поиграли с " << pet.name << "!" << endl;
    displayPetState(pet);
}

void ZhahnutPet(Pet& pet) {
    pet.hp = 0;
    pet.happiness = 0;
    pet.hunger = 0;
    cout << pet.name << " умер...";
}

int main() {
    Pet myPet = {50, 50, 100, 1, 0, "Довольный", "Пушистик"};
    
    int choice;
    
    cout << "Добро пожаловать в симулятор виртуального питомца!" << endl;
    cout << "У вас есть питомец по имени " << myPet.name << "." << endl;
    
    while (true) {
        updateMood(myPet);
        displayPetState(myPet);
        cout << "Что вы хотите сделать?" << endl;
        cout << "1. Покормить " << myPet.name << endl;
        cout << "2. Поиграть с " << myPet.name << endl;
        cout << "3. Прописать вертуху " << myPet.name << endl;
        cout << "4. Сохранить питомца в файл" << endl;
        cout << "5. Выйти" << endl;
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
            case 4: {
                string filename;
                cout << "Введите имя файла для сохранения (или нажмите Enter для использования имени по умолчанию pet_save.txt): ";
                cin.ignore();
                getline(cin, filename);
                
                if (filename.empty()) {
                    filename = "pet_save.txt";
                }
                
                savePetToFile(myPet, filename);
                break;
            }
            case 5:
                cout << "До свидания!" << endl;
                return 0;
            default:
                cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    }
    
    return 0;
}
