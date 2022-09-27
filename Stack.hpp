//
//  Stack.hpp
//  FirstCPP
//
//  Created by jyrnan on 2022/9/27.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <string>
#include <vector>

using  namespace::std;

class Stack {
public:
    bool push( const  string&);
    bool pop( string& elem);
    bool peek( string& elem);
    
    bool empty();
    bool full();
    
    int size() {return _stack.size();}
    
private:
    vector<string> _stack;
};

#endif /* Stack_hpp */
