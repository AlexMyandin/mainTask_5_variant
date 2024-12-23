#include "ObjectC.h"

ObjectC::ObjectC() {
	m_data_product.m_name = "";
	m_data_product.m_category = "";
	m_data_product.m_des = "";
	m_price = "0";
	m_in_stock = "false";
};
ObjectC::ObjectC(string name, string category, string des, string price, string in_stock) {
	m_data_product.m_name = name;
	m_data_product.m_category = category;
	m_data_product.m_des = des;
	m_price = price;
	m_in_stock = in_stock;
};


void ObjectC::getDataView() {
	cout << m_data_product.m_name << "," <<
		m_data_product.m_category << "," <<
		m_data_product.m_des << "," <<
		m_price << "," <<
		m_in_stock << endl;
};

//геттеры
string ObjectC::getName() { return m_data_product.m_name; };
string ObjectC::getCategory() { return m_data_product.m_category; };
string ObjectC::getDes() { return m_data_product.m_des; };
string ObjectC::getPrice() { return m_price; };
string ObjectC::getInStock() { return m_in_stock; };

//сеттеры
void ObjectC::setName(string name) { m_data_product.m_name = name; };
void ObjectC::setCategory(string category) { m_data_product.m_category = category; };
void ObjectC::setDes(string des) { m_data_product.m_des = des; };
void ObjectC::setPrice(string price) { m_price = price; };
void ObjectC::setInStock(string in_stock) { m_in_stock = in_stock; };