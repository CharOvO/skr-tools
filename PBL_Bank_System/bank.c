#include "bank.h"

int main()
{
    // 程序启动时，首先尝试从文件加载数据
    load_data();

    // 进入系统主循环
    run_system();

    return 0;
}

// ====== 全局变量定义 ======
Account accounts[MAX_ACCOUNTS]; // 账户数组
int account_count = 0;          // 当前账户数量

// ====== 主菜单显示 ======
void show_menu()
{
    printf("\n========== 简易银行账户管理系统 ==========\n");
    printf("1. 开户\n");
    printf("2. 显示所有账户\n");
    printf("3. 显示所有账户(自定义排序)\n");
    printf("4. 查找账户(ID)\n");
    printf("5. 查找账户(姓名)\n");
    printf("6. 存款\n");
    printf("7. 取款\n");
    printf("8. 余额查询\n");
    printf("9. 保存数据\n");
    printf("10. 加载数据\n");
    printf("11. 销户\n");
    printf("0. 退出系统\n");
    printf("==========================================\n");
    printf("请输入您的选择（0-8）：");
}

// ====== 主循环控制 ======
void run_system()
{
    int choice;
    int id;
    char name[NAME_LEN];
    double amount;

    while (1)
    {
        show_menu();
        if (scanf("%d", &choice) != 1)
        {
            printf("输入错误，请输入数字！\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer(); // 清除输入缓冲区

        switch (choice)
        {
        case 1: // 开户
            printf("请输入账户姓名：");
            fgets(name, NAME_LEN, stdin);
            name[strcspn(name, "\n")] = '\0'; // 去除换行符
            id = create_account(name);
            if (id != -1)
            {
                printf("开户成功！您的账户ID是：%d\n", id);
            }
            else
            {
                printf("开户失败，账户数量已达上限！\n");
            }
            break;

        case 2: // TODO:显示所有账户
            display_all_accounts();
            break;
        case 3: // 自定义显示所有账户
            printf("选择排序方式：1:id 2:姓名 3:余额：");
            if (scanf("%d", &choice) != 1)
            {
                clear_input_buffer();
                printf("输入错误,请输入数字!");
                break;
            }
            clear_input_buffer();
            custom_display_all_accounts(choice);
            break;
        case 4: // 查找账户-ID
            printf("请输入要查找的账户ID：");
            if (scanf("%d", &id) != 1)
            {
                printf("输入错误，请输入数字！\n");
                clear_input_buffer();
                break;
            }
            clear_input_buffer();
            Account *acc = find_account_by_id(id);
            if (acc)
            {
                printf("ID\t姓名\t余额\n");
                printf("%d\t%s\t%.2f\n", acc->id, acc->name, acc->balance);
            }
            else
            {
                printf("未找到该账户！\n");
            }
            break;

        case 5: // 查找账户-name
            printf("请输入要查找账户姓名：");
            fgets(name, NAME_LEN, stdin);
            name[strcspn(name, "\n")] = '\0'; 
            // clear_input_buffer();
            acc = find_account_by_name(name);
            if (acc)
            {
                printf("ID\t姓名\t余额\n");
                printf("%d\t%s\t%.2f\n", acc->id, acc->name, acc->balance);
            }
            else
            {
                printf("未找到该账户！\n");
            }
            break;

        
        case 6: // TODO:存款
            printf("请输入要存款的账户ID：");

            if (scanf("%d", &id) != 1)
            {
                printf("输入错误，请输入数字！\n");
                clear_input_buffer();
                break;
            }
            clear_input_buffer();
            printf("请输入要存款的金额：");
            if (scanf("%lf", &amount) != 1)
            {
                printf("输入错误，请输入数字！\n");
                clear_input_buffer();
                break;
            }

            clear_input_buffer();
            transaction(id, amount, 1);
            break;

        case 7: // TODO:取款
            printf("请输入要取款的账户ID：");

            if (scanf("%d", &id) != 1)
            {
                printf("输入错误，请输入数字！\n");
                clear_input_buffer();
                break;
            }
            clear_input_buffer();
            printf("请输入要取款的金额：");
            if (scanf("%lf", &amount) != 1)
            {
                printf("输入错误，请输入数字！\n");
                clear_input_buffer();
                break;
            }

            clear_input_buffer();
            transaction(id, amount, 2);
            break;

        case 8: // 余额查询
            printf("请输入账户ID：");
            if (scanf("%d", &id) != 1)
            {
                printf("输入错误，请输入数字！\n");
                clear_input_buffer();
                break;
            }
            clear_input_buffer();
            amount = query_balance(id);
            if (amount >= 0)
            {
                printf("账户余额：%.2f\n", amount);
            }
            else
            {
                printf("查询失败，未找到该账户！\n");
            }
            break;

        case 9: // TODO:保存数据
            save_data();
            break;
        case 10: // TODO:加载数据
            load_data();
            break;
        case 11:
            printf("请输入要销户的账户ID：");
            if (scanf("%d", &id) != 1)
            {
                printf("输入错误，请输入数字！\n");
                clear_input_buffer();
                break;
            }
        case 0: // 退出系统
            printf("感谢使用，再见！\n");
            return;
            clear_input_buffer();
            delete_account(id);
            break;
        default:
            printf("无效选择，请重新输入！\n");
            break;
        }
    }
}
