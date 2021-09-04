#include "cpp_headers.hh"
#include "dvect.hh"
#include "funcs.hh"

dvec::dvec()
{;}


dvec::dvec(double xx)
{
  x1 = xx;
  x2 = xx;
  x3 = xx;
}


dvec::~dvec()
{;}


void dvec::fillrtp(double r, double theta, double phi)
{
  x1 = r*sin(theta)*cos(phi);
  x2 = r*sin(theta)*sin(phi);
  x3 = r*cos(theta);
}


void dvec::fillxyz(double x0, double y0, double z0)
{
  x1 = x0;
  x2 = y0;
  x3 = z0;
}


double dvec::x()
{
  return x1;
}


double dvec::y()
{
  return x2;
}


double dvec::z()
{
  return x3;
}


double dvec::mag()
{
  double mom = x1*x1 + x2*x2 + x3*x3;
  if(mom>=0)
    return sqrt(mom);
  else
    return -1;
}


double dvec::the()
{
  double norm = sqrt(x1*x1 + x2*x2 + x3*x3);
  double theta;
  if(norm != 0)
  {
    theta = acos(x3/norm);
  }
  else
  {
    theta = -1;
  }

  return theta;
}


double dvec::phi()
{
  double phi;
  if(x1 != 0 && x2 != 0)
  {
    phi   = atan(abs(x2)/abs(x1));
    if(x1 > 0. && x2 > 0.)
    {
      phi = phi;
    }
    else if(x1 < 0. && x2 > 0.)
    {
      phi   = pi() - phi;
    }
    else if(x1 < 0. && x2 < 0.)
    {
      phi   = pi() + phi;
    }
    else if(x1 > 0. && x2 < 0.)
    {
      phi   = 2.*pi() - phi;
    }
  }
  else if(x1 == 0 && x2 != 0)
  {
    if(x2 > 0.)
    {
      phi = pi()/2.;
    }
    else if(x2 < 0.)
    {
      phi = 3.*pi()/2.;
    }
  }
  else if(x1 != 0 && x2 == 0)
  {
    if(x1 > 0.)
    {
      phi = 0.;
    }
    else if(x1 < 0.)
    {
      phi = pi();
    }
  }
  else if(x1 == 0 && x2 == 0)
  {
    phi = 0.;
  }

  return phi;
}


double dvec::dot(dvec vct)
{
  double tmp;
  tmp = x1*vct.x1 + x2*vct.x2 + x3*vct.x3;

  return tmp;
}


dvec dvec::cross(dvec vct)
{
  dvec tmp;
  tmp.x1 = x2*vct.x3 - x3*vct.x2;
  tmp.x2 = x3*vct.x1 - x1*vct.x3;
  tmp.x3 = x1*vct.x2 - x2*vct.x1;

  return tmp;
}


dvec dvec::operator=(dvec vct)
{
  x1 = vct.x1;
  x2 = vct.x2;
  x3 = vct.x3;

  return vct;
}


dvec dvec::operator+(dvec vct)
{
  dvec tmp;

  tmp.x1 = x1 + vct.x1;
  tmp.x2 = x2 + vct.x2;
  tmp.x3 = x3 + vct.x3;

  return tmp;
}


dvec dvec::operator-(dvec vct)
{
  dvec tmp;

  tmp.x1 = x1 - vct.x1;
  tmp.x2 = x2 - vct.x2;
  tmp.x3 = x3 - vct.x3;

  return tmp;
}


dvec dvec::operator*(double fact)
{
  dvec tmp;
  
  tmp.x1 = x1*fact;
  tmp.x2 = x2*fact;
  tmp.x3 = x3*fact;

  return tmp;
}


void dvec::dump()
{
  cout << x2 <<"  "<< x2 <<"  "<< x3 << endl;
}


