#include <stdio.h>
#define MAX 20
int main() {
    int c,len=0,cnt[MAX]={0};
    while((c=getchar())!=EOF){
        if(c==' '||c=='\n'||c=='\t'){ if(len){ cnt[len<MAX?len:MAX-1]++; len=0; } }
        else len++;
    }
    if(len) cnt[len<MAX?len:MAX-1]++;
    for(int i=1;i<MAX;i++){
        printf("%2d: ",i);
        for(int j=0;j<cnt[i];j++) putchar('#');
        puts("");
    }
}
