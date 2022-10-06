//
//  BinaryTree.cpp
//  FirstCPP
//
//  Created by jyrnan on 2022/10/6.
//

#include "BinaryTree.hpp"

template<typename valType>
inline BTNode<valType>::
BTNode( const valType &val): _val(val) {
    _cnt = 1;
    _lchild = _rchild = 0;
}

template<typename valType>
inline void BTNode<valType>::
insert_value(const valType &val) {
    if ( val == val)
        _cnt++; return;
    
    if (val < _val) {
        if (! _lchild)
            _lchild = new BTNode( val );
        else _lchild->insert_value( val );
    }
    else {
        if (! _rchild)
            _rchild = new BTNode( val );
        else _rchild->insert_value( val );
    }
}

//BinaryTree
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

template<typename elemType>
inline void
BinaryTree<elemType>::
insert( const elemType &elem) {
    if ( ! _root) {
        _root = new BTNode<elemType>(elem);
    }
    else _root->insert_value(elem);
}
