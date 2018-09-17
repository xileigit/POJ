#include<cstdio>
#include<cstring>
const int MAX=110;
struct robot{
	int x,y;//pos
	int dir;//direction
}Robot[MAX];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int board[MAX][MAX];//robot ,0 empty
int A,B;//A width B height
//s robot ,t repeat time
//return false don't crash
bool forward(int s,int t){
	int x,y,dir;
	x=Robot[s].x;
	y=Robot[s].y;
	dir=Robot[s].dir;
	//leave original pos
	board[x][y]=0;
	//move t step
	for(int i=0;i<t;++i){
		int nx=x+dx[dir];
		int ny=y+dy[dir];
		x=nx;
		y=ny;
		//crash wall
		if(nx<1||nx>A||ny<1||ny>B){
			printf("Robot %d crashes into the wall\n",s );
			return true;
		}
		//crash robot
		if(board[nx][ny]!=0){
			printf("Robot %d crashes into robot %d\n",s ,board[nx][ny]);
			return true;
		}
	}
	//update final pos
	Robot[s].x=x;
	Robot[s].y=y;
	board[x][y]=s;
	return false;
}
bool action(int s,char instruct,int t){
	switch(instruct){
		case 'F': return forward(s,t);
		case 'L': Robot[s].dir=(Robot[s].dir-t%4+4)%4;break;
		case 'R': Robot[s].dir=(Robot[s].dir+t%4+4)%4;break;
	}
	return false;
}
int main(){
	int k;
	scanf("%d",&k);
	while(k--){
		memset(board,0,sizeof(int)*MAX*MAX);
		scanf("%d%d",&A,&B);
		int n,m;
		scanf("%d%d",&n,&m);
		//input robot pos ,direction
		for(int i=0;i<n;++i){
			int x,y;
			char dir;
			scanf("%d%d %c",&x,&y,&dir);
			board[x][y]=i+1;
			Robot[i+1].x=x;
			Robot[i+1].y=y;
			switch(dir){
				case 'W':Robot[i+1].dir=0;break;
				case 'N':Robot[i+1].dir=1;break;
				case 'E':Robot[i+1].dir=2;break;
				case 'S':Robot[i+1].dir=3;break;
				default:Robot[i+1].dir=-1;
			}
		}
		bool notCrash=false;
		//input instruction
		for(int i=0;i<m;++i){
			int r,t;//r robot index,t instruct repeat time
			char instruct;
			scanf("%d %c%d",&r,&instruct,&t);
			if(!notCrash){
				notCrash=action(r,instruct,t);
			}
		}
		//notcrash
		if(!notCrash){
			printf("OK\n");
		}
	}
	return 0;
}


