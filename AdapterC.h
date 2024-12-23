#pragma once
#include "Product.h"
#include "AdapterAll.h"
#include "ModuleC.h"
#include <iostream>
class AdapterC: public AdapterAll
{
private:
    ModuleC m_moduleC;

    Product parseProduct(ObjectC& objC){
        Product product;
        string name, category, des, price, in_stock;
        name = objC.getName(), category = objC.getCategory(), des = objC.getDes();
        price = objC.getPrice(), in_stock = objC.getInStock();
        if (name == "" || category == "" || price == "" || des == "" || in_stock == "") {
            std::cerr << "Ошибка при парсинге ModuleC, один из параметров пуст!, данные: ";
            objC.getDataView();
            return product;
        }
        if (in_stock != "true" && in_stock != "false") {
            std::cerr << "Ошибка при парсинге ModuleC! параметр 'Наличие на складе' неправильно указан!, Данные: ";
            objC.getDataView();
            return product;
        }
        try
        {
            double test = stod(price);
        }
        catch (...)
        {
            std::cerr << "Ошибка при парсинге ModuleC! цена неправильна указана на товар!, индекс словарая: ";
            objC.getDataView();
            return product;
        }

        product.setName(name);
        product.setCategory(category);
        product.setDes(des);
        product.setPrice(stod(price));
        product.setInStock(in_stock == "true");

        return product;
    }
public:
    AdapterC(ModuleC& mdC) : m_moduleC(mdC) {};
    std::vector<Product> getAllProducts() override {
        std::vector<Product> products;
        for (auto& objC : m_moduleC.getData()) {
            Product product = parseProduct(objC);
            if(product.getName()!=""){ products.push_back(product); }
        }
        return products;
    }
};

