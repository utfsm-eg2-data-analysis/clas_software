#ifndef dvect_hh
#define dvect_hh 1

#include "cpp_headers.hh"

class dvec
{
 public:
  dvec();
  dvec(double);
  ~dvec();

  void   fillrtp(double, double, double);
  void   fillxyz(double, double, double);
  double x();
  double y();
  double z();
  double mag();
  double the();
  double phi();
  double dot(dvec);
  dvec   cross(dvec);
  void   dump();
  dvec   rot(double, double);

   dvec operator=(dvec vt);
   dvec operator+(dvec vt);
   dvec operator-(dvec vt);
   dvec operator*(double fact);

 private:
  double x1;
  double x2;
  double x3;
};

#endif
