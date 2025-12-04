#ifndef BANK_H
#define BANK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ACCOUNTS 50     
#define MIN_ACCOUNT_ID 1000 
#define MAX_ACCOUNT_ID 1049 
#define FILENAME "bank.dat" 
#define NAME_LEN 50         
typedef struct
{
    int id;              
    char name[NAME_LEN]; 
    double balance;      
} Account;
extern Account accounts[MAX_ACCOUNTS]; 
extern int account_count;              
void show_menu();  
void run_system(); 
int create_account(const char *name); 
void display_all_accounts();          
Account *find_account_by_id(int id);  
void transaction(int id, double amount, int option);
double query_balance(int id); 
void save_data(); 
void load_data(); 
int is_valid_id(int id);            
int is_valid_amount(double amount); 
void clear_input_buffer();          
#endif 
