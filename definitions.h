#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <math.h>


// забыла, чем можно заменить define в 17 стандарте(((( ааааа

#define ERROR_OUT_RANGE ("Выход за границы массива")

#define STRUCT_FIELD_EQ(x, y, z) (x.z == y.z)
#define STRUCT_FIELD_NEQ(x, y, z) (x.z != y.z)

#define POW2(x) ((x) * (x))
#define POW3(x) ((x) * (x) * (x))
#define POW4(x) ((x) * (x) * (x) * (x))
#define POW5(x) ((x) * (x) * (x) * (x) * (x))
#define POW6(x) ((x) * (x) * (x) * (x) * (x) * (x))

#define D2PI (6.283185307179586476925287)

#define VABSPTR(x) sqrt(POW2((x)[0]) + POW2((x)[1]) + POW2((x)[2]))

//double fMz = 398600.4415;// (км3/с2)
//double fML = 4902.65910;

#define QS(x) (QString::fromUtf8(x))

#define VABSPTR(x) sqrt(POW2((x)[0]) + POW2((x)[1]) + POW2((x)[2]))
#define PVABSPTR(x) sqrt(POW2((x)[0]) + POW2((x)[1]))

#define DNULL (0.0)
#define FNULL (0.0f)
#define DUNIT (1.0)
#define FUNIT (1.0f)
#define INULL (0)
#define IUNIT (1)

#define DR2D (57.29577951308232087679815) // double radian to degrees
#define R2G(x)  ((x) * DR2D)

#endif // DEFINITIONS_H
