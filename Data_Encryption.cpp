#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class File_base
{
  protected:
    char file_name[30];
  public:
  
    //Making base class Abstract by giving virtual functions
    
    virtual int input() = 0;
    virtual void validate_extension() = 0;
    virtual void encrypt() = 0;
    virtual void decrypt() = 0;
};
class File_processor : public File_base
{
  private:
    int key_value;
    int flag = 0;
    char content[100];
  public:
    int input()
    {
      cout<<"Enter filename: ";
      cin.getline(file_name,30);
      validate_extension(); //calling function to validate the extension file
      if(flag == 1)
      {
        cout<<"Enter content(# to end): ";
        cin.getline(content,100,'#');
        ofstream outfile(file_name,ios::out); //New object of ofstream class
        outfile<<content; //Write the content into the file
        encrypt();
        decrypt();
      }
      else
      {
        cout<<"File must have one of the following extension(.txt or .dat)"<<endl;
        exit;
      }
      return 0;
    }
    void validate_extension()
    {
      char filebasename[30],extension[10];
      int j,i=0;
      while(file_name[i]!='.') //checks till '.' in filename(eg: student.txt)
      {
        filebasename[i] = file_name[i]; //stores the characters into another string of chars
        i++;
      }
      filebasename[i] = '\0';
      j = i; //Resets the j variable to i to continue from '.'
      cout<<"File base name: "<<filebasename<<endl;
      while(file_name[j]!='\0')
      {
        extension[j-i] = file_name[j]; //stores the extension string into another one
        j++;
      }
      extension[j-i] = '\0';
      cout<<"Extension: "<<extension<<endl;
      if(strcmp(extension,".txt") == 0 || strcmp(extension,".dat") == 0) //validating the extensions
      {
        flag = 1;
      }
      else
      {
        flag = 0;
      }
    }
    void encrypt()
    {
      cout<<"Enter a key value to be encrypted with: ";
      cin>>key_value;
      if(key_value < 1 || key_value > 9) //Validating key value
      {
        cout<<"Key value must be between 1 and 9(inclusively)!!"<<endl;
        exit;
      }
      else
      {
        int i=0;
        char encrypted_content[100];
        while(content[i]!='\0')
        {
          char current_char = content[i];
          if(current_char==' ')
          {
            encrypted_content[i] = '$';
            i++;
          }
          else
          {
            encrypted_content[i] = current_char + key_value;  //Encrypting the data
            i++;
          }
        }
        encrypted_content[i] = '\0';
        cout<<"Encrypted file: "<<endl;
        ofstream efile("filename_e.txt",ios::out);
        efile<<encrypted_content<<endl; //Writing the encrypted data to a new file
        cout<<encrypted_content<<endl;
      }
    }  
    void decrypt()
    {
      int i=0;
      char content[100];
      char decrypted_content[100];
      ifstream ifile("filename_e.txt",ios::in);  //Reading the encrypted data from the new file
      while(!ifile.eof())
      {
          ifile>>content;
      }
      while(content[i]!='\0')
      {
          char current_char = content[i];
          if(current_char == '$')
          {
            decrypted_content[i] = ' ';
            i++;
          }
          else
          {
            decrypted_content[i] = current_char - key_value;  //Decrypting the data
            i++;
          }
      }
      decrypted_content[i] = '\0';
      cout<<"Decrypted file: "<<endl;
      ofstream dfile("filename_d.txt",ios::out);
      dfile<<decrypted_content<<endl;  //Writing the decrypted data into new file
      cout<<decrypted_content<<endl;
    }
};
int main()
{
  File_base *ptr;  //Base class pointer instatiated
  File_processor F; //Object of derived class
  ptr = &F;   //Base class pointer pointing to derived class object 
  ptr -> input();  //calling derived class member function
  return 0;
}