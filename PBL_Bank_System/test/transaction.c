#include "bank.h"
void transaction(int id, double amount, int option)
{
    if (!is_valid_amount(amount))
    {
        printf("金额必须为正数!\n"); 
        return;
    }

    Account *acc = find_account_by_id(id);
    if (acc == NULL)
    {
        printf("未找到该账户！\n"); 
        return;
    }
    if (option == 1)
    {
        acc->balance += amount;
        printf("存款成功!\n");
        return;
    }
    if (option == 2 && acc->balance >= amount)
    {
        acc->balance -= amount;
        printf("取款成功!\n");
        return;
    }
    else
    {
        printf("余额不足！\n");
        return;
    } 
}
double query_balance(int id)
{
    Account *acc = find_account_by_id(id);
    if (acc == NULL)
    {
        return -1.0; 
    }
    return acc->balance;
}
