#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void selectionSort(vector<int> arr)
{
	int n = arr.size();
	for (int i = 0; i < n - 1; i++)
	{
		int least = i;
		for (int j=i+1; j<n; j++)
		{
			if (arr[least] > arr[j])
			{
				least = j;
			}
		}
		swap(arr[least], arr[i]);
	}
}

int main()
{
	vector<int> arr = { 64,34,25,12,22,11,90 };
	selectionSort(arr);
	int n = arr.size();	
	
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}
