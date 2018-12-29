#include <iostream>
using namespace std;

class Shape
{
  protected:
    int length, width;

  public:
    Shape(int l = 0, int w = 0)
    {
        this->width = w;
        this->length = l;
        cout << "调用构造函数" << endl;
    }

    // 析构函数，对象在内存中删除时调用
    ~Shape()
    {
        cout << "调用析构函数" << endl;
    }

    // 虚函数：动态链接、后期绑定
    virtual int area()
    {
        cout << "Shape Area" << endl;
        return 0;
    }

    // 纯虚函数，表示java中的抽象函数，没有方法体
    // virtual int absMethod() = 0;
};

class Rectangled : public Shape
{
  public:
    Rectangled(int l = 0, int w = 0) : Shape(l, w){};
    int area()
    {
        cout << "Rectangled Area is :";
        return this->width * this->length;
    }
};

class Triangle : public Shape
{
  public:
    Triangle(int l = 0, int w = 0) : Shape(l, w){};
    int area()
    {
        cout << "Triangle Area is :";
        return (this->width * this->length / 2);
    }
};

int main(int argc, char const *argv[])
{
    Shape *shape;

    // 全局类对象，配合指针使用，高效
    // 使用栈空间，无需手动释放内存，合适频繁调用场景
    Rectangled rec(5, 6);
    Triangle tri(5, 6);

    shape = &rec;
    cout << shape->area() << endl;

    shape = &tri;
    cout << shape->area() << endl;

    // new创建的是：局部类对象
    // 使用堆空间，需要指针接收，需要手动释放内存，不适合频繁调用场景
    shape = new Shape();
    delete shape;
    return 0;
}
