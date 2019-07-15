#ifndef LIGHT_H
#define LIGHT_H
#include<vector>
#include<iomanip>
#include"Optics.h"
#include <QTextStream>
#include <QString>
using namespace std;
class Light
{
public:
	Light(){}
	virtual ~Light(){}
    virtual void Initialize(int flag);
protected:
    double L, Y, U, h, W;
	vector<Surface> opt_system;
	vector<Parameter> P_All_Shaft;
    double ideal_L_infinite;
    double ideal_L_finite;
	double actual_L_7_infinite;
	double actual_L_7_finite;
	double actual_L_1_infinite;
	double actual_L_1_finite;
	double actual_y_1_infinite;
	double actual_y_1_finite;
	double actual_y_7_infinite;
    double actual_y_7_finite;
    virtual void Cal_ideal_L_infinite();
    virtual void Cal_ideal_L_finite();
	void aperture_infinite(double Kn);
	void aperture_finite(double Kn);
	vector<Parameter> field_finite(double Kn, double Kw);
	vector<Parameter> field_infinite(double Kn, double Kw);
	void Initialize_off_axis_finite(Parameter& p)
	{
		double a = fabs(L * tan(angle_to_rad(U)));
        double tgU = (Kw * Y - Kn * a) / (-L);
		p.U = atan(tgU);
		p.sinU = sin(p.U);
		p.L = Kn * a / tgU;
	}
	void Initialize_off_axis_infinite(Parameter& p)
	{
        p = Parameter(h);
		p.U = Kw * W;
		p.U = angle_to_rad(p.U);
		p.sinU = sin(p.U);
		p.L = Kn * h / tan(p.U);
	}
	void Cal_actual_y_infinite(double Kw)
	{
        vector<Parameter> P_All_Near = field_infinite(0, Kw);
		if(Kw == 0.7)
            actual_y_7_infinite = -(P_All_Near.back().L_ - ::ideal_L_infinite) * tan(P_All_Near.back().U_);
		else
            actual_y_1_infinite = -(P_All_Near.back().L_ - ::ideal_L_infinite) * tan(P_All_Near.back().U_);
	}
	void Cal_actual_y_finite(double Kw)
	{
        vector<Parameter> P_All_Near = field_finite(0, Kw);
		if (Kw == 0.7)
            actual_y_7_finite = (P_All_Near.back().L_ - ::ideal_L_finite) * tan(P_All_Near.back().U_);
		else
            actual_y_1_finite = (P_All_Near.back().L_ - ::ideal_L_finite) * tan(P_All_Near.back().U_);
	}
public:
    QString show_f()
    {
        QString all;
        all += "焦距 = ";
        all += QString::number(::f_, 'f', 6);
        all += '\n';
        all += "主面位置 = ";
        all += QString::number(::L_H, 'f', 6);
        all += '\n';
        all += "出瞳距 = ";
        all += QString::number(::L_P, 'f', 6);
        all += '\n';
        return all;
    }
    QString show_actual_y(int flag)
    {
        QString all;
        if(flag == 0){
            all += "全视场实际像高 = ";
            all += QString::number(actual_y_1_infinite, 'f', 6);
            all += '\n';
            all += "0.7视场实际像高 = ";
            all += QString::number(actual_y_7_infinite, 'f', 6);
            all += '\n';
        }
        else{
            all += "全视场实际像高 = ";
            all += QString::number(actual_y_1_finite, 'f', 6);
            all += '\n';
            all += "0.7视场实际像高 = ";
            all += QString::number(actual_y_7_finite, 'f', 6);
            all += '\n';
        }
        return all;
    }
    QString show_ideal_L(int flag)
    {
        QString all;
        if(flag == 0){
            all += "理想像距 = ";
            all += QString::number(ideal_L_infinite, 'f', 6);
            all += '\n';
        }
        else{
            all += "理想像距 = ";
            all += QString::number(ideal_L_finite, 'f', 6);
            all += '\n';
        }
        return all;
    }
    QString show_actual_L(int flag)
    {
        QString all;
        if(flag == 0){
            all += "全孔径实际像距离 = ";
            all += QString::number(actual_L_1_infinite, 'f', 6);
            all += '\n';
            all += "0.7孔径实际像距离 = ";
            all += QString::number(actual_L_7_infinite, 'f', 6);
            all += '\n';
        }
        else{
            all += "全孔径实际像距离 = ";
            all += QString::number(actual_L_1_finite, 'f', 6);
            all += '\n';
            all += "0.7孔径实际像距离 = ";
            all += QString::number(actual_L_7_finite, 'f', 6);
            all += '\n';
        }
        return all;
    }
};


