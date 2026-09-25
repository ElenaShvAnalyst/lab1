#include "Base.h"

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

Base::~Base()
{
    std::cout << "[Base] Destructor called\n";
}