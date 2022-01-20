// OrderQueue.h

#ifndef OrderQueue_H
#define OrderQueue_H

#include "Order.h"

class OrderQueue
{
    public:
        OrderQueue();
        void addOrderToQueue(Order* order);
        void removeOrderFromQueue();
        Order& getFirstOrder();
        bool empty();
        void printAllOrders();
    private:
        Order* head;
        Order* tail;
};

#endif