// Order.h
#ifndef ORDER_H
#define ORDER_H

#include <string> // private data member string pointer
using namespace std; // std::string

class Order {
    public:
        Order(int number, string name);
        string getCustomerName();
        void printOrder();
        friend class OrderQueue;
        ~Order();
    private:
        Order* next_order;
        Order* prev_order;
        int* number;
        string* name;
};

#endif