//------------------------------------------------------------------
// File name:   standing.cpp
// Assign ID:   PROG4
// Author: Widly Delone 
//
// Purpose:     Read student data from input file, reformat data and
//              compute the average GPA and weighted (by cumHours) GPA.
//
// Input Line:  ID Firstname Lastname MiddleInit Courseload CumHours GPA 
//
//
// Sample Output:  
//
//       ACADEMIC STANDING REPORT
//
//       1234bb123456789bb1234bb12345bbb1234567890123bb      (yardstick)
//       ====  =========  ====  =====   =============  ==================
//       ====  =========  ====  =====   =============  ========================
//        GPA  StudentID  Load  Hours   Standing       Student_Name
//       ====  =========  ====  =====   =============  ========================
//       2.52  143841138    18    112   GOOD STANDING  Jones, Edward L
//       1.99  411384112    12     67   ON PROBATION   Frugal, Miser X
//       3.83  118113428     6     31   HONORS         Sapp, Marilyn Q
//       ====  =========  ====  =====   =============  ==================
//
//       Number of Students =  3
//       12bxxxxxxxxxxxxxxxxxxxxxxxxx    (yardstick)
//        1 Students in Good Standing
//        1 Students On Probation
//        1 Honors Students
//
//       Average Student GPA  = 2.779
//       Weighted Average GPA = 2.544
//
//-------------------------------------------------------------------
// 
//       STUDENT GPA REPORT
//
//       1234xx123456789xx1234xx12345xxx123456789012345678901234 (yardstick)
//       ====  =========  ====  =====   ========================
//        GPA  StudentID  Load  Hours   Student_Name
//       ====  =========  ====  =====   ========================
//       2.52  143841138    18    112   Jones, Edward L
//       1.99  411384112    12     67   Frugal, Miser X
//       3.83  118113428     6     31   Sapp, Marilyn Q
//       ====  =========  ====  =====   ========================
//
//       Number of Students =  3
//       Average Student GPA  = 2.779
//       Weighted Average GPA = 2.544
//            Note: WEIGHTED AVERAGE is OPTIONAL/BONUS.
//
//-------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

