/*
23. 合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。
*/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = nullptr;
        if (lists.size() == 0) {
            head = nullptr;
            return head;
        }
        if (lists.size() == 1) {
            head = lists[0];
            return head;
        }
        ListNode* L = nullptr;
        for (int i = 0; i < lists.size(); i++) {
            head = merge(head, lists[i]);
        }
        return head;
    }
private:
    ListNode* merge(ListNode* H1, ListNode* H2) {
        if (H1 == nullptr)
            return H2;
        if (H2 == nullptr)
            return H1;
        ListNode* A_return = (ListNode*)malloc(sizeof(ListNode));
        ListNode* A = A_return;
        if (H1->val <= H2->val ){
            A->val = H1->val;
            H1 = H1->next;
        }
        else {
            A->val = H2->val;
            H2 = H2->next;
        }
        for (; H1 != nullptr || H2 != nullptr; ) {
            if (H1 == nullptr) {
                A->next = (ListNode*)malloc(sizeof(ListNode));
                A = A->next;
                A->val = H2->val;
                H2 = H2->next;
            }
            else if (H2 == nullptr) {
                A->next = (ListNode*)malloc(sizeof(ListNode));
                A = A->next;
                A->val = H1->val;
                H1 = H1->next;
            }
            else {
                if (H1->val >= H2->val) {
                    A->next = (ListNode*)malloc(sizeof(ListNode));
                    A = A->next;
                    A->val = H2->val;
                    H2 = H2->next;
                }
                else {
                    A->next = (ListNode*)malloc(sizeof(ListNode));
                    A = A->next;
                    A->val = H1->val;
                    H1 = H1->next;
                }
            }
        }
        A->next = nullptr;
        return A_return;
    }
};
