#include "Base.h"

#include <stdexcept>

Base::Base()
    : brand(""), model("")
{
    std::cout << "[Base] Default constructor called\n";
}

Base::Base(const std::string& brand,
    const std::string& model)
    : brand(brand), model(model)
{
    std::cout << "[Base] Parameterized constructor called\n";
}

Base::Base(const Base& other)
    : brand(other.brand),
    model(other.model)
{
    std::cout << "[Base] Copy constructor called\n";
}

Base::~Base()
{
    std::cout << "[Base] Destructor called\n";
}

std::string Base::getBrand() const
{
    return brand;
}

std::string Base::getModel() const
{
    return model;
}

void Base::setBrand(const std::string& value)
{
    if (value.empty())
    {
        throw std::invalid_argument(
            "Brand cannot be empty!");
    }

    brand = value;
}

void Base::setModel(const std::string& value)
{
    if (value.empty())
    {
        throw std::invalid_argument(
            "Model cannot be empty!");
    }

    model = value;
}

Base& Base::operator=(const Base& other)
{
    if (this != &other)
    {
        brand = other.brand;
        model = other.model;
    }

    return *this;
}