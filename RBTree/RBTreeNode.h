#ifndef RBTREENODE_H
#define RBTREENODE_H
class RBTreeNode {
private:
	int key;
	char color;
	RBTreeNode* parent;
	RBTreeNode* left;
	RBTreeNode* right;
public:
	RBTreeNode ();
	RBTreeNode(int key, char color);
	~RBTreeNode ();
	
	int GetKey();
	char GetColor();
	RBTreeNode* GetParent();
	RBTreeNode* GetLeft();
	RBTreeNode* GetRight();

	void SetKey(int key);
	void SetColor(char color);
	void SetParent(RBTreeNode* parent);
	void SetLeft(RBTreeNode* left);
	void SetRight(RBTreeNode* right);
};

#endif // !RBTREENODE_H

