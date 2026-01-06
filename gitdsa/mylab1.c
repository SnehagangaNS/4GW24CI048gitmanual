#include<stdio.h>
#include<stdlib.h>
struct Day{
    char *dayName;
    char *activity;
    int date;
};
void create(struct Day *day){
    day->dayName=(char *)malloc(sizeof(char)*20);
    day->activity=(char *)malloc(sizeof(char)*50);
    printf("enter the dayName:\n");
    scanf("%s",day->dayName);
    printf("enter the date:\n");
    scanf("%d", &day->date);
    printf("enter the activity for the day:\n");
    scanf("%s",day->activity);
}
void read(struct Day *calendar,int size){

    for(int i=0;i<size;i++){
        printf("enter the details%d:\n",i+1);
        create(&calendar[i]);
    }

}
void display(struct Day *calendar,int size)
{
    printf("weeek's activity details:\n");
    for(int i=0;i<size;i++){
        printf("DAY %d:\n",i+1);
        printf("DAYNAME :%s\n",calendar[i].dayName);
        printf("DATE:%d\n",calendar[i].date);
        printf("ACTIVITY:%s\n",calendar[i].activity);
        printf("\n");
    }
    
}
void freeMemory(struct Day *calendar ,int size){
    for(int i=0;i<size;i++){
        free(calendar[i].dayName);
        free(calendar[i].activity);
    }
}
int main(){
    int size;
    printf("enter the number of days in a week :\n");
    scanf("%d",&size);
    struct Day *calendar=(struct Day*)malloc(sizeof(struct Day)* size);
    if(calendar== NULL){
        printf("exiting the program as the inputs as invalid\n");
        return 1;
    }
    
    read(calendar, size);
    display(calendar,size);
    freeMemory(calendar,size);
    free(calendar);
    return 0;


}