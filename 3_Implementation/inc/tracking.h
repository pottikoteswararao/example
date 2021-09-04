
#ifndef _TRACKING_H
#define _TRACKING_H

/*Include files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>


using namespace std; 

/**
 * @brief class Data definition
 * 
 */

class Data
{
	/**private members*/
private:
	string productName;
    int productNumber;
    float demand;
    string state;
    float productQuantity;

	/*public members*/
public:
	/*empty constructor*/
	Data():
		productName("Null"), productNumber(0), demand(0.0), state("Unavailable"), productQuantity(0.0){};

	/*parameterised constructor*/
	Data(string prodName, int num, float dem, string st, float quant):
		productName(prodName), productNumber(num), demand(dem), state(st), productQuantity(quant){};

	/**
	 * @brief Get the product Name
	 * 
	 * @return string 
	 */
	string getProductName()
	{ 
		return productName; 
	}
	
	/**
	 * @brief Get the Product Number 
	 * 
	 * @return int 
	 */
	int getProductNum()
	{ 
		return productNumber; 
	}
	
	/**
	 * @brief Get the demand 
	 * 
	 * @return float 
	 */
	float getDemand()
	{ 
		return demand; 
	}
	
	/**
	 * @brief Get the State
	 * 
	 * @return string 
	 */
	string getState()
	{ 
		return state; 
	}
	
	/**
	 * @brief Get the Quantity
	 * 
	 * @return float 
	 */
	float getQuantity()
	{ 
		return productQuantity; 
	}	

};

/**
 * @brief Function prototypes
 * 
 */
void printResults();

int readCSV();

Data stringToObject(string);

int highestDemandConsumer(vector<Data>);

int highestProductQuantity(vector<Data>);

vector<Data> productStatusAvailable(vector<Data>,string);

vector<Data> productStatusUnavailable(vector<Data>,int);

vector<Data> productsAboutToFinish(vector<Data>);

#endif //_TRACKING_H

