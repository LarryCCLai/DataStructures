#include"RBTree.h"

RBTree::RBTree() {
	this->root = nullptr;
	this->nil = new RBTreeNode();
	this->nil->SetColor('B');
}

RBTree::~RBTree() {
	
}

void RBTree::Insert(int key) {
	RBTreeNode* newNode = new RBTreeNode(key, 'R');
	RBTreeNode* cur = this->root;
	RBTreeNode* curParent = this->nil;
	while (cur != nil) {
		curParent = cur;
		if (newNode->GetKey() < cur->GetKey()) {
			cur = cur->GetLeft();
		}
		else {
			cur = cur->GetRight();
		}
	}
	newNode->SetParent(curParent);
	if (curParent == this->nil) {
		this->root = newNode;
	}
	else if (newNode->GetKey() < curParent->GetKey()) {
		curParent->SetLeft(newNode);
	}
	else {
		curParent->SetRight(newNode);
	}
	newNode->SetLeft(this->nil);
	newNode->SetRight(this->nil);
	this->InsertFix(newNode);
}

void RBTree::InsertFix(RBTreeNode* newNode) {
	RBTreeNode* sibling;
	while (newNode->GetParent()->GetColor() == 'R') {
		if (newNode->GetParent() == newNode->GetParent()->GetParent()->GetLeft()) {
			sibling = newNode->GetParent()->GetParent()->GetRight();
			if (sibling->GetColor() == 'R') {
				newNode->GetParent()->SetColor('B');
				sibling->SetColor('B');
				newNode->GetParent()->GetParent()->SetColor('R');
				newNode = newNode->GetParent()->GetParent();
			}
			else {
				if (newNode == newNode->GetParent()->GetRight()) {
					newNode = newNode->GetParent();
					this->LeftRotate(newNode);
				}
				newNode->GetParent()->SetColor('B');
				newNode->GetParent()->GetParent()->SetColor('R');
				this->RightRotate(newNode->GetParent()->GetParent());
			}
		}
		else {
			sibling = newNode->GetParent()->GetParent()->GetLeft();
			if (sibling->GetColor() == 'R') {
				newNode->GetParent()->SetColor('B');
				sibling->SetColor('B');
				newNode->GetParent()->GetParent()->SetColor('R');
				newNode = newNode->GetParent()->GetParent();
			}
			else {
				if (newNode == newNode->GetParent()->GetRight()) {
					newNode = newNode->GetParent();
					this->RightRotate(newNode);
				}
				newNode->GetParent()->SetColor('B');
				newNode->GetParent()->GetParent()->SetColor('R');
				this->LeftRotate(newNode->GetParent()->GetParent());
			}
		}
	}
	this->root->SetColor('B');
}

void RBTree::Delete(int key) {
	RBTreeNode* deleted = this->Search(key);
	if (deleted != this->nil) {
		RBTreeNode* replace = deleted;
		RBTreeNode* fixed;
		char deletedOriginalColor = deleted->GetColor();
		if (deleted->GetLeft() == this->nil) {
			fixed = deleted->GetRight();
			this->Transplant(deleted, deleted->GetRight());
		}
		else if (deleted->GetRight() == this->nil) {
			fixed = deleted->GetLeft();
			this->Transplant(deleted, deleted->GetLeft());
		}
		else {
			replace = this->TreeMinmum(deleted->GetRight());
			deletedOriginalColor = replace->GetColor();
			fixed = replace->GetRight();
			if (replace->GetParent() == deleted) {
				fixed->SetParent(replace);
			}
			else {
				this->Transplant(replace, replace->GetRight());
				replace->SetRight(deleted->GetRight());
				replace->GetRight()->SetParent(replace);
			}
			this->Transplant(deleted, replace);
			replace->SetLeft(deleted->GetLeft());
			replace->GetLeft()->SetParent(replace);
			replace->SetColor(deleted->GetColor());
		}
		if (deletedOriginalColor == 'B') {
			this->DeleteFix(fixed);
		}
		delete deleted;
	}
}

void RBTree::DeleteFix(RBTreeNode* fixed) {
	RBTreeNode* sibling;
	while (fixed != this->root && fixed->GetColor() == 'B') {
		if (fixed == fixed->GetParent()->GetLeft()) {
			sibling = fixed->GetParent()->GetRight();
			if (sibling->GetColor() == 'R') {
				sibling->SetColor('B');
				fixed->GetParent()->SetColor('R');
				this->LeftRotate(fixed->GetParent());
				sibling = fixed->GetParent()->GetRight();
			}
			if (sibling->GetLeft()->GetColor() == 'B' && sibling->GetRight()->GetColor() == 'B') {
				sibling->SetColor('R');
				fixed = fixed->GetParent();
			}
			else {
				if (sibling->GetRight()->GetColor() == 'B') {
					sibling->GetLeft()->SetColor('B');
					sibling->SetColor('R');
					this->RightRotate(sibling);
					sibling = fixed->GetParent()->GetRight();
				}
				sibling->SetColor(fixed->GetParent()->GetColor());
				fixed->GetParent()->SetColor('B');
				sibling->GetRight()->SetColor('B');
				this->LeftRotate(fixed->GetParent());
				fixed = this->root;
			}
		}
		else {
			sibling = fixed->GetParent()->GetLeft();
			if (sibling->GetColor() == 'R') {
				sibling->SetColor('B');
				fixed->GetParent()->SetColor('R');
				this->RightRotate(fixed->GetParent());
				sibling = fixed->GetParent()->GetRight();
			}
			if (sibling->GetLeft()->GetColor() == 'B' && sibling->GetRight()->GetColor() == 'B') {
				sibling->SetColor('R');
				fixed = fixed->GetParent();
			}
			else {
				if (sibling->GetRight()->GetColor() == 'B') {
					sibling->GetLeft()->SetColor('B');
					sibling->SetColor('R');
					this->LeftRotate(sibling);
					sibling = fixed->GetParent()->GetRight();
				}
				sibling->SetColor(fixed->GetParent()->GetColor());
				fixed->GetParent()->SetColor('B');
				sibling->GetRight()->SetColor('B');
				this->RightRotate(fixed->GetParent());
				fixed = this->root;
			}
		}
	}
	fixed->SetColor('B');
}

