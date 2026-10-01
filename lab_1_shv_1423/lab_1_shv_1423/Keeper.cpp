#include "Keeper.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

Keeper::Keeper()
    : objects(nullptr), size(0), capacity(2)
{
    objects = new Base * [capacity];

    for (int i = 0; i < capacity; ++i)
    {
        objects[i] = nullptr;
    }

    std::cout << "[Keeper] Default constructor called\n";
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
        if (dynamic_cast<Car*>(other.objects[i]))
        {
            objects[i] =
                new Car(*dynamic_cast<Car*>(other.objects[i]));
        }
        else if (dynamic_cast<Motorcycle*>(other.objects[i]))
        {
            objects[i] =
                new Motorcycle(
                    *dynamic_cast<Motorcycle*>(other.objects[i]));
        }
        else if (dynamic_cast<Bus*>(other.objects[i]))
        {
            objects[i] =
                new Bus(*dynamic_cast<Bus*>(other.objects[i]));
        }
    }

    std::cout << "[Keeper] Copy constructor called\n";
}

Keeper::~Keeper()
{
    for (int i = 0; i < size; ++i)
    {
        delete objects[i];
    }

    delete[] objects;

    std::cout << "[Keeper] Destructor called\n";
}

void Keeper::resize(int newCapacity)
{
    Base** newObjects = new Base * [newCapacity];

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

    std::cout << "Object successfully added.\n";
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

    std::cout << "Object successfully removed.\n";
}

void Keeper::printAll() const
{
    if (size == 0)
    {
        std::cout << "\nGarage is empty.\n";
        return;
    }

    std::cout << "\n";
    std::cout << "========== GARAGE CONTENT ==========\n";

    for (int i = 0; i < size; ++i)
    {
        std::cout << "\nObject #" << i + 1 << '\n';

        objects[i]->print();
    }

    std::cout << "\n====================================\n";
}

void Keeper::edit(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range(
            "Invalid object index!");
    }

    objects[index]->edit();

    std::cout << "Object data successfully changed.\n";
}

void Keeper::saveToFile(const std::string& filename) const
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error(
            "Failed to open file for saving!");
    }

    file << size << '\n';

    for (int i = 0; i < size; ++i)
    {
        objects[i]->save(file);
    }

    file.close();

    std::cout << "Data successfully saved to file: "
        << filename << '\n';
}

void Keeper::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error(
            "Failed to open file for loading!");
    }

    // Delete existing objects
    for (int i = 0; i < size; ++i)
    {
        delete objects[i];
        objects[i] = nullptr;
    }

    size = 0;

    int count;

    file >> count;

    if (count < 0)
    {
        throw std::runtime_error(
            "Invalid number of objects in file!");
    }

    file.ignore(10000, '\n');

    // Increase capacity if necessary
    while (capacity < count)
    {
        resize(capacity * 2);
    }

    for (int i = 0; i < count; ++i)
    {
        std::string type;

        file >> type;
        file.ignore(10000, '\n');

        Base* object = nullptr;

        if (type == "CAR")
        {
            object = new Car();
        }
        else if (type == "MOTORCYCLE")
        {
            object = new Motorcycle();
        }
        else if (type == "BUS")
        {
            object = new Bus();
        }
        else
        {
            throw std::runtime_error(
                "Unknown object type in file!");
        }

        object->load(file);

        objects[size] = object;
        ++size;
    }

    file.close();

    std::cout << "Data successfully loaded from file: "
        << filename << '\n';
}

int Keeper::getSize() const
{
    return size;
}

bool Keeper::empty() const
{
    return size == 0;
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
        if (dynamic_cast<Car*>(other.objects[i]))
        {
            objects[i] =
                new Car(*dynamic_cast<Car*>(other.objects[i]));
        }
        else if (dynamic_cast<Motorcycle*>(other.objects[i]))
        {
            objects[i] =
                new Motorcycle(
                    *dynamic_cast<Motorcycle*>(other.objects[i]));
        }
        else if (dynamic_cast<Bus*>(other.objects[i]))
        {
            objects[i] =
                new Bus(*dynamic_cast<Bus*>(other.objects[i]));
        }
    }

    return *this;
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