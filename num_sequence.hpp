//
//  num_sequence.hpp
//  FirstCPP
//
//  Created by jyrnan on 2022/9/30.
//

#ifndef num_sequence_hpp
#define num_sequence_hpp

#include <stdio.h>
#include <iostream>
using namespace::std;

class num_sequence {
public:
    virtual ~num_sequence(){};
    
    virtual int elem( int pos) const = 0;
    virtual const char* what_am_i() const = 0;
    static int max_elems(){ return _max_elems; }
    virtual ostream& print( ostream &os = cout) const = 0;

protected:
    virtual void gen_elems( int pos) const = 0;
    bool check_integrity( int pos ) const;
    const static int _max_elems = 8;
    
};

#endif /* num_sequence_hpp */
