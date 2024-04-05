#include <iostream>
#include <string>
#include <locale>
using namespace std;

class User 
{
protected:
    string name;
    int age;

public:
    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setAge(int a) {
        age = a;
    }

    int getAge() {
        return age;
    }
};

class Worker : public User 
{
private:
    double salary;

public:
    Worker(string n, int a, double s) {
        name = n;
        age = a;
        salary = s;
    }

    void setSalary(double s) {
        salary = s;
    }

    double getSalary() {
        return salary;
    }
};

class Driver : public Worker 
{
private:
    int drivingExperience;
    char drivingCategory;

public:
    Driver(string n, int a, double s, int exp, char cat)
        :Worker(n, a, s)
    {
        drivingExperience = exp; 
        drivingCategory = cat;
    
    }
};

int main() 
{
    setlocale(LC_ALL, "RUS");

    Worker ivan("Иван", 25, 1000);
    Worker vasya("Вася", 26, 2000);

    double averageSalary = (ivan.getSalary() + vasya.getSalary()) / 2.0;

    cout << "Средняя зарплата: " << averageSalary << endl;

    return 0;
}
