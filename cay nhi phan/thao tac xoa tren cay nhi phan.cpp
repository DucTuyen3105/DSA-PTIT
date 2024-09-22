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

// Hàm tìm node có giá tr? nh? nh?t (node bên trái nh?t)
node* minNode(node *root) {
    node *temp = root;
    while(temp != NULL && temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

// Hàm xóa m?t node có giá tr? là 'key'
node* deleteNode(node *root, int key) {
    if(root == NULL) return root;

    // Tìm v? trí node c?n xóa
    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Tru?ng h?p node c?n xóa có 0 ho?c 1 con
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

        // Tru?ng h?p node c?n xóa có 2 con
        node *temp = minNode(root->right); // Tìm giá tr? nh? nh?t bên cây con ph?i
        root->data = temp->data; // Thay th? giá tr? c?a node c?n xóa b?ng giá tr? nh? nh?t
        root->right = deleteNode(root->right, temp->data); // Xóa node giá tr? nh? nh?t
    }

    return root;
}
