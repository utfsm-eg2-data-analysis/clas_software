#include "cpp_headers.hh"


int file_exists(string file)
{
  ifstream ff(file.c_str());
  if (!ff)
  {
    cout<<"File "<<file<<" does not exist"<<endl;
    return -1; 
  }
  return 0;
}


double sqr(double x) {return x*x;}

double pi() {return 3.14159265359;}

double rndm() {return (double)rand()/RAND_MAX;}
