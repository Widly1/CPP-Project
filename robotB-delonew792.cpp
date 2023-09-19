// ------------------------------------------------------------------
// File name:   robotB-deloneW792.cpp
// Assign ID:   TP2 
// Due Date:    11/16/22 
//
// Purpose:     Simple robot moving on 10x10 grid.
//
// Author:      deloneW792 Widly Delone
//
// ------------------------------------------------------------------

#include <iostream>
using namespace std;

void Display_Menu()
{
   cout << "\nCommand: [S T W M L R U D]: ";
} //Display_Menu

void Perform_Choice(char choice, int & x, int & y, int & vMoves, int & iMoves)
{        
      switch (toupper(choice))
      {
        case 'S': x = 0; y = 0;
                  break;
        case 'W': cout << "ROBOT AT ( " << x << ", " 
                       << y << " )" << endl;   
                  break;

        case 'M': cout << vMoves <<" VALID MOVES, " << iMoves << " invalid moves"  << endl;
                  break;
         
        case 'L': x--; 
                  vMoves++;
                  if (x < 0)
               { 
                 cout << "INVALID MOVE TO ( " << x << ", " 
                       << y << " )" << endl; 
                       vMoves--;
                       iMoves++;
                       x++; 
               }                                                
                       break; 
      
        case 'U': y++; 
                  vMoves++;              
                  if (y > 10)
               { 
                 cout << "INVALID MOVE TO ( " << x << ", " 
                       << y << " )" << endl; 
                       vMoves--;
                       iMoves++;
                       y--; 
               }        
                 break;  

        case 'D': y--; 
                  vMoves++;
                  if (y < 0)
               { 
                 cout << "INVALID MOVE TO ( " << x << ", " 
                       << y << " )" << endl; 
                       vMoves--;
                       iMoves++;
                       y++; 
               }                                                                
                  break;          

        case 'R': x++; 
                  vMoves++;
                  if (x > 10)
               { 
                 cout << "INVALID MOVE TO ( " << x << ", " 
                       << y << " )" << endl; 
                       vMoves--;
                       iMoves++;
                       x--; 
               }               
                  break;

        case 'T': cout << "... SHUTTING DOWN" << endl; 
                  break;
   
        default:  cout << "BAD MENU CHOICE (" << choice 
                       << ") -- ignored." << endl;
                  break;

      }//switch
} //Perform_Choice


int main()
{
   // ----------------------------------------------------------------------
   //  Declare variables
   // ----------------------------------------------------------------------
   char choice;               // Menu choice.
   int xpos = 0, ypos = 0;    // Position of the robot.
   int vMoves= 0;         // The number of VALID moves. 
   int iMoves=0;         // The number of invalid moves.

   //-|-------------------------------------------------------------
   //-| Display copyright.
   //-|-------------------------------------------------------------
   cout <<endl <<  "(c) 2022, deloneW792 Widly Delone" << endl << endl;

   //-|-------------------------------------------------------------
   //-| Repeat until choice 'T' is made.
   //-|   a. Display menu.
   //-|   b. Read user choice.
   //-|   c. Perform choice.
   //-|-------------------------------------------------------------
   do
   {
      //-|-------------------------------
      //-|  a. Display menu.
      //-|-------------------------------
      Display_Menu();
     
      //-|-------------------------------
      //-| b. Read user choice.
      //-|-------------------------------
      cin >> choice;

      //-|-------------------------------
      //-| c. Perform choice.
      //-|-------------------------------
      Perform_Choice(choice, xpos, ypos, vMoves,iMoves);
   }
   while (toupper(choice) != 'T');


   //-|-------------------------------------------------------------
   //-| Display copyright.
   //-|-------------------------------------------------------------
   cout <<endl <<  "(c) 2022, deloneW792 Widly Delone" << endl << endl;

   //-|-------------------------------------------------------------
   //-| Terminate program. 
   //-|-------------------------------------------------------------
   cout << "\n\nEND OF PROGRAM\n\n";
   return 0;

}//main

