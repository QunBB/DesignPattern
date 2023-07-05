/**
 * @author: hong
 * @date: 2022/5/23 07:51
 * @description:
 * 桥模式将抽象和实现分离，可以各自往自己的维度变化
 * 抽象 -> PC&Mobile&...
 * 实现-> Lite&Perfect&...
 */

#include <iostream>
using namespace std;

// 实现部分，对应Implementor
class MessagerImp{
public:
    // 实现
    virtual void connect() = 0;
    virtual void writeMessage(string message) = 0;
    virtual void playSound() = 0;

    ~MessagerImp(){};
};

// 抽象部分，对应RefinedAbstraction
class Messager{

protected:
    MessagerImp* messagerImp;

public:
    // 抽象
    virtual void login() = 0;
    virtual void sendMessage(string message) = 0;

    ~Messager(){};
};

class PCMessagerBase: public MessagerImp{
    // 实现
    virtual void connect(){
        cout << "PC connect" << endl;
    };
    virtual void writeMessage(string message){
        cout << "PC write message: " << message << endl;
    };

    virtual void playSound(){
        cout << "PC playing Sound" << endl;
    };
};

class MessagerLite: public Messager{
public:
    MessagerLite(MessagerImp* imp){
        messagerImp = imp;
    }
    virtual void login(){
        messagerImp->connect();
    };
    virtual void sendMessage(string message){
        messagerImp->writeMessage(message);
    };
};

class MessagerPerfect: public Messager{
public:
    MessagerPerfect(MessagerImp* imp){
        messagerImp = imp;
    }
    virtual void login(){
        messagerImp->connect();
        messagerImp->playSound();
    };
    virtual void sendMessage(string message){
        messagerImp->writeMessage(message);
        messagerImp->playSound();
    };
};


int main(){
    MessagerPerfect pcMessagerPerfect(new PCMessagerBase);
    pcMessagerPerfect.login();
    pcMessagerPerfect.sendMessage("test");
}