#include <iostream>
#include "clsString.h"; 
using namespace std; 
int main()
{
	clsString String1; 
	clsString String2("Ali Ahmad");
	String1.Value = "Mohmmad Anas"; 
	cout << "String1 = " << String1.Value << endl; 
	cout << "String2 = " << String2.GetValue() << endl; 
	cout << "The Length For String 1 " << String1.Length() << "\n"; 
	cout << "The Lenght For Mohmmad Anas Alhussni " << clsString::Length("Mohmmad Anas Alhussni"); 
	cout << "----------------------\n"; 
	cout << "Print First Letter of Each word in String2 "; 
	String2.PrintFirstLetterOfEachWord(); 
	cout  << endl;
	cout << "Print First Letter of Each Word Mohmmad Anas Alhussni Dev"; 
	clsString::PrintFirstLetterOfEachWord("Mohmmad Anas Alhussni Dev");
	cout << endl; 
	cout << "----------------------\n";
	cout << "Upper First Letter Of Each Word in String2";
	 String2.UpperFirstLetterOfEachWord(); 
	
	 cout <<String2.Value <<  endl; 
	cout << "Upper First Letter Of Each Word ead aldeen ";
	 clsString::UpperFirstLetterOfEachWord("ead aldeen");
	cout << endl;
	cout << "----------------------\n";
	cout << "Lower First Letter Of Each String1";
	 String1.LowerFirstLetterOfEachString(); 
	cout <<String1.Value <<  endl; 
	cout << "Lower First Letter Of Each ead aldeen";
	clsString::LowerFirstLetterOfEachString("ead aldeen"); 
	cout << endl; 
	cout << "----------------------\n";
	cout << "Upper All String (String1) ";  
	String1.UpperAllString(); 
	cout << String1.Value;
	cout << endl; 

	cout << "Upper All String (mohmmad yasser) ";
	cout << clsString::UpperAllString("mohmmad yasser");
	cout << endl;
	cout << "----------------------\n";
	cout << "Lower All String (String1) ";
	String1.LowerAllString();
	cout << String1.Value;
	cout << endl;

	cout << "Lower All String (mohmmad yasser) ";
	cout << clsString::LowerAllString("mohmmad yasser");
	cout << endl;

	cout << "----------------------\n"; 
	cout << "Invert Letter Case i " << clsString::InvertLetterCase('i') << endl ; 
	cout << "----------------------\n";
	cout << "Invert All String Letters Case "; 
	 String1.InvertAllStringLettersCase(); 
	 cout << String1.Value; 
	 cout << endl; 
	 cout << "Invert All String Letters Case YeS : ";
	 cout << clsString::InvertAllStringLettersCase("YeS");
	 cout << endl;
	 cout << "----------------------\n";
	 cout << "CaseLetterCount"; 
	 cout << String1.CountLetters() << endl;
	 cout << "CaseLetterCount";
	 cout << clsString::CountLetters("CaseLetterCount") <<endl;

}

