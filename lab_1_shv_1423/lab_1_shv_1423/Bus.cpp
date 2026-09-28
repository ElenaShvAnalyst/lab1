#include "Bus.h"

#include <stdexcept>

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
    if (seatedPassengers < 0)
    {
        throw std::invalid_argument(
            "Number of seated passengers cannot be negative!");
    }

    if (totalPassengers < seatedPassengers)
    {
        throw std::invalid_argument(
            "Total passengers cannot be less "
            "than seated passengers!");
    }

    std::cout << "[Bus] Parameterized constructor called\n";
}

Bus::Bus(const Bus& other)
    : Base(other),
    seatedPassengers(other.seatedPassengers),
    totalPassengers(other.totalPassengers),
    destination(other.destination)
{
    std::cout << "[Bus] Copy constructor called\n";
}

Bus::~Bus()
{
    std::cout << "[Bus] Destructor called\n";
}

int Bus::getSeatedPassengers() const
{
    return seatedPassengers;
}

int Bus::getTotalPassengers() const
{
    return totalPassengers;
}

std::string Bus::getDestination() const
{
    return destination;
}

void Bus::setSeatedPassengers(int value)
{
    if (value < 0)
    {
        throw std::invalid_argument(
            "Number of seated passengers cannot be negative!");
    }

    if (value > totalPassengers)
    {
        throw std::invalid_argument(
            "Seated passengers cannot exceed "
            "total passengers!");
    }

    seatedPassengers = value;
}

void Bus::setTotalPassengers(int value)
{
    if (value < 0)
    {
        throw std::invalid_argument(
            "Total passengers cannot be negative!");
    }

    if (value < seatedPassengers)
    {
        throw std::invalid_argument(
            "Total passengers cannot be less "
            "than seated passengers!");
    }

    totalPassengers = value;
}

void Bus::setDestination(const std::string& value)
{
    if (value.empty())
    {
        throw std::invalid_argument(
            "Destination cannot be empty!");
    }

    destination = value;
}

void Bus::print() const
{
    std::cout << "\n--- BUS ---\n";

    std::cout << "Brand: "
        << brand << '\n';

    std::cout << "Model: "
        << model << '\n';

    std::cout << "Seated passengers: "
        << seatedPassengers << '\n';

    std::cout << "Total passengers: "
        << totalPassengers << '\n';

    std::cout << "Destination: "
        << destination << '\n';
}

void Bus::edit()
{
    std::cout
        << "Bus editing will be implemented "
        << "in the final stage.\n";
}

std::string Bus::getType() const
{
    return "Bus";
}

Bus& Bus::operator=(const Bus& other)
{
    if (this != &other)
    {
        Base::operator=(other);

        seatedPassengers = other.seatedPassengers;
        totalPassengers = other.totalPassengers;
        destination = other.destination;
    }

    return *this;
}