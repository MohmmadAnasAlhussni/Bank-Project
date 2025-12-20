#include <iostream>
#include "clsString.h"; 
#include "clsDate.h" ; 
#include "clsUtitl.h" ; 
#include "clsInputValidate.h" ;
using namespace std; 
int main()
{
	cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl; 
	cout << clsInputValidate::IsNumberBetween(2.5, 3.2, 4.5) << endl; 
	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(8, 12, 2022), clsDate(31, 12, 2022)) << endl; 
	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(31, 12, 2022) , clsDate(8, 12, 2022) ) << endl;
	cout << "Please Enter a Number :\n"; 
	int x = clsInputValidate::ReadIntNumber("Invaild Number,Enter agin\n"); 
	cout << "x=" << x << endl;
	cout << "Please Enter Number between 1 and 5 :\n"; 
	int y = clsInputValidate::ReadIntNumberBetween(1, 5, "Number is not within range"); 
	cout << "y=" << y << endl; 
	cout << "Please Enter a Double Number :\n";
	double a = clsInputValidate::ReadDblNumber("Invaild Number,Enter agin\n");
	cout << "a=" << a<<endl;
	cout << "Please Enter a Double Number between 1 and 5 :\n";
	double b = clsInputValidate::ReadDblNumberBetween(1, 5, "Number is not within range"); 
	cout << "b=" << b; 
	cout << endl << clsInputValidate::IsValidDate(clsDate(35, 12, 2022)); 
}

