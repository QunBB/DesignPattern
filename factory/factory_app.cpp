/**
 * @author: hong
 * @date: 2022/5/31 07:46
 * @description:
 */

#include "file_factory.h"
#include "abstract_factory.h"


// 工厂模式用例
class FactoryApp{
private:

    FileFactory* fileFactory;

public:

    // 这里传入具体工厂实现类(图中ConcreteCreator)
    // 或者可以根据字符串来获取对应的工厂类
    explicit FactoryApp(FileFactory* fileFactory){
        this->fileFactory = fileFactory;
    }

    void run(){
        // FactoryMethod：工厂方法获取对象
        FileReader* fileReader = fileFactory->create();
        // Operation
        fileReader->read();
    }

    ~FactoryApp(){
        delete fileFactory;
        fileFactory = nullptr;
    }
};


// 抽象工厂模式用例
class AbstractFactoryApp{
private:
    DBFactory* factory;

public:
    explicit AbstractFactoryApp(DBFactory* _factory): factory(_factory){};

    void run(){
        // 通过抽象工厂创建SQL相关的一系列对象
        Connect* conn = factory->createConnect();
        Command* command = factory->createCommand();
        Executor* executor = factory->createExecutor();

        conn->connect("localhost", 9000);
        command->sql("select * from tb");
        executor->run();
    }

    ~AbstractFactoryApp(){
        delete factory;
        factory = nullptr;
    }
};


int main(){
    FactoryApp app(new BinaryFileReaderFactory());
    app.run();

    AbstractFactoryApp abApp(new SQLFactory());
    abApp.run();
}