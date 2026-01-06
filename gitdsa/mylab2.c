#include<stdio.h>
char str[50],pat[20],rep[20],res[50];
int c=0,m=0,i=0,j=0,k,flag=0;
void stringmatch(){
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
            i++;
            m++;
            if(pat[i]=='\0'){
                flag=1;
                for(k=0;rep[k]!=0;k++,j++){
                    res[j]=rep[k];
                }
                i=0;
                c=m;
            
        }
    }
        else{
            res[j]=str[c];
            j++;
            c++;
            m=c;
            i=0;
        }
        res[j]='\0';
        
    }
}

void main()
{
    printf("enter the main string:\n");
    gets(str);
    printf("enter the pattern string:\n");
    gets(pat);
    printf("enter the replace string:\n");
    gets(rep);
    printf("enter the string before the pattern matching and replace string:%s",str);
    stringmatch();
    if(flag==1)
        printf("the string after pattern matching and repalcement:%s",res);
    else
        printf("pattern string is not found");
    
}