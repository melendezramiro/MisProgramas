/************Este programa calcula los pesos de una funcion ********************/
#include <stdio.h>
#include <stdlib.h>

main(){
	int N = 22;
	float X[]={1,1,1,2,2,3,4,5,5,6,7,7,2,3,3,4,4,5,5,6,6,6,7};
	float Y[]={3,4,5,2,3,1,1,1,2,2,2,3,6,5,6,4,5,3,4,4,5,6,6};
	float I[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	float S[]={1,1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int iteraciones=0;
	int i, j, k;
	float A=0.01, B=0.01, C=0.01, D=0.01, E=0.01, F=0.01;
	float alfa=0.0001, aux=0;
	float c[N];

	while( iteraciones <= 300000){

		for(i = 0; i <= N; i++){
			aux = 0;
			aux = (A*X[i]*X[i]) + (B*X[i]) + (C*X[i]*Y[i]) + (D*Y[i]) + (E*Y[i]*Y[i]) + F;
			

			if(aux != S[i]){
				c[i] = aux;
				c[i] = (S[i] - c[i])*alfa;

			}
			else 
				c[i] = 0;

			printf("%.4f\n", c[i]);
		
			A = A + c[i]*X[i]*X[i];
			B = B + c[i]*X[i];
			C = C + c[i]*X[i]*Y[i];
			D = D + c[i]*Y[i];
			E = E + c[i]*Y[i]*Y[i];
			F = F + c[i];			
		}
		
		iteraciones++;
	}

	printf("Los pesos son:\nA = %.3f, B = %.3f, C = %.3f, D = %.3f, E = %.3f, F = %.3f\n", A, B, C, D, E, F);
	printf("La funcion es:\n(%.3f) X^2 + (%.3f) X + (%.3f) XY + (%.3f) Y + (%.3f) Y^2 + (%.3f) = 0\n", A, B, C, D, E, F);

	return 0;
}
