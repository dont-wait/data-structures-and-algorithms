

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
int insertAtHead(SList &sl, Node* p);
int insertAtLast(SList& sl, Node* p);
int insertAtAfter(SList& sl, Node* q, Node* p); //chen con tro p sau q
Node* findNodeHaveValueX(SList sl, int x);
int deleteAtHead(SList &sl, int &x);
int deleteAtLast(SList &sl, int &x);
int deleteAtAfter(SList &sl, Node* q, int &x);
int isEmpty(SList sl);

int main()
{
    SList sl;
    int choice;
    Node* p, q;
    int x;  //lưu lại thông tin data đã xoá để dễ quản lí sau này
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
            int x; cout << "Input x: "; cin >> x;
            p = createSNode(x);
            cout << "Successful\n";
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
int deleteAtAfter(SList& sl, Node* q, int& x) {
    if (q != NULL || q->next != NULL)
        return 0;
    Node* p = q->next;  //p gác q 1 nước
    q->next = p->next;
    if (sl.lastNode == p)
        sl.lastNode = q;    //đổi thằng cuối 1 bước
    x = p->value;
    delete p;
    return 1;
}
int deleteAtLast(SList& sl, int& x) {
    if (isEmpty(sl))
        return 0;
    Node* p = sl.lastNode;
    Node* q = sl.headNode;
    if (p == q)
        return NULL;
    else {
        while (q->next != p)
            q = q->next;
        sl.lastNode = q;
        sl.lastNode->next = NULL;
    }
    x = p->value;
    delete p;
    return 1;
}

int deleteAtHead(SList& sl, int &x) {
    if (isEmpty(sl))
        return 0; //nothing to delete
    Node* p = sl.headNode;      //tao sẽ lưu data của m,                        
    x = p->value;              //để tí nx tao gửi nó cho x
    sl.headNode = sl.headNode->next;
    if (sl.headNode == NULL)    
        sl.lastNode = NULL;
    delete p;   //phải cần con trỏ tạm để lấy value, gửi gấm value đó cho x
    return 1;   //thực hiện xong giao kèo rồi thì mình quit
}

Node* findNodeHaveValueX(SList sl, int x) {
    if (isEmpty(sl))
        return; //Nothing to find
    Node* p = sl.headNode;
    while (p != NULL) {
        if(p->value == x)
            return p;
        p = p->next;
    }
    return NULL; //The linked list dont have Node(int x)
    //return ;
}

int insertAtAfter(SList& sl, Node* q, Node* p) {
    if (p == NULL || q == NULL)
        return 0;
        p->next = q->next;
        q->next = p;
    if (sl.lastNode == q)
        sl.lastNode = p;
    return 1;
}

int isEmpty(SList sl) {
    return sl.headNode == NULL;
}
int insertAtLast(SList& sl, Node* p) {
   
    if (p == NULL)
        return 0;
    if (isEmpty(sl))
        insertAtHead(sl, p);
    else {
        sl.lastNode->next = p;
        sl.lastNode = p;
    }
    return 1;
}

int insertAtHead(SList& sl, Node* p) {
    if (p == NULL)
        return 0;
    if (isEmpty(sl)) {
        sl.headNode = p;
        sl.lastNode = p;
    }
    else {
        p->next = sl.headNode;
        sl.headNode = p;
    }
    return 1;  
}
int insertAtLast(SList& sl, Node* p) {

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


