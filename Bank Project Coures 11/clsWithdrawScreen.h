#pragma once
#include "clsScreen.h" ; 
class clsWithdrawScreen : protected clsScreen
{
private : 
	static void _PrintClient(clsBankClient Client) {
		cout << "Client Card : \n";
		cout << "__________________________\n";
		cout << "Firts Name     " << Client.FirstName << endl;
		cout << "Last  Name     " << Client.LastName << endl;
		cout << "Full Name      " << Client.FullName() << endl;
		cout << "Email          " << Client.Email << endl;
		cout << "Phone          " << Client.Phone << endl;
		cout << "Account Number " << Client.AccountNumber() << endl;
		cout << "Pin Code       " << Client.PinCode << endl;
		cout << "Account Balance" << Client.AccountBalance << endl;
		cout << "__________________________\n";
	}
	static string _ReadAccountNumber() {
		cout << "Please Enter Account Number ? ";
		string AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}
public : 
	static void ShowWithdrawScreen() {
		_DrawScreenHeader("\t Withdraw Screen"); 
		string AccountNumber = _ReadAccountNumber(); 
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nClient With [" << AccountNumber << "]dose not exist.\n"; 
			AccountNumber = _ReadAccountNumber(); 
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber); 
		_PrintClient(Client); 
		double Amount = 0; 
		cout << "Please Enter deposit Amount ?";
		Amount = clsInputValidate::ReadDblNumber(); 
		cout << "\nAre You Sure you want to perform  This Transactions ?";
		char Answer = 'n'; 
		cin >> Answer; 
		if (Answer == 'Y' || Answer == 'y') {
			if (Client.Withdraw(Amount)) {
				cout << "\nAmount Withdraw Successfully.\n";
				cout << "\nNew Balance Is:" << Client.AccountBalance; 
			}else {
				cout << "\nCannot withdraw, Insuffecient Balance!\n"; 
				cout << "\nAmount to withdraw is : " << Amount;
				cout << "\nYour Balance is : " << Client.AccountBalance; 
			}
		}
		else {
			cout << "\nOperation was cancelled.\n"; 
		}
	}
};

