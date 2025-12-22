#include <iostream>
#include "clsInputValidate.h" ; 
#include "clsBankClient.h" ;
#include <iomanip>
#include "clsUtitl.h" ; 
using namespace std;
void PrintBalanceRecourdLine(clsBankClient Client) {
	cout << "| " << left << setw(15) << Client.AccountNumber();
	cout << "| " << left << setw(50) << Client.FullName();
	cout << "| " << left << setw(49) << Client.AccountBalance;
}
void ShowTotalBalances() {
	vector<clsBankClient>vClients = clsBankClient::GetClientsList(); 
	cout << "\n\t\t\t\tBalances List (" << vClients.size() << ") Client(s)"; 
	cout << "\n________________________________________________";
	cout << "_________________________________________\n" << endl; 
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(50) << "Client Name";
	cout << "| " << left << setw(49) << "Balance";
	cout << "\n________________________________________________";
	cout << "_________________________________________\n" << endl;
	double TotalBalances = clsBankClient::GetTotalBalances(); 
	if (vClients.size() == 0) {
		cout << "\t\t\t\tNo Clients  Avalible in the System\n";
	}
	else {
		for (clsBankClient& Client : vClients) {
			PrintBalanceRecourdLine(Client); 
		}
	}
	cout << "\n________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "\t\t\t\tTotalBalances = " << TotalBalances << "\n";
	cout << "\t\t\t\t(" << clsUtitl::NumberToText(TotalBalances)<<")";
}
int main()
{
	ShowTotalBalances(); 
	system("pause>0"); 
	return 0; 
}

