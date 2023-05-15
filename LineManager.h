// Name:   Maaz Saiyed
// Seneca Student ID:   113485205
// Seneca email:   mmmsaiyed@myseneca.ca
// Date of completion:   10-04-2022
//
// I confirm that the only author of this file
//   and the content was created entirely by me.

#pragma once
#ifndef SDDS_LINE_MANAGER_H
#define SDDS_LINE_MANAGER_H

#include <string>
#include <vector>
#include <iostream>
#include "Workstation.h"

using namespace std;

namespace sdds
{
    class LineManager
    {
        vector<Workstation*> m_activeLine;
        size_t m_cntCustomerOrder;
        Workstation* m_firstStation;

    public:
        LineManager(const string& file, const vector<Workstation*>& stations);
        void reorderStations();
        bool run(ostream& os);
        void display(ostream& os) const;
    };
};

#endif