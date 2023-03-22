#include "xyz2blh.h"

//xyz2blh::xyz2blh()
//{

//}


void ParamEllipsoid( int SK,double &BP,double &Szhat )
{
    if ( SK == 0 || SK == 1 )            // ПЗ-90.02 или ПЗ-90 /
    {
        BP = 6378.136;
        Szhat = 1/298.257839303;

        // болшево
        BP = 6378.1363;
        Szhat = 0.0033528244; // или 1/298.2560017160;
    }
    else if ( SK == 2 || SK == 3 )       // СК-42 или СК-95
    {
        BP = 6378.245;
        Szhat = 1/298.3;
    }
    else if ( SK == 4 )                  // WGS-84 или ITRF-2000
    {
        BP = 6378.137;
        Szhat = 1/298.257223563;
    }
}


void SinCos(double x, double &sinX, double &cosX)
{
    double r, g;
    r=int(x/D2PI);
    x -= r*D2PI;
    if (x < 0)
        x += D2PI;
    g=R2G(x);
    if (((g < 46) || (g > 314)) || ((g > 134) && (g < 226))) {
        sinX=sin(x);
        r=sinX*sinX;

        if (r < 1) {
            cosX =sqrt(1-r);
            if ((g > 90) && (g < 270))
                cosX=-cosX;
        } else
            cosX=cos(r);
    } else {
        cosX=cos(x);
        r=cosX*cosX;
        if (r < 1) {
            sinX=sqrt(1-r);
            if ((g >180) && (g < 360))
                sinX=-sinX;
        } else
            sinX=sin(r);
    }

}

bool xyz2blh::XYZ_2_BLH_R(double *mq3, double &Br, double &Lr, double &h, double &R,  int SK, double eps)
{
    double a,StSzh,e2,D,sinBr,cosBr,La,c,p,s1,s2,b,sinb,cosb,sin2b,cos2b,dd,r1;

    if ( SK < 0 || SK > 4 )
    {
//        if ( NOT_NULL(sError) ) (*sError) = QS("q3_BLhR: Ошибка задания параметра SK");
        return false;
    }

    ParamEllipsoid( SK,a/*BP*/,StSzh );        /* определяем большую полуось и степень сжатия ОЗЭ */

    R = VABSPTR(mq3);

//    R = sqrt( mq3[0]*mq3[0] + mq3[1]*mq3[1] + mq3[2]*mq3[2] );

    if ( R == DNULL )
    {
//        if ( NOT_NULL(sError) ) (*sError) = QS("q3_BLhR: Ошибка - точка в центре эллипсоида");
        return false;
    }

    e2 = StSzh * ( 2 - StSzh );                       /*  эксцентриситет эллипсоида в квадрате */

    D = PVABSPTR(mq3);

//    D = sqrt( mq3[0]*mq3[0] + mq3[1]*mq3[1] );       /*  D = sqrt( X*X + Y*Y ) - расстояние до точки в плоскости X0Y */

    if ( D <= 1e-5  )  /* если D = 0 */
    {
        Br = mq3[2] * M_PI_2 / fabs( mq3[2] );
        Lr = 0;

        SinCos( Br,sinBr,cosBr );

        h  = mq3[2] * sinBr - a * sqrt( 1 - e2 * sinBr * sinBr );
    }
    else          /* --------------- если D <> 0 --------------- */
    {
        La = fabs( asin( mq3[1]/D ) );             /* La - угол отклонения от оси X */

        if ( mq3[1] < 0 )      /* если Y < 0 */
        {
            if ( mq3[0] > 0 ) Lr = D2PI - La;     /* если X > 0 */
            else Lr = M_PI + La;       /* если X < 0 */
        }
        else	               /* если Y > 0 */
        {
            if ( mq3[0] > 0 ) Lr = La;               /* если X > 0 */
            else Lr = M_PI - La;       /* если X < 0 */
        }

        if ( Lr > M_PI ) Lr -= D2PI;           /* коррекция под карту */

        if ( mq3[2] == DNULL )     /* если Z = 0 */
        {
            Br = 0;
            h  = D - a;
        }
        else      /* --------------- если Z <> 0 --------------- */
        {
            c = asin( mq3[2] / R );
            p = e2 * a / ( 2 * R );

            s2 = 0;

            do
            {
                s1 = s2;
                b  = c + s1;

                SinCos( b,sinb,cosb );
                SinCos( 2*b,sin2b,cos2b );

                r1 = 1 - e2 * sinb * sinb;

                if ( r1 == DNULL )
                {
//                    if ( NOT_NULL(sError) ) (*sError) = QS("q3_BLhR: Ошибка - деление на ноль");
                    return false;
                }

                s2 = asin( p * sin2b / sqrt( r1 ) );
                dd = fabs( s2 - s1 );

            } while ( dd >= eps );   /* условие dd <= E-4 угл.сек  ->  dh < 0.003 м */

            Br = b;

            h  = D*cosb + mq3[2]*sinb - a * sqrt( 1 - e2 * sinb*sinb );
        }
    }

    return true;
}

