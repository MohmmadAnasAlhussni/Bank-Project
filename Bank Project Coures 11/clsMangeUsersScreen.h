#pragma once
#include "clsScreen.h";
#include "clsInputValidate.h" ; 
#include "clsListUsersScreen.h" ; 
#include "clsAddNewUserScreen.h" ;  
#include "clsDeleteUserScreen.h" ; 
#include "clsUpdateUserScreen.h" ; 
class clsMangeUsersScreen : protected clsScreen
{
private : 
	enum enMangeUserOptions {
		eListUsers = 1 ,eAddNewUser = 2 , eDeleteUser =3 , eUpdateUser = 4 , 
		eFindUser = 5 ,eMainMenue =6 
	};
	static short _ReadMangeUserMenueOption() {
		cout << setw(39) << left << "" << "Choose what do you want [1-6]?";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6 ");
		return Choice;
	}
	static void _ShowListUsersScreen() {
	//	cout << "\nList Users Screen Will be here...\n"; 
		clsListUsersScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen() {
	//	cout << "Add New User Screen Will be here...\n";
		clsAddNewUserScreen::ShowAddNewUserScreen(); 
	}
	static void _ShowDeleteUserScreen() {
	//	cout << "Delete User Screen Will be here...\n";
		clsDeleteUserScreen::ShowDeleteUserScreen(); 
	}
	static void _ShowUpdateUserScreen() {
	//	cout << "Update User Screen Will be here...\n";
		clsUpdateUserScreen::ShowUpdateUserScreen(); 
	}
	static void _ShowFindUserScreen() {
		cout << "Find User Screen Will be here...\n";
	}
	static void _GoBackToMangeUsersMenue(){
		cout << "Press any key to go back to Mange User Menue... ";
		system("pause>0");
		ShowMangeUsersMenue();
	}
	static void _PerformMangeUsersOption(enMangeUserOptions MangeUserOptions) {
		switch (MangeUserOptions)
		{
		case enMangeUserOptions::eListUsers:
		{
			system("cls"); 
			_ShowListUsersScreen();
			_GoBackToMangeUsersMenue(); 
			break;
		}
		case enMangeUserOptions::eAddNewUser:
		{
			system("cls"); 
			_ShowAddNewUserScreen(); 
			_GoBackToMangeUsersMenue(); 
			break;
		}
		case enMangeUserOptions::eDeleteUser:
		{
			system("cls"); 
			_ShowDeleteUserScreen(); 
			_GoBackToMangeUsersMenue(); 
			break;
		}

		case clsMangeUsersScreen::eUpdateUser:
		{
			system("cls"); 
			_ShowUpdateUserScreen(); 
			_GoBackToMangeUsersMenue(); 
			break;
		}
		case clsMangeUsersScreen::eFindUser:
		{
			system("cls"); 
			_ShowFindUserScreen(); 
			_GoBackToMangeUsersMenue(); 
			break;
		}
		case clsMangeUsersScreen::eMainMenue:
			break;
		}
	}
public : 
	static void ShowMangeUsersMenue() {
		system("cls");  
		_DrawScreenHeader("\t\tMange User Screen"); 
		cout << setw(39) << left << "" << "=============================================\n";
		cout << setw(39) << left << "" << "\t\t\tMange User Menue\n";
		cout << setw(39) << left << "" << "=============================================\n";
		cout << setw(39) << left << "" << "\t[1] List Users.\n";
		cout << setw(39) << left << "" << "\t[2] Add New User.\n";
		cout << setw(39) << left << "" << "\t[3] Delete User.\n";
		cout << setw(39) << left << "" << "\t[4] Update User.\n";
		cout << setw(39) << left << "" << "\t[5] Find Find.\n";
		cout << setw(39) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(39) << left << "" << "=============================================\n";
		_PerformMangeUsersOption((enMangeUserOptions)_ReadMangeUserMenueOption()); 
	}
};

