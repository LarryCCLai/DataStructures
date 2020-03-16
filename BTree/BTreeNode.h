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
	BTreeNode(int T, bool _leaf);
	~BTreeNode();

	int GetKey(int idx);
	BTreeNode* GetChild(int idx);
	int GetNumberOfKeys();
	bool GetLeaf();

	void SetKey(int idx, int key);
	void SetChild(int idx, BTreeNode* child);
	void SetNumberOfKeys(int num);
	void SetLeaf(bool leaf);

	void InsertNonFull(int T, int key);
	void SplitChild(int T, int i);
	
};

#endif // !BTREENODE_H
