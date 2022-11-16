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
	//����һ��ͨѶ¼
	struct Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("������:>");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);
	return 0;
}