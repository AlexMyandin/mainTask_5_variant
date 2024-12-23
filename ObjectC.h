#pragma once
#include <string>
#include <iostream>
using namespace std;

struct My_struct {
	string m_name;
	string m_category;
	string m_des;
};
class ObjectC
{
private:
	My_struct m_data_product;
	string m_price;
	string m_in_stock;
public:
	ObjectC();
	ObjectC(string name,string category,string des,string price, string in_stock);

	void getDataView();

	//геттеры
	string getName();
	string getCategory();
	string getDes();
	string getPrice();
	string getInStock();

	//сеттеры
	void setName(string name);
	void setCategory(string category);
	void setDes(string des);
	void setPrice(string price);
	void setInStock(string in_stock);
};

