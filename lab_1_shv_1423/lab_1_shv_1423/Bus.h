#ifndef BUS_H
#define BUS_H

#include "Base.h"

class Bus : public Base
{
private:
    int seatedPassengers;
    int totalPassengers;
    std::string destination;

public:
    Bus();

    Bus(const std::string& brand,
        const std::string& model,
        int seatedPassengers,
        int totalPassengers,
        const std::string& destination);

    ~Bus() override;

    void print() const override;
    void edit() override;

    std::string getType() const override;
};

#endif
