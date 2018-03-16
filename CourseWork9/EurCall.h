#pragma once


class EurCall
{
public:
	EurCall(double T_, double K_) {M_T = T_; M_K = K_;}
	void GetData();
	double value();
private:
	double M_Lambda; //
	double M_Sigma; //
	double M_m , M_s;
	double M_Rate;
	double M_stock;
	double M_T, M_K;
	double M_k_small;
	double M_Lamda_Prime;
	long double M_count = 10;
	double d_plus(double S0, double sigma, double r);
	double d_minus(double S0, double sigma, double r);
	double N(double x);
	double PriceByBSFormula(double S0, double sigma, double r);

};
