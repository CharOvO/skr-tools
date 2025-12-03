#include "bank.h"

// ====== 存款操作 (FUN-004) ======
// 向指定账户存入资金。成功返回1，失败返回0。
int deposit(int id, double amount)
{
    // 1. 验证金额合法性
    if (!is_valid_amount(amount))
    {
        return 0; // 失败：金额必须为正数
    }

    // 2. 查找账户
    Account *acc = find_account_by_id(id);
    if (acc == NULL)
    {
        return 0; // 失败：账户不存在
    }

    // 3. 执行存款
    acc->balance += amount;
    return 1; // 成功
}

// ====== 取款操作 (FUN-005) ======
// TODO:从指定账户取出资金。成功返回1，失败返回0。
int withdraw(int id, double amount)
{
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
