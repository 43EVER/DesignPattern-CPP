#include <iostream>

class AbstractBall {
public:
    AbstractBall() {}

    void play() {};
};

class Basketball : public AbstractBall {
public:
    Basketball() {
        play();
    }

    void play() {
        std::cout << "LiuYang play Basketball" << std::endl;
    }
};

class Football : public AbstractBall {
public:
    Football() {
        play();
    }

    void play() {
        std::cout << "LiuYang play Football" << std::endl;
    }
};

class AbstractShirt {
public:
    AbstractShirt() {}

    void wearShirt() {};
};

class BasketballShirt : public AbstractShirt {
public:
    BasketballShirt() {
        wearShirt();
    }

    void wearShirt() {
        std::cout << "LiuYang wear Basketball Shirt" << std::endl;
    }
};

class FootballShirt : public AbstractShirt {
public:
    FootballShirt() {
        wearShirt();
    }

    void wearShirt() {
        std::cout << "LiuYang wear Football Shirt" << std::endl;
    }
};

class AbstractFactory {
public:
    virtual AbstractBall *getBall() = 0;
    virtual AbstractShirt *getShirt() = 0;
};

class BasketballFactory : public AbstractFactory {
public:
    BasketballFactory() {
        std::cout << "BasketballFactory" << std::endl;
    }
    
    AbstractBall *getBall() {
        std::cout << "LiuYang get Basketball" << std::endl;
        return new Basketball();
    }

    AbstractShirt *getShirt() {
        std::cout << "LiuYang get Basketball shirt" << std::endl;
        return new BasketballShirt();
    }
};

class FootballFactory : public AbstractFactory {
public:
    FootballFactory() {
        std::cout << "FootballFactory" << std::endl;
    }
    
    AbstractBall *getBall() {
        std::cout << "LiuYang get Football" << std::endl;
        return new Football();
    }

    AbstractShirt *getShirt() {
        std::cout << "LiuYang get Football shirt" << std::endl;
        return new FootballShirt();
    }
};

int main() {
    std::cout << "抽象工厂模式" << std::endl;

    AbstractFactory *factory = NULL;
    AbstractShirt *shirt = NULL;
    AbstractBall *ball = NULL;

    factory = new BasketballFactory();
    ball = factory->getBall();
    shirt = factory->getShirt();

    std::cout << std::endl;

    factory = new FootballFactory();
    ball = factory->getBall();
    shirt = factory->getShirt();
}