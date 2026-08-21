#pragma once

#include <iostream>

using namespace std;

#include <string>

#include "BookOrder.h"

extern BookOrder *orders[100];

class account // 创建账号时，输入Y/N来判断是否成为VIP用户，如果没有账号，则无法添加订单以及任何操作，强制跳转回主菜单
{
public:
    account();

    account(string m_username, string m_password, bool m_isVIP);

    bool getIsVIP();

    string getUsername();

    string getPassword();

private:
    string username;

    string password;

    bool isVIP;
};

class menu
{
private:
    account *new_account;

public:
    account *getAccount();

    void showMenu();

    void createAccount(); // 按0创建账号后，并用private成员变量new_account来保存这个指针

    void addOrder();

    void deleteOrder();

    void modifyOrder();

    void queryOrder();

    void showAllOrders();

    ~menu();
};
