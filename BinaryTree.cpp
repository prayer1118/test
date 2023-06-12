#include <iostream>
using namespace std;
class BinaryNode
{
public:
	BinaryNode *left;
	BinaryNode* right;
	int data;
	BinaryNode(int d,BinaryNode * l,BinaryNode * r)
	{
		data = d;
		left = l;
		right = r;
	}
	bool isLeaf()
	{
		return ((left == NULL) && (right == NULL));
	}

};

class BinaryTree
{
public:
	BinaryNode * root;
	BinaryTree(BinaryNode * r)
	{
		root = r;
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

		cout << "-"<< static_cast<char>(node->data) << endl;
		display(node->left,depth+1);
		display(node->right,depth+1);

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
		cout << "[" << char(node->data) << "]";
		preorder(node->left);
		preorder(node->right);
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
		inorder(node->left);
		cout << "[" << char(node->data) << "]";
		inorder(node->right);
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
		postorder(node->left);
		postorder(node->right);
		cout << "[" << char(node->data) << "]";
	}

	bool isEmpty()
	{
		return root == NULL;
	}

};


int main()
{
	BinaryNode* e = new BinaryNode('e', NULL, NULL);
	BinaryNode* d = new BinaryNode('d', NULL, NULL);
	BinaryNode* f = new BinaryNode('f', NULL, NULL);
	BinaryNode* c = new BinaryNode('c', f, NULL);
	BinaryNode* b = new BinaryNode('b', d, e);
	BinaryNode* a = new BinaryNode('a', b, c);
	BinaryTree tree(a);
	tree.display();
	tree.preorder();
	tree.inorder();
	tree.postorder();
	
	return 0;
}
