#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <assert.h>

using namespace std;

struct Date {
	unsigned short year;
	char month[20];
	int day;
};

struct Date computeEaster(unsigned short y)
{
	unsigned short A = y % 19;
	unsigned short B = y % 4;
	unsigned short C = y % 7;
	unsigned short D = (19 * A + 24) % 30;
	unsigned short E = (2 * B + 4 * C + 6 * D + 5) % 7;

	unsigned short day = 22 + E + D;

	struct Date easter;

	if (day > 31)
	{
		easter.day = day - 31;
		strcpy(easter.month, "April");
	}
	else
	{
		easter.day = day;
		strcpy(easter.month, "March");
	}
	easter.year = y;
	return easter;
}


int main()
{
	unsigned short year;

	/*
	printf("Year:\n");
	scanf("%hu", &year);
	*/

	year = 1985;

	struct Date e = computeEaster(year);
	assert((e.day==7) && !(strcmp(e.month,"April")) && (e.year == 1985));

	year = 2021;
	e = computeEaster(year);
	assert((e.day == 4) && !(strcmp(e.month, "April")) && (e.year == 2021));

	year = 2008;
	e = computeEaster(year);
	assert((e.day == 23) && !(strcmp(e.month, "March")) && (e.year == 2008));

	printf("The date is: \n%d %s %d", e.day, e.month, e.year);

	return 0;

}