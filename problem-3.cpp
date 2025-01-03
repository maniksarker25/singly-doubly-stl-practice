// input doubly linked list
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    string val;
    Node *next;
    Node *prev;
    Node(string val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


void insert_at_tail(Node *&head, Node *&tail, string val)
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

Node* find_node(Node*head,string address){
    Node*temp = head;
    while (temp != NULL)
    {
      if(temp->val == address){
        return temp;
      }
      temp = temp->next;
    }
    return NULL;
    
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    string val;
    while (1)
    {
        cin >> val;
        if (val == "end")
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    int q;
    cin >> q;
    Node *current = head;
    while (q--)
    {
       string command;
       cin >> command;
       if(command == "visit"){
        string address;
        cin >> address;
        Node * node = find_node(head,address);
        if(node !=NULL){
            current = node;
            cout << current->val << endl;
        }
        else{
            cout << "Not Available" << endl;
        }
       }
       else if(command == "next"){
        if(current->next != NULL){
            current = current->next;
            cout << current->val << endl;
        }
        else{
            cout << "Not Available" << endl;
        }
       }
       else if(command == "prev"){
        if(current->prev != NULL){
            current = current->prev;
            cout << current->val << endl;
        }
        else{
            cout << "Not Available" << endl;
        }
       }
    }
    

    return 0;
}