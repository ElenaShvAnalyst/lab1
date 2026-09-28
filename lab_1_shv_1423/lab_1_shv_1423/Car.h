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

    Car(const Car& other);

    ~Car() override;

    double getEngineVolume() const;
    std::string getColor() const;
    std::string getGearboxType() const;

    void setEngineVolume(double value);
    void setColor(const std::string& value);
    void setGearboxType(const std::string& value);

    void print() const override;
    void edit() override;

    std::string getType() const override;

    Car& operator=(const Car& other);
};

#endif
