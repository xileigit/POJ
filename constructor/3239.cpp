#include<cstdio>
const int MAX=310;
int queue[MAX];
int n;
//put POSth row
//pos now input queue
bool isDanger(int pos){
	for(int i=0;i<pos;++i){
		if(queue[i]==queue[pos]||(pos-i)==fabs(queue[pos]-pos[i])){
			return false;
		}
	}
	return true;
}
void getqueue(int m){
	for(int i=0;i<n;++i){
		queue[m]=i;
		if(!isDanger(m)){
			if(m==n-1){
				for(int j=0;j<n;++j){
					printf("%d ",queue[j] );
				}
				
			}
			else{
				getqueue(m+1);
			}
		}
	}
}
int main(){
	
	while(scanf("%d",&n)&&n!=0){
		getqueue(0);
		printf("\n");
	}
	return 0;
}


