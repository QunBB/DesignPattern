#include <iostream>


// 命令对象
class Command{
public:
    virtual void execute() = 0;
    ~Command() = default;
};


// 命令对象的接收者，即真正执行命令的对象
class IReceiver{
public:
    virtual void action() = 0;
    ~IReceiver() = default;
};


class OpenCommand: public Command{
private:
    IReceiver* m_receiver;
public:
    OpenCommand(IReceiver* receiver): m_receiver(receiver){}

    void execute() override{
        m_receiver -> action();
    }
};

class OpenReceiver: public IReceiver{
public:
    void action() override{
        std::cout << "OpenCommand: 开机啦!" << std::endl;
    }
};


// 调用者，请求执行命令
class Invoker{
private:
    Command* m_command;

public:
    void SetCommand(Command* command){
        m_command = command;
    }

    void process(){
        m_command -> execute();
    }
};


int main(){
    IReceiver* receiver = new OpenReceiver();
    Command* command = new OpenCommand(receiver);

    Invoker client;
    client.SetCommand(command);
    client.process();

}