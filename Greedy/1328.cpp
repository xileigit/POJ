#include<cstdio>
#include<cmath>
#include <algorithm>
using namespace std;
const int MAX=1010;
//Projection doubleerval of island on the x-axis
struct interval{
	double left,right;
}Interval[MAX];
bool cmp(interval a,interval b){
	return a.left < b.left;
}
int main(){
	int n,d;
	int t=0;
	bool flag;
	while(scanf("%d%d",&n,&d)){
		if(n==0){
			break;
		}
		 t++;
		 flag = true;
		//input island position
		for(int i=0;i<n;++i){
			double x,y;
			scanf("%lf%lf",&x,&y);
			if(y>d){
				flag=false;
			}

				double  offSet = sqrt(double(d * d - y * y));
				Interval[i].left = x - offSet;
				Interval[i].right = x + offSet;

		}
		sort(Interval,Interval+n,cmp);
		double lastRight=Interval[0].right;
		int radia=1;
		for(int i=1;i<n;++i){
			if(Interval[i].left>lastRight){
				radia++;
				lastRight=Interval[i].right;
			}
			else if(Interval[i].right<lastRight){
				lastRight=Interval[i].right;
			}
		}
		if(flag){
			printf("Case %d: %d\n",t,radia );
		}
		else{
			printf("Case %d: -1\n",t );
		}
	}

	return 0;
}
