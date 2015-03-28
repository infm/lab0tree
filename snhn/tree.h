#ifndef __TREE__
#define __TREE__

#include <stdlib.h>

class Node {
    public:
        Node* parent;
        Node* left;
        Node* right;

        int data;
        Node(int data, Node* parent, bool is_left);
        virtual ~Node();
};

class Tree {
    public:
        Tree();
        virtual ~Tree();

        Node* find(const int);
        Node* insert(const int);
        void remove(Node*&);

        Node* next(Node*);
        Node* prev(Node*);
    private:
        Node* root;

        Node* tree_min(Node*);
        Node* tree_max(Node*);
};

#endif
