/**
 * @author: hong
 * @date: 2022/5/18 07:38
 * @description:
 */

#include <iostream>
using namespace std;

class Stream{
public:
    virtual void read() = 0;

    virtual void write(char[]) = 0;
};

class FileStream: public Stream{
public:
    virtual void read(){
        cout << "file reading...." << endl;
    }

    virtual void write(const char[]){
        cout << "file writing...." << endl;
    }
};


class MemoryStream: public Stream{
public:
    virtual void read(){
        cout << "memory reading...." << endl;
    }

    virtual void write(const char[]){
        cout << "memory writing...." << endl;
    }
};


class CryptoFileStream: public FileStream{
    virtual void read(int){
        FileStream::read();
        cout << "加密操作...." << endl;
    }

    virtual void write(char[]){
        FileStream::write("");
        cout << "加密操作........" << endl;
    }
};


class CryptoMemoryStream: public MemoryStream{
    virtual void read(int){
        MemoryStream::read();
        cout << "read 加密操作...." << endl;
    }

    virtual void write(char[]){
        MemoryStream::write("");
        cout << "write 加密操作........" << endl;
    }
};