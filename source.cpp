#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <bits/stdc++.h>
#include "header.h"
using namespace std;
int bill_no = 1;
hostel hos;
void hostel::admin(){
		system("cls");
		cout << "\n************************************************************************************************************************";
   		cout << "\n\t\t                      * WELCOME TO  ONLINE HOSTEL BOOKING PORTAL *";
   		cout << "\n************************************************************************************************************************";
    	cout << "\n************************************************************************************************************************";
		const string USERNAME = "GLOBALHELL";
   			 const string PASSWORD = "loser@79";
   			 string username, password;
   			 bool user_validated = false;

  			  do{

        		cout << "\nInsert Username:";
       		 cin >> username;

       		 cout << "Insert Password:";
       		 cin >> password;
       		 if (username == USERNAME && password == PASSWORD)
       		 {
            	cout << "User credentials are correct, Granting access" << endl;
           	 user_validated = true;
           	 system("cls");
           	 	cout << "\n************************************************************************************************************************";
   				cout << "\n\t\t                      * WELCOME TO  ONLINE HOSTEL BOOKING PORTAL *";
  				cout << "\n************************************************************************************************************************";
  				cout << "\n************************************************************************************************************************";
            	cout<<"1.Update Menu"<<endl;
            	cout<<"2. search Room Records:"<<endl;
           	 cout<<"3. Room Allotted list"<<endl;
           	 cout<<"4. EXIT"<<endl;

           	 int ch;
           	 cin>>ch;
          	  switch(ch){
            	case 1:
            		edit_menu();
            	break;
            	case 2:
            		search_bar();
            	break;
            	case 3:
            		room_alloc();
            	break;
            	case 4:
            		login();
            	break;
            	default:
            		cout<<"wrong  choice "<<endl;
            	break;
				}

       		 	}
       		  else{
           		 cout << "Wrong username or password!!!!" << endl<< "Insert again!!" << endl;
       		 	}
   			 } while (user_validated == false);
   	getch();
}
void hostel::login(){
	system("cls");

	int choice;
	cout << "\n************************************************************************************************************************";
    cout << "\n\t\t                      * WELCOME TO  ONLINE HOSTEL BOOKING PORTAL *";
    cout << "\n************************************************************************************************************************";
    cout << "\n************************************************************************************************************************";
    cout<<"1. Admin"<<endl;
    cout<<"2. Student"<<endl;
    cout<<"3. EXIT"<<endl;
    cout<<"Enter your choice:"<<endl;
    cin>>choice;
    switch(choice){
    	case 1:
    		admin();
		break;

		case 2:
			main_menu();
		break;
		case 3:
			exit(0);
		break;
		default:
			cout<<"Wrong choice"<<endl;
		getch();
	}

}
void hostel::main_menu()
{
    int option;
    while (option != 6)
    {

        system("cls");
        cout << "\n************************************************************************************************************************";
        cout << "\n\t\t                      * WELCOME TO  ONLINE HOSTEL BOOKING PORTAL *";
        cout << "\n************************************************************************************************************************";
        cout << "\n************************************************************************************************************************";
        cout << "\n\t\t\t                              * MAIN MENU *";
        cout << "\n************************************************************************************************************************";
        cout << "\n\n\n\t\t\t1.Book A Room";
        cout << "\n\t\t\t2.Search Room Records";
        cout << "\n\t\t\t3.Rooms Allotted list";
        cout << "\n\t\t\t4.Generate My Bill";
        cout << "\n\t\t\t5.Exit";
        cout << "\n\n\t\t\tEnter Option you want to choose: ";
        cin >> option;

        switch (option)
        {
        case 1:
            book_room();
            break;

        case 2:
            search_bar();
            break;

        case 3:
            room_alloc();
            break;


        case 4:
            bill_generate();
            break;
        case 5:
           login();
           break;

        default:
        {
            cout << "\n\n\t\t\tWrong choice.....!!!";
            cout << "\n\t\t\tPress any key to   continue....!!";
            getch();
        }
        }
    }
}

