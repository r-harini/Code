#include<stdio.h>
#include<string.h>

struct Student{
    int regno;
    char name [50];
    int n;
    struct coursereg{
    char subcode[10];
    char subname[50];
    char slot[50];
    int cred;
    }cr[10];
}s[10];

void List_Students(struct Student s){
    printf("%d\n%s \n ", s.regno, s.name);
}

void main(){
    for (int i=0;i<3;i++){     
        printf("Enter the student details:");
        scanf( "%d %s %d", &s[i].regno, s[i].name, &s[i].n);
        for (int j=0;j<s[i].n;j++){
            printf(" Enter the subcode, subname, slot, credits:");
            scanf ("%s %s %s %d", s[i].cr[j].subcode, s[i].cr[j].subname, s[i].cr[j].slot, &s[i].cr[j].cred);
        }
    }
    printf("List of students\n");

    for (int i=0;i<3;i++){
        List_Students(s[i]);
        //printf("%d\n%s \n ", s[i].regno, s[i].name);// s[i].cr.subcode, s[i].cr.subname, s[i].cr.slot, s[i].cr.cred);
    }

    char slot[10];
    printf("Enter the slot to be searched:");
    scanf("%s",slot);

    for (int i=0;i<3;i++){
        for (int j=0;j<s[i].n;j++){
            if (strcmp(s[i].cr[j].slot,slot)==0){
                printf("%d\n%s \n", s[i].regno, s[i].name); //s[i].cr.subcode, s[i].cr.subname, s[i].cr.slot, s[i].cr.cred);
            }
        }
    }

    int regno;
    printf("Enter the regno:");
    scanf("%d",&regno);
    
    int cred=0,num;

    for (int i=0;i<3;i++){
        if (s[i].regno==regno){
            
            for (int j=0;j<s[i].n;j++){
                cred+=s[i].cr[j].cred;
            }
            printf("%d\n%s \n%d \n", s[i].regno, s[i].name, cred);
        }
    }
}