coordVectorBLH<double> xyz2blh::XYZ_2_BLH(double x, double y, double z, double &R, int SK, double eps)
{
    double a,StSzh,e2,D,sinBr,cosBr,La,c,p,s1,s2,b,sinb,cosb,sin2b,cos2b,dd,r1;

    coordVectorBLH<double> blh;

    double xyz[3];
    xyz[0] = x;
    xyz[1] = y;
    xyz[2] = z;

    // определяем большую полуось и степень сжатия ОЗЭ
    ParamEllipsoid( SK,a/*BP*/,StSzh );

    R = VABSPTR(xyz);

    //  эксцентриситет эллипсоида в квадрате
    e2 = StSzh * ( 2 - StSzh );

    D = PVABSPTR(xyz);

    //  D = sqrt( X*X + Y*Y ) - расстояние до точки в плоскости X0Y
    D = sqrt( xyz[0] * xyz[0] + xyz[1] * xyz[1] );

    // если D = 0
    if ( D <= 1e-5  )
    {
        blh.b = xyz[2] * M_PI_2 / fabs( xyz[2] );
        blh.l = 0;

        SinCos( blh.b,sinBr,cosBr );

        blh.h  = xyz[2] * sinBr - a * sqrt( 1 - e2 * sinBr * sinBr );
    }
    else          // --------------- если D <или> 0 ---------------
    {
        // La - угол отклонения от оси X
        La = fabs( asin( xyz[1]/D ) );

        // если Y < 0
        if ( xyz[1] < 0 )
        {
            // если X > 0
            if ( xyz[0] > 0 ) blh.l = D2PI - La;
            else blh.l = M_PI + La;       // если X < 0
        }
        else	               // если Y > 0
        {
            if ( xyz[0] > 0 ) blh.l = La;               // если X > 0
            else blh.l = M_PI - La;       // если X < 0
        }

        if ( blh.l > M_PI ) blh.l -= D2PI;           // коррекция под карту

        if ( xyz[2] == DNULL )     // если Z = 0
        {
            blh.b = 0;
            blh.h  = D - a;
        }
        else      // --------------- если Z <> 0 ---------------
        {
            c = asin( xyz[2] / R );
            p = e2 * a / ( 2 * R );

            s2 = 0;

            do
            {
                s1 = s2;
                b  = c + s1;

                SinCos( b,sinb,cosb );
                SinCos( 2*b,sin2b,cos2b );

                r1 = 1 - e2 * sinb * sinb;
                s2 = asin( p * sin2b / sqrt( r1 ) );
                dd = fabs( s2 - s1 );

            } while ( dd >= eps );   // условие dd <= E-4 угл.сек  ->  dh < 0.003 м

            blh.b = b;

            blh.h  = D*cosb + xyz[2]*sinb - a * sqrt( 1 - e2 * sinb*sinb );
        }
    }

    return blh;
}

coordVectorBLH<double> xyz2blh::XYZ_2_BLH(double x, double y, double z)
{
    coordVectorBLH<double> blh;
    double A = 6378137.0;
    double B = 6356752.314245;

    double e = sqrt(1 - pow(B, 2)/pow(A,2));

    double longitude = atan2(y, x);

      // calculate latitude, in radians
   double xy_hypot = hypot(x, y);

    int     lat0 = 0;
    double    latitude = atan(z / xy_hypot);

    double N, R, phi, height;
    while( abs(latitude - lat0) > 1E-9)
    {
        lat0 = latitude;
        N = A / sqrt(1 - pow(e, 2) * pow(sin(lat0), 2));
        latitude = atan((z + pow(e, 2) * N * sin(lat0)) / xy_hypot);
    }

    // calculate height, in meters
    N = A / sqrt(1 - pow(e, 2) * pow(sin(latitude),2));
            if( abs(latitude) < M_PI / 4)
    {
            R = hypot(xy_hypot, z);
    phi = atan(z / xy_hypot);
            height = R * cos(phi) / cos(latitude) - N;
}
            else
    {
            height = z / sin(latitude) - N * (1 - pow(e, 2));

}
        // convert angle unit to degrees
//            longitude = degrees(longitude)
//            latitude = degrees(latitude)

            blh.b = latitude;
            blh.l = longitude;
            blh.h = height;

            return blh;
}



