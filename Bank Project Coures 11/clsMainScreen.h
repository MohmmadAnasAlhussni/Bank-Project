#pragma once
#include "clsScreen.h" ; 
#include <iomanip>
#include "clsInputValidate.h"  ; 
#include "clsClientListScreen.h" ; 
#include "clsAddNewClientScreen.h" ; 
#include "clsDeleteClientScreen.h"  ; 
#include "clsUpdateClientScreen.h" ; 
#include "clsFindClientScreen.h" ; 
#include "clsTransactionScreen.h" ; 
#include "clsMangeUsersScreen.h" ; 
#include "Global.h" ; 

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenueOption {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eMangeUsers = 7, eExit = 8
	};

	static short _ReadMainMenueOption() {
		cout << setw(39) << left << "" << "Choose what do you want [1-8]?";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 8, "Enter Number between 1 to 8 ");
		return Choice;
	}
	static void _ShowAllClientsScreen() {
		//cout << "Client List Screen Will be here...\n"; 
		clsClientListScreen::ShowClientsList();
	}
	static void _ShowAddNewClientScreen() {
		//cout << "Add New Screen Will be here...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	static void _ShowDeleteClientScreen() {
		//cout << "Delete Client Screen Will be here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _ShowUpdateClientScreen() {
		//cout << "Update Client Screen Will be here...\n";
		clsUpdateClientScreen::ShowUpdatClientScreen();
	}
	static void _ShowFindClientScreen() {
		//cout << "Find Client Screen Will be here...\n";
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionMenue() {
		//cout << "Transaction Menue Screen Will be here...\n";
		clsTransactionScreen::ShowTransactionsMenue();

	}
	static void _ShowMangeUserMenue() {
		//cout << "Mange User Screen Will be here...\n";
		clsMangeUsersScreen::ShowMangeUsersMenue();
	}
	//static void _ShowEndScreen() {
	//	cout << "End Screen"; 
	//}
	static void _Logout() {
		CurrentUser = clsUser::Find("", ""); 
		//	clsLoginScreen::ShowLoginScreen();
		//then it will go back to main function  
	}
	static void _GoToBackMainMenue() {
		cout << "Press any key to go back to Main Menue... ";
		system("pause>0"); 
		ShowMainMenue(); 
	}


	static void _PerformMainMenueOption(enMainMenueOption MainMenueOption) {
		switch (MainMenueOption)
		{
		case clsMainScreen::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoToBackMainMenue();
			break;
		}

		case clsMainScreen::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoToBackMainMenue();
			break;
		}
		case clsMainScreen::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoToBackMainMenue();
			break;
		}
		case clsMainScreen::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoToBackMainMenue();
			break;
		}
		case clsMainScreen::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoToBackMainMenue();
			break;
		}
		case clsMainScreen::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionMenue();
			_GoToBackMainMenue();
			break;
		}
		case clsMainScreen::eMangeUsers:
		{
			system("cls");
			_ShowMangeUserMenue();
			_GoToBackMainMenue();
			break;
		}
		case clsMainScreen::eExit:
		{
			system("cls");
			//_ShowEndScreen();
			_Logout(); 
			
		
			break;
		}
		}
	}
public : 
	static void ShowMainMenue() {
		system("cls"); 
		_DrawScreenHeader("\t\tMain Screen"); 
		
		cout << setw(39) << left << "" << "=============================================\n"; 
		cout << setw(39) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(39) << left << "" << "=============================================\n";
		cout << setw(39) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(39) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(39) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(39) << left << "" << "\t[4] Update Client.\n";
		cout << setw(39) << left << "" << "\t[5] Find Client.\n";
		cout << setw(39) << left << "" << "\t[6] Transactions.\n";
		cout << setw(39) << left << "" << "\t[7] Mange Users.\n";
		cout << setw(39) << left << "" << "\t[8] Logout.\n";
		cout << setw(39) << left << "" << "=============================================\n";
		_PerformMainMenueOption((enMainMenueOption)_ReadMainMenueOption()); 

	}
};

