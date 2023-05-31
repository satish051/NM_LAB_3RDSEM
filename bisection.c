#include<stdio.h>
#include<conio.h>
#include<math.h>

#define f(x) (pow(x,2)*sin(x))+exp(-x)-3

void main()
{
	 float x0, x1, x2, f0, f1, f2, e;
	 int step = 1;
	 
	 up:
	 printf("\nEnter two initial guesses:\n");
	 scanf("%f%f", &x1, &x2);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 
	 f1 = f(x1);
	 f2 = f(x2);
	 if( f1 * f2 > 0.0)
	 {
		  printf("Incorrect Initial Guesses.\n");
		  goto up;
	 }
	 
	 printf("\nStep\t\tx1\t\tx2\t\tx0\t\tf(x0)\n");
	 do
	 {
		  x0 = (x1 + x2)/2;
		  f0 = f(x0);
		
		  printf("%d\t\t%f\t%f\t%f\t%f\n",step, x1, x2, x0, f0);
		
		  if( f1 * f0 < 0)
		  {
			   x2 = x0;
			   f2 = f0;
		  }
		  else
		  {
			   x1 = x0;
			   f1 = f0;
		  }
		  step = step + 1;
	 }while(fabs(f0)>e);
	 printf("\nRoot is: %f", x0);
	 getch();
}
