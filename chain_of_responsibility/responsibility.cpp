#include <iostream>


enum Request{
    Request1,
    Request2
};


class IHandler{
protected:
    IHandler* pNext = nullptr;
    virtual bool process(Request& request) = 0;

public:
    void setNextChain(IHandler* handler){
        pNext = handler;
    };

    void handleRequest(Request& request){
        bool flag = process(request);
        if (!flag){
            if (pNext != nullptr){
                pNext -> handleRequest(request);
            }
        }
    }

    ~IHandler() = default;

};


class Handler1: public IHandler {
public:
    bool process(Request& request) override{
        if (request == Request1){
            std::cout << "Handler1 handle Request1" << std::endl;
            return true;
        }
        return false;
    }
};


class Handler2: public IHandler {
public:
    bool process(Request& request) override{
        if (request == Request2){
            std::cout << "Handler2 handle Request2" << std::endl;
            return true;
        }
        return false;
    }
};


int main(){
    Request req = Request2;
    
    Handler1 handler1;
    Handler2 handler2;
    handler1.setNextChain(&handler2);

    handler1.handleRequest(req);
}