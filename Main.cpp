//Student Record Management System
#include<bits/stdc++.h>
#include<fstream>
#include"D:\CPP Project\Classes.cpp"

using namespace std;

 void add_data_for_students()
    {
    char ch;
    do
       {
       student temp;
       temp.add_data();
       ofstream temp_file("Stud.DAT");
       temp_file.write((char*)&temp,sizeof(temp));
       temp_file.close();
       cout<<"Do you want to add more data?(y/n)";
       cin>>ch;
       }
    while(ch=='y');
    }

   void search_data()
     {
     int a_no;
     cout<<"Enter the addmission number of student:"<<endl;
     cin>>a_no;
     ifstream fin("Stud.DAT",ios::binary);
     if(!fin)
	{
	cout<<"!!!Error!!!\nCannot open file";
	exit(0);
	}
     else
	{
	student temp;
	while(fin.read((char*)&temp,sizeof(temp)))
	   {
	   if((temp.return_addmission_number())==a_no)
	      {
	      temp.display_data();
	      break;
	      }
	   }
	fin.close();
	}
     }
void sort_data()
     {
     fstream fin("Stud.DAT");
     fstream temp_file("Tempo.DAT");
     student temp[100];
     int i=0;
     while(fin.read((char*)&temp[i],sizeof(temp[i])))
	  {
	  i++;
	  }
     for(int a=0;a<=i;a++)
	for(int b=0;b<=(i-a);b++)
	    {
	    if((temp[b].return_addmission_number())>(temp[b+1].return_addmission_number()))
	       {
	       student swapper=temp[b];
	       temp[b]=temp[b+1];
	       temp[b+1]=swapper;
	       }
	    }
      int j=0;
      while(temp_file.write((char*)&temp[j],sizeof(temp)))
	  {
	    j++;
	  }
      remove("Stud.DAT");
      rename("Tempo.DAT","Student Records.DAT");
      }
void edit_data()
     {
     int a_no;
     cout<<"Enter the addmission number of student:"<<endl;
     cin>>a_no;
     fstream fin("Stud.DAT");
     if(!fin)
	{
	cout<<"!!!Error!!!\nCannot open file";

	exit(0);
	}
     else
	{
	student temp;
	while(fin.read((char*)&temp,sizeof(temp)))
	   {
	   if((temp.return_addmission_number())==a_no)
	      {
	      temp.editor();
	      break;
	      }
	   fstream temp_file("Tempo.DAT");
	   temp_file.write((char*)&temp,sizeof(temp));
	   remove("Stud.DAT");
	   rename("Tempo.DAT","Student Records.DAT");
	   temp_file.close();
	   }

	}
     fin.close();

     }

void delete_data()
    {
    int a_no;
     cout<<"Enter the addmission number of student:"<<endl;
     cin>>a_no;
     fstream fin("Stud.DAT");
     if(!fin)
	{
	cout<<"!!!Error!!!\nCannot open file";
	exit(0);
	}
     else
	{
	fstream temp_file("Tempo.DAT");
	student temp;
	while(fin.read((char*)&temp,sizeof(temp)))
	   {
	   if((temp.return_addmission_number())!=a_no)
	      {

		temp_file.write((char*)&temp,sizeof(temp));

	       }
	   else
	       {
	       cout<<"Data deleted successfuly"<<endl;
	       }
	   remove("Stud.DAT");
	   rename("Tempo.DAT","Student_Records.DAT");
	   temp_file.close();
	   }
	fin.close();

	}
     }
void display_data_of_students()
  {
  ifstream fin("Stud.DAT",ios::binary);
  if (!fin)
    {
    cout<<"!!!Error!!!\nCan not open file";
    exit(0);
    }
  student temp;
  while(fin.read((char*)&temp,sizeof(temp)))
    {
    temp.display_data();
    }
  fin.close();
  }
int main()
 {
 char ch;
 int choice;
 do
   {
   cout<<"\tMAIN  MENU"<<endl;
   cout<<"1.To add the information for a new student"<<endl;
   cout<<"2.To search for information of a student"<<endl;
   cout<<"3.To edit a students information"<<endl;
   cout<<"4.To delete a students information"<<endl;
   cout<<"5.To display students information"<<endl;
   cout<<"6.Exit"<<endl;
   cout<<"Enter your choice :"<<endl;
   cin>>choice;
   switch(choice)
     {
     case 1:add_data_for_students();break;
     case 2:search_data();break;
     case 3:edit_data();break;
     case 4:delete_data();break;
     case 5:display_data_of_students();break;
     case 6:exit(0);
     default :cout<<"!!!WRONG  CHOICE!!!";
     }
   cout<<endl<<"Do you want to continue ?(y/n)"<<endl;
   cin>>ch;
   }
 while(ch=='y');
 }