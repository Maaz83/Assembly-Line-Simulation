// Name:   Maaz Saiyed
// Seneca Student ID:   113485205
// Seneca email:   mmmsaiyed@myseneca.ca
// Date of completion:   10-04-2022
//
// I confirm that the only author of this file
//   and the content was created entirely by me.

#pragma once
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <string>
#include <stdexcept>

using namespace std;

namespace sdds
{
    class Utilities
    {
        size_t m_widthField = 1;
        static char m_delimiter;

    public:
        void setFieldWidth(size_t newWidth);
        size_t getFieldWidth() const;
        string extractToken(const string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter)
        {
            m_delimiter = newDelimiter;
        }
        static char getDelimiter()
        {
            return m_delimiter;
        }
    };
};

#endif