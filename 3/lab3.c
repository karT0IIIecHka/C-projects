#include<stdio.h>
 
int main()
{
	int amount = 0, divisors = 0;
	for (int i = 190; i <= 220; i++) {
		printf("%d  ", i);
		int a = 0;

		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				if (a == 0) {
					if (j < 10) {
						printf("  %d", j);
					}
					else {
						printf(" %d", j);
					}
				}
				else if(a % 4 == 0){
					printf(",\n");
					printf("     ");
					if (j < 10) {
						printf("  %d", j);
					}
					else if(j < 100){
						printf(" %d", j);
					}
					else {
						printf("%d", j);
					}
				}
				else{
					if (j < 10) {
						printf(",  %d", j);
					}
					else if (j < 100) {
						printf(", %d", j);
					}
					else {
						printf(",%d", j);
					}
				}
				a += 1;
			}
		}

		amount = divisors <= a ? i : amount;
		divisors = divisors <= a ? a : divisors;

		if (a != 0) {
			printf(" ");
			for (int b = (4 -  a % 4)%4; b > 0; b--) {
				printf("    ");
			}
			if (a < 10) {
				printf("    %d", a);
			}
			else {
				printf("   %d", a);
			}
		}
		else {
			printf("                    %d", a);
		}
		printf("\n");
	}
	printf("\n%d\n", amount);
	return 0;
}