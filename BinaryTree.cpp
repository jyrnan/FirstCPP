//
//  BinaryTree.cpp
//  FirstCPP
//
//  Created by jyrnan on 2022/10/6.
//

#include "BinaryTree.hpp"

template< typename elemType >
inline BinaryTree<elemType>::
BinaryTree() { }

template< typename elemType >
inline BinaryTree<elemType>::
BinaryTree( const BinaryTree &rhs) {
    copy(_root, rhs._root);
}

template<typename  elemType>
inline BinaryTree<elemType>::
~BinaryTree() { clear(); }

template<typename elemType>
inline BinaryTree<elemType>&
BinaryTree<elemType>::
operator=(const BinaryTree<elemType> &rhs) {
    if ( this != rhs) {
        clear();
        copy(_root, rhs._root);
    }
    return *this;
}

