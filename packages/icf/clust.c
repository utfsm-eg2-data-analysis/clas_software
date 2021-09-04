/*
 *  Program: Energy and position correction of the cluster
 *
 *  Author : Rustam Niyazov
 *
 *  Date :   Summer, 2005. 
 *   
 *
 *  Modified Jan 19, 2006 - all constants are read from database now!!!
*/
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "clust.h"
#include "ic.h"


float stX = 1.346;//These are read from database now!!!
float stY = 1.360;
float zdist=55.;//cm 
int i,j,k;
//We use new definition of the 'deep' parameter, where
//deep is determined along particle trajectory (not the projection to Z axis).

void clusten_(float *energin,float *xin,float *yin,float *enrgyout,float *xout,float *yout){
  k=0;
  stX = recon_.xstep;
  stY = recon_.ystep;
  float energ=*energin;
  float x=*xin;
  float y=*yin;
  float radi=sqrt((x*x)/(stX*stX)+(y*y)/(stY*stY));
  *enrgyout=GetEnergyCorrected(energ, radi);
  float xx=0;
  float yy=0;
  zdist=recon_.zt0;
  GetCoordCorrected(x, y, zdist,&xx,&yy);
  *xout=xx;*yout=yy;
}

float GetEnergyCorrected(float mom, float rdist){
  float corr_es=0;
  float corr_es1=0;
  float new_m=0;
  int brang[16];
  for(l=0;l<16;l++){brang[l]=0;}
  int fire=0;
  float r0=3.25;//First bin 
  float rdist1=rdist;
  if(rdist>11.5)rdist1=11.5;
  if(rdist<3.25)rdist1=3.251;
  for(i=0;i<16;i++){
    float dr=0.25;
    if(i<3||i>9)dr=0.25;
    else if(i==3||i==9)dr=0.5;
    else dr=1.0;
    float r1=r0+dr;
    brang[i]=(rdist1>r0&&rdist1<=r1);
    if(brang[i]){
      fire=1;
      //hyperbolic function
      corr_es=recon_.encorr[i][0]*(mom-recon_.encorr[i][2])/(mom-recon_.encorr[i][2]+(recon_.encorr[i][1]/recon_.encorr[i][0]));
    }
    r0=r1;
  }
  if(fire=1){
    new_m=mom/corr_es;
    //    printf("%8.6f %8.6f \n",corr_es,corr_es1);
  }
  else {new_m=mom;printf("did not fire; check R range!!! r:%5.2f\n",rdist);}
  return new_m; 
}

void GetCoordCorrected(float x, float y, float z, float *x_new, float *y_new){
  float phi=atan2(y,x);
  float radi=sqrt(x*x+y*y);
  float theta=atan2(radi,z+recon_.deep);//rude estimate
  float zdeep = recon_.deep*cos(theta);//projection of deep to z axis
  float zz=z+zdeep;
  float s=sqrt((x*x+y*y)/(x*x+y*y+zz*zz));
  float dX=-recon_.deep*s*cos(phi);
  float dY=-recon_.deep*s*sin(phi);
  float xx=x+dX;
  float yy=y+dY;
  *x_new=xx;*y_new=yy;
}
