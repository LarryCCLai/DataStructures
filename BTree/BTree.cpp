#include"BTree.h"

BTree::BTree(int T) {
	this->root = nullptr;
	this->T = T;
}

BTree::~BTree() {
	delete root;
}

void BTree::Insert(int key) {
	if (this->root == nullptr) {
		this->root = new BTreeNode(T, true);
		this->root->InsertNonFull(T, key);
	}
	else if (this->root->GetNumberOfKeys() == 2 * T - 1) {
		BTreeNode* split = new BTreeNode(T, false);
		split->SetChild(0, root);
		root = split;
		split->SplitChild(T, 0);
		int idx = (key > split->GetKey(0)) ? 1 : 0;
		split->GetChild(idx)->InsertNonFull(T, key);
	}
	else {
		this->root->InsertNonFull(T, key);
	}
}


