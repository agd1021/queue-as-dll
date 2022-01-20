// OrderQueue.cpp

#include "OrderQueue.h"
// #include "Order.h"

OrderQueue::OrderQueue()
{
    head = nullptr;
    tail = nullptr;
}

// adds customer order to DLL according to queue rules
// first in, first out ordering
void OrderQueue::addOrderToQueue(Order* order)
{
    // Case 1: Empty list
    if( empty() ) 
    {
        // both head & tail point to inserted order
        head = order;
        tail = order;
    }
    // Case 2: Insert after tail
    else
    {
        // update tail order's next order to point to inserted order
        tail->next_order = order;
        // update inserted order's prev_order to point to tail order
        order->prev_order = tail;
        // update inserted order's next_order to point to null
        order->next_order = nullptr;
        // update Doubly linked list's tail order to inserted order
        tail = order;
    }   
}

// removes customer order from DLL according to queue rules
// first in, first out ordering
void OrderQueue::removeOrderFromQueue()
{
    // Case 1: deleting order from a list with only 1 order
    if ( head == tail )
    {
        head = nullptr;
        tail = nullptr;
    }
    // Case 2: delete head order in a list with more than 1 order
    else if( !empty() ) 
    {
        // update the DLL's head pointer to the second order
        head = head->next_order;
        // update the first order's next pointer to null
        head->prev_order->next_order = nullptr; 
        // update new head's prev pointer to null
        head->prev_order = nullptr;
    }
    // else
    // {
    //     cout << "Cannot delete from an empty list!" << endl;
    // }
    
}

// gets the order that is first in the queue to be fulfilled
// based on queue ordering: first in, first out
// think: where is the order located in your list? HEAD
Order& OrderQueue::getFirstOrder()
{
    return( *head );
}

// checks if DLL is empty
bool OrderQueue::empty()
{
    if( (head == nullptr) && (tail == nullptr) )
    {
        return(true);
    }
    else
    {
        return(false);
    } 
}

// prints DLL
void OrderQueue::printAllOrders()
{
    Order* curr_order = head;
    while( curr_order != nullptr )
    {
        curr_order->printOrder();
        curr_order = curr_order->next_order;
    }
}
