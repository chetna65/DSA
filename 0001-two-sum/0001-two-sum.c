/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define TABLE_SIZE 10007 
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    
    hashTable[index] = newNode;
}

int search(int key) {
    int index = hash(key);
    Node* temp = hashTable[index];
    
    while (temp) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    
    return -1;  
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        int foundIndex = search(complement);
        
        if (foundIndex != -1) {
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;
            return result;
        }

        insert(nums[i], i);
    }

    return NULL;
}