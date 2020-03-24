#ifndef  RBTREE_H
#define RBTREE_H
#include"RBTreeNode.h"
class RBTree {
	RBTreeNode* root;
	RBTreeNode* nil;
public:
	RBTree();
	~RBTree();

	void Insert(int key);
	void InsertFix(RBTreeNode*);
	void Delete(int key);
	void DeleteFix(RBTreeNode*);
	RBTreeNode* Search(int key);

	void Transplant(RBTreeNode*, RBTreeNode*);
	void LeftRotate(RBTreeNode*);
	void RightRotate(RBTreeNode*);

	RBTreeNode* TreeMinmum(RBTreeNode*);
	RBTreeNode* TreeMaxmum(RBTreeNode*);
	RBTreeNode* Successor(RBTreeNode*);
	RBTreeNode* Predecessor(RBTreeNode*);

	void Inorder();
	void _Inorder(RBTreeNode* cur);
};
#endif //  RBTREE_H
