#include <iostream>
#include <vector>
using namespace std;


void insertSort(vector<int>& arr)
{
	int n = arr.size();
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		int key = arr[i];
		while (j >= 0 && key < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main()
{
	vector<int> arr = { 64,34,25,12,22,11,90 };
	insertSort(arr);

	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}
