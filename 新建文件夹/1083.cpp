#include<cstdio>
#include<cstring>
const int MAX=210;
struct node{
	int start;
	int end;
}Node[MAX];

int num[410];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%d%d",&Node[i].start,&Node[i].end);
			if(Node[i].start>Node[i].end){
				int tmp=Node[i].start;
				Node[i].start=Node[i].end;
				Node[i].end=tmp;
			}
			if(Node[i].start%2==0){
				Node[i].start--;
			}
			if(Node[i].end%2){
				Node[i].end++;
			}
			for(int j=Node[i].start;j<=Node[i].end;++j){
                    num[j]++;

			}
		}
		int cnt=0;
		for(int i=1;i<=400;++i){
			if(num[i]>cnt){
				cnt=num[i];
			}
		}
		printf("%d\n",cnt*10 );
	}

	return 0;
}
