#include <stdio.h>
#include <conio.h>
//#pragma warning (disable 4996)
struct stackNode {
	int value;
	stackNode* next;
};
struct stackList {
	stackNode* Top;
};
void initStack(stackList& s) {
	s.Top = NULL;	//new Stack List
}
int isEmpty(stackList s) {
	return s.Top == NULL;
}
int push(stackList& s, stackNode* p) {
	if (p == NULL)
		return 0;
	if (isEmpty(s))
		s.Top = p;
	else {
		p->next = s.Top;
		s.Top = p;
	}
	return 1;
}
int pop(stackList& s, int& x) {
	if (isEmpty(s))
		return 0;	//fail case
	stackNode* p = s.Top; //1
	x = p->value;		  //2
	s.Top = s.Top->next;
	delete p;
	return 1;
}
void show(stackList s) {
	if (isEmpty(s))
		printf("Stack List is empty\n");
	stackNode* p = s.Top;
	while (p != NULL) {
		printf("%d ", p->value);
		p = p->next;
	}

}

stackNode* createStackNode(int x) {
	stackNode* p = new stackNode;
	p->value = x;
	p->next = NULL;
	return p;
}

//CHALLENGE CONVERT TEN TO BINARY
//#1: Cần 1 hàm đầu vào là 1 con số 
//	  hàm đó sẽ chạy vòng lặp
//	  cứ mỗi lần chia | chia hết thì trả về 1, ko thì trả về 0
//	  mỗi lần như vậy output sẽ là đầu vào của hàm CONVERT
//#2: đặt Hàm convert trong vòng lặp ấy luôn, mỗi lần chia thì kết quả đưa vào stack
//#3: Xuất stack
void convertTenToBinary(stackList& s, int x);
void deleteLinkedList(stackList& s);

int main() {
	stackList s;
	initStack(s);

	for (int i = 0; i <= 300; i++) {
		printf("%d = ", i);
		convertTenToBinary(s, i);
		deleteLinkedList(s);
		printf("\n");
	}
	return 0;
}
void deleteLinkedList(stackList& s) {
	while (s.Top != NULL) {
		stackNode* temp = s.Top;
		s.Top = s.Top->next;
		delete temp;
	}
}
void convertTenToBinary(stackList& s, int x) {
	if (x > 255) {
		printf("Out of limit bit");
		return;
	}
	//0 = 00000000
	while (x != 0) {
		if (x % 2 != 0)
			push(s, createStackNode(1));
		else
			push(s, createStackNode(0));
		x /= 2;
	}
	show(s);
}
