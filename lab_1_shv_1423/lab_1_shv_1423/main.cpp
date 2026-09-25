#include <iostream>

#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"
#include "Keeper.h"

int main()
{
    std::cout << "Garage project - initial version\n\n";

    Car car(
        "Toyota",
        "Camry",
        2.5,
        "Black",
        "Automatic"
    );

    Motorcycle motorcycle(
        "Yamaha",
        "MT-07",
        0.7,
        73,
        "Road"
    );

    Bus bus(
        "Mercedes",
        "Benz",
        40,
        60,
        "Berlin"
    );

    car.print();
    motorcycle.print();
    bus.print();

    return 0;
}