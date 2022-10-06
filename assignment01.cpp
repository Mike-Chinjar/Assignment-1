#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    //Init Variables, variables entered with "Input" are direct unprocessed inputs, "Data" is post processed information
    double hoursUsedInput = -1, planA, planB, planC, smallA_B, SmallResult_C, smallest, currentPlanCost;
    int monthNum = 1, strln = 0, hoursUsedData;
    char currentPlanInput, currentPlanData;
    string monthInput, monthDataChar, monthData;
    string monthArray[14] = {"null","jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec","null"};
    int hoursArray[14] = {0,744,672,744,720,744,720,744,744,720,744,720,744,0};

    //Rates which can be changed if prices of phone plans change
    double planAOverageRate = 2.00; 
    double planAFlatFee = 9.95;
    double planAHoursIncluded = 10;

    double planBOverageRate = 1.00;
    double planBFlatFee = 14.95;
    double planBHoursIncluded = 20;

    double planCFlatFee = 19.95;  

    


    //User information
    cout << "\nThis is a program developed to help you select a phone plan." << endl;
    cout << "It will input your hours and current phone plan and tell you if switching would save you money." << endl;




    //Ask user for tolal hours used expressed as Int 
    cout << "\nPlease enter how many hours you use per month: ";
    cin >> hoursUsedInput;

    //Checks if hours is negative
    while (hoursUsedInput < 0){
        cout << "\nInvalid Hours.\n";
        cout << "\nPlease enter how many hours you use per month: ";
        cin >> hoursUsedInput;
    }

    //Rounds to the next biggest INT and stores in var hoursUsedData
    hoursUsedData = ceil(hoursUsedInput);




    //Gets Month as a string
    cout << "\nPlease enter the first 3 letters of the month: ";
    cin >> monthInput;

    //Calculate lenght of month string entered
    for (int i = 0; monthInput[i] != '\0'; i++)
    {
        strln += 1;
    }

    //Converts month to a standard system (all lower)
    for (int i = 0; i < strln; i++)
    {
        monthDataChar = tolower(monthInput[i]);
        monthData = monthData + monthDataChar;
    }


    //Finds which number month user entered, expressed as int, with 1 = Jan, 12 = Dec
    for (int i = 1; monthData != monthArray[i]; i++ )
    {
        monthNum += 1;
        //Ensures that the month input is valid, if not, ends program, stops loop from continuing forever
        if (monthNum > 12 || monthNum < 0){
            cout << "\n\nError Please Rerun and enter a valid month.\n" << endl;
            return 0;
        }
    }
    
    


    //Checks if hoursUsed is logical, exits program if not (maybe put everything in a while loop so the program doesnt have to end)
    if (hoursUsedData > hoursArray[monthNum])
    {
        cout << "\n\nYou have entered more hours than are in that month.\n" << endl;
        return 0;
    }




    //Display Phone plan options and ask which is being used
    cout << "\nOur company provides 3 phone plans, please read the information and type which plan you currently use, A, B, or C." << endl;
    cout << "A: $9.95/Month with 10 hours of calling included, additional hours are rated at $2.00/Hour." << endl;
    cout << "B: $14.95/Month with 20 hours of calling included, additional hours are rated at $1.00/Hour." << endl;
    cout << "C: $19.95/Month with unlimited calling included." << endl;




    //Get Char from user on which plan is being used
    cout << "\nPlease enter which plan you currently are using: ";
    cin >> currentPlanInput;

    //Converts Char input to a standard system
    currentPlanData = tolower(currentPlanInput);

    //check if currentPlanData is valid
    while((currentPlanData < 97 || currentPlanData > 99))
    {
        cout << "\nPlease enter a valid character." << endl;
        cin >> currentPlanInput;
        currentPlanData = tolower(currentPlanInput);
    }




    //Calculate price for Plan A
    if(hoursUsedData > planAHoursIncluded)
    {
        planA = (hoursUsedData - planAHoursIncluded) * planAOverageRate + planAFlatFee;
    }
    else
    {
        planA = planAFlatFee;
    }

    //Calculate price for Plan B
    if(hoursUsedData > planBHoursIncluded)
    {
        planB = (hoursUsedData - planBHoursIncluded) * planBOverageRate + planBFlatFee;
    }
    else
    {
        planB = planBFlatFee;
    }

    //Calculate price for Plan C
    planC = planCFlatFee;




    //Display to User current plan and other plan prices
    switch (currentPlanData)
    {
        case 97:
            cout << "\nYou are currently using plan A, For $" << planA << "/month." << endl;
            cout << "Switching to plan B would cost you $" << planB << "/month instead." << endl;
            cout << "Switching to plan C would cost you $" << planC << "/month instead." << endl;
            currentPlanCost = planA;
            break;
        case 98:
            cout << "\nYou are currently using plan B, For $" << planB << "/month." << endl;
            cout << "Switching to plan A would cost you $" << planA << "/month instead." << endl;
            cout << "Switching to plan C would cost you $" << planC << "/month instead." << endl;
            currentPlanCost = planB;
            break;
        case 99:
            cout << "\nYou are currently using plan C, For $" << planC << "/month." << endl;
            cout << "Switching to plan A would cost you $" << planA << "/month instead." << endl;
            cout << "Switching to plan B would cost you $" << planB << "/month instead." << endl;
            currentPlanCost = planC;
            break;
    }




    //Returns smallest value of 3 plans as double stored in var smallest
    smallA_B = std::min(planA, planB);
    SmallResult_C = std::min(smallA_B, planC);
    smallest = SmallResult_C;




    //Checks which plan is cheapest and whether to switch or not
    if (smallest == planA)
    {
        if(currentPlanData != 97)
        {
            cout << "\nYou should switch to plan A, it's only $" << planA << " instead of $" << currentPlanCost << endl; 
        } 
        else 
        {
            cout << "\nYou already have the best plan for your case" << endl;
        }
    }
    else if (smallest == planB)
    {
         if(currentPlanData != 98)
        {
            cout << "\nYou should switch to plan B, it's only $" << planB << " instead of $" << currentPlanCost << endl; 
        } 
        else 
        {
            cout << "\nYou already have the best plan for your case" << endl;
        }
    }
    else if (smallest == planC)
    {
         if(currentPlanData != 99)
        {
            cout << "\nYou should switch to plan C, it's only $" << planC << " instead of $" << currentPlanCost << endl; 
        } 
        else 
        {
            cout << "\nYou already have the best plan for your case" << endl;
        }
    }
    




/*  Development Tools:
    cout << "\n\n\n\n\n";
    cout << monthData << " is " << strln << " char long." <<endl;
    cout << "It is the " << monthNum << " month of the year." << endl;
    cout << "You used " << hoursUsedData << " hours." << endl;
    cout << "you are using plan " << currentPlanData << endl;
*/




    return 0;
}