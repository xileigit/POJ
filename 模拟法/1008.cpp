#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=110;
char HaabM[20][20]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu"," uayet"};
char Tzolkin[20][25]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",n);
	for(int i=0;i<n;++i){
		int year,day;
		char month[100];
		scanf("%d. %s %d",&day,month,&year);
		int  k;
		for(k=0;k<19;++k){
			if(!strcmp(month,HaabM[k])){
				break;
			}
		}
		if(k==19){
			k=0;
		}
		int days=year*365+20*k+day;
		year=days/260;
		k=days%20;
		day=days%13+1;
		printf("%d %s %d\n",day,Tzolkin[k] ,year);
	}
	return 0;
}
