struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode lessDummy, greaterDummy;
    lessDummy.next = NULL;
    greaterDummy.next = NULL;

    struct ListNode* less = &lessDummy;
    struct ListNode* greater = &greaterDummy;

    while (head != NULL) {
        if (head->val < x) {
            less->next = head;
            less = less->next;
        } else {
            greater->next = head;
            greater = greater->next;
        }
        head = head->next;
    }

    greater->next = NULL;
    less->next = greaterDummy.next;

    return lessDummy.next;
}