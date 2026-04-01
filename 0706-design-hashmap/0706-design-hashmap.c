#define SIZE 10007

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* table[SIZE];
} MyHashMap;

int hash(int key) {
    if (key < 0) key = -key;
    return key % SIZE;
}

MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    for (int i = 0; i < SIZE; i++) {
        obj->table[i] = NULL;
    }
    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int index = hash(key);
    Node* temp = obj->table[index];

    while (temp) {
        if (temp->key == key) {
            temp->value = value;
            return;
        }
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = obj->table[index];
    obj->table[index] = newNode;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int index = hash(key);
    Node* temp = obj->table[index];

    while (temp) {
        if (temp->key == key) {
            return temp->value;
        }
        temp = temp->next;
    }

    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int index = hash(key);
    Node* temp = obj->table[index];
    Node* prev = NULL;

    while (temp) {
        if (temp->key == key) {
            if (prev == NULL) {
                obj->table[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void myHashMapFree(MyHashMap* obj) {
    for (int i = 0; i < SIZE; i++) {
        Node* temp = obj->table[i];
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/