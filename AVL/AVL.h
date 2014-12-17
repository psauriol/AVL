#include <cstdio>
#include "Queue.h"
#include <math.h>
#include <iostream>
using namespace std;

template<class ItemType>
struct TreeNode
{
	ItemType data;
	TreeNode* left;
	TreeNode* right;
};

template<class ItemType>
class AVL
{
public:

	AVL();
	//Pre-Condition:
	//Function: Class constructor
	//Post-Condition: Root is set to NULL

	~AVL();
	//Pre-Condition:
	//Function: Deconstructor (calls destroySubTree on the root node)
	//Post-Condition: All content is deleted

	AVL(const AVL &oTree);
	//Pre-Condition: There is something to copy
	//Function: Copy Constructor
	//Post-Condition: Tree is copied

	void operator = (const AVL &oTree);
	//Pre-Condition: Tree is initialized and there is something to copy
	//Function: Assignment operator
	//Post-Condition: Tree now is identical to assigned tree

	bool isEmpty() const;
	//Pre-Condition: 
	//Function: Checks if root == NULL
	//Post-Condition: Returns true if tree is empty

	bool isFull() const;
	//Pre-Condition:
	//Function: Attempts to add a node to the tree and check to see if it worked
	//Post-Condition: returns true if the tree is full

	bool inTree(ItemType data);
	//Pre-Condition:
	//Function: Calls inTreeHelper function (That function checks to see if sinput data exists in the tree)
	//Post-Condition: Returns true if the entered data is in the tree

	int getSize() const;
	//Pre-Condition:
	//Function: Calls the countNodes function (That function counts all the nodes in the tree)
	//Post-Condition: Returns the total number of nodes in the tree

	void makeEmpty();
	//Pre-Condition:
	//Function: Calls destroySubTree on the root node and sets root to NULL
	//Post-Condition: root == NULL all other nodes are deleted

	void insertNode(ItemType data);
	//Pre-Condition:
	//Function: Calls insertNodeHelper (That function finds the appropriate location and inserts the new data)
	//Post-Condition: data is added to the tree and tree is rebalanced to reflect new node

	void deleteSingle(ItemType data);
	//Pre-Condition: 
	//Function: Calls deleteHelper (Finds the data and deletes one instance of it)
	//Post-Condition: One instance of the data is removed from the tree and the tree is rebalanced to reflect this

	void InOrder(ostream& outStream);
	//Pre-Condition: 
	//Function: Prints out node content InOreder
	//Post-Condition: node content is displayed in order

	void PreOrder(ostream& outStream);
	//Pre-Condition: 
	//Function: Prints out node content PreOreder
	//Post-Condition: node content is displayed in PreOrder

	void PostOrder(ostream& outStream);
	//Pre-Condition: 
	//Function: Prints out node content PostOreder
	//Post-Condition: node content is displayed in PostOrder

	int rootHeight();
	//Pre-Condition: 
	//Function: Finds total Height of tree
	//Post-Condition: returns total Height of tree

	ItemType getRoot() const;
	//Pre-Condition: There must be a root to get data from
	//Function: Gets the data from the root node
	//Post-Condition: Returns the data from the root node

	void breadthFirstPrint();
	//Pre-Condition: For int/double/float: will not diplay correctly if INT_MIN is entered
	//Pre-Condition: For string: will not display correctly if a blank string is entered
	//Pre-Condition: Will not diplay overly large trees correctly ( must be less than 7 Height to look nice)
	//Function: Queues the nodes by breadth then displays them
	//Post-Condition: Displays Tree in a nice format

private:
	TreeNode<ItemType>* root;

	int getHeight(TreeNode<ItemType>* &tPtr);
	//Pre-Condition: 
	//Function: finds the Height of a node
	//Post-Condition: returns the Height of the node

	void balance(TreeNode<ItemType>* &tPtr);
	//Pre-Condition: 
	//Function: Checks Height of child subtrees and balances if needed
	//Post-Condition: node is balanced

	void rotateLeft(TreeNode<ItemType>* &tPtr);
	//Pre-Condition: 
	//Function: rotates node left
	//Post-Condition: node has been rotated

	void rotateRight(TreeNode<ItemType>* &tPtr);
	//Pre-Condition: 
	//Function: rotates node right
	//Post-Condition: node has been rotated

	void copyTree(TreeNode<ItemType>* &tPtr, const TreeNode<ItemType>* oTree);
	//Pre-Condition: 
	//Function: recursive copies a single node then calls itself on all children
	//Post-Condition: node is copied childen are call 

