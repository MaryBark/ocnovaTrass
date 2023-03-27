#ifndef XYZ2BLH_H
#define XYZ2BLH_H

#include <QString>
#include "definitions.h"
#include "coordinateVectors.h"
#include "TMicsellFunction.h"

class xyz2blh
{
public:
//    xyz2blh();

    static bool XYZ_2_BLH_R( double *mq3,double &Br,double &Lr,double &h,double &R, int SK = 0,double eps = 1e-9);

    static coordVectorBLH<double> XYZ_2_BLH( double x, double y,double z, double &R, int SK = 0,double eps = 1e-9);

    static coordVectorBLH<double> XYZ_2_BLH( double x, double y,double z);


};

#endif // XYZ2BLH_H
