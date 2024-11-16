/*
NAME : SAKSHI SANDEEP CHAVAN 
ROLL NO.: 68
CLASS : SE COMP-II(R BATCH)

PROBLEM STATEMENT:
Write c++ program that creates an output file, write information to it,closes the file and open it again
 as input file and read the information from the file.
*/
#include<iostream>
#include<fstream>
using namespace std;
class Employee              // declaring class employee
{
 string Name;
 int ID;
 double salary;
 public:
 void accept()
 {
 cout<<"\n Name : ";
 cin.ignore();
getline(cin,Name);
 cout<<"\n Id : ";
 cin>>ID;
 cout<<"\n Salary : ";
 cin>>salary;
 }
 void display()
 {
 cout<<"\n Name : "<<Name;
 cout<<"\n Id : "<<ID;
 cout<<"\n Salary : "<<salary<<endl;
 }
};

int main()
{
 Employee o[5];
 fstream f;
 int i,n;

 f.open("demo.txt",ios::out);                                        // open file 
 cout<<"\n Enter the number of employees you want to store : ";
 cin>>n;
 for(i=0;i<n;i++)
 {
 cout<<"\n Enter information of Employee "<<i+1<<"\n";              // write info 
 o[i].accept();
 f.write((char*)&o[i],sizeof o[i]);
 }

 f.close();                                                        //close the file 

 f.open("demo.txt",ios::in);                                        // open the file 
 cout<<"\n Information of Employees is as follows : \n";            
 for(i=0;i<n;i++)
 {
 cout<<"\nEmployee "<<i+1<<"\n";                                     //read info 
 f.write((char*)&o[i],sizeof o[i]);
 o[i].display();                                                    // display 
 }
 f.close();                                                    // close the file 
 
 return 0;
}
