#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int s[MAX];
int top=-1;
void push(int item);
int pop();
void palindrome();
void display();
void main(){
    int item,choice;
    while(1){
        printf("\n\n\n----MENU----\n\n\n");
        printf("=>1.push the element to the stack and overflow demo");
        printf("=>2.pop the element from the stack and underflow  demo");
        printf("=>3. palindrome demo");
        printf("=>4. display");
        printf("=>5.exit");
        printf("enter the choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter the element to be pushed:\n");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            item =pop();
            if(item !=-1){
                printf("element to be popped is :%d",item);
            }
        case 3:
            palindrome();
            break;
        case 4 :
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("please enter valid choice");
            break;
        }
    }
}
void push(int item){
    if(top==MAX-1){
        printf("------stack overflow-----");
        return;
    }
    top=top+1;
    s[top]=item;
    

}
int pop(){
    int item;
    if(top==-1){
        printf("-------stack underflow----");
        return -1;
    }
    item=s[top];
    top=top-1;
    return item;
    
}
void display(){
    int i;
    if(top==-1){
        printf("------stack empty-----");
        return ;
    }
    printf("stack elements are:");
    for(i=top;i>=0;i--){
        printf("|%d|",s[i]);
    }
}
void palindrome(){
    int flag=1,i;
    printf("stack content");
    for(i=top;i>=0;i--){
        printf("|%d|",s[i]);
        
    }
    printf("reverse stack content are:");
    for(i=0;i<=top;i++){
        printf("|%d|",s[i]);
    }
    for(i=0;i<=top/2;i++){
        if (s[i]!=s[top-i]){
            flag=0;
            break;

        }
        if(flag==1){
            printf("it is a palindrome number");

        }
        else{
            printf("it is not a palindrome number");
        }
    }


    
}
