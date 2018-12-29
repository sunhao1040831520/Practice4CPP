#include <iostream>
#include <cstdlib>
#include "AnalogSystem.h"

// 窗口数量
#define WINDOW_NUM 4
// 总共服务时间/分钟
#define WORKING_TIME 240
// 模拟次数
#define SIMULATE_NUM 100000

int main(int argc, char const *argv[])
{

    // 参考网站： https://blog.csdn.net/qq_16849135/article/details/52278978
    // 使用当前时间作为随机数种子
    std::srand((unsigned) time(0));
    AnalogSystem analog_system(WORKING_TIME, WINDOW_NUM);



    /* code */
    return 0;
}