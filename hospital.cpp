#include <iostream>
#include <fstream>
#include "patients.h"

using namespace std;

int main() 
{
   
linkedQueueType<int> treatment;
linkedQueueType<int> discharge;

  
int allIDs[50];
string text;

  ifstream w("patients_info.txt");
  while(getline(w, text))
  {
  
    for(int j=0; j < 50; j++) 
        {
             w >> allIDs[j];
            cout << allIDs[j] << endl;
        }
        cout << endl;
  }
  w.close();

 int choice = 0 ;
    do {
            cout << endl;
                cout << "|--------------------------------------------------------|\n";
                cout << "| 1. Show sorted list of patients\n";                    
                cout << "| 2. Find a patient by ID\n";
                cout << "| 3. Add a patient to the queue\n";
                cout << "| 4. Show the queue\n";
                cout << "| 5. Remove a patient from the queue\n";
                cout << "| 6. Show the last patient in the queue\n";
                cout << "| 7. Show the total number of patients in the queue\n";
                cout << "| 8. Exit\n";
                cout << "|--------------------------------------------------------|\n";
                cout << "  Enter your choice:";
                cin >> choice;
                cout << endl;
        switch (choice) 
            {
            case 1:
               // Show sorted list of patients
                bubbleSort(allIDs, 50);
                cout << "Sorted list of patients: \n";
                for (int j = 0; j < 50; j++)
                    {
                        cout << allIDs[j] << endl;
                    }
                break;

            case 2:
                //  Find a patient by ID
                int searchItem;
                cout<<"Enter the ID you are searching for: \n";
                cin >> searchItem;
                
                int result;
                result = seqSearch(allIDs, 50, searchItem);
                    if(result != -1) //we use -1 because an array cannot have any values at -1
                        {
                            cout << "The patient with the ID "<<searchItem<<" is currently placed at position " << result + 1 << " in the list. \n";
                        }
                    else 
                        {
                            cout << "The patient with the ID you entered is not in the list.\n";
                        }
                break;

            case 3:
                // Add a patient to the queue
                int patientID;
                cout << "Enter Patient ID to add to queue: \n";
                cin >> patientID;

                int queueChoice;
                cout << "Choose the queue to add the patient to:\n";
                cout << "1. Treatment Queue\n";
                cout << "2. Discharge Queue\n";
                cin >> queueChoice;

                if (queueChoice == 1) 
                    {
                        treatment.addQueue(patientID);
                        cout << "Patient added to the Treatment Queue.\n";
                    } 
                else if (queueChoice == 2) 
                    {
                        discharge.addQueue(patientID);
                        cout << "Patient added to the Discharge Queue.\n";
                    } 
                else 
                    {
                        cout << "Invalid choice.\n";
                    }
                break;

            case 4:
                // Show the queue
                int showChoice;
                cout << "Choose the queue you would like to view:\n";
                cout << "1. Treatment Queue\n";
                cout << "2. Discharge Queue\n";
                cin >> showChoice;

                    if (showChoice == 1) 
                       {
                         treatment.showAll();
                       } 
                    else if (showChoice == 2) 
                       {
                         discharge.showAll();
                       } 
                    else 
                       {
                        cout << "Invalid queue choice.\n";
                       }
                
                break;

            case 5:
                // Remove a patient from the queue
                int deleteChoice;
                cout << "Choose the queue you would like to remove from:\n";
                cout << "1. Treatment Queue\n";
                cout << "2. Discharge Queue\n";
                cin >> deleteChoice;

                    if (deleteChoice == 1) 
                       {
                         treatment.deleteQueue();
                       } 
                    else if (deleteChoice == 2) 
                       {
                         discharge.deleteQueue();
                       } 
                    else 
                       {
                        cout << "Invalid queue choice.\n";
                       }
                
                break;

            case 6:
                // Show the last patient in the queue
                int viewChoice;
                cout << "Choose the queue you would like to view from:\n";
                cout << "1. Treatment Queue\n";
                cout << "2. Discharge Queue\n";
                cin >> viewChoice;

                    if (viewChoice == 1) 
                       {
                         cout<< "The last patient in the list is: "<<treatment.back()<< ".\n";
                       } 
                    else if (viewChoice == 2) 
                       {
                         cout<< "The last patient in the list is: "<<discharge.back()<< ".\n";
                       } 
                    else 
                       {
                        cout << "Invalid queue choice.\n";
                       }
                break;

            case 7:
                // Show the total number of patients in the queue
                int countChoice;
                cout << "Which queue would you like to view the count(total amount of patients) from:\n";
                cout << "1. Treatment Queue\n";
                cout << "2. Discharge Queue\n";
                cin >> countChoice;

                    if (countChoice == 1) 
                       {
                         cout << "There is/are " <<treatment.count()<<" patient(s) in this list.\n";
                       } 
                    else if (countChoice == 2) 
                       {
                         cout << "There is/are " <<discharge.count()<<" patient(s) in this list.\n";
                       } 
                    else 
                       {
                        cout << "Invalid queue choice.\n";
                       }
                break;

            case 8:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 8);

    return 0;
}          
                                               














