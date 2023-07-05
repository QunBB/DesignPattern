#include <iostream>

/**
 * 扩展一种ConcreteVisitor子类，就可以为Element类动态增加一种操作
 * 但缺点是，Element的子类数量需要是稳定的
*/

class Visitor;

class Element{
public:
    virtual void accept(Visitor& v) = 0;

    ~Element() = default;
};


class Visitor{
public:
    virtual void VisitConcreteElementA(Element& e) = 0;
    virtual void VisitConcreteElementB(Element& e) = 0;

    ~Visitor() = default;
};


class ConcreteVisitor1: public Visitor{
public:
    void VisitConcreteElementA(Element& e) override{
        std::cout << "ElementA Visitor1" << std::endl;
    }

    void VisitConcreteElementB(Element& e) override{
        std::cout << "ElementB Visitor1" << std::endl;
    }
};


class ConcreteVisitor2: public Visitor{
public:
    void VisitConcreteElementA(Element& e) override{
        std::cout << "ElementA Visitor2" << std::endl;
    }

    void VisitConcreteElementB(Element& e) override{
        std::cout << "ElementB Visitor2" << std::endl;
    }
};

class ElementA: public Element{
public:
    void accept(Visitor& v) override{
        v.VisitConcreteElementA(*this);
    }
};


class ElementB: public Element{
public:
    void accept(Visitor& v) override{
        v.VisitConcreteElementB(*this);
    }
};


int main(){
    ConcreteVisitor1 v1;
    ElementB b;
    b.accept(v1);
}