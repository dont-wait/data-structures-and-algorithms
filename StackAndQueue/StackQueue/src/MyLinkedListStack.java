public class MyLinkedListStack implements IStackAndQueue{
    private static class Node {
        int value;
        Node next;
        Node(int value) {
            this.value = value;
        }
    }
    Node topNode;
    MyLinkedListStack() {
        topNode = null;
    }
    @Override
    public boolean push(int value) {
        if(!isFull()) {
            //thêm 1 phần tử vào đầu của linked list
            Node newNode = new Node(value);
            newNode.next = topNode;
            topNode = newNode;
            return true;
        }
        return false;
    }

    @Override
    public int pop() {
        if(isEmpty())
            return -1;
        int value = topNode.value;
        topNode = topNode.next;
        return value;   //lưu lại giá trị node đã xoá để khi cần còn re-use
                        //khi lưu danh sách sinh viên, chợt có người nghĩ
                        //ta xoá sv đó, nhưng
                        //vào cuối năm cần thống kê lại sinh viên năm trước từng vào
                        //-> đếm luôn dữ liệu sinh viên đã remove
    }

    @Override
    public boolean isFull() {
        return false;
    }

    @Override
    public boolean isEmpty() {
        return topNode == null;
    }

    @Override
    public void show() {
        if(isEmpty()) {
            System.out.println("Stack List is empty");
            return;
        }
        Node temp = topNode;
        while(temp != null) {
            System.out.print(temp.value);
            temp = temp.next;

            if(temp == null)
                System.out.println();
            else
                System.out.print("->");
        }
    }
}
