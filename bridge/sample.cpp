/**
 * @author: hong
 * @date: 2022/5/20 07:58
 * @description:
 * Messager有两个变化的维度：抽象-PC&Mobile，实现-Lite&Perfect
 * 多继承实现这种多维度变化
 */

#include <iostream>
using namespace std;

class Messager{
public:
    // 抽象
    virtual void login() = 0;
    virtual void sendMessage(string message) = 0;

    // 实现
    virtual void connect() = 0;
    virtual void writeMessage(string message) = 0;
    virtual void playSound() = 0;

    ~Messager(){};
};

class PCMessagerBase: public Messager{
public:

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

class MobileMessagerBase: public Messager{
public:

    virtual void connect(){
        cout << "Mobile connect" << endl;
    };
    virtual void writeMessage(string message){
        cout << "Mobile write message: " << message << endl;
    };
    virtual void playSound(){
        cout << "Mobile playing Sound" << endl;
    };

};

class PCMessagerLite: public PCMessagerBase{
public:
    virtual void login(){
        PCMessagerBase::connect();
    };
    virtual void sendMessage(string message){
        PCMessagerBase::writeMessage(message);
    };
};

class PCMessagerPerfect: public PCMessagerBase{
public:
    virtual void login(){
        PCMessagerBase::connect();
        PCMessagerBase::playSound();
    };
    virtual void sendMessage(string message){
        PCMessagerBase::writeMessage(message);
        PCMessagerBase::playSound();
    };
};

// MobileMessagerLite
// MobileMessagerLite