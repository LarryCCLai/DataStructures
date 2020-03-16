#ifndef BTREENODE_H
#define BTREENODE_H


class BTreeNode {
private:
	int* keys;
	BTreeNode** children;
	int numberOfKeys;
	bool leaf;
public:

	BTreeNode();
	BTreeNode(bool _leaf);
	~BTreeNode();


	int GetKey(int idx);
	BTreeNode* GetChild(int idx);
	int GetNumberOfKeys();
	bool GetLeaf();

	void SetKey(int idx, int key);
	void SetChild(int idx, BTreeNode* child);
	void SetNumberOfKeys(int num);
	void SetLeaf(bool leaf);

};

#endif // !BTREENODE_H
