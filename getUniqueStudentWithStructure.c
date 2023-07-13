#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Student
{
    char name[50];
    int id;
    int marks;
    int total;
};
struct unique_student
{
    char name[50];
    int id;
    int total;
};

int main()
{
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        printf("file not found");
        return 0;
    }
    FILE *outputFile = fopen("output.txt", "w");

    int n;
    fscanf(inputFile, "%d", &n);
    struct Student exam[n];
    struct unique_student unique_students[n];
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        fscanf(inputFile, "%s %d %d", &exam[i].name, &exam[i].id, &exam[i].marks);
        // unique_students[i] = exam[i];
        bool found = false;
        for (int j = 0; j < idx; j++)
        {
            if (unique_students[j].id == exam[i].id)
            {
                unique_students[j].total += exam[i].marks;
                found = true;
            }
        }
        if (!found)
        {
            strcpy(unique_students[idx].name, exam[i].name);
            unique_students[idx].id = exam[i].id;
            unique_students[idx].total = exam[i].marks;
            idx++;
        }
    }

    for (int i = 0; i < idx - 1; i++)
    {
        for (int j = i; j < idx; j++)
        {
            if (unique_students[i].total < unique_students[j].total)
            {
                struct unique_student temp = unique_students[i];
                unique_students[i] = unique_students[j];
                unique_students[j] = temp;
            }
        }
    }

    for (int i = 0; i < idx; i++)
    {
        fprintf(outputFile, "%s %d %d\n", unique_students[i].name, unique_students[i].id, unique_students[i].total);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}