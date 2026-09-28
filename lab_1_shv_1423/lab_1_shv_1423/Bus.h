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

    Bus(const Bus& other);

    ~Bus() override;

    int getSeatedPassengers() const;
    int getTotalPassengers() const;
    std::string getDestination() const;

    void setSeatedPassengers(int value);
    void setTotalPassengers(int value);
    void setDestination(const std::string& value);

    void print() const override;
    void edit() override;

    std::string getType() const override;

    Bus& operator=(const Bus& other);
};

#endif