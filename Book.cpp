#include "Book.h"
using namespace std;
Book::Book() {};

Book::Book(string m_name, string m_author, int m_price) : name(m_name), author(m_author), price(m_price)
{
  cout << "Book类的有参构造函数被调用了！" << endl;
};

int Book::getPrice()
{
  return price;
}

string Book::getName()
{
  return name;
}

string Book::getAuthor()
{
  return author;
}