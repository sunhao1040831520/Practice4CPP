#include <iostream>
#include <pthread.h>
// pthread 库不是 Linux 系统默认的库，连接时需要使用静态库 libpthread.a，编译时需要添加参数 -lpthread
// 编译命令：  g++ 7.mulit_thread_in_cpp.cpp -o 7.mulit_thread_in_cpp -lpthread

using namespace std;

#define NUM_THREADS 5

struct thread_data
{
    int thread_id;
    char *messages;
};

void *MyPrint(void *threadarg)
{
    struct thread_data *mydata = (struct thread_data *)threadarg;
    cout << "Thread ID: " << mydata->thread_id;
    cout << "Message: " << mydata->messages << endl;
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];

    for (int i = NUM_THREADS - 1; i >= 0; i--)
    {
        td[i].thread_id = i;
        td[i].messages = (char *)("Thread message.");
        int rc = pthread_create(&threads[i], NULL, MyPrint, (void *)&td[i]);

        if (rc)
        {
            cout << "Error: unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}
