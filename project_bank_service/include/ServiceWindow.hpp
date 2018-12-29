#include "Customer.h"

enum WindowStatus
{
    IDLE,
    IN_SERVICE,
};

class ServiceWindow
{
  public:
    inline ServiceWindow()
    {
        this->window_status = WindowStatus::IDLE;
    }
    
    inline bool isIdle() const
    {
        return (this->window_status == WindowStatus::IDLE);
    }

    inline bool serve(Customer &customer){
        this->currCustomer = customer;
        this->window_status = WindowStatus::IDLE;
    }

  private:
    Customer currCustomer;
    WindowStatus window_status;
};