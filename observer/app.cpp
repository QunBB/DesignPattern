/**
 * @author: hong
 * @date: 2022/5/12 08:02
 * @description:
 */

#include <iostream>
#include "observer.h"
#include "subject.cpp"


int main(){
    Subject subject;

    subject.attach(new FirstObserver());
    subject.attach(new SecondObserver());

    subject.setState(0.5);

    subject.setState(0.8);
}