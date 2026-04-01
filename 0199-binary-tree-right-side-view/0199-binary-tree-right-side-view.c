/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

struct TreeNode* queue[2000];
int front = 0, rear = 0;

void enqueue(struct TreeNode* node) {
    queue[rear++] = node;
}

struct TreeNode* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(sizeof(int) * 2000);
    *returnSize = 0;

    front = rear = 0;
    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue();

            if (i == size - 1) {
                result[*returnSize] = node->val;
                (*returnSize)++;
            }

            if (node->left != NULL) enqueue(node->left);
            if (node->right != NULL) enqueue(node->right);
        }
    }

    return result;
}