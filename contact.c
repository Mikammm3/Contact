#include"contact.h"

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
		printf("通讯录已满\n");
	else
	{
		printf("请输入要添加人的名字:>");
		scanf_s("%s", ps->data[ps->size].name, MAX_NAME);
		printf("请输入要添加人的性别:>");
		scanf_s("%s", ps->data[ps->size].sex, MAX_SEX);
		printf("请输入要添加人的电话:>");
		scanf_s("%s", ps->data[ps->size].tele, MAX_TELE);
		printf("请输入要添加人的地址:>");
		scanf_s("%s", ps->data[ps->size].addr, MAX_ADDR);
		printf("请输入要添加人的年龄:>");
		scanf_s("%d", &(ps->data[ps->size].age));
		(ps->size)++;
		printf("添加成功\n");
	}
}

static int Find(const struct Contact* ps,char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
			return i;
	}
	return -1;
}


void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除的人的名字\n");
	scanf_s("%s", name, MAX_NAME);
	int pos = Find(ps, name);
	if (-1 == pos)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
	}
}
void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
		printf("该通讯录为空\n");
	else
	{
		int i = 0;
		printf("%-20s\t %-20s\t %-20s\t %-12s\t %-30s\t\n", "姓名", "性别", "年龄", "电话", "住址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-20s\t%-20d\t%-12s\t%-30s\t\n",
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf_s("%s", name, MAX_NAME);
	int pos = Find(ps, name);
	if (pos == -1)
		printf("该联系人不存在\n");
	else
	{
		printf("%-20s\t%-20s\t%-20d\t%-12s\t%-30s\t\n",
			ps->data[pos].name,
			ps->data[pos].sex,
			ps->data[pos].age,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字:>");
	scanf_s("%s", name, MAX_NAME);
	int pos = Find(ps, name);
	if (pos == -1)
	{
		printf("该联系人不存在\n");
	}
	else
	{
		printf("请输入要修改的名字:>");
		scanf_s("%s", ps->data[pos].name, MAX_NAME);
		printf("请输入要修改的性别:>");
		scanf_s("%s", ps->data[pos].sex, MAX_SEX);
		printf("请输入要修改的电话:>");
		scanf_s("%s", ps->data[pos].tele, MAX_TELE);
		printf("请输入要修改的地址:>");
		scanf_s("%s", ps->data[pos].addr, MAX_ADDR);
		printf("请输入要修改的年龄:>");
		scanf_s("%d", &(ps->data[pos].age));
		printf("修改成功\n");
	}
}