#include "Light.h"
#include <QDebug>
void Light::Initialize(int flag)
{
    if(flag == 0){
        aperture_infinite(1);
        aperture_infinite(0.7);
        Cal_ideal_L_infinite();
        Cal_actual_y_infinite(1);
        Cal_actual_y_infinite(0.7);
    }
    else{
        aperture_finite(1);
        aperture_finite(0.7);
        Cal_ideal_L_finite();
        Cal_actual_y_finite(1);
        Cal_actual_y_finite(0.7);
    }
}

void Light::Cal_ideal_L_infinite()
{
    Parameter p(0.00000001 *h);
    vector<Parameter> P;
	for (int i = 0; i < opt_system.size(); i++)
	{
		if (i == 0)
            opt_system[i].Calculate0(p, P);
		else
            opt_system[i].Calculate1(p, P);
	}
    ideal_L_infinite = P.back().L_;
}

void Light_d::Cal_ideal_L_infinite()
{
    h = ::h;
    Parameter p(0.00000001 *h);
    vector<Parameter> P;
    for (int i = 0; i < opt_system.size(); i++)
    {
        if (i == 0)
            opt_system[i].Calculate0(p, P);
        else
            opt_system[i].Calculate1(p, P);
    }
    ideal_L_infinite = P.back().L_;
    ::ideal_L_infinite = P.back().L_;
}

void Light::Cal_ideal_L_finite()
{
	Kn = 0.0001; Kw = 0;
	Parameter p(L, U);
	vector<Parameter> P_All_Shaft;
	for (int i = 0; i < opt_system.size(); i++)
	{
		opt_system[i].Calculate1(p, P_All_Shaft);
	}
	ideal_L_finite = P_All_Shaft.back().L_;
}

void Light_d::Cal_ideal_L_finite()
{
    Kn = 0.0001; Kw = 0;
    Parameter p(L, U);
    vector<Parameter> P_All_Shaft;
    for (int i = 0; i < opt_system.size(); i++)
    {
        opt_system[i].Calculate1(p, P_All_Shaft);
    }
    ideal_L_finite = P_All_Shaft.back().L_;
    ::ideal_L_finite = ideal_L_finite;
}

void Light::aperture_infinite(double Kn)
{
	::Kw = 0;
	::Kn = Kn;
	Parameter p(Kn * h);
	for (int i = 0; i < opt_system.size(); i++)
	{
		if (i == 0)
			opt_system[i].Calculate0(p, P_All_Shaft);
		else
			opt_system[i].Calculate1(p, P_All_Shaft);
	}
	if (Kn == 1) {
		actual_L_1_infinite = P_All_Shaft.back().L_;
	}
	else {
		actual_L_7_infinite = P_All_Shaft.back().L_;
	}
}

void Light::aperture_finite(double Kn)
{
	::Kn = Kn;
	::Kw = 0;
	Parameter p = Parameter(L, U);
	for (int i = 0; i < opt_system.size(); i++)
	{
		opt_system[i].Calculate1(p, P_All_Shaft);
	}
	if (Kn == 1) {
		actual_L_1_finite = P_All_Shaft.back().L_;
	}
	else {
		actual_L_7_finite = P_All_Shaft.back().L_;
	}
}

vector<Parameter> Light::field_finite(double Kn, double Kw)
{
	::Kn = Kn;
	::Kw = Kw;
	Parameter p;
	vector<Parameter> P_All_Near;
	Initialize_off_axis_finite(p);
	for (int i = 0; i < opt_system.size(); i++)
	{
		opt_system[i].Calculate1(p, P_All_Near);
	}
	return P_All_Near;
}

vector<Parameter> Light::field_infinite(double Kn, double Kw)
{
	::Kn = Kn;
	::Kw = Kw;
	Parameter p;
	vector<Parameter> P_All_Near;
	Initialize_off_axis_infinite(p);
	for (int i = 0; i < opt_system.size(); i++)
	{
		opt_system[i].Calculate1(p, P_All_Near);
	}
	return P_All_Near;
}


Light_d::Light_d(double L, double Y, double U, vector<Surface> opt_system)
{
	this->L = L;
    this->Y = Y;
	this->U = U;
	this->opt_system.assign(opt_system.begin(), opt_system.end());
}

Light_d::Light_d(double h, double W, vector<Surface> opt_system)
{
	this->h = h;
	this->W = W;
	this->opt_system.assign(opt_system.begin(), opt_system.end());
}

void Light_d::Initialize_d(int flag)
{
    Cal_f_();
    if(flag == 0){
        Cal_Spherical_aberration_infinite();
        ::ideal_L_infinite = ideal_L_infinite;
        Cal_ideal_y_infinite();
        astigmatism();
    }
    else{
        Cal_Spherical_aberration_finite();
        ::ideal_L_finite = ideal_L_finite;
        Cal_ideal_y_finite();
        astigmatism(L);
    }
    Cal_L_P();
    Cal_L_H(flag);
    Cal_coma(flag);
    Cal_disortion(flag);
}

void Light_d::Cal_f_()
{
	double h = 0.01;
	Parameter p(h);
	vector<Parameter> P_All_Shaft;
	for (int i = 0; i < opt_system.size(); i++)
	{
		if (i == 0)
			opt_system[i].Calculate0(p, P_All_Shaft);
		else
			opt_system[i].Calculate1(p, P_All_Shaft);
	}
	f_ = h / tan(P_All_Shaft.back().U_);
}

void Light_d::Cal_L_P()
{
    vector<Parameter> P;
    ::Kn = 1;
	Parameter p = Parameter(0, 0.001);
	for (int i = 0; i < opt_system.size(); i++)
	{
        opt_system[i].Calculate1(p, P);
	}
    L_P = P.back().L_;
}

void Light_d::Cal_L_H(int flag)
{

    L_H = ideal_L_infinite - f_;
}

Light_f::Light_f(double L, double Y, double U, vector<Surface> opt_system)
{
    this->L = L;
    this->Y = Y;
    this->U = U;
    this->opt_system.assign(opt_system.begin(), opt_system.end());
}

Light_f::Light_f(double h, double W, vector<Surface> opt_system)
{
    this->h = h;
    this->W = W;
    this->opt_system.assign(opt_system.begin(), opt_system.end());
}


Light_c::Light_c(double L, double Y, double U, vector<Surface> opt_system)
{
    this->L = L;
    this->Y= Y;
    this->U = U;
    this->opt_system.assign(opt_system.begin(), opt_system.end());
}

Light_c::Light_c(double h, double W, vector<Surface> opt_system)
{
    this->h = h;
    this->W = W;
    this->opt_system.assign(opt_system.begin(), opt_system.end());
}
