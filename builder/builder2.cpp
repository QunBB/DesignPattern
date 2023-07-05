/**
 * @author: hong
 * @date: 2022/8/19 08:00
 * @description:
 * Builder模式：将构建过程和实现步骤拆分
 */

#include <iostream>


// Product
class House{
public:
    std::string color;
    float area;

    virtual void show() = 0;
};

// 对应图中的Builder
// 每个步骤方法
class HouseBuilder{
    friend class HouseDirector;

public:
    virtual House* getResult() = 0;
protected:
    House* pHouse;
    virtual void builderPart1() = 0;
    virtual bool builderPart2() = 0;
    virtual void builderPart3() = 0;
};


// Product子类/实现类
class StoneHouse: public House{
public:
    void show() override{
        std::cout << "color: " << color << std::endl;
        std::cout << "area: " << area << std::endl;
    }
};


// 对应图中的ConcreteBuilder
class StoneHouseBuilder: public HouseBuilder{
public:
//    StoneHouseBuilder(House* _pHouse): pHouse(_pHouse){};
    House* getResult() override{
    return pHouse;
}
protected:
    House* pHouse = new StoneHouse();

    void builderPart1() override{
        pHouse -> color = "yellow";
        std::cout << "StoneHouse builderPart1" << std::endl;
    }
    bool builderPart2() override{
        pHouse -> area = 100.;
        std::cout << "StoneHouse builderPart2: color is " << pHouse->color << std::endl;
        return true;
    }
    void builderPart3() override{
        std::cout << "StoneHouse builderPart3: area is " << pHouse->area << std::endl;
    }
};

// Director
// Product的构建过程，稳定的
class HouseDirector{
    HouseBuilder* pHouseBuilder;

public:
    HouseDirector(HouseBuilder* _pHouseBuilder): pHouseBuilder(_pHouseBuilder){

    }

    House* init(){
        pHouseBuilder -> builderPart1();
        bool flag = pHouseBuilder -> builderPart2();
        if (flag){
            pHouseBuilder -> builderPart3();
        }

        return pHouseBuilder -> getResult();
    }
};


int main(){
    HouseDirector director(new StoneHouseBuilder());
    House* house = director.init();
    house -> show();
}