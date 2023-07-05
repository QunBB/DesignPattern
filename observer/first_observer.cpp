/**
 * @author: hong
 * @date: 2022/5/12 07:59
 * @description:
 */

#include <iostream>
#include "observer.h"

using namespace std;


void FirstObserver::update(float state){
    cout << "FirstObserver: " << state << endl;
}
