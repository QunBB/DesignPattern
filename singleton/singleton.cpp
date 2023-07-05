/**
 * @author: hong
 * @date: 2022/8/24 07:53
 * @description:
 */

#include <iostream>
#include <mutex>

std::mutex _mutex;


class Singleton{
private:
    Singleton(){
        std::cout << "Singleton构造函数" << std::endl;
    };

    static Singleton* instance;

    static Singleton* hungryInstance;

    static Singleton* volatile volatileInstance;

public:
    Singleton(Singleton &singleton) = delete;
    Singleton operator=(Singleton &singleton) = delete;

    static Singleton* getHungryInstance();

    static Singleton* getInstance();

    static Singleton* getInstanceLock();

    static Singleton* getInstanceLock2();

    static Singleton* getInstanceVolatile();

    void show(){
        std::cout << "instance addr: " << instance << std::endl;
    }
};

// 饿汉式，线程安全
Singleton* Singleton::getHungryInstance() {
    return hungryInstance;
}


// 单线程版本，线程不安全
Singleton* Singleton::getInstance() {
    if (instance == nullptr){
        instance = new Singleton();
    }
    return instance;
}


/**
 * 线程安全，但锁的代码过高
 * @return
 **/
Singleton* Singleton::getInstanceLock() {
    std::lock_guard<std::mutex> _lock_guard(_mutex);
    if (instance == nullptr){
        instance = new Singleton();
    }
    return instance;
}

/**
 * 双检查锁，但由于指令重排会出现问题
 * 正常指令：instance分配内存 -> 调用构造器 -> 赋值
 * 可能的指令：instance分配内存 -> 赋值(instance不为null了，此时其他线程就会跳过锁，直接返回instance) -> 调用构造器
 * @return
 */
Singleton* Singleton::getInstanceLock2() {
    if (instance == nullptr){
        std::lock_guard<std::mutex> _lock_guard(_mutex);;
        if (instance == nullptr){
            return new Singleton();
        }
    }
    return instance;
}

/**
 * c++11之后的volatile，禁止指令重排
 * @return
 */
Singleton* Singleton::getInstanceVolatile() {
    if (volatileInstance == nullptr){
        std::lock_guard<std::mutex> _lock_guard(_mutex);;
        if (volatileInstance == nullptr){
            return new Singleton();
        }
    }
    return volatileInstance;
}

// 懒汉式，在首次使用单例时，再创建对象
Singleton* Singleton::instance = nullptr;
Singleton* volatile Singleton::volatileInstance = nullptr;

// 饿汉式，一开始就初始化，因此也是线程安全，但缺点是：不管最终是否用到，都会创建对象
Singleton* Singleton::hungryInstance = new Singleton();


int main(){
    for (int i=0; i<10; i++){
        Singleton::getInstance()->show();
    }
}