int main()
{

   // -------------------------------------------------------------------
   // 1. Declare/Create file streams for input (students.dat) 
   //                and output (student.rpt).
   // -------------------------------------------------------------------
      ifstream inF("students.dat") ; // input file.
      ofstream outF("students.rpt"); //  output file. 
   // -----------------------------------------------------------
   // 1.5. Declare if statement in case file cannot open for student data.
   // -----------------------------------------------------------
      if (inF.fail())
      {
         cout << "FATAL ERROR: can not OPEN file 'students.dat'." << endl;
         exit(1);
      }
   // -----------------------------------------------------------
   // 2. Declare variables for student data.
   // -----------------------------------------------------------
      int load1,      // course load for student 1.
          load2,      // course load for student 2.
          load3;      // course load for student 3.
      
      int Hcount=0,   // honors count (starts at 0). 
          Pcount=0,   // probations count (starts at 0). 
          Gscount=0;  // Good Standing count (starts at 0).  
      
      int numStu=0; // Number of students.    
      
      int hours1,     //cumHours  for student 1.
          hours2,     // cumHours for student 2.
          hours3;     // cumHours for  student 3.                 
      
      long iD1,       // Student ID 1.
           iD2,       // student ID 2.
           iD3;       // student ID 3.
      
      string fName1,lName1, mInitial1;   // student 1 full name.
      string fName2,lName2, mInitial2;   // student 2 full name.
      string fName3,lName3, mInitial3;   // student 3 full name.
      string standing1,     // academic standing for student 1.  
             standing2,     // academic standing for student 2. 
             standing3;     // academic standing for student 3.           
      
      float GPA1,         // student 1 GPA.
            GPA2,         // Student 2 GPA.
            GPA3,         // student 3 GPA.
            avgGPA,       // average GPA for 3 students.
            waGPA;        // Weighted Average GPA.
        
       // -----------------------------------------------------------      
       // 3. Read INPUT for student data.
       // -----------------------------------------------------------
      cout << fixed << setprecision(3)<<showpoint;
      inF >> iD1>> fName1 >> mInitial1 >> lName1 >> load1 >> hours1 >> GPA1;    // student #1 data. 
      inF >> iD2>> fName2 >> mInitial2 >> lName2 >> load2 >> hours2 >> GPA2;    // student #2 data. 
      inF >> iD3>> fName3 >> mInitial3 >> lName3 >> load3 >> hours3 >> GPA3;    // student #3 data. 

        if (GPA1 >= 3.0)
         { standing1= "HONORS";
            Hcount++;
         }
      else if (GPA1 < 2.0) 
         {
         standing1 = "ON PROBATION";
            Pcount++;
         }
      else 
         {
         standing1 = "GOOD STANDING";
            Gscount++;
         }
         if (GPA2 >= 3.0)
         { standing2= "HONORS";
            Hcount++;
         }
      else if (GPA2 < 2.0) 
         {
         standing2 = "ON PROBATION";
            Pcount++;
         }
      else 
         {
         standing2 = "GOOD STANDING";
            Gscount++;
            cout << endl;
         }
         if (GPA3 >= 3.0)
         { standing3= "HONORS";
            Hcount++;
         }
      else if (GPA3 < 2.0) 
         {
         standing3 = "ON PROBATION";
            Pcount++;
         }
      else 
         {
         standing3 = "GOOD STANDING";
            Gscount++;
            cout << endl;
         }
   //-|-----------------------------------------------------------
   //-| Display copyright notice ON SCREEN only..
   //-|-----------------------------------------------------------
       cout << "\n\n(c) 2022,  WDelone Widly Delone\n\n"; 
   //-|-----------------------------------------------------------
   //-| PUT YOUR ALGORITHM STEPS IN, as in previous programs.
   //-|-----------------------------------------------------------
      
   //-|-----------------------------------------------------------
   //-| 4. Calculations that will be used.
   //-|-----------------------------------------------------------
          avgGPA= (GPA1 + GPA2 + GPA3)/3;           // calculations for average GPA.
          waGPA= ((GPA1*hours1)+(GPA2*hours2)+(GPA3*hours3))/(hours1+hours2+hours3);  //calculations for weighted average.
          numStu= Hcount+Gscount+Pcount;           //the number of student calculated.
    //-|-----------------------------------------------------------
   //-| 5. Output student data to output file student report file.
   //-|-----------------------------------------------------------
      outF << fixed << setprecision(2)<<showpoint;
      outF << "STUDENT GPA REPORT\n" << endl;
      outF << "====  =========  ====  =====   ========================\n";
      outF << "GPA   StudentID  Load  Hours   Student_Name\n";
      outF << "====  =========  ====  =====   ========================\n";
      outF<< setw(4)<<right<< GPA1 << "  " <<setw(9)<< right<< iD1 << "  ";
      outF<< setw(4) << right << load1 << "  "<< setw(5)<< right << hours1 <<"   ";
      outF<<lName1 << ", "<<fName1 << " " << mInitial1 <<"\n"; 

      outF<< setw(4)<<right<< GPA2 << "  " <<setw(9)<< right<< iD2 << "  ";
      outF<< setw(4) << right << load2 << "  "<< setw(5)<< right << hours2 <<"   ";
      outF<<lName2 << ", "<<fName2 << " " << mInitial2 <<"\n";
         
      outF<< setw(4)<<right<< GPA3 << "  " <<setw(9)<< right<< iD3 << "  ";
      outF<< setw(4) << right << load3 << "  "<< setw(5)<< right << hours3 <<"   ";
      outF<<lName3 << ", "<<fName3 << " " << mInitial3 <<"\n";
      outF<< "====  =========  ====  =====  ========================\n";
      outF<< endl; 
      outF<< "Number of Students = " << numStu;
      outF<<endl << endl;
      outF<< "Average Student GPA  = " << setw(4) << showpoint << fixed << setprecision(3)<< avgGPA;
      outF<< endl<< endl;
      outF<< "Weighted Average GPA = " << setw(4) << showpoint << fixed << setprecision(3) << waGPA;

   //-|-----------------------------------------------------------------------
   //-| 6. Output the students data on screen as the ACADEMIC STANDING REPORT.
   //-|-----------------------------------------------------------------------
      cout << fixed << setprecision(2)<<showpoint;
      cout << "ACADEMIC STANDING REPORT\n" << endl;
      cout << "====  =========  ====  =====   =============  ========================\n";
      cout << "GPA   StudentID  Load  Hours   Standing       Student_Name\n";
      cout << "====  =========  ====  =====   =============  ========================\n";
      cout << setw(4)<<right<< GPA1 << "  " <<setw(9)<< right<< iD1 << "  ";
      cout << setw(4) << right << load1 << "  "<< setw(5)<< right << hours1 <<"   ";
      cout << setw(13) << left << standing1 << "  "<<lName1 << ", "<<fName1 << " " << mInitial1 <<"\n"; 

      cout << setw(4)<<right<< GPA2 << "  " <<setw(9)<< right<< iD2 << "  ";
      cout << setw(4)<< right << load2 << "  "<< setw(5)<< right << hours2 <<"   ";
      cout << setw(13) << left<< standing2 << "  " <<lName2 << ", "<<fName2 << " " << mInitial2 <<"\n";
         
      cout << setw(4) << right<< GPA3 << "  " <<setw(9)<< right<< iD3 << "  ";
      cout << setw(4) << right << load3 << "  "<< setw(5)<< right << hours3 <<"   ";
      cout << setw(13) << left << standing3 << "  "<< lName3 << ", "<<fName3 << " " << mInitial3 <<"\n";
      cout << "====  =========  ====  =====   =============  ========================\n";
      cout << endl; 
      cout << "Number of Students = " << numStu<< endl;
      cout <<Hcount << " " << "Honors Student(s)" << endl; 
      cout <<Gscount  << " " << "Student(s) in Good Standing" << endl;
      cout <<Pcount<< " " <<  "Student(s) on Probation" << endl;
      cout << endl;
      cout << endl;
      cout<< "Average Student GPA  = " << setw(4) << showpoint << fixed << setprecision(3)<< avgGPA;
      cout << endl;
      cout << endl;
      cout<< "Weighted Average GPA = " << setw(4) << showpoint << fixed << setprecision(3) << waGPA;
      cout << endl;
      cout << endl;
      cout << endl;
      cout << endl;
   //-|-----------------------------------------------------------
   //-| 7. Close all files, as demonstrated in PROG3.
   //-|-----------------------------------------------------------
      inF.close();
      outF << flush; outF.close();
  //-|-----------------------------------------------------------
   //-| 8. Show Copyright at the end of outputs.
   //-|-----------------------------------------------------------
  cout<< "(c) 2022, WDelone, Widly Delone" << endl << endl;
  cout << endl;
  return 0;
}//main	
