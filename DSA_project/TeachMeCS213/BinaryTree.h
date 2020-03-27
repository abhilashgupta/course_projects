#ifndef BINARYTREE
#define BINARYTREE

//Struct defined for every node in an BST storing the x-y coordinates, left-right child and parent pointers, element and h=depth
struct TreeNode {
	int nodeval;
    int x,y,h;
    TreeNode *left, *right, *parent;
    char color;
};

class BinaryTree {
	public:
        BinaryTree();   //constructor

        int size();     //returns size of the entire BST

        int size(TreeNode& v);      //returns size of da given tree

        TreeNode* root();       //returns the root of the tree which is a private member

        void Insert(int e);     //Inserts element in the BST

        void Insert(TreeNode *v,int e); //helper function for Insert

        void Search(int e);     //Searches for the element and colour-codes the nodes properly

        void Delete(int e); //deletes a node

        void Search(TreeNode *v,int e);      //helper function for Search()

        void Delete(TreeNode *v, int e);    //helper function for Delete()

        TreeNode* rightmost(TreeNode *v);   //returns the rightmost node of a given tree

        void refresh(TreeNode *v);      //decolourises the tree given

        void refresh();     //decolorises the entire tree

        void setxy(TreeNode *v); //sets the x-y coordinates of all the subtrees of a given node as per its x-y coordinates

	private:
        TreeNode *troot;    //pointer to the root of the tree
};
#endif
