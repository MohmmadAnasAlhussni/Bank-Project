#pragma once
#include "clsScreen.h" ; 
#include "clsInputValidate.h" ; 
#include "clsUser.h" ; 
class clsDeleteUserScreen : protected clsScreen 
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
public : 
	static void ShowDeleteUserScreen() {
		_DrawScreenHeader("\tDelete User Screen"); 
		cout << "\nPlease Enter UserName : "; 
		string UserName = clsInputValidate::ReadString(); 
		while (!clsUser::IsUserExist(UserName)) {
		cout << "\nUser is not found choose another one : ";
		UserName = clsInputValidate::ReadString(); 
		}
		clsUser User = clsUser::Find(UserName); 
		_PrintUser(User); 
		char Answer = 'n';
		cout << "Are you Sure Delete This User ? y/n?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			if (User.Delete()) {
				cout << "\nDelete User Successfully :-)\n";
				_PrintUser(User);
			}
			else {
				cout << "Error User Was not Deleted\n";
			}
		}
	}
};

