/*==========================================================
* Created       : 2017-05-25 23:22
* Last modified : 2017-05-25 23:22
* Filename      : queue_2.cpp
* Description   : C++ 数组实现循环队列模版
==========================================================*/


#include<iostream>
using namespace std;

#define DEFAULT_QUEUE_SIZE 5

template <class T>
class Queue {
  private:
  public:
    T * queue_array;	// 队列空间指针
    int front;	// 队列头部
    int rear;	// 队列尾部
    int max_size;	// 队列元素最大数量
    int size; // 当前队列大小
  public:
    Queue(int size = DEFAULT_QUEUE_SIZE);
    ~Queue();

    bool isFull();
    bool isEmpty();
    int getSize ();

    bool enQueue(T elem);
    bool deQueue();

    void printQueue();
};

// 构造函数，初始化队列数组的大小
template <class T>
Queue<T>::Queue(int capacity) {
    queue_array = new T[capacity];
    front = rear = 0;
    max_size = capacity;
    size = 0;
    cout << "队列初始化,大小为" << capacity << endl << endl;
}

// 析构函数，释放数组空间
template <class T>
Queue<T>::~Queue() {
    delete [] queue_array;
}

// 获取当前队列中元素数量
template <class T>
int Queue<T>::getSize() {
    return size;
}

// 元素入队列
template <class T>
bool Queue<T>::enQueue(T elem) {
    if(getSize() == max_size) {
        cout << "队列已满，入队列失败" << endl;
        return false;
    } else {
        queue_array[rear] = elem;

        rear = rear + 1;
        rear = rear % max_size;
        size++;

        cout << "入队列:" << elem << endl;
        return true;
    }
}

// 元素出队列
template <class T>
bool Queue<T>::deQueue() {
    if(getSize() == 0) {
        cout << "队列为空，出队列失败" << endl;
        return false;
    } else {
        T de_value = queue_array[front];
        front = (front + 1) % max_size;
        size--;
        cout << "出队列:" << de_value << endl;
        return true;
    }
}

// 打印队列内容
template <class T>
void Queue<T>::printQueue() {
    cout << endl << "队列头 ————> 队列尾" << endl << "[ ";

    int temp_rear = rear;
    if(rear <= front) {
        temp_rear += max_size;
    }
    for(int i = front; i < temp_rear; i++) {
        cout << queue_array[i % max_size] << " ";
    }

    cout << "]" << endl << endl;
}


int main() {
    Queue<int> *my_queue = new Queue<int>();
    my_queue->enQueue(1);
    my_queue->enQueue(2);
    my_queue->enQueue(3);
    my_queue->enQueue(4);
    my_queue->enQueue(5);
    my_queue->printQueue();

    my_queue->deQueue();
    my_queue->printQueue();

    my_queue->enQueue(6);
    my_queue->printQueue();


    my_queue->deQueue();
    my_queue->printQueue();


    my_queue->deQueue();
    my_queue->printQueue();

    my_queue->enQueue(7);
    my_queue->printQueue();

    my_queue->enQueue(8);
    my_queue->printQueue();

    my_queue->enQueue(9);
    my_queue->printQueue();

    delete my_queue;
    return 0;
}
