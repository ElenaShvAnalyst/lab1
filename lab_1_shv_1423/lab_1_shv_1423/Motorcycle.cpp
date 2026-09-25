#include "Motorcycle.h"

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
    std::cout << "[Motorcycle] Parameterized constructor called\n";
}

Motorcycle::~Motorcycle()
{
    std::cout << "[Motorcycle] Destructor called\n";
}

void Motorcycle::print() const
{
    std::cout << "Motorcycle: "
        << brand << " "
        << model << '\n';
}

void Motorcycle::edit()
{
    // Editing will be implemented at the next stage.
}

std::string Motorcycle::getType() const
{
    return "Motorcycle";
}