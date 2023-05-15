// Name:   Maaz Saiyed
// Seneca Student ID:   113485205
// Seneca email:   mmmsaiyed@myseneca.ca
// Date of completion:   10-04-2022
//
// I confirm that the only author of this file
//   and the content was created entirely by me.

#pragma once
#ifndef STATION_H
#define STATION_H

#include <string>

using namespace std;

namespace sdds
{
    class Station
    {
        int id;
        string name;
        string description;
        unsigned int nextSerialNum;
        unsigned int numItems;

        static size_t m_widthField;
        static int id_generator;

    public:
        Station(const string& record);
        const string& getItemName() const;
        size_t getNextSerialNumber();
        size_t getQuantity() const;
        void updateQuantity();
        void display(ostream& os, bool full) const;
    };
};


#endif