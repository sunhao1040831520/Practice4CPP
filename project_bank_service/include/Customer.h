
#include "Random.hpp"

#define RANDOM_PARAMETER 100

typedef struct Customer
{
    // 到达时间
    int arrive_time;
    // 所需服务时间
    int serve_time;
    // 排队时间
    int stay_time;

    Customer(int arrive_time = 0, int serve_time = Random::uniform(RANDOM_PARAMETER))
    {
        Customer::arrive_time = arrive_time;
        Customer::serve_time = serve_time;
    };
};
