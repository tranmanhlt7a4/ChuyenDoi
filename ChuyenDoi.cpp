#include "ChuyenDoi.h"

double ChuyenDoi(const QString &kieu, const double &input)
{
    if(kieu == "inch->cm")
    {
        return in_to_cm(input);
    }
    else if(kieu == "cm->inch")
    {
        return cm_to_in(input);
    }
    else if(kieu == "°C->°F")
    {
        return C_to_F(input);
    }
    else if(kieu == "°F->°C")
    {
        return F_to_C(input);
    }
    else if(kieu == "°C->K")
    {
        return C_to_K(input);
    }
    else if(kieu == "K->°C")
    {
        return K_to_C(input);
    }
    else if(kieu == "K->°F")
    {
        return K_to_F(input);
    }
    else if(kieu == "°F->K")
    {
        return F_to_K(input);
    }
    return 0;
}

//Do dai
double in_to_cm(const double &input)
{
    const double HE_SO_QUY_DOI = (double)127 / (double)50;
    return input * HE_SO_QUY_DOI;
}

double cm_to_in(const double &input)
{
    const double HE_SO_QUY_DOI = (double)50 / (double)127;
    return input * HE_SO_QUY_DOI;
}

//Nhiet do
double C_to_F(const double &input)
{
    return input * 1.8 + 32;
}

double F_to_C(const double &input)
{
    return (input - 32) / 1.8;
}

double C_to_K(const double &input)
{
    return input + 273.15;
}

double K_to_C(const double &input)
{
    return input - 273.15;
}

double F_to_K(const double &input)
{
    double c = F_to_C(input);
    return C_to_K(c);
}

double K_to_F(const double &input)
{
    double c = K_to_C(input);
    return C_to_F(c);
}
