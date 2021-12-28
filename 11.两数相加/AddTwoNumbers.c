/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例 1：

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* TheNode;
int ListNode_length(TheNode list)
{
    int i = 0;
    for ( ; list != NULL; list = list->next, i++);
    return i;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if (l1->val == 0)
        return l2;
    else if (l2->val == 0)
        return l1;
    else
    { 
        if (ListNode_length(l1) >= ListNode_length(l2))//使得l1是较长的链表
        {
            int carry;
            TheNode list_return = (TheNode)malloc(sizeof(struct ListNode));
            if (l1->val + l2->val >= 10)
            {
                list_return->val = l1->val + l2->val - 10;
                carry = 1;
            }
            else
            {
                list_return->val = l1->val + l2->val;
                carry = 0;
            }
            TheNode i, j, k1, k2;
            i = l1->next;
            if (i == NULL)
            {
                if (carry == 0)
                {
                    list_return->next = NULL;
                    return list_return;
                }
                else
                {
                    k2 = (TheNode)malloc(sizeof(struct ListNode));
                    k2->val = 1;
                    k2->next = NULL;
                    list_return->next = k2;
                    return list_return;
                }
            }
            for (i = l1->next, j = l2->next, k1 = list_return; i->next != NULL; i = i->next)
            {
                if (j == NULL)
                {
                    if (i->val + carry >= 10)
                    {
                        k2 = (TheNode)malloc(sizeof(struct ListNode));
                        k2->val = i->val + carry - 10;
                        k1->next = k2;
                        k1 = k2;
                        carry = 1;
                    }
                    else
                    {
                        k2 = (TheNode)malloc(sizeof(struct ListNode));
                        k2->val = i->val + carry;
                        k1->next = k2;
                        k1 = k2;
                        carry = 0;
                    }
                }
                else
                {
                    if (i->val + j->val + carry >= 10)
                    {
                        k2 = (TheNode)malloc(sizeof(struct ListNode));
                        k2->val = i->val + j->val + carry - 10;
                        k1->next = k2;
                        k1 = k2;
                        carry = 1;
                        j = j->next;
                    }
                    else
                    {
                        k2 = (TheNode)malloc(sizeof(struct ListNode));
                        k2->val = i->val + j->val + carry;
                        k1->next = k2;
                        k1 = k2;
                        carry = 0;
                        j = j->next;
                    }
                }
            }
            if (i == NULL)
            {
                if (carry == 0)
                {
                    list_return->next = NULL;
                    return list_return;
                }
                else
                {
                    k2 = (TheNode)malloc(sizeof(struct ListNode));
                    k2->val = 1;
                    k2->next = NULL;
                    list_return->next = k2;
                    return list_return;
                }
            }
            k2 = (TheNode)malloc(sizeof(struct ListNode));
            if (j == NULL)
            {
                if (i->val + carry >= 10)
                {
                    k2->val = i->val + carry - 10;
                    k1->next = k2;
                    k1 = k2;
                    k2 = (TheNode)malloc(sizeof(struct ListNode));
                    k2->val = 1;
                    k2->next = NULL;
                    k1->next = k2;
                }
                else
                {
                    k2->val = i->val + carry;
                    k2->next = NULL;
                    k1->next = k2;
                }
            }
            else
            {
                if (i->val + j->val + carry >= 10)
                {
                    k2->val = i->val + j->val +carry - 10;
                    k1->next = k2;
                    k1 = k2;
                    k2 = (TheNode)malloc(sizeof(struct ListNode));
                    k2->val = 1;
                    k2->next = NULL;
                    k1->next = k2;
                }
                else
                {
                    k2->val = i->val + j->val + carry;
                    k2->next = NULL;
                    k1->next = k2;
                }
            }
            return list_return;
        }
        else
            return addTwoNumbers(l2, l1);
    }
}
