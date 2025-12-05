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
    new_account.status = 1;                // 启用账户

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
    if (account_count == 0)
    {
        printf("当前系统不存在账户信息!\n");
        return;
    }

    printf("ID\t姓名            余额\n");
    for (int i = 0; i < account_count; i++)
    {
        if (accounts[i].status == -1)
        {
            continue;
        }
        printf("%d\t%s          %.2f\n", accounts[i].id, accounts[i].name, accounts[i].balance);
    }
    return;
}

// ====== 自定义显示所有账户 (FUN-102) ======
void custom_display_all_accounts(int choice)
{
    if (choice > 3 || choice < 1)
    {
        printf("输入错误,请输入指定数字!\n");
        return;
    }
    // 检查是否存在账户信息
    if (account_count == 0)
    {
        printf("当前系统不存在账户信息!\n");
        return;
    }
    

    // 自定义排序：1=id 2=name 3=balance（升序）
    Account tmp[MAX_ACCOUNTS];
    int n = 0;
    // 挑选可用账户
    for (int i = 0; i < account_count; i++){
        if (accounts[i].status != -1){
            tmp[n] = accounts[i];
            n++;
        }
    }
    // 冒泡
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int swap = 0;
            if (choice == 1)
            {
                if (tmp[i].id > tmp[j].id){
                    swap = 1;
                }
            }
            else if (choice == 2)
            {
                if (strcmp(tmp[i].name, tmp[j].name) > 0){
                    swap = 1;
                }
            }
            else if (choice == 3)
            {
                if (tmp[i].balance > tmp[j].balance){
                    swap = 1;
                }
            }
            if (swap)
            {
                Account t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
        }
    }
    printf("ID\t姓名            余额\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%s          %.2f\n", tmp[i].id, tmp[i].name, tmp[i].balance);
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
            if (accounts[i].status == -1)
            {
                return NULL;
            }
            return &accounts[i]; // 找到，返回账户指针
        }
    }

    // 3. 遍历结束未找到
    return NULL; // 失败：未找到
}

// ====== 账户查找 (FUN-103) ======
// 根据账户姓名查找账户。如果找到，返回指向该账户的指针；否则返回NULL。
Account *find_account_by_name(char *name)
{
    // 1. 遍历账户数组进行查找
    for (int i = 0; i < account_count; i++)
    {
        if (!strcmp(accounts[i].name, name))
        {
            if (accounts[i].status == -1)
            {
                return NULL;
            }
            return &accounts[i]; // 找到，返回账户指针
        }
    }

    // 3. 遍历结束未找到
    return NULL; // 失败：未找到
}

// ====== 销户 (FUN-101) ======
void delete_account(int id)
{
    Account *acc = find_account_by_id(id);
    if (acc == NULL)
    {
        printf("未找到该账户！\n");
        return;
    }
    // 判断是否还有余额
    if (acc->balance > 0)
    {
        printf("当前账户中仍有余额,无法销户!\n");
        return;
    }
    // 销户
    acc->status = -1;
    strncpy(acc->name, "已注销", NAME_LEN - 1);
    acc->name[NAME_LEN - 1] = '\0';
    acc->balance = 0.0;
    printf("销户成功!,销户ID:%d", acc->id);
    return;
}
