/*Nguyen Tan Sang 14DHTH11
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#pragma warning (disable: 4996)
struct SNode {
    int value;
    SNode* next;
};
struct SList {
    SNode* headNode;
    SNode* lastNode;
};
void initSList(SList& sl);
SNode* createSNode(int x);
void showSNode(SNode* p);
int insertAtHead(SList& sl, SNode* p);
int isEmpty(SList sl);
void printSList(SList sl);
void createSList(SList& sl);
void inputValueByHand(SList& sl, int n);
void createSListRandom(SList& sl);
void printMenu();
void process();
int insertAtTail(SList& sl, SNode* p);  //cau a
int insertXValueAfterYValueOnList(SList& sl, int x, int y);   //cau b
void swap(int& x, int& y);
void sortByAccendingValue(SList& sl);
void sortByDecreasingValue(SList& sl);
int isPrime(int x);
int countPrimeNode(SList sl);
int isSquareNumber(int x);
int getSumOfSquareNumber(SList sl);
int getMinOfLinkedList(SList sl);
int getMaxOfLinkedList(SList sl);
int getTotalValueGreaterX2(SList sl);
void playWithEvenOddLinkedList(SList sl, SList& sl1, SList& sl2);
int checkOdd(int x);
int checkEven(int x);
int main() {
    process();
    getch();
    return 0;
}
int checkOdd(int x) {
    return x % 2 != 0;

}
int checkEven(int x) {
    return x % 2 == 0;
}
void playWithEvenOddLinkedList(SList sl, SList& sl1, SList& sl2) {
    if (isEmpty(sl)) {
        return;
    }
    else {
        SNode* p = sl.headNode;
        while (p != NULL) {
            if (checkEven(p->value))
                insertAtTail(sl1, p);

            else if (checkOdd(p->value))
                insertAtTail(sl2, p);
            p = p->next;
        }
    }
    printf("\nThe Even Linked List: ");
    printSList(sl1);
    printf("\nThe Odd Linked List: ");
    printSList(sl2);

}
int getTotalValueGreaterX2(SList sl) {
    int count = 0;
    SNode* p = sl.headNode;
    SNode* q = p->next;
    while (p != NULL && q != NULL) {
        if (p->value == (q->value * 2))
            count++;
        p = p->next;
        q = q->next;
    }
    return count;
}

int getMaxOfLinkedList(SList sl) {
    if (isEmpty(sl)) {
        printf("Linked List is empty");
        return -1;
    }
    else {
        SNode* p = sl.headNode;
        int max = p->value;
        while (p != NULL) {
            if (max < p->value)
                max = p->value;
            p = p->next;
        }
        return max;
    }
}
int getMinOfLinkedList(SList sl) {
    if (isEmpty(sl)) {
        printf("Linked List is empty");
        return -1;
    }
    else {
        SNode* p = sl.headNode;
        int min = p->value;
        while (p != NULL) {
            if (min > p->value)
                min = p->value;
            p = p->next;
        }
        return min;
    }
}
int getSumOfSquareNumber(SList sl) {
    int sum = 0;
    if (isEmpty(sl))
        return sum;   //ko có node nào thì cx như kh có số nguyên tố nào!
    else {
        SNode* p = sl.headNode;
        while (p != NULL) {
            if (isSquareNumber(p->value))
                sum += p->value;
            p = p->next;
        }
    }
    return sum;
}
int isSquareNumber(int x) {
    return sqrt(x) * sqrt(x) == x;
}
int countPrimeNode(SList sl) {
    int count = 0;
    if (isEmpty(sl))
        return count;   //ko có node nào thì cx như kh có số nguyên tố nào!
    else {
        SNode* p = sl.headNode;
        while (p != NULL) {
            if (isPrime(p->value))
                count++;
            p = p->next;
        }
    }
    return count;
}
int isPrime(int x) {
    if (x < 2)
        return 0;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return 0;
    return 1;
}
void sortByDecreasingValue(SList& sl) {
    if (isEmpty(sl))
        return;
    else
        for (SNode* p = sl.headNode; p != NULL; p = p->next)
            for (SNode* q = p->next; q != NULL; q = q->next)
                if (p->value < q->value)
                    swap(p->value, q->value);
    printf("Sorting completed!\n");
}

void sortByAccendingValue(SList& sl) {
    //muốn đổi chổ 2 node, thật chất là đổi chỗ 2 value của 2 node
    //->data
    //vậy làm sao để so
    if (isEmpty(sl))
        return;
    else
        for (SNode* p = sl.headNode; p != NULL; p = p->next)
            for (SNode* q = p->next; q != NULL; q = q->next)
                if (p->value > q->value)
                    swap(p->value, q->value);
    printf("Sorting completed!\n");
}
void swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}
void process() {
    int choice;
    SList sl;
    initSList(sl);

    do {
        printMenu();
        printf("Choose 0...14: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            int x;
            SNode* p;
            printf("Nhap x: ");
            scanf("%d", &x);
            p = createSNode(x);
            printf("Node vua nhap la: ");
            showSNode(p);
            break;
        case 2:
            printSList(sl);
            break;
        case 3:
            createSList(sl);
            break;
        case 4:
            createSListRandom(sl);
            break;
        case 5:
            int y;
            printf("Nhap y: ");
            scanf("%d", &y);
            SNode* p1;
            p1 = createSNode(y);
            insertAtTail(sl, p1);
            printf("Insert Successfull!, Please choose 2 to print Linked List\n");
            break;
        case 6:
            insertXValueAfterYValueOnList(sl, 5, 6);
            printSList(sl);
            break;
        case 7:
            sortByAccendingValue(sl);
            break;
        case 8:
            sortByDecreasingValue(sl);
            break;
        case 9:
            printf("The Linked list has %d prime number\n", countPrimeNode(sl));
            break;
        case 10:
            printf("The sum of Square node in Linked List: %d", getSumOfSquareNumber(sl));
            break;
        case 11:
            printf("Min of Linked List: %d", getMinOfLinkedList(sl));
            break;
        case 12:
            printf("Max of Linked List: %d", getMaxOfLinkedList(sl));
            break;
        case 13:
            printf("The Linked List has %d value greater x2 than value before", getTotalValueGreaterX2(sl));
        case 14:
            SList sl1, sl2;
            initSList(sl1);
            initSList(sl2);
            playWithEvenOddLinkedList(sl, sl1, sl2);
            break;
        case 0:
            printf("Bye bye, see you next time\n");
            break;
        default:
            printf("Please choose 0...4!!!\n");
            break;
        }
    } while (choice != 0);
}
//muốn chèn giá trị y vào sau x. Trước hết ta phải tạo node chứa giá trị x
//                               sau đó ta đưa giá trị y giả định có thể nằm bất kỳ trong các node trong DSLK
//                               
//vậy thì, trước hết ta khởi tạo Node chứa value x 
//sau đó ta so dò trong ds này, có p->value nào == y hay không
//thấy được rồi, yes sir, Insert time!!!
//TH1: Không có giá trị y tồn tại -> không tồn tại Node chứa value y
//TH2: Có y rồi thì chèn thôi

int insertXValueAfterYValueOnList(SList& sl, int x, int y) {
    if (isEmpty(sl)) {
        return 0;
    }
    else {
        SNode* pX = createSNode(x);
        SNode* pY = sl.headNode; //con trỏ p dùng để kiểm có value nào bằng y hay không

        while (pY->next != NULL) { //&& pY->next->data != y) {
            pY = pY->next;
        }
        if (pY->next != NULL)
            pX->next = pY->next;
        pY->next = pX;
    }
    return 1;
}
int insertAtTail(SList& sl, SNode* p) {
    if (p == NULL)
        return 0;
    if (isEmpty(sl)) {
        sl.headNode = p;
        sl.lastNode = p;
    }
    else {
        sl.lastNode->next = p;
        sl.lastNode = p;
    }
    return 1;
}

void renewLinkedList(SList& sl) {
    sl.headNode->next = NULL;
    sl.lastNode = NULL;
}
void printMenu() {
    printf("\n======================================");
    printf("\nWelcome you to Node Helper\n");
    printf("1.Create a Node and print\n");
    printf("2.Print Node list\n");
    printf("3.Create a Integer-Node List\n");
    printf("4.Create a Integer-Node-Random List\n");
    printf("5.Insert number to tail at linked list\n");
    printf("6.Updating\n");
    printf("7.Accending sort\n");
    printf("8.Decreasing sort\n");
    printf("9.Count prime number in Linked list\n");
    printf("10.Compute sum of Square Node\n");
    printf("11.Find min of Linked List\n");
    printf("12.Find max of Linked List\n");
    printf("13.Total value greater than value before\n");
    printf("14.Càng đông càng vui\n");
}
void createSListRandom(SList& sl) {
    int n;
    int x;
    initSList(sl);

    do {
        printf("Nhap so luong phan tu DSLK: ");
        scanf("%d", &n);
    } while (n <= 0);
    srand((unsigned)time(NULL));
    for (int i = 1; i <= n; i++)
    {
        x = (rand() % 199) - 99;
        SNode* p = createSNode(x);
        insertAtTail(sl, p);
    }
    printf("Khoi tao thanh cong, vui long chon 2 de in\n");
}

void createSList(SList& sl) {
    int n;
    do {
        printf("Nhap so luong phan tu DSLK: ");
        scanf("%d", &n);
    } while (n <= 0);
    inputValueByHand(sl, n);
    printf("Khoi tao thanh cong, vui long chon 2 de in\n");
}
void inputValueByHand(SList& sl, int n) {
    int x;
    for (int i = 1; i <= n; i++)
    {
        printf("Nhap Node thu %d: ", i);
        scanf("%d", &x);
        SNode* p = createSNode(x);
        insertAtTail(sl, p);
    }
}

void printSList(SList sl) {
    if (isEmpty(sl)) {
        printf("Linked List is Empty\n");
        return;
    }
    SNode* p = sl.headNode;    //muon
    while (p != NULL) {
        showSNode(p);
        //in ma`u me`
        if (p->next != NULL)
            printf("->");
        else
            printf("\n");
        p = p->next;
    }

    //renewLinkedList(sl);//mỗi lần in xong, thì phải dọn đống xà bần, tránh để lại cho hàm sau dùng
    //phải ăn đóng còn thừa

}

int insertAtHead(SList& sl, SNode* p) {
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
int isEmpty(SList sl) {
    return sl.headNode == NULL;
}

void showSNode(SNode* p) {
    printf("%d", p->value);

}

SNode* createSNode(int x) {
    SNode* p = new SNode;
    if (p == NULL) {
        printf("Miss data");    //het bo nho cap phat
        getch();
        return NULL;
    }
    p->value = x;
    p->next = NULL;
    return p;
}

void initSList(SList& sl) {
    SNode* headNode = NULL;
    SNode* lastNode = NULL;
}