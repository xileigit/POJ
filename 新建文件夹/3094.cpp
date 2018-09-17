#include<cstdio>
#include<cstring>
const int MAX=300;
char str[MAX];
int main(){
	while(gets(str+1)){
		if(str[1]=='#'){
			break;
		}
		int len=strlen(str+1);
		int sum=0;
		for(int i=1;i<=len;++i){
			if(str[i]>='A'&&str[i]<='Z'){
				sum+=i*(str[i]-'A'+1);
			}
		}
		printf("%d\n",sum );
	}

	return 0;
}
