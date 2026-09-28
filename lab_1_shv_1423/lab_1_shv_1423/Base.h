#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

class Base
{
protected:
    std::string brand;
    std::string model;

public:
    Base();
    Base(const std::string& brand,
        const std::string& model);

    Base(const Base& other);

    virtual ~Base();

    std::string getBrand() const;
    std::string getModel() const;

    void setBrand(const std::string& brand);
    void setModel(const std::string& model);

    Base& operator=(const Base& other);

    virtual void print() const = 0;
    virtual void edit() = 0;

    virtual std::string getType() const = 0;
};

#endif
