#include"BTreeNode.h"


BTreeNode::BTreeNode(){
}

BTreeNode::BTreeNode(bool leaf) {
	this->keys = nullptr;
	this->children = nullptr;
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