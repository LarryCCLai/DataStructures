#ifndef BTREE_H
#define BTREE_H
#include"BTreeNode.h"
class BTree{
private:
	BTreeNode* root;
	int T;			// Minimum degree
	void InsertNonFull(BTreeNode* cur, int key);
	void SplitChild(BTreeNode* x, int i);

public:
	BTree(int T);
	~BTree();
	void Insert(int key);
	int Search(int key);
	void Delete(int key);
};
#endif // !BTREE_H

