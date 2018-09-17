#include<cstdio>
#include<cmath>
const double PI=acos(-1.0);
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		double x,y;
		scanf("%lf%lf",&x,&y);
		int year=0;
		double area=PI*(x*x+y*y)/2;
		while(area>0){
			area-=50;
			year++;
		}
		printf("Property %d: This property will begin eroding in year %d.\n",i+1, year);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
