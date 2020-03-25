#ifndef  RBTREE_H
#define RBTREE_H
#include"RBTreeNode.h"
class RBTree {
	RBTreeNode* root;
	RBTreeNode* nil;

	void InsertFix(RBTreeNode*);
	void DeleteFix(RBTreeNode*);
	void Transplant(RBTreeNode*, RBTreeNode*);
	void LeftRotate(RBTreeNode*);
	void RightRotate(RBTreeNode*);
	RBTreeNode* TreeMinmum(RBTreeNode*);
	RBTreeNode* TreeMaxmum(RBTreeNode*);
	void _Inorder(RBTreeNode* cur);

public:
	RBTree();
	~RBTree();
	void Insert(int key);
	void Delete(int key);
	RBTreeNode* Search(int key);
	void Inorder();
};
#endif //  RBTREE_H
