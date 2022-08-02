/*
622. 设计循环队列
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。
 

示例：

MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1);  // 返回 true
circularQueue.enQueue(2);  // 返回 true
circularQueue.enQueue(3);  // 返回 true
circularQueue.enQueue(4);  // 返回 false，队列已满
circularQueue.Rear();  // 返回 3
circularQueue.isFull();  // 返回 true
circularQueue.deQueue();  // 返回 true
circularQueue.enQueue(4);  // 返回 true
circularQueue.Rear();  // 返回 4
*/
class MyCircularQueue {
    struct Q{
        int val;
        Q* next;
    };
    int nums_Q;
    int nums_Q_now;
    Q* first_;
    Q* last_;
public:
    MyCircularQueue(int k) {
        nums_Q = k;
        nums_Q_now = 0;
        Q* temp = nullptr;
        if (nums_Q == 1){
            temp = (Q*)malloc(sizeof(Q));
            temp->val = -1;
            first_ = temp;
            last_ = temp;
            temp->next = temp;
            return;
        }
        for (int i = 0; i < nums_Q; i++){
            if (i == 0){
                temp = (Q*)malloc(sizeof(Q));
                temp->val = -1;
                first_ = temp;
                continue;
            }
            if (i == nums_Q - 1){
                temp->next = (Q*)malloc(sizeof(Q));
                temp = temp->next;
                last_ = temp;
                temp->val = -1;
                temp->next = first_;
                break;
            }
            temp->next = (Q*)malloc(sizeof(Q));
            temp = temp->next;
            temp->val = -1; // -1表示未使用的。
        }
    }
    
    bool enQueue(int value) {
        if (nums_Q_now < nums_Q){
            last_ = last_->next;
            last_->val = value;
            nums_Q_now++;
            return true;
        }
        else
            return false;
    }
    
    bool deQueue() {
        if (nums_Q_now != 0){
            first_->val = -1;
            first_ = first_->next;
            nums_Q_now--;
            return true;
        }
        else
            return false;
    }
    
    int Front() {
        return first_->val; // 空的情况是返回为被初始化的，即-1。
    }
    
    int Rear() {
        return last_->val;
    }
    
    bool isEmpty() {
        if (nums_Q_now == 0)
            return true;
        else 
            return false;
    }
    
    bool isFull() {
        if (nums_Q_now == nums_Q)
            return true;
        else 
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
