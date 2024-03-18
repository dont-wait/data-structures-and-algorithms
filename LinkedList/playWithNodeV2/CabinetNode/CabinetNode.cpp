// CabinetNode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
};
struct SList {
    Node* headNode;
    Node* lastNode;
};
void initSList(SList& sl);
void printMenu();
Node* createSNode(int x);
void showSList(SList sl);
int main()
{
    SList sl;
    int choice;
    do {
        printMenu();
        printf("Please choose 0...7: ");
        cin >> choice;
        switch (choice)
        {
        case 1:
            initSList(sl);
            cout << "init List completely";
            break;
        case 2:
            break;
        case 3:
            cout << "The value of Integer Link-List has:\n";
            showSList(sl);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 0:
            cout << "See you next time!";
            break;
        default:
            cout << "Error! Are you choose 0..7?\n";
            break;
        }
    } while (choice != 0);
      
}
void showSList(SList sl) {
    if (sl.headNode == NULL)
        return;
    Node* p = sl.headNode;
    while (p != NULL) {
        cout << p->value;
        
        //in màu mè
        if (p->next != NULL)
            cout << "->";
        else
            cout << "\n";

        p = p->next;
    }
}

Node* createSNode(int x) {
    Node* p = new Node();
    if (p == NULL) {
        cout << "Not enough memory allocated\n";
        return;
    }
    p->value = x;
    p->next = NULL;
    return p;
}

void initSList(SList& sl) {
    sl.headNode = NULL;
    sl.lastNode = NULL;

}

void printMenu() {
    printf("\nWelcome you to Node craftman\n");
    printf("1.Create a Link List\n");   //khởi tạo link list
    printf("2.Add New Node\n");
    printf("3.Print Link List\n");
    printf("4.Inseft at head\n");
    printf("5.Inseft at last\n");
    printf("6.Inseft at after\n");
    printf("7.Delete at head\n");
    printf("0.Exit\n");
    
}


