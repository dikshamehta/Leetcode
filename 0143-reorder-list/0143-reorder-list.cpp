/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reverse(ListNode* node){
        ListNode* current = node->next;
        node->next = nullptr;

        ListNode* temp;
        while(current->next != nullptr){
            temp = current->next;
            current->next = node;
            node = current;
            current = temp;
        }
    }
    void reorderList(ListNode* head) {
        if(!head) return;

        // find the middle element with fast slow
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }


        // reverse the numbers after slow
        ListNode* current = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
    
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }


        // now select one at a time from both the parts
        ListNode* first = head;
        ListNode* second = prev; // prev is head of second half right now

        while(second != nullptr){ // because second half will be either equal or smaller than first
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;

        }

    }
};