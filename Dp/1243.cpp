#include<cstdio>
#include<cmath>
const int MAX=50;
int dp[MAX][MAX];//dp[G][L] max n
void init(){
	//G<---i,L<---j
	for(int i=0;i<=30;++i){
		for(int j=0;j<=i;++j){
			if(j==0){
				dp[i][j]=i;
			}
			else if(i==j){
				dp[i][j]=int(pow(2,double(i)))-1;
			}
			//j<i
			else{
				dp[i][j]=dp[i-1][j-1] + dp[i-1][j] + 1;
			}

		}
	}
}
int main(){
	int G,L;
	int id=0;
	init();
	while(scanf("%d%d",&G,&L)&&G!=0){

		printf("Case %d: %d\n", ++id,dp[G][L]);
	}
	return 0;
}
