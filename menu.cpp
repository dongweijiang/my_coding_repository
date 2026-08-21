#include "menu.h"
#include "BookOrder.h"
using namespace std;
extern BookOrder *orders[100];

account::account() {};

account::account(string m_username, string m_password, bool m_isVIP) : username(m_username), password(m_password), isVIP(m_isVIP)
{
}
bool account::getIsVIP()
{
    return isVIP;
}

string account::getUsername()
{
    return username;
}

string account::getPassword()
{
    return password;
}

account *menu::getAccount()
{
    return new_account;
}

void menu::showMenu()
{
    cout << "欢迎来到图书订单管理系统！" << endl;
    cout << "0.创建账号" << endl;
    cout << "1.添加订单" << endl;
    cout << "2.删除订单" << endl;
    cout << "3.修改订单" << endl;
    cout << "4.查询订单" << endl;
    cout << "5.显示所有订单" << endl;
    cout << "6.退出系统" << endl;
}

void menu::createAccount() // 按0创建账号后，并用private成员变量new_account来保存这个指针
{
    string username, password;
    char isVIP;
    cout << "请输入用户名：" << endl;
    cin >> username;
    cout << "请输入密码：" << endl;
    cin >> password;
    cout << "是否成为VIP用户?(Y/N)" << endl;
    cin >> isVIP;
    bool vip_status = (isVIP == 'Y' || isVIP == 'y') ? true : false;
    account *new_account = new account(username, password, vip_status);
    cout << "账号创建成功！" << endl;
    this->new_account = new_account;
}

void menu::addOrder()
{
    if (new_account == nullptr)
    {
        cout << "请先创建账号！" << endl;
        return;
    }
    else
    {
        cout << "欢迎，" << new_account->getUsername() << "!" << endl;
        string book_name, book_author;
        int book_price, book_num;
        cout << "请输入书名：" << endl;
        cin >> book_name;
        cout << "请输入作者：" << endl;
        cin >> book_author;
        cout << "请输入价格：" << endl;
        cin >> book_price;
        cout << "请输入数量：" << endl;
        cin >> book_num;
        Book new_book(book_name, book_author, book_price);

        BookOrder *new_order = NULL;

        if (new_account->getIsVIP())
        {
            new_order = new VIPBookOrder(new_book, book_num);
            cout << "订单添加成功！" << endl;
            orders[new_order->getOrderId()] = new_order;
            BookOrder::order_id++;
        }
        else
        {
            new_order = new NormalBookOrder(new_book, book_num);
            cout << "订单添加成功！" << endl;
            orders[new_order->getOrderId()] = new_order;
            BookOrder::order_id++;
        }
    }
}
void menu::deleteOrder()
{
    if (new_account == nullptr)
    {
        cout << "请先创建账号！" << endl;
        return;
    }
    else
    {
        cout << "欢迎，" << new_account->getUsername() << "!" << endl;
        cout << "请输入要删除的订单ID:" << endl;
        int order_id;
        cin >> order_id;
        if (order_id < 0 || order_id >= 100 || orders[order_id] == nullptr)
        {
            cout << "订单ID无效！" << endl;
            return;
        }
        else
        {
            if (orders[order_id] != nullptr)
            {
                delete orders[order_id];
                orders[order_id] = nullptr;
                for (int i = order_id; i < 99; i++) // 1 2 3 4 5五个订单，现在删除2，那么3 4 5的订单id都要-1，订单数组也要前移，前移完此时的order_id是
                {
                    orders[i] = orders[i + 1];
                    if (orders[i] != nullptr)
                    {
                        orders[i]->setOrderId(i);
                    } // 订单id也要更新
                }
                orders[BookOrder::order_id - 1] = nullptr;
                BookOrder::order_id--;
            }
            else
            {
                cout << "订单ID无效！" << endl;
                return;
            }
        }
        cout << "订单删除成功！" << endl;
    }
}
void menu::modifyOrder()
{
}
void menu::queryOrder()
{
}
void menu::showAllOrders()
{
}

menu::~menu()
{
    if (new_account != nullptr)
    {
        delete new_account;
        new_account = nullptr;
    }
}
