/**
 * @author: hong
 * @date: 2022/8/12 07:30
 * @description:
 */

#ifndef MYCPLUSPLUS_ABSTRACT_FACTORY_H
#define MYCPLUSPLUS_ABSTRACT_FACTORY_H


#include <string>


// AbstractProduct
class Connect {
public:
    virtual void connect(std::string host, int port) = 0;
    virtual ~Connect()= default;
};


class Command{
private:
public:
    virtual void sql(std::string text) = 0;
    virtual ~Command()= default;
};


class Executor{
public:
    virtual void run() = 0;
    virtual ~Executor()= default;
};


// Product
class SQLConnect: public Connect{
public:
    void connect(std::string host, int port) override;
};

class SQLCommand: public Command{
public:
    void sql(std::string text) override;
};


class SQLExecutor: public Executor{
public:
    void run() override;
};


// AbstractFactory：创建一系列对象的抽象工厂类
class DBFactory{
public:
    virtual Connect* createConnect() = 0;
    virtual Command* createCommand() = 0;
    virtual Executor* createExecutor() = 0;
    virtual ~DBFactory()= default;
};


// SQL系列的抽象工厂类实现
class SQLFactory: public DBFactory{
public:
    Connect* createConnect() override;

    Command* createCommand() override;

    Executor* createExecutor() override;
};

#endif //MYCPLUSPLUS_ABSTRACT_FACTORY_H
