// Name:   Maaz Saiyed
// Seneca Student ID:   113485205
// Seneca email:   mmmsaiyed@myseneca.ca
// Date of completion:   10-04-2022
//
// I confirm that the only author of this file
//   and the content was created entirely by me.

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <utility>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;
using namespace sdds;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() :
    m_name{}, m_product{}, m_cntItem{}, m_lstItem{ nullptr } {

}

CustomerOrder::CustomerOrder(const string& input)
{
    Utilities utility;
    size_t pos = 0;
    bool more = true;

    m_name = utility.extractToken(input, pos, more);
    m_product = utility.extractToken(input, pos, more);

    string listOfItems = "";
    size_t count = 0;

    do
    {
        string tmp = utility.extractToken(input, pos, more);
        if (listOfItems.length() > 0)
        {
            listOfItems += Utilities::getDelimiter();
        }
        listOfItems += tmp;
        count++;
    } while (more);

    m_lstItem = new Item * [count];
    m_cntItem = count;
    pos = 0;
    count = 0;
    more = true;

    do
    {
        string tmp = utility.extractToken(listOfItems, pos, more);
        m_lstItem[count++] = new Item(tmp);
    } while (more);

    if (m_widthField < utility.getFieldWidth())
    {
        m_widthField = utility.getFieldWidth();
    }
}

CustomerOrder::CustomerOrder(const CustomerOrder& order)
{
    throw string("Copy constructor cannot be called");
}

CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept :
    m_name{}, m_product{}, m_cntItem{}, m_lstItem{ nullptr } {
    *this = move(order);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept
{
    if (this == &order)
    {
        return *this;
    }

    swap(m_name, order.m_name);
    swap(m_product, order.m_product);
    swap(m_cntItem, order.m_cntItem);
    swap(m_lstItem, order.m_lstItem);

    return *this;
}

CustomerOrder::~CustomerOrder()
{
    for (size_t i = 0; i < m_cntItem; i++)
    {
        delete m_lstItem[i];
    }

    delete[] m_lstItem;
}

bool CustomerOrder::isOrderFilled() const
{
    size_t count = 0;

    for (size_t i = 0; i < m_cntItem; i++)
    {
        if (m_lstItem[i]->m_isFilled)
        {
            count++;
        }
    }

    return count == m_cntItem;
}

bool CustomerOrder::isItemFilled(const string& itemName) const
{
    size_t itemCount = 0;
    size_t filledCount = 0;

    for (size_t i = 0; i < m_cntItem; i++)
    {
        if (m_lstItem[i]->m_itemName == itemName)
        {
            itemCount++;

            if (m_lstItem[i]->m_isFilled)
            {
                filledCount++;
            }
        }
    }

    return itemCount == filledCount;
}

void CustomerOrder::fillItem(Station& station, ostream& os)
{
    for (size_t i = 0; i < m_cntItem; i++)
    {

        if (m_lstItem[i]->m_isFilled == false && m_lstItem[i]->m_itemName == station.getItemName())
        {

            if (station.getQuantity() > 0)
            {

                m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                m_lstItem[i]->m_isFilled = true;
                station.updateQuantity();
                os << setw(11) << right;
                os << "Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
                break;

            }
            else
            {

                os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;

            }
        }
    }


}

void CustomerOrder::display(ostream& os) const
{
    os << m_name << " - " << m_product << endl;

    for (size_t i = 0; i < m_cntItem; i++)
    {
        os << std::right;
        os << "[" << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
        os << setfill(' ') << left;
        os << setw(m_widthField + 2) << m_lstItem[i]->m_itemName << " - ";
        os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED");
        os << endl;
    }
}
