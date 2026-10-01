#include "Bus.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

Bus::Bus()
    : Base(),
    seatedPassengers(0),
    totalPassengers(0),
    destination("Not specified")
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
        throw std::invalid_argument(
            "Number of seated passengers cannot be negative!");

    if (totalPassengers < seatedPassengers)
        throw std::invalid_argument(
            "Total passengers cannot be less than seated passengers!");

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
        throw std::invalid_argument(
            "Number of seated passengers cannot be negative!");

    if (value > totalPassengers && totalPassengers != 0)
        throw std::invalid_argument(
            "Seated passengers cannot exceed total passengers!");

    seatedPassengers = value;
}

void Bus::setTotalPassengers(int value)
{
    if (value < 0)
        throw std::invalid_argument(
            "Total passengers cannot be negative!");

    if (value < seatedPassengers)
        throw std::invalid_argument(
            "Total passengers cannot be less than seated passengers!");

    totalPassengers = value;
}

void Bus::setDestination(const std::string& value)
{
    if (value.empty())
        throw std::invalid_argument(
            "Destination cannot be empty!");

    destination = value;
}

void Bus::print() const
{
    std::cout << "\n--- BUS ---\n";
    std::cout << "Brand: " << brand << '\n';
    std::cout << "Model: " << model << '\n';
    std::cout << "Seated passengers: "
        << seatedPassengers << '\n';
    std::cout << "Total passengers: "
        << totalPassengers << '\n';
    std::cout << "Destination: "
        << destination << '\n';
}

void Bus::edit()
{
    std::string input;
    int seated;
    int total;

    std::cout << "New brand: ";
    std::getline(std::cin, input);
    setBrand(input);

    std::cout << "New model: ";
    std::getline(std::cin, input);
    setModel(input);

    std::cout << "Number of seated passengers: ";
    std::cin >> seated;

    std::cout << "Total number of passengers: ";
    std::cin >> total;

    std::cin.ignore(10000, '\n');

    setTotalPassengers(total);
    setSeatedPassengers(seated);

    std::cout << "New destination: ";
    std::getline(std::cin, input);
    setDestination(input);
}

void Bus::save(std::ofstream& file) const
{
    file << "BUS\n";
    file << std::quoted(brand) << '\n';
    file << std::quoted(model) << '\n';
    file << seatedPassengers << '\n';
    file << totalPassengers << '\n';
    file << std::quoted(destination) << '\n';
}

void Bus::load(std::ifstream& file)
{
    file >> std::quoted(brand);
    file >> std::quoted(model);
    file >> seatedPassengers;
    file >> totalPassengers;
    file.ignore(10000, '\n');
    file >> std::quoted(destination);
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