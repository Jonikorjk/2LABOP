#ifndef Functions_
#define Functions_

class Functions
{
    bool IsRightInput(double x1, double x2, double q, double n);
public:
    void Output(double x1, double x2, double q, double n);
    virtual double f(double x, double n) = 0;
}; 

#endif