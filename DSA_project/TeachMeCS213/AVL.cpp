#include "AVL.h"
#include <iostream>
#include <stdio.h>

using namespace std;

AVL::AVL()
{
    troot=NULL;         //constructor : creates an empty AVL tree
}

AVLNode* AVL::root()
{
    return troot;
}

void AVL::Insert(int e)
{
   troot = insert(troot,e);
}

 int AVL::max(int a, int b)
 {
    return (a > b)? a : b;
 }

 int AVL::Height(AVLNode *v)
 {
     if (v == NULL)
         return 0;
     return v->h;
 }

 AVLNode* AVL::newNode(int val)
 {
     AVLNode *v;
     v = new AVLNode;
     v->nodeval=val;
     v->left = NULL;
     v->right = NULL;   //creates a new node and nulling its left and right children pointers nd returning the pointer to itself
     v->h = 1;
     return v;
 }

 AVLNode* AVL::rightRotate(AVLNode *y)
 {
     AVLNode *x = y->left;
     AVLNode *T2 = x->right;

     // Perform rotation
     x->right = y;
     y->left = T2;

     // Update heights
     y->h = max(Height(y->left), Height(y->right))+1;
     x->h = max(Height(x->left), Height(x->right))+1;

     // Return new root
     return x;
 }

 AVLNode* AVL::leftRotate(AVLNode *x)
 {
     AVLNode *y = x->right;
     AVLNode *T2 = y->left;

     y->left = x;
     x->right = T2;

     x->h = max(Height(x->left), Height(x->right))+1;
     y->h = max(Height(y->left), Height(y->right))+1;

     return y;
 }

 int AVL::getBalance(AVLNode *v)
 {
     if (v == NULL)
         return 0;
     return Height(v->left) - Height(v->right);
 }

 AVLNode* AVL::insert(AVLNode *v, int val)
 {
     /* 1.  Perform the normal BST rotation */
     if (v == NULL)
         return(newNode(val));

     if (val <= v->nodeval)
         v->left  = insert(v->left, val);
     else
         v->right =insert(v->right, val);

     /* 2. Update height of this ancestor node */
     v->h = max(Height(v->left), Height(v->right)) + 1;

     /* 3. Get the balance factor of this ancestor node to check whether
        this node became unbalanced */
     int balance = getBalance(v);

     // If this node becomes unbalanced, then there are 4 cases

     // Left Left Case
     if (balance > 1 && val< v->left->nodeval)
         return rightRotate(v);

     // Right Right Case
     if (balance < -1 && val > v->right->nodeval)
         return leftRotate(v);

     // Left Right Case
     if (balance > 1 && val > v->left->nodeval)
     {
         v->left =  leftRotate(v->left);
         return rightRotate(v);
     }

     // Right Left Case
     if (balance < -1 && val < v->right->nodeval)
     {
         v->right = rightRotate(v->right);
         return leftRotate(v);
     }

     return v;
 }

 void AVL::preOrder()
 {
     preOrder(troot);
 }

 void AVL::preOrder(AVLNode *v)
 {
     if(v != NULL)
     {
         cout<< v->nodeval<<"*";
         preOrder(v->left);
         preOrder(v->right);
     }
 }

 void AVL::setxy(AVLNode *v)
 {
     if(v==NULL)
     {
         return;
     }
     if(v==troot)
     {
         troot->x=475;
         troot->y=30;
     }
     if(v->left!=NULL)
     {
         v->left->x=v->x-200;
         v->left->y=v->y+100;

         setxy(v->left);
         setxy(v->right);   //recursive calls to reset all the nodes x-y coordinates as per its parent

     }
     if(v->right!=NULL)
     {
         v->right->x=v->x+200;
         v->right->y=v->y+100;

         setxy(v->left);
         setxy(v->right);   //recursive calls to reset all the nodes x-y coordinates as per its parent
     }
 }

