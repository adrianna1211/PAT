#include<math.h>
#include<stdio.h>
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int t = floor((b - a) / 100.0 + 0.5);
	printf("%02d:%02d:%02d\n", t / 3600, t % 3600 / 60, t % 60);
	return 0;