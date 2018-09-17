#include<cstdio>
#include <algorithm>
using namespace std;
const int MAX=15;
bool isVisit[MAX][MAX];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int A,B;//A width B height
char board[MAX][MAX];
int dirToInt(char dir){
	switch(dir){
		case 'N':return 0;
		case 'E':return 1;
		case 'S':return 2;
		case 'W':return 3;
		default :return -1;
    }
}
int main(){
	int row,col,s;
	while(scanf("%d%d%d",&A,&B,&s)){
		row=A,col=B;
		if(row==0){
			break;
		}
		getchar();
		fill(isVisit[0],isVisit[0]+MAX*MAX,false);
		for(int i=0;i<row;++i){
			for(int j=0;j<col;++j){
				scanf("%c",&board[i][j]);
			}
			getchar();
		}
		int x=0,y=s-1;
		isVisit[x][y]=true;
		int step=0;
		while(true){
			step++;
			int dir=dirToInt(board[x][y]);
			int nx=x+dx[dir];
			int ny=y+dy[dir];
			x=nx;
			y=ny;
			if(nx<0||nx>=A||ny<0||ny>=B){
				printf("%d step(s) to exit\n",step);
				break;
			}
			if(isVisit[nx][ny]){
				int loopStep=0;
				isVisit[nx][ny]=false;
				while(true){
					loopStep++;
					dir=dirToInt(board[nx][ny]);
				    nx=nx+dx[dir];
				    ny=ny+dy[dir];
				    if(isVisit[nx][ny]==false){
				    	break;
				    }
				    isVisit[nx][ny]=false;
				}
				printf("%d step(s) before a loop of %d step(s)\n",step-loopStep, loopStep);
				break;
			}
			isVisit[nx][ny]=true;
		}
	}
	return 0;
}


