#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

// 类模板使用
using namespace std;
template <class T>
class Stack
{
  private:
    vector<T> elems;
  public:
    // const: 只读
    // &: 引用
    // 函数申明时，只有类型也可以，实现时自己加上变量名
    void push(T const &);
    void pop();
    // top() const: 表示在 top() 函数内部，不能直接或间接修改 成员变量
    T top() const;
    bool empty() const
    {
        return elems.empty();
    }
};

template <class T>
void Stack<T>::push(T const &elem)
{
    this->elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::pop(): empty stack.");
    }
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::top(): empty stack.");
    }
    return elems.back();
}

int main(int argc, char const *argv[])
{
    try
    {
        Stack<int> intStack;
        Stack<string> stringStack;

        intStack.push(32);
        cout << intStack.top() << endl;

        stringStack.push("asfasf");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const &ex)
    {
        cerr << "Exception: " << ex.what() << endl;
        return -1;
    }

    return 0;
}
