#include <stdio.h>
#include <cs50.h>
#include <math.h>
 
int main(void)
{
    float change = 0;
    int leftover_change = 0;
    int cents_change = 0;
    int dimes = 0;
    int nickels = 0;
    int quarters = 0;
    int coins = 0;
    
    printf("Hello! How much change is owed?\n");
    change = GetFloat();
    
    if (change > 0)
    {
    cents_change = (int)round(change*100);
    quarters = cents_change / 25;
    leftover_change = cents_change % 25;
    dimes = leftover_change / 10;
    leftover_change = leftover_change % 10;
    nickels = leftover_change / 5;
    leftover_change = leftover_change % 5;
    coins = quarters + dimes + nickels + leftover_change;
    printf("%d\n", coins);
    }
    else
    {
        printf("The customer hasnt paid enough money!\n");
    }
    if (change < 0)
    {
        printf("The customer cannot have negative change.");
        GetFloat();
    }
    return 0;
}
