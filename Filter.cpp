#include "Filter.h"

Filter::Filter(vector<Product> products): m_products(products) {};
vector<Product> Filter::getProductsByFilter(vector<string>& categoryies, size_t in_stock) {
	vector<Product> result;
	if (in_stock == -1){
		for (auto& pr: m_products)
		{
			for (auto& category: categoryies)
			{
				if (pr.getCategory() == category) { result.push_back(pr);break; }
			}
		}
	}
	if (in_stock == 1) {
		for (auto& pr : m_products)
		{
			for (auto& category : categoryies)
			{
				if (pr.getCategory() == category && pr.getInStock()==true) { result.push_back(pr); break; }
			}
		}
	}
	if (in_stock == 0) {
		for (auto& pr : m_products)
		{
			for (auto& category : categoryies)
			{
				if (pr.getCategory() == category && pr.getInStock() == false) { result.push_back(pr); break; }
			}
		}
	}
	return result;
};

vector<Product> Filter::getProducts() { return m_products; };
void Filter::setProducts(vector<Product> products) { m_products = products; };