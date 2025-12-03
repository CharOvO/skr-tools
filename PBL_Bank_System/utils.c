#include "bank.h"
#include <ctype.h> // 用于 isdigit

// ====== 检查ID是否合法 ======
// TODO:检查账户ID是否在1000-1049的范围内。合法返回1，非法返回0。
int is_valid_id(int id)
{
    if (1000 >= id && id <= 1049)
    {
        return 1;
    }else{
        return 0;
    }
}

// ====== 检查金额是否合法 ======
// TODO:检查金额是否为正数。合法返回1，非法返回0。
int is_valid_amount(double amount)
{
    if(amount > 0){
        return 1;
    }else{
        return 0;
    }
}

// ====== 清空输入缓冲区 ======
// 清除标准输入中剩余的字符，直到遇到换行符或文件结尾。
void clear_input_buffer()
{
    int c;
    // 循环读取并丢弃字符，直到遇到换行符'\n'或EOF
    while ((c = getchar()) != '\n' && c != EOF);
}
