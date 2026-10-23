class Solution {
public:
    int len(ListNode* head) {
        int count = 0;

        while (head != NULL) {
            count++;
            head = head->next;
        }

        return count;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int N = len(head);
        int groups = N / k;

        ListNode* prevHead = NULL;
        ListNode* currHead = head;
        ListNode* ansNode = head;

        for (int i = 0; i < groups; i++) {
            ListNode* prev = NULL;
            ListNode* curr = currHead;
            ListNode* nextNode = NULL;

            // Reverse k nodes
            for (int j = 0; j < k; j++) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Connect previous group
            if (prevHead == NULL) {
                ansNode = prev;
            } else {
                prevHead->next = prev;
            }

            prevHead = currHead;
            currHead = curr;
        }

        // Attach remaining nodes
        if (prevHead != NULL)
            prevHead->next = currHead;

        return ansNode;
    }
};