#include<stdio.h>
#include<string.h>

struct Employee{
int empno;
char e_name[50];
char designation[50];
int basicpay,hra,pa;
int netpay;
};

int Calc_Netpay(struct Employee e){
    int netpay=e.basicpay+e.hra+e.pa;
    //printf("The netpay is: %d \n",e.netpay);
    return netpay;
}

void Check_Manager(struct Employee e){
    if (strcmp(e.designation,"Manager")==0){
            printf("Manager details: \n %d \n %s \n %s \n %d \n %d \n %d \n %d \n", e.empno, e.e_name, e.designation, e.basicpay, e.hra, e.pa, e.netpay );
        }
}

void Check_netpay(struct Employee e){
     if (e.netpay>200000){
            printf("Employee details with high salary: \n %d \n %s \n %s \n %d \n %d \n %d \n %d \n",e.empno, e.e_name, e.designation, e.basicpay, e.hra, e.pa, e.netpay );
        }
}

void Check_name(struct Employee e){
     if (e.e_name[0]=='A'){
            printf("Employee details whose name starts with A: \n %d \n %s \n %s \n %d \n %d \n %d \n %d \n",e.empno, e.e_name, e.designation, e.basicpay, e.hra, e.pa, e.netpay );
        }
}

void main(){
    struct Employee e[5];
    for (int i=0;i<3;i++){
        scanf("%d %s %s %d %d %d",&e[i].empno, e[i].e_name, e[i].designation, &e[i].basicpay, &e[i].hra, &e[i].pa );
        e[i].netpay=Calc_Netpay(e[i]);
        printf("The netpay is: %d \n",e[i].netpay);
    }

    for (int i=0;i<3;i++){
        Check_Manager(e[i]);
    }

    for (int i=0;i<3;i++){
       Check_netpay(e[i]);
    }

    for (int i=0;i<3;i++){
       Check_name(e[i]);
    }

}
