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


int main() {
    return 0;
}
