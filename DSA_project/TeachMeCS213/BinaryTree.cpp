#include "BinaryTree.h"
#include<iostream>
#include<stdio.h>

using namespace std;

BinaryTree::BinaryTree()
{
    troot=NULL;         //constructor : creates an empty BST
}


void BinaryTree::Insert(int e)
{
	Insert(troot,e);
}

TreeNode* BinaryTree::root()
{
    return(troot);
}

void BinaryTree::Insert(TreeNode *v, int e)
{
    if(troot==NULL)
	{
        troot = new TreeNode;
        troot->nodeval=e;
        troot->parent=NULL;
        troot->left=NULL;
        troot->right=NULL;
        troot->x=475;       //set coordinates as the first node in dialog space
        troot->y=50;
        troot->h=0;
        troot->color='#';
        cout<<troot->h<<"*";
        return;
	}
    if(e<=v->nodeval)
    {
        if(v->left==NULL)
        {
            v->left= new TreeNode;

            v->left->nodeval=e;
            v->left->parent=v;
            v->left->left=NULL;
            v->left->right=NULL;
            v->left->color='#';
            v->left->h=v->h+1;
            v->left->x=v->x-200+50*(v->left->h-1); //while inserting update the coordinates as per parent's coordinates
            v->left->y=v->y+100;
            cout<<v->left->h<<"*";
            return;

        }
        else
            Insert(v->left,e);
    }
    if(e > v->nodeval)
    {
        if(v->right==NULL)
        {

            v->right= new TreeNode;
            v->right->nodeval=e;
            v->right->parent=v;
            v->right->left=NULL;
            v->right->right=NULL;
            v->right->color='#';
            v->right->h=v->h+1;
            v->right->x=v->x+200-50*(v->right->h-1);
            v->right->y=v->y+100;
            cout<<v->right->h<<"*";
            return;

        }
        else
            Insert(v->right,e);
    }
			
}

void BinaryTree::Search(TreeNode *v,int e)
{
    if(v==NULL)
    {
        return ;
    }
    if(v->nodeval==e)
    {
        v->color='g';
        return ;
    }
    else if(e<v->nodeval)
    {
        v->color='r';
        Search(v->left,e);
    }
    else
    {
        v->color='r';
        Search(v->right,e);
    }
}

void BinaryTree::Search(int e)
{
    Search(troot,e);
}

void BinaryTree::Delete(int e)
{
    Delete(troot,e);
}

void BinaryTree::Delete(TreeNode *v, int e)
{

    if(v==NULL)
        return;
    else if(v->nodeval==e)
    {
        if(v->left==NULL && v->right==NULL)
                {
                    if(v->parent==NULL)
                    {
                        troot=NULL;
                        return;
                    }
                    else if(v->parent->left==v)
                    {
                        v->parent->left=NULL;
                        return;
                    }

                    else if(v->parent->right==v)
                    {
                        v->parent->right=NULL;
                        return;
                    }
                }
                if(v->left!=NULL && v->right==NULL)
                {
                    if(v->parent==NULL)
                    {
                        v->left->x=troot->x;
                        v->left->y=troot->y;
                        v->left->h=troot->h;
                        troot=v->left;
                        return;
                    }
                    else if(v->parent->right==v)
                    {
                        v->left->x=v->x;
                        v->left->y=v->y;
                        v->left->h=v->h;
                        v->parent->right=v->left;
                        v->left->parent=v->parent;
                        setxy(v->left);
                        delete v;
                        return;
                    }
                    else if(v->parent->left==v)
                    {
                        v->left->x=v->x;
                        v->left->y=v->y;
                        v->left->h=v->h;
                        v->parent->left=v->left;
                        v->left->parent=v->parent;
                        setxy(v->left);
                        delete v;
                        return;
                    }
                }
                if(v->left==NULL && v->right!=NULL)
                {

                    if(v->parent==NULL)
                    {
                        v->right->x=troot->x;
                        v->right->y=troot->y;
                        v->right->h=troot->h;
                        troot=v->right;
                        return;
                    }
                    else if(v->parent->right==v)
                    {
                        v->right->x=v->x;
                        v->right->y=v->y;
                        v->right->h=v->h;
                        v->parent->right=v->right;
                        v->right->parent=v->parent;
                        setxy(v->right);
                        delete v;
                        return;
                    }
                    else if(v->parent->left==v)
                    {
                        v->right->x=v->x;
                        v->right->y=v->y;
                        v->right->h=v->h;
                        v->parent->left=v->right;
                        v->right->parent=v->parent;
                        setxy(v->right);
                        delete v;
                        return;
                    }
                }
                if(v->left!=NULL && v->right!=NULL)
                {
                    TreeNode *tmp;
                    tmp = rightmost(v->left);
                    tmp->right = v->right;
                    tmp->right->parent = tmp;
                    if(tmp==v->left)
                    {
                        tmp->parent=v->parent;
                        tmp->x=v->x;
                        tmp->y=v->y;
                        tmp->h=v->h;
                        setxy(tmp);
                        //return;
                    }
                    //tmp->left = v->left;
                    //tmp->left->parent = tmp;
                    //tmp->parent=v->parent;
                    if(v->parent==NULL)
                    {
                        tmp->x=troot->x;
                        tmp->y=troot->y;
                        tmp->h=troot->h;
                        troot=tmp;
                        setxy(troot);
                        //return;
                        //troot=tmp;
                    }
                    else if(v==v->parent->right)
                    {
                        v->left->x=v->x;
                        v->left->y=v->y;
                        v->left->h=v->h;
                        v->parent->right=v->left;
                        v->left->parent=v->parent;
                        setxy(v->left);
                        delete v;
                        return;
                    }
                    else if(v==v->parent->left)
                    {
                        v->left->x=v->x;
                        v->left->y=v->y;
                        v->left->h=v->h;
                        v->parent->left=v->left;
                        v->left->parent=v->parent;
                        setxy(v->left);
                        delete v;
                        return;
                    }
                    //print_inorder();
                    Delete(tmp->left, tmp->nodeval);
                }
    }
    else if(e<=v->nodeval)
    {
        Delete(v->left, e);
        return;
    }

    else if(e>v->nodeval)
    {
        Delete(v->right, e);
        return;
    }
}

TreeNode* BinaryTree::rightmost(TreeNode *v)
{
    if(v->right==NULL)
            return v;
        else
            return (rightmost(v->right));
}

void BinaryTree::refresh(TreeNode *v)
{
    if(v==NULL)
        return;
    else
    {
        v->color='#';
        refresh(v->left);
        refresh(v->right);  //recursive calls to refresh all the nodes i.e decolorise all nodes
    }
}

void BinaryTree::refresh()
{
    refresh(troot);
}

void BinaryTree::setxy(TreeNode *v)
{
    if(v==NULL)
        return;
    else
    {
        if(v==troot)
        {
            v->x=475;
            v->y=50;
            v->h=0;
            setxy(v->left);
            setxy(v->right);    //recursive calls to reset all the nodes x-y coordinates as per its parent
        }
        if(v==v->parent->left)
        {
            v->h=v->parent->h+1;
            v->x=v->parent->x-200+50*(v->h-1);
            v->y=v->parent->y+100;
            setxy(v->left);
            setxy(v->right);    //recursive calls to reset all the nodes x-y coordinates as per its parent
        }
        if(v==v->parent->right)
        {
            v->h=v->parent->h+1;
            v->x=v->parent->x+200-50*(v->h-1);
            v->y=v->parent->y+100;
            setxy(v->left);
            setxy(v->right);    //recursive calls to reset all the nodes x-y coordinates as per its parent
        }
    }
}
