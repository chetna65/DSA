struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* curr = head;

    while (curr != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = curr->val;
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }

    curr = head;

    while (curr != NULL) {
        if (curr->random != NULL)
            curr->next->random = curr->random->next;
        else
            curr->next->random = NULL;
        curr = curr->next->next;
    }

    curr = head;
    struct Node* newHead = head->next;

    while (curr != NULL) {
        struct Node* copy = curr->next;
        curr->next = copy->next;
        if (copy->next != NULL)
            copy->next = copy->next->next;
        curr = curr->next;
    }

    return newHead;
}