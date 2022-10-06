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

template<typename valType>
class BTNode {
    friend BinaryTree<valType>;
    
public:
private:
    valType _val;
    int     _cnt;
    BTNode  *_lchild;
    BTNode  *_rchild;
};

template <typename elemType>
class BinaryTree {
public:
    BinaryTree();
    BinaryTree( const BinaryTree& );
    ~BinaryTree();
    BinaryTree& operator=( const BinaryTree& );
    
    bool empty() {return _root = 0; }
    void clear();
private:
    BTNode<elemType> *_root;
    
    void copy( BTNode<elemType>* tar, BTNode<elemType>src );
};

#endif /* BinaryTree_hpp */
