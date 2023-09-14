//------------------------------------------------------------------
// File name:   momNpopzPizza.cpp
// Assign ID:   PROG3
// Due Date:    09/22/2022
//
// Purpose:     Process ONE order at pizza shop. Prices are read from 
//              file 'prices.dat'. A customer order is taken: a 7.5% 
//              sales tax is applied to the order amount. The customer
//              pays for the order and is given a customer receipt. 
//              The order is written to output file 'sales.dat'. 
//
// Author:      WDelone Widly Delone 
//------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
   //----------------------------------------------------------------------
   //  Declare variables, ONE PER LINE.
   //----------------------------------------------------------------------

         // Input/Output file streams. 
   ifstream pricesF("prices.dat"); // Input file containing prices.
   ofstream salesF("sales.dat");   // Output file containing sale summary.

         // Input variables -- prices.dat file data.
   float cost_Pizza,  // Cost of today's pizza.
         cost_Drink,  // Cost of drinks.
         cost_Bread,  // Cost of today's bread stick order.  
         cost_Cookie; // Cost of cookies.

         // Input variables -- customer order from keyboard.
   int   num_Pizzas,  // Number of pizzas ordered.
         num_Drinks,  // Number of drinks ordered.
         num_Breads,  // Number of breads ordered.
         num_Cookies; // Number of Cookies ordered.  

         // Calculated variables.
   float order_Amt,   // Amount of order.
         sales_Tax,   // Amount of sales tax.
         amt_Due,     // Payment due from customer.
         amt_Tendered,// Amount tendered by customer.
         amt_Change;  // Amount of change due to customer.


   //-|---------------------------------------------------------------------
   //-| Display the copyright notice declaring authorship.
   //-|---------------------------------------------------------------------
   cout << "\n\n(c) 2022,  WDelone Widly Delone\n\n"; 

   //-|---------------------------------------------------------------
   //-| 1. INPUT (I): Read prices for today's menu from input file.
   //-|             
   //-|    1.1. Read cost of pizza.
   //-|    1.2. Read cost of drink.
   //-|    1.3. Read cost of bread sticks.
   //-|    1.4. Read cost of big cookie.
   //-|---------------------------------------------------------------
      pricesF >> cost_Pizza; // input the cost of pizza.
      pricesF >> cost_Drink; // input the cost of drink.
      pricesF >> cost_Bread; // input the cost of bread.
      pricesF >> cost_Cookie; //input the cost of cookies from file. 

   //-|---------------------------------------------------------------
   //-| 2. OUTPUT (O): Display today's menu to screen.
   //-|             
   //-|    2.1 Cost  of today's pizza.
   //-|    2.2 Cost of drink.
   //-|    2.3 Cost of bread sticks.
   //-|    2.4 Cost of big cookie.
   //-|---------------------------------------------------------------
   cout << endl << fixed << showpoint << setprecision(2);

   cout << "TODAY'S MENU at MOM-N-POPZ PIZZA" << endl;
   cout << endl;
   cout << "      $ " << cost_Pizza << "  - Pizza of the Day" << endl;  // the cost of pizza displayed.
   cout << "      $ " << cost_Drink << "  - 2L Drink" << endl;          // the cost of the drinks displayed. 
   cout << "      $ " << cost_Bread << "  - Bread Sticks(6)" << endl;   // the cost of the bread displayed.
   cout << "      $ " << cost_Cookie <<"  - Big Cookie" << endl;       // the cost of the cookie displayed.  
   cout << endl;
   //-|---------------------------------------------------------------
   //-| 3. INPUT (I): Read customer order from keyboard.
   //-|             
   //-|    3.1 Read number of pizzas (num_Pizzas)
   //-|    3.2 Read number of drinks (num_Drinks).
   //-|    3.3 Read number of bread sticks orders (num_Breads).
   //-|    3.4 Read number of big cookies (num_Cookies).
   //-|---------------------------------------------------------------
   cout << "Enter number of Pizzas: ";                // asking for number of pizzas ordered.
   cin >>  num_Pizzas; 
   cout << endl;
   cout << "Enter number of Drinks: ";                // asking for number of drinks ordered.
   cin >> num_Drinks;
   cout << endl;
   cout << "Enter number of Bread Stick orders: ";    // asking for number of bread sticks ordered.
   cin >>num_Breads;
   cout << endl;
   cout << "Enter number of Cookies: ";              // asking for number of cookies ordered.
   cin >>num_Cookies;
   cout << endl;
   cout << endl;
   
   //-|---------------------------------------------------------------
   //-| 4. PROCESS (P) Calculate amount due.
   //-|
   //-|    4.1 Compute order_Amt = num_Pizzas * cost_Pizza
   //-|                           + num_Drinks * cost_Drink
   //-|                           + num_Breads * cost_Bread
   //-|                           + num_Cookies * cost_Cookie
   //-|
   //-|    4.2 Compute sales_Tax = 0.075 * order_Amt
   //-|    4.3 Compute amt_Due = order_Amt + sales_Tax
   //-|---------------------------------------------------------------
   order_Amt=(num_Pizzas * cost_Pizza)+(num_Drinks * cost_Drink )+(num_Breads * cost_Bread)+(num_Cookies * cost_Cookie);  // compute the order amount.

   sales_Tax= 0.075 * order_Amt;   // computing the sales tax.

   amt_Due= order_Amt + sales_Tax;  // computing the amount due. 
       
   //-|---------------------------------------------------------------
   //-| 5. OUTPUT (O) Display Amount Due to screen.
   //-|---------------------------------------------------------------
   cout << "Amount Due: $"<< amt_Due;     //output the display amount due.
   cout << endl;                          // input from user amount payed. 
   cout << endl;                          
   //-|---------------------------------------------------------------
   //-| 6. INPUT (I): Read amount tendered by customer (amt_Tendered)
   //-|               from keyboard.
   //-|---------------------------------------------------------------
   cout << "Enter payment: ";      // output to display the payment.
   cin >>amt_Tendered;
   cout << endl;
   //-|---------------------------------------------------------------
   //-| 7. PROCESS (P) Calculate amt_Change = amt_Tendered - amt_Due.
   //-|---------------------------------------------------------------
      amt_Change = amt_Tendered - amt_Due ;    //calculate the amount of change due.
   cout << endl;  
   //-|--------------------------------------------------------------------
   //-| 8. OUTPUT (O) Display Customer Receipt to screen.
   //-|             
   //-|    8.1 Receipt caption.
   //-|    8.2 Order caption.
   //-|    8.3 Number of pizzas.
   //-|    8.4 Number of drinks.
   //-|    8.5 Number of bread stick orders.
   //-|    8.6 Number of big cookies.
   //-|    8.7 Payment caption. 
   //-|    8.8 order amount. 
   //-|    8.9 sales tax. 
   //-|    8.10 amount due. 
   //-|    8.11 amount tendered. 
   //-|    8.12 change.
   //-|    8.13 thank-you caption.
   //-|    8.14 Receipt footer.
   //-|
   //-| NOTE***** The receipt is FORMATTED!!
   //-|---------------------------------------------------------------
      cout << "CUSTOMER RECEIPT" << endl;
      cout << "==============================================" << endl;
      cout << endl;
      cout << "YOUR ORDER:" << endl;
      cout << endl;
      cout << "     #Pizzas  =" << setw(3) <<num_Pizzas << endl;    // display the amount of pizzas purchased.
      cout << "     #Drinks  =" << setw(3) <<num_Drinks << endl;    // display the number of drinks purchased.
      cout << "     #Breads  =" << setw(3) <<num_Breads << endl;    // display the number of breads purchased.
      cout << "     #Cookies =" << setw(3) <<num_Cookies<<endl;  // display the number of cookies purchased.
      cout << endl;
      cout << "YOUR PAYMENT: " << amt_Tendered << endl;       // display the amount tendered.
      cout << endl;
      cout << "     AMOUNT OF ORDER = $" << setw(6) <<order_Amt << endl;   // display the order amount.
      cout << "     SALES TAX       = $" << setw(6) <<sales_Tax <<endl;    // display the sales tax.
      cout << "     AMOUNT DUE      = $" << setw(6) <<amt_Due <<endl;      // display the total amount due.
      cout << "     AMOUNT TENDERED = $" << setw(6) <<amt_Tendered << endl; // display the amount paid.
      cout << "     CHANGE RECEIVED = $" << setw(6) <<amt_Change << endl;   // display the change received.
      cout << endl;
      cout << "THANKS FOR YOUR BUSINESS. COME AGAIN. " << endl;
      cout << endl;
      cout << "==============================================" << endl;
      cout << "CUSTOMER RECEIPT" << endl;

   //-|---------------------------------------------------------------
   //-| 9. OUTPUT (O) Write sale to output file.
   //-|    9.1 Number of pizzas.
   //-|    9.2 Number of drinks.
   //-|    9.3 Number of bread stick orders.
   //-|    9.4 Number of big cookies.
   //-|    9.5 Order amount.
   //-|
   //-|   IN THE FORMAT:
   //-| CUSTOMER ORDER: x Pizzas, x Drinks, x Breadsticks, x Cookies ==> $ xxx.xx SALE
   //-|---------------------------------------------------------------
      salesF<< "CUSTOMER ORDER: "<< num_Pizzas << " Pizzas, " << num_Drinks << " Drinks, " << num_Breads << " Breadsticks, "<< num_Cookies << " Cookies ==> $ " << order_Amt << " SALE"<< endl; 
       
   //-|---------------------------------------------------------------
   //-| 10. Last: Close input and output files. DO NOT TOUCH!!
   //-|---------------------------------------------------------------
   pricesF.close();
   salesF << flush; salesF.close();

   //-|---------------------------------------------------------------------
   //-| Display the copyright notice declaring authorship again.
   //-|---------------------------------------------------------------------
   cout << endl << endl << "(c) 2022, WDelone Widly Delone " << endl; 

   return 0;

}//main

