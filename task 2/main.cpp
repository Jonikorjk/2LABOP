#include <iostream>
#include "Functions.h"

using std::cout;
using std::endl;

class ChildFunction : public Functions
{
public:
    double f(double x1, double n) override
    {
        double sum = 0;
        if (x1 < 0)
        {
            for (int i = 1; i <= n; i++)
            {
                sum += (i + x1) * (i + x1);
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                double y = 1;
                for (int j = 1; j <= n; j++)
                {
                    y *= (x1 + i) / (i + j);
                }
                sum += y;
            }
        }
        return sum;
    }

};

int main()
{
    setlocale(LC_ALL, "ru");
    ChildFunction d;
    d.Output(-5, -1, 0.1, 3);
}