void hostel::book_room()
{

    system("cls");
    int r, n, flag;
    char ch;
    ofstream fout("Record.dat", ios::app);
    cout << "\n************************************************************************************************************************";
    cout << "\n\t\t                      * WELCOME TO  ONLINE HOSTEL BOOKING PORTAL *";
    cout << "\n************************************************************************************************************************";
    cout << "\n============================================= Room List is as follows: =================================================";
    cout << "\n\n\t\t\t Total no. of Rooms present:  \t   60    ";
    cout << "\n\t\t   -------------------------------------------------";
    cout << "\n\t\t   |     Types of room         |    Room Number    |";
    cout << "\n\t\t   -------------------------------------------------";
    cout << "\n\t\t   | AC Room                   |\t01 - 20    |";
    cout << "\n\t\t   | Water-Cooler Room         |\t21 - 40    |";
    cout << "\n\t\t   | Fan Room                  |\t41 - 60    |";
    cout << "\n \t\t   -------------------------------------------------";
top:
    cout << "\n\n\t\t Enter the room you want to book:- ";
    cin >> r;
    if( r ==0 || r >60)
    {
       cout << "\n\t\t\t Room number invalid....!!";
       goto top;
    }
   else
   {
       flag = check(r);
       if (flag)
    {
        cout << "\n Sorry..!!! Room is already booked";
        goto top;
    }
    else
    {
        char space[10],p[10];
        room_no = r;
        cout << "\n\t\t\tThe room is available.........!!" << endl;
        cout << "\n\t\t---------------------------- Kindly enter your details: --------------------------------------" << endl;
        gets(space);
        cout << " Name: ";
        gets(name);
        cout << " Course: ";
        gets(course);
        cout << " Branch: ";
        gets(branch);
        cout << " Semester: ";
        gets(semester);
        cout << " Address: ";
        gets(address);
        cout<<  " University Roll number: ";
        cin>>uni_roll;
        cout << " Phone Number: ";
        cin >> p;

        cout << "\n\n\t\t Do you want to save the data? (y/n)";
        cin >> ch;
        if (ch == 'y')
        {
            fout.write((char *)this, sizeof(hostel));
            cout << "\n Room booked successfully...!!!";
            cout << "\n You can get your bill from the main menu.........";
            fout.close();
        }
        else
        {
            cout << "Data not entered.. " << endl;
            fout.close();
        }
    }
    cout << "\n Press any key to continue.....!!";
    getch();
    fout.close();
   }
}

void hostel ::search_bar()
{
    system("cls");
    int  opt;
    do
    {
        system("cls");
        cout << "\n************************************************************************************************************************";
        cout << "\n\t\t                      * WELCOME TO  ONLINE HOSTEL BOOKING PORTAL *";
        cout << "\n************************************************************************************************************************";
        cout << "\n==================================================== * SEARCH MENU * ===================================================";
        cout << "\n\n 1.Search details by university roll no.";
        cout << "\n 2.Search details by room no.";
        cout << "\n 3.Go to Main menu .";
        cout << "\n\n Enter your choice: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            uni_search();
            break;

        case 2:
            search_roomno();
            break;

        case 3:
            main_menu();
            break;
        default:
        {
            cout << "\n Wrong Choice.....!!";
            cout << "\n Press any key to continue....!!!";
            getch();
        }
        }
    }while (opt != 3);

}

