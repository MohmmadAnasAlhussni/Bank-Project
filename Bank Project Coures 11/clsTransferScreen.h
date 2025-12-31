#pragma once
#include "clsScreen.h" ;
#include "clsInputValidate.h" ; 
#include "clsBankClient.h" ; 
class clsTransferScreen:protected clsScreen 
{
private : 
	static void _PrintClient(clsBankClient Client) {
		cout << "Client Card";
		cout << "\n____________________\n";
		cout << "FullName : " << Client.FullName() << endl;
		cout << "Acc.Number : " << Client.AccountNumber() << endl; 
		cout << "Balance : " << Client.AccountBalance;
		cout << "\n____________________\n";
	}
	static string _ReadAccountNumber() {
		string AccountNumber;
		cout << "Please Enter Account Number to Transfer From : "; 
		AccountNumber = clsInputValidate::ReadString(); 
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nUser Name is not found choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber; 
	}
	static float ReadAmount(clsBankClient SourcsClient) {
		float Amount; 
		cout << "\nEnter Transfer Amount?"; 
		Amount = clsInputValidate::ReadNumber<float>(); 
		while (Amount > SourcsClient.AccountBalance) {
			cout << "Amount Exceeds the available Balance , Enter Another Amount?";
			Amount = clsInputValidate::ReadNumber<float>();
		}
		return Amount; 
	}
public : 
	static void ShowTransferScreen() {
		_DrawScreenHeader("\tTransfer Screen"); 
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(SourceClient);
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber() );
		_PrintClient(DestinationClient); 
		float Amount = ReadAmount(SourceClient);
		cout << "\nAre you sure you want to perform this Transaction?y/n "; 
		char Answer = 'n'; 
		cin >> Answer; 
		if (Answer == 'y' || Answer == 'Y') {
			if (SourceClient.Transfer(Amount, DestinationClient , CurrentUser.UserName)) {
				cout << "\nTransfer done Successfully\n";
			}
			else {
				cout << "\nTransfer Faild\n"; 
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

