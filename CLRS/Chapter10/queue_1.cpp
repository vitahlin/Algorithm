/*============================================================================
* Author        : vitah
* Mail          : linw1225@163.com
* Created       : 2017-05-25 16:24
* Last modified : 2017-05-25 16:24
* Filename      : queue_1.cpp
* Description   : C++链表实现队列模版
=============================================================================*/

#include<iostream>
using namespace std;

template <class T>
class Node {
  public:
    T data;	// 数组内容
    Node<T> *next; // 指向下一个节点的指针
};

template <class T>
class Queue {
  public:
    Queue();
    ~Queue();

    bool enQueue(const T &);	// 入队列
    bool deQueue();	// 出队列
    bool isEmpty();	// 判断队列是否为空
    int getSize();	// 获取队列的大小
    void printQueue();	// 打印队列

  private:
    Node<T> *head;
    Node<T> *tail;
};

// 构造函数，初始化队列节点
template <class T>
Queue<T>::Queue() {
    Node<T> *new_queue = new Node<T>();
    new_queue->next = NULL;
    head = new_queue;
    tail = new_queue;

    cout << "初始化队列" << endl;
}

// 析构函数
template <class T>
Queue<T>::~Queue() {
    int delete_node_count = 0;

    while(head->next != NULL) {
        Node<T> *p = head->next;
        head->next = p->next;
        delete p;
        delete_node_count++;
    }

    if(head == tail) {
        delete head;
    }

    cout << "队列空间释放，共 " << delete_node_count << " 个节点" << endl;
}

// 入队列操作
template <class T>
bool Queue<T>::enQueue(const T &a) {
    Node<T> *p = new Node<T>();
    p->data = a;
    tail->next = p;
    tail = p;
    cout << "入队列 : " << a << endl;
    return true;
}

// 出队列操作
template <class T>
bool Queue<T>::deQueue() {
    if(isEmpty()) {
        return false;
    }

    Node<T> *p = head->next;
    head->next = p->next;
    if(p == tail) {
        head = tail;
    }

    cout << "出队列 : " << p->data << endl;
    delete p;
    return true;
}

// 判断队列是否为空
template <class T>
bool Queue<T>::isEmpty() {
    return head == tail ? true : false;
}

// 获取队列大小
template <class T>
int Queue<T>::getSize() {

    int queue_size = 0;
    if(isEmpty()) {
        return queue_size;
    } else {
        Node<T> *p = new Node<T>();
        p = head->next;
        while(p != NULL) {
            queue_size++;
            p = p->next;
        }

        return queue_size;
    }
}

// 队列内容打印
template <class T>
void Queue<T>::printQueue() {
    Node<T> *p = head->next;
    cout << endl << "队列大小 : " << getSize() << " , " << "队列头 ————> 队列尾:" << endl << "[ ";
    while(p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }

    cout << "]" << endl << endl;
}

int main() {
    Queue<int> *my_queue = new Queue<int>();
    my_queue->printQueue();

    my_queue->enQueue(1);
    my_queue->enQueue(2);
    my_queue->enQueue(3);
    my_queue->enQueue(4);
    my_queue->printQueue();

    my_queue->deQueue();
    my_queue->deQueue();
    my_queue->printQueue();

    delete my_queue;
    return 0;
}
