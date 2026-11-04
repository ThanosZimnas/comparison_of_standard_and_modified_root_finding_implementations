
#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>
double f(double x){
return 94*pow(cos(x),3)- 24*cos(x)+177*pow(sin(x),2)-108*pow(sin(x),4)-72*pow(cos(x),3)*pow(sin(x),2)-65;   
};
double f2(double x){
  return (216*pow(cos(x),2)-432*cos(x))*pow(sin(x),3)+(-144*pow(cos(x),4)-282*pow(cos(x),2)+354*cos(x)+24)*sin(x);  
};
double f3(double x){
    return 432*(1-cos(x))*pow(sin(x),4)+(1224*pow(cos(x),3)-1296*pow(cos(x),2)+564*cos(x)-354)*pow(sin(x),2)-144*pow(cos(x),5)-282*pow(cos(x),3)+354*pow(cos(x),2)+24*cos(x);
}
double bisection(double start,double end,double error,int counter){
    if(fabs((start+end)/2.0)<error ||(end-start)<error)
    { std::cout<<counter<<std::endl;
    return (start+end)/2.0;
   }
    if (f(start)*f((start+end)/2.0)<0)
    return bisection(start,(start+end)/2.0,error,counter+1);
    else
    return bisection((start+end)/2.0,end,error,counter+1);
};
double ModifiedBisection(double a,double b,double error,int counter){
    double p1=a+(b-a)*1/3.0;
    double p2=a+(b-a)*2/3.0;
    if(fabs(p1)<error || b-a<error)
    {std::cout<<counter<<std::endl;
    return p1;}
    if(fabs(p2)<error)
    {std::cout<<counter<<std::endl;
    return p2;}
    if(f(a)*f(p1)<0 && f(p2)*f(b)>0)
    return ModifiedBisection(a,p1,error,counter+1);
    if (f(a)*f(p1)>0 && f(p2)*f(b)<0)
    return ModifiedBisection(p2,b,error,counter+1);
    if (f(a)*f(p1)<0 && f(b)*f(p2)<0)
    {
        if (f(a)<f(b))
        return ModifiedBisection(a,p1,error,counter+1);
        else return ModifiedBisection(p2,b,error,counter+1);
    }
    if (f(a)<f(b))
    return ModifiedBisection(a,p2,error,counter+1);
    else return ModifiedBisection(p1,b,error,counter+1);
}
double NewtonRaphson(double x,double error,int counter){
   double  x2=x-f(x)/(double)f2(x);
    if (fabs(x2-x)<error)
    {std::cout<<counter<<std::endl;
    return x2;
    }
    return NewtonRaphson(x2,error,counter+1);
};
double ModifiedNewtonRaphson(double x,double error,int counter){
    double x2=x-f(x)/f2(x)-(1/2.0)*pow(f(x),2)*f3(x)/pow(f2(x),3);
    if (fabs(x2-x)<error)
    {std::cout<<counter<<std::endl;
    return x2;
    }
    return ModifiedNewtonRaphson(x2,error,counter+1);
}
double secant(double x1,double x2,double error,int counter){
  double x3 = x2-f(x2)*(x2-x1)/(f(x2)-f(x1));
  if (fabs(x3-x2)<error)
  {
  std::cout<<counter<<std::endl;
  return x3;}
  return secant(x2,x3,error,counter+1);
};
double ModifiedSecant(double x0,double x1,double x2,double error,int counter){
    double q=f(x0)/(double)f(x1);
    double r = f(x2)/(double)f(x1);
    double s=f(x2)/(double)f(x0);
    double x3=x2-(r*(r-q)*(x2-x1)+(1-r)*s*(x2-x1))/(double)((q-1)*(r-1)*(s-1));
    if (fabs(x3-x2)<error)
  {
  std::cout<<counter<<std::endl;
  return x3;}
  return ModifiedSecant(x1,x2,x3,error,counter+1);
}
int main()
{
    std::cout<<std::fixed<<std::setprecision(7);
     std::random_device rd;
    std::mt19937 gen(rd());
     std::uniform_real_distribution<double> dista(0.0,0.8);
     std::uniform_real_distribution<double> distb(2.4,3.0);
 std::cout<<ModifiedBisection(0,1,1e-8,0)<<std::endl;
 std::cout<<ModifiedNewtonRaphson(0.8,1e-8,0)<<std::endl;
 std::cout<<ModifiedSecant(0.6,0.7,0.8,1e-8,0)<<std::endl;
  std::cout<<ModifiedBisection(0.85,1.1,1e-8,0)<<std::endl;
 std::cout<<ModifiedNewtonRaphson(1.15,1e-8,0)<<std::endl;
 std::cout<<ModifiedSecant(1.4,1.3,1.2,1e-8,0)<<std::endl;
  std::cout<<ModifiedBisection(2,3,1e-8,0)<<std::endl;
 std::cout<<ModifiedNewtonRaphson(2.5,1e-8,0)<<std::endl;
 std::cout<<ModifiedSecant(1.7,1.8,1.9,1e-8,0)<<std::endl;
 for (int i=0;i<20;i++)
 {double x1=dista(gen);
 double x2=distb(gen);
  std::cout<<ModifiedBisection(x1,x2,1e-8,0)<<' '<<x1<<' '<<x2<<std::endl;}
  std::uniform_real_distribution<double> dist2(0,0.5);
  std::uniform_real_distribution<double> dist3(0.9,1);
  for (int j=0;j<100;j++){
       double a=dist2(gen);
       double b=dist3(gen);
      std::cout<<"------"<<std::endl;
      ModifiedBisection(a,b,1e-8,0);
      bisection(a,b,1e-8,0);
  }
  std::cout<<"///////////////////////////////////////////////////////////"<<std::endl;
  std::uniform_real_distribution<double> dist(0.5,2.5);
  for (int k=0;k<100;k++){
      double z=dist(gen);
       std::cout<<"------"<<std::endl;
       ModifiedNewtonRaphson(z,1e-8,0);
       NewtonRaphson(z,1e-8,0);
  }
  std::uniform_real_distribution<double> dist4(0.4,0.5);
  std::cout<<"///////////////////////////////////////////////////////////"<<std::endl;
  for (int l=0;l<100;l++){
      double h=dist4(gen);
       std::cout<<"------"<<std::endl;
       ModifiedSecant(h,h+0.1,h+0.2,1e-8,0);
       secant(h,h+0.1,1e-8,0);
  }
    return 0;
}