//Program to calculate Frobenius norm
//Frobenius form = square root of sum of squares of all the matrix entries.

#include<iostream>
#include<conio.h>
#include<math.h> //For square root calculations
using namespace std;
int main()
{
  int row_size,col_size; //Frobenius works on matrices
  cout<<"Enter row size: "; //Defining sizes of matrix
  cin>>row_size;
  cout<<"Enter column size: ";
  cin>>col_size;
  int a[row_size][col_size];
  cout<<"Enter array elements: ";
  for(int i=0;i<row_size;i++) //Reading elements of matrix
  {
    for(int j=0;j<col_size;j++)
      cin>>a[i][j];
  }
  int sum = 0; //Initializing sum to 0
  for(int i=0;i<row_size;i++)
  {
    for(int j=0;j<col_size;j++)
    {
      sum = sum + (a[i][j] * a[i][j]); //Calculating the sum of squares of all elements using a for loop
    }
  }
  double result = sqrt(sum); //calculating square root of the obtained sum and initializing to a new variable
  cout<<"Matrix: "<<endl;
  for(int i=0;i<row_size;i++)
  {
    for(int j=0;j<col_size;j++)
      cout<<a[i][j]<<" "; //Printing the matrix
    cout<<endl;
  }
  cout<<endl;
  cout<<"Frobenius norm of Matrix: "<<result<<endl; //Printing the Frobenius norm of Matrix answer
}