#include"contact.h"

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
		printf("ͨѶ¼����\n");
	else
	{
		printf("������Ҫ����˵�����:>");
		scanf_s("%s", ps->data[ps->size].name, MAX_NAME);
		printf("������Ҫ����˵��Ա�:>");
		scanf_s("%s", ps->data[ps->size].sex, MAX_SEX);
		printf("������Ҫ����˵ĵ绰:>");
		scanf_s("%s", ps->data[ps->size].tele, MAX_TELE);
		printf("������Ҫ����˵ĵ�ַ:>");
		scanf_s("%s", ps->data[ps->size].addr, MAX_ADDR);
		printf("������Ҫ����˵�����:>");
		scanf_s("%d", &(ps->data[ps->size].age));
		(ps->size)++;
		printf("��ӳɹ�\n");
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
	printf("������Ҫɾ�����˵�����\n");
	scanf_s("%s", name, MAX_NAME);
	int pos = Find(ps, name);
	if (-1 == pos)
	{
		printf("Ҫɾ�����˲�����\n");
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
		printf("��ͨѶ¼Ϊ��\n");
	else
	{
		int i = 0;
		printf("%-20s\t %-20s\t %-20s\t %-12s\t %-30s\t\n", "����", "�Ա�", "����", "�绰", "סַ");
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
	printf("������Ҫ�����˵�����:>");
	scanf_s("%s", name, MAX_NAME);
	int pos = Find(ps, name);
	if (pos == -1)
		printf("����ϵ�˲�����\n");
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
	printf("������Ҫ�޸��˵�����:>");
	scanf_s("%s", name, MAX_NAME);
	int pos = Find(ps, name);
	if (pos == -1)
	{
		printf("����ϵ�˲�����\n");
	}
	else
	{
		printf("������Ҫ�޸ĵ�����:>");
		scanf_s("%s", ps->data[pos].name, MAX_NAME);
		printf("������Ҫ�޸ĵ��Ա�:>");
		scanf_s("%s", ps->data[pos].sex, MAX_SEX);
		printf("������Ҫ�޸ĵĵ绰:>");
		scanf_s("%s", ps->data[pos].tele, MAX_TELE);
		printf("������Ҫ�޸ĵĵ�ַ:>");
		scanf_s("%s", ps->data[pos].addr, MAX_ADDR);
		printf("������Ҫ�޸ĵ�����:>");
		scanf_s("%d", &(ps->data[pos].age));
		printf("�޸ĳɹ�\n");
	}
}