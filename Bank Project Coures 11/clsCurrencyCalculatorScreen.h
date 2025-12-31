#pragma once
#include "clsScreen.h" ;
#include "clsInputValidate.h" ;
#include "clsCurrency.h" ; 
#include "clsString.h" ; 
class clsCurrencyCalculatorScreen : protected clsScreen
{
private : 
	static clsCurrency _GetCurrency(string Message) {
		string CurrencyCode; 
		cout << Message << endl; 
		CurrencyCode = clsInputValidate::ReadString(); 
		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "\nCurrency is not found, choose another one : "; 
			CurrencyCode = clsInputValidate::ReadString(); 
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode); 
		return Currency; 
	}
	static float _ReadAmount() {
		float Amount = 0;
		cout << "Enter Amount Exchange : ";
		Amount = clsInputValidate::ReadNumber<float>();
		return Amount;
	}
	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card") {
		cout << "\n" << Title << "\n"; 
		cout << "___________________\n"; 
		cout << "\nCountry     :" << Currency.Country() ;
		cout << "\nCode     :" << Currency.CurrencyCode();
		cout << "\nName     :" << Currency.CurrencyName();
		cout << "\nRate(1$) =      :" << Currency.Rate();
		cout << "\n___________________\n\n";

	}
	static void _PrintCalculationsResult(float Amount, clsCurrency Currency1, clsCurrency Currency2) {
		_PrintCurrencyCard(Currency1,"Convert From");
		float AmountUSD = Currency1.ConvertToUSD(Amount); 
		cout << Amount << " " << Currency1.CurrencyCode() << "=" << AmountUSD << "USD\n"; 
		if (Currency2.CurrencyCode() == "USD") {
			return;
		}
		cout << "\nConverting From USD to : \n"; 
		_PrintCurrencyCard(Currency2, "To:"); 
		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);
		cout << Amount << " " << Currency1.CurrencyCode() << "=" << AmountInCurrency2 << " " << Currency2.CurrencyCode(); 
	}
public : 
	static void ShowCurrencyCalculatorScreen() {
		char Continue = 'y';
		while (Continue == 'y' || Continue == 'Y') {
			system("cls"); 
			_DrawScreenHeader("\tCurrency Calculater Screen");
			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code : "); 
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code : ");
			float Amount = _ReadAmount(); 
			_PrintCalculationsResult(Amount, CurrencyFrom, CurrencyTo); 
			cout << "\n\nDo You Want to Perform another Calculation?y/n?";
			cin >> Continue; 
		}
		
	}
};

