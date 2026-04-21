/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct {
    struct ListNode** arr;
    int size;
} MinHeap;

void swap(struct ListNode** a, struct ListNode** b) {
    struct ListNode* t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap* h, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->arr[p]->val > h->arr[i]->val) {
            swap(&h->arr[p], &h->arr[i]);
            i = p;
        } else break;
    }
}

void heapifyDown(MinHeap* h, int i) {
    while (1) {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < h->size && h->arr[l]->val < h->arr[smallest]->val)
            smallest = l;
        if (r < h->size && h->arr[r]->val < h->arr[smallest]->val)
            smallest = r;

        if (smallest != i) {
            swap(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else break;
    }
}

void push(MinHeap* h, struct ListNode* node) {
    h->arr[h->size++] = node;
    heapifyUp(h, h->size - 1);
}

struct ListNode* pop(MinHeap* h) {
    struct ListNode* root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;

    MinHeap h;
    h.arr = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
    h.size = 0;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i]) push(&h, lists[i]);
    }

    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    tail->next = NULL;

    while (h.size > 0) {
        struct ListNode* minNode = pop(&h);
        tail->next = minNode;
        tail = tail->next;

        if (minNode->next) {
            push(&h, minNode->next);
        }
    }

    struct ListNode* result = dummy.next;
    free(h.arr);
    return result;
}