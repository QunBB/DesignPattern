/**
 * @author: hong
 * @date: 2022/8/30 07:52
 * @description:
 */

#include <iostream>


// 目标新接口
class ITarget{
public:
    virtual void process() = 0;
};


// 遗留接口，待适配者
class IAdaptee{
public:
    virtual int create() = 0;
    virtual void run(int runner) = 0;
};
// 遗留接口实现
class Legacy: public IAdaptee{
public:
    int create() override{
        std::cout << "Legacy Create" << std:: endl;
    };
    void run(int runner) override{
        std::cout << "Legacy Runner" << std:: endl;
    };
};

// 目标接口适配器，适配遗留接口
// 对象适配器
class Adapter: public ITarget{
    IAdaptee* pIAdaptee;
public:
    Adapter(IAdaptee* iAdaptee): pIAdaptee(iAdaptee){

    }
    void process() override{
        int runner = pIAdaptee -> create();
        pIAdaptee ->run(runner);
    }
};


// 类适配器，多继承的方式，紧耦合，不推荐使用
// protect继承意味仅需使用它的实现
class ClassAdapter: public ITarget, protected Legacy{
public:
    ClassAdapter()= default;

    void process() override{
        int runner = create();
        run(runner);
    }
};


int main(){
    Adapter adapter(new Legacy());
    adapter.process();

    ClassAdapter adapter2;
    adapter2.process();
}