//Mini Tollbooth application

#include<iostream>
using namespace std;
class Tollbooth
{
  int totalCars;
  double totalCash;
  public:
    Tollbooth():totalCars(0),totalCash(0){}
    void payingCar()
    {
      totalCars++;
      totalCash += 0.50;
    }
    void noPayCar()
    {
      totalCars++;
    }
    void display()
    {
      cout<<"Total cars passed by: "<<totalCars<<endl;
      cout<<"Total cash collected: "<<totalCash<<endl;
    }
};
int main()
{
  Tollbooth T; //Object of Tollbooth class created
  char ch;
  cout<<"Choose one"<<endl; //Menu driven
  cout<<"P for Paying car"<<endl;
  cout<<"N for Non-paying car"<<endl;
  cout<<"D for Displaying totals"<<endl;
  cout<<"Q for quitting application"<<endl;
  do
  {
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 'P':
      case 'p': T.payingCar(); //Adds a paying car
                cout<<"Paying car added!"<<endl;
                break;
      case 'N':
      case 'n': T.noPayCar(); //Adds a non paying car
                cout<<"Non-paying car added!"<<endl;
                break;
      case 'D':
      case 'd': T.display(); //Display totals of two functions
                break;
      case 'Q':
      case 'q': cout<<"Exiting......";
                exit(0); //Exits when pressed q or Q
      default: cout<<"Invalid option"<<endl;
    }
  }while(ch!='Q' || ch!='q'); //Loop until user exits manually by pressing Q or q.
  return 0;
}