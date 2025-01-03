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

void print_left_to_right(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

void print_right_to_left(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
}

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

void insert_at_any_post(Node *head, int idx, int val)
{

    Node *newNode = new Node(val);

    Node *temp = head;
    for (int i = 1; i < idx; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
int count_linked_list(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int q;
    cin >> q;
    while(q--){
        int x,v;
        cin >> x >> v;
        int totalNode = count_linked_list(head);
        if(x < 0 || x > totalNode){
            cout << "Invalid" << endl;
        }
        else if(x == totalNode){
            insert_at_tail(head,tail,v);
            cout << "L -> ";
            print_left_to_right(head);
            cout << endl;
            cout << "R -> ";
            print_right_to_left(tail);
            cout << endl;
        }
        else if(x == 0){
            insert_at_head(head,tail,v);
            cout << "L -> ";
            print_left_to_right(head);
            cout << endl;
            cout << "R -> ";
            print_right_to_left(tail);
            cout << endl;
        }
        else{
            insert_at_any_post(head,x,v);
            cout << "L -> ";
            print_left_to_right(head);
            cout << endl;
            cout << "R -> ";
            print_right_to_left(tail);
            cout << endl;
        }

    }

    return 0;
}