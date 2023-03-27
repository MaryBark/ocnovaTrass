#pragma once
#ifndef TMicsellFunction_H
#define TMicsellFunction_H

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

	
    const double C_Pi = 3.1415926535;
    const double C_k = 2.414213562373095;

    const double C_Kelvin = 273.15;

    const double C_ConstStefBolzman = 5.67*pow(10.0,-8);
    const double C_TempBlakBody = 5800.0;

    const double C_SunRadius = 6.96*pow(10.0,8);

    const double C_EquTempKosmos = 3.0;

    const double C_AE = 149597870700.0;

    const double C_RadianceSun = 10000.0;

    const double C_OneArkMinute =0.00029088820866572;

    const double C_ApparAnglRadSun = 16*C_OneArkMinute;
    const double C_SpeedOfLight = 299792458.0;

    const double C_GravConst = 6.6738480E-10;

    const double C_MassaErde = 5.9726E24;

	const double C_g = 9.81;

    const double C_RadiusErde = 6378137.0;

    const double C_Mu = 398600441800000.0;

    const double C_ConstBolzman = 1.380648813;

    const double C_m = 0.029;



    const double C_Emax = 3.0;

    const double C_T0 = 290.0;

    const double C_Tnsr = 5.0;

    const double C_Tpr = 1500.0;


	const double C_Transfusion = 0.025;

	const double C_sigmaA = 4.0e-3;

	const double C_alfa2 = (1.0 - 2.0 * C_Transfusion) * (1.0 - 2.0 * C_Transfusion);

    const double C_n = 4.0;
    const double C_P0 = 4.5606 * pow(10, -6);

    const double C_fmM = 4.902799 * pow(10, 3);

    const double C_fmS = 1.32712438 * pow(10, 11);

    const double C_RadiusErdekm = 6378.14;

    const double C_sgatieErde = 1/298.257;

    const double C_J2 = 108455.0 * pow(10, -7);

    const double C_wz = 7.292115078*pow(10, -5);

    const double C_deltaUT = 0.9;

    const double C_rs = 0.017453292519943296;

struct koordSkorost
{
    double s_x;
    double s_y;
    double s_z;
    double s_vx;
    double s_vy;
    double s_vz;
};


struct koordSun
{
    double s_Xs;
    double s_Ys;
    double s_Zs;
};


struct koordMoon
{
    double s_Xm;
    double s_Ym;
    double s_Zm;
};


struct degMinSec
{
    unsigned degrees;
    unsigned minuta;
    double sekunda;
};


struct FiLambdaR
{
    double s_fi;
    double s_lambda;
    double s_RV;
};


class TMicsellFunction
{
public:

	static double radians(double degrees);

	static double degrees(double radians);
//    static double deg(double radians);

    static double degreesB(double radians);


    static double degrees180(double radians);


    static double VirtelAtan(const double chislitel, const double znamenatel);


    static double VirtelAcos(double chislitel, double znamenatel);


    static double VirtelAsin(double chislitel, double znamenatel);


    static degMinSec degrees2DMS(double deg);


    static double DMS2Degrees(degMinSec dms);


    static double deg(double radians);

};

#endif
