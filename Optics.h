#ifndef OPTICS_H
#define OPTICS_H
#include<iostream>
#include<cmath>
#include<vector>
extern const double PI;
extern double Kn, Kw;
extern double f_, L_H, L_P;
extern int flag;
extern double h, W, L, Y, U;
extern double ideal_L_infinite;
extern double ideal_L_finite;

double angle_to_rad(double U);

double rad_to_angle(double U);

class Parameter
{
public:
	Parameter() {}
	Parameter(double L, double U) : L(L)
	{
		this->U = angle_to_rad(U);
		sinU = Kn * sin(this->U);
		this->U = asin(sinU);
	}
	Parameter(double h) :h(h), U(0) {}
	double h;
	double L;
	double L_;
	double U;
	double sinU;
	double U_;
	double sinU_;
	double I;
	double sinI;
	double I_;
	double sinI_;
};

class Surface
{
public:
	Surface(double r, double n1, double n2, double d2)
	{
		this->r = r;
		this->n = n1;
		this->n_ = n2;
		this->d = 0;
		this->d_ = d2;
	}
	Surface(double r, double n1, double n2, double d1, double d2)
	{
		this->r = r;
		this->n = n1;
		this->n_ = n2;
		this->d = d1;
		this->d_ = d2;
	}
	void Calculate0(Parameter& p, std::vector<Parameter>& P_All)
	{
		p.sinI = p.h / r;
		p.sinI_ = n * p.sinI / n_;
		p.I = asin(p.sinI);
		p.I_ = asin(p.sinI_);
		p.U_ = p.U + p.I - p.I_;
		p.sinU_ = sin(p.U_);
		p.L_ = r + r * p.sinI_ / p.sinU_;
		P_All.push_back(p);
		p.L = p.L_ - d_;
		p.U = p.U_;
		p.sinU = sin(p.U);
	}
	void Calculate1(Parameter& p, std::vector<Parameter>& P_All)
	{
		p.sinI = (p.L - r) * p.sinU / r;
		p.sinI_ = n * p.sinI / n_;
		p.I = asin(p.sinI);
		p.I_ = asin(p.sinI_);
		p.U_ = p.U + p.I - p.I_;
		p.sinU_ = sin(p.U_);
		p.L_ = r + r * p.sinI_ / p.sinU_;
		P_All.push_back(p);
		p.L = p.L_ - d_;
		p.U = p.U_;
		p.sinU = sin(p.U);
	}
	~Surface() {}
	double d;
	double n;
	double r;
	double n_;
	double d_;
};

class Parameter_plus
{
public:
	Parameter_plus() {}

	void Calculate_infinite(std::vector<Parameter>& p_all, std::vector<Surface>& sur, int i)
	{
		Parameter p1 = p_all[i];
		Parameter p2 = p_all[i + 1];
		Surface sur1 = sur[i];
		Surface sur2 = sur[i + 1];
		PA = p1.L_ * p1.sinU_ / cos((p1.I_ - p1.U_) / 2);
		x = PA * PA / sur1.r / 2;
		t_ = sur1.n_ * cos(p1.I_) * cos(p1.I_) / ((sur1.n_ * cos(p1.I_) - sur1.n * cos(p1.I)) / sur1.r);
		s_ = sur1.n_ / ((sur1.n_ * cos(p1.I_) - sur1.n * cos(p1.I)) / sur1.r);
		PA_ = p2.L_ * p2.sinU_ / cos((p2.I_ - p2.U_) / 2);
		x_ = PA * PA / sur2.r / 2;
		Dv = (sur1.d_ - x + x_) / cos(p1.U_);
	}
	void Calculate(double L, std::vector<Parameter> & p_all, std::vector<Surface> & sur, int i)
	{
		Parameter p1 = p_all[i];
		Parameter p2 = p_all[i + 1];
		Surface sur1 = sur[i];
		Surface sur2 = sur[i + 1];
		PA = p1.L_ * p1.sinU_ / cos((p1.I_ - p1.U_) / 2);
		x = PA * PA / sur1.r / 2;
		s = t = (L - x) / cos(p1.U);
		t_ = sur1.n_ * cos(p1.I_) * cos(p1.I_) / ((sur1.n_ * cos(p1.I_) - sur1.n * cos(p1.I)) / sur1.r + (sur1.n * cos(p1.I) * cos(p1.I) / t));
		s_ = sur1.n_ / ((sur1.n_ * cos(p1.I_) - sur1.n * cos(p1.I)) / sur1.r + sur1.n / s);
		PA_ = p2.L_ * p2.sinU_ / cos((p2.I_ - p2.U_) / 2);
		x_ = PA * PA / sur2.r / 2;
		Dv = (sur1.d_ - x + x_) / cos(p1.U_);
	}
	void Calculate(std::vector<Parameter> & p_all, std::vector<Surface> & sur, int i, Parameter_plus pp)
	{
		Parameter p1 = p_all[i];
		Parameter p2 = p_all[i + 1];
		Surface sur1 = sur[i];
		Surface sur2 = sur[i + 1];
		PA = p1.L_ * p1.sinU_ / cos((p1.I_ - p1.U_) / 2);
		x = PA * PA / sur1.r / 2;
		t = pp.t_ - pp.Dv;
		t_ = sur1.n_ * cos(p1.I_) * cos(p1.I_) / ((sur1.n_ * cos(p1.I_) - sur1.n * cos(p1.I)) / sur1.r + sur1.n * cos(p1.I) * cos(p1.I) / t);
		s = pp.s_ - pp.Dv;
		s_ = sur1.n_ / ((sur1.n_ * cos(p1.I_) - sur1.n * cos(p1.I)) / sur1.r + sur1.n / s);
		PA_ = p2.L_ * p2.sinU_ / cos((p2.I_ - p2.U_) / 2);
		x_ = PA * PA / sur2.r / 2;
		Dv = (sur1.d_ - x + x_) / cos(p1.U_);
	}

	void Calculate_final(std::vector<Parameter> & p_all, std::vector<Surface> & sur, int i, Parameter_plus pp)
	{
		Parameter p1 = p_all[i];
		Surface sur1 = sur[i];
		t = pp.t_ - pp.Dv;
		t_ = sur1.n_ * cos(p1.I_) * cos(p1.I_) / ((sur1.n_ * cos(p1.I_) - sur1.n * cos(p1.I)) / sur1.r + sur1.n * cos(p1.I) * cos(p1.I) / t);
		s = pp.s_ - pp.Dv;
		s_ = sur1.n_ / ((sur1.n_ * cos(p1.I_) - sur1.n * cos(p1.I)) / sur1.r + sur1.n / s);
	}

    void get_as(double L, double U, double& xt_, double& xs_, double& x_)
    {
        xt_ = t_ * cos(U) - L;
        xs_ = s_ * cos(U) - L;
        x_ = (t_ - s_) * cos(U);
    }

private:
	double PA;
	double PA_;
	double x;
	double x_;
	double s;
	double s_;
	double t;
	double t_;
	double Dv;
};
#endif
