#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_owed_change(string prompt) ;

int CoinNr ;

int main (void)
{
    float change_float = get_owed_change("Change owed:") ; //asking for positive number greater than 0
    int change_cent = (int) round(change_float*100) ; //converting dollar input to rounded cents

    //Check Quarters (25ct)
    int quarters = floor(change_cent / 25) ; //determining # of quaters
    change_cent = change_cent%25 ; //determining remaining change
    CoinNr = CoinNr + quarters ; //Adding quarter quantity to coin amount

    //Check Dimes (10ct)
    int dimes = floor(change_cent/10) ; //determining # of dime
    change_cent = change_cent%10 ; //determining remaining change
    CoinNr = CoinNr + dimes ; //Adding dime quantity to coin amount

    //Check Nickels (5ct)
    int nickels = floor(change_cent/5) ; //determining # of nickels
    change_cent = change_cent%5 ; //determining remaining change
    CoinNr = CoinNr + nickels; //Adding nickel quantity to coin amount

    //Check Pennys (1ct)
    CoinNr = CoinNr + change_cent ; //remaining change equals amount of pennys
                                    //Remaining change added to Coin number

    printf("%i\n", CoinNr) ;
}

float get_owed_change(string prompt)
{
    float change ;
    do //do while loop to repeat prompt in case of incorrect input
    {
        change = get_float ("%s", prompt) ;
    }
    while (change <=0) ; //checking if prompt is greater 0
    return change ;
}