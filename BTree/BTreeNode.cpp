
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
	int idx = this->numberOfKeys - 1;

	if (this->leaf) {
		while (idx >= 0 && key < this->keys[idx]) {
			this->keys[idx + 1] = this->keys[idx];
			idx--;
		}
		this->keys[idx + 1] = key;
		this->numberOfKeys++;
	}
	else {
		while (idx >= 0 && key < this->keys[idx]) {
			idx--;
		}
		idx++;
		if (this->children[idx]->numberOfKeys == 2 * T - 1) {
			this->SplitChild(T, idx);
			if (key > this->keys[idx]) {
				idx++;
			}
		}
		this->children[idx]->InsertNonFull(T, key);
	}
}

void BTreeNode::SplitChild(int T, int idx) {
	BTreeNode* rightChild = new BTreeNode(T, false);
	BTreeNode* leftChild = this->children[idx];

	rightChild->leaf = leftChild->leaf;
	rightChild->numberOfKeys = T - 1;
	
	for (int i = 0; i < T - 1; i++) {
		rightChild->keys[i] = leftChild->keys[i + T];
	}
	if (!rightChild->leaf) {
		for (int i = 0; i < T; i++)	{
			rightChild->children[i] = leftChild->children[i + T];
		}
	}
	leftChild->numberOfKeys = T - 1;

	for (int i = this->numberOfKeys; i > idx; i--) {
		this->children[i + 1] = this->children[i];
	}

	this->children[idx + 1] = rightChild;
	
	for (int i = this->numberOfKeys - 1; i >= idx; i--) {
		this->keys[i + 1] = this->keys[i];
	}
	this->keys[idx] = leftChild->keys[T - 1];
	this->numberOfKeys++;
}

void BTreeNode::Delete(int T, int key) {
	int idx = 0;
	while (idx < this->numberOfKeys && this->keys[idx] < key) {
		idx++;
	}

	if (idx < this->numberOfKeys && this->keys[idx] == key) {
		if (this->leaf) {
			this->DeleteFromLeaf(T, idx);
		}
		else {
			this->DeleteFromNonLeaf(T, idx);
		}
	}
	else {
		if (this->leaf) {
			return;
		}
		bool flag = idx == this->numberOfKeys;
		if (this->children[idx]->numberOfKeys < T) {
			this->Fill(T, idx);
		}

		if (flag && idx > this->GetNumberOfKeys()) {
			this->children[idx - 1]->Delete(T, key);
		}
		else {
			this->children[idx]->Delete(T, key);
		}

	}
}

void BTreeNode::DeleteFromLeaf(int T, int idx) {
	for (int i = idx + 1; i < this->numberOfKeys; i++) {
		this->keys[i - 1] = this->keys[i];
	}
	this->numberOfKeys--;
}

void BTreeNode::DeleteFromNonLeaf(int T, int idx) {
	int key = this->keys[idx];
	if (this->children[idx]->numberOfKeys >= T) {
		int pred = this->GetPred(idx);
		this->keys[idx] = pred;
		this->children[idx]->Delete(T, pred);
	}
	else if (this->children[idx + 1]->numberOfKeys >= T) {
		int succ = this->GetSucc(idx);
		this->keys[idx] = succ;
		this->children[idx + 1]->Delete(T, succ);
	}
	else {
		this->Merge(T, idx);
		this->children[idx]->Delete(T, key);
	}
}

int BTreeNode::GetPred(int idx) {
	BTreeNode* cur = this->children[idx];
	while (!cur->leaf) {
		cur = cur->children[cur->numberOfKeys];
	}
	return cur->keys[cur->numberOfKeys - 1];
}

int BTreeNode::GetSucc(int idx) {
	BTreeNode* cur = this->children[idx + 1];
	while (!cur->leaf) {
		cur = cur->children[0];
	}
	return cur->keys[0];
}

void BTreeNode::Fill(int T, int idx) {
	if (idx != 0 && this->children[idx - 1]->numberOfKeys >= T) {
		this->BorrowFromPrev(T, idx);
	}
	else if (idx != this->numberOfKeys && this->children[idx + 1]->numberOfKeys >= T) {
		this->BorrowFromNext(T, idx);
	}
	else if (idx != this->numberOfKeys) {
		this->Merge(T, idx);
	}
	else {
		this->Merge(T, idx - 1);
	}
}

void BTreeNode::BorrowFromPrev(int T, int idx) {
	BTreeNode* child = this->children[idx];
	BTreeNode* sibling = this->children[idx - 1];

	for (int i = child->numberOfKeys - 1; i >= 0; i--) {
		child->keys[i + 1] = child->keys[i];
	}

	if (!child->leaf) {
		for (int i = child->numberOfKeys; i >= 0; i--) {
			child->children[i + 1] = child->children[i];
		}
	}

	child->keys[0] = this->keys[idx - 1];

	if (!child->leaf) {
		child->children[0] = sibling->children[sibling->numberOfKeys];
	}

	this->keys[idx - 1] = sibling->keys[sibling->numberOfKeys - 1];

	child->numberOfKeys++;
	sibling->numberOfKeys--;
}

void BTreeNode::BorrowFromNext(int T, int idx) {
	BTreeNode* child = this->children[idx];
	BTreeNode* sibling = this->children[idx + 1];

	child->keys[child->numberOfKeys] = this->keys[idx];

	if (!child->leaf) {
		child->children[child->numberOfKeys + 1] = sibling->children[0];
	}

	this->keys[idx] = sibling->keys[0];

	for (int i = 1; i < sibling->numberOfKeys; i++) {
		sibling->keys[i - 1] = sibling->keys[i];
	}

	if (!sibling->leaf) {
		for (int i = 1; i <= sibling->numberOfKeys; i++) {
			sibling->children[i - 1] = sibling->children[i];
		}
	}

	child->numberOfKeys++;
	sibling->numberOfKeys--;
}

void BTreeNode::Merge(int T, int idx) {
	BTreeNode* child = children[idx];
	BTreeNode* sibling = children[idx + 1];

	child->keys[T - 1] = keys[idx];

	for (int i = 0; i < sibling->numberOfKeys; i++) {
		child->keys[i + T] = sibling->keys[i];
	}

	if (!child->leaf) {
		for (int i = 0; i <= sibling->numberOfKeys; i++) {
			child->children[i + T] = sibling->children[i];
		}
	}

	for (int i = idx + 1; i < numberOfKeys; i++) {
		keys[i - 1] = keys[i];
	}

	for (int i = idx + 2; i <= numberOfKeys; i++) {
		children[i - 1] = children[i];
	}

	child->numberOfKeys += sibling->numberOfKeys + 1;
	numberOfKeys--;

	delete(sibling);
}

int BTreeNode::Search(int key) {
	int idx = 0;
	while (idx < this->numberOfKeys && key > this->keys[idx]) {
		idx++;
	}
	if (idx < this->numberOfKeys && keys[idx] == key) {
		return key;
	}
	else if (this->leaf) {
		return -1;
	}
	else {
		return this->children[idx]->Search(key);
	}
}

void BTreeNode::Inorder(std::fstream& file) {
	for (int i = 0; i < this->GetNumberOfKeys(); i++) {
		if (leaf == false) {
			this->GetChild(i)->Inorder(file);
		}
		file << keys[i] << " ";
	}
	if (leaf == false) {
		this->GetChild(this->GetNumberOfKeys())->Inorder(file);
	}
}
