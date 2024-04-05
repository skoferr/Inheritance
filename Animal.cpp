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
        cout << "�������� ������ ����" << endl;
    }

    virtual void eat() {
        cout << "�������� ��������" << endl;
    }

    virtual string getDescription() {
        return "��� ��������";
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
        cout << "������ �������" << endl;
    }

    void eat() override {
        cout << "������ ��� �����" << endl;
    }

    string getDescription() override {
        return "��� ������";
    }
};

class Cat : public Animal 
{
public:
    Cat(string catName) : Animal(catName) {}

    void makeNoise() override {
        cout << "����� �������" << endl;
    }

    void eat() override {
        cout << "����� ��� ����" << endl;
    }

    string getDescription() override {
        return "��� �����";
    }
};

class Bear : public Animal 
{
public:
    Bear(string bearName) : Animal(bearName) {}

    void makeNoise() override {
        cout << "������� �����" << endl;
    }

    void eat() override {
        cout << "������� ��� ��" << endl;
    }

    string getDescription() override {
        return "��� �������";
    }
};

class Vet 
{
public:
    void treatAnimal(Animal* animal) {
        cout << "��������� �����������: " << animal->getName() << ". " << animal->getDescription() << endl;
    }
};

int main() 
{
    setlocale(LC_ALL, "RUS");

    Animal* animals[3] = {
        new Dog("�����"),
        new Cat("�����"),
        new Bear("����")
    };

    Vet vet;
    for (int i = 0; i < 3; ++i) {
        vet.treatAnimal(animals[i]);
        delete animals[i];
    }

    return 0;
}
