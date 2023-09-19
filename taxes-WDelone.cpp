//---------------------------------------------------------------------------
// File name:   taxes.cpp
// Assign ID:   PROG1
//
// Purpose:     Compute annual income tax based on tax rate and monthly pay.
//
// Author:      Widly Delone
//---------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
   //-------------------------------------------------------------------------
   //  Declare variables, ONE PER LINE.
   //-------------------------------------------------------------------------
   float  taxRate, //tax rate.
          Annual_Income, // annual income.
          Taxes_Due; //taxes due.
   float  Jan,    // January pay.
          Feb,   // February pay.
          Mar,   // March pay.
          Apr,   // April pay.
          May,   // May pay.
          Jun,   // June pay.
          Jul,   // July pay.
          Aug,   // August pay.
          Sep,   // September pay.
          Oct,   // October pay.
          Nov,   // November pay.
          Dec;   // December pay.          
   
   
   //-|-----------------------------------------------------------------------
   //-| Display the copyright notice declaring authorship.
   //-|-----------------------------------------------------------------------
   cout << endl << "\n\n(c) 2022, DeloneW, Widly Delone" << endl << endl; 

   //-|-----------------------------------------------------------------------
   //-| 0. Ensures that numbers are displayed with 2 decimal places.
   //-|    
   //-|-----------------------------------------------------------------------
   cout << showpoint << fixed << setprecision(2);


   //-|-----------------------------------------------------------------------
   //-| 1. INPUT(I) Read inputs.
   //-|-----------------------------------------------------------------------
   //-|    1.a Read tax rate.
   //-|    1.b Read amount of pay for each of the 12 months.
   //-|-----------------------------------------------------------------------
   cout << endl << "Enter tax rate (as a fraction: 10% as 0.10): ";
   cin >> taxRate; //reading the tax rate input from user.

   cout << endl << "Enter pay for Jan, Feb, and Mar (followed by a space): " << endl;
   cin >> Jan >> Feb >> Mar;  // reading the pay from Jan-march. 

   cout << endl << "Enter pay for Apr, May, and Jun (followed by a space): " << endl;
   cin >> Apr >> May >> Jun; //reading the monthly pay.

   cout << endl << "Enter pay for Jul, Aug, and Sep (followed by a space): " << endl;
   cin>> Jul >> Aug >> Sep; // reading the monthly pay.

   cout << endl << "Enter pay for Oct, Nov, and Dec (followed by a space): " << endl;
   cin >> Oct >> Nov >> Dec; // reading the monthly pay.


   //-|-----------------------------------------------------------------------
   //-| 2. PROCESS(P) Perform calculation.
   //-|-----------------------------------------------------------------------
   //-|    2.a Compute Annual_Income = JanPay + FebPay + ... + DecPay
   //-|    2.b Compute Taxes_Due = (tax rate) x totalIncome
   //-|-----------------------------------------------------------------------
   //-|----------------------------------------------------------------------
   Annual_Income = (Jan + Feb + Mar + Apr + May + Jun + Jul + Aug + Sep + Oct + Nov + Dec); //compute the annual income entered. 

   Taxes_Due = taxRate * Annual_Income; // calculation for taxes due.

   taxRate = (100 * taxRate); // calculations for tax rate.

   
   //-|-----------------------------------------------------------------------
   //-| 3. OUTPUT(O) Display outputs. 
   //-|-----------------------------------------------------------------------
   //-|    3a)  ANNUAL INCOME = $ AnnualIncome
   //-|    3b)  TAX RATE = 100 * taxRate %
   //-|    3c)  INCOME TAX = $ Taxes_Due
   //-|-----------------------------------------------------------------------
   cout << endl << "ANNUAL INCOME = $ " << Annual_Income; // displaying output for Annual Income. 

   cout << endl << "TAX RATE = " << taxRate << " % "; //  displaying output for tax rate.

   cout << endl << "INCOME TAX = $ " << Taxes_Due; // displaying output for taxes due.



   //-|-----------------------------------------------------------------------
   //-| Display the copyright notice declaring authorship again.
   //-|-----------------------------------------------------------------------
   cout << endl << "\n\n(c) 2022, DeloneW, Widly Delone" << endl << endl; 


   return 0;

}//main

