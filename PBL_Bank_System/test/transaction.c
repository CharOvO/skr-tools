#include "bank.h"

// ====== 存款操作 (FUN-004) ======
// 向指定账户存入资金。成功返回1，失败返回0。
// ====== 取款操作 (FUN-005) ======
// TODO:从指定账户取出资金。成功返回1，失败返回0。
void transaction(int id, double amount, int option)
{
    // 1. 验证金额合法性
    if (!is_valid_amount(amount))
    {
        printf("金额必须为正数!\n"); // 失败：金额必须为正数
        return;
    }

    // 2. 查找账户
    Account *acc = find_account_by_id(id);
    if (acc == NULL)
    {
        printf("未找到该账户！\n"); // 失败：账户不存在
        return;
    }

    // 3. 存款
    if (option == 1)
    {
        acc->balance += amount;
        printf("存款成功!\n");
        return;
    }
    // 3. 取款
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

// ====== 余额查询 (FUN-006) ======
// 查询指定账户的当前余额。成功返回余额，失败返回-1。
double query_balance(int id)
{
    // 1. 查找账户
    Account *acc = find_account_by_id(id);
    if (acc == NULL)
    {
        return -1.0; // 失败：账户不存在
    }

    // 2. 返回余额
    return acc->balance;
}
