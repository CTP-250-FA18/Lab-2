/** Client application that reads wealth data from a file, creates
  *     a Billionaire object for each person listed,
  *     and adds the object to an array.
  * The array of Billionaire objects is displayed, particular statistics
  *     are calculated and displayed.
  * 
  * @author Prof Gregory
  * @author YOUR NAME
  */
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Billionaire.h"

using namespace std;  // You may comment out this line and use std:: instead

// Any prototypes? 

int main()
{
    const string FILENAME = "WealthyTechies.csv";
	const int COUNT = 30;
	Billionaire billionaire[COUNT];   
	
	// Load billionaire array with Billionaire objects read from data file
	readFile(FILENAME,billionaire,COUNT);
	
	// Display the array of Billionaire objects
	displayAll(billionaire,COUNT);
	cout << endl;
	
	// Determine the range of wealth values and display
	float low;
	float high;
	getRange(billionaire,COUNT,low,high);
	cout << "The wealth of the billionaires range from $" << low 
	     << "B to $" << high << "B" << endl;
		  
	// Determine the wealthiest Billionaire and display
	Billionaire richPerson = getWealthiest(billionaire,COUNT);
	cout << "The wealthiest technology person is " << endl;
	richPerson.printBillionaire();
	
	// Determine how many are from the US and display
	int usTotal = getUS(billionaire, COUNT);
	cout << "There are " << usTotal << " US billionaires in the top 30!";
	
	return 0;
}
