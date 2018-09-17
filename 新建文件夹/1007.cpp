#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAX=110;
struct dna{
	string content;
	int time;
}DNA[MAX];
bool cmp(dna a,dna b){
	return a.time<b.time;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>DNA[i].content;
		for(int j=0;j<n;++j){
			for(int k=j+1;k<n;++k){
				if(DNA[i].content[j]>DNA[i].content[k]){
					DNA[i].time++;
				}
			}
		}
	}
	stable_sort(DNA,DNA+m,cmp);
	for(int i=0;i<m;++i){
		cout<<DNA[i].content<<endl;
	}
	return 0;
}
