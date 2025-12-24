#pragma once
#include "clsUser.h" ; 
#include "clsInputValidate.h" ; 
#include "clsScreen.h" ; 
class clsAddNewUserScreen : protected clsScreen
{
	static void _ReadUserInfo(clsUser& User) {
		cout << "\n Enter FirstName : "; 
		User.FirstName = clsInputValidate::ReadString(); 
		cout << "\n Enter LastName : ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\n Enter Email : ";
		User.Email= clsInputValidate::ReadString();
		cout << "\n Enter Phone : ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Password : "; 
		User.Password = clsInputValidate::ReadString(); 
		cout << "\nEnter Permission : ";
		User.Permissions = _ReadPermissionsToSet() ;

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
	static void ShowAddNewUserScreen() {
		_DrawScreenHeader("\t Add New User Screen"); 
		string UserName = ""; 
		cout << "\nPlease Enter UserName : ";
		UserName = clsInputValidate::ReadString(); 
		while (clsUser::IsUserExist(UserName)) {
			cout << "\nUserName Is Already Used Choose another one : "; 
			UserName = clsInputValidate::ReadString(); 
		}
		clsUser NewUser = clsUser::GetAddNewUserObject(UserName); 
		_ReadUserInfo(NewUser);
		clsUser::enSaveResult SaveResult; 
		SaveResult = NewUser.Save(); 
		switch (SaveResult)
		{
		case clsUser::svFaildEmptyObject:	
			cout << "\nError UserName was not saved because it's Empty";
			break;
		case clsUser::svSuccessded:
			cout << "\nUser Added Successfully :-)\n";
			_PrintUser(NewUser); 
			break;
		case clsUser::svFaildUserExists:
			cout << "Error UserName was not saved becauce UserName is used!\n";
			break;
		default:
			break;
		}
	}
};

