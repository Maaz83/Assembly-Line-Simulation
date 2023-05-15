// Name:   Maaz Saiyed
// Seneca Student ID:   113485205
// Seneca email:   mmmsaiyed@myseneca.ca
// Date of completion:   10-04-2022
//
// I confirm that the only author of this file
//   and the content was created entirely by me.

#pragma once
#ifndef SDDS_CUSTOMER_ORDER_H
#define SDDS_CUSTOMER_ORDER_H

#include "Station.h"

using namespace std;

namespace sdds
{
    struct Item
    {
        string m_itemName;
        size_t m_serialNumber{ 0 };
        bool m_isFilled{ false };

        Item(const string& src) : m_itemName(src)
        {
        };
    };

    class CustomerOrder
    {
        string m_name;
        string m_product;
        size_t m_cntItem;
        Item** m_lstItem;
        static size_t m_widthField;

    public:
        CustomerOrder();
        CustomerOrder(const string& input);
        CustomerOrder(const CustomerOrder& order);
        CustomerOrder& operator=(const CustomerOrder& order) = delete;
        CustomerOrder(CustomerOrder&& order) noexcept;
        CustomerOrder& operator=(CustomerOrder&& order) noexcept;
        ~CustomerOrder();
        bool isOrderFilled() const;
        bool isItemFilled(const string& itemName) const;
        void fillItem(Station& station, ostream& os);
        void display(ostream& os) const;

    };
};

#endif