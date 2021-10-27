#ifndef CHUYENDOI_H
#define CHUYENDOI_H

#include <QString>

double ChuyenDoi(const QString &kieu, const double &input);

//Do dai
double in_to_cm(const double &input);
double cm_to_in(const double &input);

//Nhiet do
double C_to_F(const double &input);
double F_to_C(const double &input);
double C_to_K(const double &input);
double K_to_C(const double &input);
double F_to_K(const double &input);
double K_to_F(const double &input);

#endif // CHUYENDOI_H