void hostel::search_roomno()
{
    int r,flag =0;
    ifstream fin("Record.dat", ios::in);
    system("cls");
    cout << "\n************************************************************************************************************************";
    cout << "\n\t\t                      * WELCOME TO  ONLINE HOSTEL BOOKING PORTAL *";
    cout << "\n************************************************************************************************************************";
    cout << "\n==================================================== * SEARCH MENU * ===================================================";
    cout << "\n\n Enter room no.to get the student`s details :- ";
    cin >> r;

    while (!fin.eof())
    {
        fin.read((char *)this, sizeof(hostel));
        if (room_no == r)
        {
            cout << "\n Student Details";
            cout << "\n ---------------";
            cout << "\n\n Room no: " << room_no;
            cout << "\n University Roll Number : " << uni_roll;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n Semester: " <<semester ;
            cout << "\n Branch: " << branch;
            cout << "\n Course: " << course;
            cout << "\n Phone number: " << phone;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "\n Sorry Room you entered found vacant....!!";
    }

    cout << "\n\n Press any key to continue....!!";
    getch();
    fin.close();

}

void hostel ::uni_search()
{
    int ur,u,flag =0,temp =0;
    ifstream fin("Record.dat", ios::in);
    system("cls");
    cout << "\n************************************************************************************************************************";
    cout << "\n\t\t                      * WELCOME TO  ONLINE HOSTEL BOOKING PORTAL *";
    cout << "\n************************************************************************************************************************";
    cout << "\n==================================================== * SEARCH MENU * ===================================================";
    num:
    cout << "\n\n Enter university roll no.to get the student`s details :- ";
    cin >> ur;
          while (!fin.eof())
         {
           fin.read((char *)this, sizeof(hostel));
           if (uni_roll == ur)
          {
            cout << "\n Student Details";
            cout << "\n ---------------";
            cout << "\n\n Room no: " << room_no;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n University Roll Number : " << uni_roll;
            cout << "\n Semester: " <<semester ;
            cout << "\n Branch: " << branch;
            cout << "\n Course: " << course;
            flag = 1;
            break;
           }
           else{
		   }
         }
    if (flag == 0)
    {
        cout << "\n Sorry Room not found....!!";
    }
        }
    //cout<< "\n\n Press any key to continue....!!"<<endl;;
   // fin.close();




void hostel ::room_alloc()
{
    system("cls");
    cout << "\n************************************************************************************************************************";
    cout << "\n\t\t                      * WELCOME to ONLINE HOSTEL BOOKING PORTAL *";
    cout << "\n************************************************************************************************************************";
    cout << "\n============================================== ROOM ALLOCATION MENU: ===================================================";
    ifstream fin("Record.dat", ios::in);
    cout << "\n\n\t    List Of Rooms Allotted";
    cout << "\n\t    ----------------------";
    cout << "\n\n Room No.\t\t\tName\t\t\tRollNO\t\t\tAddress\t\t\tPhone No\t\t\tSemester\t\t\tCourse\t\t\t\tBranch\n";

    while (fin.read((char *)this, sizeof(hostel)))
    {

        cout << "\n\n " << room_no << "\t\t\t" << name;
        cout << "\t\t\t" << uni_roll << "\t\t\t" << address;
        cout << "\t\t\t" << phone << "\t\t\t" << semester;
        cout << "\t\t\t" << course << "\t\t\t\t" << branch;

    }
    cout << "\n\n\n\t\t\tPress any key to continue.....!!";
    getch();
    fin.close();
}

int hostel ::check(int r)
{

    int flag = 0;
    ifstream fin("Record.dat", ios::in);

    while (!fin.eof())
    {
        fin.read((char *)this, sizeof(hostel));
        if (room_no == r)
        {
            flag = 1;
            break;
        }
    }
    fin.close();
    return (flag);
}

void hostel ::bill_generate()
{
    system("cls");
    int dd, mm, yy, r, flag = 0;
    int acprice = 20000, cprice = 10000, fprice = 8000;
    static int mess = 1500;
    cout << "\n************************************************************************************************************************";
    cout << "\n\t\t                       * WELCOME TO  ONLINE HOSTEL BOOKING PORTAL *                                             ";
    cout << "\n************************************************************************************************************************";
    cout << "\n================================================= GENERATE BILL: =======================================================";
    cout << "Enter the date of the bill" << endl;
    cin >> dd >> mm >> yy;
    ifstream rd;
    rd.open("record.dat", ios::in | ios::binary);
    cout << "Enter the room number " << endl;
    cin >> r;

    if (!rd)
    {
        cout << "Error opening file.........!" << endl;
    }
    else
    {
        rd.read((char *)&hos, sizeof(hostel));
        while (rd)
        {
            rd.read((char *)&hos, sizeof(hostel));
        }
        if (hos.room_no == r)
        {
            system("cls");
            cout << "\n************************************************************************************************************************";
            cout << "\n\t\t                       * WELCOME TO ONLINE HOSTEL BOOKING PORTAL *                                             ";
            cout << "\n************************************************************************************************************************";
            cout << "\n================================================== HOSTEL BILL: ========================================================";
            if (hos.room_no >= 1 && hos.room_no <= 20)
            {
                cout << "\n\n\n========================================================================================================================";
                cout << "\n\tDate:" << dd << "-" << mm << "-" << yy << "\t\t\t\t\t\t\t\t "
                     << "Bill Number:" << bill_no;
                ;
                cout << "\n========================================================================================================================";
                cout << "\n\n Student Details";
                cout << "\n ---------------";
                cout << "\n\n Room no: " << room_no;
                cout << "\n Name: " << name;
                cout << "\n Address: " << address;
                cout << "\n University Roll Number : " << uni_roll;
                cout << "\n Semester: " <<semester ;
                cout << "\n Branch: " << branch;
                cout << "\n Course: " << course;
                cout << "\n\n\t\t You are booked for AC Room";
                cout << "\n\n Charges:";
                cout << "\n --------";
                cout << "\n Hostel Room Charges: \t\t\t" << acprice;
                cout << "\n Mess Charges: \t\t\t\t" << mess;
                cout << "\n ------------- ";
                cout << "\n Total Charges: \t\t\t" << (mess + acprice);
            }
            else if (hos.room_no >= 21 && hos.room_no <= 40)
            {
                cout << "\n\n\n========================================================================================================================";
                cout << "\n\tDate:" << dd << "-" << mm << "-" << yy << "\t\t\t\t\t\t\t\t "
                     << "Bill Number:" << bill_no;
                ;
                cout << "\n========================================================================================================================";
                cout << "\n\n Student Details";
                cout << "\n ---------------";
                cout << "\n\n Room no: " << room_no;
                cout << "\n Name: " << name;
                cout << "\n Address: " << address;
                cout << "\n University Roll Number : " << uni_roll;
                cout << "\n Semester: " <<semester ;
                cout << "\n Branch: " << branch;
                cout << "\n Course: " << course;
                cout << "\n\n\t\t You are booked for cooler Room";
                cout << "\n\n Charges:";
                cout << "\n --------";
                cout << "\n Hostel Room Charges: \t\t\t" << cprice;
                cout << "\n Mess Charges: \t\t\t\t" << mess;
                cout << "\n ------------- ";
                cout << "\n Total Charges: \t\t\t" << (mess + cprice);
            }
            else
            {
                cout << "\n\n\n========================================================================================================================";
                cout << "\n\tDate:" << dd << "-" << mm << "-" << yy << "\t\t\t\t\t\t\t\t "
                     << "Bill Number:" << bill_no;
                ;
                cout << "\n========================================================================================================================";
                cout << "\n\n Student Details";
                cout << "\n ---------------";
                cout << "\n\n Room no: " << room_no;
                cout << "\n Name: " << name;
                cout << "\n Address: " << address;
                cout << "\n University Roll Number : " << uni_roll;
                cout << "\n Semester: " <<semester ;
                cout << "\n Branch: " << branch;
                cout << "\n Course: " << course;
                cout << "\n\n\t\t You are booked for Fan Room";
                cout << "\n\n Charges:";
                cout << "\n --------";
                cout << "\n Hostel Room Charges: \t\t\t" << fprice;
                cout << "\n Mess Charges: \t\t\t\t" << mess;
                cout << "\n ------------- ";
                cout << "\n Total Charges: \t\t\t" << (mess + fprice);
            }
            bill_no++;
            cout << "\n\n\t\t\t\t\t THANK YOU...!";
            cout << "\n\n\n========================================================================================================================";
            flag = 1;
            getch();
        }
     }

}

void hostel ::edit_menu()
{

    int choice;
    do
    {
        system("cls");
        cout << "\n******************************************";
        cout << "\n\t\t                      * WELCOME TO  ONLINE HOSTEL BOOKING PORTAL *";
        cout << "\n******************************************";
        cout << "\n=================================================== EDIT MENU: =========================================================";
        cout << "\n\n 1.Modify My Record.";
        cout << "\n 2.Vacate My Room.";
        cout << "\n 3.Go to Main menu .";
        cout << "\n\n Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            modify();
            break;

        case 2:
            vacate_room();
            break;

        case 3:
            admin();
            break;
        default:
        {
            cout << "\n Wrong Choice.....!!";
            cout << "\n Press any key to continue....!!!";
            getch();
        }
        }
    } while (choice != 3);
}

