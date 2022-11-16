#include"contact.h"

void menu()
{
	printf("**************************************\n");
	printf("****    1.Add         2.Del    *******\n");
	printf("****    3.Search      4.Modify *******\n");
	printf("****    5.Show        0.Exit   *******\n");
	printf("**************************************\n");
}

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}

int main()
{
	//创建一个通讯录
	struct Contact con;
	//初始化通讯录
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请输入:>");
		scanf_s("%d", &input);
		switch(input)
		{
		case add:
			AddContact(&con);
			break;
		case del:
			DelContact(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case show:
			ShowContact(&con);
			break;
		case exit:
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	return 0;
}