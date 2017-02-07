#include<stdio.h>
#include<stdlib.h>
char const* myfunction(){
	char const* b = "false";
	return b;
}
void main(){
	char const *hyp;
	
	hyp=myfunction();
	printf("+++INFO: hyp= %s\n",hyp);
	printf("%d\n",hyp=="false");
	if (hyp!="false")
		{printf("+++INFO: hyp= %s\n",hyp);}
	else{printf("+++INFO: false");}
}


