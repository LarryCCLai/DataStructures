#include"BTree.h"

BTree::BTree(int T) {
	this->root = nullptr;
	this->T = T;
}

BTree::~BTree() {
	delete root;
}

void BTree::InsertNonFull(BTreeNode* cur, int key) {
	int idx = cur->GetNumberOfKeys() - 1;
	if (cur->GetLeaf()) {
		while (idx >= 0 && key < cur->GetKey(idx)) {
			cur->SetKey(idx + 1, cur->GetKey(idx));
			idx--;
		}
		cur->SetKey(idx + 1, key);
		cur->SetNumberOfKeys(cur->GetNumberOfKeys() + 1);
	}
	else {
		while (idx >= 0 && key < cur->GetKey(idx)) {
			idx--;
		}
		idx++;
		if (cur->GetChild(idx)->GetNumberOfKeys() == 2 * T - 1) {

			SplitChild(cur, idx);
			if (key > cur->GetKey(idx)) {
				idx++;
			}
		}
		InsertNonFull(cur->GetChild(idx), key);
	}
}

void BTree::SplitChild(BTreeNode* split, int leftChildIdx) {
	BTreeNode* rightChild = new BTreeNode(T, false);
	BTreeNode* leftChild = split->GetChild(leftChildIdx);

	rightChild->SetLeaf(leftChild->GetLeaf());
	rightChild->SetNumberOfKeys(T - 1);
	
	for (int idx = 0; idx < T - idx; idx++) {
		rightChild->SetKey(idx, leftChild->GetKey(idx + T));
	}
	if (!rightChild->GetLeaf()) {
		for (int idx = 0; idx < T; idx++) {
			rightChild->SetChild(idx, leftChild->GetChild(idx + T));
		}
	}
	leftChild->SetNumberOfKeys(T - 1);

	for (int idx = split->GetNumberOfKeys(); idx >= leftChildIdx + 1; idx--) {
		split->SetChild(idx + 1, split->GetChild(idx));
	}

	split->SetChild(leftChildIdx + 1, rightChild);
	for (int idx = split->GetNumberOfKeys() - 1; idx >= leftChildIdx; idx--) {
		split->SetKey(idx + 1, split->GetKey(idx));
	}
	split->SetKey(leftChildIdx, leftChild->GetKey(T - 1));
	split->SetNumberOfKeys(split->GetNumberOfKeys() + 1);
}

void BTree::Insert(int key) {
	if (this->root == nullptr) {
		this->root = new BTreeNode(T, true);
		this->InsertNonFull(this->root, key);
	}
	else if (this->root->GetNumberOfKeys() == 2 * this->T - 1) {
		BTreeNode* split = new BTreeNode(T, false);
		split->SetChild(0, root);
		root = split;
		this->SplitChild(split, 0);
		int idx = (split->GetKey(0) < key) ? 1 : 0;
		this->InsertNonFull(split->GetChild(idx), key);
	}
	else {
		this->InsertNonFull(this->root, key);
	}
}

