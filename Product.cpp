#include <iostream>
#include <string>
#include <locale>
using namespace std;

class Product {
private:
    string name;
    double price;
    double rating;

public:
    Product()
    {
        name = ""; 
        price = 0.0; 
        rating = 0.0;
    }
    Product(string n, double p, double r)
    {
        name = n; 
        price = p; 
        rating = r;
    }
    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }

    double getRating() {
        return rating;
    }
};

class Category {
private:
    string categoryName;
    Product* products;
    int numProducts;

public:
    Category(string name, int num)
    {
        categoryName = name;
        numProducts = num;
        products = new Product[numProducts];
    }

    void setProduct(int index, string name, double price, double rating) {
        products[index] = Product(name, price, rating);
    }

    void printProducts() {
        cout << "Категория: " << categoryName << endl;
        for (int i = 0; i < numProducts; ++i) {
            cout << "Название товара: " << products[i].getName() << ", Цена: " << products[i].getPrice() << ", Рейтинг: " << products[i].getRating() << endl;
        }
    }

    ~Category() {
        delete[] products;
    }
};

class Basket {
private:
    Product* products;
    int numProducts;

public:
    Basket() : products(nullptr)
    {
        numProducts = 0;
    }

    void addProduct(Product product) {
        Product* newProducts = new Product[numProducts + 1];
        for (int i = 0; i < numProducts; ++i) {
            newProducts[i] = products[i];
        }
        newProducts[numProducts] = product;
        delete[] products;
        products = newProducts;
        ++numProducts;
    }

    void printBasket() {
        cout << "Список купленных товаров:" << endl;
        for (int i = 0; i < numProducts; ++i) {
            cout << "Название товара: " << products[i].getName() << ", Цена: " << products[i].getPrice() << ", Рейтинг: " << products[i].getRating() << endl;
        }
    }

    ~Basket() {
        delete[] products;
    }
};

class User {
private:
    string login;
    string password;
    Basket basket;

public:
    User(string Login, string Password)
    {
        login = Login;
        password = Password;
    }

    void addProductToBasket(Product product) {
        basket.addProduct(product);
    }

    void printBasket() {
        cout << "Корзина пользователя " << login << ":" << endl;
        basket.printBasket();
    }
};

int main() {
    setlocale(LC_ALL, "RUS");

    Category category("Электроника", 3);
    category.setProduct(0, "Смартфон", 1000.0, 4.5);
    category.setProduct(1, "Ноутбук", 1500.0, 4.0);
    category.setProduct(2, "Планшет", 800.0, 4.2);

    category.printProducts();

    User user1("user1", "password1");
    User user2("user2", "password2");

    user1.addProductToBasket(Product("Смартфон", 1000.0, 4.5));
    user1.addProductToBasket(Product("Наушники", 50.0, 4.0));
    user2.addProductToBasket(Product("Ноутбук", 1500.0, 4.0));

    user1.printBasket();
    user2.printBasket();

    return 0;
}
