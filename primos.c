#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
		int i, j, N = 10000000, c, count = 0, primos = 0;

		for(i = 2; i <= N; i++){
			c = 0;
			for(j = 2; j <=  sqrt(N); j++){
				if((i%j == 0) && (i != j)){
					c = 1;
				}
			}	
			if(c == 0){
				primos++;
				/*printf("%d\t", i);
				count++;
				if(count%14 == 0){
					printf("\n");
				}*/
			}		
						
		}
		printf("\ncantidad de primos : %d", primos);
		printf("\ncantidad por Gauss : %f", N / log(N));
		return 0;
}


