#ifndef BTREENODE_H
#define BTREENODE_H
#include<fstream>
class BTreeNode {
private:
	int* keys;
	BTreeNode** children;
	int numberOfKeys;
	bool leaf;

	void DeleteFromLeaf(int T, int idx);
	void DeleteFromNonLeaf(int T, int idx);
	int GetPred(int idx);
	int GetSucc(int idx);
	void Fill(int T, int idx);
	void BorrowFromPrev(int T, int idx);
	void BorrowFromNext(int T, int idx);
	void Merge(int T, int idx);

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
	void SplitChild(int T, int idx);

	void Delete(int T, int key);
	int Search(int key);
	void Inorder(std::fstream& file);
};
#endif // !BTREENODE_H
