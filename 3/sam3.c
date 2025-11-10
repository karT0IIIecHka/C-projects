#include<stdio.h>
#include<limits.h>

int main()
{
	int summa_s = 0, summa_f = 0;
	int digit, digit_n;
	int flag = 1;
	int n = 1;
	char reason = '*';
	int k;
	scanf("%d", &k);
	int cnt = 0;
	for (int ffiv = 0; ffiv <= 4; ffiv++) {
		for (int fth = 0; fth <= 7; fth++) {
			for (int fon = 0; fon <= 21; fon++) {
				if (ffiv * 5 + fth * 3 + fon == 21 && ffiv + fth + fon <= 11) {
					cnt += 1;
				}
			}
		}
	}
	printf("%d\n", cnt);
	printf("\n");

	
	for (int i = 1; i <= 40; i++){
		n = i;
		for (int a = 1; a <= k; a++){
			digit_n = a;
			digit = a;
			for (int j = 1; j <= n; j++) {
				if (digit <= LONG_MAX / digit_n) {
					digit *= digit_n;
				}
				else {
					flag = 0;
					reason = '*';
					break;
				}
			}
			if (flag == 0) {
				break;
			}
			else {
				if (summa_s <= LONG_MAX - digit) {
					summa_s += digit;
				}
				else {
					flag = 0;
					reason = '+';
					break;
				}
			}
		}
		if (flag == 0) {
			break;
		}
		else {
			summa_f = summa_s;
			summa_s = 0;
		}
	}
	printf("%d\n", summa_f);
	printf("%d\n", n);
	printf("%c\n", reason);
	return 0;
}