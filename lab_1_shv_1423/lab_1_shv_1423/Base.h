#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>
#include <fstream>

class Base
{
protected:
    std::string brand;
    std::string model;

public:
    // Конструкторы
    Base();
    Base(const std::string& brand, const std::string& model);
    Base(const Base& other);

    // Виртуальный деструктор
    virtual ~Base();

    // Геттеры
    std::string getBrand() const;
    std::string getModel() const;

    // Сеттеры
    void setBrand(const std::string& brand);
    void setModel(const std::string& model);

    // Чисто виртуальные функции
    virtual void print() const = 0;
    virtual void edit() = 0;
    virtual void save(std::ofstream& file) const = 0;
    virtual void load(std::ifstream& file) = 0;
    virtual std::string getType() const = 0;

    // Перегрузка оператора присваивания
    Base& operator=(const Base& other);

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const Base& object);
};

#endif
