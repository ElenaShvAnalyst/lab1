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
    // Конструкторы
    Car();
    Car(const std::string& brand,
        const std::string& model,
        double engineVolume,
        const std::string& color,
        const std::string& gearboxType);

    Car(const Car& other);

    // Деструктор
    ~Car() override;

    // Get
    double getEngineVolume() const;
    std::string getColor() const;
    std::string getGearboxType() const;

    // Set
    void setEngineVolume(double value);
    void setColor(const std::string& value);
    void setGearboxType(const std::string& value);

    // Переопределение методов Base
    void print() const override;
    void edit() override;
    void save(std::ofstream& file) const override;
    void load(std::ifstream& file) override;
    std::string getType() const override;

    // Перегрузка оператора присваивания
    Car& operator=(const Car& other);
};

#endif
