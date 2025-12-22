#pragma once
#include<iostream>
using namespace std; 
class clsScreen
{
protected : 
	static void _DrawScreenHeader(string Title , string SubTitle=""){
		cout << "\t\t\t\t\t____________________________________________\n\n"; 
		cout <<"\t\t\t\t\t" << Title << "\n";
		if (SubTitle != "") {
			cout << "\t\t\t\t" << SubTitle << endl;
		}
		cout << "\t\t\t\t\t____________________________________________\n\n";
	}
};

