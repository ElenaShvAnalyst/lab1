#ifndef CAR_H
#define CAR_H

#include "Base.h"

class Car : public Base
{
private:
    double engineVolume;
    std::string color;
    std::string gearboxType;

public:
    Car();
    Car(const std::string& brand,
        const std::string& model,
        double engineVolume,
        const std::string& color,
        const std::string& gearboxType);

    ~Car() override;

    void print() const override;
    void edit() override;

    std::string getType() const override;
};

#endif
