#include <iostream>
#include <string>
#include <limits>

#include "Keeper.h"

using namespace std;

// ============================================================
// INPUT FUNCTIONS
// ============================================================

int readInt(const string& message)
{
    int value;

    while (true)
    {
        cout << message;

        if (cin >> value)
        {
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            return value;
        }

        cout << "Error: please enter an integer.\n";

        cin.clear();

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );
    }
}

double readDouble(const string& message)
{
    double value;

    while (true)
    {
        cout << message;

        if (cin >> value)
        {
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            return value;
        }

        cout << "Error: please enter a number.\n";

        cin.clear();

        cin.ignore(
            numeric_limits<streamsize>::max(),
            '\n'
        );
    }
}

string readString(const string& message)
{
    string value;

    while (true)
    {
        cout << message;

        getline(cin, value);

        if (!value.empty())
        {
            return value;
        }

        cout << "Error: input cannot be empty.\n";
    }
}

// ============================================================
// ADD CAR
// ============================================================

void addCar(Keeper& garage)
{
    cout << "\n";
    cout << "===== ADD CAR =====\n";

    string brand =
        readString("Brand: ");

    string model =
        readString("Model: ");

    double engineVolume =
        readDouble("Engine volume (L): ");

    string color =
        readString("Color: ");

    string gearbox =
        readString("Gearbox type: ");

    try
    {
        Car* car = new Car(
            brand,
            model,
            engineVolume,
            color,
            gearbox
        );

        garage += car;

        cout << "Car successfully added.\n";
    }
    catch (const exception& e)
    {
        cout << "Error while adding car: "
            << e.what() << '\n';
    }
}

// ============================================================
// ADD MOTORCYCLE
// ============================================================

void addMotorcycle(Keeper& garage)
{
    cout << "\n";
    cout << "===== ADD MOTORCYCLE =====\n";

    string brand =
        readString("Brand: ");

    string model =
        readString("Model: ");

    double engineVolume =
        readDouble("Engine volume (L): ");

    double power =
        readDouble("Engine power (hp): ");

    string purpose =
        readString("Purpose / terrain: ");

    try
    {
        Motorcycle* motorcycle =
            new Motorcycle(
                brand,
                model,
                engineVolume,
                power,
                purpose
            );

        garage += motorcycle;

        cout << "Motorcycle successfully added.\n";
    }
    catch (const exception& e)
    {
        cout << "Error while adding motorcycle: "
            << e.what() << '\n';
    }
}

// ============================================================
// ADD BUS
// ============================================================

void addBus(Keeper& garage)
{
    cout << "\n";
    cout << "===== ADD BUS =====\n";

    string brand =
        readString("Brand: ");

    string model =
        readString("Model: ");

    int seated =
        readInt("Number of seated passengers: ");

    int total =
        readInt("Total number of passengers: ");

    string destination =
        readString("Destination: ");

    try
    {
        Bus* bus =
            new Bus(
                brand,
                model,
                seated,
                total,
                destination
            );

        garage += bus;

        cout << "Bus successfully added.\n";
    }
    catch (const exception& e)
    {
        cout << "Error while adding bus: "
            << e.what() << '\n';
    }
}

// ============================================================
// ADD OBJECT MENU
// ============================================================

void addObject(Keeper& garage)
{
    while (true)
    {
        cout << "\n";
        cout << "========== ADD VEHICLE ==========\n";
        cout << "1. Car\n";
        cout << "2. Motorcycle\n";
        cout << "3. Bus\n";
        cout << "0. Back\n";
        cout << "=================================\n";

        int choice =
            readInt("Your choice: ");

        switch (choice)
        {
        case 1:
            addCar(garage);
            return;

        case 2:
            addMotorcycle(garage);
            return;

        case 3:
            addBus(garage);
            return;

        case 0:
            return;

        default:
            cout << "Error: no such menu option.\n";
        }
    }
}

// ============================================================
// REMOVE OBJECT
// ============================================================

void removeObject(Keeper& garage)
{
    if (garage.empty())
    {
        cout << "Garage is empty.\n";
        return;
    }

    garage.printAll();

    int index =
        readInt("Enter object number to remove: ");

    try
    {
        garage -= index - 1;
    }
    catch (const exception& e)
    {
        cout << "Error while removing object: "
            << e.what() << '\n';
    }
}

// ============================================================
// EDIT OBJECT
// ============================================================

void editObject(Keeper& garage)
{
    if (garage.empty())
    {
        cout << "Garage is empty.\n";
        return;
    }

    garage.printAll();

    int index =
        readInt("Enter object number to edit: ");

    try
    {
        garage.edit(index - 1);
    }
    catch (const exception& e)
    {
        cout << "Error while editing object: "
            << e.what() << '\n';
    }
}

// ============================================================
// SAVE
// ============================================================

void saveGarage(const Keeper& garage)
{
    string filename =
        readString("Enter file name: ");

    try
    {
        garage.saveToFile(filename);
    }
    catch (const exception& e)
    {
        cout << "Error while saving: "
            << e.what() << '\n';
    }
}

// ============================================================
// LOAD
// ============================================================

void loadGarage(Keeper& garage)
{
    string filename =
        readString("Enter file name: ");

    try
    {
        garage.loadFromFile(filename);
    }
    catch (const exception& e)
    {
        cout << "Error while loading: "
            << e.what() << '\n';
    }
}

// ============================================================
// MAIN MENU
// ============================================================

void showMenu()
{
    cout << "\n";
    cout << "========================================\n";
    cout << "                 GARAGE\n";
    cout << "========================================\n";
    cout << "1. Add vehicle\n";
    cout << "2. Remove vehicle\n";
    cout << "3. Show all vehicles\n";
    cout << "4. Edit vehicle\n";
    cout << "5. Save garage to file\n";
    cout << "6. Load garage from file\n";
    cout << "0. Exit\n";
    cout << "========================================\n";
}

// ============================================================
// MAIN
// ============================================================

int main()
{
    Keeper garage;

    while (true)
    {
        showMenu();

        int choice =
            readInt("Enter menu option: ");

        switch (choice)
        {
        case 1:
            addObject(garage);
            break;

        case 2:
            removeObject(garage);
            break;

        case 3:
            garage.printAll();
            break;

        case 4:
            editObject(garage);
            break;

        case 5:
            saveGarage(garage);
            break;

        case 6:
            loadGarage(garage);
            break;

        case 0:
            cout << "Program finished.\n";
            return 0;

        default:
            cout << "Error: no such menu option.\n";
        }
    }
}