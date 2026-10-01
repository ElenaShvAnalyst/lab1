#include "Car.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

Car::Car()
    : Base(),
    engineVolume(0.0),
    color("Not specified"),
    gearboxType("Not specified")
{
    std::cout << "[Car] Default constructor called\n";
}

Car::Car(const std::string& brand,
    const std::string& model,
    double engineVolume,
    const std::string& color,
    const std::string& gearboxType)
    : Base(brand, model),
    engineVolume(engineVolume),
    color(color),
    gearboxType(gearboxType)
{
    if (engineVolume <= 0)
        throw std::invalid_argument(
            "Engine volume must be greater than zero!");

    std::cout << "[Car] Parameterized constructor called\n";
}

Car::Car(const Car& other)
    : Base(other),
    engineVolume(other.engineVolume),
    color(other.color),
    gearboxType(other.gearboxType)
{
    std::cout << "[Car] Copy constructor called\n";
}

Car::~Car()
{
    std::cout << "[Car] Destructor called\n";
}

double Car::getEngineVolume() const
{
    return engineVolume;
}

std::string Car::getColor() const
{
    return color;
}

std::string Car::getGearboxType() const
{
    return gearboxType;
}

void Car::setEngineVolume(double value)
{
    if (value <= 0)
        throw std::invalid_argument(
            "Engine volume must be greater than zero!");

    engineVolume = value;
}

void Car::setColor(const std::string& value)
{
    if (value.empty())
        throw std::invalid_argument(
            "Color cannot be empty!");

    color = value;
}

void Car::setGearboxType(const std::string& value)
{
    if (value.empty())
        throw std::invalid_argument(
            "Gearbox type cannot be empty!");

    gearboxType = value;
}

void Car::print() const
{
    std::cout << "\n--- CAR ---\n";
    std::cout << "Brand: " << brand << '\n';
    std::cout << "Model: " << model << '\n';
    std::cout << "Engine volume: "
        << engineVolume << " L\n";
    std::cout << "Color: " << color << '\n';
    std::cout << "Gearbox type: "
        << gearboxType << '\n';
}

void Car::edit()
{
    std::string input;
    double volume;

    std::cout << "New brand: ";
    std::getline(std::cin, input);
    setBrand(input);

    std::cout << "New model: ";
    std::getline(std::cin, input);
    setModel(input);

    std::cout << "New engine volume: ";
    std::cin >> volume;
    std::cin.ignore(10000, '\n');
    setEngineVolume(volume);

    std::cout << "New color: ";
    std::getline(std::cin, input);
    setColor(input);

    std::cout << "New gearbox type: ";
    std::getline(std::cin, input);
    setGearboxType(input);
}

void Car::save(std::ofstream& file) const
{
    file << "CAR\n";
    file << std::quoted(brand) << '\n';
    file << std::quoted(model) << '\n';
    file << engineVolume << '\n';
    file << std::quoted(color) << '\n';
    file << std::quoted(gearboxType) << '\n';
}

void Car::load(std::ifstream& file)
{
    file >> std::quoted(brand);
    file >> std::quoted(model);
    file >> engineVolume;
    file.ignore(10000, '\n');
    file >> std::quoted(color);
    file >> std::quoted(gearboxType);
}

std::string Car::getType() const
{
    return "Car";
}

Car& Car::operator=(const Car& other)
{
    if (this != &other)
    {
        Base::operator=(other);

        engineVolume = other.engineVolume;
        color = other.color;
        gearboxType = other.gearboxType;
    }

    return *this;
}