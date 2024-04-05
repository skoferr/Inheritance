#include <iostream>
#include <string>
#include <locale>
using namespace std;

class Student {
protected:
    string firstName;
    string lastName;
    string group;
    double averageMark;

public:
    Student(string firstname, string lastname, string Group, double AverageMark) {
        firstName = firstname;
        lastName = lastname;
        group = Group;
        averageMark = AverageMark;
    }

    string getFirstName() {
        return firstName;
    }

    string getLastName() {
        return lastName;
    }

    string getGroup() {
        return group;
    }

    virtual double getAverageMark() {
        return averageMark;
    }

    virtual double getScholarship() {
        if (getAverageMark() == 5.0)
            return 2000;
        else
            return 1900;
    }
};

class Aspirant : public Student
{
private:
    string scientificWork;

public:
    Aspirant(string firstname, string lastname, string Group, double AverageMark, string ScientificWork)
        :Student(firstname, lastname, Group, AverageMark) 
    {
        scientificWork = ScientificWork;
    }

    string getScientificWork() {
        return scientificWork;
    }

    double getScholarship() override {
        if (getAverageMark() == 5.0)
            return 2500;
        else
            return 2200;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    Student* students[3] = {
        new Student("����", "������", "������ 1", 4.8),
        new Aspirant("����", "������", "������ 2", 5.0, "�������� ������� ������"),
        new Student("�����", "�������", "������ 3", 4.5)
    };

    for (int i = 0; i < 3; ++i) {
        cout << "������� " << students[i]->getFirstName() << " " << students[i]->getLastName()
            << ", ���������: " << students[i]->getScholarship() << endl;
        delete students[i];
    }

    return 0;
}
