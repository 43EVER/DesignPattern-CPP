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

class AbstractFactory {
public:
    virtual AbstractProduct *getSupportProduct() = 0;
};

class BasketballFactory : public AbstractFactory {
public:
    BasketballFactory() {
        std::cout << "BasketballFactory" << std::endl;
    }

    AbstractProduct *getSupportProduct() {
        std::cout << "basketball" << std::endl;
        return new Basketball();
    }
};

class FootballFactory : public AbstractFactory {
public:
    FootballFactory() {
        std::cout << "FootballFactory" << std::endl;
    }

    AbstractProduct *getSupportProduct() {
        std::cout << "football" << std::endl;
        return new Football();
    }
};

class VolleyballFactory : public AbstractFactory {
public:
    VolleyballFactory() {
        std::cout << "VolleyballFactory" << std::endl;
    }

    AbstractProduct *getSupportProduct() {
        std::cout << "volleyball" << std::endl;
        return new Volleyball();
    }
};

int main() {
    AbstractFactory *factory = NULL;
    AbstractProduct *product = NULL;

    factory = new BasketballFactory();
    product = factory->getSupportProduct();
    
    factory = new FootballFactory();
    product = factory->getSupportProduct();

    factory = new VolleyballFactory();
    product = factory->getSupportProduct();
}