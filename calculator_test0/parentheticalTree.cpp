#ifndef PARENTHETICALTREE_H
#define PARENTHETICALTREE_H

#include <iostream>
#include <vector>
#include "opera.cpp"

class treeNode {

private:
    treeNode* parent;
    std::vector<treeNode*> children;

    bool valid;
    Opera* val;

public:

    treeNode( Opera* p ) ;
    ~treeNode(  );

    size_t nChildren() ;
    treeNode* getParent();
    treeNode* addChild( Opera* ) ;
    Opera* pop(); 
    Opera* pop( bool& ) ; // Pop and test

    bool isValid();
    void validate();
    void invalidate();

    void displayGraph();
    void displayGraphPlus();

};



//=================================================================

treeNode::treeNode( Opera* p ) {
    parent = nullptr;
    valid  = false;
    val    = p;
}

treeNode::~treeNode(  ){ 
    while ( nChildren()>0) {
        pop();
    }
}

size_t treeNode::nChildren() {
    return children.size();
}

treeNode* treeNode::getParent() {
    return parent;
}

treeNode* treeNode::addChild( Opera* p ) {

    treeNode* child = new treeNode( p );
    this->children.push_back(child);
    child->parent = this;
    return child;
}

Opera* treeNode::pop() {
    Opera* x;
    if ( 0 == nChildren() ) {
        x = val;
        if ( parent != nullptr ) {
            parent->children.pop_back();
        }
        delete this;
    } else {
        x = children.back()->pop();
    }
    return x;
}

Opera* treeNode::pop( bool& v ) { // Pop and test
    Opera* x;
    if ( 0 == nChildren() ) {
        x = val;
        v = valid;
        if ( parent != nullptr ) {
            parent->children.pop_back();
        }
        delete this;
    } else {
        x = children.back()->pop();
    }
    return x;
}

bool treeNode::isValid() {
    return valid;
}

void treeNode::validate() {
    valid = true;
}

void treeNode::invalidate() {
    valid = false;
}


void treeNode::displayGraph() {

    std::cout << '(';

    for ( auto c : children ) {
        c->displayGraph();
    }
    if ( valid ) {
        std::cout << ')';
    }
    

}

void treeNode::displayGraphPlus() {

    std::cout << '(';

    Opera* p = this->val;
    Operation op = p->getOperation();
    if ( valid ) {        
        if ( isCParen(op) ) {
            std::cout << p->getVal() << operationToString(op) ;
        } else {
            std::cout << p->getVal() << operationToString(op) << "...";
        }
    }
    for ( auto c : children ) {
        c->displayGraphPlus();
    }
    if ( valid ) {
        if ( !isCParen(op) ) {
            std::cout << ')';
        }
    }
    

}

#endif