class Light_d : public Light
{
public:
	Light_d(){}
    Light_d(double L, double Y, double U, vector<Surface> opt_system);
    Light_d(double h, double W, vector<Surface> opt_system);
    void Initialize_d(int flag);
    void show(int flag, QTextStream& out)
    {
        out << (QString)"f` = " << f_ << "\n";
        out << (QString)"L_H` = " << L_H << "\n";
        out << (QString)"L_P` = " << L_P << "\n";
        if(flag == 0)
        {
            out << (QString)"Light d\n";
            out << (QString)"ideal_y` = " << ideal_y_1_infinite << (QString)"(Kw = 1)\n";
            out << (QString)"ideal_y` = " << ideal_y_7_infinite << (QString)"(Kw = 0.7)\n";
            out << (QString)"ideal_L` = " << ideal_L_infinite << "\n";
            out << (QString)"actual_L` = " << actual_L_1_infinite << (QString)"(Kn = 1)\n";
            out << (QString)"actual_L` = " << actual_L_7_infinite << (QString)"(Kn = 0.7)\n";
            out << (QString)"actual_y` = " << actual_y_1_infinite << (QString)"(Kn = 1)\n";
            out << (QString)"actual_y` = " << actual_y_7_infinite << (QString)"(Kn = 0.7)\n";
            out << (QString)"coma = " << coma_1_1_infinite << (QString)"(Kn = 1, Kw = 1)\n";
            out << (QString)"coma = " << coma_1_7_infinite << (QString)"(Kn = 1, Kw = 0.7)\n";
            out << (QString)"coma = " << coma_7_1_infinite << (QString)"(Kn = 0.7, Kw = 1)\n";
            out << (QString)"coma = " << coma_7_7_infinite << (QString)"(Kn = 0.7, Kw = 0.7)\n";
            out << (QString)"xt` = " << xt_infinite << "\n";
            out << (QString)"xs` = " << xs_infinite << "\n";
            out << (QString)"x` = " << x_infinite << "\n";
            out << (QString)"Spherical_aberration = " << Sa_1_infinite << (QString)"(Kn = 1)" << "\n";
            out << (QString)"Spherical_aberration = " << Sa_7_infinite << (QString)"(Kn = 0.7)" << "\n";
            out << (QString)"absolute_distortion = " << absolute_ds_1_infinite << (QString)"(Kw = 1)" << "\n";
            out << (QString)"absolute_distortion = " << absolute_ds_7_infinite << (QString)"(Kw = 0.7)" << "\n";
            out << (QString)"relative_distortion  = " << relative_ds_1_infinite << (QString)"(Kw = 1)" << "\n";
            out << (QString)"relative_distortion = " << relative_ds_7_infinite << (QString)"(Kw = 0.7)" << "\n";
        }
        else{
            out << (QString)"Light d" << "\n";
            out << (QString)"ideal_y` = " << ideal_y_1_finite << (QString)"(Kw = 1)"  << "\n";
            out << (QString)"ideal_y` = " << ideal_y_7_finite << (QString)"(Kw = 0.7)" << "\n";
            out << (QString)"ideal_L` = " << ideal_L_finite << "\n";
            out << (QString)"actual_L` = " << actual_L_1_finite << (QString)"(Kn = 1)" << "\n";
            out << (QString)"actual_L` = " << actual_L_7_finite << (QString)"(Kn = 0.7)" << "\n";
            out << (QString)"actual_y` = " << actual_y_1_finite << (QString)"(Kn = 1)" << "\n";
            out << (QString)"actual_y` = " << actual_y_7_finite << (QString)"(Kn = 0.7)" << "\n";
            out << (QString)"coma = " << coma_1_1_finite << (QString)"(Kn = 1, Kw = 1)" << "\n";
            out << (QString)"coma = " << coma_1_7_finite << (QString)"(Kn = 1, Kw = 0.7)" << "\n";
            out << (QString)"coma = " << coma_7_1_finite << (QString)"(Kn = 0.7, Kw = 1)" << "\n";
            out << (QString)"coma = " << coma_7_7_finite << (QString)"(Kn = 0.7, Kw = 0.7)" << "\n";
            out << (QString)"xt` = " << xt_finite << "\n";
            out << (QString)"xs` = " << xs_finite << "\n";
            out << (QString)"x` = " << x_finite << "\n";
            out << (QString)"Spherical_aberration = " << Sa_1_finite << (QString)"(Kn = 1)" << "\n";
            out << (QString)"Spherical_aberration = " << Sa_7_finite << (QString)"(Kn = 0.7)" << "\n";
            out << (QString)"absolute_distortion = " << absolute_ds_1_finite << (QString)"(Kw = 1)" << "\n";
            out << (QString)"absolute_distortion = " << absolute_ds_7_finite << (QString)"(Kw = 0.7)" << "\n";
            out << (QString)"relative_distortion  = " << relative_ds_1_finite << (QString)"(Kw = 1)" << "\n";
            out << (QString)"relative_distortion = " << relative_ds_7_finite << (QString)"(Kw = 0.7)" << "\n";
        }
    }
    QString Sa_show(int flag)
    {
        QString all;
        if(flag == 0){
            all += "全孔径球差 = ";
            all += QString::number(Sa_1_infinite, 'f', 6);
            all += '\n';
            all += "0.7孔径球色差 = ";
            all += QString::number(Sa_7_infinite, 'f', 6);
            all += '\n';
        }
        else{
            all += "全孔径球色差 = ";
            all += QString::number(Sa_1_finite, 'f', 6);
            all += '\n';
            all += "0.7孔径球色差 = ";
            all += QString::number(Sa_7_finite, 'f', 6);
            all += '\n';
        }
        return all;
    }
    QString coma_show(int flag)
    {
        QString all;
        if(flag == 0){
            all += "全孔径全视场子午彗差 = ";
            all += QString::number(coma_1_1_infinite, 'f', 6);
            all += '\n';
            all += "0.7孔径全视场子午彗差 = ";
            all += QString::number(coma_7_1_infinite, 'f', 6);
            all += '\n';
            all += "全孔径0.7视场子午彗差 = ";
            all += QString::number(coma_1_7_infinite, 'f', 6);
            all += '\n';
            all += "0.7孔径0.7视场子午彗差 = ";
            all += QString::number(coma_7_7_infinite, 'f', 6);
            all += '\n';
       }
       else{
            all += "全孔径全视场子午彗差 = ";
            all += QString::number(coma_1_1_finite, 'f', 6);
            all += '\n';
            all += "0.7孔径全视场子午彗差 = ";
            all += QString::number(coma_7_1_finite, 'f', 6);
            all += '\n';
            all += "全孔径0.7视场子午彗差 = ";
            all += QString::number(coma_1_7_finite, 'f', 6);
            all += '\n';
            all += "0.7孔径0.7视场子午彗差 = ";
            all += QString::number(coma_7_7_finite, 'f', 6);
            all += '\n';
       }
       return all;
    }
    QString As_show(int flag)
    {
        QString all;
        if(flag == 0){
            all += "子午场曲 = ";
            all += QString::number(xt_infinite, 'f', 6);
            all += '\n';
            all += "弧矢场曲 = ";
            all += QString::number(xs_infinite, 'f', 6);
            all += '\n';
            all += "像散 = ";
            all += QString::number(x_infinite, 'f', 6);
            all += '\n';
        }
        else{
            all += "子午场曲 = ";
            all += QString::number(xt_finite, 'f', 6);
            all += '\n';
            all += "弧矢场曲 = ";
            all += QString::number(xs_finite, 'f', 6);
            all += '\n';
            all += "像散 = ";
            all += QString::number(x_finite, 'f', 6);
            all += '\n';
        }
        return all;
    }
    QString dis_show(int flag)
    {
        QString all;
        if(flag == 0){
            all += "全视场绝对畸变 = ";
            all += QString::number(absolute_ds_1_infinite, 'f', 6);
            all += '\n';
            all += "0.7绝对畸变 = ";
            all += QString::number(absolute_ds_7_infinite, 'f', 6);
            all += '\n';
            all += "全视场相对畸变 = ";
            all += QString::number(relative_ds_1_infinite, 'f', 6);
            all += '\n';
            all += "0.7视场相对畸变 = ";
            all += QString::number(relative_ds_7_infinite, 'f', 6);
            all += '\n';
        }
        else{
            all += "全视场绝对畸变 = ";
            all += QString::number(absolute_ds_1_finite, 'f', 6);
            all += '\n';
            all += "0.7绝对畸变 = ";
            all += QString::number(absolute_ds_7_finite, 'f', 6);
            all += '\n';
            all += "全视场相对畸变 = ";
            all += QString::number(relative_ds_1_finite, 'f', 6);
            all += '\n';
            all += "0.7视场相对畸变 = ";
            all += QString::number(relative_ds_7_finite, 'f', 6);
            all += '\n';
        }
        return all;
    }
    QString show_ideal_y(int flag)
    {
        QString all;
        if(flag == 0){
            all += "全视场理想像高 = ";
            all += QString::number(ideal_y_1_infinite, 'f', 6);
            all += '\n';
            all += "0.7视场理想像高 = ";
            all += QString::number(ideal_y_7_infinite, 'f', 6);
            all += '\n';
        }
        else{
            all += "全视场理想像高 = ";
            all += QString::number(ideal_y_1_finite, 'f', 6);
            all += '\n';
            all += "0.7视场理想像高 = ";
            all += QString::number(ideal_y_7_finite, 'f', 6);
            all += '\n';
        }
        return all;
    }
    virtual void Cal_ideal_L_infinite();
    virtual void Cal_ideal_L_finite();
    ~Light_d(){}
private:
    void Cal_f_();
    void Cal_L_P();
    void Cal_L_H(int flag);
    void Cal_ideal_y_infinite()
    {
        ideal_y_1_infinite = f_ * tan(angle_to_rad(W));
        ideal_y_7_infinite = f_ * tan(angle_to_rad(0.7*W));
    }
    void Cal_ideal_y_finite()
    {
        Kn = 0.0001; Kw = 0;
        Parameter p(L, U);
        vector<Parameter> P_All_Shaft;
        for (int i = 0; i < opt_system.size(); i++)
        {
            opt_system[i].Calculate1(p, P_All_Shaft);
        }
        double A = opt_system.front().n * P_All_Shaft.front().U;
        double A_ = opt_system.back().n_ * P_All_Shaft.back().U_;
        ideal_y_1_finite = A * Y / A_;
        ideal_y_7_finite = A*0.7*Y /A_;
    }

