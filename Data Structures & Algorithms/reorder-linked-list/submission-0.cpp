class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. Count nodes
        int n = 0;
        ListNode* dummy = head;
        while (dummy) {
            n++;
            dummy = dummy->next;
        }

        // 2. Move to midpoint
        int mid = (n/2) + (n%2);
        dummy = head;
        for (int i = 1; i < mid; i++) {
            dummy = dummy->next;
        }

        // dummy is now at midpoint
        ListNode* second = dummy->next;
        dummy->next = nullptr; // break list

        // 3. Reverse second half
        ListNode* tail = nullptr;
        ListNode* temp;
        while (second) {
            temp = second->next;
            second->next = tail;
            tail = second;
            second = temp;
        }

        // 4. Merge alternating
        ListNode* first = head;
        ListNode* next1;
        ListNode* next2;

        while (tail) {
            next1 = first->next;
            next2 = tail->next;

            first->next = tail;
            tail->next = next1;

            first = next1;
            tail = next2;
        }
    }
};
