#pragma once
#include "clsInputValidate.h" ; 
#include "clsUser.h" ; 
#include"clsScreen.h" ; 
class clsFindUserScreen : protected clsScreen
{
private : 
	static void _PrintUser(clsUser User) {
		cout << "User Card : \n";
		cout << "__________________________\n";
		cout << "Firts Name     " << User.FirstName << endl;
		cout << "Last  Name     " << User.LastName << endl;
		cout << "Full Name      " << User.FullName() << endl;
		cout << "Email          " << User.Email << endl;
		cout << "Phone          " << User.Phone << endl;
		cout << "UserName       " << User.UserName << endl;
		cout << "Pasword        " << User.Password << endl;
		cout << "Permissions    " << User.Permissions << endl;
		cout << "__________________________\n";
	}
public:
	static void ShowFindUserScreen() {
		_DrawScreenHeader("\tFind User Screen"); 
		string UserName = "";
		cout << "Please Enter UserName : "; 
		UserName = clsInputValidate::ReadString(); 
		while (!clsUser::IsUserExist(UserName)) {
			cout << "\nUser Name is not found choose another one : ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName); 
		if (!User.IsEmpty()) {
			cout << "\nUser Found :-)\n";
		}
		else {
			cout << "\nUser Was not Found :-(\n";
		}
		_PrintUser(User);
	}
};

