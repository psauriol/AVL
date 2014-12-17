#include "AVL.h"
#include "helper.h"
#include <iostream>
#include <string>

using namespace std;

typedef int DataType; 

//void main()
//{
//	AVL<DataType> AVL1;
//	helper<DataType> helper1;
//	string command;
//	
//	while (command != "Quit")
//	{
//		cout << "Enter a command: ";
//		cin >> command;
//
//		if (command == "Insert" || command == "I")
//		{
//			DataType addNum;
//			cout << "Enter the data to be inserted: ";
//			addNum = helper1.inputTest();//takes input and checks type
//			AVL1.insertNode(addNum);
//
//			cout << addNum << " has been entered into the tree." << endl;
//		}
//		else if (command == "Pre")
//		{
//			for(int i = 1; i <= 7; i++)
//			{
//				AVL1.insertNode(i);
//			}
//		}
//		else if (command == "DestroyTree" || command == "DT")
//		{
//			AVL1.makeEmpty();
//		}
//		else if (command == "Print" || command == "P")
//		{
//			string printTemp;
//			cout << "Type PreOrder, InOrder, or PostOrder: ";
//			cin >> printTemp;
//			if(printTemp == "PreOrder")
//			{
//				AVL1.PreOrder();
//				cout << endl;
//			}
//			else if(printTemp == "PostOrder")
//			{
//				AVL1.PostOrder();
//				cout << endl;
//			}
//			else //inOrder
//			{
//				AVL1.InOrder();
//				cout << endl;
//			}
//
//			//pre
//			//post
//		}
//		else if (command == "GetRoot")
//		{
//			if(!AVL1.isEmpty())
//			{
//				cout << AVL1.getRoot() << endl;
//			}
//			else
//			{
//				cout << "There is no root." << endl;
//			}
//
//		}
//		else if (command == "GetSize")
//		{
//			cout << "There are " << AVL1.getSize() << " nodes in this tree." << endl;
//		}
//		else if (command == "Search")
//		{
//			DataType searchNum;
//			cout << "Enter the data to look for: ";
//			cin >> searchNum;
//			bool temp = AVL1.inTree(searchNum);
//			if (temp)
//			{
//				cout << searchNum << " does exist in the tree." << endl;
//			}
//			else
//			{
//				cout << searchNum << " does not exist in the tree." << endl;
//			}
//		}
//		else if (command == "")
//		{
//			cout << ".";
//		}
//		else if (command == "Quit")
//		{
//
//		}
//		else if (command == "DeleteSingle" || command == "DS")//one instance
//		{
//			DataType delNum;
//			cout << "Enter the data to be deleted: ";
//			cin >> delNum;
//			AVL1.deleteSingle(delNum);
//			cout << "One " << delNum << " has been deleted." << endl;
//		}
//		else if (command == "Test" || "t")
//		{
//			AVL1.breadthFirstPrint();
//		}
//		else//command is anything else
//		{
//			cout << command << " is not a valid command." << endl;
//		}
//
//	}//end command while
//
//}//end main