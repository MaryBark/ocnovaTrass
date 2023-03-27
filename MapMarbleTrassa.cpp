#include "MapMarbleTrassa.h"

#include <math.h>
#include <QByteArray>


//MapMarbleTrassa::MapMarbleTrassa()
//{


//    if (!ui->cB_showSat->isChecked())
//        updateSourceSatPos();

//    SNCode::Map<QMap<QDateTime, MVectorBLH<double> > > mapCoordSat;
//    SNCode::Map<QColor> mapColorOrbit;

//    showSatellitesSettings sets = panelSatWgt->settings();

//    QDateTime dt_begin = sets.dtInterval.first;
//    QDateTime dt_end = sets.dtInterval.second;

//    foreach (QString sat, panelSatWgt->satChecked())
//    {
//        SNCode id_sat = SNCode::fromString(sat);

//        int step = sets.stepTrackGnss;
//        if (id_sat.isLEO() || id_sat.isMCC())
//            step = sets.stepTrackLeo;

//        QString sourceType = panelSatWgt->sourceTypeGnss()[SNCode::fromString(sat).type()];

//        int countIter = static_cast<int>((NTime(dt_end) - NTime(dt_begin))/step);

//        for (int i = 0; i <= countIter; ++i)
//        {
//            QDateTime dt = dt_begin.addSecs(i*step);
//            mapCoordSat[sat][dt] = satData->getBLH(sourceType, sat, NTime(dt), coordSys);
//        }

//        mapColorOrbit[sat] = panelSatWgt->getColor(id_sat);
//    }

//    w->setMapCoordSat(mapCoordSat);
    //    w->setMapColorOrbit(mapColorOrbit);
//}

void array_proc(double *array_first, double **array_second, int ARRAY_ROWS, int ARRAY_COLUMNS)
{
    int i, j;
    for (i = 0; i < ARRAY_ROWS; i++) {
        for (j = 0; j < ARRAY_COLUMNS; j++) {
            array_second[i][j] = array_first[ARRAY_ROWS * ARRAY_COLUMNS - i * ARRAY_COLUMNS - j - 1];
        }
    }
}


vector<coordVectorBLH<double>> MapMarbleTrassa::buildingRouteKA()
{
    // координаты левого рандомного спутника и пес с ним((((
    vector<double> init_coord(6);
    vector<double> acc(6);
    init_coord[0]=-0.615996679688*pow(10.0,4)*1000; // в метрах эта ересь
    init_coord[1]=-0.157834936523*pow(10.0,5)*1000;
    init_coord[2]=0.190386489258*pow(10.0,5)*1000;
    init_coord[3]=0.387048721313*1000;
    init_coord[4]=-0.258716773987*pow(10.0,1)*1000;
    init_coord[5]=-0.201687240601*pow(10.0,1)*1000;

    acc[0]=0.931322574616*pow(10.0,-9)*1000;
    acc[1]=0.000000000000*1000;
    acc[2]=-0.279396772385*pow(10.0,-8)*1000;

    int n=1115;
    int h=150;

    double CHUR[3],GOLD[3],SCH[3],WHIT[3];
    CHUR[0]=-0.236438985662755*pow(10.0,6);CHUR[1]=-0.330761688992456*pow(10.0,7);CHUR[2]=0.543004928368367*pow(10.0,7);
    GOLD[0]=-0.235361442800738*pow(10.0,7);GOLD[1]=-0.464138528219584*pow(10.0,7);GOLD[2]=0.367697640102964*pow(10.0,7);
    SCH[0]=0.144863666340839*pow(10.0,7);SCH[1]=-0.338524374414401*pow(10.0,7);SCH[2]=0.519104714249338*pow(10.0,7);
    WHIT[0]=-0.221833805636663*pow(10.0,7);WHIT[1]=-0.220120512159133*pow(10.0,7);WHIT[2]=0.554305751316722*pow(10.0,7);

    double c = 299792458.0; //скорость светы..... бесит
    double omega = 7.292115 * pow(10.0, -5); // радиальная скорость вращения Земли

    // иинтегрируем ';nb дифуры движения
    vector<double> coord;
    coord = Runge_Kutta(init_coord, acc, n, h);

    vector<vector<double>> coord2array;
//    for(int f = 0; f < coord.size(); f++)
//    array_proc(coord, coord2array, 150, 6);


//    for (int i = 1; i < n; i++) {
//           for (int j = 0; j < 6; j++) {
//               coord2array[i][j] = coord[n * 6 - i * 6 - j - 1];
//           }
//    }


//    int size = sizeof(coord)/sizeof(int);
//    int col = (int) ceil(size/n);
//    int idx = 0;
//    for(int i=0; i<n; i++)
//    for(int j=0; j<col && idx<size; j++)
//    coord2array[i][j] = coord[idx++];


    double minh, maxh, R;

    vector<coordVectorBLH<double>> coordBLH_R;


//    for (int j=0;j<12;j++)
//{
//for( int i=0;i<6;i++) coordBLH_R[j*6+i]=coord[42+j*48+i];
//}

    int i = 0, j = 1;

//    for(auto it: coord)
//    {

    for ( j = 1; j < n; j++)
    {



    /*coordVectorXYZ<*/double/*>*/ * xyz3;
    coordVectorBLH<double> blh3, blh;

    double b, l;

    blh3 = xyz2blh::XYZ_2_BLH(coord[(j-1) * 6], coord[(j-1) * 6 +1], coord[(j-1) * 6 +2], R);


    coordBLH_R.push_back(blh3);

    }

    return coordBLH_R;

}

