/**
 * @author: hong
 * @date: 2022/5/12 07:34
 * @description:
 */

#ifndef MYCPLUSPLUS_OBSERVER_H
#define MYCPLUSPLUS_OBSERVER_H


class Observer{
public:
    virtual void update(float state) = 0;
    virtual ~Observer()= default;

};

class FirstObserver: public Observer{
    void update(float state) override;
};

class SecondObserver: public Observer{
    void update(float state) override;
};


#endif //MYCPLUSPLUS_OBSERVER_H
