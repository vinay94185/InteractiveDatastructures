#include<iostream>
#include<windows.h>
#include "tree.h"

tree::tree()/*:height(_height)*/ {
	root = NULL;
//	_height = -1;
}
tree::tree(int num)/*:height(_height)*/ {
	init(num);
}

void tree::init(int num) {
	root = new _tree_;
	root -> left = NULL;
	root -> right = NULL;
	root -> data = num;
	in = &inorder;
	pre = &preorder;
	post = &postorder;
//	_height = 0;
}

void tree::push(int num) {
	if(root == NULL) {
		init(num);
	} else {
		temp = root;
//		int tmp_height = 0;
		while(1) {
//			++tmp_height;
			if(temp -> data > num) {
				if(temp -> left == NULL) {
					temp -> left = new_leaf(num);
					break;
				} else {
					temp = temp -> left;
					continue;
				}
			} else if(temp -> data < num) {
				if(temp -> right == NULL) {
					temp -> right = new_leaf(num);
					break;
				} else { 
					temp = temp -> right;
					continue;
				}
			}
			break;
		}
//		if(tmp_height > _height) _height = tmp_height;
	}
}

tree::_tree_* tree::new_leaf(int num) {
	_tree_ *leaf = new _tree_;
	leaf -> left = NULL;
	leaf -> right = NULL;
	leaf -> data = num;
	return leaf;
}

void tree::print(void (tree::*order)(_tree_ *)) {
	if(root == NULL) return;
	temp = root;
	(this->*order)(temp);
}

void tree::preorder(_tree_ *temp) {
	std::cout << temp -> data << " ";	
	if(temp -> left != NULL) preorder(temp -> left);
	if(temp -> right != NULL) preorder(temp -> right);
}

void tree::inorder(_tree_ *temp) {
	if(temp -> left != NULL) inorder(temp -> left);
	std::cout << temp -> data << " ";	
	if(temp -> right != NULL) inorder(temp -> right);
}

void tree::postorder(_tree_ *temp) {
	if(temp -> left != NULL) postorder(temp -> left);
	if(temp -> right != NULL) postorder(temp -> right);
	std::cout << temp -> data << " ";
}


tree::_tree_* tree::search(int num) {
	if(root == NULL) return NULL;
	temp = root;
	while(temp != NULL) {
		if(temp -> data == num) break;
		else {
			if(temp -> data > num) {
				temp = temp -> left;
			} else {
				temp = temp -> right;
			}
		}
	}
	return temp;
}

tree::_tree_* tree::parent_of(tree::_tree_ *item) {
	if(root == NULL || item == NULL || root == item) return NULL;
	_tree_ *tmp = root;
	while(tmp) {
		if(tmp -> data > item -> data) {
			if(tmp -> left == item) break;
			tmp = tmp -> left;
		} else {
			if(tmp -> right == item) break;
			tmp = tmp -> right;
		}
	}
	return tmp;
}

void tree::pop(int num) {
	_tree_* parent;
	_tree_* item;
	item = search(num);
	parent = parent_of(item);
	if(item == NULL) return;
	else {
		if(item -> left && item -> right) {
			temp = item -> right;
			while(temp -> left) temp = temp -> left;
			if(temp -> right) {
				parent_of(temp) -> left = temp -> right;
			}
			if(parent) {
				if(parent -> right == item) {
					parent -> right = item;
				} else {
					parent -> left = item;
				}
			} else {
				root = temp;
				if(item -> left == temp) item -> left = NULL;
				else if(item -> right == temp) item -> right = NULL;
			}
			temp -> left = item -> left;
			temp -> right = item -> right;
		} else if(item -> left || item -> right) {
			if(item -> right) {
					temp = item -> right;
				} else {
					temp = item -> left;
				}
			if(parent) {
				if(parent -> right == item) {
					parent -> right = temp;
				} else {
					parent -> left = temp;
				}
			} else { root = temp; }
		} else {
			if(parent) {
				if(parent -> right == item) {
					parent -> right = NULL;
				} else {
					parent -> left = NULL;
				}
			} else { root = NULL; }
			delete item;
		}
	}
}

void tree::reset() {
	while(root != NULL) pop(root -> data);
//	_height = -1;
}

void tree::show_whole(int beg_h) {
	if(root == NULL) return;
	int height = getheight();
	show_self(root,height*2,beg_h);
	gotoXY(0,((height*2) + beg_h)+2);
}

void tree::show_self(_tree_ *temp,int x,int y) {
	if(temp -> left != NULL) { 
		gotoXY(x-1,y+1);
		std::cout << "/";
		show_self(temp -> left,x-2,y+2); 
	}
	if(temp -> right != NULL) { 
		gotoXY(x+1,y+1);
		std::cout << "\\";
		show_self(temp -> right,x+2,y+2); 
	}
	gotoXY(x,y);
	std::cout << temp -> data;
}

inline void tree::gotoXY(const short X,const short Y) {
	static HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	static COORD cursor;
	cursor.X = X;
	cursor.Y = Y;
	SetConsoleCursorPosition(hOutput,cursor);
}

int tree::getheight() {
	return root ? rec_height(root,0) : -1;
}

int tree::rec_height(_tree_* root,int height) {
	int left = height,right = height;
	if(root -> left != NULL) left = rec_height(root -> left,height + 1);
	if(root -> right != NULL) right = rec_height(root -> right,height + 1);
	return (left > right) ? left:right;
}