#include <iostream>

#include "Keeper.h"

int main()
{
    Keeper garage;

    std::cout
        << "\n===== DAY 2: KEEPER TEST =====\n";

    Car* car = new Car(
        "Toyota",
        "Camry",
        2.5,
        "Black",
        "Automatic"
    );

    Motorcycle* motorcycle = new Motorcycle(
        "Yamaha",
        "MT-07",
        0.7,
        73,
        "Road"
    );

    Bus* bus = new Bus(
        "Mercedes",
        "Benz",
        40,
        60,
        "Berlin"
    );

    garage += car;
    garage += motorcycle;
    garage += bus;

    std::cout
        << "\nCurrent garage:\n";

    garage.printAll();

    std::cout
        << "\nGarage size: "
        << garage.getSize()
        << '\n';

    std::cout
        << "\nRemoving object #2...\n";

    garage -= 1;

    garage.printAll();

    return 0;
}