void hostel::modify()
{
    system("cls");
    int pos, flag = 0, r;
    char space[10];
    fstream file("Record.dat", ios::in | ios::out | ios::binary);
    cout << "\n************************************************************************************************************************";
    cout << "\n\t\t                      * WELCOME TO  ONLINE HOSTEL BOOKING PORTAL *";
    cout << "\n************************************************************************************************************************";
    cout << "\n=============================================== MODIFY RECORD MENU: ===================================================";
    cout << "\n\n Enter room no: ";
    cin >> r;

    while (!file.eof())
    {

        pos = file.tellg();
        file.read((char *)this, sizeof(hostel));
        if (room_no == r)
        {
            cout << "\n Enter New Details";
            cout << "\n -----------------";
            gets(space);
            cout << " Name: ";
            gets(name);
            cout << " Course: ";
            gets(course);
            cout << " Branch: ";
            gets(branch);
            cout << " Semester: ";
            gets(semester);
            cout << " Address: ";
            gets(address);
            cout<<  " University Roll number: ";
            cin>>uni_roll;
            cout << " Phone Number: ";
            cin >> phone;
            file.seekp(pos);
            file.write((char *)this, sizeof(hostel));
            cout << "\n\n\t\t Record is modified....!!";
            cout << "\n\n Updated details are:";
            cout << "\n\n Room no: " << room_no;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n University Roll Number : " << uni_roll;
            cout << "\n Semester: " <<semester ;
            cout << "\n Branch: " << branch;
            cout << "\n Course: " << course;

            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "\n Sorry Room found vacant...!!";
    }
    file.close();
}

void hostel::vacate_room()
{
    system("cls");
    int flag = 0, r;
    char ch;
    ifstream fin("Record.dat", ios::in);
    ofstream fout("temp.dat", ios::out);
    cout << "\n************************************************************************************************************************";
    cout << "\n\t\t                      * WELCOME TO ONLINE HOSTEL BOOKING PORTAL *";
    cout << "\n************************************************************************************************************************";
    cout << "\n============================================== VACATE MY ROOM MENU: ===================================================";
    cout << "\n\n Enter room no: ";
    cin >> r;

    while (fin.read((char *)this, sizeof(hostel)))
    {
        if (room_no == r)
        {

            cout << "\n\n Room no: " << room_no;
            cout << "\n Name: " << name;
            cout << "\n Address: " << address;
            cout << "\n University Roll Number : " << uni_roll;
            cout << "\n Semester: " <<semester ;
            cout << "\n Branch: " << branch;
            cout << "\n Course: " << course;
            cout << "\n\n Do you want to delete this record(y/n): ";
            cin >> ch;
            if (ch == 'y')
            {
               cout << "\t\t\t\t\tYour record is deleted. ";
                flag = 1;
            }
            else
            {
                cout<< "\n\n\t\t\tRecord not deleted....";
                cout << "\n\t\t\t Press any key to continue....!!!";
                getch();
            }
        }
        else
        {
            fout.write((char *)this, sizeof(hostel));
        }
    }
    fin.close();
    fout.close();
    if (flag == 0)
    {
        cout << "\t\tSorry room not found vacant......!!!!! " << endl;
    }
    else
    {
        remove("Record.dat");
        rename("temp.dat", "Record.dat");
    }
}

