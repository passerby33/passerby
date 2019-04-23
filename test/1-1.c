//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
////int main()
////{
////	int i = 0;
////	int j = 0;
////	for (i = 1; i <= 9; i++)
////	{
////		for (j = 1; j <= i; j++)
////			printf("%d*%d=%d  ", j, i, i*j);
////		    printf("\n");
////	}
////	system("pause");
////	return 0;
////}
////int main()
////{
////	int a = 10;
////	int b = 20;
////	int temp = 0;
////	temp = a;
////	a = b;
////	b = temp;
////	printf("a=%d b=%d\n", a, b);
////	system("pause");
////	return 0;
////}
////int main()
////{
////	int a = 10;
////	int b = 20;
////	a = a + b;
////	b = a - b;
////	a = a - b;
////	printf("a=%d b=%d\n", a, b);
////	system("pause");
////	return 0;
////
////}
////int main()
////{
////	int a[10] = { 0 };
////	int i = 0;
////	for (i = 0; i < 10; i++)
////		scanf("%d", &a[i]);
////	for (i = 1; i < 10; i++)
////	{
////		if (a[i]>a[0])
////			a[0]= a[i];
////	}
////	printf("最大值为:%d\n", a[0]);
////	system("pause");
////	return 0;
////}
////int main()
////{
////	int a = 0;
////	int b = 0;
////	int c = 0;
////	scanf("%d %d %d", &a, &b, &c);
////	if (a < b)
////	{
////		a = a + b;
////		b = a - b;
////		a = a - b;
////	}
////    if (a < c)
////	{
////		a = a + b;
////		b = a - b;
////		a = a - b;
////	}
////	 if (b < c)
////	{
////		b = b + c;
////		c = b - c;
////		b = b - c;
////	}
////
////	printf("%d %d %d\n", a, b, c);
////	system("pause");
////	return 0;
////}
////int main()
////{
////	int a = 0;
////	int b = 0;
////	int temp = 0;
////	int i = 0;
////	scanf("%d %d", &a, &b);
////	if (a < b)
////	{
////		temp = b;
////		b = a;
////		a = temp;
////	}
////	for (i = b; i >= 1; i--)
////	{
////		if (a%i == 0 && b%i == 0)
////			break;
////	}
////	printf("最大公约数为：%d\n", i);
////	system("pause");
////	return 0;
////}
////int main()
////{
////	int a[5] = { 1, 2 ,3 ,4 ,5 };
////	int b[5] = { 6, 7, 8, 9, 10 };
////	int temp = 0;
////	int i = 0;
////	for (i = 0; i < 5; i++)
////	{
////		temp = a[i];
////		a[i] = b[i];
////		b[i] = temp;
////	}
////	for (i = 0; i < 5; i++)
////	{
////		printf("%d ", a[i]);
////	}
////	printf("\n");
////	for (i = 0; i < 5; i++)
////	{
////		printf("%d ", b[i]);
////	}
////	printf("\n");
////	system("pause");
////	return 0;
////
////}
//int main()
//{
//	int i = 0;
//	double sum = 0;
//
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 2 == 1)
//		{
//			sum += 1.0 / i;
//		}
//		if (i % 2 == 0)
//		{
//			sum -= 1.0 / i;
//		}
//	}
//	printf("%lf", sum);	
//	system("pause");
//	return 0;
//}
////int main()
////{
////	int i = 0;
////	int j = 0;
////	for (i = 1; i <= 100; i++)
////	{
////		if (i % 10 == 9)
////			j++;
////	    if (i - i % 10 == 90)
////			j++;
////	}
////	printf("%d\n", j);
////	system("pause");
////	return 0;
////}
//
//
//
//
//
