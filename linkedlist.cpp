#include<bits/stdc++.h>
using namespace std;
class ListNode{
private:
    int val;
    ListNode *next;
public:
    ListNode *createLL(ListNode *head, int limit){
        if(limit == 0) return NULL;
        ListNode *newNode = NULL , *temp = NULL;
        int data;
        cout<<"Enter the elements in the linked list"<<endl;
        cin>>data;
        head = new ListNode;
        head->val = data;
        head->next = NULL;
        temp = head;
        for(int i = 2; i <= limit; ++i){
            newNode = new ListNode;
            cin>>data;
            newNode->val = data;
            newNode->next = NULL;
            temp->next = newNode;
            temp = temp->next;
        }
        return head;
    }
    void reverseLL(ListNode **head){
        ListNode *newNode = NULL, *curr = (*head), *prev = NULL;
        while(curr){
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        (*head) = prev;
    }
    void printLL(ListNode *head){
        ListNode *temp = head;
        if(!temp) return;
        else{
            while(temp){
                cout<<temp->val<<" ";
                temp = temp->next;
            }
        }
    }
    ListNode *insertAtTop(ListNode *head, int key){
        ListNode *newNode = new ListNode;
        newNode->val = key;
        newNode->next = head;
        head = newNode;
        return head;
    }
    ListNode *insertAtLast(ListNode *head, int key){
        ListNode *temp = head;
        ListNode *newNode = new ListNode;
        while(temp->next){
            temp = temp->next;
        }
        newNode->val = key;
        temp->next = newNode;
        newNode->next = NULL;
        return head;
    }
    ListNode *atGivenIndex(ListNode *head, int index, int key){
        if(index == 0){
            head = head->insertAtTop(head, key);
            return head;
        }
        ListNode *temp = head;
        ListNode *newNode = new ListNode;
        int n = 0;
        while(n != index - 1){
            temp = temp->next;
            n++;
        }
        newNode->val = key;
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }
    ListNode *deleteAtTop(ListNode *head){
        ListNode *temp = head;
        head = head->next;
        free(temp);
        return head;
        
    }
    ListNode *deleteAtLast(ListNode *head){
        ListNode *temp = head->next;
        ListNode *newNode = head;
        while(temp->next){
            temp = temp->next;
            newNode = newNode->next;
        }
        newNode->next = NULL;
        free(temp);
        return head;
    }
    ListNode *deleteAtIndex(ListNode *head, int index){
        ListNode *temp = head;
        int p = 0;
        while(p != index - 1){
            temp = temp->next;
            p++;
        }
        ListNode *newNode = temp->next;
        temp->next = newNode->next;
        free(newNode);
        return head;
    }
    ListNode *findmid(ListNode *head){
        if(head == NULL) return NULL;
        ListNode *walker = head, *runner = head->next;
        while(runner && runner->next){
            walker = walker->next;
            runner = runner->next->next;
        }
        return walker;
    }
};
int main(){
    ListNode *head = NULL;
    head = head->createLL(head, 5);
    // head->reverseLL(&head);
    // head = head->insertAtTop(head, 9);
    // head = head->insertAtLast(head, 10);
    // head = head->atGivenIndex(head, 1, 37);
    // head = head->deleteAtTop(head);
    head = head->deleteAtLast(head);
    // head = head->deleteAtIndex(head, 2);
    head->printLL(head);
    return 0;
}
