//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//int add1(int n)
//{
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	return add1(n - 1) + add1(n - 2);
//}
//int add2(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	int i = 1;
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	for (i = 2; i < n;i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return b;
//
//}
//
//int main()
//{
//	int n = 0;
//	int ret1 = 0;
//	int ret2 = 0;
//	scanf("%d", &n);
//	ret1 = add1(n);
//	ret2 = add2(n);
//	printf("递归第%d个斐波那契数为：%d\n", n,ret1);
//	printf("非递归第%d个斐波那契数为：%d\n", n,ret2);
//	system("pause");
//	return 0;
//}
//int fun(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	return fun(n, k - 1)*n;
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	int ret = 0;
//	scanf("%d%d", &n, &k);
//	ret=fun(n, k);
//	printf("%d^%d=%d\n", n, k, ret);
//	system("pause");
//	return 0;
//
//}
//int DigitSum(int n)
//{
//	int a = 0;
//	if (n < 10)
//	{
//		return n;
//	}
//	while (n>9)
//	{
//		a = n % 10;
//		n /= 10;
//		return a + DigitSum(n);
//	}
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret=DigitSum(n);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//}
//void reverse_string(char *p)
//{
//		
//	if (*p != '\0')
//	{
//		p++;
//		reverse_string(p);
//		printf("%c", *(p - 1));
//	}
//	return 0;
//}
//int main()
//{
//	char string[]="";
//	scanf("%s", string);
//	reverse_string(string);
//	system("pause");
//	return 0;
//}
//int strlen1(char *arr)
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		arr++;
//		count++;
//	}
//	return count;
//}
//int strlen2(char *p)
//{
//	if (*p != '\0')
//		return 1 + strlen2(p + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	char arr[100];
//	scanf("%s", arr);
//	int ret1 = strlen1(arr);
//	int ret2 = strlen2(arr);
//	printf("非递归字符串长度：%d\n", ret1);
//	printf("递归字符串长度：%d\n", ret2);
//	system("pause");
//	return 0;
//}
//int fun1(int n)
//{
//	int i = 0;
//	int sum = 1;
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	return sum;
//}
//int fun2(int n)
//{
//	if (n == 1 || n == 2)
//		return n;
//	else
//		n--;
//		return (n + 1)*fun2(n);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret1 = fun1(n);
//	int ret2 = fun2(n);
//	printf("非递归下%d！=%d\n", n,ret1);
//	printf("递归下%d！=%d\n", n, ret2);
//	system("pause");
//	return 0;
//}
//void fun(int a)
//{
//	if (a > 9)
//		fun(a / 10);
//		printf("%d ", a % 10);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	fun(n);
//	system("pause");
//	return 0;
//}
//






