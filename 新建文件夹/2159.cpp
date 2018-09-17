#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
const int MAX=110;
char src[MAX];
char encrypt[MAX];
int sfre[26];
int efre[26];
int n;

int main(){
	gets(encrypt);
	gets(src);
	n=strlen(src);
	memset(efre,0,sizeof(efre));
	memset(sfre,0,sizeof(sfre));
	for(int i=0;i<n;++i){
		efre[int(encrypt[i]-'A')]++;
		sfre[int(src[i]-'A')]++;
	}
    sort(efre,efre+26);
    sort(sfre,sfre+26);
    int i;
    for(i=0;i<26;++i){
    	if(sfre[i]!=efre[i]){
    		break;
    	}
    }
    if(i==26){
    	printf("NO\n");
    }
    else{
    	printf("YES\n");
    }
	return 0;
}
