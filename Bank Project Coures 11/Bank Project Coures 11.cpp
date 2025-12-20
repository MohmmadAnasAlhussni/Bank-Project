#include <iostream>
#include "clsString.h"; 
#include "clsDate.h" ; 
#include "clsUtitl.h" ; 
using namespace std; 
int main()
{
	clsUtitl::Srand(); 
	cout << clsUtitl::RandomNumber(1, 10) << endl;
	cout << clsUtitl::GetRandomCharacter(clsUtitl::Digit) << endl; 
	cout << clsUtitl::GenerateWord(clsUtitl::MixChars, 8) << endl;
	cout << clsUtitl::GenerateKey(clsUtitl::MixChars) << endl;
	 clsUtitl::GeneratesKeys(10, clsUtitl::MixChars);
	 cout << "\n"; 
	 //Swap int : 
	 int x = 10, y = 20; 
	 cout << x << "" << y << endl; 
	 clsUtitl::Swap(x, y); 
	 cout << x << "" << y << endl;
	 double a = 10.5 , b = 20.5 ;
	 cout << a << " " << b << endl; 
	 clsUtitl::Swap(a, b); 
	 cout << a << " " << b << endl;
	 string s1 = "Ali", s2 = "Ahmad"; 
	 cout << s1 << " " << s2 << endl; 
	 clsDate d1(1, 10, 2022) , d2(1,1,2022);
	 d1.Print(); 
	 d2.Print(); 
	 clsUtitl::Swap(d1, d2); 
	 d1.Print(); 
	 d2.Print(); 
	 int arr1[5] = { 1,2,3,4,5 }; 
	 clsUtitl::ShuffleArray(arr1, 5); 
	 cout << "\nAfter Array Shuffle \n"; 
	 for (int i = 0; i < 5; i++) {
		 cout << arr1[i] << endl; 
	 }
	 string arr2[5] = { "Ali","Ahmad","Anas","Nezar","Tyesser" }; 
	 clsUtitl::ShuffleArray(arr2 , 5);
	 cout << "\nAfter Array Shuffle \n";
	 for (short i = 0; i < 5; i++) {
		 cout << arr2[i] << endl; 
	 }
	 int Arr3[5];
	 clsUtitl::FillArrayWithRandomNumber(Arr3, 5, 20, 50); 
	 cout << "\n Array After fill\n"; 
	 for (int i = 0; i < 5; i++) {
		 cout << Arr3[i] << endl; 
	 }
	 string Arr4[5]; 
	 clsUtitl::FillArrayWithRandomWords(Arr4, 5, clsUtitl::MixChars, 8); 
	 cout << "\n Array After fill Words\n";
	 for (int i = 0; i < 5; i++) {
		 cout << Arr4[i] << endl;
	 }
	 string Arr5[5];
	 clsUtitl::FillArrayWithRandomKeys(Arr5, 5, clsUtitl::MixChars);
	 cout << "\n Array After fill Keys\n";
	 for (int i = 0; i < 5; i++) {
		 cout << Arr5[i] << endl;
	 }
	 cout << "\nText1" << clsUtitl::Tabs(5) << "Text2\n"; 
}

