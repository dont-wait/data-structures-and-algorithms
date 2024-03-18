#include <stdio.h>;
#include <iostream>
using namespace std;
struct Node
{
	int value;
	Node* next;
};
struct MyLinkedList {
	Node* headNode;
	Node* lastNode;
};

Node* newNode(int x);	//tại mới 1 node
void showNode(Node* x);	//in ra value node
void initSNList(MyLinkedList &sl);	//khởi tạo danh sách liên kết(quản lí đầu và cuối)
int isEmpty(MyLinkedList sl);		//Kiểm tra xem dslk có rỗng hay không
void printLinkedList(MyLinkedList sl);
int insertAtHead(MyLinkedList& sl, Node* p);
int insertAtLast(MyLinkedList& sl, Node* p);
int insertAtAfter(MyLinkedList& sl, Node* q, Node* p);	//chèn p sau q
int deleteAtHead(MyLinkedList& sl);
int deleteAtLast(MyLinkedList& sl);
void printMenu();
void main() {
	int choice;
	do {
		printMenu();
		cout << "Vui lòng chọn 0...7: "; cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "See you next time<3\n";
			break;
		case 1:
			MyLinkedList sl;
			initLinkedList();
			break;
		case 2:

			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;

		default:
			cout << "KHÔNG HỢP LỆ! VUI LÒNG CHỌN TỪ 0...7\n";
			break;
		}
	} while (choice != 0);
}
void printMenu() {
	cout << "Welcome you to Node Helper\n";
	cout << "Please choose a option you want\n";
	cout << "1.Khởi tạo danh sách liên kết\n";
	cout << "2.Tạo 1 node\n";
	cout << "3.In danh sách liên kết\n";
	cout << "4.Chèn đầu danh sách liên kết\n";
	cout << "5.Chèn cuối danh sách liên kết\n";
	cout << "6.Chèn p sau q danh sách liên kết\n";
	cout << "7.Xoá Node đầu\n";
	cout << "0.Thoát\n";

	cout << "Udataing~~~\n";

}

int deleteAtLast(MyLinkedList& sl) {
	Node* p = new Node();
	Node* q = new Node();

	p = sl.lastNode;
	q = sl.headNode;
		
	while (q->next != p)
		q = q->next;
		sl.lastNode = q;
		sl.lastNode->next = NULL;
	
	
	return 1;
}

int deleteAtHead(MyLinkedList& sl) {
	Node* p = new Node();
	if (isEmpty(sl)) cout << "Nothing to delete";
	p = sl.headNode;
	sl.headNode = sl.headNode->next;
	delete p;
	return 1;
}

int insertAtAfter(MyLinkedList& sl, Node* q, Node* p) {
	if (p == NULL || q == NULL)
		return 0;
	p->next = q->next;
	q->next = p;
	if (sl.lastNode = q)
		sl.lastNode = p;
	return 1;
}

int insertAtLast(MyLinkedList& sl, Node* p) {
	if (p == NULL)
		return 0;
	if (isEmpty(sl)) {
		insertAtHead(sl, p);
		return 1;
	}
	sl.lastNode->next = p;
	sl.lastNode = p;
	//p = sl.lastNode;

	return 1;
}

int insertAtHead(MyLinkedList& sl, Node* p) {
	if (p == NULL)
		return 0;
	if(isEmpty(sl)) {
		sl.headNode = p;
		sl.lastNode = p;
	}
	else {
		p->next = sl.headNode;
		sl.headNode = p;
	}
	return 1;
}

void printLinkedList(MyLinkedList sl) {
	if (isEmpty(sl)) {
		cout << "DSLK rỗng";
		return;
	}
	Node* p = new Node;
	p = sl.headNode;	//anh nhân viên dọn vệ sinh may mắn
	while (p != NULL) {
		showNode(p);
		if (p->next != NULL)
			cout << "->";
		else
			cout << "\n";
		p = p->next;
	}


}

int isEmpty(MyLinkedList sl) {
	return sl.headNode == NULL;
}

void initSNList(MyLinkedList &sl) {
	sl.headNode = NULL;
	sl.lastNode = NULL;
}

void showNode(Node* x) {
	
	cout << x->value;
}

Node* newNode(int x) {
	Node* newNode = new Node;
	if (newNode == NULL) {
		cout << "Không đủ bộ nhớ cấp phát";
		return NULL;
	}
	newNode->value = x;
	newNode->next = NULL;
	return newNode;
}

void initLinkedList() {

}
