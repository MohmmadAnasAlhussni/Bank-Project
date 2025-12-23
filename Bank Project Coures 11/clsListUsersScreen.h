#pragma once
#include "clsScreen.h" ; 
#include "clsUser.h"  ; 
#include <vector>
#include <string>
class clsListUsersScreen : protected clsScreen
{
private : 
	static void _PrintUserRecordLine(clsUser User) {
		cout << setw(8) << left << "" << "| " << left << setw(15) << User.UserName;


		cout << "| " << left << setw(20) << User.FullName();


		cout << "| " << left << setw(12) << User.Phone;


		cout << "| " << left << setw(25) << User.Email;


		cout << "| " << left << setw(10) << User.Password;


		cout << "| " << left << setw(18) << User.Permissions;
	}
public : 
	static void ShowUsersList() {
		vector<clsUser>vUser = clsUser::GetUserList(); 
		string Title = "\t User List Screen"; 
		string SubTitle = "\t    (" + to_string(vUser.size()) + "User(s)\n";
		_DrawScreenHeader(Title, SubTitle); 
		cout << setw(8) << left << "" << "\n\t________________________________";
		cout << "__________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(18) << "Permissions";
		cout << setw(8) << left << "" << "\n\t________________________________";
		cout << "__________________________________________________________________\n" << endl;
		if (vUser.size() == 0) 
			cout << "\t\t\t\tNo Users Available in the System\n";
		
		else 
			for (clsUser User : vUser) {
				_PrintUserRecordLine(User); 
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t________________________________";
		cout << "__________________________________________________________________\n" << endl;


	}
};

