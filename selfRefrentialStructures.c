#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int roll;
    char name[100];
    struct student *p;
}student;

int main()
{
    student s1={127,"Shreya",NULL};
    student s2={126,"Vaibhav", NULL};
    s1.p=&s2;

    printf("%d %s", s1.p->roll, s1.p->name);

    return 0;
}
