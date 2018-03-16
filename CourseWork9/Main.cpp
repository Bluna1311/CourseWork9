#include <iostream>
#include "EurCall.h"
#include <map>
using namespace std;

int main() 
{
	// Initial Data 
	double Stock = 100;
	double Rate = 0.05;
	double sigma = 0.15;
	double M_m = 0.05;
	double M_s = 0.3;
	double K = 105;
	double Time_To_Expire = 0.5;
	double lambda = 1;
	// compact data
	double Lamda_Prime = lambda * (1 + K);
	double R_n = Rate;

	EurCall Call(Time_To_Expire, K);
	Call.GetData();
	double Price = Call.value();

	//part 2;
	//double K_trial;
	//EurCall Trial(Time_To_Expire, K_trial);
	//Map(mypair<double , double > PARTB;
	/*
	
	
	
	*/
	cout << Price;
	system("pause");
	return 0;
}