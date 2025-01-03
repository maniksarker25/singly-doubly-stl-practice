#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


void insert_at_tail(Node *&head, Node *&tail, int val)
{

    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void checkPalindrome(Node*head,Node*tail){
    if(head == tail){
        cout << "YES";
        return;
    }
    int isPalindrome = 1;
    for (Node *i = head, *j = tail; i != j && i->prev != j; i = i->next, j = j->prev){
            if(i->val != j->val){
                isPalindrome = 0;
            }
    }
    if(isPalindrome == 1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (1)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    checkPalindrome(head,tail);

    return 0; 
}