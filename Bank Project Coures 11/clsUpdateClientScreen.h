#pragma once
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsBankClient.h" ;
class clsUpdateClientScreen : protected clsScreen 
{
private : 
	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "First Name  : ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "Last Name  : ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "Email  : ";
		Client.Email = clsInputValidate::ReadString();
		cout << "Phone : ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "Password  : ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "Account Balance : ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();

	}
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
public : 
	static void ShowUpdatClientScreen() {
		_DrawScreenHeader("\tUpdate Client Screen"); 
		string AccountNumber = ""; 
		cout << "\nPlease Enter Account Number";
		AccountNumber = clsInputValidate::ReadString(); 
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number is not found choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber); 
		_PrintClient(Client); 
		char Answer = 'n';
		cout << "Are you Sure Update This Client ? y/n?";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			cout << "Update Client Info :"; 
			cout << "\n__________________\n"; 
			_ReadClientInfo(Client);
			clsBankClient::enSaveResult SaveResult;
			SaveResult = Client.Save();
			switch (SaveResult)
			{
			case clsBankClient::svFaildEmptyObject:
				cout << "\nError account was not saved because it's Empty";

				break;
			case clsBankClient::svSucceeded:
				cout << "Client Update Successfully\n";
				_PrintClient(Client);
				break;
			}
		}
	}
};

