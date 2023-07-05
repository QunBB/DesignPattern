/**
 * @author: hong
 * @date: 2023/6/12 08:14
 * @description:
 * 1、Library晚绑定于应用程序APP
 * 2、主流程由Library开发
 */


#include <iostream>

class Library{
public:
    void primitive_operation1(){
        std::cout << "Library Step1" << std::endl;
    }

    void primitive_operation3(){
        std::cout << "Library Step4" << std::endl;
    }

    void primitive_operation5(){
        std::cout << "Library Step5" << std::endl;
    }

    // 主流程
    void template_method(){
        primitive_operation1();

        if (primitive_operation2()){
            primitive_operation3();
        }

        if (primitive_operation4()){
            primitive_operation5();
        }
    }

    virtual ~Library(){}

protected:
    virtual bool primitive_operation2() = 0;
    virtual bool primitive_operation4() = 0;

};


class Client: public Library{
public:
    virtual bool primitive_operation2(){
        std::cout << "Client Step1" << std::endl;
        return true;
    }

    virtual bool primitive_operation4(){
        std::cout << "Client Step4" << std::endl;
        return true;
    }
};


int main(){
    Library* app = new Client();
    app->template_method();
    delete app;
}