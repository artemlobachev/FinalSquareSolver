#ifndef UT_H
#define UT_H
#include <stdlib.h>

/** @file
 *  @brief Unit tests for program safety
*/

struct QuadCoef
{
    double a;
    double b;
    double c;
};

struct QuadRoots
{
    double x1EXP;
    double x2EXP;
};

struct QuadEqu
{
    QuadCoef Coef;
    QuadRoots Roots;
    int nRootsEXP;
};

/**
 * @brief after finishing the function we have pointer on array of structures and his size
 * @param [in] sizeout-pointer - size(in numbers not in memory) array of structures
 * @return pointer on array of structures
*/
QuadEqu* UnitFill(size_t * sizeout);
/**
 * @brief testing unit-tests and outputs wrong if they don`t comply
 * @param [in] unit-pointer: pointer on array of structures
 * @param [in] SIZE: size array of Structures
*/
void UnitTests(QuadEqu * unit, size_t SIZE);
/**
 * @brief Unit-test for quadratic equation
 * @param [in] a
 * @param [in] b
 * @param [in] c
 * @param [in] x1EXP
 * @param [in] x1
 * @param [in] x2EXP
 * @param [in] x2
 * @param [in] nRootsEXP
 * @param [in] nRoots
*/
void UnitTestQuad(double a, double b, double c, double x1EXP, double x1, double x2EXP, double x2, int nRootsEXP, int nRoots);
/**
 * @brief Unit-test for linear equation
 * @param [in] b
 * @param [in] c
 * @param [in] x1EXP
 * @param [in] x1
 * @param [in] nRootsEXP
 * @param [in] nRoots
*/
void UnitTestLinear(double b, double c, double x1EXP, double x1, int nRootsEXP, int nRoots);

#endif
