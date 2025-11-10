#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


struct Marks{
    int Math;
    int Phis;
    int Inf;
};

struct Students_files{
    char SurName[16];
    char Name[16];
    int Grade;
    struct Marks MPI;
};

void input(struct Students_files students[], int n){
   for (int i = 0; i < n; i++){
        scanf("%s", &students[i].SurName);
        scanf("%s", &students[i].Name);
        scanf("%d", &students[i].Grade);
        scanf("%d", &students[i].MPI.Math);
        scanf("%d", &students[i].MPI.Phis);
        scanf("%d", &students[i].MPI.Inf);
    }   
}

void output(struct Students_files students[], int n){
    for (int i = 0; i < n; i++){
        printf("%-15s",  students[i].SurName);
        printf("%-15s",  students[i].Name);
        printf("%5d", students[i].Grade);
        printf("%5d", students[i].MPI.Math);
        printf("%5d", students[i].MPI.Phis);
        printf("%5d", students[i].MPI.Inf);
        printf("\n");
    }
}

void data(struct Students_files students[], int n){
    int max = 0, min = 300;
    for (int i = 0; i < n; i++){
        if (students[i].Grade == 1){
            int sum_assessments = students[i].MPI.Math + students[i].MPI.Phis + students[i].MPI.Inf;
            max = sum_assessments > max ? sum_assessments : max;
        }
        if (students[i].Grade == 2){
            int sum_assessments = students[i].MPI.Math + students[i].MPI.Phis + students[i].MPI.Inf;
            min = sum_assessments < min ? sum_assessments : min;
        }
    }

    printf("\n");

    for (int i = 0; i < n; i++){
        int sum_assessments = students[i].MPI.Math + students[i].MPI.Phis + students[i].MPI.Inf;
        if (max == sum_assessments && students[i].Grade == 1){
            printf("%s %s\n", students[i].SurName, students[i].Name);
        }
    }

    printf("\n");

    for (int i = 0; i < n; i++){
        int sum_assessments = students[i].MPI.Math + students[i].MPI.Phis + students[i].MPI.Inf;
        if (min == sum_assessments && students[i].Grade == 2){
            printf("%s %s\n", students[i].SurName, students[i].Name);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Students_files students[n];

    input(students, n);
    output(students, n);
    data(students, n);

    return 0;
}