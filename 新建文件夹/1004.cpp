#include<cstdio>
int main(){
		double sum=0,s;
		for(int i=0;i<12;++i){
			scanf("%lf",&s);
			sum+=s;
		}
		printf("$%.2f\n",sum/12 );
	
	return 0;
}
