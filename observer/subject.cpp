/**
 * @author: hong
 * @date: 2022/5/9 11:24
 * @description:
 */

#include <iostream>
#include <list>
#include "unistd.h"
#include "observer.h"
using namespace std;

class Subject {
private:
    list<Observer*> m_observers;
    float m_state;

public:
    // 观察者订阅
    void attach(Observer* observer){
        m_observers.push_back(observer);
    }
    // 取消订阅
    void detach(Observer* observer){
        m_observers.remove(observer);
    }
    // 通知传播
    void notify(float state){
        for (Observer* ob: m_observers){
            ob->update(state);
        }
    }

    void setState(float state){
        m_state = state;
        notify(m_state);
    }

    float getState(){
        return m_state;
    }

};