#include<iostream>
#include<fstream>
using namespace std;
enum OS {iOS=1,Android,windows_phone};	
enum Ram {_2GB=1,_4GB,_6GB,_8GB,_12GB,_16GB,_32GB,_64GB};
enum Storage {__16GB=1,__32GB,__64GB,__128GB,__256GB,__512GB,__1TB,__2TB};
enum Color {white=1,black,blue};
struct phone_store
{
	string name;
	string company;
	long double cost;
	int number_of_exist;
	int number_of_sold;
	OS os;
	Ram ram;
	Storage storage;
	Color color;
};
void add_phone(phone_store * &,int & );
void add_phone(phone_store * &,string ,string,int,int );
void print_mpbile(phone_store* ,int ,int);
void load_from_a_file(phone_store *&, int &);
void save_to_a_file(phone_store *, int);
void remove_phone(phone_store *& ,int &,string,string);
void sort_by_price(phone_store *& ,int );
void most_sold_phone(phone_store *,int );
int  search(phone_store *& ,int ,string ,string);
void change_mobile_info(phone_store *& ,int ,string ,string);
void sell_a_phone(phone_store *& ,int ,string ,string);
void ram_change_input(Ram &,int);
void ram_change_output(Ram);
void os_change_input(OS &,int);
void os_change_output(OS);
void storage_change_input(Storage &,int);
void storage_change_output(Storage);
void color_change_input(Color &,int);
void color_change_output(Color);
int main(int argc,char *argv[])
{
	int size=0;
	phone_store* my_phone=new phone_store[size];
	load_from_a_file(my_phone,size);
	if(argc!=1)
	{
		if(strcmp(argv[1],"add")==0)
		{
			string name=argv[2];
			string company=argv[3];
			string n=argv[4];
			int num=stoi(n);
			int andis=search(my_phone,size,name ,company);
			if(andis==-1)
			{
				phone_store * temp=new phone_store[size+1];
				for(int q=0;q<size;q++)
				{
					temp[q]=my_phone[q];
				}
				temp[size].name=name;
				temp[size].company=company;
				temp[size].number_of_exist=num;
				temp[size].os=Android;
				temp[size].ram=_8GB;
				temp[size].storage=__256GB;
				temp[size].cost=7000;
				temp[size].color=blue;
				temp[size].number_of_sold=100;
				delete [] my_phone;
				my_phone=temp;
				size++;
				cout<<"\nit is done\n";
				save_to_a_file(my_phone,size);
			}
			else
			{
				my_phone[andis].number_of_exist+=num;
				save_to_a_file(my_phone,size);
				cout<<"\nit is done\n";
			}	
		}
		else if(strcmp(argv[1],"remove")==0)
		{
			string name=argv[2];
			string company=argv[3];
			string n=argv[4];
			int num=stoi(n);
			int andis=search(my_phone,size,name ,company);
			if(andis==-1)
			{
				cout<<"\nthere is no such mobile !\n";
			}
			else
			{
				if((my_phone[andis].number_of_exist-num)<0)
				{
					cout<<"\nwe can not do this ";
					cout<<"its exist num is lower than your want \n";
				}
				else
				{
					my_phone[andis].number_of_exist-=num;
					save_to_a_file(my_phone,size);
					cout<<"\nit is done\n";
				}
			}
		}
	}
	else if(argc<2)
	{	
		char check;
		do
		{
			system("cls");
			cout<<"This is the menu : \n\n";
			cout<<"1.Add a phone\n";
			cout<<"---------------------------------------------------\n";
			cout<<"2.Remove a phone\n";
			cout<<"---------------------------------------------------\n";
			cout<<"3.Sort phones by price \n";
			cout<<"---------------------------------------------------\n";
			cout<<"4.Search a phone \n";
			cout<<"---------------------------------------------------\n";
			cout<<"5.Change mobile info \n";
			cout<<"---------------------------------------------------\n";
			cout<<"6.Sell a phone \n";
			cout<<"---------------------------------------------------\n";
			cout<<"7.Print phones \n";
			cout<<"---------------------------------------------------\n";
			cout<<"8.Print phones sorted by the most sold to the least\n";
			cout<<"---------------------------------------------------\n";
			cout<<"9.Quit\n";
			cout<<"---------------------------------------------------\n";
			cout<<"Enter number of your option . . .\n";
			int num;
			cin>>num;
			if(num>9||num<1)
			{
				cout<<"we have not this option \n";
			}
			else
			{
				if(num==1)
				{
					add_phone(my_phone,size);
				}
				else if(num==2)
				{
					cout<<"enter these to remove it : \n";
					string temp_name,temp_company;
					cout<<"name : ";
					cin>>temp_name;
					cout<<"company : ";
					cin>>temp_company;
					remove_phone(my_phone,size,temp_name,temp_company);
				}
				else if(num==3)
				{
					sort_by_price(my_phone,size);
				}
				else if(num==4)
				{
					string name5;
					string company5;
					cout<<"we need the name and company name to search :\n";
					cout<<"name : ";
					cin>>name5;
					cout<<"company : ";
					cin>>company5;
					if(search(my_phone,size,name5,company5)==-1)
					{
						cout<<"\nthere is no such mobile !\n";
					}
					else
					{
						int andis1=search(my_phone,size,name5,company5);
						print_mpbile(my_phone,size,andis1);
					}
				}
				else if(num==5)
				{
					string name6;
					string company6;
					cout<<"we need name and company name : \n";
					cout<<"name : ";
					cin>>name6;
					cout<<"company : ";
					cin>>company6;
					change_mobile_info(my_phone,size,name6,company6);
				}
				else if(num==6)
				{
					string name7,company7;
					cout<<"we need the name and company name : \n";
					cout<<"name : ";
					cin>>name7;
					cout<<"company : ";
					cin>>company7;
					sell_a_phone(my_phone,size,name7,company7);
				}
				else if(num==7)
				{
					system("cls");
					for(int q=0;q<size;q++)
					{
						print_mpbile(my_phone,size,q);
					}
				}
				else if(num==8)
				{
					system("cls");
					most_sold_phone(my_phone,size);
				}
				else if(num==9)
				{
					cout<<"thanks for your use "<<(char)1;
					save_to_a_file(my_phone,size);
					_getwch();
					return 0;
				}
			}
			save_to_a_file(my_phone,size);
			cout<<"\ndo you want to go back to the menu ? (if yes ,press y) \n";
			cin>>check;
		}while((check=='y')||(check=='Y'));
		system("cls");
		save_to_a_file(my_phone,size);
		cout<<"\a";
		cout<<"thanks for your use "<<(char)1;
	}
	delete [] my_phone;
	_getwch();
	return 0;
}
void add_phone(phone_store *& my_phone,int &size)
{
	string name1;
	string company1;
	cout<<"enter the . . .";
	cout<<"\nName : ";
	cin>>name1;
	cout<<"\nCompany : ";
	cin>>company1;
	for(int q=0;q<size;q++)
	{
		if((my_phone[q].name==name1)&&(my_phone[q].company==company1))
		{
			int num;
			cout<<"we had this yet !\n";
			cout<<"enter num to add to this phone :";
			cin>>num;
			add_phone(my_phone,name1,company1,size,num);
			return;
		}
	}
	phone_store * temp=new phone_store[size+1];
	for(int q=0;q<size;q++)
	{
		temp[q]=my_phone[q];
	}
	temp[size].name=name1;
	temp[size].company=company1;
	
	int temp_int;
	long double temp_cost;
	cout<<"\ncost : ";
	cin>>temp_cost;
	temp[size].cost=temp_cost;
	
	cout<<"\nexist : ";
	cin>>temp_int;
	temp[size].number_of_exist=temp_int;
	
	cout<<"\nsold : ";
	cin>>temp_int;
	temp[size].number_of_sold=temp_int;
	
	int temp_ram;
	cout<<"\nthese are the rams there are ,choose one : ";
	cout<<"\n1_2GB,2_4GB,3_6GB,4_8GB,5_12GB,6_16GB,7_32GB,8_64GB\n";
	bool check=true;
	while(check)
	{
		cin>>temp_ram;
		if(temp_ram>0&&temp_ram<9)
		{
			ram_change_input(temp[size].ram,temp_ram);
			check=false;
			cout<<"\n";
		}
		else
		{
			cout<<"\nwrong input,lets do it again . . .\n";
			cout<<"enter a number betwin 1 and 8 : ";
		}
	}

	int temp_os;
	cout<<"\nthese are the oss there are ,choose one : ";
	cout<<"\n1_iOS,2_Android,3_windows phone\n";
	check=true;
	while(check)
	{
		cin>>temp_os;
		if(temp_os>0&&temp_os<4)
		{
			os_change_input(temp[size].os,temp_os);
			check=false;
			cout<<"\n";
		}
		else
		{
			cout<<"\nwrong input,lets do it again . . .\n";
			cout<<"enter a number betwin 1 and 3 : ";
		}
		
	}

	int temp_storage;
	cout<<"\nthese are the storages there are,choose one : ";
	cout<<"\n1_16GB,2_32GB,3_64GB,4_128GB,5_256GB,6_512GB,7_1TB,8_2TB\n";
	check=true;
	while(check)
	{
		cin>>temp_storage;
		if(temp_storage>0&&temp_storage<9)
		{
			storage_change_input(temp[size].storage,temp_storage);
			check=false;
			cout<<"\n";
		}
		else
		{
			cout<<"\nwrong input,lets do it again . . .\n";
			cout<<"enter a number betwin 1 and 8 : ";
		}
	}

	
	int temp_color;
	cout<<"\nthese are the colors there are,choose one : ";
	cout<<"\n1_white,2_black,3_blue\n";
	check=true;
	while(check)
	{
		cin>>temp_color;
		if(temp_color>0&&temp_color<4)
		{
			color_change_input(temp[size].color,temp_color);
			check=false;
			cout<<"\n";
		}
		else
		{
			cout<<"\nwrong input,lets do it again . . .\n";
			cout<<"enter a number betwin 1 and 3 : ";
		}
	}
	delete [] my_phone;
	my_phone=temp;
	size++;
}
void add_phone(phone_store * & my_phone,string name3,string company3,int size,int num1)
{
	for(int q=0;q<size;q++)
	{
		if((my_phone[q].name==name3)&&(my_phone[q].company==company3))
		{
			my_phone[q].number_of_exist+=num1;
			cout<<"\nit is done \n";
			return ;
		}
	}
}
void print_mpbile(phone_store* my_phone,int size,int andis)
{
	cout<<"---------------------------------------------------\n";
	cout<<"mobile "<<andis+1<<" : \n\n";
	cout<<"name : "<<my_phone[andis].name;
	cout<<"\ncompany : "<<my_phone[andis].company;
	cout<<"\ncost : "<<my_phone[andis].cost;
	cout<<"\nexist : "<<my_phone[andis].number_of_exist;
	cout<<"\nsold : "<<my_phone[andis].number_of_sold;
	cout<<"\nram : ";ram_change_output(my_phone[andis].ram);
	cout<<"\nstorage : ";storage_change_output(my_phone[andis].storage);
	cout<<"\nos : ";os_change_output(my_phone[andis].os);
	cout<<"\ncolor : ";color_change_output(my_phone[andis].color);
	cout<<"\n";
}
void remove_phone(phone_store *&my_phone,int &size,string name2,string company2)
{
	if(search(my_phone,size,name2,company2)==-1)
	{
		cout<<"\nthere is no such mobile !";
	}
	else
	{
		int andis=0;
		phone_store * temp1=new phone_store[size-1];
		for(int q=0;q<size;q++)
		{
			if((my_phone[q].name==name2)&&(my_phone[q].company==company2))
			{}
			else
			{
				temp1[andis]=my_phone[q];
				andis++;
			}
		}
		delete [] my_phone;
		size--;
		my_phone=temp1;
		cout<<"\nremoved\n\n";
	}
}
void sort_by_price(phone_store *& my_phone,int size)
{
	for(int q=0;q<size;q++)
	{
		for(int w=0;w<size-q-1;w++)
		{
			if(my_phone[w].cost>my_phone[w+1].cost)
			{
				swap(my_phone[w],my_phone[w+1]);
			}
		}
	}
	cout<<"\n\nit is done !";
}
int search(phone_store *& my_phone,int size,string name4,string company4)
{
	for(int q=0;q<size;q++)
	{
		if((my_phone[q].name==name4)&&(my_phone[q].company==company4))
		{
			return q;
		}
	}
	return -1;
}
void change_mobile_info(phone_store *& my_phone,int size,string name6,string company6)
{
	if(search(my_phone,size,name6,company6)==-1)
	{
		cout<<"\nthere is no such mobile !\n";
	}
	else
	{
		int andis2=search(my_phone,size,name6,company6);
		cout<<"\n---------------------------------------------------\n";
		cout<<"we can change these : \n";
		cout<<"1.name";
		cout<<"\n2.company";
		cout<<"\n3.cost";
		cout<<"\n4.exist";
		cout<<"\n5.sold";
		cout<<"\n6.color";
		cout<<"\n7.ram";
		cout<<"\n8.storage";
		cout<<"\n9.os";
		cout<<"\nwhich one do you want to change ?\n";
		int temp_choice;
		cin>>temp_choice;
		if(temp_choice==1)
		{
			cout<<"now the name is : "<<my_phone[andis2].name<<"\n";
			string temp_string;
			cout<<"\nname : ";
			cin>>temp_string;
			if(search(my_phone,size,temp_string,my_phone[andis2].company)==-1)
			{
				my_phone[andis2].name=temp_string;
				cout<<"\nit is done !";
			}
			else
			{
				cout<<"\nwe can not change it ,a mobile with this name\nand company name is exist now\n";
			}
		}
		else if(temp_choice==2)
		{
			cout<<"now the company is : "<<my_phone[andis2].company<<"\n";
			string temp_string;
			cout<<"\ncompany : ";
			cin>>temp_string;
			if(search(my_phone,size,my_phone[andis2].name,temp_string)==-1)
			{
				my_phone[andis2].company=temp_string;
				cout<<"\nit is done !";
			}
			else
			{
				cout<<"\nwe can not change it ,a mobile with this name\nand company name is exist now\n";
			}
		}
		else if(temp_choice==3)
		{
			cout<<"now the cost is : "<<my_phone[andis2].cost<<"\n";
			long double temp_cost1;
			cout<<"cost : ";
			cin>>temp_cost1;
			my_phone[andis2].cost=temp_cost1;
			cout<<"\nit is done !";
		}
		else if(temp_choice==4)
		{
			cout<<"now the exist is : "<<my_phone[andis2].number_of_exist<<"\n";
			int temp_int1;
			cout<<"exist : ";
			cin>>temp_int1;
			my_phone[andis2].number_of_exist=temp_int1;
			cout<<"\nit is done !";
		}
		else if(temp_choice==5)
		{
			cout<<"now the sold is : "<<my_phone[andis2].number_of_sold<<"\n";
			int temp_int1;
			cout<<"sold : ";
			cin>>temp_int1;
			my_phone[andis2].number_of_sold=temp_int1;
			cout<<"\nit is done !";
		}
		else if(temp_choice==6)
		{
			
			cout<<"now the color is : ";color_change_output(my_phone[andis2].color);cout<<"\n";
			int temp_color;
			cout<<"\nthese are the colors there are,choose one : ";
			cout<<"\n1_white,2_black,3_blue\n";
			cin>>temp_color;
			color_change_input(my_phone[andis2].color,temp_color);
			cout<<"\nit is done !";
		}
		else if(temp_choice==7)
		{
			cout<<"now the ram is : ";ram_change_output(my_phone[andis2].ram);cout<<"\n";
			int temp_ram;
			cout<<"\nthese are the rams there are ,choose one : ";
			cout<<"\n1_2GB,2_4GB,3_6GB,4_8GB,5_12GB,6_16GB,7_32GB,8_64GB\n";
			cin>>temp_ram;
			ram_change_input(my_phone[andis2].ram,temp_ram);
			cout<<"\nit is done !";
		}
		else if(temp_choice==8)
		{
			cout<<"now the storage is : ";storage_change_output(my_phone[andis2].storage);cout<<"\n";
			int temp_storage;
			cout<<"\nthese are the storages there are,choose one : ";
			cout<<"\n1_16GB,2_32GB,3_64GB,4_128GB,5_256GB,6_512GB,7_1TB,8_2TB\n";
			cin>>temp_storage;
			storage_change_input(my_phone[andis2].storage,temp_storage);
			cout<<"\nit is done !";
		}
		else if(temp_choice==9)
		{
			cout<<"now the os is : ";os_change_output(my_phone[andis2].os);cout<<"\n";
			int temp_os;
			cout<<"\nthese are the oss there are ,choose one : ";
			cout<<"\n1_iOS,2_Android,3_windows phone\n";
			cin>>temp_os;
			os_change_input(my_phone[andis2].os,temp_os);
			cout<<"\nit is done !";
		}
		else
		{
			cout<<"\nwe have not this option \n";
		}
	}
}
void sell_a_phone(phone_store *& my_phone,int size,string name7,string company7)
{
	if(search(my_phone,size,name7,company7)==-1)
	{
		cout<<"there if no such mobile\n";
	}
	else
	{
		int andis3=search(my_phone,size,name7,company7);
		cout<<"we have now "<<my_phone[andis3].number_of_exist<<" of this mpbile\n";
		cout<<"enter the number of sell : ";
		int temp_num;
		cin>>temp_num;
		if((my_phone[andis3].number_of_exist-temp_num)<0)
		{
			cout<<"\nthere is no enough phone to be sold\n";
		}
		else
		{
			my_phone[andis3].number_of_exist-=temp_num;
			my_phone[andis3].number_of_sold+=temp_num;
			cout<<"\nit is done !\n";
		}
	}
}
void most_sold_phone(phone_store *my_phone,int size)
{
	int temp_arr1[size],temp_arr2[size];
	for(int q=0;q<size;q++)
	{
		temp_arr1[q]=q;
		temp_arr2[q]=my_phone[q].number_of_sold;
	}
	for(int q=0;q<size;q++)
	{
		for(int w=0;w<size-q-1;w++)
		{
			if(temp_arr2[w]<temp_arr2[w+1])
			{
				swap(temp_arr2[w],temp_arr2[w+1]);
				swap(temp_arr1[w],temp_arr1[w+1]);
			}
		}
	}
	for(int q=0;q<size;q++)
	{
		print_mpbile(my_phone,size,temp_arr1[q]);
	}
}
void ram_change_input(Ram &ram,int temp_ram)
{
	if(temp_ram>0&&temp_ram<9)
	{
		if(temp_ram==1)ram=_2GB;
		else if(temp_ram==2)ram=_4GB;
		else if(temp_ram==3)ram=_6GB;
		else if(temp_ram==4)ram=_8GB;
		else if(temp_ram==5)ram=_12GB;
		else if(temp_ram==6)ram=_16GB;
		else if(temp_ram==7)ram=_32GB;
		else if(temp_ram==8)ram=_64GB;
	}
	else 
	{
		cout<<"\ninvalid input !\n";
	}
}
void ram_change_output(Ram ram)
{
	if(ram==1)cout<<"2GB";
	else if(ram==2)cout<<"4GB";
	else if(ram==3)cout<<"6GB";
	else if(ram==4)cout<<"8GB";
	else if(ram==5)cout<<"12GB";
	else if(ram==6)cout<<"16GB";
	else if(ram==7)cout<<"32GB";
	else if(ram==8)cout<<"64GB";
}
void os_change_input(OS & os,int temp_os)
{
	if(temp_os>0&&temp_os<4)
	{
		if(temp_os==1)os=iOS;
		else if(temp_os==2)os=Android;
		else if(temp_os==3)os=windows_phone;
	}
	else 
	{
		cout<<"\ninvalid input !\n";
	}
}
void os_change_output(OS os)
{
	if(os==1)cout<<"iOS";
	else if(os==2)cout<<"Android";
	else if(os==3)cout<<"windows phone";
}
void storage_change_input(Storage &storage,int temp_storage)
{
	if(temp_storage>0&&temp_storage<9)
	{
		if(temp_storage==1)storage=__16GB;
		else if(temp_storage==2)storage=__32GB;
		else if(temp_storage==3)storage=__64GB;
		else if(temp_storage==4)storage=__128GB;
		else if(temp_storage==5)storage=__256GB;
		else if(temp_storage==6)storage=__512GB;
		else if(temp_storage==7)storage=__1TB;
		else if(temp_storage==8)storage=__2TB;
	}
	else
	{
		cout<<"\ninvalid input !\n";
	}
}
void storage_change_output(Storage storage)
{
	if(storage==1)cout<<"16GB";
	else if(storage==2)cout<<"32GB";
	else if(storage==3)cout<<"64GB";
	else if(storage==4)cout<<"128GB";
	else if(storage==5)cout<<"256GB";
	else if(storage==6)cout<<"512GB";
	else if(storage==7)cout<<"1TB";
	else if(storage==8)cout<<"2TB";
}
void color_change_input(Color & color,int temp_color)
{
	if(temp_color>0&&temp_color<4)
	{
		if(temp_color==1)color=white;
		else if(temp_color==2)color=black;
		else if(temp_color==3)color=blue;
	}
	else 
	{
		cout<<"\ninvalid input !\n";
	}
}
void color_change_output(Color color)
{
	if(color==1)cout<<"white";
	else if(color==2)cout<<"black";
	else if(color==3)cout<<"blue";
}
void save_to_a_file(phone_store *my_phone, int size)
{
	ofstream myfile("file.txt",ios::trunc);
	if(myfile)
	{
		for(int q=0;q<size;q++)
		{
			myfile<<"mobile"<<q+1<<":";
			myfile<<"\nname: "<<my_phone[q].name;
			myfile<<"\ncompany: "<<my_phone[q].company;
			myfile<<"\ncost: "<<my_phone[q].cost;
			myfile<<"\nexist: "<<my_phone[q].number_of_exist;
			myfile<<"\nsold: "<<my_phone[q].number_of_sold;
			{
				myfile<<"\n";
				if(my_phone[q].ram==1)myfile<<"Ram(GB): "<<"2";
				else if(my_phone[q].ram==2)myfile<<"Ram(GB): "<<"4";
				else if(my_phone[q].ram==3)myfile<<"Ram(GB): "<<"6";
				else if(my_phone[q].ram==4)myfile<<"Ram(GB): "<<"8";
				else if(my_phone[q].ram==5)myfile<<"Ram(GB): "<<"12";
				else if(my_phone[q].ram==6)myfile<<"Ram(GB): "<<"16";
				else if(my_phone[q].ram==7)myfile<<"Ram(GB): "<<"32";
				else if(my_phone[q].ram==8)myfile<<"Ram(GB): "<<"64";
			}
			{
				myfile<<"\n";
				if(my_phone[q].os==1)myfile<<"OS: "<<"iOS";
				else if(my_phone[q].os==2)myfile<<"OS: "<<"Android";
				else if(my_phone[q].os==3)myfile<<"OS: "<<"windows_phone";
			}
			{
				myfile<<"\n";
				if(my_phone[q].storage==1)myfile<<"storage(GB): "<<"16";
				else if(my_phone[q].storage==2)myfile<<"storage(GB): "<<"32";
				else if(my_phone[q].storage==3)myfile<<"storage(GB): "<<"64";
				else if(my_phone[q].storage==4)myfile<<"storage(GB): "<<"128";
				else if(my_phone[q].storage==5)myfile<<"storage(GB): "<<"256";
				else if(my_phone[q].storage==6)myfile<<"storage(GB): "<<"512";
				else if(my_phone[q].storage==7)myfile<<"storage(TB): "<<"1";
				else if(my_phone[q].storage==8)myfile<<"storage(TB): "<<"2";
			}
			{
				myfile<<"\n";
				if(my_phone[q].color==1)myfile<<"color: "<<"white";
				else if(my_phone[q].color==2)myfile<<"color: "<<"black";
				else if(my_phone[q].color==3)myfile<<"color: "<<"blue";
			}
			myfile<<'\n';	
		}
		myfile.close();
	}
	else
	{
		cout<<"\nthere is a problem in opening file\n";
	}
	
}
void load_from_a_file(phone_store *& my_phone, int &size)
{
	ifstream myfile("file.txt");
	if(myfile)
	{
		while(myfile)
		{
			phone_store* temp=new phone_store [size+1];
			for(int q=0;q<size;q++)
			{
				temp[q]=my_phone[q];
			}
			string temp_string_num;
			myfile>>temp_string_num;
			string temp_name;
			myfile>>temp_name;
			myfile>>temp_name;
			temp[size].name=temp_name;
			string temp_company;
			myfile>>temp_company;
			myfile>>temp_company;
			temp[size].company=temp_company;
			string temp_cost;
			myfile>>temp_cost;
			long double temp_double_cost;
			myfile>>temp_double_cost;
			temp[size].cost=temp_double_cost;
			string temp_exist;
			myfile>>temp_exist;
			int temp_int_exist;
			myfile>>temp_int_exist;
			temp[size].number_of_exist=temp_int_exist;
			string temp_sold;
			myfile>>temp_sold;
			int temp_int_sold;
			myfile>>temp_int_sold;
			temp[size].number_of_sold=temp_int_sold;
			string temp_ram;
			myfile>>temp_ram;
			int temp_int_ram;
			myfile>>temp_int_ram;
			{
				if(temp_int_ram==2)temp[size].ram=_2GB;
				else if(temp_int_ram==4)temp[size].ram=_4GB;
				else if(temp_int_ram==6)temp[size].ram=_6GB;
				else if(temp_int_ram==8)temp[size].ram=_8GB;
				else if(temp_int_ram==12)temp[size].ram=_12GB;
				else if(temp_int_ram==16)temp[size].ram=_16GB;
				else if(temp_int_ram==32)temp[size].ram=_32GB;
				else if(temp_int_ram==64)temp[size].ram=_64GB;
			}
			string temp_os;
			myfile>>temp_os;
			myfile>>temp_os;
			{
				if(temp_os=="iOS")temp[size].os=iOS;
				else if(temp_os=="Android")temp[size].os=Android;
				else if(temp_os=="windows_phone")temp[size].os=windows_phone;
			}
			string temp_storage;
			myfile>>temp_storage;
			int temp_int_storage;
			myfile>>temp_int_storage;
			{
				if(temp_int_storage==16)temp[size].storage=__16GB;
				else if(temp_int_storage==32)temp[size].storage=__32GB;
				else if(temp_int_storage==64)temp[size].storage=__64GB;
				else if(temp_int_storage==128)temp[size].storage=__128GB;
				else if(temp_int_storage==256)temp[size].storage=__256GB;
				else if(temp_int_storage==512)temp[size].storage=__512GB;
				else if(temp_int_storage==1)temp[size].storage=__1TB;
				else if(temp_int_storage==2)temp[size].storage=__2TB;
			}
			string temp_color;
			myfile>>temp_color;
			myfile>>temp_color;
			{
				if(temp_color=="white")temp[size].color=white;
				else if(temp_color=="black")temp[size].color=black;
				else if(temp_color=="blue")temp[size].color=blue;
			}
			delete [] my_phone;
			my_phone=temp;
			size++;			
		}
		phone_store* temp=new phone_store [size-1];
		for(int q=0;q<size-1;q++)
		{
			temp[q]=my_phone[q];
		}
		delete [] my_phone;
		my_phone=temp;
		size--;
		myfile.close();
	}
}






