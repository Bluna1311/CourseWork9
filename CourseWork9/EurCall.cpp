#include "EurCall.h"
#include <iostream>
#include <cmath>
using namespace std;



double EurCall::N(double x)
{
	double gamma = 0.2316419;     double a1 = 0.319381530;
	double a2 = -0.356563782;   double a3 = 1.781477937;
	double a4 = -1.821255978;   double a5 = 1.330274429;
	double pi = 4.0*atan(1.0); double k = 1.0 / (1.0 + gamma * x);
	if (x >= 0.0)
	{
		return 1.0 - ((((a5*k + a4)*k + a3)*k + a2)*k + a1)
			*k*exp(-x * x / 2.0) / sqrt(2.0*pi);
	}
	else return 1.0 - N(-x);
}

double EurCall::d_plus(double S0, double sigma, double r)
{
	return (log(S0 / M_K) +
		(r + 0.5*pow(sigma, 2.0))*M_T) / (sigma*sqrt(M_T));
}

double EurCall::d_minus(double S0, double sigma, double r)
{
	return d_plus(S0, sigma, r) - sigma * sqrt(M_T);
}

double EurCall::PriceByBSFormula(double S0, double sigma, double r)
{
	return S0 * N(d_plus(S0, sigma, r))
		- M_K * exp(-r * M_T)*N(d_minus(S0, sigma, r));
}


void EurCall::GetData()
{
	M_stock = 100;//
	M_Rate = 0.05;
	M_Sigma = 0.15;
	M_m = 0.05;
	M_s = 0.3;
	M_Lambda = 1;
	// fill of member variables 
	M_k_small = exp(M_m + pow(M_s, 2) / 2) - 1;
	M_Lamda_Prime = M_Lambda * (1 + M_k_small);
	return;
	// member variables are filled 
	// i started as a generic code, then was forced cram member variables.
}

double EurCall::value()
{
	double Value_Of_JD = 0;
	double I_Factorial = 1 ;
	double J = 0;
	for (int i = 0; i <= M_count; i++)
	{
		if (i == 0)
		{
			I_Factorial = 1;
		}
		for (J = 1; J <= i; J++)
		{
			I_Factorial *= J;
		}



		double Sigma_N = sqrt(pow(M_Sigma, 2) + (i *pow(M_s, 2) / M_T));
		double R_n = M_Rate - M_Lambda * M_k_small + ((i*log(1 + M_k_small)) / M_T);

		double pt2 = PriceByBSFormula(M_stock, Sigma_N, R_n);
		double pt1 = exp((-M_Lamda_Prime * M_T * pow(M_Lamda_Prime*M_T, i)) / I_Factorial);
		Value_Of_JD += pt1 * pt2;
		I_Factorial = 1;
	}


	return Value_Of_JD;


}