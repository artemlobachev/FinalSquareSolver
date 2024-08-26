#include <assert.h>
#include <stdio.h>
#include "asserts.h"

void AssertTests1(double *a, double *b, double *c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    assert(a != b && a != c && b != c);
}

void AssertTests2(double *x1, double *x2, int *nRoots )
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(nRoots != NULL);
    assert(x1 != x2);
}
