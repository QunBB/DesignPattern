#include <iostream>

enum NetworkState{
    Open,
    Close
    // 这里再增加一种状态的话，下面的operation1和operation2都需要修改
};


class Context{
    NetworkState state;

    void handle1(){
        if (state == Open){
            state = Close;
        } 
        else if (state == Close){
            std::cout << "operation1: close already" << std::endl;
        }
    }

    void handle2(){
        if (state == Open){
            std::cout << "operation2: open already" << std::endl;
        } 
        else if (state == Close){
            state = Open;
        }
    }
};