// ------------------------------------------------------------------
// File name:   robotD-deloneW792.cpp
// Assign ID:   TP4 
// Due Date:    11/22/22 
//
// Purpose:     Simple robot moving on 10x10 grid.
//
// Author:      deloneW792 Widly Delone
//
// ------------------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

void Display_Menu()
{
   cout << "\nCommand: [F S T W M L R U D]: ";
} //Display_Menu

void Perform_Choice(ifstream & inF, string name, char choice, int & x, int & y, int & vMoves, int & iMoves, int & power)
{        
    switch (toupper(choice))
      {
         case 'F': 
              cout << "+====================================================+"<< endl;
               cout << "|  ROBOT " << name <<" Main Menu                           |" << endl; 
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
         
         case 'S': inF >> name >> x >> y >> power;
                   cout << "ROBOT " << name;
                   cout << " STARTING AT (" << x << ", " << y << ") ";
                   cout << "WITH POWER " << power << endl << endl;
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
   int power;                 // The amount of power the robot has.

   string name;               // Robot's Name.

   //-|-------------------------------------------------------------
   //-| The input stream.
   //-|-------------------------------------------------------------

      ifstream inF("robot_start.txt");         

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

         inF >> name >> xpos >> ypos >> power;

      //-|-------------------------------
      //-|  b. Display menu.
      //-|-------------------------------
      Display_Menu();
     
      //-|-------------------------------
      //-| c. Read user choice.
      //-|-------------------------------
      cin >> choice;

      //-|-------------------------------
      //-| d. Perform choice.
      //-|-------------------------------
      Perform_Choice(inF, name, choice, xpos, ypos, vMoves,iMoves, power);
   } 
   while (toupper(choice) != 'T' && power > 0);     
      if(power <= 0)
        {
          cout << endl << "ROBOT " << name << " POWER LEVEL = " << power << " SHUTTING DOWN.";
          cout << endl;
          cout << endl;
          cout << endl << "ROBOT " << name << " SERVICE SUMMARY " << endl;
          cout << endl <<"===========================================";
          cout << endl <<"STOP POSITION: (" << xpos <<", " << ypos << " )";
          cout << endl <<"STOP POWER = " << power;
          cout << endl <<"VALID MOVES = "<< vMoves << ", INVALID MOVES = " << iMoves;
          cout << endl <<"===========================================";
        }

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

