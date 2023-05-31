#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) pow(x,2)+log(x)-3

void main()
{
	 float x1, x2, x3, f1, f2, f3, e;
	 int step = 1, N;
	 
	 printf("\nEnter initial guesses:\n");
	 scanf("%f%f", &x1, &x2);
	 printf("Enter tolerable error:\n");
	 scanf("%f", &e);
	 printf("Enter maximum iteration:\n");
	 scanf("%d", &N);
	
	 /* Implementing Secant Method */
	 printf("\nStep\t\tx1\t\tx2\t\tx3\t\tf(x3)\n");
	 do
	 {
		  f1 = f(x1);
		  f2 = f(x2);
		  if(f1 == f2)
		  {
			   printf("Mathematical Error.");
			   exit(0);
		  }
		  
		  x3 = x2 - (f2*(x2-x1))/(f2-f1);
		  f3 = f(x3);
		  
		  printf("%d\t\t%f\t%f\t%f\t%f\n", step, x1, x2, x3, f3);
		  
		  x1 = x2;
		  f1 = f2;
		  x2 = x3;
		  f2 = f3;
		  
		  step = step + 1;
		  
		  if(step > N)
		  {
			   printf("Not Convergent.");
			   exit(0);
		  }
	 }while(fabs(f3)>e);
	
	 printf("\nRoot is: %f", x3);
	 getch();
}
