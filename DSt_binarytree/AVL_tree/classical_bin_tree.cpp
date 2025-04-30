

#ifndef BINTREE_H
#define BINTREE_H

#define LARGE_INT  2147483647
#define SMALL_INT -2147483648

#include <iostream>


class BinTree {

protected:
    //-------------------------------------------------------------------------------------
    // Struct Defn
    //-------------------------------------------------------------------------------------
    enum Color {
        black = 0,
        red,
    };

    struct TreeNode {
        int val;
        Color color;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;

        TreeNode() : val( 0 ), left(nullptr), right(nullptr), parent(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right), parent(nullptr) {}
    };

    typedef struct TreeNode *NODEPTR;

    
    /*
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
    */

    TreeNode* subTreeSearch( TreeNode* root, int x) {
    
        if (root == nullptr) { 
            return nullptr; 
        }
    
        if ( x == root->val ) {
            return root;
        } else if ( x < root->val ){
            return subTreeSearch( root->left, x);
        } else {
            return subTreeSearch( root->right, x);
        }
    }
    TreeNode* subTreeMin( TreeNode* root ){
    
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
    TreeNode* subTreeMax( TreeNode* root ){
    
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
        TreeNode* b = subTreeSearch( root, x );
    
        if ( b == nullptr ){ 
            return nullptr; 
        }
    
        if ( b->right != nullptr ) {
            p = subTreeMin( b->right );
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
        TreeNode* b = subTreeSearch( root, x );
    
        if ( b == nullptr ){ 
            return nullptr; 
        }
    
        if ( b->left != nullptr ) {
            p = subTreeMax( b->left );
            return p;
        } 
    
        p = b->parent;
    
        while( p != nullptr && b == p->left ) {
            b = p;
            p = p->parent;
        }
        return p;
    }
    
    int subTreeHeight( TreeNode* node ) {

        int height = 0;

        if ( node == nullptr ) {
            return height;
        }
        
        height = 1;

        int hL = subTreeHeight( node->left );
        int hR = subTreeHeight( node->right );
        int h  = ( hL + hR + abs(hL-hR)  )/2;  // take max

        height = height + h;

        return height;

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
    
    void leftRotate( NODEPTR& root, NODEPTR& x ) {

        if ( x->right == nullptr ) { return; }
        
        NODEPTR p   = x->parent;
        NODEPTR y   = x->right;
        NODEPTR mid = y->left;

        // promote y into x's position
        y->left   = x;
        y->parent = p;

        // Put x subordinate to y
        // and give mid (y's original left subtree)
        // to be a right child of x.
        x->parent = y;
        x->right  = mid;

        if  ( mid != nullptr ) {
            mid->parent = x;
        }

        // Change child pointers of this subtree's parent 
        // to point to y
        if ( p == nullptr ) {
            root     = y;
        } else if ( p->left == x ){
            p->left  = y;
        } else {
            p->right = y;
        }
    }

    void rightRotate( NODEPTR& root, NODEPTR& x ) {

        if ( x->left == nullptr ) { return; }
        
        NODEPTR p   = x->parent;
        NODEPTR y   = x->left;
        NODEPTR mid = y->right;

        //---------------------------------

        // promote y into x's position
        y->right   = x;
        y->parent  = p;

        // Put x subordinate to y
        // and give mid (y's original right subtree)
        // to be a left child of x.
        x->parent = y;
        x->left  = mid;

        if  ( mid != nullptr ) {
            mid->parent = x;
        }

        // Change child ptrs of this subtree's parent 
        // to point to y
        if ( p == nullptr ) {
            root = y;
        } else if ( p->left == x ){
            p->left  = y;
        } else {
            p->right = y;
        }
    }
    
    // Diagnostic
    void displaySubTree( TreeNode* root ) {

        //TreeNode*p=root;
    
        if( root!=nullptr ) {
            displaySubTree( root->left );
            std::cout << root->val << ", ";
            displaySubTree( root->right );
        }
    }

private:
    NODEPTR root;

public:
    // --- Constr/Destr ---------------------------
    BinTree(){ root = nullptr; };
    ~BinTree(){ };

    // --- Basic Gets -----------------------------
    bool isEmpty() { if (root==nullptr) return true; else return false; }
    int height() { return subTreeHeight(root); }

    // --- Basic Methods --------------------------
    void    insert( int );
    NODEPTR search( int x ){ return subTreeSearch( root, x ); }
    void    remove( int );

    // --- Tree Vital Stats -----------------------
    int max(){ return subTreeMax(root)->val; }
    int min(){ return subTreeMin(root)->val; }

    // --- Basic Displays/diagnostic --------------
    void testRotations(  );
    void display(  );
    
    // --- Composite Methods ----------------------
};


//-------------------------------------------------------------------------------------
// Basic Methods: Insert, Search, Remove 
//-------------------------------------------------------------------------------------

void BinTree::insert( int x ) {
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
            //std::cout << "error: node val, " << x << ", is already in the tree.\n";
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

}

// NODEPTR BinTree::search( int x ) {}

void BinTree::remove( int x ) {
    
    NODEPTR xp = search( x );

    if ( xp == nullptr ) {return;}

    if (xp->left == nullptr) {
        transplant( root, xp, xp->right );
        delete xp;
    } else if ( xp->right == nullptr ) {
        transplant( root, xp, xp->left );
        delete xp;
    } else {
        NODEPTR succx = subTreeMin( xp->right );

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

void BinTree::testRotations() {

    rightRotate( root, root );
    leftRotate(  root, root );
    leftRotate(  root, root->right );
    leftRotate(  root, root->left );
    rightRotate( root, root->right );
    rightRotate( root, root->left );
    
}


void BinTree::display(  ) {

        std::cout << "[ ";
        if( root!=nullptr ) {
            displaySubTree( root->left );
            std::cout << root->val << ", ";
            displaySubTree( root->right );
        }
        std::cout << "]\n";
}

#endif