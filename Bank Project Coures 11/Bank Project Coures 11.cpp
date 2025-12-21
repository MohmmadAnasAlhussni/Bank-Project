#include <iostream>
#include "clsInputValidate.h" ; 
#include "clsBankClient.h" ; 
using namespace std; 
void ReadClientInfo(clsBankClient& Client) {
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
void AddNewClient() {
	string AccountNumber; 
	cout << "Please Enter Account Number : "; 
	AccountNumber = clsInputValidate::ReadString(); 
	while (clsBankClient::IsClientExist(AccountNumber)) {
		cout << "\n Account Number Is Already Used, Choose another one :"; 
		AccountNumber = clsInputValidate::ReadString(); 
	}
	clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber); 
	ReadClientInfo(Client); 
	clsBankClient::enSaveResult SaveResult; 
	SaveResult = Client.Save();
	switch (SaveResult)
	{
	case clsBankClient::svFaildEmptyObject:
		cout << "\nError account was not saved because it's Empty";
		break;
	case clsBankClient::svSucceeded:

		cout << "\nAccount Addeded Successfully :-)\n";
		Client.Print();
		break;
	case clsBankClient::svFaildAccountNumberExists:
		cout << "\nError account was not saved because account number is used!\n";
		break;

	}
}
int main()
{
	AddNewClient();
	system("pause>0"); 
	return 0; 
}

