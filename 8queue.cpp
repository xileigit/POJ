#include<cstdio>
#include<cmath>
const int MAX=310;
int queue[MAX];
int n;
int cnt;
//put POSth row
//pos now input queue
bool isDanger(int pos){
	for(int i=0;i<pos;++i){
		if(queue[i]==queue[pos]||(pos-i)==fabs(queue[pos]-queue[i])){
			return true;
		}
	}
	return false;
}
void getqueue(int m){
	for(int i=0;i<n;++i){
		queue[m]=i;
		if(!isDanger(m)){
			if(m==n-1){
				cnt++;
				for(int j=0;j<n;++j){
					printf("%d ",queue[j] );
				}
				return;
			}
			else{
				getqueue(m+1);
			}
		}
	}
}

int main(){
	while(scanf("%d",&n)&&n!=0){
        cnt=0;
		getqueue(0);
		printf("\n cnt = %d\n",cnt);
	}
	return 0;
}


