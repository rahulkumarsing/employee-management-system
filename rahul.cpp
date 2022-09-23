#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip.h>
fstream empDB("database.dat",ios::in | ios::out | ios::app | ios::binary);
class employee
{
	long id, salary;
	int tenure;
	char name[20], dob[10], prcs[20], desg[30], contact[10];
	public:
	void enterData()
	{
		cout<<"Enter Employee ID: \t\t";
		cin>>id;
		cout<<"Enter Name of Employee: \t";
		gets(name);
		cout<<"Enter Date of Birth: \t\t";
		gets(dob);
		cout<<"Enter Process: \t\t\t";
		gets(prcs);
		cout<<"Enter Designation: \t\t";
		gets(desg);
		cout<<"Enter Contact number: \t\t";
		gets(contact);
		cout<<"Salary of the employee is "<<salary;
	}
	void readData()
	{
		cout<<endl;
cout<<setw(8)<<id<<setw(20)<<name<<setw(15)<<prcs<<setw(20)<<desg<<setw(15)<<contact<<endl;
	}
	long getID()
	{
		return id;
	}
	char* getName()
	{
		return name;
	}
	char* getPrcs()
	{
		return prcs;
	}
	char* getDesg()
	{
		return desg;
	}
	char* getContact()
	{
		return contact;
	}
	int checkID(long eID)
	{
		int flag=0;
		empDB.seekg(0,ios::beg);
		empDB.read((char*)&e,sizeof(e));
		while(empDB.good())
		{
			if(e.getID()==eID)
			{
				flag=1;
				break;
			}
			empDB.read((char*)&e,sizeof(e));
		}
		empDB.clear();
		return flag;
	}
}emp,e;
void main()
{
clrscr();
int inp, flag=0, search;
long eID;
char ask, name[20], prc[20], dsg[30], cont[10], admin[10], pass[10];
while(ask!='n' && ask!='N')
{
	cout<<"Enter Username: ";
	gets(admin);
	if(strcmp(admin,"Admin")==0)
	{
		cout<<"Enter Password: ";
		gets(pass);
		if(strcmp(pass,"Password")==0)
		{
			while(ask!='n' && ask!='N')
			{
				clrscr();
				fstream empDB("database.dat",ios::in | ios::out | ios::app | ios::binary);
				cout<<"\n\t\t------------------------------------------------";
				cout<<"\n\t\t\t\tEnter your choice\n";
				cout<<"\t\t------------------------------------------------";
				cout<<"\n\t\t1 for Enter new Record";
				cout<<"\n\t\t2 for Display All Employee";
				cout<<"\n\t\t3 for Search an Employee's Details";
				cout<<"\n\t\t4 for Delete a Record";
				cout<<"\n\t\t5 for Update Employee's Details";
				cout<<"\n\t\t6 for Exit\n";
				cin>>inp;
				switch(inp)
				{
					case 1:
						empDB.seekp(0,ios::end);
						emp.enterData();
						if(emp.getID()==0)
						{
							cout<<setw(50)<<"\nEnter another ID!"<<endl;
							emp.enterData();
						}
						if(emp.checkID(emp.getID())==0)
						{
							empDB.write((char*)&emp,sizeof(emp));
						}
						else
						{
cout<<endl<<setw(50)<<"Employee ID Exists!\n"<<setw(50)<<"Try Another ID";
						}
					break;
					case 2:
cout<<setw(8)<<"EmpID"<<setw(20)<<"Employe Name"<<setw(15)<<"Process"<<setw(20)<<"Designation"<<setw(15)<<"Contact"<<endl;
cout<<"\n--------------------------------------------------------------------------------\n";
						empDB.seekg(0,ios::beg);
						empDB.read((char*)&e,sizeof(e));
						while(empDB.good())
						{
							e.readData();
							empDB.read((char*)&e,sizeof(e));
						}
						empDB.clear();
					break;
					case 3:
						cout<<"\n1 Search by Employee ID";
						cout<<"\n2 Search by Employee Process";
						cout<<"\n3 Search by Employee Designation";
						cout<<"\n4 Search by Employee Contact no.\n";
						cin>>search;
						switch(search)
						{
							case 1:
cout<<"Enter Employee ID to be searched: ";
								cin>>eID;
								cout<<endl<<endl;
								empDB.seekg(0,ios::beg);
								empDB.read((char*)&e,sizeof(e));
								while(empDB.good())
								{
									if(e.getID()==eID)
									{
cout<<setw(8)<<"EmpID"<<setw(20)<<"Employe Name"<<setw(15)<<"Process"<<setw(20)<<"Designation"<<setw(15)<<"Contact"<<endl;
cout<<"\n--------------------------------------------------------------------------------\n";
										e.readData();
											flag=1;
										break;
									}
								empDB.read((char*)&e,sizeof(e));
								}
								empDB.clear();
								if(flag==0)
								{
cout<<setw(50)<<"Enter Valid Employee ID\n";
cout<<setw(50)<<"Employee ID hasn't found/";
								}
							break;
							case 2:
cout<<"Enter Process Name to be searched: ";
								cin>>prc;
								cout<<endl<<endl;
								empDB.seekg(0,ios::beg);
								empDB.read((char*)&e,sizeof(e));
								while(empDB.good())
								{
									if(strcmp(e.getPrcs(),prc)==0)
									{
cout<<setw(8)<<"EmpID"<<setw(20)<<"Employe Name"<<setw(15)<<"Process"<<setw(20)<<"Designation"<<setw(15)<<"Contact"<<endl;
cout<<"\n--------------------------------------------------------------------------------\n";
										e.readData();
										flag=1;
										break;
									}
								empDB.read((char*)&e,sizeof(e));
								}
								empDB.clear();
								if(flag==0)
								{
cout<<setw(50)<<"Enter Valid Process Name\n";
cout<<setw(50)<<"Process hasn't found/";
								}
							break;
							case 3:
cout<<"Enter Designation to be searched: ";
								cin>>dsg;
								cout<<endl<<endl;
								empDB.seekg(0,ios::beg);
								empDB.read((char*)&e,sizeof(e));
								while(empDB.good())
								{
									if(strcmp(e.getDesg(),dsg)==0)
									{
cout<<setw(8)<<"EmpID"<<setw(20)<<"Employe Name"<<setw(15)<<"Process"<<setw(20)<<"Designation"<<setw(15)<<"Contact"<<endl;
cout<<"\n--------------------------------------------------------------------------------\n";
										e.readData();
										flag=1;
										break;
									}
								empDB.read((char*)&e,sizeof(e));
								}
								empDB.clear();
								if(flag==0)
								{
cout<<setw(50)<<"Enter Valid Designation\n";
cout<<setw(50)<<"Designation hasn't found/";
								}
							break;
							case 4:
								cout<<"Enter Contact to be searched: ";
								cin>>cont;
								cout<<endl<<endl;
								empDB.seekg(0,ios::beg);
								empDB.read((char*)&e,sizeof(e));
								while(empDB.good())
								{
if(strcmp(e.getContact(),cont)==0)
									{
cout<<setw(8)<<"EmpID"<<setw(20)<<"Employe Name"<<setw(15)<<"Process"<<setw(20)<<"Designation"<<setw(15)<<"Contact"<<endl;
cout<<"\n--------------------------------------------------------------------------------\n";
										e.readData();
										flag=1;
										break;
									}
								empDB.read((char*)&e,sizeof(e));
								}
								empDB.clear();
								if(flag==0)
								{
cout<<setw(50)<<"Enter Valid Contact Number\n";
cout<<setw(50)<<"Contact Number hasn't found/";
								}
							break;
						}
					break;
					case 4:
						cout<<"Enter Employee ID: ";
						cin>>eID;
						cout<<endl<<endl;
						if(emp.checkID(eID)==1)
						{
fstream temp("temp.dat", ios::in | ios::out | ios::app | ios::binary);
							empDB.seekg(0,ios::beg);
							empDB.read((char*)&e,sizeof(e));
							while(empDB.good())
							{
								if(e.getID()!=eID)
								{
								temp.write((char*)&e,sizeof(e));
								}
								empDB.read((char*)&e,sizeof(e));
							}
							empDB.clear();
							temp.close();
							empDB.close();
							remove("database.dat");
							rename("temp.dat","database.dat");
cout<<setw(50)<<"Record Deleted Successfully!"<<endl;
empDB.open("database.dat", ios::in | ios::out | ios::app | ios::binary);
						}
						else
						{
cout<<setw(50)<<"Employee ID doesn't exists!\n"<<setw(50)<<"Try Another ID";
						}
					break;
					case 5:
						int record=0, flag=0;
						cout<<endl<<setw(50)<<"File is being modified....";
						cout<<endl<<"Enter Employee ID to be updated:";
						cin>>eID;
						empDB.seekg(0,ios::beg);
						empDB.read((char*)&e,sizeof(e));
						while(empDB.good())
						{
							record++;
							if(e.getID()==eID)
							{
cout<<setw(50)<<"Previous Record with Employee ID "<<eID<< "is:\n\n";
cout<<setw(8)<<"EmpID"<<setw(20)<<"Employe Name"<<setw(15)<<"Process"<<setw(20)<<"Designation"<<setw(15)<<"Contact"<<endl;
cout<<"\n--------------------------------------------------------------------------------\n";
								e.readData();
								flag=1;
								break;
							}
						empDB.read((char*)&e,sizeof(e));
						}
						if(flag==0)
						{
cout<<endl<<setw(40)<<"Employee ID "<<eID<<" doesn't exists!";
							break;
						}
						empDB.clear();
						int loc=(record-1)*sizeof(e);
						empDB.seekp(loc,ios::beg);
cout<<endl<<"Enter new record for Employee having ID"<<eID<<endl<<endl;
						e.enterData();
						empDB.write((char*)&e,sizeof(e));
					break;
					case 6:
					exit(1);
					break;
					default:
					cout<<"\t\t\t\tInvalid input!";
					continue;
				}
				empDB.close();
				cout<<"\nDo you want to continue (y/n): ";
				cin>>ask;
				empDB.close();
				if(ask=='n' && ask=='N')
					exit(1);
				clrscr();
				}
			}
		else
		{
			cout<<setw(45)<<"Wrong Password!";
			cout<<"\nEnter Username and Password again";
			getch();
			clrscr();
		}
	}
	else
	{
	cout<<setw(45)<<"Invalid Username!";
	cout<<"\nDo you want to enter again(y/n): ";
	cin>>ask;
	clrscr();
	}
}
getch();
}