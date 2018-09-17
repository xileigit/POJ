#include<cstdio>
int main(){
	int p,e,i,d;
	int cas=0;
	while(scanf("%d%d%d%d",&p,&e,&i,&d)&&!(p==-1&&e==-1&&i==-1&&d==-1)){
		cas++;

		int k=d+1;
		while((k-p)%23){
			k++;
		}
		while((k-e)%28){
			k+=23;
		}
		while((k-i)%33){
			k+=23*28;
		}

		printf("Case %d: the next triple peak occurs in %d days.\n", cas,k-d);
	}
	return 0;
}
