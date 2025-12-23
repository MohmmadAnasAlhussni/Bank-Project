#pragma once
#include "clsScreen.h" ; 
#include "clsBankClient.h";
#include <iomanip>
#include "clsUtitl.h" ; 

class clsTotalBalancesScreen : protected clsScreen
{
private : 
	static void _PrintClientRecourdBalanceLine(clsBankClient Client) {
		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName(); 
		cout << "| " << setw(12) << left << Client.AccountBalance;

	} 
public : 
	static void ShowTotalBalances() {
		vector<clsBankClient> vClients = clsBankClient::GetClientsList(); 
		string Title = "\t Balances List Screen"; 
		string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s)"; 
		_DrawScreenHeader(Title,SubTitle);
		cout << setw(25) << left << "" << "\n\t\t_______________________________________";
		cout << "_________________________________________\n\n"; 
		cout << setw(25) << left << "" << "| " << setw(15) << left << "Account Number";
		cout << "| " << setw(40) << left <<"Client Name";
		cout << "| " << setw(12) << left << "Balance";
		cout << setw(25) << left << "" << "\n\t\t_______________________________________";
		cout << "_________________________________________\n\n";
		double TotalBalances = clsBankClient::GetTotalBalances();
		if (vClients.size() == 0) {
			cout << "\t\t\t\tNo Clients Available In The System !\n"; 

		}
		else {
			for (clsBankClient Client : vClients) {
				_PrintClientRecourdBalanceLine(Client); 
				cout << endl; 
			}
		}
		cout << setw(25) << left << "" << "\n\t\t_______________________________________";
		cout << "_________________________________________\n\n";
		cout << setw(8) << left << "\t\t\t Total Balances = " << TotalBalances << "\n"; 
		cout << setw(8) << left << "\t\t\t ( " << clsUtitl::NumberToText(TotalBalances) << ")\n";
	}
};

