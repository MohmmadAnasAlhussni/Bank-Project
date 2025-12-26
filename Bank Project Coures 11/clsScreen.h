#pragma once
#include<iostream>
using namespace std; 
#include "clsUser.h" ; 
#include "Global.h" ; 
#include "clsDate.h" ; 
class clsScreen
{
protected : 
	static void _DrawScreenHeader(string Title , string SubTitle=""){
		cout << "\t\t\t\t\t____________________________________________"; 
		cout <<"\n\n\t\t\t\t\t" << Title << "\n";
		if (SubTitle != "") {
			cout << "\n\t\t\t\t\t" << SubTitle ;
		}
		cout << "\n\t\t\t\t\t____________________________________________\n\n";
		cout << "\t\t\t\t\tUser : " << CurrentUser.UserName << endl;
		cout << "\t\t\t\t\tDate : " << clsDate::DateToString(clsDate())<<endl;
	}
	static bool CheckAccessRights(clsUser::enPermissions Permissions) {
		if (!CurrentUser.CheckAccessPermissions(Permissions)) {
			cout << "\t\t\t\t\t____________________________________________";
			cout << "\n\n\t\t\t\t\t Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t____________________________________________\n";
			return false; 
		}
		return true; 
	}
	
};

