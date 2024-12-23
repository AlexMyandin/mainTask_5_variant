#pragma once
#include <string>


using namespace std;

class Product
{
public:
    Product();
    Product(string name,string category,double price,string des,bool in_stock);
    ~Product();
    //геттеры
    string getName();
    string getCategory();
    double getPrice();
    string getDes();
    bool getInStock();
    //сеттеры
    void setName(string name);
    void setCategory(string category);
    void setPrice(double price);
    void setDes(string des);
    void setInStock(bool in_stock);
private:
    string m_name;
    string m_category;
    double m_price;
    string m_description;
    bool m_in_stock;
};

