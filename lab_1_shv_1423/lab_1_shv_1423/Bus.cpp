#include "Bus.h"

Bus::Bus()
    : Base(),
    seatedPassengers(0),
    totalPassengers(0),
    destination("")
{
    std::cout << "[Bus] Default constructor called\n";
}

Bus::Bus(const std::string& brand,
    const std::string& model,
    int seatedPassengers,
    int totalPassengers,
    const std::string& destination)
    : Base(brand, model),
    seatedPassengers(seatedPassengers),
    totalPassengers(totalPassengers),
    destination(destination)
{
    std::cout << "[Bus] Parameterized constructor called\n";
}

Bus::~Bus()
{
    std::cout << "[Bus] Destructor called\n";
}

void Bus::print() const
{
    std::cout << "Bus: "
        << brand << " "
        << model << '\n';
}

void Bus::edit()
{
    // Editing will be implemented at the next stage.
}

std::string Bus::getType() const
{
    return "Bus";
}