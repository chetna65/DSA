/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
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

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);

    *returnSize = 0;

    front = rear = 0;

    enqueue(root);

    while (!isEmpty()) {
        int size = rear - front;

        int* level = (int*)malloc(sizeof(int) * size);

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue();
            level[i] = node->val;

            if (node->left != NULL) enqueue(node->left);
            if (node->right != NULL) enqueue(node->right);
        }

        result[*returnSize] = level;
        (*returnColumnSizes)[*returnSize] = size;
        (*returnSize)++;
    }

    return result;
}