	int countNodes(TreeNode<ItemType>* tPtr) const;
	//Pre-Condition: 
	//Function: recursive calls all children and adds them together 
	//Post-Condition: returns count of nodes below it plus itself

	bool inTreeHelper(ItemType data, TreeNode<ItemType>* &tPtr);
	//Pre-Condition: 
	//Function: recursive finds if data is in node if not calls itself with the appropriate child node
	//Post-Condition: returns true if it or its children contain the data

	void insertHelper(ItemType data, TreeNode<ItemType>* &tPtr);
	//Pre-Condition: 
	//Function: recurive finds the spot to place a node and puts it in
	//Post-Condition: node is inserted

	void destroySubTree(TreeNode<ItemType>* &tPtr);
	//Pre-Condition: 
	//Function: destroys node and all its desendants
	//Post-Condition: the node and everything below it no longer exist

	void deleteSearch(ItemType data, TreeNode<ItemType>* &tPtr);
	//Pre-Condition: 
	//Function: checks if node contains data and deletes it or calls the appropriate child to search for node
	//Post-Condition: node is deleted

	void deleteHelper(TreeNode<ItemType>* &tPtr);
	//Pre-Condition: 
	//Function: deletes the node while moving desendants
	//Post-Condition: node is deleted desendants are in the right places

	void FindSuccessor(TreeNode<ItemType>* tPtr, ItemType& data);
	//Pre-Condition: 
	//Function: finds the nodes successor in delete
	//Post-Condition: succesor data is moved to deleted node

	void PreOrderHelper(ostream& outStream, TreeNode<ItemType>* tPtr);
	//Pre-Condition: 
	//Function: recursive function calls root left right
	//Post-Condition: recursive function calls root left right

	void InOrderHelper(ostream& outStream, TreeNode<ItemType>* tPtr);
	//Pre-Condition: 
	//Function: recursive function calls left root right
	//Post-Condition: recursive function calls left root right

	void PostOrderHelper(ostream& outStream, TreeNode<ItemType>* tPtr);
	//Pre-Condition: 
	//Function: recursive function calls right left root
	//Post-Condition: recursive function calls right left root

	ostream& print(ostream& outStream, ItemType data);
	//Pre-Condition: 
	//Function: Prints out the data in the node
	//Post-Condition: node data is output


};

template<class ItemType>
int AVL<ItemType>::getHeight(TreeNode<ItemType>* &tPtr)
{
	if(tPtr != NULL)
	{
		int LHeight = getHeight(tPtr->left);//height of left child
		int RHeight = getHeight(tPtr->right);//height of right child

		if(LHeight > RHeight)
		{
			return(1 + LHeight);
		}
		else //(Lheight <= RHeight)
		{
			return(1 + RHeight);
		}
	}
	else
	{
		return(0);
	}
}

template<class ItemType>
void AVL<ItemType>::rotateLeft(TreeNode<ItemType>* &tPtr)
{
	TreeNode<ItemType>* temp = tPtr->right; 
	tPtr->right = temp->left;
	temp->left = tPtr;
	tPtr = temp;
}

template<class ItemType>
void AVL<ItemType>::rotateRight(TreeNode<ItemType>* &tPtr)
{
	TreeNode<ItemType>* temp = tPtr->left;
	tPtr->left = temp->right;
	temp->right = tPtr;
	tPtr = temp;
}

template<class ItemType>
void AVL<ItemType>::balance(TreeNode<ItemType>* &tPtr)
{
	int tBalance = (getHeight(tPtr->right) - getHeight(tPtr->left));

	if(tBalance > 1)//tree is off balance to the right
	{
		if(getHeight(tPtr->right->left) > getHeight(tPtr->right->right))//right-left heavy
		{
			rotateRight(tPtr->right);//change to right/right heavy
			rotateLeft(tPtr);//balance node
		}
		else//right-right heavy
		{
			rotateLeft(tPtr);//balance node
		}
	}
	else if(tBalance < -1)//tree is off balance to the left
	{
		if(getHeight(tPtr->left->right) > getHeight(tPtr->left->left))//left-right heavy
		{
			rotateLeft(tPtr->left);//change to left/left heavy
			rotateRight(tPtr);//balance node
		}
		else
		{
			rotateRight(tPtr);//balance node
		}
	}
	else//tree is balanced
	{
		//do nothing
	}
}

template<class ItemType>
AVL<ItemType>::AVL()
{
	root = NULL;
}

template<class ItemType>
AVL<ItemType>::~AVL()
{
	if(!isEmpty())
	{
		destroySubTree(root);
	}
}

template<class ItemType>
AVL<ItemType>::AVL(const AVL &oTree)
{
	copyTree(root, oTree.root);
}

