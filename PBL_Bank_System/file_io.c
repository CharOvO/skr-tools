#include "bank.h"

// ====== 数据保存功能 (FUN-007) ======
// 将当前内存中的账户数据保存到二进制文件 bank.dat 中。
void save_data()
{
    FILE *fp = fopen(FILENAME, "wb"); // "wb" 表示以二进制写入模式打开文件
    if (fp == NULL)
    {
        printf("错误：无法打开文件 %s 进行写入。\n", FILENAME);
        return;
    }

    // 1. 按照文件结构定义，先写入账户数量
    size_t written = fwrite(&account_count, sizeof(int), 1, fp);
    if (written != 1)
    {
        printf("错误：写入账户数量失败。\n");
        fclose(fp);
        return;
    }

    // 2. 再写入整个账户数组
    // 写入 account_count 个 Account 结构体大小的数据块
    written = fwrite(accounts, sizeof(Account), account_count, fp);
    if (written != (size_t)account_count)
    {
        printf("错误：写入账户数据失败。\n");
    }
    else
    {
        printf("成功保存 %d 个账户到文件。\n", account_count);
    }

    fclose(fp); // 关闭文件
}

// ====== 数据加载功能 (FUN-008) ======
// 从二进制文件 bank.dat 中加载账户数据到内存。
void load_data()
{
    FILE *fp = fopen(FILENAME, "rb"); // "rb" 表示以二进制读取模式打开文件
    if (fp == NULL)
    {
        printf("提示：未找到数据文件 %s，将启动一个空系统。\n", FILENAME);
        account_count = 0; // 确保账户数量为0
        return;
    }

    // 1. 先读取账户数量
    size_t read = fread(&account_count, sizeof(int), 1, fp);
    if (read != 1)
    {
        printf("错误：读取账户数量失败。文件可能已损坏。\n");
        account_count = 0; // 重置为0，防止后续读取错误
        fclose(fp);
        return;
    }

    // 2. 检查读取到的账户数量是否合法
    if (account_count < 0 || account_count > MAX_ACCOUNTS)
    {
        printf("错误：文件中的账户数量 %d 不合法。将启动一个空系统。\n", account_count);
        account_count = 0;
        fclose(fp);
        return;
    }

    // 3. 再读取账户数组数据
    read = fread(accounts, sizeof(Account), account_count, fp);
    if (read != (size_t)account_count)
    {
        printf("错误：读取账户数据失败。文件可能已损坏。\n");
        account_count = 0; // 读取失败，重置为0
    }
    else
    {
        printf("成功从文件加载 %d 个账户。\n", account_count);
    }

    fclose(fp); // 关闭文件
}
