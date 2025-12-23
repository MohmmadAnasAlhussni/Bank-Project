#pragma once
#include "clsPerson.h" ;
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h" ;
class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 ,	AddNewMode = 2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete = false; 

	// Abstraction Method (Hidding Methode To Object )  
	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#") {
		vector<string>vClientData;
		vClientData = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}
	
	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#") {
		string DataLine="";
		DataLine += Client.FirstName + Seperator; 
		DataLine += Client.LastName + Seperator; 
		DataLine += Client.Email + Seperator; 
		DataLine += Client.Phone + Seperator; 
		DataLine += Client.AccountNumber() + Seperator;
		DataLine += Client.PinCode + Seperator; 
		DataLine += to_string(Client.getAccountBalance());
		return DataLine;
	}
	static clsBankClient _GetEmptyClient() {
		return clsBankClient(enMode::EmptyMode,"", "", "", "", "", "", 0);
	}
	
	static vector<clsBankClient> _LoadClientsDataFromFile() {
		vector<clsBankClient> vClients; 
		fstream MyFile; 
		MyFile.open("Clients.txt", ios::in); 
		if (MyFile.is_open()) {
			string DataLine; 
			while (getline(MyFile, DataLine)) {
				clsBankClient Client = _ConvertLineToClientObject(DataLine); 
				vClients.push_back(Client); 
			}
			MyFile.close(); 
		}
		return vClients; 
	}
	static void _SaveClientDataToFile(vector<clsBankClient>vClient) {
		fstream	MyFile;
		MyFile.open("Clients.txt", ios::out );
		string DataLine;
		if (MyFile.is_open()) {
			for (clsBankClient& Client : vClient) {
				if (Client._MarkForDelete == false) {
					DataLine = _ConvertClientObjectToLine(Client);
					MyFile << DataLine << endl;
			}
			}
			MyFile.close(); 
		}
	}

		void _Update() {
		vector<clsBankClient> _vClients; 
		_vClients = _LoadClientsDataFromFile(); 
		for (clsBankClient& Client : _vClients) {
			if (Client.AccountNumber() == AccountNumber()) {
				Client = *this; 
				break; 
			}
		}
		_SaveClientDataToFile(_vClients); 
	}
		void _AddNew() {
			_AddNewDataLineToFile(_ConvertClientObjectToLine(*this)); 
		}
		void _AddNewDataLineToFile(string DataLine){
			fstream MyFile; 
			MyFile.open("Clients.txt", ios::out | ios::app);
			if (MyFile.is_open()) {
				MyFile << DataLine << endl; 
				MyFile.close(); 
			}
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
	 //void Print() {
		// cout << "Client Card : \n"; 
		// cout << "__________________________\n"; 
		// cout << "Firts Name     " << FirstName << endl; 
		// cout << "Last  Name     " << LastName << endl;
		// cout << "Full Name      " << FullName() << endl;
		// cout << "Email          " << Email << endl;
		// cout << "Phone          " << Phone << endl;
		// cout << "Account Number " << _AccountNumber << endl;
		// cout << "Pin Code       " << _PinCode << endl;
		// cout << "Account Balance" << _AccountBalance << endl;
		// cout << "__________________________\n";
	 //}
	 static bool IsClientExist(string AccountNumber) {
		 clsBankClient Client = Find(AccountNumber);
		 return (!Client.IsEmpty());
	 }
	 enum enSaveResult {svFaildEmptyObject = 0 , svSucceeded = 1 , svFaildAccountNumberExists = 2};
	 enSaveResult Save() {
		 switch (_Mode)
		 {
		 case enMode::EmptyMode: {
			 if (IsEmpty()) {
				 return enSaveResult::svFaildEmptyObject;
			 }
		 }
		 case clsBankClient::UpdateMode:
		 {
			 _Update();
			 return enSaveResult::svSucceeded;
			 break;

		 }
		 case enMode::AddNewMode:
		 {
			 if (clsBankClient::IsClientExist(_AccountNumber)) {
				 return enSaveResult::svFaildAccountNumberExists;
			 }
			 else {
				 _AddNew();
				 _Mode = enMode::UpdateMode;
				 return enSaveResult::svSucceeded;
			 }
		 }
		 }
	 }
	 static clsBankClient GetAddNewClientObject(string AccountNumber) {
		 return clsBankClient(enMode::AddNewMode,"","","","",AccountNumber,"",0);
	}
	 bool Delelte() {
		 vector<clsBankClient>_vClient = _LoadClientsDataFromFile();
		 for (clsBankClient& Client : _vClient) {
			 if (Client.AccountNumber() == _AccountNumber) {
				 Client._MarkForDelete = true;
				 break; 
			 }
			 
		 }
		 _SaveClientDataToFile(_vClient); 
		 *this = _GetEmptyClient();
		 return true; 
	 }
	 static vector<clsBankClient> GetClientsList() {
		 return _LoadClientsDataFromFile(); 
	 }
	 static double GetTotalBalances() {
		 double TotalBalances = 0; 
		 vector<clsBankClient>vClients = _LoadClientsDataFromFile(); 
		 for (clsBankClient& C : vClients) {
			 TotalBalances += C.AccountBalance; 
		 }
		 return TotalBalances; 
	 }
	 void Deposit(double Amount) {
		 _AccountBalance += Amount; 
		 Save(); 
	 }
	 bool Withdraw(double Amount) {
		 if (Amount > AccountBalance) {
			 return false; 
		 }
		 else {
			 _AccountBalance -= Amount; 
			 Save(); 

		 }
	 }
	 
};

