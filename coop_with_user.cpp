#include <stdio.h>
#include "asserts.h"
#include "need_for_sol.h"
#include "coop_with_user.h"

void StartMenu(void)
{
    printf("Hello, dear user! Please enter the ");
    printf("coefficients of quadratic equation:\n");
}


int CoefScanf(double *coef, char char_coef) /*new_scanf requires good enter (numbers)*/
{
    int result = 0;

    printf("%c: ", char_coef);
    while (true)
    {
        result = scanf("%lf", coef);
        if (result == 1)            /*scanf returns numbers count*/
        {
            CleanBuf();
            return 1;
        }
        CleanBuf();
        puts("WRONG! PLEASE TRY AGAIN.");
        printf("%c: ", char_coef);
    }

    return 0;
}

void ReadCoef(double *a, double *b, double *c)
{
    AssertTests1(a, b, c);

    if (!(CoefScanf(a, 'a') && CoefScanf(b, 'b') && CoefScanf(c, 'c') ))
        assert(false);  /*comp g++*/
}

void RootsOut(double a, double x1, double x2, int nRoots)
{
    if (IsZero(a))
        LinOut( x1, nRoots);
    else
        QuadOut(x1, x2, nRoots);
}

void LinOut(double x1, enum enumRoots NameRoots)
{
    switch(NameRoots)
    {
        case ONEROOT:
            printf("a == 0. linear equation: x = %lf\n", x1);
            break;
        case 0:
            printf("No solutions =(\n");
            break;
        case -1:    /*Infinity solutions*/
            printf("any value of x is a solution\n");
            break;
        default:
            assert(false);      //comp g++
    }
}

void QuadOut(double x1, double x2,int nRoots)
{
    switch(nRoots)
    {
        case 0:
            printf("No solutions =(");
            break;
        case 1:
            printf("D == 0 or close to 0.\n");
            printf("x1 = x2 = %lf\n", x1);
            break;
        case 2:
            printf("D > 0: the equation have 2 roots\n");
            printf("x1 = %lf    x2 = %lf\n", x1, x2);
            break;
        default:
            assert(false); //comp g++
    }
}

void ByeBye(void)
{
    printf("Thanks for using! Hope the program help to you\n");
//    printf("wanna see cutie cat? :3 :3 :3 \n  y/n");
}

void CleanBuf(void)
{
    while (getchar() != '\n')
            continue;
}
