#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void bubbleSort(vector<int> &arr)
{
	int n = arr.size();
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main()
{
	vector<int> arr = { 64,34,25,12,22,11,90 };
	bubbleSort(arr);

	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;

}
