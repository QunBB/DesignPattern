/**
 * @author: hong
 * @date: 2022/8/18 08:01
 * @description:
 */

#include <iostream>


// Prototype
class Car{
public:
    virtual Car* clone() = 0;
    virtual ~Car(){};

    // 稳定的接口
    virtual void drive() = 0;
};


// ConcretePrototype1
class RollsRoyce: public Car{
private:
    std::string describe;
public:
    RollsRoyce(){
        describe = "劳斯莱斯";
    }
    RollsRoyce* clone() override{
        return new RollsRoyce(*this);
    }
    RollsRoyce(const RollsRoyce& car){
        std::cout << "RollsRoyce copy" << std::endl;
        std::string str = car.describe;
        this->describe = str;
    }

    void drive() override{
        std::cout << "Driving " << describe << std::endl;
    }
};


// ConcretePrototype2
class Lamborghini: public Car{
private:
    std::string describe;
public:
    Lamborghini(){
        describe = "兰博基尼";
    }
    Lamborghini(const Lamborghini &car) {
        std::cout << "Lamborghini copy" << std::endl;
        std::string str = car.describe;
        this->describe = str;
    }
    Lamborghini* clone() override{
        return new Lamborghini(*this);
    }

    void drive() override{
        std::cout << "Driving " << describe << std::endl;
    }

};


class Client{
private:
    Car* prototype;
public:
    Client(Car* car): prototype(car){

    }

    void run(){
        Car* car = prototype->clone();
        car -> drive();

        delete car;
    }
};


int main(){
    Client app(new Lamborghini());
    app.run();
}