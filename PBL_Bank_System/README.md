# 🏦 PBL银行账户管理系统

> 一个基于C语言的简易银行账户管理系统 - 课程设计项目

![项目状态](https://img.shields.io/badge/状态-已完成-brightgreen)
![语言](https://img.shields.io/badge/语言-C语言-blue)
![平台](https://img.shields.io/badge/平台-Windows-lightgrey)
![编码](https://img.shields.io/badge/编码-GBK/UTF8-orange)

## 📋 项目简介

这是一个完整的银行账户管理系统，实现了账户管理、交易操作、数据持久化等核心功能。项目采用模块化设计，结构清晰，适合作为C语言课程设计或学习项目。

## ✨ 功能特性

- ✅ **账户管理**：开户、查询、显示所有账户
- ✅ **交易操作**：存款、取款、余额查询
- ✅ **数据持久化**：自动保存/加载账户数据
- ✅ **输入验证**：完善的错误检查和输入清理
- ✅ **用户友好**：中文界面，清晰的操作提示
- ✅ **模块化设计**：功能分离，便于维护和扩展

## 📁 项目结构

```
PBL_Bank_System/
├── bank.c          # 主程序文件（程序入口）
├── bank.h          # 头文件（所有声明和定义）
├── account.c       # 账户管理模块
├── transaction.c   # 交易操作模块
├── file_io.c       # 文件I/O模块
├── utils.c         # 工具函数模块
├── README.md       # 项目说明文档（本文档）
├── bank.exe        # 可执行文件
├── .vscode/        # VS Code开发配置
└── .git/           # Git版本控制
```

## 🎯 系统菜单

```
========== 简易银行账户管理系统 ==========
1. 开户
2. 显示所有账户
3. 查找账户
4. 存款
5. 取款
6. 余额查询
7. 保存数据
8. 加载数据
0. 退出系统
==========================================
```

## 📊 数据结构

### 账户结构体
```c
typedef struct {
    int id;              // 账户ID (1000-1049)
    char name[NAME_LEN]; // 账户姓名 (最大50字符)
    double balance;      // 账户余额
} Account;
```

### 全局变量
```c
Account accounts[MAX_ACCOUNTS]; // 账户数组，最大50个账户
int account_count = 0;          // 当前账户数量计数器
```

### 常量定义
```c
#define MAX_ACCOUNTS 50     // 最大账户数量
#define MIN_ACCOUNT_ID 1000 // 账户ID最小值
#define MAX_ACCOUNT_ID 1049 // 账户ID最大值
#define FILENAME "bank.dat" // 数据文件名
#define NAME_LEN 50         // 姓名最大长度
```

## 🔧 功能模块详解

### 1. 主控模块 (`bank.c`)
| 函数 | 功能说明 |
|------|----------|
| `main()` | 程序入口，加载数据并启动系统 |
| `show_menu()` | 显示主菜单界面 |
| `run_system()` | 系统主循环，处理用户选择 |

### 2. 账户管理模块 (`account.c`)
| 函数 | 功能说明 | 返回值 |
|------|----------|--------|
| `create_account(name)` | 创建新账户 | 成功: 账户ID, 失败: -1 |
| `display_all_accounts()` | 显示所有账户信息 | void |
| `find_account_by_id(id)` | 根据ID查找账户 | 成功: 账户指针, 失败: NULL |

### 3. 交易操作模块 (`transaction.c`)
| 函数 | 功能说明 | 返回值 |
|------|----------|--------|
| `deposit(id, amount)` | 存款操作 | 成功: 0, 失败: -1 |
| `withdraw(id, amount)` | 取款操作 | 成功: 0, 失败: -1 |
| `query_balance(id)` | 查询余额 | 成功: 余额, 失败: -1.0 |

### 4. 文件I/O模块 (`file_io.c`)
| 函数 | 功能说明 |
|------|----------|
| `save_data()` | 保存所有账户数据到文件 |
| `load_data()` | 从文件加载账户数据 |

### 5. 工具函数模块 (`utils.c`)
| 函数 | 功能说明 | 返回值 |
|------|----------|--------|
| `is_valid_id(id)` | 检查ID是否合法 | 合法: 1, 非法: 0 |
| `is_valid_amount(amount)` | 检查金额是否合法 | 合法: 1, 非法: 0 |
| `clear_input_buffer()` | 清空输入缓冲区 | void |

## 🚀 快速开始

### 环境要求
- Windows 操作系统
- GCC 编译器 (MinGW)
- 或 Visual Studio Code + C/C++扩展

### 编译项目
```bash
# 方法1：编译所有.c文件（推荐）
gcc *.c -fexec-charset=gbk -o bank

# 方法2：指定文件编译
gcc bank.c account.c transaction.c file_io.c utils.c -fexec-charset=gbk -o bank

# 方法3：使用UTF-8编码编译
gcc *.c -finput-charset=UTF-8 -fexec-charset=GBK -o bank
```

### 运行程序
```bash
.\bank
```

## 🔄 数据流说明

1. **启动时**：程序自动从 `bank.dat` 文件加载账户数据
2. **操作时**：所有账户操作在内存中进行，实时更新
3. **退出时**：可选择保存当前数据到文件
4. **持久化**：使用二进制格式保存，确保数据安全

## 📝 编码规范

- **文件编码**：支持GBK和UTF-8编码
- **命名规范**：函数名使用小写字母和下划线
- **注释规范**：关键函数和复杂逻辑添加详细注释
- **错误处理**：完善的输入验证和错误提示

## 🐛 常见问题

### Q1: 编译时出现"undefined reference"错误？
**A**: 确保编译时包含了所有.c文件：
```bash
gcc *.c -o bank
```

### Q2: 中文显示乱码？
**A**: 使用正确的编码参数：
```bash
# Windows控制台（GBK）
gcc *.c -fexec-charset=gbk -o bank

# 或使用UTF-8
gcc *.c -finput-charset=UTF-8 -fexec-charset=UTF-8 -o bank
```

### Q3: 如何清空所有账户数据？
**A**: 删除项目目录下的 `bank.dat` 文件即可。

## 📈 扩展建议

1. **密码功能**：为账户添加密码保护
2. **交易记录**：记录每笔交易的详细信息
3. **利息计算**：根据存款时间计算利息
4. **图形界面**：使用GTK或Qt添加GUI
5. **网络功能**：实现客户端-服务器架构
6. **数据库**：使用SQLite替代文件存储

## 👥 贡献指南

1. Fork 本仓库
2. 创建功能分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 开启 Pull Request

## 📄 许可证

本项目仅供学习使用，遵循 MIT 许可证。

## 🙏 致谢

感谢所有为这个项目提供帮助和建议的同学和老师！

---
**最后更新**：2025年12月2日  
**项目状态**：✅ 已完成基础功能  
**下一步计划**：添加更多高级功能和优化用户体验

> 💡 提示：运行前请确保已正确编译，生成 `bank.exe` 可执行文件。