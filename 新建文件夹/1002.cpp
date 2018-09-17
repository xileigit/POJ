#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
const int MAX=100010;
map<string, int> telMap;
int main(){
	int t1=2,t2=0;
	int a[26];
	for(int i=0;i<26;++i){
		if(i==16||i==25){
			continue;
		}
		else{
			a[i]=t1;
			t2++;
			if(t2==3){
				t1++;
				t2=0;
				continue;
			}
		}
	}
	int n;
	scanf("%d",&n);
	string str,num="";
	for(int i=0;i<n;++i){
		str=num="";
		cin>>str;
		int len=str.length();
		for(int j=0;j<len;++j){
			if('-'==str[j]){
				continue;
			}
			else{
				if(str[j]>='A'&&str[j]<='Z'){
					int index=str[j]-'A';
					num+=a[index]+'0';
				}
				else{
					num+=str[j];
				}
			}
		}
		num.insert(3,"-");
		telMap[num]++;
	}
	int resultFlag = 0;
	for(map<string, int>::iterator it=telMap.begin();it!=telMap.end();++it){
		pair<string,int>p=*it;
		if(p.second>1){
			cout<<p.first<<" "<<p.second<<endl;
			resultFlag=1;
		}

	}
	if(resultFlag==0){
		cout << "No duplicates." << endl;
	}
	return 0;
}
