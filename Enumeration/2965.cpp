#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
int MIN=99999999;
int x[20],y[20];//tmp path
int ansx[20],ansy[20];//final path
char a[10][10];
void change(int i,int j){
	if(a[i][j]=='+'){
		a[i][j]='-';
	}
	else{
		a[i][j]='+';
	}
}
void flip(int n){
	//change Nth and its around chess state
	int row=n/4;
	int col=n%4;
	//flip Nth chess
	for(int i=0;i<4;++i){
        change(row,i);
	}
	for(int i=0;i<4;++i){
        change(i,col);
	}
	change(row,col);

}
//n flip Ntn chess,t flip times ,a chess board state
void dfs(int n,int t){
	int sum=0;//sum chess state
	//judge chess board state
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			if(a[i][j]=='-'){
				sum++;
			}
		}
	}
	//all open
	if(sum==16){
		//update min flip times ,path
		if(t<MIN){
			MIN=t;
			for(int i=0;i<MIN;++i){
				ansx[i]=x[i];
				ansy[i]=y[i];
			}
		}
		return;
	}
	//all chess flip over
	if(n==16){
		return;
	}
	//do not flip Nth chess
	dfs(n+1,t);

	//flip Nth chess
	flip(n);
	//update tmp path
	x[t]=n/4;
	y[t]=n%4;

	dfs(n+1,t+1);
	flip(n);
}
int main(){

	for(int i=0;i<4;++i){
		scanf("%s",a[i]);
	}
	dfs(0,0);
	printf("%d\n", MIN);
	for(int i=0;i<MIN;++i){
		printf("%d %d\n", ansx[i]+1,ansy[i]+1);
	}
	return 0;
}
