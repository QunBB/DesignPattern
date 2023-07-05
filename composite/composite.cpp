#include <iostream>
#include <list>
#include <utility>


class Component{

protected:
    std::string message;

private:
    // 这部分对于Leaf不需要实现，因此使用private，并且不设置未纯虚函数
    virtual void add(Component* element){};
    virtual void remove(Component* element){};

public:
    virtual void operation() = 0;
    virtual ~Component()= default;
};


// 树结构
class Composite: public Component{

private:
    std::list<Component*> children;

public:
    // 基类的成员变量 无法使用初始化列表
    explicit Composite(std::string m){
        message = std::move(m);
    }

    void operation() override{
        std::cout << "Composite: " << message << std::endl;
        for (std::list<Component*>::iterator it = children.begin(); it != children.end(); it++){
            (*it) -> operation();
        }
    }

    void add(Component* element) override{
        children.push_back(element);
    }

    void remove(Component* element) override{
        children.remove(element);
    }
};


// 叶子结点
class Leaf: public Component{

public:
    explicit Leaf(std::string m){
        message = std::move(m);
    }

    void operation() override{
        std::cout << "Leaf: " << message << std::endl;
    }
};


int main(){
    Composite root("root");
    Composite tree("tree1");

    Leaf leaf("leaf1");
    
    root.add(&tree);
    tree.add(&leaf);

    // 使用一致性
    // 对组合对象的处理等同单个对象，"一对多" -> "一对一"

    // 组合对象
    root.operation();

    // 单个对象
    leaf.operation();
    
}