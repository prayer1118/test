#include <iostream>
using namespace std;

int binarySearch(int list[], int key, int low, int high)
{
	while (low <= high)
	{
		int middle = (low + high) / 2;
		if (list[middle] == key)
		{
			return middle;
		}
		else if (list[middle] > key)
		{
			high = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
	}
	return -1;
}

int main()
{
	int list[] = { 1,3,5,7,9,11,13,15,17,19 };
	int size = sizeof(list)/sizeof(list[0]);
	int idx= binarySearch(list,10,0,size-1);
	cout << idx << endl;
	return 0;
}
