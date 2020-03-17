// https://www.spoj.com/problems/TEST/

#include <iostream>

using namespace std;

int main()
{
	int num;

	for(;;)
	{	
		cin >> num;
		if (num == 42)
			break;
		cout << num << "\n";
	}
	
	return 0;
}
