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
void DeleteClient() {
	string AccountNumber; 
	cout << "Please Enter Account Number :"; 
	AccountNumber = clsInputValidate::ReadString(); 
	while (!clsBankClient::IsClientExist(AccountNumber)) {
		cout << " Account Number is not found ,choose another one :";
		AccountNumber = clsInputValidate::ReadString(); 
	}
	clsBankClient Client = clsBankClient::Find(AccountNumber); 
	Client.Print(); 
	cout << "\nAre You Sure you want Delete this Client?y/n?"; 
	char Answer = 'n';
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y') {
		if (Client.Delelte()) {
			cout << "Client Delete Successfully :-)"; 
			Client.Print();
		}
		else {
			cout << "Error Client was not Delete\n"; 
		}
	}
}
int main()
{
	DeleteClient(); 
	system("pause>0"); 
	return 0; 
}

