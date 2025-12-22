#pragma once
#include "clsScreen.h" ; 
#include "clsInputValidate.h" ;
class clsDeleteClientScreen : protected clsScreen 
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
public : 
	static void ShowDeleteClientScreen() {
		_DrawScreenHeader("\tDelete Client Screen"); 
		string AccountNumber="";
		cout << "Please Enter Account Number :"; 
		AccountNumber = clsInputValidate::ReadString(); 
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number is not found choose another one : "; 
			AccountNumber = clsInputValidate::ReadString(); 
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber); 
		_PrintClient(Client); 
		char Answer = 'n'; 
		cout << "Are you Sure Delete This Client ? y/n?"; 
		cin >> Answer; 
		if (Answer == 'Y' || Answer == 'y') {
			if (Client.Delelte()) {
				cout << "Delete Client Successfully :-)"; 
				_PrintClient(Client); 
			}
			else {
				cout << "Error Client Was not Deleted\n"; 
			}
		}
	}
};

