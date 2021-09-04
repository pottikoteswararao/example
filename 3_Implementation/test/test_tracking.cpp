

#include "tracking.h"

#include <gtest/gtest.h>

/**
 * @brief Testing empty constructor
 * 
 */
TEST(Data, Empty_Constructor)
{
  Data a;
  EXPECT_EQ("Null", a.getProductName());
  EXPECT_EQ(0, a.getProductNum());
  EXPECT_FLOAT_EQ(0, a.getDemand());
  EXPECT_EQ("Unavailable", a.getState());
  EXPECT_FLOAT_EQ(0.0, a.getQuantity());
}

/**
 * @brief Testing parameterised constructor
 * 
 */
TEST(Data, Param_Constructor)
{
  Data a("Soap", 20, 50, "Unavailable", 20.1);
  EXPECT_EQ("Soap", a.getProductName());
  EXPECT_EQ(20, a.getProductNum());
  EXPECT_FLOAT_EQ(50, a.getDemand());
  EXPECT_EQ("Unavailable", a.getState());
  EXPECT_FLOAT_EQ(20.1, a.getQuantity());
}

/**
 * @brief Testing stringToObject function
 * 
 */
TEST(Data, stringToObject)
{
  Data a = stringToObject("Shampoo,101,50.1,Available,25.51");
  EXPECT_EQ("Shampoo", a.getProductName());
  EXPECT_EQ(101, a.getProductNum());
  EXPECT_FLOAT_EQ(50.1, a.getDemand());
  EXPECT_EQ("Available", a.getState());
  EXPECT_FLOAT_EQ(25.51, a.getQuantity());
}

/**
 * @brief Testing highestDemandConsumer function
 * 
 */
TEST(Data, highestDemandConsumer)
{
  vector<Data> testInventory;
  Data a = stringToObject("Shampoo,101,50.1,Available,25.51");
  Data b = stringToObject("Soap,5,90.5,Unavailable,35.6");
  Data c = stringToObject("Sugar,403,70.4,Available,25.74");
  testInventory.push_back(a);
  testInventory.push_back(b);
  testInventory.push_back(c);
  EXPECT_EQ(5, highestDemandConsumer(testInventory));
}

/**
 * @brief Testing highestProductQuantity function
 * 
 */
TEST(Data, highestProductQuantity)
{
  vector<Data> testInventory;
  Data a = stringToObject("Shampoo,101,50.1,Available,25.51");
  Data b = stringToObject("Soap,5,90.5,Unavailable,35.6");
  Data c = stringToObject("Sugar,403,70.4,Available,25.74");
  testInventory.push_back(a);
  testInventory.push_back(b);
  testInventory.push_back(c);
  EXPECT_EQ(5, highestProductQuantity(testInventory));
}


/**
 * @brief Testing productStatusAvailable function
 * 
 */
TEST(Data, productStatusAvailable)
{
  vector<Data> testInventory, resultInventory, expectedResultInventory;
  string testStr = "Soap";
  Data a = stringToObject("Shampoo,101,50.1,Available,25.51");
  Data b = stringToObject("Soap,5,90.5,Unavailable,35.6");
  Data c = stringToObject("Sugar,403,70.4,Available,25.74");
  Data d = stringToObject("Soap,1,50,Available,25.5");
  Data e = stringToObject("Soap,2,60,Available,25.6");
  Data f = stringToObject("Soap,3,70,Available,25.7");
  Data g = stringToObject("Soap,100,80,Unavailable,65");
  Data h = stringToObject("Soap,5,90.5,Unavailable,35.6");
  testInventory.push_back(a);
  testInventory.push_back(b);
  testInventory.push_back(c);
  testInventory.push_back(d);
  testInventory.push_back(e);
  testInventory.push_back(f);
  testInventory.push_back(g);
  testInventory.push_back(h);
  
  expectedResultInventory.push_back(d);
  expectedResultInventory.push_back(e);
  expectedResultInventory.push_back(f);

  resultInventory = productStatusAvailable(testInventory, testStr);
  for (int i = 0; i < expectedResultInventory.size(); ++i)
  {
   EXPECT_EQ(expectedResultInventory[i].getProductName(), resultInventory[i].getProductName());
   EXPECT_EQ(expectedResultInventory[i].getProductNum(), resultInventory[i].getProductNum());
   EXPECT_EQ(expectedResultInventory[i].getDemand(), resultInventory[i].getDemand());
   EXPECT_EQ(expectedResultInventory[i].getState(), resultInventory[i].getState());
   EXPECT_EQ(expectedResultInventory[i].getQuantity(), resultInventory[i].getQuantity());
  }
}

