/**
 * @author: hong
 * @date: 2022/5/31 07:38
 * @description:
 */

#ifndef MYCPLUSPLUS_FILE_FACTORY_H
#define MYCPLUSPLUS_FILE_FACTORY_H


// 对应图中Product
class FileReader{
public:
    virtual void read()=0;
    virtual ~FileReader(){}
};

// 以下对应图中的ConcreteProduct
class BinaryFileReader: public FileReader{
public:
    void read() override;
};

class TextFileReader: public FileReader{
public:
    void read() override;
};


// 创建对象的工厂类：对应图中Creator
class FileFactory{
public:
    virtual FileReader* create()=0;
    virtual ~FileFactory(){};
};

// 不同子类的工厂类实现：以下对应图中ConcreteCreator
class BinaryFileReaderFactory: public FileFactory{
public:
    FileReader* create() override;
};

class TextFileReaderFactory: public FileFactory{
public:
    FileReader* create() override;
};
#endif //MYCPLUSPLUS_FILE_FACTORY_H
