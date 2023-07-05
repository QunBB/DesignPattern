#include <iostream>

/**
 * 如果IVisitor基类需要增加其他方法，如operation3
 * 那么，所有子类都需要对应增加operation3的override
*/

class IVisitor{
public:
    virtual void operation1() = 0;
    virtual void operation2() = 0;

    ~IVisitor() = default;
};


class Visitor1: public IVisitor{
public:
    void operation1() override{
        std::cout << "Visitor1 operation1" << std::endl;
    }

    void operation2() override{
        std::cout << "Visitor1 operation2" << std::endl;
    }
};


class Visitor2: public IVisitor{
public:
    void operation1() override{
        std::cout << "Visitor2 operation1" << std::endl;
    }

    void operation2() override{
        std::cout << "Visitor2 operation2" << std::endl;
    }
};