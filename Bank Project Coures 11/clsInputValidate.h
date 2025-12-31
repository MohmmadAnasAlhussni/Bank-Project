#pragma once
#include "clsDate.h" ; 

class clsInputValidate
{
public : 
	
	template< typename T>static bool IsNumberBetween(T Number, T From, T To) {
		if (Number >= From && Number <= To)
		return true;
		else
			return false;
	}
	static bool IsDateBetween(clsDate DateTime, clsDate DateFrom, clsDate DateTo) {
		if ((clsDate::IsDate1AfterDate2(DateTime, DateFrom) || clsDate::IsDate1EqualDate2(DateTime, DateFrom))
			&&
			(clsDate::IsDate1BeforeDate2(DateTime, DateTo) || clsDate::IsDate1EqualDate2(DateTime, DateTo))
			) {
			return true; 
		}
		if ((clsDate::IsDate1AfterDate2(DateTime, DateTo) || clsDate::IsDate1EqualDate2(DateTime, DateTo))
			&&
			(clsDate::IsDate1BeforeDate2(DateTime, DateFrom) || clsDate::IsDate1EqualDate2(DateTime, DateFrom))
			) {
			return true;
		}
		return false;
	}
	template <typename T>static T ReadNumber(string ErrorMessage="Invaild Number ,Enter agine\n") {
		T Number; 
		while (!(cin >> Number)) {
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << ErrorMessage; 
		}
		return Number; 
	}

   template<typename T>	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range please Enter agin") {
		T Number; 
		Number = ReadNumber<T>();
		while (!IsNumberBetween(Number,From,To) ) {
			cout << ErrorMessage << endl; 
			Number = ReadNumber<T>();
		}
		return Number; 
	}
		static bool IsValidDate(clsDate DateTime) {
		return DateTime.IsValidDate(); 
	}
	static string ReadString() {
		string S1;
		getline(cin >> ws, S1); 
		return S1; 
	}
};

