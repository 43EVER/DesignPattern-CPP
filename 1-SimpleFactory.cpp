#include <iostream>

class AbstractProduct {
public:
    AbstractProduct() {}

    void printName() {}
    void play() {}

    virtual ~AbstractProduct() {}
};

class Basketball : public AbstractProduct {
public:
    Basketball() {
        printName();
        play();
    }

    void printName() {
        std::cout << "get Basketball" << std::endl;
    }

    void play() {
        std::cout << "play Basketball" << std::endl;
    }
};

class Football : public AbstractProduct {
public:
    Football() {
        printName();
        play();
    }

    void printName() {
        std::cout << "get Football" << std::endl;
    }

    void play() {
        std::cout << "play Football" << std::endl;
    }
};

class Volleyball : public AbstractProduct {
public:
    Volleyball() {
        printName();
        play();
    }

    void printName() {
        std::cout << "get Volleyball" << std::endl;
    }

    void play() {
        std::cout << "play Volleyball" << std::endl;
    }
};

class Factory {
public:
    AbstractProduct *getSupportProduct (std::string productName) {
        AbstractProduct *product = NULL;
        
        if (productName == "Basketball") {
            product = new Basketball();
        } else if (productName == "Football") {
            product = new Football();
        } else if (productName == "Volleyball") {
            product = new Volleyball();
        }
        
        return product;
    }
};

int main() {
    std::cout << "简单工厂模式" << std::endl;

    auto factory = new Factory();
    AbstractProduct *product = NULL;
    product = factory->getSupportProduct("Basketball");
    product = factory->getSupportProduct("Football");
    product = factory->getSupportProduct("Volleyball");

    return 0;
}