/*============================================================================
* Author        : vitah
* Mail          : linw1225@163.com
* Created       : 2017-05-23 10:40
* Last modified : 2017-05-23 10:40
* Filename      : stack_1.cpp
* Description   : 数组实现栈功能
=============================================================================*/

#include<iostream>
using namespace std;

template <class T>
class Stack {
  private:
    T * stack_array;	// 栈空间指针
    int capacity;	// 栈的容量
    int top_index;	// 栈顶
  public:
    Stack(int size = 10);
    ~Stack();

    bool isFull();
    bool push(T elem);
    T pop();
    void printStack();

};

// 构造函数，初始化栈数组的大小
template <class T>
Stack::Stack(int size) {
    capacity = size;
    stack_array = new T[size];
    top_index = 0;
}

// 析构函数，释放数组空间
template <class T>
Stack::~Stack() {
    delete [] stack_array;
}

// 判断栈是否已经满
template <class T>
boo Stack::isFull() {
    return capacity == top_index ? true : false;
}

// 元素入栈
template <class T>
bool Stack::push(T elem) {
    if(isFull()) {
        return false;
    }

    stack_array[top_index++] = elem;
    return true;
}

// 元素出栈
template <class T>
T Stack::pop() {
    if(top_index <= 0) {
        return NULL;
    }

    T elem = stack_array[top_index--];
    return elem;
}

// 打印栈内容
template <class T>
void Stack::printStack() {
    int stack_size = top_index;

    cout << "栈顶 ————> 栈底" << endl;
    for(int i = stack_size; i >= 0; i--) {
        cout << stack_array[i] << " ";
    }
}


int main() {
    return 0;
}
