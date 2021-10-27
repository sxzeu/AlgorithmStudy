#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct _node {
	int left, right;
}node[26];

void preorder(int start)
{
	cout << (char)(start + 'A');
	if (node[start].left != -1)
		preorder(node[start].left);
	if (node[start].right != -1)
		preorder(node[start].right);
	return;
}

void inorder(int start)
{
	if (node[start].left != -1)
		inorder(node[start].left);
	cout << (char)(start + 'A');
	if (node[start].right != -1)
		inorder(node[start].right);
	return;
}

void postorder(int start)
{
	if (node[start].left != -1)
		postorder(node[start].left);
	if (node[start].right != -1)
		postorder(node[start].right);
	cout << (char)(start + 'A');
	return;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < 26; ++i)
		node[i].left = node[i].right = -1;

	for (int i = 0; i < n; ++i) {
		char p, l, r;
		cin >> p >> l >> r;
		if (l != '.')
			node[p - 'A'].left = l - 'A';
		if (r != '.')
			node[p - 'A'].right = r - 'A';
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);

	return 0;
}