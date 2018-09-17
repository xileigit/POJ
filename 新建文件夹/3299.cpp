#include<cstdio>
#include <cmath>
using namespace std;
int main(){
	double t,d,h;
	bool ft,fd,fh;
	while(true){
		char op;
		ft=false,fd=false,fh=false;
		scanf("%c",&op);
		if(op=='E'){
			break;
		}
		else if(op=='T'){
			scanf("%lf",&t);
			ft=true;
		}
		else if(op=='D'){
			scanf("%lf",&d);
			fd=true;
		}
		else if(op=='H'){
			scanf("%lf",&h);
			fh=true;
		}
		scanf(" %c",&op);
		if(op=='T'){
			scanf("%lf",&t);
			ft=true;
		}
		else if(op=='D'){
			scanf("%lf",&d);
			fd=true;
		}
		else if(op=='H'){
			scanf("%lf",&h);
			fh=true;
		}
		getchar();
		if(ft&&fd){
			h=t+(0.5555)*(6.11*exp(5417.7530* ((1/273.16) - (1/(d+273.16))))-10.0);
		}
		else if(fh&&fd){
			t=h-(0.5555)*(6.11*exp(5417.7530* ((1/273.16) - (1/(d+273.16))))-10.0);
		}
		else if(ft&&fh){
			d=1/((1/273.16)-log(((h-t)/(0.5555)+10.0)/(6.11))/(5417.7530))-273.16;
		}

		printf("T %.1f D %.1f H %.1f\n", t,d,h);
	}
	return 0;
}
