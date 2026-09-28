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

    Motorcycle(const Motorcycle& other);

    ~Motorcycle() override;

    double getEngineVolume() const;
    double getPower() const;
    std::string getPurpose() const;

    void setEngineVolume(double value);
    void setPower(double value);
    void setPurpose(const std::string& value);

    void print() const override;
    void edit() override;

    std::string getType() const override;

    Motorcycle& operator=(const Motorcycle& other);
};

#endif