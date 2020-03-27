#ifndef AVL_H
#define AVL_H

//Struct defined for every node in an AVL tree storing the x-y coordinates, left-right child pointers, element and height
struct AVLNode {
    int nodeval;
    int x,y,h;
    AVLNode *left, *right;
};

class AVL{
public:
    AVL();              //constructor

    AVLNode* root();    //returns the root of the tree which is a private member

    void Insert(int e); //Inserts the element at the appropriate place in the AVL tree

    int max(int a,int b);   //finds the max of a and b

    int Height(AVLNode *v); //returns the height of a given node

    AVLNode* newNode(int val);  //creates a new node and returns the pointer to it

    AVLNode* leftRotate(AVLNode *x);    //left rotates the tree at a given node to facilitate AVL insert

    AVLNode* rightRotate(AVLNode *y);   //right rotaes the tree at a given node to facilitate AVL insert

    int getBalance(AVLNode *v); // Get Balance factor of node v again required to facilitate AVL rotations

    AVLNode* insert(AVLNode *v, int val);   //helper function required for Insert

    void preOrder(); //print the preorder traversal of the tree

    void preOrder(AVLNode *v);  //helper function for the preorder traversal

    void setxy(AVLNode *v); //sets the x-y coordinates of all the subtrees of a given node as per its x-y coordinates

private:

    AVLNode *troot; //pointer to the root of the tree
};

#endif // AVL_H
