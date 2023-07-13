#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Students
{
    /* data */
    char name[100];
    int marks;
    int roll;
    char section;
    int whichClass;
};

int main()
{

    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
        return 0;
    FILE *outputFile = fopen("output.txt", "w");

    struct Students student[3] = {};
    for (int i = 0; i < 3; i++)
    {
        fscanf(inputFile, "%s %d %d %c %d", &student[i].name, &student[i].marks, &student[i].roll, &student[i].section, &student[i].whichClass);
    }
    struct Students Highest = {.marks = 0};
    struct Students Lowest = {.marks = student[0].marks};

    printf("Lowest => %s %d %d %c %d\n", Lowest.name, Lowest.marks, Lowest.roll, Lowest.section, Lowest.whichClass);
    printf("Highest => %s %d %d %c %d", Highest.name, Highest.marks, Highest.roll, Highest.section, Highest.whichClass);

    for (int i = 0; i < 3; i++)
    {
        if (Highest.marks < student[i].marks)
            Highest = student[i];
        if (Lowest.marks > student[i].marks)
            Lowest = student[i];
    }

    fprintf(outputFile, "Highest => %s %d %d %c %d", Highest.name, Highest.marks, Highest.roll, Highest.section, Highest.whichClass);
    fprintf(outputFile, "\n");
    fprintf(outputFile, "Lowest => %s %d %d %c %d", Lowest.name, Lowest.marks, Lowest.roll, Lowest.section, Lowest.whichClass);

    return 0;
}