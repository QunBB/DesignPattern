/**
 * @author: hong
 * @date: 2022/5/7 7:51 上午
 * @description: 策略模式 代替if-else分支
 */

#include <iostream>
using namespace std;

class TaxStrategy{
public:
    virtual void cal() = 0;
    virtual ~TaxStrategy(){};
};

class CNTax: public TaxStrategy{
    virtual void cal(){
        cout << "中国税率" << endl;
    }
};

class JPTax: public TaxStrategy{
    virtual void cal(){
        cout << "日本税率" << endl;
    }
};

class ENTax: public TaxStrategy{
    virtual void cal(){
        cout << "英国税率" << endl;
    }
};

class Client{
    TaxStrategy* m_tax;
public:
    Client(TaxStrategy* tax): m_tax(tax){

    }
    ~Client(){
        delete this->m_tax;
    }

    void cal(){
        m_tax->cal();
    }
};

int main(){
//    CNTax cn;
//    Client app(&cn);

    Client app(new CNTax);

    app.cal();
}