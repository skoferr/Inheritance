#include <iostream>
#include <string>
using namespace std;

class Animal 
{
protected:
    string name;

public:
    Animal(string animalName) {
        name = animalName;
    }

    virtual void makeNoise() {
        cout << "Животное издает звук" << endl;
    }

    virtual void eat() {
        cout << "Животное питается" << endl;
    }

    virtual string getDescription() {
        return "Это животное";
    }

    string getName() {
        return name;
    }
};

class Dog : public Animal 
{
public:
    Dog(string dogName) : Animal(dogName) {}

    void makeNoise() override {
        cout << "Собака гавкает" << endl;
    }

    void eat() override {
        cout << "Собака ест кость" << endl;
    }

    string getDescription() override {
        return "Это собака";
    }
};

class Cat : public Animal 
{
public:
    Cat(string catName) : Animal(catName) {}

    void makeNoise() override {
        cout << "Кошка мяукает" << endl;
    }

    void eat() override {
        cout << "Кошка ест рыбу" << endl;
    }

    string getDescription() override {
        return "Это кошка";
    }
};

class Bear : public Animal 
{
public:
    Bear(string bearName) : Animal(bearName) {}

    void makeNoise() override {
        cout << "Медведь рычит" << endl;
    }

    void eat() override {
        cout << "Медведь ест мёд" << endl;
    }

    string getDescription() override {
        return "Это медведь";
    }
};

class Vet 
{
public:
    void treatAnimal(Animal* animal) {
        cout << "Ветеринар обслуживает: " << animal->getName() << ". " << animal->getDescription() << endl;
    }
};

int main() 
{
    setlocale(LC_ALL, "RUS");

    Animal* animals[3] = {
        new Dog("Шарик"),
        new Cat("Мурка"),
        new Bear("Миша")
    };

    Vet vet;
    for (int i = 0; i < 3; ++i) {
        vet.treatAnimal(animals[i]);
        delete animals[i];
    }

    return 0;
}
