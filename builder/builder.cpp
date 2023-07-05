/**
 * @author: hong
 * @date: 2022/8/19 08:00
 * @description:
 * 简单版本的Builder模式
 */

#include <iostream>


class House{
public:
    // 构建过程是稳定
    void init(){
        builderPart1();
        bool flag = builderPart2();
        if (flag){
            builderPart3();
        }

    }
protected:
    // 但每个步骤是变化的
    virtual void builderPart1() = 0;
    virtual bool builderPart2() = 0;
    virtual void builderPart3() = 0;
};


class StoneHouse: public House{
protected:
    void builderPart1() override{
        std::cout << "StoneHouse builderPart1" << std::endl;
    }
    bool builderPart2() override{
        std::cout << "StoneHouse builderPart2" << std::endl;
        return true;
    }
    void builderPart3() override{
        std::cout << "StoneHouse builderPart3" << std::endl;
    }
};


int main(){
    House* house = new StoneHouse();
    house -> init();
}