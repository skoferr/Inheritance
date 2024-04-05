#include <iostream>
#include <locale>
using namespace std;

class Shape {
protected:
    string color;

public:
    Shape(string c)
    {
        color = c;
    }
    virtual void draw() = 0;
};

class Circle : public Shape {
private:
    int x;
    int y;
    int radius;

public:
    Circle(string c, int xCoord, int yCoord, int r) : Shape(c)
    {
        x = xCoord;
        y = yCoord;
        radius = r;
    }

    void draw() override {
        cout << "������ ���� � ������������ (" << x << ", " << y << "), �������� " << radius << " � ������ " << color << endl;
    }
};

class Rectangle : public Shape {
private:
    int x;
    int y;
    int width;
    int height;

public:
    Rectangle(string c, int xCoord, int yCoord, int w, int h) : Shape(c)
    {
        x = xCoord;
        y = yCoord;
        width = w;
        height = h;
    }
    void draw() override {
        cout << "������ ������������� � ������������ (" << x << ", " << y << "), �������� " << width << "x" << height << " � ������ " << color << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RUS");

    const int numShapes = 3;
    Shape* shapes[numShapes];

    shapes[0] = new Circle("�������", 0, 0, 5);
    shapes[1] = new Rectangle("�����", 2, 2, 3, 7);
    shapes[2] = new Circle("������", 3, 1, 8);

    for (int i = 0; i < numShapes; ++i) {
        shapes[i]->draw();
    }

    for (int i = 0; i < numShapes; ++i) {
        delete shapes[i];
    }

    return 0;
}
