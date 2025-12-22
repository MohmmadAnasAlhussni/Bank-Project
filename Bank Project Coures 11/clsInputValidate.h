#pragma once
#include "clsDate.h" ; 

class clsInputValidate
{
public : 
	static bool IsNumberBetween(short Number, short From, short To) {
		if (Number >= From && Number <= To)
		return true;
		else
			return false;
	}
	static bool IsNumberBetween(int Number, int From, int To) {
		if (Number >= From && Number <= To)
		return true;
		else
			return false;
	}
	static bool IsNumberBetween(double Number, double From, double To) {
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo) {
		if ((clsDate::IsDate1AfterDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom))
			&&
			(clsDate::IsDate1BeforeDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateTo))
			) {
			return true; 
		}
		if ((clsDate::IsDate1AfterDate2(Date, DateTo) || clsDate::IsDate1EqualDate2(Date, DateTo))
			&&
			(clsDate::IsDate1BeforeDate2(Date, DateFrom) || clsDate::IsDate1EqualDate2(Date, DateFrom))
			) {
			return true;
		}
		return false;
	}
	static int ReadIntNumber(string ErrorMessage="Invaild Number ,Enter agine\n") {
		int Number; 
		while (!(cin >> Number)) {
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << ErrorMessage; 
		}
		return Number; 
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range please Enter agin") {
		int Number; 
		Number = ReadIntNumber();
		while (!IsNumberBetween(Number,From,To) ) {
			cout << ErrorMessage << endl; 
			Number = ReadIntNumber();
		}
		return Number; 
	}
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range please Enter agin") {
		short Number;
		Number = ReadIntNumber();
		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage << endl;
			Number = ReadIntNumber();
		}
		return Number;
	}
	static double ReadDblNumberBetween( double From, double To, string ErrorMessage = "Number is not within range please Enter agin") {
		double Number;
		Number = ReadIntNumber();
		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage << endl;
			Number = ReadIntNumber();
		}
		return Number;
	}
	static double ReadDblNumber(string ErrorMessage = "Invaild Number ,Enter agine\n") {
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static bool IsValidDate(clsDate Date) {
		return Date.IsValidDate(); 
	}
	static string ReadString() {
		string S1;
		getline(cin >> ws, S1); 
		return S1; 
	}
};

