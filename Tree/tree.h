#ifndef _TREE
#define _TREE
class tree {
	struct _tree_ {
		int data;
		_tree_ *left;
		_tree_ *right;
	};
	_tree_ *root;
	_tree_ *temp;
//	int _height;
		int rec_height(_tree_*,int);
		void init(int);
		void inorder(_tree_ *);
		void preorder(_tree_ *);
		void postorder(_tree_ *);
		_tree_* new_leaf(int);
		_tree_* parent_of(_tree_*);
		void gotoXY(const short,const short);
		void show_self(_tree_*,int,int);
	public:
//		const int &height;
		typedef struct _tree_  holder;
		void push(int);
		void print(void (tree::*)(_tree_ *));
		_tree_* search(int);
		void pop(int);
		void show_whole(int);
		void reset();
		int getheight();
		
		void (tree::*pre) (_tree_*);
		void (tree::*in) (_tree_*);
		void (tree::*post) (_tree_*);
		
		tree();
		tree(int);
};
#endif