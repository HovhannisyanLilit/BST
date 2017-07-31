#include <iostream>
using std::cout;
using std::endl;

struct node {
	int data;
	node* left;
	node* right;
	node* parent;
	node() {}
	node(int d) : data(d), left(nullptr), right(nullptr) {};
};

class tree {
public:
	node* root;
	size_t sz;
	tree() : root(nullptr), sz(0) {}
	~tree()
	{
		clear(root);
	}
	void clear(node*);
	int height(node*);
	bool isBalanced(node*);
	void insert(const int&);
	node* search(int);
	void inorder(node*);
	void postorder(node*);
	void preorder(node*);
	node* copyHelper(const node*);
};
void tree::clear(node* p)
{
	if (p != nullptr)
	{
		if (p->left != nullptr)
			clear(p->left);
		if (p->right != nullptr)
			clear(p->right);
		delete p;
	}
}
node* tree::search(int key)
{
	node* rt = root;
	while (rt != nullptr)
	{
		if (rt->data == key)
			return rt;
		else if (key < rt->data)
			rt = rt->left;
		else
			rt = rt->right;
	}
	return nullptr;
}

void tree::insert(const int& value)
{
	node* p = new node(value);
	node* parent = nullptr;

	if (!sz)
	{
		root = p;
		++sz;
		return;
	}
	node* curr = root;

	while (curr != nullptr)
	{
		parent = curr;
		curr = p->data > curr->data ? curr->right : curr->left;
	}

	if (p->data < parent->data)
		parent->left = p;
	else
		parent->right = p;
	++sz;
}
int tree::height(node* rt)
{
	if (rt == nullptr)
		return 0;
	else
	{
		int left = height(rt->left);
		int right = height(rt->right);
		if (left > right)
			return left + 1;
		else
			return right + 1;
	}
}
bool tree::isBalanced(node* rt)
{
	if (rt == nullptr)
		return true;
	int left = height(rt->left);
	int right = height(rt->right);
	if (abs(left - right) <= 1 &&
		isBalanced(rt->left) &&
		isBalanced(rt->right))
		return true;
	return false;
}
void tree::inorder(node* p)
{
	if (p != nullptr)
	{
		if (p->left != nullptr)
			inorder(p->left);
		cout << p->data << " ";
		if (p->right != nullptr)
			inorder(p->right);
	}
}
int main()
{
	tree ob;
	ob.insert(9);
	ob.insert(4);
	ob.insert(11);
	ob.insert(3);
	ob.insert(6);
	ob.insert(12);
	ob.insert(10);



	cout << endl;
	ob.inorder(ob.root);
	cout << endl;


	cout << ob.isBalanced(ob.root) << endl;
	cout << ob.height(ob.root) << endl;

	tree ob2;
	ob2 = ob;
	cout << endl << endl << endl;


	return 0;
}