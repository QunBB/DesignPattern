/**
 * @author: hong
 * @date: 2022/5/7 7:51 上午
 * @description: if-else分支扩展时，违反开放封闭原则
 */

#include <iostream>
using namespace std;

enum Tax{
    CN,
    JP,
    EN
};


class App{
    Tax m_tax;
public:
    App(Tax tax): m_tax(tax){

    }

    void Cal(){
        if (m_tax == CN){
            cout << "中国税率" << endl;
        }
        else if(m_tax == JP){
            cout << "日本税率" << endl;
        }
        else if(m_tax == EN){
            cout << "英国税率" << endl;
        }
    }
};

int main(){

}