#include<cstdio>
int main(){
	double len;
	while(scanf("%lf",&len)&&len!=0.0){
		double i=2;
		for(double sum=0;sum<len;++i){
			sum+=1/i;
		}
		printf("%d card(s)\n",int(i-2) );
	}
	return 0;
}
