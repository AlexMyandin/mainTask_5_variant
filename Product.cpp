#include "Product.h"
Product::Product() :
m_name(""), m_category(""), m_price(0), m_description(""), m_in_stock(false) {};
Product::Product(string name, string category, double price, string des, bool in_stock) :
	m_name(name), m_category(category), m_price(price), m_description(des), m_in_stock(in_stock) {};
Product::~Product() {};
//геттеры
string Product::getName() { return m_name; };
string Product::getCategory() { return m_category; };
double Product::getPrice() { return m_price; };
string Product::getDes() { return m_description; };
bool Product::getInStock() { return m_in_stock; };
//сеттеры
void Product::setName(string name) { m_name = name; };
void Product::setCategory(string category) { m_category = category; };
void Product::setPrice(double price) { m_price = price; };
void Product::setDes(string des) { m_description = des; };
void Product::setInStock(bool in_stock) { m_in_stock = in_stock; };