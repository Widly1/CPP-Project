// ------------------------------------------------------------------
// File name:   robotC-deloneW792.cpp
// Assign ID:   TP3 
// Due Date:    11/18/22 
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
   cout << "\nCommand: [F S T W M L R U D]: ";
} //Display_Menu

void Perform_Choice(char choice, int & x, int & y, int & vMoves, int & iMoves, int & power)
{        
      switch (toupper(choice))
      {
         case 'F': 
               cout << "+====================================================+"<< endl;
               cout << "| ROBOT C Main Menu                                  |" << endl; 
               cout << "|   F - show detailed menu                           |" << endl;
               cout << "|   S - start robot                                  |" << endl;
               cout << "|   W - show current position                        |" << endl;
               cout << "|   P - show power level (-2 Power for invalid moves)|" << endl;
               cout << "|   M - show valid/invalid moves                     |" << endl;
               cout << "|   R - move right 1 space                           |" << endl;
               cout << "|   L - move left 1 space                            |" << endl;
               cout << "|   U - move up 1 space                              |" << endl;
               cout << "|   D - move down 1 space                            |" << endl; 
               cout << "|   T - terminate/shut down robot                    |" << endl;
               cout << "+====================================================+"<< endl;
               cout << endl;
               break;
         
         case 'S': x = 0; y = 0;
                   power=20;
                  break;
               
         case 'P': cout << "ROBOT POWER = " << power << endl;
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
                       power-=2;
               }
                  else
               {
                   power--;
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
                       power-=2;
               }  
                 else
               {
                   power--;
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
                       power-=2;
               } 
                 else
               {
                   power--;
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
                       power-=2;
               }
                else
                {
                   power--;
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
   int vMoves= 0;             // The number of VALID moves. 
   int iMoves= 0;             // The number of invalid moves.
   int power= 20;             // The amount of power the robot has.

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
      Perform_Choice(choice, xpos, ypos, vMoves,iMoves, power);
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

