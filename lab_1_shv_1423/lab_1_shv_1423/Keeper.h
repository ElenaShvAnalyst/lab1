#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"

class Keeper
{
private:
    Base** objects;
    int size;
    int capacity;

    void resize(int newCapacity);

public:
    Keeper();
    Keeper(const Keeper& other);
    ~Keeper();

    void add(Base* object);
    void remove(int index);
    void printAll() const;
    void edit(int index);

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    int getSize() const;
    bool empty() const;

    Keeper& operator=(const Keeper& other);
    Base*& operator[](int index);
    Keeper& operator+=(Base* object);
    Keeper& operator-=(int index);
};

#endif