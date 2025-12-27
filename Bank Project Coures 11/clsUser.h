#pragma once
#include"clsPerson.h" ;
#include"clsString.h" ; 
#include <fstream>
#include<string>
#include <vector>
#include "clsDate.h" ; 
class clsUser : public clsPerson
{
private : 
	enum enMode{EmptyMode  = 0, UpdateMode = 1 , AddNewMode = 2};
	enMode _Mode;
	string _UserName;
	string _Password; 
	int _Permissions; 
	bool _MarkForDelete = false; 
	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#") {
		vector<string> vUserData; 
		vUserData = clsString::Split(Line, Seperator); 
		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6])); 
	}
	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static vector<clsUser>_LoadUserDataFromFile() {
		vector<clsUser> vUsers; 
		fstream MyFile;
		MyFile.open("Users.txt", ios::in); 
		if (MyFile.is_open()) {
			string DataLine;
			while (getline(MyFile, DataLine)) {
				clsUser  User = _ConvertLineToUserObject(DataLine); 
				vUsers.push_back(User); 
			}
			MyFile.close(); 
		}
		return vUsers;
	}
	static string _ConvertUserObjectToLine(clsUser User , string Seperator="#//#") {
		string DataLine = ""; 
		DataLine += User.FirstName + Seperator; 
		DataLine += User.LastName + Seperator;
		DataLine += User.Email + Seperator;
		DataLine += User.Phone + Seperator;
		DataLine += User.UserName + Seperator;
		DataLine += User.Password + Seperator;
		DataLine += to_string(User.Permissions) ;
		return DataLine; 
	}
	void static _SaveUserDataToFile(vector<clsUser>vUsers) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out); 
		string DataLine;
		if (MyFile.is_open()) {
			for (clsUser& User : vUsers) {
				if (User.MarkForDeleted() == false) {
					DataLine = _ConvertUserObjectToLine(User); 
					MyFile << DataLine << endl; 
				}
			}
			MyFile.close(); 
		}
	}
	void _Update() {
		vector<clsUser> vUsers = _LoadUserDataFromFile(); 
		for (clsUser& U : vUsers) {
			if (U.UserName == UserName) {
				U = *this;
				break;
			}
		}
		_SaveUserDataToFile(vUsers); 
	}
	void _AddNewDataLineToFile(string Line){
		fstream MyFile; 
		MyFile.open("Users.txt", ios::out | ios::app); 
		if (MyFile.is_open()) {
			MyFile << Line << endl; 
			MyFile.close(); 
		}
	}
	void _AddNew() {
		_AddNewDataLineToFile(_ConvertUserObjectToLine(*this) ); 
	}
	string _PerpareLogInRecourd(string Seperator="#//#") {
		string LoginRecourd = ""; 
		LoginRecourd += clsDate::GetSystemDateTimeString() + Seperator; 
		LoginRecourd += UserName + Seperator; 
		LoginRecourd += Password + Seperator; 
		LoginRecourd += to_string(Permissions); 
		return LoginRecourd; 
	}
public : 
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string UserName, string Password, int Permissions) 
		: clsPerson(FirstName, LastName, Email, Phone) {
		_Mode = Mode; 
		_UserName = UserName; 
		_Password = Password; 
		_Permissions = Permissions; 

	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode); 
	}
	bool MarkForDeleted() {
		return _MarkForDelete; 
	}
	string GetUserName() { return _UserName;  } 

	void SetUserName(string UserName) { _UserName = UserName;  } 
	
	__declspec(property(get = GetUserName, put = SetUserName))string UserName;
	
	string GetPassword() { return _Password;  } 
	
	void SetPassword(string Password) { _Password = Password;  } 
	
	__declspec(property(get = GetPassword, put = SetPassword))string Password; 

	void SetPermissions(int Permissions) {
		_Permissions = Permissions; 
	}

	int GetPermissions() {
		return _Permissions; 
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions; 

	static clsUser Find(string UserName) {
		fstream MyFile; 
		MyFile.open("Users.txt", ios::in); 
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName) {
					MyFile.close(); 
					return User;
				}
			}
			MyFile.close(); 
		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName , string Password) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password) {
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}
	enum enSaveResult {
		svFaildEmptyObject = 0 , 
		svSuccessded = 1 , 
		svFaildUserExists = 2 , 
	};

	enSaveResult Save() {
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty()) {
				return enSaveResult::svFaildEmptyObject;
				
			}
			
		}
		case enMode::UpdateMode:
		{
			_Update(); 
			return enSaveResult::svSuccessded; 
			break;
			
		}
		case enMode::AddNewMode:
		{
			if (clsUser::IsUserExist(_UserName)) {
				return enSaveResult::svFaildUserExists; 
			}
			else {
				_AddNew(); 
				_Mode = enMode::UpdateMode; 
				return enSaveResult::svSuccessded; 
			}
			break;
		}
	
		}
	}
	bool static IsUserExist(string UserName) {
		clsUser User = clsUser::Find(UserName);
		return(!User.IsEmpty());
	}
	bool Delete() {
		vector<clsUser>_vUsers; 
		_vUsers = _LoadUserDataFromFile(); 
		for (clsUser& User : _vUsers) {
			if (User.UserName == _UserName) {
				User._MarkForDelete = true; 
				break; 
			}
		}
		_SaveUserDataToFile(_vUsers); 
		*this = _GetEmptyUserObject();
		return true; 
	}
	static clsUser GetAddNewUserObject(string UserName) {
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0); 
	}
	static vector<clsUser>GetUserList() {
		return _LoadUserDataFromFile();
	}

	enum enPermissions {
		eAll = -1 , pListClients = 1 ,  pAddNewClient = 2 , 
		pDeleteClient = 4 , pUpdateClient = 8 ,  pFindClient = 16 , pTransaction = 32 , pMangeUsers =64  
	};
	bool CheckAccessPermissions(enPermissions Permissions) {
		if (this->Permissions == enPermissions::eAll) {
			return true; 
		}
		if ((Permissions & this->Permissions) == Permissions)
			return true;
		else
			return false;
	} 
	//RegisterLogin 
	void RegisterLogIn() {
		string stDataLine = _PerpareLogInRecourd(); 
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app); 
		if (MyFile.is_open()) {
			MyFile << stDataLine << endl;
			MyFile.close(); 
		}
	}
};

