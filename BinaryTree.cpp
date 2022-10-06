//
//  BinaryTree.cpp
//  FirstCPP
//
//  Created by jyrnan on 2022/10/6.
//

#include "BinaryTree.hpp"

template< typename  elemType>
class BinaryTree;

template <typename elemType>
class BTNode;

template<typename valType>
inline BTNode<valType>::
BTNode( const valType &val): _val(val) {
    _cnt = 1;
    _lchild = _rchild = 0;
}

//创建左叶子
template<typename valType>
void BTNode<valType>::
lchild_leaf(BTNode<valType> *leaf, BTNode<valType> *subTree) {
    while (subTree->_lchild)
        subTree = subTree->_lchild;
    subTree->_lchild = leaf;
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

template<typename valType>
void BTNode<valType>::
remove_value(const valType &val, BTNode<valType> *& prev) { //prev其实是当前节点
    if (val < _val) {
        if (! _lchild)
            return; //不在此二叉树中
        else _lchild->remove_value(val, _lchild);
    }
    else
        if (val > _val) {
            if (! _rchild)
                return; //不在此二叉树中
            else _rchild->remove_value(val, _rchild);
                
        }
        else {
            //ok: 找到了
            //重置此树，然后删除此节点
            
            if (_rchild) {
                prev = _rchild;
                if (_lchild)
                    if ( ! prev->_lchild )
                        {
                            prev->_lchild = _lchild;
                        }
                    else
                    {
                        BTNode<valType>::lchild_leaf(_lchild, prev->_lchild);
                        
                    }
            }
            else prev = _lchild;
            delete this;
        }
}

template<typename valType>
void BTNode<valType>::
preorder(BTNode<valType> *pt, std::ostream &os) const {
    if (pt) {
        display_val(pt, os);
        if (pt-> _lchild) preorder(pt->_lchild, os);
        if (pt-> _rchild) preorder(pt->_rchild, os);
        
    }
}

//BinaryTree
template< typename elemType >
inline
BinaryTree<elemType>::
BinaryTree()
    : _root(0) { }

template< typename elemType >
inline BinaryTree<elemType>::
BinaryTree( const BinaryTree &rhs) {
    copy(_root, rhs._root);
}

template<typename  elemType>
inline BinaryTree<elemType>::
~BinaryTree() {
//    clear();
    
}


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

template<typename elemType>
inline void
BinaryTree<elemType>::
remove(const elemType &elem){
    if (_root)
        remove_root();
    else
        _root->remove_value(elem, _root);
}

template<typename elemType>
void BinaryTree<elemType>::
remove_root()
{
    if (! _root) return;
    
    BTNode<elemType> *tmp = _root;
    if ( _root->_rchild)
    {
        _root = _root->_rchild;
        
        //现在我们必须讲左子节点搬移到右子节点的左子树的底部
        if (tmp->_lchild)
        {
            //为了可读性分解如下
            BTNode<elemType> *lc = tmp->_lchild;
            BTNode<elemType> *newlc = _root->_lchild;
            if (!newlc)
                //如果没有任何子树，那就直接接上
                _root->_lchild = lc;
            
            //lchild_leaf()会遍历整个左子树寻找某个可接上去的null左子节点
            //lchild_leaf()是一个static memeber function
            else BTNode<elemType>::lchild_leaf(lc, newlc);
            
        }
    }
    else _root = _root->_lchild;
    delete tmp; //ok, 现在我们已经移去了那个根节点
}

template<typename elemType>
void BinaryTree<elemType>::
clear(BTNode<elemType> *pt){
    if (pt) {
        clear(pt->_lchild);
        clear(pt->_rchild);
        delete pt;
    }
}
