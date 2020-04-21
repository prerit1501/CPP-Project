#include<bits/stdc++.h>
using namespace std;
struct date
 {
   int year,month,day;
 };
   void enter_date(date &d )
   {
     cout<<"\nPlease enter the date in dd:mm:yy format"<<endl;
     cout<<"Enter the date :"<<endl;
     cin>>d.day;
     cout<<"Enter the month :"<<endl;
     cin>>d.month;
     cout<<"Enter the year :"<<endl;
     cin>>d.year;
   }
   void show_date(date d)
   {
     cout<<d.day<<" : "<<d.month<<" : "<<d.year<<endl;
   }


class student
 {
   char name[30],class_student[10];
   int addmission_number;
   date date_of_birth;
   public:
   student()
   {
     strcpy(name," ");
     strcpy(class_student," ");
     addmission_number=0;
   }
   void display_data()
   {
     cout<<"The name of the student is :";
     puts(name);
     cout<<"The class and section of the student is :";
     puts(class_student);
     cout<<"The addmission number of the student is :"<<addmission_number<<endl;
     cout<<"The date of birth of the student is :"<<endl;
     show_date(date_of_birth);
   }
    void add_data()
    {
    char ch;
    do
      {
	cout<<"Enter the name of the student :"<<endl;
    cin>>name;
	cout<<"Enter the class and section of student :"<<endl;
	cin>>(class_student);
	cout<<"Enter the date of birth of student :"<<endl;
	enter_date(date_of_birth);
	cout<<"Enter the admission number of the student :"<<endl;
	cin>>addmission_number;
	display_data();
	cout<<"Do you want to make any changes ?(y/n)"<<endl;
	cin>>ch;
      }
    while(ch=='y');
    }
    int return_addmission_number()
    {
      return(addmission_number);
    }
    void editor()
    {
      cout<<"The current data is :"<<endl;
      display_data();
      cout<<"Please make the necessary changes";
      add_data();
    }
 };