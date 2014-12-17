#include <iostream>
using namespace std;

template<class InputType>
class helper
{
public:
	InputType inputTest();
	//Pre-conditions: none
	//Function: checks if input will 'fit' data type and flushes the stream if it does not
	// Post-Condition: either data is returned or stream is flushed
private:
	InputType temp;
};

template<class InputType>
InputType helper<InputType>::inputTest()
{
	while(!(cin >> temp))
	{
		cout << "Bad input please re-enter: ";
		cin.sync();
		cin.clear();
	}
	return temp;
}