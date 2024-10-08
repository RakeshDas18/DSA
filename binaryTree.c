#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insertNode(struct node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }

    return node;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void heapify(struct node* node) {
    if (node == NULL) {
        return;
    }
    heapify(node->left);
    heapify(node->right);

    struct node *left = node->left, *right = node->right;
    if (left != NULL && left->data > node->data) {
        int temp = left->data;
        left->data = node->data;
        node->data = temp;
        heapify(left);
    }
    if (right != NULL && right->data > node->data) {
        int temp = right->data;
        right->data = node->data;
        node->data = temp;
        heapify(right);
    }
}

void heapSort(struct node* node) {
    if (node == NULL) {
        return;
    }
    heapify(node);

    struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
    temp->data = node->data;
    temp->left = node->left;
    temp->right = node->right;

    node->data = root->data;
    node->left = root->left;
    node->right = root->right;

    root->data = temp->data;
    root->left = temp->left;
    root->right = temp->right;

    heapify(node); // Re-heapify after swapping the root with the last node
    deleteNode(node, temp->data); // Delete the last node
    heapSort(node); // Recursive call for sorting the remaining nodes
}

void displayInOrder(struct node* node) {
    if (node == NULL) {
        return;
    }
    displayInOrder(node->left);
    printf("%d\t", node->data);
    displayInOrder(node->right);
}

void displayPreOrder(struct node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d\t", node->data);
    displayPreOrder(node->left);
    displayPreOrder(node->right);
}

void displayPostOrder(struct node* node) {
    if (node == NULL) {
        return;
    }
    displayPostOrder(node->left);
    displayPostOrder(node->right);
    printf("%d\t", node->data);
}

void display(struct node* node) {
    if (node == NULL) {
        return;
    }
    display(node->left);
    printf("%d\t", node->data);
    display(node->right);
}

int main() {
    int n, data, choice;
    int i;
    printf("Enter the total number of nodes of the binary tree: \n");
    scanf("%d", &n);
    printf("Enter Data into the Binary Tree: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    printf("--------------------------------------\n");
    printf("                     MENU\n");
    printf("--------------------------------------\n");
    printf("1. Inorder\n2. Preorder\n3. Postorder\n4. Display binary tree\n5. Insert node\n6. Delete node\n7. Heapify\n8. Heap Sort\n9. Exit\n");
    printf("Enter your choice: \n");
    scanf("%d", &choice);

    while (1) {
        switch (choice) {
            case 1:
                printf("Inorder traversal of the Binary Tree is: \n");
                displayInOrder(root);
                break;
            case 2:
                printf("Preorder traversal of the Binary Tree is: \n");
                displayPreOrder(root);
                break;
            case 3:
                printf("Postorder traversal of the Binary Tree is: \n");
                displayPostOrder(root);
                break;
            case 4:
                printf("The binary tree is: \n");
                display(root);
                break;
            case 5:
                printf("Enter the data to insert: \n");
                scanf("%d", &data);
                root = insertNode(root, data);
                printf("Node inserted successfully!\n");
                break;
            case 6:
                printf("Enter the data to delete: \n");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Node deleted successfully!\n");
                break;
            case 7:
                printf("Heapifying the binary tree...\n");
                heapify(root);
                printf("Binary tree has been heapified!\n");
                break;
            case 8:
            	printf("Sorting the binary tree using Heap Sort...\n");
                heapSort(root);
                printf("Binary tree has been sorted!\n");
                printf("Sorted order: \n");
                display(root);
                break;
            case 9:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Wrong choice!!! Try again.\n");
        }

        printf("\n\nEnter your choice: \n");
        scanf("%d", &choice);
    }

    return 0;
}
