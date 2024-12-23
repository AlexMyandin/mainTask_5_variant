#pragma once
#include <vector>
#include "Product.h"
class AdapterAll
{
public:
	virtual std::vector<Product> getAllProducts()= 0;
	virtual ~AdapterAll() = default;
};

