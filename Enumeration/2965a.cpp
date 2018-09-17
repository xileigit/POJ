#include<iostream>
#include<cstdio>
using namespace std;
int a[4][4]={0};
int main()
{
    char str;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>str;

            //if close flip all chess on Irow Jcol ,[i,j ]change 7 time,
            //other change 4 times result as same as unchanged 
            if(str=='+')
            {
                for(int t=0;t<4;t++)
                {
                    a[i][t]^=1;//change Irow
                    a[t][j]^=1;//change Jcol
                }
                a[i][j]^=1;//change [i,j]
            }
        }
    }

    int sum=0;//change times
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(a[i][j])
                sum++;
    printf("%d\n",sum);

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(a[i][j])
                printf("%d %d\n",i+1,j+1);
        }
    }
    return 0;
}
