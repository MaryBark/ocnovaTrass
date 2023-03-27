#ifndef TMicsellFunction_CPP
#define TMicsellFunction_CPP

#include "TMicsellFunction.h"


double TMicsellFunction::radians(double degrees)
{
	return degrees*(3.1415926535/180.0);
}

double TMicsellFunction::degrees(double radians)
{
    double deg;
    deg = radians*(180.0/3.1415926532);
    if(deg < 0)
        deg +=360.0;
    else if(deg > 360.0)
        deg -= 360.0;
    return deg;
}

//double TMicsellFunction::deg(double radians)
//{
//    double deg;
////    deg = radians*(180.0/3.1415926532);
////    if(deg < 0)
////        deg +=360.0;
////    else if(deg > 360.0)
////        deg -= 360.0;
//    return deg;
//}

double TMicsellFunction::degreesB(double radians)
{
    double deg;
    deg = radians*(180.0/ M_PI);

    if(deg > 90.0)
    {
        deg = 360 - deg;
    }

    return deg;
}

//------------------------------
double TMicsellFunction::degrees180(double radians)
{
    double deg180;
    deg180 = radians*(180.0/3.1415926532);
    if(deg180 < 0)
        deg180 += 180.0;
    else if(deg180 > 180.0)
        deg180 -= 180.0;
    return deg180;
}

//-----------------------------------------
double TMicsellFunction::VirtelAtan(const double chislitel, const double znamenatel)
{
    double resatan;
    if(chislitel > 0 && znamenatel > 0) // ������ �������� 0 - 90
    {
        resatan = TMicsellFunction::degrees(atan( chislitel / znamenatel ));
        if(resatan < 0)
            resatan += 90.0;
        else if(resatan > 90.0)
            resatan -= 90.0;
        return resatan;
    }
    else if(chislitel > 0 && znamenatel < 0) // ������ �������� 90 - 180
    {
        resatan = TMicsellFunction::degrees(atan(chislitel / znamenatel ));
        if(resatan < 90.0)
            resatan += 90.0;
        else if(resatan > 180.0)
            resatan -= 180.0;
        return resatan;
    }
    else if(chislitel < 0 && znamenatel < 0) // ������ �������� 180 - 270
    {
        resatan = TMicsellFunction::degrees(atan(chislitel / znamenatel));
        if(resatan < 180.0)
            resatan += 180.0;
        else if(resatan > 270.0)
            resatan -= 270.0;
        return resatan;
    }
    else if(chislitel < 0 && znamenatel > 0) // ��������� �������� 270 - 360
    {
        resatan = TMicsellFunction::degrees(atan(chislitel / znamenatel));
        if(resatan < 270)
            resatan += 270.0;
        else if(resatan > 360.0)
            resatan -= 360.0;
        return resatan;
    }
}

//  acos
double TMicsellFunction::VirtelAcos(double chislitel, double znamenatel)
{
    double resacos;
    if(chislitel > 0 && znamenatel > 0) // ������ �������� 0 - 90
    {
        resacos = TMicsellFunction::degrees(acos( chislitel / znamenatel ));
        if(resacos < 0)
            resacos += 90.0;
        else if(resacos > 90.0)
            resacos -= 90.0;
        return resacos;
    }
    else if(chislitel > 0 && znamenatel < 0) // ������ �������� 90 - 180
    {
        resacos = TMicsellFunction::degrees(acos(chislitel / znamenatel ));
        if(resacos < 90.0)
            resacos += 90.0;
        else if(resacos > 180.0)
            resacos -= 180.0;
        return resacos;
    }
    else if(chislitel < 0 && znamenatel < 0) // ������ �������� 180 - 270
    {
        resacos = TMicsellFunction::degrees(acos(chislitel / znamenatel));
        if(resacos < 180.0)
            resacos += 180.0;
        else if(resacos > 270.0)
            resacos -= 270.0;
        return resacos;
    }
    else if(chislitel < 0 && znamenatel > 0) // ��������� �������� 270 - 360
    {
        resacos = TMicsellFunction::degrees(acos(chislitel / znamenatel));
        if(resacos < 270)
            resacos += 270.0;
        else if(resacos > 360.0)
            resacos -= 360.0;
        return resacos;
    }
}

//  asin
double TMicsellFunction::VirtelAsin(double chislitel, double znamenatel)
{
    double resasin;
    if(chislitel > 0 && znamenatel > 0) // ������ �������� 0 - 90
    {
        resasin = TMicsellFunction::degrees(asin( chislitel / znamenatel ));
        if(resasin < 0)
            resasin += 90.0;
        else if(resasin > 90.0)
            resasin -= 90.0;
        return resasin;
    }
    else if(chislitel > 0 && znamenatel < 0) // ������ �������� 90 - 180
    {
        resasin = TMicsellFunction::degrees(asin(chislitel / znamenatel ));
        if(resasin < 90.0)
            resasin += 90.0;
        else if(resasin > 180.0)
            resasin -= 180.0;
        return resasin;
    }
    else if(chislitel < 0 && znamenatel < 0) // ������ �������� 180 - 270
    {
        resasin = TMicsellFunction::degrees(asin(chislitel / znamenatel));
        if(resasin < 180.0)
            resasin += 180.0;
        else if(resasin > 270.0)
            resasin -= 270.0;
        return resasin;
    }
    else if(chislitel < 0 && znamenatel > 0) // ��������� �������� 270 - 360
    {
        resasin = TMicsellFunction::degrees(asin(chislitel / znamenatel));
        if(resasin < 270)
            resasin += 270.0;
        else if(resasin > 360.0)
            resasin -= 360.0;
        return resasin;
    }
}

//
degMinSec TMicsellFunction::degrees2DMS(double deg)
{
    degMinSec dms;
    dms.degrees = int(deg);
    dms.minuta = int((deg - dms.degrees) * 60);
    dms.sekunda = (((deg - dms.degrees) * 60.0) - dms.minuta) * 60.0;
    return dms;
}

//
double TMicsellFunction::DMS2Degrees(degMinSec dms)
{
    return dms.degrees + dms.minuta / 60.0 + dms.sekunda / 3600.0;
}

//
double TMicsellFunction::deg(double radians)
{
    double deg1;
    deg1 = radians*(180.0/3.1415926532);
//    if(deg1 > 0)
//        deg1 -=360.0;
    return deg1;
}

#endif

