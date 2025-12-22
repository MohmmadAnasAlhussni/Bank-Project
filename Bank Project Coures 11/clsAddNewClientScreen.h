#pragma once
#include "clsScreen.h" ;
#include "clsInputValidate.h";
#include "clsBankClient.h" ; 
class clsAddNewClientScreen : protected clsScreen 
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
	static void ShowAddNewClientScreen() {
		_DrawScreenHeader("\t\tAdd New Client Screen");
		string AccountNumber; 
		cout << "\nPlease Enter Account Number"; 
		AccountNumber = clsInputValidate::ReadString(); 
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "Account Number Alerady Used,Choose another One : "; 
			AccountNumber = clsInputValidate::ReadString(); 
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber); 
		_ReadClientInfo(NewClient); 
		clsBankClient::enSaveResult SaveResult; 
		SaveResult = NewClient.Save(); 
		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError account was not saved because it's Empty"; 
			break;
		case clsBankClient::svSucceeded:
			cout << "\nAccount Added Successfully :-)\n"; 
			//No UI Related code iside object . 
			_PrintClient(NewClient); 
			break;
		case clsBankClient::svFaildAccountNumberExists:
			cout << "Error Account was not saved becauce account number is used!\n"; 
			break;
		default:
			break;
		}
	}
};

