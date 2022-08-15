/*
641. 设计循环双端队列
设计实现双端队列。

实现 MyCircularDeque 类:

MyCircularDeque(int k) ：构造函数,双端队列最大为 k 。
boolean insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true ，否则返回 false 。
boolean insertLast() ：将一个元素添加到双端队列尾部。如果操作成功返回 true ，否则返回 false 。
boolean deleteFront() ：从双端队列头部删除一个元素。 如果操作成功返回 true ，否则返回 false 。
boolean deleteLast() ：从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 false 。
int getFront() )：从双端队列头部获得一个元素。如果双端队列为空，返回 -1 。
int getRear() ：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1 。
boolean isEmpty() ：若双端队列为空，则返回 true ，否则返回 false  。
boolean isFull() ：若双端队列满了，则返回 true ，否则返回 false 。
 

示例 1：

输入
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
输出
[null, true, true, true, false, 2, true, true, true, 4]

解释
MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
circularDeque.insertLast(1);			        // 返回 true
circularDeque.insertLast(2);			        // 返回 true
circularDeque.insertFront(3);			        // 返回 true
circularDeque.insertFront(4);			        // 已经满了，返回 false
circularDeque.getRear();  				// 返回 2
circularDeque.isFull();				        // 返回 true
circularDeque.deleteLast();			        // 返回 true
circularDeque.insertFront(4);			        // 返回 true
circularDeque.getFront();				// 返回 4
*/
class MyCircularDeque {
    struct Q_node {
        int val;
        Q_node* next;
        Q_node* last;
    };
    Q_node* front;
    Q_node* back;
    int Q_size;
    int size_now;
public:
    MyCircularDeque(int k) {
        front = nullptr;
        back = nullptr;
        Q_size = k;
        size_now = 0;
    }

    bool insertFront(int value) {
        if (size_now == 0) {
            size_now++;
            front = new(Q_node);
            front->last = nullptr;
            front->next = nullptr;
            front->val = value;
            back = front;
            return true;
        }
        else if (size_now < Q_size) {
            size_now++;
            Q_node* temp = new(Q_node);
            temp->val = value;
            temp->last = nullptr;
            temp->next = front;
            front->last = temp;
            front = temp;
            return true;
        }
        else 
            return false;
    }

    bool insertLast(int value) {
        if (size_now == 0) {
            size_now++;
            front = new(Q_node);
            front->last = nullptr;
            front->next = nullptr;
            front->val = value;
            back = front;
            return true;
        }
        else if (size_now < Q_size) {
            size_now++;
            Q_node* temp = new(Q_node);
            temp->val = value;
            temp->next = nullptr;
            temp->last = back;
            back->next = temp;
            back = temp;
            return true;
        }
        else 
            return false;
    }

    bool deleteFront() {
        if (size_now == 0)
            return false;
        else {
            if (size_now == 1) {
                size_now--;
                delete(front);
                back = front = nullptr;
                return true;
            }
            size_now--;
            Q_node* temp = front;
            front = front->next;
            delete(temp);
            return true;
        }
    }

    bool deleteLast() {
        if (size_now == 0)
            return false;
        else {
            if (size_now == 1) {
                size_now--;
                delete(back);
                back = front = nullptr;
                return true;
            }
            size_now--;
            Q_node* temp = back;
            back = back->last;
            delete(temp);
            return true;
        }
    }

    int getFront() {
        if (front == nullptr)
            return -1;
        else
            return front->val;
    }

    int getRear() {
        if (back == nullptr)
            return -1;
        else
            return back->val;
    }

    bool isEmpty() {
        if (size_now == 0)
            return true;
        else
            return false;
    }

    bool isFull() {
        if (size_now == Q_size)
            return true;
        else
            return false;
    }
};
