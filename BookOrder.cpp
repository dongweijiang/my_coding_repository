#include "BookOrder.h"

#include <string>

using namespace std;

BookOrder::BookOrder() {};

BookOrder::BookOrder(Book m_book, int m_book_num) : book(m_book), book_num(m_book_num) {
                                                    };

BookOrder::~BookOrder() {};

Book &BookOrder::getBook()
{
    return book;
}

int BookOrder::getBookNum()
{
    return book_num;
}

int BookOrder::getOrderId()
{
    return order_id;
}

void BookOrder::setOrderId(int new_id)
{
    order_id = new_id;
}

VIPBookOrder::VIPBookOrder()
{
}

VIPBookOrder::VIPBookOrder(Book m_book, int m_book_num) : BookOrder(m_book, m_book_num)
{
}

int VIPBookOrder::getTotalPrice()
{
    return book.getPrice() * getBookNum() * 0.8;
}

VIPBookOrder::~VIPBookOrder()
{
}

NormalBookOrder::NormalBookOrder()
{
}

NormalBookOrder::NormalBookOrder(Book m_book, int m_book_num) : BookOrder(m_book, m_book_num)
{
}

int NormalBookOrder::getTotalPrice()
{
    return book.getPrice() * getBookNum();
}

NormalBookOrder::~NormalBookOrder()
{
}

int BookOrder::order_id = 0;

BookOrder *orders[100] = {nullptr}; // 订单数组，最多存储100个订单

ostream &operator<<(ostream &os, BookOrder &order)
{
    os << "订单ID: " << order.getOrderId() << endl;
    os << "书名: " << order.getBook().getName() << endl;
    os << "作者: " << order.getBook().getAuthor() << endl;
    os << "单价: " << order.getBook().getPrice() << endl;
    os << "数量: " << order.getBookNum() << endl;
    os << "总价: " << order.getTotalPrice() << endl;
    return os;
}