template<class ItemType>
void AVL<ItemType>::operator = (const AVL &oTree)
{
	if(oTree != this)
	{
		destroySubTree(root);
		copyTree(root, oTree.root);
	}
}

template<class ItemType>
void AVL<ItemType>::copyTree(TreeNode<ItemType>* &tPtr, const TreeNode<ItemType>* oTree)
{
	if(oTree == NULL)
	{
		tPtr == NULL;
	}
	else
	{
		copy = new TreeNode<ItemType>;
		copy->data = oTree->data;
		copyTree(tPtr->left, oTree->left);
		copyTree(tPtr->right, oTree->right);
	}
}

template<class ItemType>
bool AVL<ItemType>::isEmpty() const
{
	return(root == NULL);
}

template<class ItemType>
bool AVL<ItemType>::isFull() const
{
	TreeNode<ItemType>* temp = new TreeNode<ItemType>;
	if( temp == NULL)
	{
		return true;
	}
	else
	{
		delete temp;
		return false;
	}
}

template<class ItemType>
ItemType AVL<ItemType>::getRoot() const
{
	if(!isEmpty())
	{
		return (root->data);
	}
}

template<class ItemType>
int AVL<ItemType>::getSize() const
{
	return(countNodes(root));
}

template<class ItemType>
int AVL<ItemType>::countNodes(TreeNode<ItemType>* tPtr) const
{
	if(tPtr != NULL)
	{
		return(1 + countNodes(tPtr -> left) + countNodes(tPtr -> right));
	}
	else
	{
		return (0);
	}
}

template<class ItemType>
void AVL<ItemType>::insertNode(ItemType data)
{
	if(isFull())
	{
		//cant insert return error msg
	}
	else if(isEmpty())
	{
		root = new TreeNode<ItemType>;
		root -> left = NULL;
		root -> right = NULL;
		root -> data = data;
	}
	else
	{
		insertHelper(data, root);
	}
}

template<class ItemType>
void AVL<ItemType>::insertHelper(ItemType data, TreeNode<ItemType>* &tPtr)
{
	if(tPtr == NULL)
	{
		tPtr = new TreeNode<ItemType>;
		tPtr -> left = NULL;
		tPtr -> right = NULL;
		tPtr -> data = data;
	}
	else if(tPtr -> data > data)//the data is smaller than the nodes info
	{
		insertHelper(data, tPtr -> left);
	}
	else// (tPtr -> data <= data)//the data is larger than the nodes info //or equal
	{
		insertHelper(data, tPtr -> right);
	}
	balance(tPtr);
}

template<class ItemType>
bool AVL<ItemType>::inTree(ItemType data)
{
	if(!isEmpty())
	{
		return(inTreeHelper(data, root));
	}
	else
	{
		return(false);
	}
}

template<class ItemType>
bool AVL<ItemType>::inTreeHelper(ItemType data, TreeNode<ItemType>* &tPtr)
{
	if(tPtr == NULL)
	{
		return(false);
	}
	else if(tPtr->data == data)
	{
		return(true);
	}
	else if(tPtr->data > data)
	{
		return(inTreeHelper(data, tPtr->left));
	}
	else //(ptr->data < data)
	{
		return(inTreeHelper(data, tPtr->right));
	}
}

template<class ItemType>
void AVL<ItemType>::makeEmpty()
{
	if(!isEmpty())
	{
		destroySubTree(root);
		root = NULL;
	}
}

template<class ItemType>
void AVL<ItemType>::destroySubTree(TreeNode<ItemType>* &tPtr)
{
	if(tPtr != NULL)
	{
		destroySubTree(tPtr->left);
		destroySubTree(tPtr->right);
	}
	delete tPtr;
}

template<class ItemType>
void AVL<ItemType>::InOrder(ostream& outStream)
{
	InOrderHelper(outStream, root);
}

template<class ItemType>
void AVL<ItemType>::InOrderHelper(ostream& outStream, TreeNode<ItemType>* tPtr)
{
	if(tPtr != NULL)
	{
		InOrderHelper(outStream, tPtr->left);
		print(outStream, tPtr->data);
		InOrderHelper(outStream, tPtr->right);
	}
}

template<class ItemType>
void AVL<ItemType>::PreOrder(ostream& outStream)
{
	PreOrderHelper(outStream, root);
}

template<class ItemType>
void AVL<ItemType>::PreOrderHelper(ostream& outStream, TreeNode<ItemType>* tPtr)
{
	if(tPtr != NULL)
	{
		print(outStream, tPtr->data);
		PreOrderHelper(outStream, tPtr->left);
		PreOrderHelper(outStream, tPtr->right);
	}
}

