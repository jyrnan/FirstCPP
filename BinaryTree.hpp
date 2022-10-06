//
//  BinaryTree.hpp
//  FirstCPP
//
//  Created by jyrnan on 2022/10/6.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>

template< typename  elemType>
class BinaryTree;

//BTNode
template<typename valType>
class BTNode {
    friend BinaryTree<valType>;
    
public:
    BTNode( const valType &val );
    void insert_value( const valType &val );
    
private:
    valType _val;
    int     _cnt;
    BTNode  *_lchild;
    BTNode  *_rchild;
};

//BinaryTree
template <typename elemType>
class BinaryTree {
public:
    BinaryTree();
    BinaryTree( const BinaryTree& );
    ~BinaryTree();
    BinaryTree& operator=( const BinaryTree& );
    
    bool empty() {return _root = 0; }
    void clear();
    
    void insert( const elemType &elem);

private:
    BTNode<elemType> *_root;
    
    void copy( BTNode<elemType>* tar, BTNode<elemType>src );
};

#endif /* BinaryTree_hpp */
