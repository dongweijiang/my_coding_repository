#pragma once

#include <string>

#include "Book.h"

#include <iostream>

using namespace std;

class menu;

class BookOrder
{
    friend class menu;

    friend ostream &operator<<(ostream &os, BookOrder &order);

public:
    BookOrder();

    BookOrder(Book m_book, int m_book_num);

    virtual ~BookOrder();

    virtual int getTotalPrice() = 0;

    Book &getBook();

    int getBookNum();

    int getOrderId();

    void setOrderId(int new_id);

protected:
    Book book;

    static int order_id;

    int book_num;
};

extern BookOrder *orders[100];

ostream &operator<<(ostream &os, BookOrder &order);

class VIPBookOrder : public BookOrder // VIP打八折
{
public:
    VIPBookOrder();

    VIPBookOrder(Book m_book, int m_book_num);

    int getTotalPrice();

    ~VIPBookOrder();
};

class NormalBookOrder : public BookOrder // 普通没有折扣
{
public:
    NormalBookOrder();

    NormalBookOrder(Book m_book, int m_book_num);

    virtual ~NormalBookOrder();

    int getTotalPrice();
};