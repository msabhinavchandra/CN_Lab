// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>

void xor_op(char *dividend,char *divisor){
    int divisor_len=strlen(divisor);
    
    //now for this you should loop divisor_len no of times because
    //u need to solve it for each and every element in the string.
    
    for(int i=0;i<divisor_len;i++){
        dividend[i]=(dividend[i]==divisor[i]) ? '0' : '1';
    }
    
}

void Crc_encode_Sender(char *data,char *divisor,char *rem){
    int data_len=strlen(data);
    int divisor_len=strlen(divisor);
    // data_len + padded lenght(divisor-1)
    int tempLen=data_len+divisor_len-1;
    //initializing the temp to pad the zeroes
    char temp[tempLen],FinalDividend[tempLen];
    
    strcpy(temp,data);//copy data into it because i don't want to 
    //disturb the given data.
    //Pad zeroes at the end of the temp
    for(int i=data_len;i<tempLen;i++){
        temp[i]='0';
    }//Padded 0s
    temp[tempLen]='\0';//Setting the end of string for it.
    

    //perform the division operation, loop data_len -1 no of times.
    for(int i=0;i<=data_len-1;i++){
        if(temp[i]=='1'){
            printf("dividend %s and divisor %s",temp+i,divisor);
            xor_op(temp+i,divisor);
        }
    }
    
    strncpy(rem,temp+data_len,divisor_len-1);
    rem[divisor_len-1]='0';//setting up the end of string.
    strcpy(FinalDividend,data);
    FinalDividend[tempLen]='\0';
    //Now we have the remainder
    //replace the last divisor_len-1 no if digits with this remainder.
    for(int i=data_len;i<tempLen;i++){
        FinalDividend[i]=rem[i-data_len];
        printf("%c",rem[i-data_len]);printf("\n");
    }//Padded 0s
    
    //Now temp carries that proper modified dividend
    
    printf("Modified Dividend After Division Operation: %s",FinalDividend);
    printf("\nData that is being sent: %s\n", FinalDividend);

    
}

void Crc_encode_Receiver(char *data_recv,char *divisor,char *rem_Check,int data_len){
    int divisor_len=strlen(divisor);
    
    //perform the division operation, loop data_len -1 no of times.
    for(int i=0;i<=data_len-1;i++){
        if(data_recv[i]==1){
            xor_op(data_recv+i,divisor);
        }
    }
    
    strncpy(rem_Check,data_recv+data_len,divisor_len-1);
    rem_Check[divisor_len-1]='0';//setting up the end of string.
    
    
    
}

int main() {
    char data[100],rem[100],rem_Check[100],divisor[100],data_recv[100];
    
    printf("Enter the data to be transmitted :");
    scanf("%s",data);
    
    printf("Enter the divisor :");
    scanf("%s",divisor);
    
    //Sender CRC
    Crc_encode_Sender(data,divisor,rem);
    
    printf("Enter the data that is reveived: ");
    scanf("%s",data_recv);
    
    Crc_encode_Receiver(data_recv,divisor,rem_Check,strlen(data));
    
    if(strchr(rem_Check,'1')==NULL){//1 is not there.
        printf("No Error detected\n");
    }else{
        printf("Error is detected");
    }
    
    

    return 0;
}