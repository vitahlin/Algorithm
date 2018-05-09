/*============================================================================
* Created       : 2017-05-23 10:40
* Last modified : 2017-05-23 10:40
* Filename      : stack_1.cpp
* Description   : C++数组实现栈模版
=============================================================================*/

#include<iostream>
using namespace std;

#define DEFAULT_STACK_SIZE 10

template <class T>
class Stack {
  private:
    T * stack_array;	// 栈空间指针
    int capacity;	// 栈的容量
    int top_index;	// 栈顶
  public:
    Stack(int size = DEFAULT_STACK_SIZE);
    ~Stack();

    bool isFull();
    bool isEmpty();
    bool push(T elem);
    bool pop();
    T getTop();
    void printStack();

};

// 构造函数，初始化栈数组的大小
template <class T>
Stack<T>::Stack(int size) {
    capacity = size;
    stack_array = new T[size];
    top_index = 0;
    cout << "栈初始化,大小为" << size << endl << endl;
}

// 析构函数，释放数组空间
template <class T>
Stack<T>::~Stack() {
    delete [] stack_array;
}

// 判断栈是否已经满
template <class T>
bool Stack<T>::isFull() {
    return capacity == top_index ? true : false;
}

// 判断栈是否为空
template <class T>
bool Stack<T>::isEmpty() {
    return top_index == 0 ? true : false;
}

// 元素入栈
template <class T>
bool Stack<T>::push(T elem) {
    if(isFull()) {
        return false;
    }

    stack_array[top_index] = elem;
    top_index++;
    cout << "入栈:" << elem << endl;
    return true;
}

// 元素出栈
template <class T>
bool Stack<T>::pop() {
    if(top_index <= 0) {
        return false;
    }

    top_index--;
    cout << "执行出栈" << endl;
    return true;
}

// 获取栈顶元素
template <class T>
T Stack<T>::getTop() {
    if(!isEmpty()) {
        return stack_array[top_index - 1];
    } else {
        return 0;
    }
}

// 打印栈内容
template <class T>
void Stack<T>::printStack() {
    cout << endl << "栈顶 ————> 栈底" << endl << "[ ";
    for(int i = top_index - 1; i >= 0; i--) {
        cout << stack_array[i] << " ";
    }

    cout << "]" << endl << endl;
}


int main() {
    Stack<int> *my_stack = new Stack<int>();
    my_stack->push(4);
    my_stack->push(5);
    my_stack->printStack();

    my_stack->pop();
    my_stack->printStack();

    delete my_stack;
    return 0;
}
