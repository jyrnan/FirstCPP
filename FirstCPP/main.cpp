//
//  main.cpp
//  FirstCPP
//
//  Created by jyrnan on 2022/9/24.
//

#include <iostream>
#include "Stack.hpp"
#include "TestTemplate.hpp"
#include "StringDemo.hpp"
#include <memory>

void printString(const StringDemo& string) {
    std::cout << string.m_buffer << std::endl;
}

template<typename T>
void printcopy(T value) {
    std::cout << value << std::endl;
}

template<>
void printcopy(std::string value) {
    std::cout << "string: " << value << std::endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    printcopy<int>(5);
    std::string str("hello string2");
    printcopy(str);

    
    unique_ptr<StringDemo> u_ptr = make_unique<StringDemo>(StringDemo("Unique StringDemo"));
    printString(*u_ptr);
    
    return 0;
}
