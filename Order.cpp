// Order.cpp

#include "Order.h"
#include <iostream> // for cout
#include <string> // for customer names
using namespace std;

// Overloaded constructor
Order::Order(int number, string name)
{
    // allocate memory for order number and customer's name
    this->number = new int;
    this->name = new string;
    // assign argument values to private data members
    *(this->number) = number;
    *(this->name) = name;
    // assign null pointers to next and previous orders
    this->next_order = nullptr;
    this->prev_order = nullptr;
}

string Order::getCustomerName()
{
    return( *name );
}

void Order::printOrder()
{
    cout << *number << ". " << *name << endl;
}

Order::~Order()
{
    delete this->number;
    delete this->name;
    delete this->next_order;
    delete this->prev_order;
}