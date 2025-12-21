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
void UpdateClient() {
	string AccountNumber; 
	cout << "Please Enter Client Account Number : "; 
	AccountNumber = clsInputValidate::ReadString(); 
	while (!clsBankClient::IsClientExist(AccountNumber)) {
		cout << "\nAccount number is not found, choose another one: ";
		AccountNumber = clsInputValidate::ReadString(); 
	}
	clsBankClient Client = clsBankClient::Find(AccountNumber); 
	Client.Print(); 
	cout << "Update Client Info :\n ";  
	ReadClientInfo(Client);
	clsBankClient::enSaveResult SaveResult; 
	SaveResult = Client.Save(); 
	switch (SaveResult)
	{
	case clsBankClient::svFaildEmptyObject:
		cout << "\nError account was not saved because it's Empty";
		break;
	case clsBankClient::svSucceeded:
		cout << "\nAccount Updated Successfully :-)\n";
		Client.Print();
		break;

	}
}
int main()
{
	UpdateClient(); 
	system("pause>0"); 
	return 0; 
}

