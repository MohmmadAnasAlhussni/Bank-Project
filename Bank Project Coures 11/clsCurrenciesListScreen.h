#pragma once
#include "clsScreen.h" ; 
#include <vector> 
#include <iomanip>
#include "clsCurrency.h" ; 
class clsCurrenciesListScreen : protected clsScreen
{
private : 
	static void _PrintCurrenciesRecord(clsCurrency Currency) {
		cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(8) << Currency.CurrencyCode();
		cout << "| " << left << setw(45) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();
	}
public : 
	static void ShowCurrenciesListScreen() {
		vector<clsCurrency> vCurrency = clsCurrency::GetCurrenciesList(); 
		string Title = "\tCurrencies List Screen"; 
		string SubTitle = "(" + to_string(vCurrency.size()) + ") Currency"; 
		_DrawScreenHeader(Title, SubTitle); 
		cout << setw(8) << left << "" << "\n\t________________________________";
		cout << "__________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate(1$)";
		cout << setw(8) << left << "" << "\n\t________________________________";
		cout << "__________________________________________________________________\n" << endl;
		if (vCurrency.size() == 0) 
			cout << "\nNo Currencies Available In The System!"; 
		
		else 
			for (clsCurrency Currency : vCurrency) {
				_PrintCurrenciesRecord(Currency); 
				cout << endl; 
			}
			cout << setw(8) << left << "" << "\n\t________________________________";
			cout << "__________________________________________________________________\n" << endl;
		
	}
};

