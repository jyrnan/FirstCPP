//
//  StringDemo.hpp
//  FirstCPP
//
//  Created by jyrnan on 2022/10/19.
//

#ifndef StringDemo_hpp
#define StringDemo_hpp

#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <iostream>

class StringDemo {
public:
    StringDemo(char* string) : m_size(strlen(string)) {
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, string, m_size + 1);
        std::cout << "Constructed" << std::endl;
    }
    
    StringDemo(const StringDemo& other) {
        m_buffer = new char[other.m_size + 1];
        m_size = other.m_size;
        memcpy(m_buffer, other.m_buffer, m_size + 1);
    }
    
    ~StringDemo() {
        delete[] m_buffer;
        std::cout << "Destructed" << std::endl;
    }
    
    friend void printString(const StringDemo& string);
private:
    char* m_buffer;
    int m_size;
};


#endif /* StringDemo_hpp */
