//
// Created by 懒小植 on 2018/10/2.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* head = result;
        bool carry = false;
        while(1){
            if(l1 == NULL && l2 == NULL){
                if(carry){
                    result -> next = new ListNode(1);
                }
                break;
            }
            else if(l1 != NULL && l2 != NULL){
                int val;
                if(carry){
                    val = l1->val + l2->val + 1;
                }
                else{
                    val = l1->val + l2->val;
                }
                carry = val / 10;
                result -> next = new ListNode(0);
                result = result -> next;
                result -> val = val % 10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 != NULL){
                while(l1 != NULL){
                    int val;
                    if(carry){
                        val = l1->val + 1;
                        carry = val / 10;
                        result -> next = new ListNode(0);
                        result = result -> next;
                        result -> val = val % 10;
                        l1 = l1 -> next;
                    }
                    else{
                        result -> next = l1;
                        l1 = NULL;
                    }
                }
            }
            else if(l2 != NULL){
                while(l2 != NULL){
                    int val;
                    if(carry){
                        val = l2->val + 1;
                        carry = val / 10;
                        result -> next = new ListNode(0);
                        result = result -> next;
                        result -> val = val % 10;
                        l2 = l2 -> next;
                    }
                    else{
                        result -> next = l2;
                        l2 = NULL;
                    }
                }
            }
        }
        return head -> next;
    }
};