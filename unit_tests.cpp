#include <stdio.h>
#include "asserts.h"
#include "need_for_sol.h"
#include "unit_tests.h"


QuadEqu* UnitFill(size_t * sizeout)
{
    const size_t SIZE = 8;

    QuadEqu * unit = (QuadEqu *) calloc(SIZE, sizeof(QuadEqu) );
    unit[0] = {{1, 0, 0}, {0, 0}, 1};
    unit[1] = {{1, 2, 1}, {-1.0, -1.0}, 1};
    unit[2] = {{1, -6, 9}, {3.0, 3.0}, 1};
    unit[3] = {{0, 0, 0}, {NAN, NAN}, -1};
    unit[4] = {{0, 0, -32.2311}, {NAN, NAN}, 0};
    unit[5] = {{0, 0, 21.321}, {NAN, NAN}, 0};
    unit[6] = {{1, 0, 0}, {0, 0}, 1};
    unit[7] = {{1, 0, -4}, {2, -2}, 2};

    *sizeout = SIZE;

    return unit;
}

void UnitTests(QuadEqu * unit, size_t SIZE)
{
    for (unsigned int i = 0; i < SIZE; i++)
    {
        double a = unit[i].Coef.a, b = unit[i].Coef.b, c = unit[i].Coef.c;
        double x1EXP = unit[i].Roots.x1EXP, x2EXP = unit[i].Roots.x2EXP;
        int nRootsEXP = unit[i].nRootsEXP;

        double x1 = NAN, x2 = NAN;
        int nRoots = 0;
        SquareSol(a, b, c, &x1, &x2, &nRoots);
        if (IsZero(a))
            UnitTestLinear(b, c, x1EXP, x1, nRootsEXP, nRoots);
        else
            UnitTestQuad(a, b, c , x1EXP, x1, x2EXP, x2, nRootsEXP, nRoots );
     }
}

void UnitTestQuad(double a, double b, double c, double x1EXP, double x1, double x2EXP, double x2, int nRootsEXP, int nRoots)
{
    if (!IsZero(x1EXP - x1) || !IsZero(x2EXP - x2) || nRootsEXP != nRoots)
        {
            printf("WRONG! FOR COEF: a = %lf  b = %lf  c = %lf\n", a, b, c);
            printf("roots received: %d roots expected: %d\n", nRoots, nRootsEXP);
            printf("x1 received: %lf x1 expected: %lf\n", x1, x1EXP);
            printf("x2 received: %lf x2 expected: %lf\n", x2, x2EXP);
         }
}

void UnitTestLinear(double b, double c, double x1EXP, double x1, int nRootsEXP, int nRoots)
{
    if (nRootsEXP != nRoots && (x1 != NAN && !IsZero(x1 - x1EXP) ))
    {
        printf("WRONG!FOR COEF: a = 0  b = %lf  c = %lf\n", b, c);
        printf("roots received: %d roots expected: %d\n", nRoots, nRootsEXP);
        printf("x1 received: %lf x1 expected: %lf\n", x1, x1EXP);
    }
}
