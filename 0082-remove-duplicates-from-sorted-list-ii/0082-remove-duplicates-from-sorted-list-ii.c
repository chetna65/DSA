struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* prev = &dummy;

    while (head != NULL) {
        if (head->next != NULL && head->val == head->next->val) {
            int val = head->val;
            while (head != NULL && head->val == val) {
                head = head->next;
            }
            prev->next = head;
        } else {
            prev = prev->next;
            head = head->next;
        }
    }

    return dummy.next;
}