#include "stdio.h"
#include "math.h"


//input should between 0-45,that is what i need!!
//sin(0)=0 cos(0)=1 is always correct
int __65536_cos(int deg)
{
   return (deg*(-9*deg-21))+65536;
}

int __65536_sin(int deg)
{
   return deg*(-4*deg+1210);
}

//test
int main()
{
   int i;   
   for(i=0;i<=45;i++)
   {
      printf("%02d,0x%x %+f \t",i,__65536_cos(i), cos(i*2*3.1415926535/360)-__65536_cos(i)/65536.0);
      printf("%02d,0x%x %+f \n",i,__65536_sin(i), sin(i*2*3.1415926535/360)-__65536_sin(i)/65536.0);
   }
   
   for(i=0;i<=45;i++)
   {
      printf("%02d, %d\t",i,round(100*cos(i*2*3.1415926535/360))-100*__65536_cos(i)/65536);
      printf("%02d, %d\n",i,round(100*sin(i*2*3.1415926535/360))-100*__65536_sin(i)/65536);
   }
   for(i=0;i<=45;i++)
   {
      printf("%02d, %d\t",i,round(44*cos(i*2*3.1415926535/360))-44*__65536_cos(i)/65536);
      printf("%02d, %d\n",i,round(44*sin(i*2*3.1415926535/360))-44*__65536_sin(i)/65536);
   }
}
