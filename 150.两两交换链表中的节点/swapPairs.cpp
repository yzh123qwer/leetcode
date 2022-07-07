/*
24. 两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

 

示例 1：


输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：

输入：head = []
输出：[]
示例 3：

输入：head = [1]
输出：[1]
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* temp_last = nullptr;
        ListNode* temp = nullptr;
        ListNode* temp_next;
        while(true){
            if (temp_last == nullptr){
                temp = head->next;
                if (temp == nullptr)
                    break;
                head->next = temp->next;
                temp->next = head;
                head = temp;
                temp_last = head->next;
            }
            temp = temp_last->next;
            if (temp == nullptr)
                break;
            temp_next = temp->next;
            if (temp_next == nullptr)
                break;
            temp->next = temp_next->next;
            temp_last->next = temp_next;
            temp_next->next = temp;
            temp_last = temp;
        }
        return head;
    }
};
