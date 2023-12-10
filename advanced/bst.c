#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new BST node
struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into the BST
struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to search for a key in the BST
struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function to find the minimum value node in a BST
struct TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a key from the BST
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct TreeNode* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Function to perform inorder traversal of the BST
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    int keyToSearch = 40;
    struct TreeNode* searchResult = search(root, keyToSearch);
    if (searchResult != NULL) {
        printf("%d found in the BST.\n", keyToSearch);
    } else {
        printf("%d not found in the BST.\n", keyToSearch);
    }

    int keyToDelete = 30;
    root = deleteNode(root, keyToDelete);
    printf("Inorder traversal after deleting %d: ", keyToDelete);
    inorder(root);
    printf("\n");

    return 0;
}

/*
1. If the tree is empty, return NULL.
2. Compare the key of the current node with the key to be deleted:
   a. If the key is less than the current node's key, recursively call `deleteNode` on the left subtree.
   b. If the key is greater than the current node's key, recursively call `deleteNode` on the right subtree.
   c. If the key matches the current node's key:
      i. If the node has only one child or no child:
         - Return the child (if any), which effectively removes the current node.
      ii. If the node has two children:
         - Find the in-order successor (the smallest node in the right subtree).
         - Copy the in-order successor's key to the current node.
         - Recursively call `deleteNode` on the right subtree to delete the in-order successor.
3. Return the modified (or unchanged) subtree to the caller.
*/
