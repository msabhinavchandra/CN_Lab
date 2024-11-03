// Online C compiler to run C program online
#include <stdio.h>
//Go back N ARQ.
int main() {
    
    int windowSize;
    printf("Enter the window size: ");
    scanf("%d",&windowSize);
    int sent=0;
    int ack;
    while(1){
        for(int i=0;i<windowSize;i++){
            printf("Frame sent %d\n",sent);
            sent++;
            if(sent==windowSize){
                break;
            }
        }
        printf("Acknowledge frame received: ");
        scanf("%d",&ack);
        
        if(ack==windowSize){
            printf("All the Frames Sent Successfully");
            break;
        }else{
            sent=ack;
        }
    }

    return 0;
}