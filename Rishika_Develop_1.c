/*Develop a simple datalink layer that performs the flow control using the sliding window protocol

sample output
Enter window size : 3                                                           
Enter number of frames to transmit: 5                                           
Enter 5 frames:                                                                 
1                                                                               
2                                                                               
5                                                                               
8                                                                               
9                                                                               
                                                                                
With sliding window protocol the frames will be sent in the following manner (as
suming no corruption of frames)                                                 
                                                                                
After sending 3 frames at each stage sender waits for acknowledgement sent by th
e receiver                                                                      
                                                                                
1 2 5                                                                           
Acknowledgement of above frames sent is received by sender                      
                                                                                
8 9                                                                             
Acknowledgement of above frames sent is received by sender
*/


#include <stdio.h>
int main()
{
    int window_size, num_frames, i, j;
    printf("Enter window size: ");
    scanf("%d", &window_size);
    printf("Enter number of frames to transmit: ");
    scanf("%d", &num_frames);
    int frames[num_frames];
    printf("Enter %d frames: \n", num_frames);
    for (i = 0; i < num_frames; i++){
        scanf("%d", &frames[i]);
    }
    printf("With sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n\n");
    printf("After sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n\n", window_size);
    for (i = 0; i < num_frames; i += window_size){
        for (j = i; j < i + window_size && j < num_frames; j++){
            printf("%d ", frames[j]);
            }
        printf("\nAcknowledgement of above frames sent is received by sender\n\n");
        }
    return 0;
}