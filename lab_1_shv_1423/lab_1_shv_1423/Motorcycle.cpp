#include "Motorcycle.h"

#include <stdexcept>

Motorcycle::Motorcycle()
    : Base(),
    engineVolume(0.0),
    power(0.0),
    purpose("")
{
    std::cout << "[Motorcycle] Default constructor called\n";
}

Motorcycle::Motorcycle(const std::string& brand,
    const std::string& model,
    double engineVolume,
    double power,
    const std::string& purpose)
    : Base(brand, model),
    engineVolume(engineVolume),
    power(power),
    purpose(purpose)
{
    if (engineVolume <= 0)
    {
        throw std::invalid_argument(
            "Engine volume must be greater than zero!");
    }

    if (power <= 0)
    {
        throw std::invalid_argument(
            "Engine power must be greater than zero!");
    }

    std::cout << "[Motorcycle] Parameterized constructor called\n";
}

Motorcycle::Motorcycle(const Motorcycle& other)
    : Base(other),
    engineVolume(other.engineVolume),
    power(other.power),
    purpose(other.purpose)
{
    std::cout << "[Motorcycle] Copy constructor called\n";
}

Motorcycle::~Motorcycle()
{
    std::cout << "[Motorcycle] Destructor called\n";
}

double Motorcycle::getEngineVolume() const
{
    return engineVolume;
}

double Motorcycle::getPower() const
{
    return power;
}

std::string Motorcycle::getPurpose() const
{
    return purpose;
}

void Motorcycle::setEngineVolume(double value)
{
    if (value <= 0)
    {
        throw std::invalid_argument(
            "Engine volume must be greater than zero!");
    }

    engineVolume = value;
}

void Motorcycle::setPower(double value)
{
    if (value <= 0)
    {
        throw std::invalid_argument(
            "Engine power must be greater than zero!");
    }

    power = value;
}

void Motorcycle::setPurpose(const std::string& value)
{
    if (value.empty())
    {
        throw std::invalid_argument(
            "Purpose cannot be empty!");
    }

    purpose = value;
}

void Motorcycle::print() const
{
    std::cout << "\n--- MOTORCYCLE ---\n";

    std::cout << "Brand: "
        << brand << '\n';

    std::cout << "Model: "
        << model << '\n';

    std::cout << "Engine volume: "
        << engineVolume << " L\n";

    std::cout << "Engine power: "
        << power << " hp\n";

    std::cout << "Purpose: "
        << purpose << '\n';
}

void Motorcycle::edit()
{
    std::cout
        << "Motorcycle editing will be implemented "
        << "in the final stage.\n";
}

std::string Motorcycle::getType() const
{
    return "Motorcycle";
}

Motorcycle& Motorcycle::operator=(const Motorcycle& other)
{
    if (this != &other)
    {
        Base::operator=(other);

        engineVolume = other.engineVolume;
        power = other.power;
        purpose = other.purpose;
    }

    return *this;
}