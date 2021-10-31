/**
 * 430. Flatten a Multilevel Doubly Linked List
 * https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* cur = head;
        
        while (cur){
            if (cur->child){
                Node* x = cur->child;
                while(x->next) x = x->next;
                x->next = cur->next;
                if (cur->next) cur->next->prev = x;
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = nullptr;
            }
            cur = cur->next;
        }
        return head;
    }
};