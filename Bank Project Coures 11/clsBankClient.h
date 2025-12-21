#pragma once
#include "clsPerson.h" ;
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h" ;
class clsBankClient : public clsPerson 
{
private : 
	enum enMode {EmptyMode = 0 , UpdateMode = 1};
	enMode _Mode; 
	string _AccountNumber; 
	string _PinCode;
	double _AccountBalance; 
	// Abstraction Method (Hidding Methode To Object )  
	static clsBankClient _ConvertLineToClientObject(string Line , string Seperator="#//#") {
		vector<string>vClientData; 
		vClientData = clsString::Split(Line, Seperator); 
		return clsBankClient(enMode::UpdateMode,vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6])); 
	}
	static clsBankClient _GetEmptyClient() {
		return clsBankClient(enMode::EmptyMode,"", "", "", "", "", "", 0);
	}
public : 
	clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode; 
		_AccountNumber = AccountNumber; 
		_PinCode = PinCode; 
		_AccountBalance = AccountBalance; 
	}
	// get Mode 
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	string AccountNumber() {
		return _AccountNumber; 
	}
	void setPinCode(string PinCode) {
		_PinCode = PinCode; 
	}
	string getPinCode() {
		return _PinCode; 
	}
	__declspec(property(get = getPinCode, put = setPinCode))string PinCode; 
	void setAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance; 
	}
	double getAccountBalance() {
		return _AccountBalance; 
	}
	__declspec(property(get = getAccountBalance,put = setAccountBalance))double AccountBalance; 
	 static clsBankClient Find(string AccountNumber) {
		
		fstream MyFile;
		MyFile.open("Clients.txt",ios::in); 
		if (MyFile.is_open()) {
			string Line; 
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line); 
				if (Client.AccountNumber() == AccountNumber) {
					MyFile.close(); 
					return Client; 
				}
			}
			MyFile.close(); 
		}
		return _GetEmptyClient(); 
	}
	 static clsBankClient Find(string AccountNumber , string PinCode) {
		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::in);
		 if (MyFile.is_open()) {
			 string Line;
			 while (getline(MyFile, Line)) {
				 clsBankClient Client = _ConvertLineToClientObject(Line);
				 if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode) {
					 MyFile.close();
					 return Client;
				 }
			 }
			 MyFile.close();
		 }
		 return _GetEmptyClient();
	 }
	 void Print() {
		 cout << "Client Card : \n"; 
		 cout << "__________________________\n"; 
		 cout << "Firts Name     " << FirstName << endl; 
		 cout << "Last  Name     " << LastName << endl;
		 cout << "Full Name      " << FullName() << endl;
		 cout << "Email          " << Email << endl;
		 cout << "Phone          " << Phone << endl;
		 cout << "Account Number " << _AccountNumber << endl;
		 cout << "Pin Code       " << _PinCode << endl;
		 cout << "Account Balance" << _AccountBalance << endl;
		 cout << "__________________________\n";
	 }
	 static bool IsClientExist(string AccountNumber) {
		 clsBankClient Client = Find(AccountNumber);
		 return (!Client.IsEmpty());
	 }
};

