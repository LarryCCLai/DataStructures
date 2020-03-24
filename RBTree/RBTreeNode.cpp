#include"RBTreeNode.h"
#include<iostream>
RBTreeNode::RBTreeNode() {
	this->key = NULL;
	this->color = NULL;
	this->parent = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}

RBTreeNode::RBTreeNode(int key, char color) {
	this->key = key;
	this->color = color;
	this->parent = nullptr;
	this->left = left;
	this->right = right;
}

RBTreeNode::~RBTreeNode() {
	this->parent = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}

int RBTreeNode::GetKey() {
	return this->key;
}

char RBTreeNode::GetColor() {
	return this->color;
}

RBTreeNode* RBTreeNode::GetParent() {
	return this->parent;
}

RBTreeNode* RBTreeNode::GetLeft() {
	return this->left;
}

RBTreeNode* RBTreeNode::GetRight() {
	return this->right;
}

void RBTreeNode::SetKey(int key) {
	this->key = key;
}

void RBTreeNode::SetColor(char color) {
	this->color = color;
}

void RBTreeNode::SetParent(RBTreeNode* parent) {
	this->parent = parent;
}

void RBTreeNode::SetLeft(RBTreeNode* left) {
	this->left = left;
}

void RBTreeNode::SetRight(RBTreeNode* right) {
	this->right = right;
}
