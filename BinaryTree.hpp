//
//  BinaryTree.hpp
//  FirstCPP
//
//  Created by jyrnan on 2022/10/6.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#include <iostream>
using namespace::std;

template< typename  elemType>
class BinaryTree;

template <typename elemType>
class BTNode;

//BTNode
template<typename valType>
class BTNode {
    friend BinaryTree<valType>;
    static void lchild_leaf(BTNode *leaf, BTNode *subTree);
    
public:
    BTNode( const valType &val );
    void insert_value( const valType &val );
    void remove_value(const valType &val, BTNode *& prev);
    void preorder( BTNode *pt, std::ostream &os ) const;
    
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
    
    void clear(){ if ( _root ) { clear( _root ); _root = 0; }}
    
    void insert( const elemType &elem);
    void remove( const elemType &elem );
    
    void remove_root();
    
    void preorder(std::ostream &os = std::cout) {_root->preorder(_root, os);}

private:
    BTNode<elemType> *_root;
    
    void copy( BTNode<elemType>* tar, BTNode<elemType>src );
    void clear( BTNode<elemType>*);
};

#endif /* BinaryTree_hpp */
