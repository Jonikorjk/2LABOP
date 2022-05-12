#include <iostream>
#include "Functions.h"


void Functions::Output(double x1, double x2, double q, double n)
{
    if (IsRightInput(x1,x2,q,n))
    {
        double minX = x1;
        while (x1 <= x2)
        {
            std::cout << "X = " << x1 << "\t\tY = " << f(x1, n) << std::endl;
            if (f(minX,n) > f(x1,n)) minX = x1;
            x1 *= 1000000;
            x1 = round(x1);
            x1 /= 1000000;
            x1 += q;
        }
        std::cout << "The min root is: " << minX << std::endl;
    }
}

bool Functions::IsRightInput(double x1, double x2, double q, double n)
{
    double multiplicity = (x2 - x1) / q;
    if (q <= 0)
    {
        std::cout << "������! ��� q ������ ���� ������ ������ 0 (q>0)" << std::endl;
        return false;
    }
    else if (x1 > x2)
    {
        std::cout << "������! �1 ������ ���� ������ ��� ��������� �2 (x1<=x2)" << std::endl;
        return false;
    }
    else if (multiplicity != (long)multiplicity)
    {
        std::cout << "������! ������� x2-x1 ������ ���� ������� ���� q ((x2-x1)/q = c, c � Z)" << std::endl;
        return false;
    }
    else if (n < 1 || n != (long)n)
    {
        std::cout << "������!, ���������� �������� n ������ ���� ����������� ������ (n � N)" << std::endl;
        return false;
    }
    return true;
}
