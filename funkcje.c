#include <stdio.h>
#include <math.h>
#include <limits.h>

using namespace std;

double f(double x)
{
	//double res = 2*x*x - 5*x + 2.3;
	double res = 0.2*x*x *x - 4*x*x + 3*x + 12;
	printf("\nf(%f) = %f", x, res);
	return res;
}


double bisekcja(double a, double b, double epsilon,int &kroki)
{
	double srodek;
	if(f(a) * f(b) < 0)
	{
  		srodek = a;
  		while((b - a) > epsilon)
		  {
  			srodek = (a + b) / 2;
  			if(f(a) * f(srodek) < 0)
  			{
  	 			b = srodek;
  			}
  			else 
     			if(f(b) * f(srodek) < 0)
	 			{
        			a = srodek;
     			}
	 			else 
	    			break;
  			kroki++;
  		  }
	}
	else
  	{
    	/* sprawdzamy odcinek [a,b] w 1/epsilon kawalkach */
    	double min = 1000000; /* najblizsza 0 wartosc funkcji */
    	double num = a; /* argument, dla ktorego funkcja byla najmniej odlegla od 0 */
   		a = a + epsilon * 100;
    	do
    	{
    		double val = fabs(f(a));
    		if (val < min)
    		{
    			min = val;
    			num = a;
			}
			a = a + epsilon * 100;
			kroki = kroki + 1;
    	} while (a <= b);
    	int j = 0;
		do {
	    	a = num;
	    	int i = 0;
	    	do
	    	{
	    		double val = fabs(f(a));
	    		if (val < min)
	    		{
	    			min = val;
	    			num = a;
				}
				a = a - epsilon;
				i = i + 1;
				kroki++;
	    	} while (i < 100);
			a = num + epsilon;
			i = 0;
	    	do
	    	{
	    		double val = fabs(f(a));
	    		if (val < min)
	    		{
	    			min = val;
	    			num = a;
				}
				a = a + epsilon;
				i = i + 1;
				kroki++;
	    	} while (i < 100);
	    	epsilon = epsilon /10;
	    	j = j + 1;
    } while (min > epsilon && j < 5);
    srodek = num;
	}
	return srodek;
}
