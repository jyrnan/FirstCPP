//
//  main.cpp
//  FirstCPP
//
//  Created by jyrnan on 2022/9/24.
//

#include <iostream>
#include "Stack.hpp"



class LessThan {
public:
    LessThan(int val) : _val(val){}
    int comp_val() const {return _val;} // 基值的读取
    void comp_val(int nval) {_val = nval;} // 基值的写入
    
    bool operator()(int _value) const;
    
private:
    int _val;
};

inline bool  LessThan::
operator()(int value) const {return value < _val;}

class num_sequence {
public:
    typedef void (num_sequence::*PtrType)(int);
    
    //_pmf可指向下列任何函数
    void fibonoacci( int );
    void pell( int );
    //...
    
private:
    PtrType _pmf;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    LessThan lt10(10); //初始化，并设置内部的基值为10
    bool b = lt10(9);
    cout <<  b << endl;
    
    
    return 0;
}




