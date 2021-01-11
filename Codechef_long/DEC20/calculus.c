
#include<stdio.h>
#include<math.h>
int main(){
	int n=1;
	double  s=0;
	double  x=0.0000000001;
	while (x<100000000000000)
    {s+=(((exp((2*M_PI*x))-1)/(exp((2*M_PI*x))+1))*(1/x - x/(pow(n,2)+pow(x,2))))*x;
    x=x+0.00000001;
	}
	printf("%lf",s);
	return 0;
}
