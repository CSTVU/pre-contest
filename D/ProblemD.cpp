#include <stdio.h>
#include <math.h>

int checkPrime(int n) {
	int sw;
	if (n == 1 || (n % 2 == 0 && n != 2)) sw = 0;
	else sw = 1;
	int i;
	for(i = 2;i < n && sw == 1; i++) {
		if (n % i == 0) sw = 0;
	}
	return sw;
}

int dieHard(long int n) {
	while (n > 0) {
		if (checkPrime(n) == 0) return 0;
		n /= 10;
	}
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	long int i = pow(10, n - 1);
	for (i; i < pow(10, n); i++) {
		if (dieHard(i) == 1) printf("%ld\n", i);
	}
	return 0;
}

