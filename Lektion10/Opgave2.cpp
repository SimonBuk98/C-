#include <iostream>
#include <cmath>

class Func
{
public:
    virtual double getf(double x) = 0;
    virtual double getdfdx(double x) = 0;
};

class Parabola : public Func
{

public:
    Parabola(double a, double b, double c) : _a(a), _b(b), _c(c) {}

    virtual double getf(double x) override
    {
        return _a * x * x + _b * x + _c;
    }
    virtual double getdfdx(double x) override
    {
        return 2 * _a * x + _b;
    }

private:
    int _a;
    int _b;
    int _c;
};

class NumFunc: public Func{
    public:
    virtual double getdfdx(double x){
        return (getf(x+0.5*_dx)-getf(x-0.5*_dx))/_dx;
    }
    virtual void setdx(double dx){_dx=dx;}
    virtual double getdx(){
        return _dx;
    }

    private: 
        double _dx = 1;
};

class Parabola_num: public NumFunc{
    public:
    Parabola_num(double a,double b, double c):_a(a),_b(b),_c(c){}

    virtual double getf(double x) override {
        return _a * x * x + _b * x + _c;
    }
    private:
    int _a;
    int _b;
    int _c;
};

class SolverEq: public NumFunc{
    public:
        virtual double getf(double x) override{
            double error = std::exp(-x)-std::pow(x,2.0);
            return error*error;
        }
};


double findMinimum(Func *f, double init, double lr, int iterations)
{
    double x = init;
    for (int i = 0; i < iterations; i++)
    {
        double dfdx = f->getdfdx(x);
        x = x - (lr * dfdx);
        std::cout << "iteration " << i << ": " << x << " " << f->getf(x) << std::endl;
    }
    return x;
}

int main()
{
    Parabola f(1, 2, 3);
    Parabola_num f1(1,2,3);
    f1.setdx(0.1);
    findMinimum(&f, 4, 0.3, 20);
    findMinimum(&f1, 4, 0.3, 20);

    SolverEq eq;
    eq.setdx(0.01);
    findMinimum(&eq, 0.5, 0.1,30); 
}
