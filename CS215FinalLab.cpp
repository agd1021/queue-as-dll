// CS215 Final Lab Exam
// Allison G. Davis
// ada283@uky.edu

// Help: http://www.cplusplus.com/doc/tutorial/exceptions/
// Help: CS215 Lab 8 Team: Doubly Linked Lists

#include <iostream> // cin, cout
#include <string> // for customerName
#include <stdexcept> // for try-throw-catch exception handling
#include <cctype> // for isdigit()
#include "OrderQueue.h"
// #include "Order.h"
using namespace std;

// Helper function
string get_user_input();

// Main Function
int main()
{
    bool validInput = false;
    int customerNumber = 0;
    string customerName = "";
    OrderQueue queue;

    // 1) get as many customer orders as user is going to enter (q to quit)
    do
    {
        // Get name
        customerName = get_user_input();

        // Add to queue
        if(customerName != "q")
        {
            Order* order;
            order = new Order(++customerNumber, customerName);
            queue.addOrderToQueue(order);
        }

    } while (customerName != "q");

    // 5) After user enters ‘q’, if order queue is not empty, 
    if (!queue.empty() )
    {
        do
        {
            // print all customer orders
            // and Print the queue after each order fulfillment.
            cout << endl << "Customer queue:" << endl;
            queue.printAllOrders();

            // fulfill all the orders by using FIFO queue ordering by removing one order at the time from the queue. 
            cout << endl << ">> Fulfilling order for: " << queue.getFirstOrder().getCustomerName() << endl;

            // Remove order
            queue.removeOrderFromQueue();

        }
        while ( !queue.empty() );
    }
    
     
    // 6) After all orders have been fulfilled, display corresponding message and quit the program.
    cout << endl;
    cout << "-------------------------------" << endl;
    cout << "All orders have been fulfilled!" << endl;
    cout << endl;

    return(0);
}


//Purpose: get user input customer name
//Pre-Condition: user enters FirstName LastName separated by space
//Post-Conditions: returns string of full name
string get_user_input()
{
    bool validInput = false;
    string customerName;

    // 1. DO-WHILE loop until you get good user input
    do
    {
        // 2. try-catch block to verify cin success
        try
        {
            // 1) gets as many customer orders as user is going to enter (q to quit)
            cout << "Enter customer full name (q to quit): ";
            getline(cin, customerName);

            // Verify input was a string
            if( cin.fail() )
            {
                // Use cin.fail / clear / ignore to clear input buffer in case of failure
                cin.clear();            // clear flags
                cin.ignore(256, '\n');  // ignore everything on stream

                // 4. Throw type error
                throw runtime_error("Input must be a string.");
            }
            // 2) you must verify that the user input is not empty, 
            // if it is, display error message, and display prompt for input again.
            else if( customerName.empty() )
            {
                throw runtime_error("You must enter customer name. Try again!");
            }
            else // user input was non-empty string
            {
                // 3) you must verify that input does not contain any digits. If there are digits in the string,
                // use boolean variable state (T/F) to indicate presence of the digits, display error message, and prompt for input again. 
                // Hint: use isdigit() function. It will check if the string contains digits (it will return true in this case) or not (will return false)
                for(int i = 0; i < customerName.length(); i++)
                {
                    if( isdigit(customerName[i]) )
                    {
                        throw runtime_error("Customer name cannot contain numbers. Try again!");
                    }
                }
            }
            // No errors thrown
            validInput = true; // exit while loop
        }
        catch(exception& e)
        {
            cout << e.what() << '\n';
        }
    // 4) use “q” as the indication of end of user input
    }while ( !validInput && (customerName != "q") );


    return customerName;
}