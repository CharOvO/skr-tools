#ifndef BANK_H
#define BANK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ====== 常量定义 ======
#define MAX_ACCOUNTS 50     // 最大账户数量
#define MIN_ACCOUNT_ID 1000 // 账户ID最小值
#define MAX_ACCOUNT_ID 1049 // 账户ID最大值
#define FILENAME "bank.dat" // 数据文件名称
#define NAME_LEN 50         // 账户姓名最大长度

// ====== 结构体定义 ======
typedef struct
{
    int id;              // 账户ID
    char name[NAME_LEN]; // 账户姓名
    double balance;      // 账户余额
    int status;          // 账户状态
} Account;

// ====== 全局变量声明 ======
extern Account accounts[MAX_ACCOUNTS]; // 账户数组
extern int account_count;              // 当前账户数量

// ====== 函数接口声明 ======

// 主控模块（main.c）
void show_menu();  // 显示主菜单
void run_system(); // 系统主循环

// 账户管理模块（account.c）
int create_account(const char *name); // 创建账户，返回账户ID
void display_all_accounts();          // 显示所有账户
Account *find_account_by_id(int id);  // 根据ID查找账户
Account *find_account_by_name(char *name); // 根据姓名查找账户
void delete_account(int id); // 根据ID销户

// 交易操作模块（transaction.c）
void transaction(int id, double amount, int option);
double query_balance(int id); // 查询余额

// 文件操作模块（file_io.c）
void save_data(); // 保存数据到文件
void load_data(); // 从文件加载数据

// 工具函数模块（utils.c）
int is_valid_id(int id);            // 检查ID是否合法
int is_valid_amount(double amount); // 检查金额是否合法
void clear_input_buffer();          // 清空输入缓冲区

#endif // BANK_H
