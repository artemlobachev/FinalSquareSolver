#ifndef CWU_H
#define CWU_H

/** @file
 * @brief Read/output variables(coefficients, roots, nroots) quadratic equation also communicate with user
 */

/**
 * @brief Welcomes User
*/
void StartMenu(void);
/**
 * @brief scanning coefficients in right way(only numbers) and if user mistaken wrong him that scan doesn`t work
 * @param [out] coef
 * @param [in] char_coef
 * @return 1 - scans well 0 - scans not all
*/
int CoefScanf(double * coef, char char_coef);
/**
 *@brief fills in coefficients input values asserted if input is bad
 *@param [out] a - Pointer
 *@param [out] b - Pointer
 *@param [out] c - Pointer
*/
void ReadCoef(double *a, double * b, double * c);
/**
 *@brief Output all roots and number roots
 *@param [in] a
 *@param [out] x1
 *@param [out] x2
 *@param [out] nRoots
*/
void RootsOut(double a, double x1, double x2, int nRoots);
/**
 * @brief output number of roots and their values for a == 0
 * @param [out] x1
 * @param [out] nRoots
*/
void LinOut(double x1, int nRoots);
/**
 * @brief output number of roots and their values for quadratic equation
 * @param [out] x2
 * @param [out] x1
 * @param [out] x2
*/
void QuadOut(double x1, double x2, int nRoots);
/**
 * @brief Goodbyes the user
*/
void ByeBye(void);
/**
 * @brief Clean buffer
*/
void CleanBuf(void);
#endif
