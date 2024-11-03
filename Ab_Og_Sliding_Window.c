// Online C compiler to run C program online
#include <stdio.h>
//Sliding window.

int main() {
    
    int n,frames[30];
    
    printf("Enter the window size: ");
    scanf("%d",&n);
    
    printf("Enter the no of frames to be transmitted: ");
    int size;
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        scanf("%d",&frames[i]);
    }
    
    for(int i=1;i<=size;i++){
        if(i%n==0){//IF you reach the window limit.
            printf("%d ",frames[i]);//that last frame 
            //whose ack was received by the sender.
            printf("\nThe ack of all the above frames is received by the sender\n");
        }else{
            printf("%d ",frames[i]);
        }
    }
    //if the no of frames is not divisible by the window size
    //the if cond won't be satisfied
    //then the below will be executed.
    if(size%n){
        printf("\nThe ack of all the above frames is received by the sender\n");
    }
    printf("All the frames sent successfully to the receiver.");
    

    return 0;
}