#include "bank.h"
int create_account(const char *name)
{
    if (account_count >= MAX_ACCOUNTS)
    {
        return -1; 
    }
    int new_id = MIN_ACCOUNT_ID;
    if (account_count > 0)
    {
        new_id = accounts[account_count - 1].id + 1;
    }
    if (new_id > MAX_ACCOUNT_ID)
    {
        return -1; 
    }
    Account new_account;
    new_account.id = new_id;
    strncpy(new_account.name, name, NAME_LEN - 1);
    new_account.name[NAME_LEN - 1] = '\0'; 
    new_account.balance = 0.0;             
    accounts[account_count] = new_account;
    account_count++; 
    return new_id; 
}
void display_all_accounts()
{
    if(account_count == 0){
        printf("当前系统不存在账户信息!\n");
        return;
    }
    printf("ID\t姓名\t余额\n");
    for (int i = 0; i < account_count; i++)
    {
        printf("%d\t%s\t%.2f\n",accounts[i].id,accounts[i].name,accounts[i].balance);
    }
    return;
}
Account *find_account_by_id(int id)
{ 
    if (!is_valid_id(id))
    {
        return NULL; 
    }
    for (int i = 0; i < account_count; i++)
    {
        if (accounts[i].id == id)
        {
            return &accounts[i]; 
        }
    }
    return NULL; 
}
