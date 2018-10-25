#include<stdio.h>
#include<string.h>
#define N strlen(g)
char data[28],cs[28],g[]="10001000000100001";
int l,i,j;
void xor(){
    for(j = 1;j < N; j++)
    cs[j] = (( cs[j] == g[j])?'0':'1');
}
void crc(){
    for(i=0;i<N;i++)
        cs[i]=data[i];
    do{
        if(cs[0]=='1')
            xor();
        for(j=0;j<N-1;j++)
            cs[j]=cs[j+1];
        cs[j]=data[i++];
    }while(i<=l+N-1);
}
int main()
{
    printf("\nEnter data : ");
    scanf("%s",data);
    printf("\n----------------------------------------");
    printf("\nGeneratng polynomial : %s",g);
    l=strlen(data);
    for(i=l;i<l+N-1;i++)
        data[i]='0';
    printf("\n----------------------------------------");
    printf("\nModified data is : %s",data);
    printf("\n----------------------------------------");
    crc();
    printf("\nChecksum is : %s",cs);
    for(i=l;i<l+N-1;i++)
        data[i]=cs[i-l];
    printf("\n----------------------------------------");
    printf("\nFinal codeword is : %s",data);
    printf("\n----------------------------------------");
    printf("\nTest error detection 0(yes) 1(no)? : ");
    scanf("%d",&i);
    if(i==0)
    {
        do{
            printf("\nEnter the position where error is to be inserted : ");
            scanf("%d",&i);
        }while(i==0 || i>a+N-1);
        data[i-1]=(data[i-1]=='0')?'1':'0';
        printf("\n----------------------------------------");
        printf("\nErroneous data : %s\n",data);
    }
    crc();
    printf("\nChecksum is : %s",cs);
    for(i=0;(i<N-1) && (cs[i]!='1');i++);
        if(i<N-1)
            printf("\nError detected\n\n");
        else
            printf("\nNo error detected\n\n");
            printf("\n----------------------------------------\n");
        return 0;
}
