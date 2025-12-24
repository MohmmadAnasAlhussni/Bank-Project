#pragma once
#include "clsScreen.h" ; 
#include "clsInputValidate.h" ; 
#include "clsUser.h" ; 
class clsUpdateUserScreen : protected clsScreen
{
	static void _ReadUserInfo(clsUser& User) {
		cout << "\n Enter FirstName : ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\n Enter LastName : ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\n Enter Email : ";
		User.Email = clsInputValidate::ReadString();
		cout << "\n Enter Phone : ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Password : ";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter Permission : ";
		User.Permissions = _ReadPermissionsToSet();
	}
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
	static int _ReadPermissionsToSet() {
		int Permissions = 0;
		char Answer = 'n';
		cout << "\nDo You Want to give Full access?y/n?";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			return -1;
		}
		cout << "\nDo you want to give access to : \n";
		cout << "\n Show Client List ? y/n?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUser::enPermissions::pListClients;
		}
		cout << "\nAdd New Client?y/n?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUser::enPermissions::pAddNewClient;
		}
		cout << "\nDelete Client?y/n?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUser::enPermissions::pDeleteClient;
		}
		cout << "\nUpdate Client?y/n?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUser::enPermissions::pUpdateClient;
		}
		cout << "\nFind Client?y/n?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUser::enPermissions::pFindClient;
		}
		cout << "\nTransaction?y/n?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUser::enPermissions::pTransaction;
		}
		cout << "\nMange Users?y/n?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			Permissions += clsUser::enPermissions::pMangeUsers;
		}
		return Permissions;
	}
public : 
	static void ShowUpdateUserScreen() {
		_DrawScreenHeader("\tUpdate User Screen"); 
		cout << "\nPlease Enter User Name : "; 
		string UserName = clsInputValidate::ReadString(); 
		while (!clsUser::IsUserExist(UserName)) {
			cout << "\nUserName is not found choose another one : ";
			UserName = clsInputValidate::ReadString(); 
		}
		clsUser User = clsUser::Find(UserName); 
		_PrintUser(User); 
		char Answer = 'n'; 
		cout << "Are you Sure Update This User ? y/n?";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			cout << "Update Client Info :";
			cout << "\n__________________\n";
			_ReadUserInfo(User);
			clsUser::enSaveResult SaveResult; 
			SaveResult = User.Save(); 
			
			switch (SaveResult)
			{
			case clsUser::svFaildEmptyObject:
				cout << "\nError UserName was not saved because it's Empty";
				break;
			case clsUser::svSuccessded:
				cout << "\nUser Updated Successfully :-)\n";
				_PrintUser(User);
				break;
			}
		}
	}
};

