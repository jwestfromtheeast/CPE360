// bst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

//the definition of a TreeNode
//it has two pointers, one to the left and one to the right
class TreeNode
{
public:
	int value;
	TreeNode *left;
	TreeNode *right;

	//constructor: uniform new chunks
	TreeNode()
	{
		value = 0;
		left = right = NULL;
	}
};

//binary serach tree of TreeNodes
class BST
{
public:
	TreeNode * root;

	BST()
	{
		root = NULL;
	}

	void searchBST(int key)
	{
		if (root == NULL)
		{
			cout << "Nothing to see here. Empty tree" << endl;
			return;
		}
		TreeNode *temp = root; //don't mess with the original root pointer
							   //end game: won't find, and fall off tree. prepare for this
		while (temp != NULL)
		{
			if (temp->value == key)
			{
				cout << "Found the value" << endl;
				return;
			}
			else if (temp->value < key)
			{
				temp = temp->right;
			}
			else //temp->value > key
			{
				temp = temp->left;
			}
		}

	}

	void addNodeBST(int val)
	{
		//every new value is a leaf node
		//step1: Begin a search for that value
		//step2: if you find it, dont add it
		//step3: if you dont find it, ie fall off the tree, thats where you add

		//get our root pointers
		TreeNode *chase, *follow;
		chase = follow = root;

		//get a new pointer to prepare for addition
		TreeNode *temp = new TreeNode;
		temp->value = val;

		if (root == NULL)
		{
			root = temp;
		}
		else
		{
			while (chase != NULL) //follow shadows chase
			{
				if (chase->value == val)
				{
					//duplicate, dont add
					cout << "Duplicate, not adding this" << endl;
					return;
				}
				else if (chase->value < val) //if the stored value is less than our new value, go right
				{
					follow = chase;
					chase = chase->right;
				}
				else
				{
					follow = chase;
					chase = chase->left;
				}
			}
			if (chase == NULL)
			{
				if (follow->value > val)
					follow->left = temp;
				else
					follow->right = temp;
			}
		}
	}

	void deleteNodeBST(int val, TreeNode *start) //tell it where to start, or your effective root
	{
		//Step 1: Find the value
		//Use two pointers (chase and follow)
		//chase points to the node you want to delete, follow to the parent
		TreeNode *chase, *follow;
		chase = follow = start;

		if (root == NULL)
		{
			cout << "Empty tree" << endl;
		}
		else
		{
			while (chase->value != val || chase != NULL)
			{
				if (chase->value < val)
				{
					follow = chase;
					chase = chase->right;
				}
				else
				{
					follow = chase;
					chase = chase->left;
				}
			}
			//you'll now figure out if the value exists in this tree
			if (chase == NULL)
			{
				//you fell off the tree, or this value does not exist in the tree
				cout << "Value not found, cannot delete" << endl;
				return;
			}
		}
		//if you get past that statement, the value was found

		//Step 2: FIgure out if it's case I/II/III
		//Remember: case I: leaf (no children)
		//case II: one child
		//case III: two children
		//Step 3: Dispatch code for case I,II,or III

		//Case I: how do you know? (both left and right pointers are NULL)
		if (chase->left == NULL && chase->right == NULL)
		{
			if (follow->value < chase->value)
			{
				//chase is to the right
				follow->right = NULL;
				cout << "Found. About to delete: " << chase->value << endl;
				delete chase;
			}
			else
			{
				follow->left = NULL;
				cout << "Found. About to delete: " << chase->value << endl;
				delete chase;
			}
		}
		//Case II: how do you know?
		//exactly one child is null and one is not
		else if ((chase->left != NULL && chase->right == NULL) || (chase->left == NULL && chase->right != NULL))
		{
			//where is chase w.r.t. follow?
			//where is the lone child w.r.t chase?
			//set follow->(left/right) to chase->(left/right)
			if (follow->value > chase->value)
			{
				//chase is to the left
				if (chase->left == NULL)
				{
					//chase is to the left of follow. child is to the right of chase.
					follow->left = chase->right;
					delete chase;
				}
				else if(chase->right == NULL)
				{
					//child to the left of chase
					follow->left = chase->left;
					delete chase;
				}
			}
			else if (follow->value < chase->value)
			{
				if (chase->left == NULL)
				{
					follow->right = chase->left;
					delete chase;
				}
				else if (chase->right == NULL)
				{
					follow->right = chase->right;
					delete chase;
				}
			}
		}
		//Case III: how do you know?
		//both children are not null
		//goal is to reduce case III to case I
		//Find a replacement value: the minimum value of the right subtree
		else 
		{
			int replacement = minValRST(chase->right); //find minimum value of subtree to the right of chase

			chase->value = replacement;
			//at this point, this tree is NOT A VALID BST but will be fixed (has a duplicate value)

			deleteNodeBST(replacement, chase->right);
		}
	}

	//get min value
	int minValRST(TreeNode *start)
	{
		TreeNode *temp = start;
		while (temp->left != NULL)
			temp = temp->left;

		return temp->value;
	}

	//Prefix is w.r.t. to root
	//1: In-Order Traversal: left, root, right
	void inorder(TreeNode *start)
	{
		if (start == NULL)
			return;
		else
		{
			//visit left
			inorder(start->left);
			//visit root
			cout << start->value << endl;
			//visit right
			inorder(start->right);
		}
	}
	//2: Pre-Order Traversal: root, left, right
	void preorder(TreeNode *start)
	{
		if (start == NULL)
			return;
		else
		{
			//visit root
			cout << start->value << endl;
			//visit left
			inorder(start->left);
			//visit right
			inorder(start->right);
		}
	}
	//3: Post-Order Traversal: left, right, root
	void postorder(TreeNode *start)
	{
		if (start == NULL)
			return;

		else
		{
			//visit left
			inorder(start->left);
			//visit right
			inorder(start->right);
			//visit root
			cout << start->value << endl;
		}
	}

};

int main()
{
	BST myTree;
	int choice, value;

	while (1)
	{
		cout << "1 to add" << endl;
		cout << "2 to search" << endl;

		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Add what?" << endl;
			cin >> value;
			myTree.addNodeBST(value);
			break;

		case 2: cout << "Search for what?" << endl;
			cin >> value;
			myTree.searchBST(value);
			break;
		}

		//how to call delete
		//myTree.deleteNodeBST(value, myTree.root);
	}




	return 1;
}

