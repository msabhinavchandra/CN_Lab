#include<stdio.h>
int main(){
    int size,frames;
    printf("Enter window size : ");
    scanf("%d",&size);
    printf("Enter number of frames to transmit: ");
    scanf("%d",&frames);
    printf("Enter %d frames:\n",frames);

    int arr[frames];
    for (int i = 0; i < frames; i++){
        scanf("%d",&arr[i]);
    }

    printf("With sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n");
    printf("After sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n",size);

    int n = frames/size;
    int temp=0;
    if(frames%size!=0){
        n=n+1;
    }
    for (int i = 0; i < n; i++){
        for (int j = temp; j < temp+size; j++){
            if(j<frames){
                printf("%d ",arr[j]);
            }
        }
        printf("\nAcknowledgement of above frames sent is received by sender\n");
        temp= temp+size;
    }
    return 0;
}
