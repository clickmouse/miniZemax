#include "Optics.h"
const double PI = 3.14159265;
double Kn = 1, Kw = 0;
double f_, L_H, L_P;
int flag;
double h, W, L, Y, U;
double ideal_L_infinite;
double ideal_L_finite;

double angle_to_rad(double U)
{
    U = U * PI / 180;
    return U;
}
double rad_to_angle(double U)
{
    U = U * 180 / PI;
    return U;
}

