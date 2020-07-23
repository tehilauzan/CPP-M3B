//
// Created by Tehila on 28/04/2020.
//

#include "solver.hpp"
#include <iostream>
#include <math.h>

using namespace std;
using solver::RealVariable, solver::ComplexVariable;
 namespace solver{


      RealVariable operator+ (float a, RealVariable r) {
          r=r+a;
          return r;
      }
     RealVariable operator+ ( RealVariable r, float a) {
          r.c+=a;
          return r;
          }
     RealVariable operator+ (RealVariable r1, RealVariable r2) {
          r1.a+=r2.a;
          r1.b+=r2.b;
          r1.c+=r2.c;
          return r1;
      }
     RealVariable operator* (float a, RealVariable r) {
          r.a*=a;
          r.b*=a;
          r.c*=a;
          return r;
          }
     RealVariable operator- (RealVariable r, float  a) {
          r.c-=a;
          return r;
      }
     RealVariable operator- (RealVariable r1, RealVariable  r2) {
          r1.a-=r2.a;
          r1.b-=r2.b;
          r1.c-=r2.c;
          return r1;

      }
     RealVariable operator== (RealVariable r1,RealVariable  r2)
     {
     r1.a-=r2.a;
     r1.b-=r2.b;
     r1.c-=r2.c;
     return r1;
     ;}
     float operator== (RealVariable r, float  a) {
         a = a - r.c;
         r.c=0;
         if(r.a>0 && a<0){
             throw exception();
         }

         if(r.a==0) {
             cout<<"sdds"<<endl;
             if(r.b==0){
                 throw exception();
             }
              return a / r.b;
          }
          if (r.a!=0&& r.b==0){
              a=a/r.a;
              r.a=1;
              a=sqrt(a);
              return a/r.a;
          }
      }
     RealVariable operator^ (RealVariable r, float  a) {
          if(a==0){
              return RealVariable(0,0,1);
          }if(a==1){
              return RealVariable(0,1,0);
          }if(a==2){
              return RealVariable(1,0,0);
          }
          if(a>2 || a<0){
              throw exception();
          }




      }
     ostream& operator<<(ostream& os, const RealVariable& r){return os;}
     RealVariable operator/(  RealVariable r,float a){
          if(a==0){
              throw exception();
          }
      r.a/=a;
      r.b/=a;
      return r;
      }


     ComplexVariable operator+ (float a, ComplexVariable c) {
         c.v_f+=a;
         return c;
      }
     ComplexVariable operator+ ( ComplexVariable c1, int a) {
          c1.v_f+=a;
          return c1;
      }
     ComplexVariable operator+ (ComplexVariable c1, ComplexVariable c2) {
    c1.c.imag(c2.c.imag()+c1.c.imag());
    c1.c.real(c2.c.real()+c1.c.real());
    c1.v_f+=c2.v_f;
    c1.i+=c2.i;
    return c1;
      }
     ComplexVariable operator+ (ComplexVariable c1, std::complex<double> c2) {
          c1.i=c2.imag();
          return c1;
      }
     ComplexVariable operator+ (std::complex<double> c1,ComplexVariable c2 ) {return c2;}
     ComplexVariable operator* (float a, ComplexVariable c1) {
          c1.c.real(c1.c.real()*a);
          c1.c.imag(c1.c.imag()*a);
          return c1;
      }
     ComplexVariable operator- (ComplexVariable c1, float  a) {
          c1.v_f-=a;
          return c1;
      }
     ComplexVariable operator- (ComplexVariable c1, ComplexVariable  c2) {
     c1.c.real(c1.c.real()-c2.c.real());
     c1.c.imag(c1.c.imag()-c2.c.imag());
     c1.v_f-=c2.v_f;
     c1.i-=c2.i;
     return c1;
     }
     ComplexVariable operator == (ComplexVariable c, double  a){
        c.v_f=c.v_f-a;
        return c;

      }
     ComplexVariable operator== (ComplexVariable c1, ComplexVariable c2) {
          c1.i-=c2.i;
          c1.c.real(c1.c.real()-c2.c.real());
          c1.c.imag(c1.c.imag()-c2.c.imag());
          c1.v_f-=c2.v_f;
          return c1;

          }
     ComplexVariable operator^ (ComplexVariable c1, float  a) {
         if(a==2){
             c1.hezka=2;
             return c1;
         }
         if(a>2 || a<=0){
             throw exception();
         }

      }
     ostream& operator<<(ostream& os, const ComplexVariable c){return os;}
     ComplexVariable operator/( ComplexVariable c,float a){
          c.c.imag(c.c.imag()/a);
          c.c.real(c.c.real()/a);
          return c;
      }


float solve(RealVariable a) {
        return Quadratic_Equation(a.a,a.b,a.c);
}
float Quadratic_Equation(float a,float b,float c){
    float d,root1,root2;


    d=b*b-4*a*c;

    if(d==0)
    {
        root1=(-b)/(2*a);
        root2=root1;
        //cout<<"Roots are real & equal";
    }
    else if(d>0)
    {
        root1=-(b+sqrt(d))/(2*a);
        root2=-(b-sqrt(d))/(2*a);
        //cout<<"Roots are real & distinct";
    }
    else
    {
        root1=(-b)/(2*a);
        root2=sqrt(-d)/(2*a);
        cout<<"Roots are imaginary";
    }
return root1;
    //cout<<"\nRoot 1= "<<root1<<"\nRoot 2= "<<root2;
      }
     std::complex<double> Quadrati_Complex(double a,double b,double c){
         float d,root1,root2;

         d=b*b-4*a*c;

         if(d==0)
         {
             root1=(-b)/(2*a);
             root2=root1;
             //cout<<"Roots are real & equal";
         }
         else if(d>0)
         {
             root1=-(b+sqrt(d))/(2*a);
             root2=-(b-sqrt(d))/(2*a);
             return  std::complex<double> (root1,0);
             //cout<<"Roots are real & distinct";
         }
         else
         {
             root1=(-b)/(2*a);
             root2=sqrt(-d)/(2*a);
             cout<<"Roots are imaginary";
             return  std::complex<double> (0,root2);

         }
          return  std::complex<double> (root1,0);

         //cout<<"\nRoot 1= "<<root1<<"\nRoot 2= "<<root2;
     }
double solve (float a){
    return a;
}


}
std::complex<double> solver::solve (ComplexVariable c){
    std::complex<double> ans;
    if(c.i>0){
        return std::complex<double> (0,2);
    }
    if(c.hezka>0){
          return  Quadrati_Complex(c.c.real(),0,c.v_f);
    }
    if(c.v_f>0){
        c.v_f=sqrt(c.v_f);
        ans.imag(c.v_f/c.c.imag());
        return ans;
    }
    if(c.hezka>0){
        c.v_f=sqrt(-c.v_f);
        ans.real(-c.v_f/c.c.real()  );
    return ans;
    }
    if(c.i==0) {
        ans.real(-c.v_f/c.c.real()  );
    }
    return ans;
}






