#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Base.h"

class Motorcycle : public Base
{
private:
    double engineVolume;
    double power;
    std::string purpose;

public:
    Motorcycle();

    Motorcycle(const std::string& brand,
        const std::string& model,
        double engineVolume,
        double power,
        const std::string& purpose);

    ~Motorcycle() override;

    void print() const override;
    void edit() override;

    std::string getType() const override;
};

#endif