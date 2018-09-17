#include<cstdio>
#include<cmath>
const int MAX=100;

int p[MAX];
char str[MAX];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&p[i]);
		}
		//make s
		int k=0;
		for(int i=1;i<=n;++i){
			int m=p[i]-p[i-1];
			while(m--){
				str[k++]='(';
			}
			str[k++]=')';
		}
		//make w
		int ans,j,flag;
		int mark=0;
		for(int i=0;i<k;++i){
			ans=0;
			flag=1;
			if(str[i]==')'){
				j=i-1;
				while(flag&&j>=0){
					if(str[j]=='('){
						flag--;
						ans++;
					}
					else if(str[j]==')'){
						flag++;
					}
					j--;
				}
				if(!mark){
					mark=1;
				}
				else{
					printf(" ");
				}
				printf("%d",ans );

			}
		}
		printf("\n");
	}
   
	return 0;
}


