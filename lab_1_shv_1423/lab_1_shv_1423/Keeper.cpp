#include "Keeper.h"

#include <iostream>

Keeper::Keeper()
    : objects(nullptr),
    size(0),
    capacity(0)
{
    std::cout << "[Keeper] Default constructor called\n";
}

Keeper::~Keeper()
{
    std::cout << "[Keeper] Destructor called\n";
}

void Keeper::add(Base* object)
{
    // Will be implemented at the next stage.
}

void Keeper::remove(int index)
{
    // Will be implemented at the next stage.
}

void Keeper::printAll() const
{
    // Will be implemented at the next stage.
}