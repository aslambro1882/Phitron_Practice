#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date getNextDate(struct Date date)
{
    struct Date nextDate = date;
    if (nextDate.day != daysInMonths[nextDate.month - 1])
        nextDate.day++;
    else if (nextDate.month != 12)
    {
        nextDate.day = 1;
        nextDate.month++;
    }
    else
    {
        nextDate.day = 1;
        nextDate.month = 1;
        nextDate.year++;
    }
    return nextDate;
}

void printDate(struct Date date)
{
    printf("%d-%d-%d\n", date.day, date.month, date.year);
}
int main()
{

    struct Date start;
    int n;
    scanf("%d %d %d", &start.day, &start.month, &start.year);

    scanf("%d", &n);

    struct Date current = start;
    for (int i = 0; i < n; i++)
    {
        current = getNextDate(current);
        printf("%dth day: ", i + 1);
        printDate(current);
    }

    return 0;
}