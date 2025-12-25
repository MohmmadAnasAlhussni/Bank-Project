#pragma once
#include "clsScreen.h"; 
#include "Global.h" ; 
#include "clsMainScreen.h" ; 
class clsLoginScreen : protected clsScreen 
{
private : 
	static void _Login() {
		bool LoginFaild = false; 
		string UserName, Password; 
		do {
			if (LoginFaild) {
				cout << "InvaildUserName/Password \n";  
			}
			cout << "Enter UserName?"; 
			cin >> UserName; 
			cout << "Enter Password?";
			cin >> Password; 
			CurrentUser = clsUser::Find(UserName, Password); 
			LoginFaild = CurrentUser.IsEmpty(); 
		} while (LoginFaild); 
		clsMainScreen::ShowMainMenue(); 
	}
public : 
	static void ShowLoginScreen() {
		system("cls"); 
		_DrawScreenHeader("\t Login Screen");
		_Login();
	}
};

