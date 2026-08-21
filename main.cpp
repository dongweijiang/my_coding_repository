#include <iostream>
#include <string>
#include "Book.h"
#include "BookOrder.h"
#include "menu.h"

/*对了，老师你好:),如果你点进来了，来看我的代码了，那我只能说，谢谢你，辛苦了。但是老师，最好不要直接运行我的源码。很神奇。至少我在VSCode上直接运行会给我报错。需要在终端输入“g++ .\main.cpp menu.cpp Book.cpp BookOrder.cpp -o .\main.exe”才能正常运行:)。我真没招了。如果非得运行我的源码，老师可以考虑直接用我准备好的main.exe，实在不行可以用其他IDE试试。*/

using namespace std;

extern BookOrder *orders[100];
// 图书订单管理系统：0、创建账号；1、添加订单；2、删除订单；3、修改订单；4、查询订单；5、显示所有订单；6、退出系统
// 继承的应用：bookorder可以派生出两个子类，VIPBookOrder和NormalBookOrder，分别代表VIP订单和普通订单，VIP订单可以享受折扣优惠，而普通订单则没有折扣优惠。
// 静态成员的应用：图书id设置为静态成员。

int main()
{

    Book book1("C++ Primer", "Stanley B.Lippman", 88);
    VIPBookOrder order1(book1, 2);
    orders[0] = &order1;
    cout << "hello world!" << endl;
    cout << "订单信息：" << endl;
    system("pause");
    return 0;
}

int a=3;