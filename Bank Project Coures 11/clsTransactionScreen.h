#pragma once
#include "clsScreen.h" ;
#include <iomanip>
#include "clsInputValidate.h" ; 
#include "clsDepositScreen.h" ; 
#include "clsWithdrawScreen.h";
#include "clsTotalBalancesScreen.h" ; 
#include "clsTransferScreen.h";
#include "TransfarLogScreen.h"; 
class clsTransactionScreen : protected clsScreen
{
private:
	enum enTransactionMenueOption {
		eDeposit = 1, eWithDraw = 2,
		eShowTotalBalances = 3,
		eShowTransfer = 4 ,
		eTransferLog = 5 ,
		eShowMainMenue = 6
	};
	static short _ReadTransactionMenueOption() {
		cout << setw(39) << left << "" << "Choose what do you want [1-6]?";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6 ");
		return Choice;
	}
	static void _ShowDepositsScreen() {
		//cout << "Deposit  Screen Will be here...\n";
		clsDepositScreen::ShowDepositScreen(); 
	}
	static void _ShowWithdrawScreen() {
		//cout << "WithDraw  Screen Will be here...\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalancesScreen() {
		//cout << "Total Balances  Screen Will be here...\n";
		clsTotalBalancesScreen::ShowTotalBalances();
	}
	static void _ShowTransferScreen() {
		//cout << "Show Transfer Screen Will be here...\n"; 
		clsTransferScreen::ShowTransferScreen(); 
	}
	static void _ShowTransfarLogScreen() {
		clsTransfarLogScreen::ShowTransfarLogScreen();
	}
	static void _GoToBackTrasnctionMenue() {
		cout << "\nPress any key to go back to Transaction Menue... ";
		system("pause>0");
		ShowTransactionsMenue();
	}
	
	static void _PerformTransactionMenueOption(enTransactionMenueOption TransactionMenue) {

		switch (TransactionMenue)
		{
		case enTransactionMenueOption::eDeposit:
		{
			system("cls");
			_ShowDepositsScreen();
			_GoToBackTrasnctionMenue();
			break;
		}
		case enTransactionMenueOption::eWithDraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoToBackTrasnctionMenue();
			break;
		}
		case enTransactionMenueOption::eShowTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoToBackTrasnctionMenue();
			break;
		}
		case enTransactionMenueOption::eShowTransfer : 
		{
			system("cls");
			_ShowTransferScreen();
			_GoToBackTrasnctionMenue(); 
			break; 
		}
		case enTransactionMenueOption::eTransferLog: {
			system("cls"); 
			_ShowTransfarLogScreen(); 
			_GoToBackTrasnctionMenue(); 
		}
		case enTransactionMenueOption::eShowMainMenue:
		{
	
			
		}

		}
	}
public:
	static void ShowTransactionsMenue() {
		if (!CheckAccessRights(clsUser::enPermissions::pTransaction)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("\tTransactions Screen");
		
		cout << setw(39) << left << "" << "=============================================\n";
		cout << setw(39) << left << "" << "\t\t\tTransaction Menue\n";
		cout << setw(39) << left << "" << "=============================================\n";
		cout << setw(39) << left << "" << "\t[1] Deposit.\n";
		cout << setw(39) << left << "" << "\t[2] WithDraw.\n";
		cout << setw(39) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(39) << left << "" << "\t[4] Transfer.\n";
		cout << setw(39) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(39) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(39) << left << "" << "=============================================\n";
		_PerformTransactionMenueOption((enTransactionMenueOption)_ReadTransactionMenueOption());
	}
	
}; 
