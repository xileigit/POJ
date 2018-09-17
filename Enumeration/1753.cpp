#include<cstdio>
#include<cstring>
int MIN=99999999;
int flag;
void change(char a[10][10],int i,int j){
	if(a[i][j]=='b'){
		a[i][j]='w';
	}
	else{
		a[i][j]='b';
	}
}
//n flip Ntn chess,t flip times ,a chess board state
void dfs(int n,int t,char a[10][10]){
	int row,col,sum=0;//sum chess state
	char b[10][10];
	//judge chess board state
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			if(a[i][j]=='b'){
				sum++;
			}
		}
	}
	//all black or white
	if(sum==0||sum==16){
		//update min flip times
		if(t<MIN){
			MIN=t;
			flag=1;
		}
		return;
	}
	//all chess flip over
	if(n==16){
		return;
	}

	for(int i=0;i<4;++i){
		strcpy(b[i],a[i]);
	}
	//do not flip Nth chess
	dfs(n+1,t,b);
	//flip Nth chess
	//change Nth and its around chess state
	row=n/4;
	col=n%4;
	change(b,row,col);
	if(row>=1){
		change(b,row-1,col);
	}
	if(row<=2){
		change(b,row+1,col);
	}
	if(col>=1){
		change(b,row,col-1);
	}
	if(col<=2){
		change(b,row,col+1);
	}
	dfs(n+1,t+1,b);
}
int main(){
	flag=0;
	char a[10][10];
	for(int i=0;i<4;++i){
		scanf("%s",a[i]);
	}
	dfs(0,0,a);
	if(flag==1){
		printf("%d\n", MIN);
	}
	else{
		printf("Impossible\n");
	}
	return 0;
}
