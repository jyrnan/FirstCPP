//
//  main.cpp
//  FirstCPP
//
//  Created by jyrnan on 2022/9/24.
//

#include <iostream>
#include "Stack.hpp"
#include "TestTemplate.hpp"



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

template<typename OutStream>
class PrintIt {
public:
    PrintIt(OutStream &os):_os(os){}
    
    template<typename elemType>
    void print(const elemType &elem, char delimiter = '\n'){
        _os << elem << delimiter;
        throw 45;
        
        
    }
private:
    OutStream& _os;
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    LessThan lt10(10); //初始化，并设置内部的基值为10
    bool b = lt10(9);
    cout <<  b << endl;
    
    Stack stack;
    cout << stack.size() << endl;
    
    TestTmeplate<int> temp;
    temp.print();
    
    try {
        PrintIt<ostream> to_standard_out(cout);
        to_standard_out.print("Hello world");
    }
    catch (int num) {
        cout << num << "错误出现了" << endl;
    }
    
    return 0;
}

template<typename  elemType>
class lessThanCopy {
public:
            lessThanCopy(const elemType &val): _val(val) {}
    bool    operator()(elemType &val) const {
        return val < _val;
    }
    void    val(elemType &newval) {
        _val = newval;
    }
    elemType val() {return _val;}
private:
    elemType _val;
};

template<typename elemType, typename BinaryComp>
class StringLen {
public:
    bool operator()(const elemType &s1, const elemType &s2) {return BinaryComp(s1, s2);}
};

struct Demo {
    int a, b;
    
    void increase(int x) {
        a += x;
    }
};

class MyClass {
public:
    int a, b;
    
private:
    void empty() {

    }
};

class MyClass2 {
public:
    
};