template<class ItemType>
void AVL<ItemType>::PostOrder(ostream& outStream)
{
	PostOrderHelper(outStream, root);
}

template<class ItemType>
void AVL<ItemType>::PostOrderHelper(ostream& outStream, TreeNode<ItemType>* tPtr)
{
	if(tPtr != NULL)
	{
		
		PostOrderHelper(outStream, tPtr->left);
		PostOrderHelper(outStream, tPtr->right);
		print(outStream, tPtr->data);
	}
}


template<class ItemType>
ostream& AVL<ItemType>::print(ostream& outStream, ItemType data)
{
	outStream << data << " ";
	return outStream;
}

template<class ItemType>
void AVL<ItemType>::deleteSingle(ItemType data)
{
	deleteSearch(data, root);
}

template<class ItemType>
void AVL<ItemType>::deleteSearch(ItemType data, TreeNode<ItemType>* &tPtr)
{
	if(tPtr == NULL)
	{

	}
	else if(tPtr->data > data)
	{
		deleteSearch(data, tPtr->left);
	}
	else if (tPtr->data < data)
	{
		deleteSearch(data, tPtr->right);
	}
	else if(tPtr->data == data)
	{
		deleteHelper(tPtr);
	}
	
	if(tPtr != NULL)
	{
		balance(tPtr);
	}
}

template<class ItemType>
void AVL<ItemType>::deleteHelper(TreeNode<ItemType>* &tPtr)//
{
	if(tPtr != NULL)
	{
		TreeNode<ItemType>* temp;
		if(tPtr->left == NULL && tPtr->right == NULL)//no children
		{
			delete tPtr;
			tPtr = NULL;
		}
		else if(tPtr->left == NULL && tPtr->right != NULL)//only right child
		{
			temp = tPtr;
			tPtr = tPtr->right;
			delete temp;
		}
		else if(tPtr->right == NULL && tPtr->left != NULL)//only left child
		{
			temp = tPtr;
			tPtr = tPtr->left;
			delete temp;
		}
		else//(tPtr->right != NULL && tPtr->left != NULL) //two children
		{
			ItemType data;
			FindSuccessor(tPtr->left, data);
			tPtr->data = data;
			deleteHelper(tPtr->left);
		}
	}//end if NULL
}//end deleteHelper

template<class ItemType>
void AVL<ItemType>::FindSuccessor(TreeNode<ItemType>* tPtr, ItemType& data)//
{
	while(tPtr->right != NULL)
	{
		tPtr=tPtr->right;
	}
	data = tPtr->data;
}

template<class ItemType>
int AVL<ItemType>::rootHeight()
{
	return getHeight(root);
}

template<class ItemType>
void AVL<ItemType>::breadthFirstPrint()

{
	Queue<TreeNode<ItemType>*> Que1;//make a queue

	if(root != NULL)
	{
		Que1.EnQueue(root);
	}

	TreeNode<ItemType>* dummy = new TreeNode<ItemType>;
	dummy->left = NULL;
	dummy->right = NULL;
	dummy->data = INT_MIN;//TODO change for other datatypes +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	TreeNode<ItemType>* temp;

	int count = 0;
	int row = 0;
	while(!Que1.IsEmpty() && count < (pow((double)2, (int)(getHeight(root))) - 1))//makes it print full rows but stops it from indefinite looping
	{
		if(count == pow((double)2, (int)row) - 1)//finds when a new row is needed
		{
			cout << endl;
			for( int i = ((int)pow((double)2, (int)getHeight(root) - 1) - ((int)pow((double)2, (int)row))); i > 0; i--)
			{//this loop adds spaces to make the tree display look pretty!
				cout << " ";
			}
			row++;//tracks the row we are on
		}
		count++;//tracks the number of items displayed (tree items + dummyFillers)

		Que1.DeQueue(temp);
		if(temp->data != INT_MIN)//adds either node data or a dummy filler //change for other datatypes +++++++++++++++++++++++++++++
		{
			cout << temp->data << " ";
		}
		else
		{
			cout << "X ";
		}

		if(temp->left != NULL)//queues the left node or a dummy if left is NULL
		{
			Que1.EnQueue(temp->left);
		}
		else
		{
			Que1.EnQueue(dummy);
		}

		if(temp->right != NULL)//queues the right node or a dummy if right is NULL
		{
			Que1.EnQueue(temp->right);
		}
		else
		{
			Que1.EnQueue(dummy);
		}

	}//end while Queue !isempty
	cout << endl;
}//end breadth first print