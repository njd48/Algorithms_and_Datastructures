

#ifndef BINTREE_H
#define BINTREE_H

#define LARGE_INT  2147483647
#define SMALL_INT -2147483648

#include <iostream>

//-------------------------------------------------------------------------------------
// Struct Defn
//-------------------------------------------------------------------------------------
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;

    TreeNode() : val( 0 ), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), parent(nullptr) {}
};

//-------------------------------------------------------------------------------------
// Basic Bin Tree Methods 
//-------------------------------------------------------------------------------------
void treeInsert( TreeNode*& root , int x ) {

    
    if (root==nullptr) { // Tree was empty 
        //std::cout <<"insr1\n";
        root = new TreeNode;
        root->val = x;
        return;
    }

    //std::cout <<"insr2\n";

    TreeNode* p = root;
    TreeNode* q = nullptr;

    while ( p != nullptr ) {
        q = p;
        if ( x == p->val ){
            std::cout << "error: node val, " << x << ", is already in the tree.\n";
            return;
        } else if ( x < p->val ) {
            p = p->left;
        } else {
            p = p->right;
        }
    }

    p = new TreeNode;    
    p->val = x;
    p->parent = q;

    if ( x < q->val ) { 
        q->left = p; 
    } else {
        q->right = p;
    }
    

    //TreeNode(x);
}
TreeNode* treeSearch( TreeNode* root, int x) {

    if (root == nullptr) { 
        return nullptr; 
    }

    if ( x == root->val ) {
        return root;
    } else if ( x < root->val ){
        return treeSearch( root->left, x);
    } else {
        return treeSearch( root->right, x);
    }
}
TreeNode* treeMin( TreeNode* root ){

    //if ( root == nullptr ){
    //    int m = LARGE_INT;
    //    return m;
    //}

    TreeNode* q = nullptr; 
    TreeNode* p = root;

    while( p != nullptr ){
        q = p;
        p = p->left;
    }
    return q;
    
}
TreeNode* treeMax( TreeNode* root ){

    //if ( root == nullptr ){
    //    int m = SMALL_INT;
    //    return m;
    //}

    TreeNode* q = nullptr; 
    TreeNode* p = root;

    while( p != nullptr ){
        q = p;
        p = p->right;
    }
    return q;
    
}

TreeNode* successor( TreeNode* root, int x ) {

    TreeNode* p;
    TreeNode* b = treeSearch( root, x );

    if ( b == nullptr ){ 
        return nullptr; 
    }

    if ( b->right != nullptr ) {
        p = treeMin( b->right );
        return p;
    } 

    p = b->parent;

    while( p != nullptr && b == p->right ) {
        b = p;
        p = p->parent;
    }
    return p;
}
TreeNode* predecessor( TreeNode* root, int x ) {

    TreeNode* p;
    TreeNode* b = treeSearch( root, x );

    if ( b == nullptr ){ 
        return nullptr; 
    }

    if ( b->left != nullptr ) {
        p = treeMax( b->left );
        return p;
    } 

    p = b->parent;

    while( p != nullptr && b == p->left ) {
        b = p;
        p = p->parent;
    }
    return p;
}

// Unsafe
void transplant( TreeNode*& root, TreeNode*& targetNode, TreeNode*& subTreeRoot ) {

    if ( targetNode->parent == nullptr) {
        root = subTreeRoot;

    } else if ( targetNode == (targetNode->parent)->left ) {
        (targetNode->parent)->left  = subTreeRoot;

    } else {
        (targetNode->parent)->right  = subTreeRoot;

    }

    if ( subTreeRoot != nullptr) {
        subTreeRoot->parent = targetNode->parent;

    }
}

void remove( TreeNode*& root , int x ) {

    TreeNode* xp = treeSearch( root, x );
    //TreeNode* p  = nullptr;

    if ( xp == nullptr ) {return;}

    // if ( xp->parent == nullptr ) {} // xp must be the root

    if (xp->left == nullptr) {
        transplant( root, xp, xp->right );
        delete xp;
    } else if ( xp->right == nullptr ) {
        transplant( root, xp, xp->left );
        delete xp;
    } else {
        TreeNode* succx = treeMin( xp->right );

        if ( succx->parent != xp ) {
            transplant( root, succx, succx->right );

            succx->right           = xp->right;
            (succx->right)->parent = succx;
        } 
        transplant( root, xp, succx);
        succx->left = xp->left;
        (succx->left)->parent = succx;
        
        delete xp;
    }
}

//-------------------------------------------------------------------------------------
// Basic Displays 
//-------------------------------------------------------------------------------------
void displaySubTree( TreeNode* root ) {

    //TreeNode*p=root;

    if( root!=nullptr ) {
        displaySubTree( root->left );
        std::cout << root->val << ", ";
        displaySubTree( root->right );
    }
}
void displayTree( TreeNode* root ) {

    //TreeNode*p=root;

    std::cout << "[ ";
    if( root!=nullptr ) {
        displaySubTree( root->left );
        std::cout << root->val << ", ";
        displaySubTree( root->right );
    }
    std::cout << "]\n";
}


//-------------------------------------------------------------------------------------
// Composite methods 
//-------------------------------------------------------------------------------------
TreeNode* randTree( int N_nodes ) {

    //std::cout << "inr\n";
    TreeNode* root = nullptr;

    //std::cout << "inr2\n";
    int x;
    int rndNumCut = 100;

    //std::cout << "inr3\n";
    for ( int i = 0; i < N_nodes ; i++ ) 
    {
        //std::cout << i ;
        x = rand()%rndNumCut;
        treeInsert( root, x );
    }

    return root;
}

#endif