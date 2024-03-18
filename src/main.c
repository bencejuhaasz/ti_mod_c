#include <ti/getcsc.h>
#include <ti/screen.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fileioc.h>

/* Set maximum size of input and output buffers */
#define INPUT_SIZE  1000
#define RESP_SIZE   100

int mod(char *num, int a)
    {
     // Initialize result
     int res = 0;

     // One by one process all digits of 'num'
     for (int i = 0; i < strlen(num); i++)
         res = (res * 10 + num[i] - '0') % a;

     return res;
    }


int main(void)
{
    char xBuffer[INPUT_SIZE];
    char yBuffer[INPUT_SIZE];
    char response[RESP_SIZE];

    /* Clear the homescreen */
    os_ClrHome();

    os_GetStringInput("X? ", xBuffer, INPUT_SIZE);
    os_GetStringInput("Y? ", yBuffer, INPUT_SIZE);
         
    const int ans = mod(&xBuffer, atoi(yBuffer));
    
    real_t * real = ti_MallocReal();

    *real=os_Int24ToReal(ans);

    ti_SetVar(OS_TYPE_REAL, OS_VAR_ANS, real);

    free(real);
    
    /* Build the user response */
    sprintf(response, "Ans is %d.", ans);
    
    

    /* Clear the homescreen and display the built response */
    os_ClrHome();
    os_PutStrFull(response);

    /* Waits for a key */
    while (!os_GetCSC());

    return 0;
}
