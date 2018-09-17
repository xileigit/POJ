#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
using  namespace std;
const int MAX=110;
const char ENUM_CODE=0x1f;
const char P_MASK=0x01;
const char Q_MASK=0x02;
const char R_MASK=0x04;
const char S_MASK=0x08;
const char T_MASK=0x10;
#define _K(w, x) ((w) && (x))		//	K --> and:  w && x
#define _A(w, x) ((w) || (x))		//	A --> or:  w || x
#define _N(w) (!(w))				//	N --> not :  !w
#define _C(w, x) ((!(w)) || (x))	//	C --> implies :  (!w) || x
#define _E(w, x) ((w) == (x))		//	E --> equals :  w == x
char toVAl(char ch,char code){
	char val=2;
	switch(ch){
		case 'p': val=(code&P_MASK)==0?0:1;  break;
		case 'q': val=(code&Q_MASK)==0?0:1;  break;
		case 'r': val=(code&R_MASK)==0?0:1; break;
		case 's': val=(code&S_MASK)==0?0:1; break;
		case 't': val=(code&T_MASK)==0?0:1; break;
		default:  val=2;
	}
	return val;
}
bool isTrue(char*wff,char code){
    stack<char>s;
	for(int i=strlen(wff)-1;i>=0;--i){
		char ch=wff[i];
		char val=toVAl(ch,code);
		//variable
		if(val!=2){
			s.push(val);
		}
		else{
			if(ch=='N'){
				val=s.top();
				s.pop();
				s.push(_N(val));
			}
			else{
				char v1=s.top();
				s.pop();
				char v2=s.top();
				s.pop();
				switch(ch){
					case 'K':s.push(_K(v1,v2)); break;
					case 'A':s.push(_A(v1,v2)); break;
					case 'C':s.push(_C(v1,v2)); break;
					case 'E': s.push(_E(v1,v2));
				}
			}
		}
	}
	return (s.size()==1&&s.top()==1);
}
int main(){
    char wff[MAX];
	while(scanf("%s",wff)&&wff[0]!='0'){
		bool isTautology = true;
		for(char code=0;code<=ENUM_CODE;code++){
			isTautology&=isTrue(wff,code);
			if(!isTautology){
				break;
			}
		}
		if(isTautology){
			printf("tautology\n");
		}
		else{
			printf("not\n");
		}
	}
	return 0;
}
