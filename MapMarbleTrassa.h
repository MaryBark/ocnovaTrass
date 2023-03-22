#ifndef MAPMARBLETRASSA_H
#define MAPMARBLETRASSA_H

#include <vector>
#include "coordinateVectors.h"
#include "xyz2blh.h"

using namespace std;

class MapMarbleTrassa
{
public:
//    MapMarbleTrassa();

    static vector<coordVectorBLH<double>> buildingRouteKA();

    static vector<double> Runge_Kutta(vector<double> init_coord, vector<double> acc,int n,int h);
};

#endif // MAPMARBLETRASSA_H
