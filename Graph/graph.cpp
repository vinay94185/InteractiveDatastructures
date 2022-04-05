#include<iostream>

using namespace std;

struct node {
    struct edge {
        node* node;
        edge* list;
    };
    int data;
    node* next;
    edge* list;
};

void print_list(node* head) {
    node::edge* edge = head -> list;
    cout << "List of : " << head -> data << " :: ";
    while(edge) {
        cout << edge -> node -> data << " -> ";
        edge = edge -> list;
    }
    cout  << "NULL" << endl;
}

int main() {
    node* head = new node; // 1 
    head -> next = new node; // 2 
    head -> next -> next  = new node; // 3
    head -> next -> next -> next = new node; // 4
    head -> next -> next -> next -> next = NULL;

    head -> data = 1;
    head -> next -> data = 2;
    head -> next -> next -> data = 3;
    head -> next -> next -> next -> data = 4;

    // node 1
    head -> list = new node::edge;
    head -> list -> node = head -> next;
    head -> list -> list = new node::edge;
    head -> list -> list -> node = head -> next -> next -> next;
    head -> list -> list -> list = new node::edge;
    head -> list -> list -> list -> node = head -> next -> next;
    head -> list -> list -> list -> list = NULL;

    //node 2
    head -> next -> list = new node::edge;
    head -> next -> list -> node = head -> next -> next -> next;
    head -> next -> list -> list = NULL;

    //node 3
    head -> next -> next -> list = new node::edge;
    head -> next -> next -> list -> node = head -> next -> next -> next;
    head -> next -> next -> list -> list = NULL;
    
    //node 4
    head -> next -> next -> next -> list = NULL;

    //printing nodes 
    print_list(head); // 1
    print_list(head -> next); // 2
    print_list(head -> next -> next); // 3
    print_list(head -> next -> next -> next); // 4

    cin.clear();
    cin.sync();
    cin.ignore();
    return 0;
}