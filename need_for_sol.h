#ifndef NFS_H
#define NFS_H
#include <stdio.h>
#include <math.h>

enum enumRoots{INFROOTS = -1, ZEROROOTS = 0, ONEROOT = 1, TWOROOTS = 2};

/** @file
 * @brief calculate number of roots and their values
*/

/**
 * @brief complain float-numbers with 0
 * @param [in] D: any float-number
 * @return True - if complain to zero False - Else
*/
int IsZero(double D);
/**
 * @brief by discriminant determines how much roots in quadratic equation
 * @param [in] a
 * @param [in] b
 * @param [in] c
*/
int DiscrRoots(double a, double b, double c);
/**
 * @brief Square solver assigns to x1, x2, nRoots values
 * @param [in] a
 * @param [in] b
 * @param [in] c
 * @param [out] x1-pointer
 * @param [out] x2-pointer
 * @param [out] nRoots-pointer
*/
void SquareSol(double a, double b, double c, double *x1, double *x2, int *nRoots);
/**
 * @brief by other coefficients determines how much roots in linear equation
 * @param [in] b
 * @param [in] c
*/
int LinRoots(double b, double c);
/**
 * @brief Linear equation solver assigns to x1, x2, nRoots values
 * @param [in] b
 * @param [in] c
 * @param [out] x1-pointer
 * @param [out] nRoots-pointer
*/
void LinSol(double b, double c, double * x1, int *nRoots);

#endif
