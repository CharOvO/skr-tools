#include "bank.h"
void save_data()
{
    FILE *fp = fopen(FILENAME, "wb"); 
    if (fp == NULL)
    {
        printf("错误：无法打开文件 %s 进行写入。\n", FILENAME);
        return;
    }
    size_t written = fwrite(&account_count, sizeof(int), 1, fp);
    if (written != 1)
    {
        printf("错误：写入账户数量失败。\n");
        fclose(fp);
        return;
    }
    written = fwrite(accounts, sizeof(Account), account_count, fp);
    if (written != (size_t)account_count)
    {
        printf("错误：写入账户数据失败。\n");
    }
    else
    {
        printf("成功保存 %d 个账户到文件。\n", account_count);
    }

    fclose(fp); 
}
void load_data()
{
    FILE *fp = fopen(FILENAME, "rb"); 
    if (fp == NULL)
    {
        printf("提示：未找到数据文件 %s，将启动一个空系统。\n", FILENAME);
        account_count = 0; 
        return;
    }

    size_t read = fread(&account_count, sizeof(int), 1, fp);
    if (read != 1)
    {
        printf("错误：读取账户数量失败。文件可能已损坏。\n");
        account_count = 0; // 重置为0，防止后续读取错误
        fclose(fp);
        return;
    }
    if (account_count < 0 || account_count > MAX_ACCOUNTS)
    {
        printf("错误：文件中的账户数量 %d 不合法。将启动一个空系统。\n", account_count);
        account_count = 0;
        fclose(fp);
        return;
    }
    read = fread(accounts, sizeof(Account), account_count, fp);
    if (read != (size_t)account_count)
    {
        printf("错误：读取账户数据失败。文件可能已损坏。\n");
        account_count = 0;
    }
    else
    {
        printf("成功从文件加载 %d 个账户。\n", account_count);
    }
    fclose(fp); 
}
