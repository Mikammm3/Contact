#include<stdio.h>
#include<string.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_TELE 12
#define MAX_ADDR 30


enum Option
{
	exit,
	add,
	del,
	search,
	modify,
	show,
	sort
};

struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	int age;
	char addr[MAX_ADDR];
};

struct Contact
{
	struct PeoInfo data[MAX];
	int size;
};

void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void DelContact(struct Contact* ps);
void ShowContact(struct Contact* ps);
void SearchContact(struct Contact* ps);
void ModifyContact(struct Contact* ps);

