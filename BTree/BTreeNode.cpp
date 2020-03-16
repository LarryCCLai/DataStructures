#include"BTreeNode.h"


BTreeNode::BTreeNode(){
}

BTreeNode::BTreeNode(int T,bool leaf) {
	this->keys = new int[2 * T - 1];
	this->children = new BTreeNode * [2 * T];
	this->numberOfKeys = 0;
	this->leaf = leaf;
}

BTreeNode::~BTreeNode() { 
	delete[]keys; 
	
	delete[](children);
}

int BTreeNode::GetKey(int idx) {
	return this->keys[idx];
}

BTreeNode* BTreeNode::GetChild(int idx) {
	return this->children[idx];
}

int BTreeNode::GetNumberOfKeys() {
	return this->numberOfKeys;
}

bool BTreeNode::GetLeaf() {
	return this->leaf;
}

void BTreeNode::SetKey(int idx, int key) {
	this->keys[idx] = key;
}

void BTreeNode::SetChild(int idx, BTreeNode* child) {
	this->children[idx] = child;
}

void BTreeNode::SetNumberOfKeys(int num) {
	this->numberOfKeys = num;
}

void BTreeNode::SetLeaf(bool leaf) {
	this->leaf = leaf;
}

void BTreeNode::InsertNonFull(int T, int key) {
	int idx = this->GetNumberOfKeys() - 1;
	if (this->GetLeaf()) {
		while (idx >= 0 && key < this->GetKey(idx)) {
			this->SetKey(idx + 1, this->GetKey(idx));
			idx--;
		}
		this->SetKey(idx + 1, key);
		this->SetNumberOfKeys(this->GetNumberOfKeys() + 1);
	}
	else {
		while (idx >= 0 && key < this->GetKey(idx)) {
			idx--;
		}
		idx++;
		if (this->GetChild(idx)->GetNumberOfKeys() == 2 * T - 1) {
			this->SplitChild(T, idx);
			if (key > this->GetKey(idx)) {
				idx++;
			}
		}
		this->GetChild(idx)->InsertNonFull(T, key);
	}
}

void BTreeNode::SplitChild(int T, int idx) {
	BTreeNode* rightChild = new BTreeNode(T, false);
	BTreeNode* leftChild = this->GetChild(idx);

	rightChild->SetLeaf(leftChild->GetLeaf());
	rightChild->SetNumberOfKeys(T - 1);
	
	for (int i = 0; i < T - idx; i++) {
		rightChild->SetKey(i, leftChild->GetKey(i + T));
	}
	if (!rightChild->GetLeaf()) {
		for (int i = 0; i < T; i++)	{
			rightChild->SetChild(i, leftChild->GetChild(i + T));
		}
	}
	leftChild->SetNumberOfKeys(T - 1);

	for (int i = this->GetNumberOfKeys(); i > idx; i--) {
		this->SetChild(i + 1, this->GetChild(i));
	}
	this->SetChild(idx + 1, rightChild);
	for (int i = this->GetNumberOfKeys() - 1; i >= idx; i--) {
		this->SetKey(i + 1, this->GetKey(i));
	}

	this->SetKey(idx, leftChild->GetKey(T - 1));
	this->SetNumberOfKeys(this->GetNumberOfKeys() + 1);
}