/**
 * @author: hong
 * @date: 2022/5/18 07:47
 * @description:
 */

#include <iostream>
using namespace std;

class Stream{
public:
    virtual void read(int) = 0;

    virtual void write(char[]) = 0;
};

class FileStream: public Stream{
    virtual void read(int){
        cout << "file reading...." << endl;
    }

    virtual void write(char[]){
        cout << "file writing...." << endl;
    }
};


class MemoryStream: public Stream{
    virtual void read(int){
        cout << "memory reading...." << endl;
    }

    virtual void write(char[]){
        cout << "memory writing...." << endl;
    }
};

// 扩展功能
class DecoratorSteam: public Stream{
protected:
    Stream* m_stream;
    DecoratorSteam(Stream* stream): m_stream(stream){

    }
};

class CryptoStream: public DecoratorSteam{
public:
    CryptoStream(Stream* stream): DecoratorSteam(stream){

    }

    virtual void read(int size){
        m_stream->read(size);
        cout << "read 加密操作...." << endl;
    }

    virtual void write(char data[]){
        m_stream->write(data);
        cout << "write 加密操作...." << endl;
    }
};

class BufferedStream: public DecoratorSteam{
public:
    BufferedStream(Stream* stream): DecoratorSteam(stream){

    }

    virtual void read(int size){
        m_stream->read(size);
        cout << "read 缓存操作...." << endl;
    }

    virtual void write(char data[]){
        m_stream->write(data);
        cout << "write 缓存操作...." << endl;
    }
};


int main(){
    FileStream s1;
    CryptoStream s2(&s1);
    BufferedStream s3(&s2);

    s2.read(0);
    s3.read(0);
    char data[] = "test";
    s3.write(data);
}