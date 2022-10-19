//
//  iterator_overflow.cpp
//  FirstCPP
//
//  Created by jyrnan on 2022/10/6.
//

#include <stdio.h>
#include <iostream>
using namespace::std;

class iterator_overflow {
public:
    iterator_overflow(int index, int max): _index(index), _max(max){}
    int index() {return _index;}
    int max() {return _max;}
    
    void what_happend( ostream &os = cerr) {
        os << "Internal error: current index"
        << _index <<"exceeds maximum bound: "
        << _max;
    }
private:
    int _index;
    int _max;
};
