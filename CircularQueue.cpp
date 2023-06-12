#include <iostream>
#define SIZE 10

using namespace std;

class CircularQueue 
{
	int front;
	int rear;
	int data[SIZE];
public:
	CircularQueue()
	{
		front = 0;
		rear = 0;
	}
	bool isEmpty()
	{
		return (front == rear);
	}
	bool isFull()
	{
		return (rear + 1)%SIZE == front%SIZE ;
	}
	void enc(int val)
	{
		if (isFull())
		{
			
		}
		else
		{
			rear = (rear + 1) % SIZE;
			data[rear] = val;
		}
	}
	int dec()
	{
		if (isEmpty())
		{

		}
		else
		{
			front = (front + 1) % SIZE;
			return data[front];
		}
	}

	void display()
	{
		int maxi = (front < rear) ? rear : rear + SIZE;
		for (int i = front + 1; i <= maxi; i++)
		{
			cout << data[i%SIZE] << endl;
		}
	}

};

int main()
{

	return 0;
}
