

#ifndef _Bill_H
#define _Bill_H

#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;
class Bill
{
public:
    /* data */
 vector<string> ProductName;        
 vector<int> ProductNumber;
 vector<double> Demand;
 vector<string> Status;
 vector<double> Price;

public:
     Bill();
     vector <int> get_ProductNumber();
     vector <double> get_Demand();
     vector <double> get_Price();
     vector <string> get_ProductName();
     vector <string>  get_status();
     void read_data_set();
     double get_product_price(int);
     string get_product_name(int);
     void display_bill();
     void get_details(Bill);
      ~Bill();
};

#endif

