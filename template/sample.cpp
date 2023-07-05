/**
 * @author: hong
 * @date: 2023/6/12 08:06
 * @description:
 * 1、应用程序App早绑定于Library
 * 2、应用程序App需要开发主流程
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

};


class App{
public:
    bool primitive_operation2(){
        std::cout << "App Step1" << std::endl;
        return true;
    }

    bool primitive_operation4(){
        std::cout << "App Step4" << std::endl;
        return true;
    }
};


int main(){
    Library lib;
    App app;

    lib.primitive_operation1();

    if (app.primitive_operation2()){
        lib.primitive_operation3();
    }

    if (app.primitive_operation4()){
        lib.primitive_operation5();
    }

}