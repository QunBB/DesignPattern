#include <iostream>
#include <utility>

using namespace std;


class Memento{
private:
    string state;
    
public:
    explicit Memento(string t_state): state(std::move(t_state)){}
    string getState(){
        return state;
    }
    void setState(string t_state){
        state = std::move(t_state);
    }

};


class Originator{
private:
    string state;

public:
    explicit Originator(string t_state): state(std::move(t_state)){}


    // 创建备忘录备份
    Memento createMemento(){
        Memento m(state);
        return m;
    }

    // 读取备忘录备份，恢复到原来的状态
    void setMemento(Memento m){
        state = m.getState();
    }
    void setState(string t_state){
        state = std::move(t_state);
    }
    void show(){
        std::cout << "state: " << state << std::endl;
    }
};


int main(){
    Originator o("running");
    o.show();

    Memento m = o.createMemento();

    // do something
    o.setState("failed");
    o.show();

    o.setMemento(m);
    o.show();

}