#include <iostream>
#include "clsInputValidate.h" ; 
#include "clsBankClient.h" ;
#include <iomanip>
using namespace std; 
void PrintClientRecoudLine(clsBankClient Client) {
	cout << "| " << left << setw(15) << Client.AccountNumber();
	cout << "| " << left << setw(20) << Client.FullName();
	cout << "| " << left << setw(12) << Client.Phone;
	cout << "| " << left << setw(20) << Client.Email;
	cout << "| " << left << setw(10) << Client.PinCode;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}
void ShowClientList() {
	vector<clsBankClient>vClient = clsBankClient::GetClientsList(); 
	cout << "\n\t\t\t\tClient List (" << vClient.size() << ") Client(s)\n";
	cout << "\n_____________________________________________";
	cout << "______________________________________________________\n" << endl; 
	cout << "| " << left << setw(15) << "Account Number "; 
	cout << "| " << left << setw(20) << "Client Name ";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "PinCode";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_____________________________________________";
	cout << "______________________________________________________\n" << endl;
	if (vClient.size() == 0) {
		cout << "\t\t\tNo Client Avalible in The System!";
	}
	else {
		for (clsBankClient& Client : vClient) {
			PrintClientRecoudLine(Client); 
			cout << endl; 
		}
		cout << "\n_____________________________________________";
		cout << "______________________________________________________\n" << endl;
	}
}
int main()
{
	ShowClientList();
	system("pause>0"); 
	return 0; 
}