    void SetK(double Kn, double Kw, vector<Parameter>& P_All_Near_main, vector<Parameter>& P_All_Near_up, vector<Parameter>& P_All_Near_down)
    {
        P_All_Near_main = field_infinite(0, Kw);
        P_All_Near_up = field_infinite(Kn, Kw);
        P_All_Near_down = field_infinite(-Kn, Kw);
    }
    void SetK_finite(double Kn, double Kw, vector<Parameter>& P_All_Near_main, vector<Parameter>& P_All_Near_up, vector<Parameter>& P_All_Near_down)
    {
        P_All_Near_main = field_finite(0, Kw);
        P_All_Near_up = field_finite(Kn, Kw);
        P_All_Near_down = field_finite(-Kn, Kw);
    }

    void Cal_abc(int flag, double &a, double &b, double &c, vector<Parameter>& P_All_Near_main, vector<Parameter>& P_All_Near_up, vector<Parameter>& P_All_Near_down)
    {
        if(flag == 0){
            a = (P_All_Near_up.back().L_ - ideal_L_infinite) * tan(P_All_Near_up.back().U_);
            b = (P_All_Near_down.back().L_ - ideal_L_infinite) * tan(P_All_Near_down.back().U_);
            c = (P_All_Near_main.back().L_ - ideal_L_infinite) * tan(P_All_Near_main.back().U_);
        }
        else{
            a = (P_All_Near_up.back().L_ - ideal_L_finite) * tan(P_All_Near_up.back().U_);
            b = (P_All_Near_down.back().L_ - ideal_L_finite) * tan(P_All_Near_down.back().U_);
            c = (P_All_Near_main.back().L_ - ideal_L_finite) * tan(P_All_Near_main.back().U_);
        }
    }

