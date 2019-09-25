struct D_company{
    char Name[50];
    int regno;
    char cname[50];
    int pckg;
}d[50];

struct L_company{
    char Name[50];
    int regno;
    char cname[50];
    int pckg;
}l[50];

int n=0,m=0; //n is the counter for dream company and m is the counter for level1 company

algorithm add(struct company* c, int k){
    printf ("Enter no of students:");
    scanf("%d",&k);
    for (int i=0;i<k;i++){
    printf("Enter the name, regno, company name and annual package:");
    scanf("%s", c[i].name);
    scanf("%d", &c[i].regno);
    scanf("%s", c[i].cname);
    scanf("%d", &c[i].pckg);
    }
}

Algorithm merge( ){
	K=0;
	For i in range (0,n) loop{
		C[k].name=d[i].name;
		C[k].regno=d[i].regno;
		C[k].company=d[i].company;
		K=k+1;
	For i in range (0,m) loop{
		R=l[i].regno;
		X=0;
		For w in range(0,k) loop{
			If (c[j].regno==r){
                Char pref[50];
			    Printf(“Enter student preference:”);
			    scanf("%s", pref);
                if (strcmp(l[i].cname, pref)==0){
                    
                }
				//X=1;
			}
		}
		If X=1{
			Char pref[50];
			Printf(“Enter student preference:”);
			scanf("%s", pref);

		}
