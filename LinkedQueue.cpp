#include <iostream>
using namespace std;

class Node
{
	Node* link;
	int data;
public:
	Node(int val = 0)
	{
		data = val;
		link = NULL;
	}

	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
	void display() { cout << "<" << data << ">"; }
};

class LinkedQueue
{
	Node* front;
	Node* rear;
public:
	LinkedQueue() : front(NULL), rear(NULL) {}

	bool isEmpty()
	{
		return (front == NULL && rear == NULL);
	}

	void enq(Node * n)
	{
		if (isEmpty())
		{
			rear = front = n;
		}
		else
		{
			rear->setLink(n);
			rear = n;
		}
	}

	Node* deq()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			Node* p = front;
			front = front->getLink();
			if (front== NULL)
				rear = NULL;
			return p;
		}
	}
	
	void display()
	{
		for (Node *p=front ; p!=NULL; p=p->getLink())
		{
			p->display();
		}
	}
};

int main()
{
	LinkedQueue que;
	que.enq(new Node(1));
	que.enq(new Node(2));
	que.enq(new Node(3));
	que.display();
	que.deq();
	que.display();
	return 0;
}