    void Cal_Spherical_aberration_finite()
    {
        Sa_7_finite = actual_L_7_finite - ideal_L_finite;
        Sa_1_finite = actual_L_1_finite - ideal_L_finite;
    }
    void Cal_Spherical_aberration_infinite()
    {
        Sa_7_infinite = actual_L_7_infinite - ideal_L_infinite;
        Sa_1_infinite = actual_L_1_infinite - ideal_L_infinite;
    }
    void astigmatism()
    {
        vector<Parameter> P_All_Near = field_infinite(0, 1);
        Parameter_plus pp;
        int k = opt_system.size();
        for (int i = 0; i < k; i++) {
            if (i == 0)
                pp.Calculate_infinite(P_All_Near, opt_system, i);
            else if (i != k - 1) {
                pp.Calculate(P_All_Near, opt_system, i, pp);
            }
            else {
                pp.Calculate_final(P_All_Near, opt_system, i, pp);
            }
        }
        pp.get_as(ideal_L_infinite, P_All_Near.back().U_, xt_infinite, xs_infinite, x_infinite);
    }
    void astigmatism(double L)
    {
        vector<Parameter> P_All_Near = field_finite(0, 1);
        Parameter_plus pp;
        int k = opt_system.size();
        for (int i = 0; i < k; i++) {
            if (i == 0)
                pp.Calculate(L, P_All_Near, opt_system, i);
            else if (i != k - 1) {
                pp.Calculate(P_All_Near, opt_system, i, pp);
            }
            else {
                pp.Calculate_final(P_All_Near, opt_system, i, pp);
            }
        }
        pp.get_as(ideal_L_finite, P_All_Near.back().U_, xt_finite, xs_finite, x_finite);
    }
    void Cal_disortion(int flag)
    {
        if(flag == 0){
            absolute_ds_7_infinite = ideal_y_7_infinite - actual_y_7_infinite;
            relative_ds_7_infinite = absolute_ds_7_infinite / ideal_y_7_infinite;
            absolute_ds_1_infinite = ideal_y_1_infinite - actual_y_1_infinite;
            relative_ds_1_infinite = absolute_ds_1_infinite / ideal_y_1_infinite;
        }
        else{
            absolute_ds_7_finite = ideal_y_7_finite - actual_y_7_finite;
            relative_ds_7_finite = absolute_ds_7_finite / ideal_y_7_finite;
            absolute_ds_1_finite = ideal_y_1_finite - actual_y_1_finite;
            relative_ds_1_finite = absolute_ds_1_finite / ideal_y_1_finite;
        }
    }
    void Cal_coma(int flag)
    {
        vector<Parameter> P_All_Near_main;
        vector<Parameter> P_All_Near_up;
        vector<Parameter> P_All_Near_down;
        double a, b, c;
        if(flag == 0){
            SetK(1,1,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            Cal_abc(0,a, b, c,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            coma_1_1_infinite = 0.5*(a+b)-c;
            SetK(1,0.7,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            Cal_abc(0,a, b, c,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            coma_1_7_infinite = 0.5*(a+b)-c;
            SetK(0.7,1,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            Cal_abc(0,a, b, c,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            coma_7_1_infinite = 0.5*(a+b)-c;
            SetK(0.7,0.7,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            Cal_abc(0,a, b, c,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            coma_7_7_infinite = 0.5*(a+b)-c;
        }
        else{
            SetK_finite(1,1,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            Cal_abc(1,a, b, c,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            coma_1_1_finite = 0.5*(a+b)-c;
            SetK_finite(1,0.7,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            Cal_abc(1,a, b, c,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            coma_1_7_finite = 0.5*(a+b)-c;
            SetK_finite(0.7,1,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            Cal_abc(1,a, b, c,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            coma_7_1_finite = 0.5*(a+b)-c;
            SetK_finite(0.7,0.7,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            Cal_abc(1,a, b, c,P_All_Near_main, P_All_Near_up, P_All_Near_down);
            coma_7_7_finite = 0.5*(a+b)-c;
        }
    }

    double ideal_y_1_infinite;
    double ideal_y_1_finite;
    double ideal_y_7_infinite;
    double ideal_y_7_finite;
	double Sa_7_infinite, Sa_1_infinite;
	double Sa_7_finite, Sa_1_finite;
	double xt_infinite, xs_infinite, x_infinite;
	double xt_finite, xs_finite, x_finite;
    double absolute_ds_7_infinite, absolute_ds_1_infinite;
    double relative_ds_7_infinite, relative_ds_1_infinite;
    double absolute_ds_7_finite, absolute_ds_1_finite;
    double relative_ds_7_finite, relative_ds_1_finite;
    double coma_1_1_infinite, coma_1_7_infinite, coma_7_1_infinite, coma_7_7_infinite;
    double coma_1_1_finite, coma_1_7_finite, coma_7_1_finite, coma_7_7_finite;
};

class Light_f;

class Light_c : public Light
{
    friend class Light_f;
public:
    Light_c(){}
    Light_c(double L, double y, double U, vector<Surface> opt_system);
    Light_c(double h, double W, vector<Surface> opt_system);
    void show(int flag, QTextStream& out)
    {
        if(flag == 0)
        {
            out << (QString)"Light c" << "\n";
            out << (QString)"ideal_L` = " << ideal_L_infinite << "\n";
            out << (QString)"actual_L` = " << actual_L_1_infinite << (QString)"(Kn = 1)" << "\n";
            out << (QString)"actual_L` = " << actual_L_7_infinite << (QString)"(Kn = 0.7)" << "\n";
            out << (QString)"actual_y` = " << actual_y_1_infinite << (QString)"(Kn = 1)" << "\n";
            out << (QString)"actual_y` = " << actual_y_7_infinite << (QString)"(Kn = 0.7)" << "\n";
            }
        else{
            out << (QString)"Light c" << "\n";
            out << (QString)"ideal_L` = " << ideal_L_finite << "\n";
            out << (QString)"actual_L` = " << actual_L_1_finite << (QString)"(Kn = 1)" << "\n";
            out << (QString)"actual_L` = " << actual_L_7_finite << (QString)"(Kn = 0.7)" << "\n";
            out << (QString)"actual_y` = " << actual_y_1_finite << (QString)"(Kn = 1)" << "\n";
            out << (QString)"actual_y` = " << actual_y_7_finite << (QString)"(Kn = 0.7)" << "\n";
        }
    }
    ~Light_c(){}

private:

};

class Light_f : public Light
{
public:
	Light_f(){}
    Light_f(double L, double y, double U, vector<Surface> opt_system);
    Light_f(double h, double W, vector<Surface> opt_system);
    void show(int flag, QTextStream& out)
    {
        if(flag == 0)
        {
            out << (QString)"Light f" << "\n";
            out << (QString)"ideal_L` = " << ideal_L_infinite << "\n";
            out << (QString)"actual_L` = " << actual_L_1_infinite << (QString)"(Kn = 1)" << "\n";
            out << (QString)"actual_L` = " << actual_L_7_infinite << (QString)"(Kn = 0.7)" << "\n";
            out << (QString)"actual_y` = " << actual_y_1_infinite << (QString)"(Kn = 1)" << "\n";
            out << (QString)"actual_y` = " << actual_y_7_infinite << (QString)"(Kn = 0.7)" << "\n";
            out << (QString)"Position_Chromatic_Aberration = " << PCA_1_infinite << (QString)"(Kw = 1)" << "\n";
            out << (QString)"Position_Chromatic_Aberration = " << PCA_7_infinite << (QString)"(Kw = 0.7)" << "\n";
            out << (QString)"Lateral_Chromatic_Aberration  = " << LCA_1_infinite << (QString)"(Kw = 1)" << "\n";
            out << (QString)"Lateral_Chromatic_Aberration  = " << LCA_7_infinite << (QString)"(Kw = 0.7)" << "\n";

            }
        else{
            out << (QString)"Light f" << "\n";
            out << (QString)"ideal_L` = " << ideal_L_finite << "\n";
            out << (QString)"actual_L` = " << actual_L_1_finite << (QString)"(Kn = 1)" << "\n";
            out << (QString)"actual_L` = " << actual_L_7_finite << (QString)"(Kn = 0.7)" << "\n";
            out << (QString)"actual_y` = " << actual_y_1_finite << (QString)"(Kn = 1)" << "\n";
            out << (QString)"actual_y` = " << actual_y_7_finite << (QString)"(Kn = 0.7)" << "\n";
            out << (QString)"Position_Chromatic_Aberration = " << PCA_1_finite << (QString)"(Kw = 1)" << "\n";
            out << (QString)"Position_Chromatic_Aberration = " << PCA_7_finite << (QString)"(Kw = 0.7)" << "\n";
            out << (QString)"Lateral_Chromatic_Aberration  = " << LCA_1_finite << (QString)"(Kw = 1)" << "\n";
            out << (QString)"Lateral_Chromatic_Aberration  = " << LCA_7_finite << (QString)"(Kw = 0.7)" << "\n";
        }
    }
    QString Ca_show(int flag)
    {
        QString all;
        if(flag == 0){
            all += "全孔径位置色差 = ";
            all += QString::number(PCA_1_infinite, 'f', 6);
            all += '\n';
            all += "0.7孔径位置色差 = ";
            all += QString::number(PCA_7_infinite, 'f', 6);
            all += '\n';
            all += "全视场倍率色差 = ";
            all += QString::number(LCA_1_infinite, 'f', 6);
            all += '\n';
            all += "0.7视场倍率色差 = ";
            all += QString::number(LCA_7_infinite, 'f', 6);
        }
        else{
            all += "全孔径位置色差 = ";
            all += QString::number(PCA_1_finite, 'f', 6);
            all += '\n';
            all += "0.7孔径位置色差 = ";
            all += QString::number(PCA_7_finite, 'f', 6);
            all += '\n';
            all += "全视场倍率色差 = ";
            all += QString::number(LCA_1_finite, 'f', 6);
            all += '\n';
            all += "0.7视场倍率色差 = ";
            all += QString::number(LCA_7_finite, 'f', 6);
        }
        return all;
    }

    ~Light_f(){}
    void Cal_Chromatic_Aberration(int flag, Light_c &c)
    {
        Cal_Position_Chromatic_Aberration(flag, c);
        Cal_Lateral_Chromatic_Aberration(flag, c);
    }

private:
    void Cal_Position_Chromatic_Aberration(int flag, Light_c &c)
    {
        if(flag == 0){
            PCA_1_infinite = actual_L_1_infinite - c.actual_L_1_infinite;
            PCA_7_infinite = actual_L_7_infinite - c.actual_L_7_infinite;
        }
        else{
            PCA_1_finite = actual_L_1_finite - c.actual_L_1_finite;
            PCA_7_finite = actual_L_7_finite - c.actual_L_7_finite;
        }
    }

    void Cal_Lateral_Chromatic_Aberration(int flag, Light_c &c)
    {
        if(flag == 0){
            LCA_1_infinite = actual_y_1_infinite - c.actual_y_1_infinite;
            LCA_7_infinite = actual_y_7_infinite - c.actual_y_7_infinite;
        }
        else{
            LCA_1_finite = actual_y_1_finite - c.actual_y_1_finite;
            LCA_7_finite = actual_y_7_finite - c.actual_y_7_finite;
        }
    }

    double LCA_1_infinite, LCA_7_infinite;
    double LCA_1_finite, LCA_7_finite;
    double PCA_1_infinite, PCA_7_infinite;
    double PCA_1_finite, PCA_7_finite;
};
#endif
