#include <iostream>
#include <cstring>

using namespace std;
 

struct Book
{
    int book_id;
    char title[50];
    char author[50];
    char subject[100];
};

// 在 C 中，加上这句话，可以： Book book 申明变量，不加不行
// 在 C++ 中，不加也可以
typedef struct Book Book;

int main(int argc, char const *argv[])
{
    struct Book Book1;
    Book Book2;

    strcpy(Book1.title, "C++ 教程"); 
    strcpy(Book1.author, "Runoob");
    strcpy(Book1.subject, "编程语言");
    Book1.book_id = 10001;

    strcpy(Book2.title, "C++ 教程"); 
    strcpy(Book2.author, "Runoob");
    strcpy(Book2.subject, "编程语言");
    Book2.book_id = 10001;
 
   // 输出 Book1 信息
   cout << "第一本书标题 : " << Book1.title <<endl;
   cout << "第一本书作者 : " << Book1.author <<endl;
   cout << "第一本书类目 : " << Book1.subject <<endl;
   cout << "第一本书 ID : " << Book1.book_id <<endl;
 
   // 输出 Book2 信息
   cout << "第二本书标题 : " << Book2.title <<endl;
   cout << "第二本书作者 : " << Book2.author <<endl;
   cout << "第二本书类目 : " << Book2.subject <<endl;
   cout << "第二本书 ID : " << Book2.book_id <<endl;

    return 0;
}