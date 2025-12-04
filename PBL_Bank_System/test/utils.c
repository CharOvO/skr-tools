#include "bank.h"
#include <ctype.h> 
int is_valid_id(int id)
{
    if (1000 <= id && id <= 1049)
    {
        return 1;
    }else{
        return 0;
    }
}
int is_valid_amount(double amount)
{
    if(amount > 0){
        return 1;
    }else{
        return 0;
    }
}
void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
