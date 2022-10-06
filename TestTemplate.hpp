//
//  TestTemplate.hpp
//  FirstCPP
//
//  Created by jyrnan on 2022/10/6.
//

#ifndef TestTemplate_hpp
#define TestTemplate_hpp

#include <stdio.h>
#include <iostream>
using namespace::std;

template<typename T>
class TestTmeplate {
public:
    TestTmeplate();
    ~TestTmeplate();
    void print(){cout << "this is a testTemplate object" << endl;};
private:
    T *_val;
};

template<typename T>
TestTmeplate<T>::TestTmeplate(): _val(0) {
    cout << "test template object constructed" << endl;
}

template<typename T>
TestTmeplate<T>::~TestTmeplate(){
    cout << "test template object destructed" << endl;
}

#endif /* TestTemplate_hpp */
