#pragma once
#include "clsScreen.h" ; 
#include "clsCurrency.h";
#include "clsInputValidate.h";
class clsUpdateCurrencyRateScreen : protected clsScreen

{
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }
    static float _ReadRate() {
        cout << "\nEnter New Rate: "; 
        float NewRate = 0;
        NewRate = clsInputValidate::ReadNumber<double>(); 
        return NewRate;
    }

public:
	static void ShowUpdateCurrencyRateScreen() {
		_DrawScreenHeader("\tUpdate Currency Screen"); 
		cout << "Please Enter Currency Code : "; 
		string CurrencyCode = clsInputValidate::ReadString();
		
        while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
            cout << "Currency is not found ,choose another one :";
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);
        char Answer = 'n'; 
        cout << "Are You Sure you want to update the rate of this Currency?y/n?"; 
        cin >> Answer; 
        if (Answer == 'y' || Answer == 'Y') {
            cout << "Update Currency Rate :";
            cout << "\n_______________________\n"; 
            Currency.UpdateRate(_ReadRate()); 
            cout << "Currency Rate Update Successfully :-)"; 
            _PrintCurrency(Currency); 
        }
	}
};

