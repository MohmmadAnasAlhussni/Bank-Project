#pragma once
#include <iostream>
#include <cstdlib>
#include "clsDate.h" ; 
class clsUtitl
{
public: 
	static void Srand() {
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To) {
		return rand() % (To - From + 1) + From;
	}
	
    enum enCharacterType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };
  static  char GetRandomCharacter(enCharacterType CharType) {
        if (CharType == enCharacterType::MixChars) {
            CharType = (enCharacterType)RandomNumber(1, 3); 
        }
        switch (CharType)
        {
        case enCharacterType::SamallLetter:
            return char(RandomNumber(97, 122));

        case enCharacterType::CapitalLetter:
            return char(RandomNumber(65, 90));
        case enCharacterType::Digit:
            return char(RandomNumber(48, 57));
            break;
        case enCharacterType::SpecialCharacter:
            return char(RandomNumber(33, 47));
            break;
        }
    }

 static string GenerateWord(enCharacterType CharType, short Length) {
      string Word = "";
      for (int i = 1; i <= Length; i++) {
          Word += GetRandomCharacter(CharType);
      }
      return Word;
  }
 static string GenerateKey(enCharacterType CharacterType = CapitalLetter) {
     string Key = "";
     Key = GenerateWord(CharacterType, 4) + "-";
     Key = Key + GenerateWord(CharacterType, 4) + "-";
     Key = Key + GenerateWord(CharacterType, 4) + "-";
     Key = Key + GenerateWord(CharacterType, 4);
     return Key;
 }
static void GeneratesKeys(short NumberOfKey , enCharacterType CharacterType) {
     for (int i = 1; i <= NumberOfKey; i++) {
         cout << "Key [" << i << "]";
         cout << GenerateKey(CharacterType) << "\n";
     }
 }
static void Swap(int& A, int& B) {
    int Temp = 0; 
    Temp = A; 
    A = B; 
    B = Temp; 
}
static void Swap(double& A, double& B) {
    double Temp = 0; 
    Temp = A; 
    A = B; 
    B = Temp; 
}
static void Swap(string& S1, string& S2) {
    string Temp = ""; 
    Temp = S1; 
    S1 = S2; 
    S2 = Temp; 
}
static void Swap(clsDate& Date1, clsDate& Date2) {
    clsDate::SwapDates(Date1, Date2); 
}
static void ShuffleArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        int index1 = RandomNumber(1, arrLength) - 1;
        int index2 = RandomNumber(1, arrLength) - 1;
        Swap(arr[index1], arr[index2]);

    }
}
//ArrayShuffle
static void ShuffleArray(string arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        int index1 = RandomNumber(1, arrLength) - 1;
        int index2 = RandomNumber(1, arrLength) - 1;
        Swap(arr[index1], arr[index2]);

    }
    }

static void FillArrayWithRandomNumber(int arr[100], int arrLength, short From, short To) {

    for (int i = 0; i < arrLength; i++) {
        arr[i] = RandomNumber(From, To);
    }
}
static void FillArrayWithRandomWords(string  arr[100], short arrLength, enCharacterType CharacterType, short LengthWord) {
    for (short i = 0; i < arrLength; i++) {
        arr[i] = GenerateWord(CharacterType, LengthWord);
    }
}
static void FillArrayWithRandomKeys(string arr[100] , short arrLength , enCharacterType CharacterType) {
    for (short i = 0; i < arrLength; i++) {
        arr[i] = GenerateKey(CharacterType);
    }
}
static string Tabs(short NumberOfTabs) {
    string tap="";
    for (int i = 1; i <= NumberOfTabs; i++) {
        tap += "\t";
    }
    return tap;
}
static string  EncryptText(string Text, short EncryptionKey)
{

    for (int i = 0; i <= Text.length(); i++)
    {

        Text[i] = char((int)Text[i] + EncryptionKey);

    }

    return Text;

}

static string  DecryptText(string Text, short EncryptionKey)
{

    for (int i = 0; i <= Text.length(); i++)
    {

        Text[i] = char((int)Text[i] - EncryptionKey);

    }
    return Text;

}
static string NumberToText(int Number) {
    string NumberText;
    if (Number == 0) {
        return "";
    }
    if (Number >= 1 && Number <= 19) {
        string arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven" ,
        "Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
        };
        return arr[Number] + " ";
    }
    if (Number >= 20 && Number <= 99) {
        string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }
    if (Number >= 100 && Number <= 199) {
        return "One Hundred " + NumberToText(Number % 100);
    }
    if (Number >= 200 && Number <= 999) {
        return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
    }
    if (Number >= 1000 && Number <= 1999) {
        return "One Thousand " + NumberToText(Number % 1000);
    }
    if (Number >= 2000 && Number <= 999999) {
        return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
    }
    if (Number >= 1000000 && Number <= 1999999) {
        return "One Million " + NumberToText(Number % 1000000);
    }
    if (Number >= 2000000 && Number <= 9999999) {
        return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
    }
    if (Number >= 10000000 && Number <= 19999999) {
        return "One Billion " + NumberToText(Number % 10000000);
    }
    else {
        return NumberToText(Number / 10000000) + "Billions " + NumberToText(Number % 10000000);
    }
    return NumberText;
}
};

