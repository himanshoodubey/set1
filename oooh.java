
#include <stdio.h>

int main()
{
    int n1,n2,i;
    char s;
    
    for(int i=1;i<4;i++){
        scanf("%d%c%d",&n1,&s,&n2);
    
    if(s=='/'){
        printf("%d\n",n1/n2);
    }
    else{
        printf("%d\n",n1%n2);
    }
}
    return 0;
}
