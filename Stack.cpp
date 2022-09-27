//
//  Stack.cpp
//  FirstCPP
//
//  Created by jyrnan on 2022/9/27.
//

#include "Stack.hpp"

inline bool
Stack::empty() {
    return _stack.empty();
}

bool
Stack::pop( string &elem) {
    if (empty()){
        return false;
    }
    
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

inline bool Stack::full() {return _stack.size() == _stack.max_size();}

bool Stack::peek(string &elem){
    if (empty()) {
        return false;
    }
    
    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem){
    if (full()){
        return false;
    }
    
    _stack.push_back(elem);
    return true;
}
