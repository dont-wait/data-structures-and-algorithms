public class Main {

    public static void main(String[] args) {

//        MyArrayStack myStack = new MyArrayStack(3);
//
//        myStack.push(1);
//        myStack.push(2);
//        myStack.push(5);
//        myStack.push(4);
//        myStack.show();
//
//        myStack.pop();
//        myStack.show();
//        myStack.pop();
//        myStack.show();
//        myStack.pop();
//        myStack.show();

        MyLinkedListStack StackList = new MyLinkedListStack();  //FILO  //LIFO
        StackList.push(0);                                //First-In-Last-Out
        StackList.push(5);                                //Last-In-First-Out
        StackList.push(10);
        StackList.push(15);
        StackList.show();

        StackList.pop();
        StackList.show();

        StackList.pop();
        StackList.show();

        StackList.pop();
        StackList.show();

        StackList.pop();
        StackList.show();

    }
}