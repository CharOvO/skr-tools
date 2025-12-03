#include "bank.h"

// ====== 开户功能 (FUN-001) ======
// 创建新账户，并返回分配的账户ID。如果失败，返回-1。
int create_account(const char *name)
{
    // 1. 检查账户数量是否已达上限
    if (account_count >= MAX_ACCOUNTS)
    {
        return -1; // 失败：账户已满
    }

    // 2. 生成唯一的账户ID
    int new_id = MIN_ACCOUNT_ID;
    // 从一个已有的账户ID开始，寻找下一个可用的ID
    if (account_count > 0)
    {
        new_id = accounts[account_count - 1].id + 1;
    }

    // 检查ID是否超出范围
    if (new_id > MAX_ACCOUNT_ID)
    {
        return -1; // 失败：ID范围已用尽
    }

    // 3. 创建新账户并初始化
    Account new_account;
    new_account.id = new_id;
    strncpy(new_account.name, name, NAME_LEN - 1);
    new_account.name[NAME_LEN - 1] = '\0'; // 确保字符串以null结尾
    new_account.balance = 0.0;             // 新账户初始余额为0

    // 4. 将新账户添加到全局数组中
    accounts[account_count] = new_account;
    account_count++; // 账户数量加一

    return new_id; // 返回新创建的账户ID
}

// ====== 显示所有账户 (FUN-002) ======
// TODO:遍历并打印所有账户的详细信息。
void display_all_accounts()
{
    // 检查是否存在账户信息
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

// ====== 账户查找 (FUN-003) ======
// 根据账户ID查找账户。如果找到，返回指向该账户的指针；否则返回NULL。
Account *find_account_by_id(int id)
{
    // 1. 检查ID是否合法
    if (!is_valid_id(id))
    {
        return NULL; // 失败：ID不合法
    }

    // 2. 遍历账户数组进行查找
    for (int i = 0; i < account_count; i++)
    {
        if (accounts[i].id == id)
        {
            return &accounts[i]; // 找到，返回账户指针
        }
    }

    // 3. 遍历结束未找到
    return NULL; // 失败：未找到
}
