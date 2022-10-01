//
//  num_sequence.cpp
//  FirstCPP
//
//  Created by jyrnan on 2022/9/30.
//

#include "num_sequence.hpp"

bool num_sequence::
check_integrity(int pos) const {
    if (pos <= 0 || pos > _max_elems ) {
        cerr << "!! invalid position: " << pos << " Cannot honor request\n";
        return false;
    }
    
    return true;
}

ostream& operator<<( ostream &os, const num_sequence &ns) {
    return ns.print( os );
}
