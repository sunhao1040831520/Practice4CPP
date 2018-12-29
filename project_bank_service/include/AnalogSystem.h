// 模拟系统，虚拟一天的人员接待
#include "ServiceWindow.hpp"
// deque STL 双端队列
#include <deque>
#include "Customer.h"

class AnalogSystem
{
  public:
    AnalogSystem(int working_hours, int window_num);

    ~AnalogSystem();

    void run();

    int getAverageStayTime()
    {
        return this->avg_stay_time;
    }

    int getTotalCustomerNum()
    {
        return this->total_customer_num;
    }

  private:
    int working_hours;
    int window_num;
    int total_customer_num;
    int total_stay_time;
    int avg_stay_time;
    int total_serve_time;
    int avg_serve_time;

    void init();

    ServiceWindow *windos;
    std::deque<Customer> customerDeque;
};
