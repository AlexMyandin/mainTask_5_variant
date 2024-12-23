#pragma once
#include "Product.h"
#include <vector>
#include <string>
using namespace std;
class Filter
{
private:
	vector<Product> m_products;
public:
	Filter(vector<Product> products);
	vector<Product> getProductsByFilter(vector<string>& categoryies, size_t in_stock = -1);

	vector<Product> getProducts();
	void setProducts(vector<Product> products);
};

