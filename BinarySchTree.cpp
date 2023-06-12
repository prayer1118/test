#include <iostream>
using namespace std;

class BinaryNode
{
protected:
	BinaryNode* left;
	BinaryNode* right;
	int data;
public:
	BinaryNode(int d)
	{
		data = d;
	}
	bool isLeaf()
	{
		return ((left == NULL) && (right == NULL));
	}

	void setData(int d)	{data = d;}
	int getData(){return data;}

	void setLeft(BinaryNode* n){left = n;}
	BinaryNode* getLeft(){return left;}

	void setRight(BinaryNode* n) { right = n; }
	BinaryNode* getRight(){return right;}
};
class BinaryTree
{
public:
	BinaryNode * root;

public:
	BinaryTree()
	{
		root = NULL;
	}
	void display()
	{
		cout << "Binary Tree:" << endl;
		if (isEmpty())
		{
			cout << "Empty Tree" << endl;
		}
		else
		{
			display(root,0);
		}	
	}
	void display(BinaryNode* node,int depth)
	{
		if (node==NULL)
		{
			return;
		}

		for (int i = 0; i < depth; i++)
		{
			printf("\t");
		}

		cout << "-"<< (node->getData()) << endl;
		display(node->getLeft(),depth+1);
		display(node->getRight(),depth+1);

	}

	void preorder()
	{
		cout << "preorder: ";
		preorder(root);
		cout << endl;
	}

	void preorder(BinaryNode* node)
	{
		if (node == NULL) return;
		cout << "[" << (node->getData()) << "]";
		preorder(node->getLeft());
		preorder(node->getRight());
	}

	void inorder()
	{
		cout << "inorder: ";
		inorder(root);
		cout << endl;
	}

	void inorder(BinaryNode* node)
	{
		if (node == NULL) return;
		inorder(node->getLeft());
		cout << "[" << (node->getData()) << "]";
		inorder(node->getRight());
	}


	void postorder()
	{
		cout << "postorder: ";
		postorder(root);
		cout << endl;
	}

	void postorder(BinaryNode* node)
	{
		if (node == NULL) return;
		postorder(node->getLeft());
		postorder(node->getRight());
		cout << "[" << (node->getData()) << "]";
	}

	bool isEmpty()
	{
		return root == NULL;
	}

};

class BinarySchTree: public BinaryTree
{
public:
	void insert(BinaryNode* n)
	{
		if (root == NULL)
			root = n;
		else
			insert(root, n);

	}

	void insert(BinaryNode* r, BinaryNode* n)
	{
		if (r->getData() == n->getData())
			return;
		else if (r->getData() > n->getData())
		{
			if (r->getLeft() == NULL)
				r->setLeft(n);
			else
				insert(r->getLeft(), n);
		}
		else
		{
			if (r->getRight() == NULL)
				r->setRight(n);
			else
				insert(r->getRight(), n);
		}

	}

	BinaryNode* search(int d)
	{
		BinaryNode *node= search(root, d);

		if (node == NULL)
		{
			cout << "찾는 데이터 없음" << endl;
		}
		else
		{
			cout << "찾는 데이터 있음" << node->getData() << endl;
		}

		return node;
	}

	BinaryNode* search(BinaryNode* r, int d)
	{
		if (r == NULL)
			return NULL;

		if (r->getData() == d)
		{
			return r;
		}
		else if (r->getData() > d)
		{
			return search(r->getLeft(), d);
		}
		else
			return search(r->getRight(), d);
	}

	void remove(int d)
	{
		BinaryNode* node = root;
		BinaryNode* parent = NULL;

		while (node->getData() != d && node != NULL)
		{
			parent = node;
			node = (node->getData()) > d ? node->getLeft() : node->getRight();
		}

		if (node == NULL)
			cout << "없음" << endl;
		else
			remove(parent, node);
	}
	void remove(BinaryNode* p, BinaryNode* n)
	{

		if (n->isLeaf())
		{
			if (p == NULL) root = NULL;
			else
			{
				if (p->getLeft() == n) p->setLeft(NULL);
				else p->setRight(NULL);
			}
		}

		else if (n->getLeft() == NULL || n->getRight() == NULL)
		{
			BinaryNode* child = (n->getLeft() != NULL) ? n->getLeft() : n->getRight();
			if (n == root)
			{
				root = child;
			}
			else
			{
				if (p->getRight() == n)
					p->setRight(child);
				else
					p->setLeft(child);
			}
		}
		else
		{
			BinaryNode* succp = n;
			BinaryNode* succ = n->getRight();
			while (succ->getLeft() != NULL)
			{
				succp = succ;
				succ = succ->getLeft();
			}
			if (succp->getLeft() == succ)
			{
				succp->setLeft(succ->getRight());
			}
			n->setData(succ->getData());
		}

	}
};

int main()
{
	BinarySchTree tree;

	tree.insert(new BinaryNode(35));
	tree.insert(new BinaryNode(18));
	tree.insert(new BinaryNode(7));
	tree.insert(new BinaryNode(26));
	tree.insert(new BinaryNode(12));
	tree.insert(new BinaryNode(3));
	tree.insert(new BinaryNode(68));
	tree.insert(new BinaryNode(22));
	tree.insert(new BinaryNode(30));
	tree.insert(new BinaryNode(99));

	tree.remove(18);
	tree.display();
	tree.preorder();



	return 0;
}
