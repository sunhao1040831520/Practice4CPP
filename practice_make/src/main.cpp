#include <iostream>
#include "../include/module1.h"
#include "../include/module2.h"
#include "../include/module3.h"

using namespace std;

void main_say(){
    cout << "main.cpp" << endl;
}

int main(int argc, char const *argv[])
{
    main_say();
    module1_say();
    module2_say();
    module3_say();
    return 0;
}