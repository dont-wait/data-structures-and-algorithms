//#include<stdio.h>
//#include<conio.h>
//#pragma warning (disable 4996)
//struct queueNode {
//	int value;
//	queueNode* next;
//};
//struct queueList {
//	queueNode* headNode;
//	queueNode* tailNode;
//};
//int isEmpty(queueList qu) {
//	return qu.headNode == NULL;
//}
//void initQueueList(queueList& qu) {
//	qu.headNode = qu.tailNode = NULL;
//}
//queueNode* createQueueNode(int x) {
//	queueNode* p = new queueNode;
//	if (p == NULL)
//		return NULL;
//	p->value = x;
//	p->next = NULL;
//	return p;
//}
//int push(queueList& qu, queueNode* p) {
//	if (p == NULL)
//		return 0;
//	if (isEmpty(qu))
//		qu.headNode = qu.tailNode = p;
//	else {
//		qu.tailNode->next = p;
//		qu.tailNode = p;
//	}
//	return 1;
//}
//int pop(queueList& qu, int& x) {
//	if (isEmpty(qu))
//		printf("Queue list is empty\n");
//	queueNode* p = qu.headNode;	//1
//	qu.headNode = qu.headNode->next;//2
//	if (qu.headNode == NULL)//kiem tra sau khi day node ra co phai la node cuoi hay khong
//		qu.tailNode = NULL;	//neu phai thi cho tailNode di vao di~ vang~ cung` headNode
//	x = p->value;
//	delete p;
//	return 1;
//}
//void show(queueList qu) {
//	if (isEmpty(qu))
//		printf("Queue List is empty\n");
//	queueNode* p = qu.headNode;
//	while (p != NULL) {
//		printf("%d ", p->value);
//		p = p->next;
//	}
//}
//int main() {
//	queueList qu;
//
//	push(qu, createQueueNode(1));
//	push(qu, createQueueNode(2));
//	push(qu, createQueueNode(3));
//	show(qu);
//
//	int x;
//	pop(qu, x);
//	printf("| X dang luu %d\n", x);
//	pop(qu, x);
//	printf("| X dang luu %d\n", x);
//	pop(qu, x);
//	printf("| X dang luu %d\n", x);
//	show(qu);
//	_getch();
//	return 0;
//}