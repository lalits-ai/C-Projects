//Cake Loft application

//B Lalit Sai

#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
class cakeOrder
{
  protected:
    int orderno;
    char customerName[30];
    char flavour[20];
    float weight;
    int quantity;
    double price;
    char cakeType[50];
    time_t now = time(0);
    char *dt = ctime(&now);
  public:
    void getdata()
    {
      cout<<"Enter order number: ";
      cin>>orderno;
      cout<<"Enter customer name: ";
      cin.ignore();
      cin.getline(customerName,30);
      cin.ignore();
      cout<<"Enter flavour: ";
      cin.getline(flavour,20);
      cout<<"Enter weight: ";
      cin>>weight;
      cout<<"Enter unit price: ";
      cin>>price;
      cout<<"Enter quantity required: ";
      cin>>quantity;
    }
    void setdata()
    {
      cout<<"Order#: "<<orderno<<endl;
      cout<<"Customer Name: "<<customerName<<endl;
      cout<<"Flavour: "<<flavour<<endl;
      cout<<"Weight: "<<weight<<endl;
      cout<<"Quantity: "<<quantity<<endl;
      cout<<"Price("<<quantity<<"*"<<price<<"): "<<quantity*price<<endl;
      cout<<"Time: "<<dt<<endl;
    }
    virtual void computePrice() = 0;
    virtual void printBill() = 0;
};
class TranquilTemptaion : public cakeOrder
{
  double total;
  int napkins;
  double wrappingCharges = 10.50;
  char cakeType[50] = "Tranquil Temptation";
  public:
    void computePrice()
    {
      cout<<"Enter napkins quantity: ";
      cin>>napkins;
      total = (quantity * price) + (napkins*2) + wrappingCharges;
      // cout<<"Total: "<<total<<endl;
    }
    void printBill()
    {
      cout<<setw(50)<<"Cake Loft"<<endl;
      cout<<setw(40)<<"Cake type: "<<cakeType<<endl;
      cout<<setw(40)<<"Order#: "<<orderno<<endl;
      cout<<setw(40)<<"Customer name: "<<customerName<<endl;
      cout<<setw(40)<<"Order quantity: "<<quantity<<endl;
      for(int i=0;i<100;i++)
        cout<<"-";
      cout<<endl;
      cout<<setw(15)<<"Name of cake"<<setw(30)<<"Flavour"<<setw(30)<<"Weight(in kgs)"<<setw(25)<<"Unit Price"<<endl;
      for(int i=0;i<100;i++)
        cout<<"-";
      cout<<endl;
      cout<<setw(15)<<cakeType<<setw(20)<<flavour<<setw(30)<<weight<<setw(20)<<price<<endl;
    }
};
class BirthdayBash : public cakeOrder
{
  double total;
  char customization;
  char cakeType[50] = "Birthday Bash";
  public:
    void computePrice()
    {
        cout<<"Customization required(y or n) : ";
        cin>>customization;
        if(customization == 'y')
        {
          total = (quantity * price) + (50*weight);
          cout<<"Total: "<<total<<endl;
        }
        else if(customization == 'n')
        {
          total = quantity * price;
          cout<<"Total: "<<total<<endl;
        }
    }
    void printBill()
    {
      cout<<"bill";
    }
};
class WishfulWedding : public cakeOrder
{
  double total;
  char customization;
  const double topPiece = 100;
  char cakeType[50] = "Wishful Wedding";
  public:
    void computePrice()
    {
      cout<<"Customization required(y or n): ";
      cin>>customization;
      if(customization == 'y')
      {
        total = (quantity*price) + (75.50*weight) + topPiece;
        cout<<"Total: "<<total<<endl;
      }
      else
      {
        total = (quantity * price) + topPiece;
        cout<<"Total: "<<total<<endl;
      }
    }
    void printBill()
    {
      cout<<"bill";
    }
};

int main()
{
  int ch,n;
  cout<<"Enter number of inputs: ";
  cin>>n;
  cakeOrder *ptr; //Base class pointer
  TranquilTemptaion TT[n];
  BirthdayBash BB[n];
  WishfulWedding WW[n];
  for(int i=0;i<n;i++)
  {
    cout<<"Choose cake type: "<<endl;
    cout<<"1. Tranquil Temptation \n";
    cout<<"2. Birthday Bash\n";
    cout<<"3. Wishful Wedding\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: ptr = &TT[i];
              ptr -> getdata();
              ptr -> setdata();
              ptr -> computePrice();
              ptr -> printBill();

              break;
      case 2: ptr = &BB[i];
              ptr -> getdata();
              ptr -> setdata();
              ptr -> computePrice();
              break;
      case 3: ptr = &WW[i];
              ptr -> getdata();
              ptr -> setdata();
              ptr -> computePrice();
              break;
      default: exit(0);
    }
  }
  return 0;

}