vector<double> MapMarbleTrassa::Runge_Kutta(vector<double> init_coord, vector<double> acc, int n, int h)
{
    double mu {398600.4418 * pow(10.0,9)};
    double ae{6378136.0};
    double C20{-1082625.7*pow(10.0,-9)};
    double omega {7.292115*pow(10.0,-5)};

    vector<double> coord(n * 6);

    for (int l = 0; l < 6; l++)
        coord[l] = init_coord[l];


    // как вот это по нормальному оформить???? А то оно *овно похоже(((
    double k1, k2, k3, k4, q1, q2, q3, q4;
    double f, X, Y, Z, X_dot, Y_dot, radius;
    int i = 0, j = 1;

    // как эти долбанные формулы представить в 17 стандарте??? ааааааа
    for ( j = 1; j < n; j++)
    {
        radius = sqrt(pow(coord[(j - 1) * 6], 2)
                + pow(coord[(j-1) * 6 + 1], 2)
                + pow(coord[(j-1) * 6 + 2], 2));
        f = -mu / pow(radius, 3);

        for (i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                X = coord[(j-1) * 6 + i];
            k1 = h * (X * f + 1.5 * C20 * mu * pow(ae,2) * X * (1 - 5 * pow(coord[(j-1) * 6 + 2], 2)
                      /pow(radius, 2)) / pow(radius, 5) + pow(omega, 2) * X + 2 * omega * coord[(j-1) * 6 + 4] + acc[i]);

            q1 = coord[(j-1) * 6 + 3 + i] * h;
            X = coord[(j-1) * 6 + i] + q1 / 3;
            Z = coord[(j-1) * 6 + 2] + q1 / 3;
            Y_dot = coord[(j-1) * 6 + 4] + q1 / 3;

            k2 = h * (X * f + 1.5 * C20 * mu * pow(ae,2) * X * (1-5 * pow(Z, 2)
                 / pow(radius, 2)) / pow(radius, 5) + pow(omega, 2) * X + 2 * omega * coord[(j-1) * 6 + 4] + acc[i]);

            q2 = (coord[(j-1) * 6 + 3 + i] + k1 / 3) * h;
            X = coord[(j-1) * 6 + i] - q1 / 3 + q2;
            Z = coord[(j-1) * 6 + 2] - q1 / 3 + q2;

            k3 = h * (X * f + 1.5 * C20 * mu * pow(ae, 2) * X * (1 - 5 * pow(coord[(j-1) * 6 + 2], 2)
                      / pow(radius, 2)) / pow(radius, 5) + pow(omega, 2) * X + 2 * omega * coord[(j-1) * 6 + 4] + acc[i]);

            q3 = (coord[(j-1) * 6 + 3 + i] - k1 / 3 + k2) * h;
            X = coord[(j-1) * 6 + i] + q1 - q2 + q3;
            Z = coord[(j-1) * 6 + 2] + q1 - q2 + q3;
            k4 = h * (X * f + 1.5 * C20 * mu * pow(ae,2) * X * (1 - 5 * pow(coord[(j-1) * 6 + 2],2)
                      / pow(radius, 2)) / pow(radius, 5) + pow(omega, 2) * X + 2 * omega * coord[(j-1) * 6 + 4] + acc[i]);
            q4 = (coord[(j-1) * 6 + 3 + i] + k1 - k2 + k3) * h;

            coord[j*6+i+3] = coord[(j-1) * 6 + i + 3] + (k1 + 3 * k2 + 3 * k3 + k4) / 8;
            coord[j*6+i] = coord[(j-1) * 6 + i] + (q1 + 3 * q2 + 3 * q3 + q4) / 8;
            }

            if (i == 1)
            {
            X = coord[(j-1) * 6 + i];
            k1 = h * ( X * f + 1.5 * C20 * mu * pow(ae,2) * X * (1 - 5 * pow(coord[(j-1)*6+2],2)/pow(radius, 2)) / pow(radius, 5) + pow(omega, 2) * X - 2 * omega * coord[(j-1) * 6 + 3] + acc[i]);
            q1 = coord[(j-1) * 6 + i + 3] * h;
            X = coord[(j-1) * 6 + i] + q1 / 3;
            Z = coord[(j-1) * 6 + 2] + q1 / 3;
            X_dot = coord[(j-1) * 6 + 3] + q1 / 3;
            k2 = h * (X * f + 1.5 * C20 * mu * pow(ae, 2) * X *(1 - 5 * pow(Z, 2)
              /pow(radius, 2)) / pow(radius, 5) + pow(omega, 2) * X - 2 * omega * X_dot + acc[i]);
            q2 = (coord[(j-1) * 6 + i + 3] + k1 / 3) * h;
            X = coord[(j-1) * 6 + i] - q1 / 3 + q2;
            Z = coord[(j-1) * 6 + 2] - q1 / 3 + q2;
            X_dot = coord[(j-1) * 6 + 3] - q1 / 3 + q2;
            k3 = h * (X * f + 1.5 * C20 * mu * pow(ae, 2) * X * (1 - 5 * pow(Z, 2) / pow(radius, 2))
                  /pow(radius, 5) + pow(omega, 2) * X - 2 * omega * X_dot + acc[i]);
            q3 = (coord[(j-1) * 6 + i + 3] - k1 / 3 + k2) * h;
            X = coord[(j-1) * 6 + i] + q1 - q2 + q3;
            Z = coord[(j-1) * 6 + 2] + q1 - q2 + q3;
            X_dot = coord[(j-1) * 6 + 3] + q1 - q2 + q3;
            k4 = h * (X * f + 1.5 * C20 * mu * pow(ae,2) * X * (1 - 5 * pow(Z, 2) / pow(radius, 2))
                      /pow(radius, 5) + pow(omega,2) * X - 2 * omega * X_dot + acc[i]);
            q4 = (coord[(j-1) * 6 + i + 3] + k1 - k2 + k3) * h;

            coord[j*6+i+3] = coord[(j-1) * 6 + i + 3] + (k1 + 3 * k2 + 3 * k3 + k4) / 8;
            coord[j*6+i] = coord[(j-1) * 6 + i] + (q1 + 3 * q2 + 3 * q3 + q4) / 8;
            }

            if (i == 2)
            {
            X = coord[(j-1) * 6 + i];
            k1 = h * (X * f + 1.5 * C20 * mu * pow(ae,2) * X * (3 - 5 * pow(coord[(j-1) * 6 + 2], 2)
                    /pow(radius, 2)) / pow(radius, 5) + acc[i]);
            q1 = coord[(j-1) * 6 + i + 3] * h;
            X = coord[(j-1) * 6 + i] + q1 / 3;

            k2 = h * (X * f + 1.5 * C20 * mu * pow(ae,2) * X * (3 - 5 * pow(coord[(j-1) * 6 + 2], 2)
                      / pow(radius, 2)) / pow(radius, 5) + acc[i]);
            q2 = (coord[(j-1) * 6 + i + 3] + k1 / 3) * h;
            X = coord[(j-1) * 6 + i] - q1 / 3 + q2;
            k3 = h * (X * f + 1.5 * C20 * mu * pow(ae,2) * X * (3 - 5 * pow(coord[(j-1) * 6 + 2], 2)
                     /pow(radius, 2)) / pow(radius, 5) + acc[i]);
            q3 = (coord[(j-1) * 6 + i + 3] - k1 / 3 + k2) * h;
            X = coord[(j-1) * 6 + i] + q1 - q2 + q3;

            k4 = h * (X * f + 1.5 * C20 * mu * pow(ae,2) * X * (3 - 5 * pow(coord[(j-1) * 6 + 2], 2)
                      /pow(radius,2))/pow(radius,5)+acc[i]);
            q4 = (coord[(j-1) * 6 + i + 3] + k1 - k2 + k3) * h;

            coord[j*6+i+3] = coord[(j-1) * 6 + i + 3] + (k1 + 3 * k2 + 3 * k3 + k4) / 8;
            coord[j*6+i] = coord[(j-1) * 6 + i] + (q1 + 3 * q2 + 3 * q3 + q4) / 8;
            }
        }
    }

    return coord;
}
