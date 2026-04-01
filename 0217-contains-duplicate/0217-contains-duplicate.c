#define TABLE_SIZE 10007

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

bool search(int key) {
    int index = hash(key);
    Node* temp = hashTable[index];
    
    while (temp) {
        if (temp->key == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void insert(int key) {
    int index = hash(key);
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = hashTable[index];
    
    hashTable[index] = newNode;
}

bool containsDuplicate(int* nums, int numsSize) {
    
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    for (int i = 0; i < numsSize; i++) {
        
        if (search(nums[i])) {
            return true;  
        }
        
        insert(nums[i]);
    }
    
    return false;  
}