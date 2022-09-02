#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Test creditcard: 436014
Test creditcard: 2060
4003600000000014

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
   if (iscredit(a) == true)
    {
        if ((a / 1e12 >= 4 && a / 1e12 < 5) || (a / 1e15 >= 4 && a / 1e15 < 5) )
        {
            printf("VISA\n");
        }
        else if ((a / (1e13) >= 34 && a / (1e13) < 35) || (a / (1e13) >= 37 && a / (1e13) < 38) )
        {
            printf("AMEX\n");
        }
        else if (a / (1e14) < 56 && a / (1e14) >= 51)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}


bool iscredit(long prompt)
{
    long may_credit = prompt;
    long a1 = may_credit;
    pro_digit = 0;
    long b1 = may_credit;

    do
    {
        // Step one adding products digits of every other digit from the number
        a1 = a1 / 10;
        int a2 = a1 % 10;
        a2 = a2*2;
        a1 = a1 / 10;

        pro_digit = pro_digit + (a2%10) + (a2/10);
    }
    while(a1 > 0);

    do
    {
        int b2 = b1 % 10;
        pro_digit = pro_digit + b2;
        b1 = b1 / 100;
    }
    while (b1 > 0);

    if (pro_digit % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
