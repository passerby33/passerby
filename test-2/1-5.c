//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//int binary_Search(int arr[], int y, int left, int right)
//{
//	int mid=0;
//	while (left <= right)
//	{
//		mid = left + (right - left);
//		if (y == arr[mid])
//		     return mid;
//		else if (y < arr[mid])
//			right = mid - 1;
//		else if (y > arr[mid])
//			left = mid + 1;
//	}
//	return -1;
//
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int left = 0;
//	int x = 0;
//	int ret = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	scanf("%d", &x);
//	ret = binary_Search(arr, x, left, right);
//	if (ret >= 0)
//		printf("�±�Ϊ��%d\n", ret);
//	else
//		printf("û�ҵ�\n");
//	system("pause");
//	return 0;
//}
//int main()
//{
//	char arr[20]="";
//	int i = 0;
//	printf("����������:\n");
//	while (i < 3)
//	{
//		scanf("%s", arr);
//		if (0 == strcmp(arr, "qwer"))
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//		else if (i == 2)
//		{
//			printf("��������˳�����\n");
//			break;
//		}
//		else if (1)
//		{
//			printf("����������:\n");
//		}
//
//		i++;
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	char x;
//	scanf("%c", &x);
//	if ('a' <= x&&x <= 'z')
//		printf("%c�Ĵ�д��ĸΪ��%c\n", x,x - 32);
//	else if ('A' <= x&&x <= 'Z')
//		printf("%c��Сд��ĸΪ��%c\n", x,x + 32);
//	system("pause");
//	return 0;
//}
//
//#include <time.h>
//void game()
//{
//	int ret = 0;
//	int guess = 0;
//	ret = rand()%100+1;
//	while(1)
//	{
//		printf("�������:>");
//		scanf("%d", &guess);
//		if(guess>ret)
//		{
//			printf("�´���\n");
//		}
//		else if(guess<ret)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("�¶���\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do 
//	{
//		printf("*******************\n");
//		printf("    1,��ʼ��Ϸ     \n");
//		printf("    0,�˳���Ϸ     \n");
//		printf("*******************\n");
//		printf("��ѡ��:");
//		scanf("%d", &input);
//		switch(input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��\n");
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}
//
