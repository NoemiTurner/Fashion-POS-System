//----------------------------------------------------------------------
// Name: Noemi Turner
// File: fashion_project.h
// Date: Summer 2021
// Desc: fashion business software project
//----------------------------------------------------------------------

#ifndef FASHION_PROJECT_H
#define FASHION_PROJECT_H

#include <iostream>
#include <string>
using namespace std;

class FashionSoftware
{
public:
    // default constructor is implied

    // default destructor
    virtual ~FashionSoftware() {};
    
    virtual void display_main_menu(string company_name);

private:
    // private member variables and functions go here

};

#endif