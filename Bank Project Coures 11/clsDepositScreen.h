#pragma once
#include "clsScreen.h" ; 
#include "clsInputValidate.h" ; 
class clsDepositScreen : protected clsScreen
{
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
	static void ShowDepositScreen() {
		_DrawScreenHeader("\tDeposit Screen"); 
		
		string AccountNumber = _ReadAccountNumber(); 
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber(); 
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber); 
		_PrintClient(Client); 
		double Amount = 0; 
		cout << "Please Enter deposit Amount ?"; 
		Amount = clsInputValidate::ReadDblNumber(); 
		char Answer = 'n'; 
		cout << "\nAre You Sure you want to perform  This Transactions ?"; 
		cin >> Answer; 
		if (Answer == 'y' || Answer == 'Y') {
			Client.Deposit(Amount); 
				cout << "Amount Deposit Successfully\n"; 
				cout << "New Balance Is : " << Client.AccountBalance << "\n";
		}
		else {
			cout << "Operation was cancelled.\n";
		}
	}
};

