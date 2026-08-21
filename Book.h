#pragma once
#include <iostream>
#include <string>
using namespace std;

class BookOrder;

class Book
{
  friend class BookOrder;

public:
  Book();

  Book(string m_name, string m_author, int m_price);

  int getPrice();

  string getName();

  string getAuthor();

protected:
  string name;

  string author;

  int price;
};
