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
    Node *head = createNode("Mapa by SB19");
    traverse(head);
    
    head = insertAtEnd("Fine Line by Harry Styles", head);
    traverse(head);
    head = insertAtEnd("Di Mapakali by Pattia", head);
    traverse(head);
    head = insertAtEnd("Secrets by One Republic", head);
    traverse(head);
    
    head = insertAtBeginning("PagMAMAhal by Ex Battalion", head);
    traverse(head);
    head = insertAtBeginning("Sa Bawat Sandali by Amiel Sol", head);
    traverse(head);
    head = insertAtBeginning("Your eyes tell by BTS", head);
    traverse(head);
    head = insertAtBeginning("Kidult by SEVENTEEN", head);
    traverse(head);
    
    insertAfter ("PagMAMAhal by Ex Battalion", "Your Song by Parokya Ni Edgar", head);
    traverse(head);
    insertAfter ("Sa Bawat Sandali by Amiel Sol", "With A Smile by Eraserheads", head);
    traverse(head);
    insertAfter ("Your eyes tell by BTS", "Araw-Araw by Ben&Ben" , head);
    traverse(head);
    
    cout << deleteAtEnd(head);
    traverse(head);
    head = deleteFromBeginning(head);
    traverse(head);
    head = deleteFromGivenNode("Sa Bawat Sandali by Amiel Sol",head);
    traverse(head);

    return 0;
}
