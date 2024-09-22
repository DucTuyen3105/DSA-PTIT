#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left, *right;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

// H�m t�m node c� gi� tr? nh? nh?t (node b�n tr�i nh?t)
node* minNode(node *root) {
    node *temp = root;
    while(temp != NULL && temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

// H�m x�a m?t node c� gi� tr? l� 'key'
node* deleteNode(node *root, int key) {
    if(root == NULL) return root;

    // T�m v? tr� node c?n x�a
    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Tru?ng h?p node c?n x�a c� 0 ho?c 1 con
        if(root->left == NULL) {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // Tru?ng h?p node c?n x�a c� 2 con
        node *temp = minNode(root->right); // T�m gi� tr? nh? nh?t b�n c�y con ph?i
        root->data = temp->data; // Thay th? gi� tr? c?a node c?n x�a b?ng gi� tr? nh? nh?t
        root->right = deleteNode(root->right, temp->data); // X�a node gi� tr? nh? nh?t
    }

    return root;
}
