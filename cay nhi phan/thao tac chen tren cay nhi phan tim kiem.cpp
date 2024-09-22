node *insert(node *root, int key){
if(root == NULL){
return makeNode(key);
}
if(key < root->data){
root->left = insert(root->left, key);
}
else if(key > root->data){
root->right = insert(root->right, key);
}
return root;
}
