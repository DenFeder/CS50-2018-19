#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
Test creditcard: 436014
Test creditcard: 2060
v VISA
6003600000000015 INVALID
4003600000000 VISA
5490031801949067 Mastercard
378282246310005 AMEX
5200000000000000 Master
370000000000000 AMEX
340000000000000 AMEX
4000000000000000 VISA
4000000000000 VISA

 4003600000000014

 371449635398431 AMEX
 5105105105105100 Mastercard
 4111111111111111 Visa
 4111111111111113 Invalid?
 4012888888881881 Visa
*/


bool iscredit(long prompt);

int pro_digit;

int main (void)
{
    long a = get_long("Number: ");
    long b13 = a / (1e13);
    long c14 = a / (1e14);
    long d15 = a / (1e15);

    if ((a / 1e12 == 4) || (a / 1e15 == 4) )
    {
        printf("VISA\n 13: %li \n c14: %li\n d15: %li \n",b13,c14,d15);
    }
    else if ((a / (1e13) == 34) || (a / (1e13) == 37) )
    {
        printf("AMEX\n b13: %li \n c14: %li\n d15: %li \n",b13,c14,d15);
    }
    else if (a / (1e14) < 56 && a / (1e14) > 50)
    {
        printf("MASTERCARD\n b13: %li \n c14: %li\n d15: %li \n",b13,c14,d15);
    }
    else
    {
        printf("INVALID\n b13: %li \n c14: %li\n d15: %li \n",b13,c14,d15);
    }

}

