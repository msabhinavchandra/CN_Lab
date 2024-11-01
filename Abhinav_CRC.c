/*Write a program to compute CRC code for the polynomials

sample
input=11100011
11001
11100011
output=Enter data to be transmitted:
Enter the Generating polynomial:
Data padded with n-1 zeros : 111000110000CRC or Check value is : 0000Final data
to be sent : 111000110000Enter the received data:
Data received: 11100011No error detected

*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void xor(char *dividend, char *divisor, int divisor_len){
printf("XOR Func Called for dividend %s and divisor %s and dividor length %d\n",dividend,divisor,divisor_len);
  for (int i = 0; i < divisor_len; i++){
    dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
  }

}

void crc_encode(char *data, char *polynomial, char *remainder, bool flag){
  int data_len = strlen(data);
  int poly_len = strlen(polynomial);

  char temp[data_len + poly_len - 1];
  strcpy(temp, data);

  // Pad the data with n-1 zeros
  for (int i = data_len; i < data_len + poly_len - 1; i++){
    temp[i] = '0';
  }
  temp[data_len + poly_len - 1] = '\0';

  if (flag){
    printf("Data padded with n-1 zeros: %s\n", temp);
  }

  // Perform the division process
  for (int i = 0; i <= data_len - 1; i++){
    if (temp[i] == '1'){
      xor(temp + i, polynomial, poly_len);
    }
  }

  strncpy(remainder, temp + data_len, poly_len - 1);//divisor_length -1.
  remainder[poly_len - 1] = '\0';//0-based indexing. setting the last char as
  //end of string.
}

void crc_encodeR(char *data, char *polynomial, char *remainder, int data_len){
  int poly_len = strlen(polynomial);

  // Perform the division process
  for (int i = 0; i <= data_len - 1; i++){
    if (data[i] == '1'){
      xor(data + i, polynomial, poly_len);
    }
  }

  strncpy(remainder, data + data_len, poly_len - 1);//divisor_length -1.
  remainder[poly_len - 1] = '\0';//0-based indexing. setting the last char as
  //end of string.
}

int main()

{
  char data[100], polynomial[100], received_data[100];
  char remainder[100], remainder_check[100];

  printf("Enter data to be transmitted: ");
  scanf("%s", data);
  printf("Enter the Generating polynomial: ");
  scanf("%s", polynomial);

  bool flag = true;
  crc_encode(data, polynomial, remainder, flag);
  printf("CRC or Check value is: %s\n", remainder);

  strcat(data, remainder);
  printf("Final data\n to be sent: %s\n", data);

  printf("Enter the received data: \n");
  scanf("%s", received_data);

  printf("Data received: %s\n", received_data);

  flag = false;
  crc_encodeR(received_data, polynomial, remainder_check, strlen(data));

  if (strchr(remainder_check, '1') == NULL){
    printf("No error detected\n");

  } else{
    printf("Error detected in the received data\n");
  }

  return 0;
}