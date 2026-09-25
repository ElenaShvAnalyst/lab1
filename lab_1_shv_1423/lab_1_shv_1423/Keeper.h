#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"

class Keeper
{
private:
    Base** objects;
    int size;
    int capacity;

public:
    Keeper();
    ~Keeper();

    void add(Base* object);
    void remove(int index);
    void printAll() const;
};

#endif