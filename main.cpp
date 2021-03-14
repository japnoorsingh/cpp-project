#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <process.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <windows.h>
using namespace std;

class emp
{
private:
    int emp_id, sal, group_id;
    string name, address;

public:
    void menu();
    void insert();
    void display();
    void search();
    void modify();
    void del();
    void group();
    void search_group();
    void show_group();
};

    void intro()
	{
		system("cls");
		cout << "\n\n\n";
		cout << "\t\t\t============================================================================";
		cout << "\n\t\t\t============================================================================";
		cout << "\n\n\t\t\t\t    EMPLOYEE MANAGEMENT SYSYTEM WITH FILE HANDLING IN C++ ";
		cout << "\n\n\t\t\t============================================================================";
		cout << "\n\t\t\t============================================================================";
		cout << "\n\n\t\t\t\t\t Made By: Japnoor Singh        2K20/B1/01";
		cout << "\n\n\t\t\t\t\t          Shivansh Dhondiyal   2K20/B1/42";
		cout << "\n\n\n";
		cout << "\n\t\t\t\t\t    Submitted To: Prof. Rajeev Kumar";
		cout << "\n\n";
		cout << "\n\t\t\t\t\t     DELHI TECHNOLOGICAL UNIVERSITY";
		cout << "\n\t\t\t\t\t                NEW DELHI";
		cout << "\n\n\t\t\t============================================================================";
		cout << "\n\t\t\t============================================================================";
		getch();
	}

    void login()
    {
        p:
		system("cls");
		char ch;
		string user,pass;
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t==============================";
		cout<<"\n\n\t\t\t\t    LOGIN";
		cout<<"\n\n\t\t\t==============================";
		cout<<"\n\n\n Enter User Name : ";
		cin>>user;
		cout<<"\n\n Enter Password : ";
		for(int i=1;i<=4;i++)
		{
			ch = getch();
			pass += ch;
			cout<<"*";
		}
		if(user == "b101b142" && pass == "abcd")
		{
			cout<<"\n\n\n\t\t\tLogin Successful...";
			cout<<"\n\n\n\t\t\t\t\tLoading";
			for(int i=1;i<=6;i++)
			{
				Sleep(500);
				cout<<".";
			}
		}
		else if(user != "b101b142" && pass == "abcd")
		{
			cout<<"\n\n\n Wrong User Name....";
			getch();
			goto p;
		}
		else if(user == "b101b142" && pass != "abcd")
		{
			cout<<"\n\n\n Wrong Password....";
			getch();
			goto p;
		}
		else
		{
			cout<<"\n\n\n Wrong Login Details....";
			getch();
			exit(0);
		}
	}

    void emp :: menu()
    {
        p:
        system ("cls");
        int x;

        cout << "\n\n\t\t\t\t\tCONTROL PANEL";
        cout << "\n\n 1. Insert Record";
        cout << "\n 2. Display Record";
        cout << "\n 3. Search Record";
        cout << "\n 4. Modify Record";
        cout << "\n 5. Delete Record";
        cout << "\n 6. Group Record";
        cout << "\n 7. Search Group";
        cout << "\n 8. Show All Groups";
        cout << "\n 9. Exit";
        cout << "\n\n Enter Your Choice: ";
        cin >> x;

        switch (x)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                modify();
                break;
            case 5:
                del();
                break;
            case 6:
                group();
                break;
            case 7:
                search_group();
                break;
            case 8:
                show_group();
                break;
            case 9:
                exit(0);
            default:
                cout << "\n\n Invalid Input....Please Try Again";
        }
        getch();
        goto p;
    }

    void emp :: insert()
	{
		system("cls");
		int test_id,found=0; //case8
		fstream file,file1;  // file for Employees and file1 for groups fstream fr both read and write

		cout << "\n\n\t\t\t\tINSERT RECORD";

        cout << "\n\n\nEmployee ID: ";
        cin >> emp_id;

        cout << "\n\nEmployee Name: ";
        cin >> name;

        cout << "\n\nEmployee Salary: ";
        cin >> sal;

        cout << "\n\nEmployee Address: ";
        cin >> address;

        cout << "\n\nEmployee Group ID: ";
        cin >> group_id;

		file.open("emp.txt", ios::out | ios::app); // ios::out for writing the file and ios::in for read and ios::app for keeping the previous data after you enter new data
        file << " " << emp_id << " " << name << " " << sal << " " << address << " " << group_id << "\n";
        file.close();

        file1.open("group.txt", ios::out | ios::app);
        file1 << " " << group_id << " " << emp_id << " " << sal << "\n";
        file1.close();

        //case8

		file.open("groupid.txt",ios::in);

		if(!file)
		{
			file1.open("groupid.txt", ios::app | ios::out);
            file1 << " " << group_id << "\n";
            file1.close();
		}
		else
		{
			file>>test_id;

			while(!file.eof())
			{
				if(test_id == group_id)
				found++;
				file >> test_id;
			}
			file.close();

			if(found == 0)
			{
				file1.open("groupid.txt",ios::app|ios::out);
				file1 << " " << group_id << "\n";
				file1.close();
			}
		}

		// case8 over

        cout << "\n\n\t\tNew Record Inserted Successfully!!!";
	}

    void emp :: display()
	{
		system("cls");
		fstream file;

		cout << "\n\n\t\t\t\tDISPLAY RECORD";

        file.open("emp.txt", ios::in);

		if(!file)
		{
			cout << "\n\n\t**ERROR** No Records Found...";
            getch();
            menu();
		}

		file >> emp_id >> name >> sal >> address >> group_id;
        while(!file.eof()) // eof = end of file === returns 1 if file ends, returns 0 if file does not end, !=converts 0 to 1 and 1 to 0
        {
            cout << "\n\n\n\nEmployee ID: " << emp_id;
            cout << "\n\nEmployee Name: " << name;
            cout << "\n\nEmployee Salary: " << sal;
            cout << "\n\nEmployee Address: " << address;
            cout << "\n\nEmployee Group ID: " << group_id;

            file >> emp_id >> name >> sal >> address >> group_id;
		}
		file.close();
	}

    void emp :: search()
	{
		system("cls");
		fstream file;
		int emp_idd,found=0;

        cout << "\n\n\t\t\t\tSEARCH RECORD";

		file.open("emp.txt",ios::in);

		if(!file)
		{
			cout << "\n\n\t**ERROR** File Not Found...";
            getch();
            menu();
		}
		cout << "\n\nEnter Employee ID: ";
        cin >> emp_idd;

        while(!file.eof()) // eof = end of file === returns 1 if file ends, returns 0 if file does not end, !=converts 0 to 1 and 1 to 0
		{
			if(emp_idd == emp_id)
			{
			system("cls");

			cout << "\n\n\t\t\t\tSEARCH RECORD";

            cout << "\n\nEmployee ID: " << emp_id;
            cout << "\n\nEmployee Name: " << name;
            cout << "\n\nEmployee Salary: " << sal;
            cout << "\n\nEmployee Address: " << address;
            cout << "\n\nEmployee Group ID: " << group_id;

            found ++;
            }
            file >> emp_id >> name >> sal >> address >> group_id;
		}
		file.close();
		if(found == 0)
            cout << "\n\nNo Record Found...";
	}

    void emp :: modify()
	{
		system("cls");
		int sall, test_id, found=0; //only salary, address and anme can be modified
		string name1,address1;

		fstream file, file1, file2, file3; // file - old emp, file1 - old grp, file2 - new emp, file3 - new grp

        cout << "\n\n\t\t\t\tMODIFY RECORD";

		file.open("emp.txt", ios::in);
		file1.open("group.txt", ios::in);

		if(!file || !file1)
		{
            cout << "\n\n\t**ERROR** File Not Found...";
			getch();
			menu();
		}
        cout << "\n\nEnter Employee ID: ";
		cin>>test_id;

		file2.open("emp1.txt", ios::app|ios::out);
		file >> emp_id >> name >> sal >> address >> group_id;

		while(!file.eof())
		{
			if(test_id == emp_id)
			{
				system ("cls");
                cout << "\n\n\t\t\t\tMODIFY RECORD";

                cout << "\n\n\nEmployee Name: ";
                cin >> name1;

                cout << "\n\nEmployee Salary: ";
                cin >> sall;

                cout << "\n\nEmployee Address: ";
                cin >> address1;

				file2<<" "<<emp_id<<" "<<name1<<" "<<sall<<" "<<address1<<" "<<group_id<<"\n";
				found++;
			}
			else
			{
				file2<<" "<<emp_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<"\n";
			}
			file>>emp_id>>name>>sal>>address>>group_id;
		}
		file.close();
		file2.close();
		remove("emp.txt");
		rename("emp1.txt", "emp.txt");

		file3.open("group1.txt", ios::app|ios::out);
		file1>>group_id>>emp_id>>sal;

		while(!file1.eof())
		{
			if(test_id == emp_id)
				file3<<" "<<group_id<<" "<<emp_id<<" "<<sall<<"\n";
			else
				file3<<" "<<group_id<<" "<<emp_id<<" "<<sal<<"\n";
			file1>>group_id>>emp_id>>sal;
		}
		file1.close();
		file3.close();
		remove("group.txt");
		rename("group1.txt", "group.txt");

		if(found == 0)
            cout << "\n\nNo Record Found...";
		else
            cout << "\n\n\t\tRecords Modified Successfully!!!";	}

    void emp :: del()
	{
		system ("cls");
		int test_id, found=0;
		fstream file, file1, file2, file3;

		cout << "\n\n\t\t\t\tDELETE RECORD";

		file.open("emp.txt",ios::in);
		file1.open("group.txt",ios::in);
		if(!file || !file1)
		{
			cout << "\n\n\t**ERROR** File Not Found...";
			getch();
			menu();
		}

		cout<<"\n\n Employee ID For Delete : ";
		cin>>test_id;

		file2.open("emp1.txt",ios::app|ios::out);
		file>>emp_id>>name>>sal>>address>>group_id;

		while(!file.eof())
		{
			if(test_id == emp_id)
			{
				cout << "\n\n\t\tRecord Deleted Successfully!!!";
				found++;
			}
			else
			{
				file2<<" "<<emp_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<"\n";
			}
			file>>emp_id>>name>>sal>>address>>group_id;
		}
		file.close();
		file2.close();

		remove ("emp.txt");
		rename ("emp1.txt", "emp.txt");

		file3.open( "group1.txt",ios::app|ios::out);
		file1 >> group_id >> emp_id >> sal;

		while(!file1.eof())
		{
			if(test_id != emp_id)
				file3<<" "<<group_id<<" "<<emp_id<<" "<<sal<<"\n";
			file1>>group_id>>emp_id>>sal;
		}
		file1.close();
		file3.close();

		remove("group.txt");
		rename("group1.txt","group.txt");

		if(found == 0)
		cout << "\n\nNo Record Found...";
	}

    void emp :: group()
	{
		system("cls");
		fstream file;

        cout << "\n\n\t\t\t\GROUP RECORD";

		file.open("group.txt",ios::in);

		if(!file)
		{
			cout<< "\n\n File Openning Error...";
			getch();
			menu();
		}
		file >> group_id >> emp_id >> sal;
		while(!file.eof())
		{
			cout << "\n\n\n\nGroup ID: " << group_id;
             cout << "\n\nEmployee ID: " << emp_id;
             cout << "\n\nEmployee Salary: " << sal;

			file>>group_id>>emp_id>>sal;
		}
		file.close();
	}

    void emp :: search_group()
	{
		system("cls");
		int test_id, found=0, emp_count=0, sal_count=0;
		fstream file;

		cout << "\n\n\t\t\t\tSEARCH GROUP RECORDS";

		file.open("group.txt",ios::in);
		if(!file)
		{
			cout << "\n\n\t**ERROR** File Not Found...";
			getch();
			menu();
		}
        cout << "\n\nEnter Group ID: ";
		cin>>test_id;
		system("cls");

        cout << "\n\n\t\t\t\tSEARCH GROUP RECORDS";

		file>>group_id>>emp_id>>sal; //fetching data from file

		while(!file.eof())
		{
			if(test_id == group_id)
			{
				cout << "\n\n\n\nGroup ID: " << group_id;
                cout << "\n\nEmployee ID: " << emp_id;
                cout << "\n\nEmployee Salary: " << sal;

				found++;
				emp_count++;
				sal_count = sal_count + sal;
			}
			file>>group_id>>emp_id>>sal;
		}
		file.close();
		if(found != 0)
		{
			cout<<"\n\n\n Group ID : "<<test_id;
			cout<<"\n\nTotal Number Of Employees : "<<emp_count;
			cout<<"\n\n Total Salary : "<<sal_count;
		}
		else
            cout << "\n\nNo Record Found...";
	}

    void emp :: show_group()
	{
		system("cls");
		int test_id,emp_count=0, sal_count=0, emp_total=0, sal_total=0;
		fstream file, file1;

        cout << "\n\n\t\t\t\tALL GROUP RECORDS";

		file.open("groupid.txt",ios::in);
		if(!file)
		{
            cout << "\n\n\t**ERROR** File Not Found...";
			getch();
			menu();
		}
		file>>test_id;

		while(!file.eof())
		{
			file1.open("group.txt",ios::in);
			file1 >> group_id >> emp_id >> sal;
			while(!file1.eof())
			{
				if(test_id == group_id)
				{
					emp_count++;      //only 1 group id
					sal_count += sal; //only 1 group id
					emp_total++;
					sal_total += sal;
				}
				file1 >> group_id >> emp_id >> sal;
			}
			file1.close();

			cout << "\n\n\n\nGroup ID: " << test_id;
            cout << "\n\nTotal Employees: " << emp_count;
            cout << "\n\nTotal Salary: " << sal_count;

			emp_count=0;
			sal_count=0;

			file>>test_id;
		}
		file.close();

		cout << "\n\n\n\nTotal Number Of Employees: " << emp_total;
        cout << "\n\nTotal Salary: " << sal_total;
	}

main()
{
    emp e;
    intro();
    login();
    e.menu();
}
