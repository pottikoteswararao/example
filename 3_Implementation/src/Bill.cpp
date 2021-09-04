#include "Bill.h"
Bill::Bill(){

}
    vector <int> Bill::get_ProductNumber(){
          return ProductNumber;
     }
    vector <double>Bill::get_Demand(){
         return Demand;

     }
    vector <double> Bill::get_Price(){
         return Price;

     }
     vector <string> Bill::get_ProductName(){
         return ProductName;

     }
     vector <string> Bill:: get_status(){
         return Status;
     }
  void Bill::read_data_set(){
         fstream file;
         file.open("data.csv", ios::in);
         vector<string> row;
         string line;
         while(getline(file,line)){
            string bit;            
            stringstream linestream(line);
            while(getline(linestream,bit,',')){
               row.push_back(bit);
            }
            ProductName.push_back(row[0]);
            ProductNumber.push_back(stoi(row[1]));
            Demand.push_back(stod(row[2]));
            Status.push_back(row[3]);
            Price.push_back(stod(row[4]));
             
            row.clear(); 
           /*cout<<row[0];
            cout<<row[1];
            cout<<row[2];
            cout<<row[3];
            cout<<row[4]<<endl;
           */
        }
           
          /*  cout<<ProductName[0];
            cout<<ProductNumber[1];
            cout<<Price[4];
            cout<<Status[3];
            cout<<Demand[4]<<endl;  
           */
}
vector<int> pprice;
double Bill::get_product_price(int ProductNo){
  for(int it=0;it<ProductNumber.size();it++){
      if(ProductNumber[it]==ProductNo){
          pprice.push_back(Price[it]);
          return Price[it];
      }
   }
   return 0;
}
vector<string> pName;
string Bill::get_product_name(int ProductNo){
  for(int it=0;it<ProductNumber.size();it++){
      if(ProductNumber[it]==ProductNo){
          pName.push_back(ProductName[it]);
          return ProductName[it];
      }
   }
 return "NULL";
}

void Bill::display_bill(){
  int tprice=0;
  cout<<"---------------"<<endl;
  cout<<"     BILL      "<<endl;
  cout<<"---------------"<<endl;
  cout<<"Product\t"<<"Price"<<endl;
  for(int i=0;i<pName.size();i++){
    cout<<pName[i]<<"\t"<<pprice[i]<<endl;
    tprice+=pprice[i];
  }
   cout<<"---------------"<<endl;
   cout<<"total\t"<<tprice<<endl;
   cout<<"---------------"<<endl;
   pprice.clear();
   pName.clear();
}

void Bill::get_details(Bill b){
  int id;
   b.read_data_set();
   do{
     cout<<"Enter Product Number:";
     cin>>id;
     cout<<b.get_product_name(id)<<"\t"<<b.get_product_price(id)<<endl;
   }while(id!=0);
   b.display_bill();
}

Bill::~Bill()
{
}
/*
int main(){
   int id;
   Bill b;
   b.get_details(b);
   
  return 0;
}
*/