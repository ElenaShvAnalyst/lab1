#include "Keeper.h"

#include <iostream>
#include <stdexcept>

Keeper::Keeper()
    : objects(nullptr),
    size(0),
    capacity(2)
{
    objects = new Base * [capacity];

    for (int i = 0; i < capacity; ++i)
    {
        objects[i] = nullptr;
    }

    std::cout
        << "[Keeper] Default constructor called\n";
}

Keeper::Keeper(const Keeper& other)
    : objects(nullptr),
    size(other.size),
    capacity(other.capacity)
{
    objects = new Base * [capacity];

    for (int i = 0; i < capacity; ++i)
    {
        objects[i] = nullptr;
    }

    for (int i = 0; i < size; ++i)
    {
        if (Car* car =
            dynamic_cast<Car*>(other.objects[i]))
        {
            objects[i] = new Car(*car);
        }
        else if (Motorcycle* motorcycle =
            dynamic_cast<Motorcycle*>(
                other.objects[i]))
        {
            objects[i] = new Motorcycle(*motorcycle);
        }
        else if (Bus* bus =
            dynamic_cast<Bus*>(other.objects[i]))
        {
            objects[i] = new Bus(*bus);
        }
    }

    std::cout
        << "[Keeper] Copy constructor called\n";
}

Keeper::~Keeper()
{
    for (int i = 0; i < size; ++i)
    {
        delete objects[i];
    }

    delete[] objects;

    std::cout
        << "[Keeper] Destructor called\n";
}

void Keeper::resize(int newCapacity)
{
    if (newCapacity <= capacity)
    {
        return;
    }

    Base** newObjects =
        new Base * [newCapacity];

    for (int i = 0; i < newCapacity; ++i)
    {
        newObjects[i] = nullptr;
    }

    for (int i = 0; i < size; ++i)
    {
        newObjects[i] = objects[i];
    }

    delete[] objects;

    objects = newObjects;
    capacity = newCapacity;
}

void Keeper::add(Base* object)
{
    if (object == nullptr)
    {
        throw std::invalid_argument(
            "Cannot add a null object!");
    }

    if (size >= capacity)
    {
        resize(capacity * 2);
    }

    objects[size] = object;
    ++size;

    std::cout
        << "Object successfully added.\n";
}

void Keeper::remove(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range(
            "Invalid object index!");
    }

    delete objects[index];

    for (int i = index; i < size - 1; ++i)
    {
        objects[i] = objects[i + 1];
    }

    objects[size - 1] = nullptr;

    --size;

    std::cout
        << "Object successfully removed.\n";
}

void Keeper::printAll() const
{
    if (size == 0)
    {
        std::cout
            << "\nGarage is empty.\n";

        return;
    }

    std::cout
        << "\n========== GARAGE CONTENT ==========\n";

    for (int i = 0; i < size; ++i)
    {
        std::cout
            << "\nObject #"
            << i + 1
            << '\n';

        objects[i]->print();
    }

    std::cout
        << "\n====================================\n";
}

int Keeper::getSize() const
{
    return size;
}

bool Keeper::empty() const
{
    return size == 0;
}

Base*& Keeper::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range(
            "Index is out of range!");
    }

    return objects[index];
}

Keeper& Keeper::operator+=(Base* object)
{
    add(object);

    return *this;
}

Keeper& Keeper::operator-=(int index)
{
    remove(index);

    return *this;
}

Keeper& Keeper::operator=(const Keeper& other)
{
    if (this == &other)
    {
        return *this;
    }

    for (int i = 0; i < size; ++i)
    {
        delete objects[i];
    }

    delete[] objects;

    size = other.size;
    capacity = other.capacity;

    objects = new Base * [capacity];

    for (int i = 0; i < capacity; ++i)
    {
        objects[i] = nullptr;
    }

    for (int i = 0; i < size; ++i)
    {
        if (Car* car =
            dynamic_cast<Car*>(other.objects[i]))
        {
            objects[i] = new Car(*car);
        }
        else if (Motorcycle* motorcycle =
            dynamic_cast<Motorcycle*>(
                other.objects[i]))
        {
            objects[i] = new Motorcycle(*motorcycle);
        }
        else if (Bus* bus =
            dynamic_cast<Bus*>(other.objects[i]))
        {
            objects[i] = new Bus(*bus);
        }
    }

    return *this;
}