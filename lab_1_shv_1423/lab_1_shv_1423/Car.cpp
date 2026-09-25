#include "Car.h"

Car::Car()
    : Base(),
    engineVolume(0.0),
    color(""),
    gearboxType("")
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
    std::cout << "[Car] Parameterized constructor called\n";
}

Car::~Car()
{
    std::cout << "[Car] Destructor called\n";
}

void Car::print() const
{
    std::cout << "Car: "
        << brand << " "
        << model << '\n';
}

void Car::edit()
{
    // Editing will be implemented at the next stage.
}

std::string Car::getType() const
{
    return "Car";
}