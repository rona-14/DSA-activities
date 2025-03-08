#include <iostream>

using namespace std;

typedef struct Node{
    string songName;
    Node  *link;
}Node;

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;

    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;
    
    cout << "My Playlist" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }
        
        temp = temp->link;
    }
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    
    Node *newNode = createNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;
    
    head = newNode;
    
    cout << "A new node has been inserted at the beginning \n" <<endl;
    
    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;
    
    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such exist, please try again later.";
        }
        
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    return "An new node has been inserted after " + after + "\n";
}

int main(){
    Node *head = createNode("So Big by Iyaz");
    
    head = insertAtEnd("Solo by Iyaz", head);
    head = insertAtEnd("Ok by Iyaz", head);
    head = insertAtEnd("One Less Lonely Girl by Justin Bieber", head);
    
    head = insertAtBeginning("Steel My Girl by One Direction", head);
    head = insertAtBeginning("Grenade by Bruno Mars", head);
    head = insertAtBeginning("Bubbly by Colbie Cailat", head);
    head = insertAtBeginning("Lupaypay by Haring Manggi Meguelito Malakas", head);
    traverse(head);
    
    insertAfter ("Alipin Ako by Liezel Garcia", head);
    insertAfter ("Kung Dina Ako by Agsunta", head);
    insertAfter ("Hindi Na Bale by Bugoy Drillon", head);
    traverse(head);
    
    

    return 0;
}
