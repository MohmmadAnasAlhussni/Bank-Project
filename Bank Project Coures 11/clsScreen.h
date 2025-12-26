#pragma once
#include<iostream>
using namespace std; 
#include "clsUser.h" ; 
#include "Global.h" ; 
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
	//cout << "\n\n\t\t\t\t\t Access Denied! Contact Your Access";
};

