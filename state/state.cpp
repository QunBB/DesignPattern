/**
 * 这里增加一种状态的话，仅需要扩展该状态类的实现
 */ 

#include <iostream>


class NetworkState{
public:
    NetworkState *pNext;
    virtual void handle1() = 0;
    virtual void handle2() = 0;

    virtual ~NetworkState(){};
};


class OpenState: public NetworkState{
private:
    static NetworkState* pState;

public:
    static NetworkState* get();

    void handle1() override;

    void handle2() override;

    ~OpenState() = default;
};


class CloseState: public NetworkState{
private:
    static NetworkState* pState;

public:
    static NetworkState* get();

    void handle1() override;

    void handle2();

    ~CloseState() = default;
};

NetworkState* OpenState::get(){
    if (pState == nullptr){
            pState = new OpenState();
    }
    return pState;
}
void OpenState::handle1(){
    pNext = CloseState::get();
}
void OpenState::handle2(){
    std::cout << "handle2: close already" << std::endl;
    pNext = OpenState::get();
}


NetworkState* CloseState::get(){
    if (pState == nullptr){
            pState = new CloseState();
    }
    return pState;
}
void CloseState::handle1(){
    std::cout << "handle1: open already" << std::endl;
    pNext = CloseState::get();
}
void CloseState::handle2(){
    pNext = OpenState::get();
}



class Context{

private:
    NetworkState *pState;

public:
    Context(NetworkState *_pState): pState(_pState){

    }

    void request1(){
        pState->handle1();
        pState = pState -> pNext;
    }

    void request2(){
        pState->handle2();
        pState = pState -> pNext;
    }

};

// 非const静态成员变量需要在类外初始化
NetworkState* OpenState::pState = nullptr;
NetworkState* CloseState::pState = nullptr;


int main(){
    Context op(new CloseState());
    op.request1();
    op.request2();

}