/*
vector<double>  vec::fill_matr(double Theta, double Phi)
{
  vector<double> matr;
  matr.resize(9);

  matr.at(0) = -cos(Theta)*cos(Phi); //(1,1)
  matr.at(1) = -cos(Theta)*sin(Phi); //(1,2)
  matr.at(2) =  sin(Theta);          //(1,3)
  matr.at(3) =  sin(Phi);            //(2,1)
  matr.at(4) = -cos(Phi);            //(2,2)
  matr.at(5) =  0.0;                 //(2,3)
  matr.at(6) =  sin(Theta)*cos(Phi); //(3,1)
  matr.at(7) =  sin(Theta)*sin(Phi); //(3,2)
  matr.at(8) =  cos(Theta);          //(3,3)

  return matr;
}
*/


dvec dvec::rot(double theta, double phi)
{
  //vector<double> matr = fill_matr(Theta, Phi);
  //vector<vector<double> > mymatr(3);
  //unsigned int i, j;
  //for(i=0; i<mymatr.size(); i++) mymatr[i].resize(3);
  //for(i=0; i<mymatr.size(); i++)
  //  for(j=0; j<mymatr[i].size(); j++) mymatr[i][j] = matr.at(3*i+j);

  double **rot_matr = new double*[3];
  for(unsigned int i=0; i<3; i++) rot_matr[i] = new double[3];

  rot_matr[0][0] =  cos(theta)*cos(phi);
  rot_matr[0][1] = -sin(phi);
  rot_matr[0][2] =  sin(theta)*cos(phi);
  rot_matr[1][0] =  cos(theta)*sin(phi);
  rot_matr[1][1] =  cos(phi);
  rot_matr[1][2] =  sin(theta)*sin(phi);
  rot_matr[2][0] = -sin(theta);
  rot_matr[2][1] =  0.;
  rot_matr[2][2] =  cos(theta);

  vector<double> vv;
  for(unsigned int i=0; i<3; i++)
    vv.push_back(rot_matr[i][0]*x1 + rot_matr[i][1]*x2 + rot_matr[i][2]*x3);

  dvec vtmp; vtmp.fillxyz(vv[0], vv[1], vv[2]);

  return vtmp;
}


/*
vector<double>  vec::fill_invmatr(double Theta, double Phi)
{
  vector<double> matr;
  matr.resize(9);

//pyrobo
//        ROT(1,1)=COS(THE)*COS(PHI)
//        ROT(1,2)=-SIN(PHI)
//        ROT(1,3)=SIN(THE)*COS(PHI)
//        ROT(2,1)=COS(THE)*SIN(PHI)
//        ROT(2,2)=COS(PHI)
//        ROT(2,3)=SIN(THE)*SIN(PHI)
//        ROT(3,1)=-SIN(THE)
//        ROT(3,2)=0D0
//        ROT(3,3)=COS(THE)

  matr.at(0) = -cos(Theta)*cos(Phi); //(1,1)+
  matr.at(1) =  sin(Phi);            //(1,2)-
  matr.at(2) =  sin(Theta)*cos(Phi); //(1,3)+
  matr.at(3) = -cos(Theta)*sin(Phi); //(2,1)+
  matr.at(4) = -cos(Phi);            //(2,2)+
  matr.at(5) =  sin(Theta)*sin(Phi); //(2,3)+
  matr.at(6) =  sin(Theta);          //(3,1)-
  matr.at(7) =  0.0;                 //(3,2)+
  matr.at(8) =  cos(Theta);          //(3,3)+

  return matr;
}
*/

/*
 vec  vec::invrot(double Theta, double Phi)
{
  vector<double> matr = fill_invmatr(Theta, Phi);
  vector<vector<double> > mymatr(3);
  unsigned int i, j;
  for(i=0; i<mymatr.size(); i++) mymatr[i].resize(3);
  for(i=0; i<mymatr.size(); i++)
    for(j=0; j<mymatr[i].size(); j++) mymatr[i][j] = matr.at(3*i+j);

   vec vv(0);
  for(i=0; i<v.size(); i++)
  {
    double sum = 0.;
    for(j=0; j<mymatr[i].size(); j++) sum += mymatr[i][j]*v.at(j);
    vv.set(i,sum);
  }

  return vv;
}
*/
