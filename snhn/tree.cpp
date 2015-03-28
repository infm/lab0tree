#include "tree.h"

#include <algorithm>

Node::Node(int data, Node* parent, bool is_left){
    this -> data = data;
    this -> parent = parent;
    if (parent){
        if (is_left)
            parent -> left = this;
        else
            parent -> right = this;
    }
}

Node::~Node(){
    if (NULL != parent)
        free(parent);
    if (NULL != left)
        free(left);
    if (NULL != right)
        free(right);
}

Tree::Tree(){
    root = NULL;
}

Tree::~Tree(){
    free(root);
}

Node* Tree::find(const int key){
    Node* curr = root;
    while (NULL != curr){
        if (key == curr -> data)
            return curr;
        if (key > curr -> data)
            curr = root -> right;
        else
            curr = root -> left;
    }
    return curr;
}

Node* Tree::insert(const int key){
    Node* curr = root;
    Node* prev = NULL;
    while (curr){
        prev = curr;
        if (key > curr -> data)
            curr = curr -> right;
        else
            curr = curr -> left;
    }
    if (!prev)
        return root = new Node(key, NULL, false);
    else if (key > prev -> data)
        return prev -> right = new Node(key, prev, false);
    else
        return prev -> left = new Node(key, prev, true);
}

void Tree::remove(Node*& node){
    if (NULL != node){
        Node* left = node -> left;
        Node* right = node -> right;

        if (left && right){
            Node* successor = next(node);
            std::swap(successor -> data, node -> data);
            remove(successor);
        } else {
            Node* child = (left) ? left : right;
            if (node -> parent){
                child -> parent = node -> parent;
                if (node -> parent -> right == node)
                    node -> parent -> right = child;
                else
                    node -> parent -> left = child;
            } else {
                root = child;
            }
        }
    }
}

Node* Tree::next(Node* curr){
    if (curr -> right)
        return tree_min(curr -> right);
    if (curr -> parent && curr -> parent -> left == curr)
        return next(curr -> parent);
    return curr;
}

Node* Tree::prev(Node* curr){
    if (curr -> left)
        return tree_max(curr -> left);
    if (curr -> parent && curr -> parent -> right == curr)
        return prev(curr -> parent);
    return curr;
}

Node* Tree::tree_min(Node* curr){
    while (curr -> left)
        curr = curr -> left;
    return curr;
}

Node* Tree::tree_max(Node* curr){
    while (curr -> right)
        curr = curr -> right;
    return curr;
}
