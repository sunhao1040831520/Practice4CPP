#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    char *temp_input_char = new char[100];

    // 追加 | 定位最后位置 | 数据写出模式
    ofstream outfile;
    outfile.open("4.file_stream_cpp_text.txt", ios::app | ios::ate | ios::out);

    // 提示获取输入
    cout << "Wirtting to the file";
    cout << "Enter your name:";
    cin.getline(temp_input_char, 100);

    // 写出数据
    outfile << "Name: " << temp_input_char;

    // 提示获取输入
    cout << "Enter your age:";
    cin >> temp_input_char;
    cin.ignore();

    // 写出数据
    outfile << " Age:" << temp_input_char << endl;

    // 关闭文件流
    outfile.close();

    // 读出数据模式
    ifstream infile;
    infile.open("4.file_stream_cpp_text.txt", ios::in);

    // 读数据: 一行
    // infile >> temp_input_char;

    // 读数据： char、全部
    // infile.seekg(0, ios::end);
    // int length = infile.tellg();
    // infile.seekg(0, ios::beg);
    // temp_input_char = new char[length];
    // infile.read(temp_input_char, length);
    // cout << temp_input_char << endl;

    // 读数据： string、全部
    stringstream buffer;
    buffer << infile.rdbuf();
    string temp_input_string(buffer.str());
    cout << temp_input_string << endl;

    // 关闭文件
    infile.close();

    return 0;
}
