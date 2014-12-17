#include "AVL.h"
#include "helper.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>  
//TODO re-add left aligned display tree
//TODO add quick input

using namespace std;

typedef int DataType; 

void main()
{
	AVL<DataType> AVL1;
	helper<DataType> helper1;
	string command;
	srand (time(NULL));
	
	cout << "For help with the program commands enter 'HELP' at any time \nfor a list of commands and what they do." << endl;
	while (command != "Quit")/////////////////////////
	{
		cout << "Enter a command: ";
		cin.sync();
		cin.clear();
		cin >> command;

		if (command == "Help" || command == "HELP" || command == "H" || command == "help")
		{
			cout << "The Insert command will insert a node with given data." << endl;
			cout << "The Delete command will remove a node with given data." << endl;
			cout << "The PreBuild command will insert the numbers 1-10 into the tree in order." << endl;
			cout << "The PreBuildRandom command will insert a given number of node with random data into the tree." << endl;
			cout << "The MakeEmpty command will remove all nodes from the tree." << endl;
			cout << "The GetHeight command will give the height of the tree." << endl;
			cout << "The InOrder command will print out the tree nodes in order." << endl;
			cout << "The PreOrder command will print out the tree nodes in pre-order." << endl;
			cout << "The PostOrder command will print out the tree nodes in post-order." << endl;
			cout << "The GetRoot command will print out the data in the root node." << endl;
			cout << "The GetSize command will give the number of nodes in the tree." << endl;
			cout << "The Search command will tell if a node exists in the tree with the given data." << endl;
			cout << "The DisplayTree command will display the tree center aligned by level." << endl;
			cout << "The CommandList command will give a short list of all commands without help." << endl;
			cout << "Most commands can also be called by only entering the capital letters." << endl;
			
		}
		else if (command == "Insert" || command == "I")////////////////////////////////
		{
			DataType addNum;
			cout << "Enter the data to be inserted: ";
			//cin >> addNum;
			addNum = helper1.inputTest();
			AVL1.insertNode(addNum);

			cout << addNum << " has been entered into the tree." << endl;
		}
		else if (command == "Delete" || command == "D")//one instance ////////////////////////
		{
			DataType delNum;
			cout << "Enter the data to be deleted: ";
			cin >> delNum;
			AVL1.deleteSingle(delNum);
			cout << "One " << delNum << " has been deleted." << endl;
		}
		else if (command == "PreBuild" || command == "Pre")///////////////////////////
		{
			for(int i = 1; i <= 10; i++)
			{
				AVL1.insertNode(i);
			}
		}
		else if (command == "PreBuildRandom" || command == "PreR")///////////////////////////
		{
			cout << "How many items should be inserted: ";
			int i;
			i = helper1.inputTest();
			for(i; i >= 0; i--)
			{
				AVL1.insertNode( rand() % 100 + 1);
			}
		}
		else if (command == "MakeEmpty" || command == "ME")//////////////////////////////
		{
			AVL1.makeEmpty();
		}
		else if (command == "GetHeight" || command == "GT")
		{
			cout << "Tree Height is: " << AVL1.rootHeight() << endl;
		}
		else if (command == "Print" || command == "P" || command == "InOrder" || command == "InO")///////////////////////////////
		{
			AVL1.InOrder(cout);
			cout << endl;
		}
		else if(command == "PreOrder" || command == "PreO")////
		{
			AVL1.PreOrder(cout);
			cout << endl;
		}
		else if(command == "PostOrder" || command == "PostO")////
		{
			AVL1.PostOrder(cout);
			cout << endl;
		}
		else if (command == "GetRoot" || command == "GR")/////////////////////////////////////
		{
			if(!AVL1.isEmpty())
			{
				cout << AVL1.getRoot() << endl;
			}
			else
			{
				cout << "There is no root." << endl;
			}

		}
		else if (command == "GetSize" || command ==  "GS")/////////////////////////////
		{
			cout << "There are " << AVL1.getSize() << " nodes in this tree." << endl;
		}
		else if (command == "Search" || command == "S")//////////////////////////////
		{
			DataType searchNum;
			cout << "Enter the data to look for: ";
			cin >> searchNum;
			bool temp = AVL1.inTree(searchNum);
			if (temp)
			{
				cout << searchNum << " does exist in the tree." << endl;
			}
			else
			{
				cout << searchNum << " does not exist in the tree." << endl;
			}
		}
		else if (command == "DisplayTree" || command == "D" || command == "d")
		{
			AVL1.breadthFirstPrint();
		}
		else if(command == "CommandList" || command == "CL")
		{
			cout << "Help, Insert, Delete, PreBuild, PreBuildRandom, DisplayTree, CommandList" << endl;
			cout << "MakeEmpty, GetHeight, InOrder, PreOrder, PostOrder, GetRoot, GetSize, Search," << endl;
		}
		else//command is anything else
		{
			cout << command << " is not a valid command." << endl;
		}

	}//end command while

}//end main