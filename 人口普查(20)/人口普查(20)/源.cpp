#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <iomanip>  
using namespace std;

#define MAX 100000+10  
struct People
{
	char name[20];
	int year;
	int month;
	int day;
} people[MAX];

int isLegal(People p)
{
	if (p.year > 1814 && p.year < 2014)
		return 1;
	else if (p.year == 1814)
	{
		if (p.month > 9)
			return 1;
		else if (p.month == 9 && p.day >= 6)
			return 1;
	}
	else if (p.year == 2014)
	{
		if (p.month < 9)
			return 1;
		else if (p.month == 9 && p.day <= 6)
			return 1;
	}
	return 0;
}

int younger(People p1, People p2)
{
	if (p1.year > p2.year)
		return 1;
	else if (p1.year == p2.year && p1.month > p2.month)
		return 1;
	else if (p1.year == p2.year && p1.month == p2.month && p1.day > p2.day)
		return 1;
	return 0;
}

int older(People p1, People p2)
{
	if (p1.year < p2.year)
		return 1;
	else if (p1.year == p2.year && p1.month < p2.month)
		return 1;
	else if (p1.year == p2.year && p1.month == p2.month && p1.day < p2.day)
		return 1;
	return 0;
}
/*
int cmp(const void *a, const void *b)
{
struct People* c = (People*)a;
struct People* d = (People*)b;
if ((*c).year == (*d).year)
{
if ((*c).month == (*d).month)
return (*d).day - (*c).day;
else
return (*d).month - (*c).month;
}
else
{
return (*d).year - (*c).year;
}
}
*/

int main()
{
	//freopen("in.txt", "r", stdin);  
	//freopen("out.txt", "w", stdout);  
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", people[i].name);
		scanf("%d/%d/%d", &people[i].year, &people[i].month, &people[i].day);
	}

	//qsort(people, n, sizeof(people[0]), cmp);  

	int cnt = 0;
	People youngpeople = { "", 0, 0, 0 }, oldpeople = { "", 9999, 9999, 9999 };
	for (int i = 0; i < n; i++)
	{
		if (isLegal(people[i]))
		{
			if (older(people[i], oldpeople))
				oldpeople = people[i];
			if (younger(people[i], youngpeople))
				youngpeople = people[i];
			cnt++;
		}
	}

	cout << cnt << " " << oldpeople.name << " " << youngpeople.name;
	return 0;
}