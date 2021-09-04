#include "Bill.h"
#include <gtest/gtest.h>

TEST(Bill, ProductName){   
    Bill csv;
    csv.read_data_set();
    EXPECT_EQ("NULL",csv.get_product_name(0)); 
    EXPECT_EQ("Soap",csv.get_product_name(1));
    EXPECT_EQ("Shampoo",csv.get_product_name(101));
    EXPECT_EQ("Salt",csv.get_product_name(201));
    EXPECT_EQ("Sugar",csv.get_product_name(301));
    EXPECT_EQ("Tooth Paste",csv.get_product_name(401));
 } 

TEST(Bill, Price){   
    Bill csv;
    csv.read_data_set();
    EXPECT_EQ(0,csv.get_product_price(0)); 
    EXPECT_EQ(25.5,csv.get_product_price(1));
    EXPECT_EQ(25.51,csv.get_product_price(101));
    EXPECT_EQ(25.52,csv.get_product_price(201));
    EXPECT_EQ(25.53,csv.get_product_price(301));
    EXPECT_EQ(25.54,csv.get_product_price(401));
 } 

TEST(Bill, get_ProductNumber)        
{   Bill csv;
    csv.read_data_set();
    vector <int> pNo =  csv.get_ProductNumber();
    ASSERT_EQ(1,pNo[0]); 
    ASSERT_EQ(2,pNo[1]);
    ASSERT_EQ(3,pNo[2]);
} 
TEST(Bill, get_ProductName)        
{   Bill csv;
    csv.read_data_set();
    vector <string> ProductName= csv.get_ProductName();
    ASSERT_EQ("Soap",ProductName[0]); 
    ASSERT_EQ("Soap",ProductName[1]);
    ASSERT_EQ("Soap",ProductName[2]);
} 
TEST(Bill, get_Price)        
{   Bill csv;
    csv.read_data_set();
    vector <double> price =  csv.get_Price();
    ASSERT_EQ(25.5,price[0]); 
    ASSERT_EQ(25.6,price[1]);
    ASSERT_EQ(25.7,price[2]);
} 

TEST(Bill, get_status)        
{   Bill csv;
    csv.read_data_set();
    vector <string> status =  csv.get_status();
    ASSERT_EQ("Available",status[0]); 
    ASSERT_EQ("Available",status[1]);
    ASSERT_EQ("Available",status[2]);
} 

TEST(Bill, get_Demand)        
{   Bill csv;
    csv.read_data_set();
    vector <double> demand =  csv.get_Demand();
    ASSERT_EQ(50,demand[0]); 
    ASSERT_EQ(60,demand[1]);
    ASSERT_EQ(70,demand[2]);
} 