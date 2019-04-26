//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//void nxn(int N)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= N; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ",j,i,i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	nxn(n);
//	system("pause");
//	return 0;
//}
//void swap(int *A, int *B)
//{
//	int temp = 0;
//	temp = *A;
//	*A = *B;
//	*B = temp;
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d",&a, &b);
//	swap(&a, &b);
//	printf("a=%d b=%d\n", a, b);
//	system("pause");
//	return 0;
//	
//}
//int leap_year(int year)
//{
//	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	int year = 0;
//	int ret = 0;
//	scanf("%d", &year);
//	ret = leap_year(year);
//	if (ret == 1)
//	{
//		printf("%d是闰年\n", year);
//	}
//	else
//		printf("%d不是闰年\n", year);
//	system("pause");
//	return 0;
//	
//}
//void init(int arr[], int sz)
//{
//	int i = 0;
//	int*p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	printf("数组的初始化：");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//}
//void empty(int arr[], int sz)
//{
//	int i = 0;
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//	printf("数组的清空：" );
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//}
//void reverse(int arr[], int sz)
//{
//	int i = 0;
//	int temp = 0;
//	int *p = arr;
//	for (i = 0; i < sz/2; i++)
//	{
//		temp = arr[i];
//		arr[i] = arr[sz - i - 1];
//		arr[sz - i - 1] = temp;
//	}
//	printf("数组的逆置：");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int arr[7] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int *p = arr;
//	init(arr, sz);
//	reverse(arr, sz);
//	empty(arr, sz);
//    system("pause");
//	return 0;
//
//}
//int is_prime(int a)
//{
//	int i = 0;
//	for (i = 2; i < a; i++)
//	{
//		if (a % i == 0)
//			break;
//	}
//	if (i == a)
//	{
//		return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret=is_prime(a);
//	if (ret == 1)
//	{
//		printf("%d是素数\n", a);
//	}
//	else
//		printf("%d不是素数\n", a);
//	system("pause");
//	return 0;
//}
