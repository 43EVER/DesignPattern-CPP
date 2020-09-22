/*
 * 将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示
*/

#include <string>
#include <iostream>
#include <cstdio>

class House {
public:
    House() {}
    void setFloor(std::string iFloor) {
        this->floor = iFloor;
    }
    void setWall(std::string iWall) {
        this->wall = iWall;
    }
    void setRoof(std::string iRoof) {
        this->roof = iRoof;
    }

    void printHouseInfo() {
        std::printf("Floor: %s\t\n", this->floor.c_str());
        std::printf("Wall: %s\t\n", this->wall.c_str());
        std::printf("Roof: %s\t\n", this->roof.c_str());
    }

private:
    std::string floor;
    std::string wall;
    std::string roof;
};

class AbstractBuilder {
public:
    AbstractBuilder() {
        house = new House();
    }

    virtual void buildFloor() = 0;
    virtual void buildWall() = 0;
    virtual void buildRoof() = 0;
    virtual House *getHouse() = 0;

    House *house;
};

class ConcreteBuilderA : public AbstractBuilder {
public:
    ConcreteBuilderA() {
        std::cout << "ConcreteBuilderA" << std::endl;
    }

    void buildFloor() {
        this->house->setFloor("Floor_A");
    }

    void buildWall() {
        this->house->setWall("Wall_A");
    }

    void buildRoof() {
        this->house->setRoof("Roof_A");
    }

    House *getHouse() {
        return this->house;
    }
};

class ConcreteBuilderB : public AbstractBuilder {
public:
    ConcreteBuilderB() {
        std::cout << "ConcreteBuilderB" << std::endl;
    }

    void buildFloor() {
        this->house->setFloor("Floor_B");
    }

    void buildWall() {
        this->house->setWall("Wall_B");
    }

    void buildRoof() {
        this->house->setRoof("Roof_B");
    }

    House *getHouse() {
        return this->house;
    }
};

class Director {
public:
    Director() {}

    void setBuilder(AbstractBuilder *iBuilder) {
        this->builder = iBuilder;
    }

    House *construct() {
        builder->buildFloor();
        builder->buildWall();
        builder->buildRoof();
        return builder->getHouse();
    }

private:
    AbstractBuilder *builder;
};

int main() {
    AbstractBuilder *builder = NULL;
    Director *director = new Director();
    House *house = NULL;

    builder = new ConcreteBuilderA();
    director->setBuilder(builder);
    house = director->construct();
    house->printHouseInfo();

    std::cout << std::endl << std::endl;

    builder = new ConcreteBuilderB();
    director->setBuilder(builder);
    house = director->construct();
    house->printHouseInfo();
}