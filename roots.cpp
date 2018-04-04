#include <iostream>
 #include <cmath>
  
  using fptr = double(double);
  
  double f(double x);
  double bisection(double xl, double xu, double eps, int nmax, fptr func);
 
 int main(void)
 {
   const double eps = 1.0e-8;
   int NMAX = 50;
   double xl =0, xu = 1, xr=0;
   xr = bisection(xl, xu, eps, NMAX, f);
   
   return 0;
 }
 
 double f(double x)
 {
   return (5*x*x-5*x*x+6*x-2);
 }
      double bisection(double xl, double xu, double eps, int nmax, fptr func)
      {
      std::cout.precision(16);
      std::cout.setf(std::ios::scientific);
      double xr = 0;
 
        for(int ii = 0; ii <= nmax; ++ii) {
          xr = 0.5*(xu + xl);
          std::cout << ii << "  " << xl << " " << xu << " " << xr << " " << f(xr) << std::endl;
          if (std::fabs(f(xr)) < eps) break;
          if (f(xr)*f(xl) < 0)
            xu = xr;
          else
            xl = xr;
        }
        std::cout << xr << std::endl;
   
        return xr;
      }
