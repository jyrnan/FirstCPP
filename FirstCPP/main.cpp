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

class Entity {
public:
    Entity() {
        std::cout << "Construct Entity" << std::endl;
    }
    
    ~Entity() {
        std::cout << "Destruct Entity" << std::endl;
    }
};

template<class T>
class ScopedPtr {
private:
    T* m_ptr;
public:
    ScopedPtr(T* ptr) : m_ptr(ptr) {
        
    }
    ~ScopedPtr() {
        delete m_ptr;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    ScopedPtr e = new Entity();
    
    return 0;
}
