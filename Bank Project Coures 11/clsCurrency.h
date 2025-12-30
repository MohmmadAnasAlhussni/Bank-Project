#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h" ; 
using namespace std; 
class clsCurrency
{
private : 
	enum enMode {EmptyMode = 0 , UpdateMode = 1}; 
	enMode _Mode; 
	string _Country; 
	string _CurrencyCode; 
	string _CurrencyName; 
	float _Rate;
	static clsCurrency _ConvertDataLineToCurrencyObject(string Line , string Seperator ="#//#") {
		vector<string> vString = clsString::Split(Line , Seperator); 
		return clsCurrency(enMode::UpdateMode, vString[0], vString[1], vString[2], stof(vString[3])); 
	}
	static  vector<clsCurrency> _LoadCurrencysDataFromFile() {
		vector<clsCurrency>vCurrencys; 
		fstream MyFile; 
		MyFile.open("Currencies.txt", ios::in); 
		if (MyFile.is_open()) {
			string DataLine; 
			while (getline(MyFile, DataLine)) {
				clsCurrency Currency = _ConvertDataLineToCurrencyObject(DataLine); 
				vCurrencys.push_back(Currency);
			}
			MyFile.close(); 
		}
		return vCurrencys; 
	}
	static string _ConvertCurrencyObjectToLine(clsCurrency Currency , string Seperator ="#//#") {
		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency.CurrencyCode() + Seperator;
		stCurrencyRecord += Currency.CurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency>vCurrencys) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out); 
		if (MyFile.is_open()) {
			string DataLine; 
			for (clsCurrency Currency : vCurrencys) {
				DataLine = _ConvertCurrencyObjectToLine(Currency);
				MyFile << DataLine << endl; 
			}
			MyFile.close(); 
		}
	}
	 void _Update(){

		vector<clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencysDataFromFile(); 
		for (clsCurrency& Currency : _vCurrencys) {
			if (Currency.CurrencyCode() == _CurrencyCode) {
				Currency = *this; 
				break; 
			}
		}
		_SaveCurrencyDataToFile(_vCurrencys); 
	}
	 static clsCurrency _GetEmptyCurrencyObject() {
		 return clsCurrency(enMode::EmptyMode, "", "", "", 0); 
	 }
public : 
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country; 
		_CurrencyCode = CurrencyCode; 
		_CurrencyName = CurrencyName; 
		_Rate = Rate; 
	}
	static vector<clsCurrency> GetAllUSDRates() {
		return _LoadCurrencysDataFromFile(); 
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode); 
	}
	string Country() {	return _Country; }
	string CurrencyCode() { return _CurrencyCode;  } 
	string CurrencyName() { return _CurrencyName;  } 
	float Rate() { return _Rate;  } 
	void UpdateRate(float NewRate){
		_Rate = NewRate; 
		_Update(); 
	}
	static clsCurrency FindByCode(string CurrencyCode) {
		CurrencyCode = clsString::UpperAllString(CurrencyCode); 
		fstream MyFile; 
		MyFile.open("Currencies.txt", ios::in); 

		if (MyFile.is_open()) {
			string DataLine;
			while (getline(MyFile, DataLine)) {
				clsCurrency Currency = _ConvertDataLineToCurrencyObject(DataLine);
				if (Currency.CurrencyCode() == CurrencyCode) {
					MyFile.close(); 
					return Currency; 
				}
		    }
			MyFile.close();
		}
		return _GetEmptyCurrencyObject(); 
	}
	static clsCurrency FindByCountry(string Country) {
		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		
		if (MyFile.is_open()) {
			string DataLine;
			while (getline(MyFile, DataLine)) {
				clsCurrency Currency = _ConvertDataLineToCurrencyObject(DataLine);
				if (clsString::UpperAllString(Currency.Country()) == Country) {
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty()); 
	}
	static vector<clsCurrency>GetCurrenciesList() {
		return _LoadCurrencysDataFromFile(); 
	}
};


