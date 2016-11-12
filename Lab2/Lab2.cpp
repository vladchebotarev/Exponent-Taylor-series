// Lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

double ext(double x, int n){
	
	double suma = 1;
	double tmp = 1;
	
	for (int i = 1; i < n; i++){
		tmp *= x / i;
		suma += tmp;
	}
	return suma;
}


double ext2(double x, int n){
	if (x >= 0.0)
		return ext(x, n);
	else return 1.0f / ext(-x, n);
}



int _tmain(int argc, _TCHAR* argv[])
{
	double myfunk, myfunk2, sysfunk;
	double err1, err2;



	cout << "X" << "     exp(x)" << "\t\tMy funk 1" << "\tError 1" << "\t\t  My funk 2" << "\t  Error2 " << endl << endl;


	for (int x = -30; x <= 30; x++){
		myfunk = ext(x, 1000);
		myfunk2 = ext2(x, 100);
		sysfunk = exp(x);
		
		err1 = abs((myfunk - sysfunk) / sysfunk);
		err2 = abs((myfunk2 - sysfunk) / sysfunk);

		cout << setw(4) << left << x << right << setw(14) << sysfunk << setw(18) << myfunk << setw(16) << err1 << setw(18) << myfunk2 << setw(16) << err2 << endl;
	}

	system("pause");
	return 0;
}

