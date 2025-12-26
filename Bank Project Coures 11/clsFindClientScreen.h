#pragma once
#include "clsScreen.h";
#include "clsInputValidate.h";
class clsFindClientScreen : protected clsScreen
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
	static void ShowFindClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pListClients)) {
			return;
		}
		_DrawScreenHeader("\tFind Client Screen"); 
		string AccountNumber = ""; 
		cout << "\nPlease Enter Account Number"; 
		AccountNumber = clsInputValidate::ReadString(); 
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number is not found choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		if (!Client.IsEmpty()) {
			cout << "\nClient Found :-)"; 
		}
		else {
			cout << "\nClient Was not Found :-("; 
		}
		_PrintClient(Client); 
	}
};