/**
 * @brief Testing productStatusUnavailable function
 * 
 */
TEST(Data, productStatusUnavailable)
{
  vector<Data> testInventory, resultInventory, expectedResultInventory;
  int minimumQuantity = 30;
  Data a = stringToObject("Shampoo,101,50.1,Available,25.51");
  Data b = stringToObject("Soap,5,90.5,Unavailable,35.6");
  Data c = stringToObject("Sugar,403,70.4,Available,25.74");
  Data d = stringToObject("Soap,1,50,Available,25.5");
  Data e = stringToObject("Soap,2,60,Available,25.6");
  Data f = stringToObject("Soap,3,70,Available,25.7");
  Data g = stringToObject("Soap,100,80,Unavailable,65");
  Data h = stringToObject("Salt,204,80.2,Unavailable,35.52");
  testInventory.push_back(a);
  testInventory.push_back(b);
  testInventory.push_back(c);
  testInventory.push_back(d);
  testInventory.push_back(e);
  testInventory.push_back(f);
  testInventory.push_back(g);
  testInventory.push_back(h);
  
  expectedResultInventory.push_back(b);
  expectedResultInventory.push_back(g);
  expectedResultInventory.push_back(h);

  resultInventory = productStatusUnavailable(testInventory, minimumQuantity);
  for (int i = 0; i < expectedResultInventory.size(); ++i)
  {
   EXPECT_EQ(expectedResultInventory[i].getProductName(), resultInventory[i].getProductName()); 
   EXPECT_EQ(expectedResultInventory[i].getProductNum(), resultInventory[i].getProductNum()); 
   EXPECT_EQ(expectedResultInventory[i].getDemand(), resultInventory[i].getDemand()); 
   EXPECT_EQ(expectedResultInventory[i].getState(), resultInventory[i].getState()); 
   EXPECT_EQ(expectedResultInventory[i].getQuantity(), resultInventory[i].getQuantity());
  }
}
 
 /**
  * @brief testing the function productsAboutToFinish
  * 
  */
TEST(Data, productsAboutToFinish){
   vector<Data> testInventory, resultInventory, expectedResultInventory;
  int minimumQuantity = 30;
  Data a = stringToObject("Shampoo,101,50.1,Available,15.51");
  Data b = stringToObject("Soap,5,90.5,Unavailable,35.6");
  Data c = stringToObject("Sugar,403,70.4,Available,12.74");
  Data d = stringToObject("Soap,1,50,Available,25.5");
  Data e = stringToObject("Soap,2,60,Available,17.6");
  Data f = stringToObject("Soap,3,70,Available,25.7");
  Data g = stringToObject("Soap,100,80,Unavailable,65");
  Data h = stringToObject("Salt,204,80.2,Available,20.00");
  testInventory.push_back(a);
  testInventory.push_back(b);
  testInventory.push_back(c);
  testInventory.push_back(d);
  testInventory.push_back(e);
  testInventory.push_back(f);
  testInventory.push_back(g);
  testInventory.push_back(h);
  
  expectedResultInventory.push_back(a);
  expectedResultInventory.push_back(c);
  expectedResultInventory.push_back(e);
  expectedResultInventory.push_back(h);

  resultInventory = productsAboutToFinish(testInventory);
  for (int i = 0; i < expectedResultInventory.size(); ++i)
  {
   EXPECT_EQ(expectedResultInventory[i].getProductName(), resultInventory[i].getProductName()); 
   EXPECT_EQ(expectedResultInventory[i].getProductNum(), resultInventory[i].getProductNum()); 
   EXPECT_EQ(expectedResultInventory[i].getDemand(), resultInventory[i].getDemand()); 
   EXPECT_EQ(expectedResultInventory[i].getState(), resultInventory[i].getState()); 
   EXPECT_EQ(expectedResultInventory[i].getQuantity(), resultInventory[i].getQuantity());
  }
}

/**
 * @brief main function
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)
{
  readCSV();
  printResults();
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
