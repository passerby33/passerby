#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//unsigned int reverse_bit(unsigned int value)
//{
//	int count = 0;
//	int a = value;
//	while (a >> 1)
//	{
//		count++;
//	}
//	count++;
//	return value << (32 - count);
//}
//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 0;
//	int bit = 0;
//	int sum = 0;
//	for (i = 0; i < 32; i++)
//	{
//		sum = sum << 1;
//		bit = value & 1;
//		sum = sum | bit;
//		value = value >> 1;
//	}
//	return sum;
//}
//int main()
//{
//	unsigned int value = 0;
//	scanf("%u", &value);
//	printf("%u", reverse_bit(value));
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d%d", &a, &b);
//	printf("%d", (a&b) + ((a^b) >> 1));
//	system("pause");
//	return 0;
//}
int main()
{
	int a[8] = { 3, 4, 5, 1, 3, 4, 5 };
	int i = 0;
	for (i = 1; i < sizeof(a) / sizeof(a[0]); i++)
	{
		a[0] = a[0] ^ a[i];
	}
	printf("%d", a[0]);
	system("pause");
	return 0;
}


