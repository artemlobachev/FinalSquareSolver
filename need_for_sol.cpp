#include <math.h>
#include <stdio.h>
#include "asserts.h"
#include "need_for_sol.h"

int IsZero(double D)
{
    const double EPSILON = 1e-9;
    return fabs(D) < EPSILON;
}

void SquareSol(double a, double b, double c, double *x1, double *x2, int *nRoots)
{
    if (IsZero(a))
        LinSol(b, c, x1, nRoots);
    else
    {
        AssertTests2(x1, x2, nRoots);

        double D = b * b - 4 * a * c;
        *nRoots = DiscrRoots(a, b, c);
        if (*nRoots == 1)
            *x1 = *x2 = IsZero(b) ? 0.0 : -b / (2 * a) ;
        if (*nRoots == 2)
        {
            double D_sqrt = sqrt(D);
            *x1 = (-b + D_sqrt) / (2.0 * a);       //formula roots quad equation
            *x2 = (-b - D_sqrt) / (2.0 * a);
        }
     }
}

int DiscrRoots(double a, double b, double c)
{
    double D = b * b - 4 * a * c; //formula discriminant

    if (IsZero(D))
    {
        NameRoots = ONEROOT;
        return 1;
    }
    if ( D > 0)
    {
        NameRoots = TWOROOTS;
        return 2;
    }
    NameRoots = ZEROROOTS;
    return 0;
    //return  (D > 0.0) ? 2 : 0 ;
}

void LinSol(double b, double c, double * x1, int *nRoots)
{
    assert(x1 != NULL);
    assert(nRoots != NULL);

    *nRoots = LinRoots(b, c);
    if (NameRoots == ONEROOT)
        *x1 = IsZero(-c / b) ? 0 : -c / b;
}

int LinRoots(double b, double c)
{
    bool bZero = IsZero(b);
    bool cZero = IsZero(c);

    if ( bZero && cZero )
    {
        NameRoots = INFROOTS;
        return -1;
    }
    if ( bZero && !cZero )
    {
        NameRoots = ZEROROOTS;
        return 0;  //zero roots
    }
    NameRoots = ONEROOT;
    return 1; //linear equation
}
