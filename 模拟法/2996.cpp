#include<cstdio>
#include <algorithm>
using namespace std;
const int MAX=35;
char chessBoard[MAX][MAX];
void  outBlack(char ch){
	for(int i=17;i>=1;--i){
		for(int j=1;j<=33;++j){
			if(chessBoard[i][j]==ch){
				printf("%c%c%d,",ch,'a'+j/4,i/2 );
			}
		}
	}
}
void  outWhite(char ch){
	for(int i=1;i<=17;++i){
		for(int j=1;j<=33;++j){
			if(chessBoard[i][j]==ch){
				printf("%c%c%d,",ch,'a'+j/4,i/2 );
			}
		}
	}
}
void solveWhite(){
	outWhite('K');
	outWhite('Q');
	outWhite('R');
	outWhite('B');
	outWhite('N');
	int flag=0;
	for(int i=1;i<=17;++i){
		for(int j=1;j<=33;++j){
			if(chessBoard[i][j]=='P'){
				if(flag){
					printf(",%c%d",'a'+j/4,i/2 );
				}
				else{
					printf("%c%d",'a'+j/4,i/2 );
				}
				flag++;
			}
		}
	}
}
void solveBlack(){
	outBlack('k');
    outBlack('q');
    outBlack('r');
    outBlack('b');
    outBlack('n');
    int flag=0;
    for(int i=17;i>=1;i--)
        for(int j=1;j<=33;j++)
        {
            if(chessBoard[i][j]=='p')
            {
               if(flag)
                 printf(",%c%d",'a'+j/4,i/2);
               else printf("%c%d",'a'+j/4,i/2);
               flag++;
            }
        }
}
int main(){
	for(int i=1;i<=17;++i){
		scanf("%s",chessBoard[i]+1);
	} 
	printf("White: ");
	solveWhite();
	printf("Black: ");
	solveBlack();
	return 0;
}


