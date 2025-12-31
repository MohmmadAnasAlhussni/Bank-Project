#include <iostream>
#include "clsMainScreen.h" ; 
#include "clsLoginScreen.h" ; 
 
using namespace std;
template<typename T> T myMax(T Number1, T Number2) {
	if (Number1 > Number2)
		return Number1;
	else
		return Number2; 
}
template<class T>
class Calculator {
private:
	T	_Number1, _Number2;
public:
	Calculator(T N1, T N2) {
		_Number1 = N1;
		_Number2 = N2;
	}
	T Add() {
		return (_Number1 + _Number2); 
	}
	T Sub() {
		return (_Number1 - _Number2); 
	}
};
int main()
{
  
	while (true  ) {
		if (!clsLoginScreen::ShowLoginScreen()) {
			break;
		}
	}
	/*cout << myMax<int>(3,7) << endl; 
	cout << myMax<double>(2.2, 2.3) << endl;*/ 
	/*Calculator<int> CalInt(10, 11); 
	cout << CalInt.Add() << endl; */
	system("pause>0"); 
	return 0; 
}

