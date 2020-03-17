#ifndef BTREE_H
#define BTREE_H
#include"BTreeNode.h"
class BTree{
private:
	BTreeNode* root;
	int T;			// Minimum degree
public:
	BTree(int T);
	~BTree();
	void Insert(int key);
	int Search(int key);
	void Delete(int key);
	void Inorder();

};
#endif // !BTREE_H

