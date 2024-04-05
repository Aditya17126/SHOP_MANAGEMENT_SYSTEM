#include<bits/stdc++.h>
using namespace std;

class shop{
	public:
  char nm[100];
  char nm1[100];
  float price;
  int qty;
  
  void input();
  void display();
  
};
void shop :: input(){
	cin.ignore();
	cout<<"ENTER THE PRODUCT NAME :"<<endl;
	gets(nm);
	cout<<"ENTER THE COMPANY NAME :"<<endl;
	gets(nm1);
	cout<<"ENTER THE PRICE :"<<endl;
	cin>>price;
	cout<<"ENTER TOTAL NO OF PIECES :"<<endl;
	cin>>qty;
}
 void shop::display(){
 	cout<<"\t\t\t\t"<<nm1<<"   |  "<<nm<<"   |  "<<price<<"  | "<<qty<<"   |  "<<endl;
 }
  void add_prod()
  {
  	shop s1;
  	fstream fout;
  	fout.open("shop.dat",ios::app|ios::binary);
  	s1.input();
    fout.write((char *)&s1,sizeof(s1));
    fout.close();
  }
  
  void prod_display(){
  	shop s1;
  	fstream fin;
  	fin.open("shop.dat",ios::in|ios::binary);
  	
  	if(!fin){
  		cout<<"FILE DOESNOT EXIST ....";
  		exit;
	  }
    else
	{
	while(fin.read((char *)&s1,sizeof(s1)))
	{
		s1.display();
	}
}
	fin.close();
}  

 void prod_search(){
 	char nam[100], found =0;
 	cin.ignore();
 	cout<<"ENTER THE PRODUCT YOU WANT TO SEARCH "<<endl;
 	gets(nam);
 	
 	shop s1;
 	fstream fin;
 fin.open("shop.dat",ios::in| ios::binary);
 
 while(fin.read((char *)&s1,sizeof(s1))){
 
 	if(strcmp(nam,s1.nm) == 0){
 		found =1;
  cout<<"\t\t\t--------------------------------------------------";
  cout<<endl<<"\t\t\t   COMPANY NAME | PRODUCT | PRICE | QUANTITY |";
  cout<<endl<<"\t\t\t--------------------------------------------------"<<endl;
  s1.display();
cout<<"\t\t\t---------------------------------------------------"<<endl; 
 break;
 }
}

if(found == 0){
	cout<<"\tRECORD NOT FOUND";
}
}  
 void delete_prod(char nm2[100]){
 	shop s1;
 	bool flag = false;
ifstream fin;
fstream fin1;
 fin.open("shop.dat",ios::binary);
fin1.open("temp.dat",ios::binary|ios::out);

if(!fin)
{
 cout<<"File could not be open ! press any key.... ";
	return;
}	
 while(fin.read((char *)&s1,sizeof(s1)))
{
	if(strcmp(nm2,s1.nm) != 0)
	{
		fin1.write((char *)&s1, sizeof(s1));
	}
}
	fin.close();
			fin1.close();
			remove("shop.dat");
			rename("temp.dat","shop.dat");
			
cout<<"RECORD HAS BEEN DELETED......";

 }  
  
  
  
  
int main()
{
  int n,r;
  shop s1;
 
  while(1)
  {
  	cout<<endl<<endl<<"\t\t\t\t************************************************************"<<endl;
  	cout<<endl<<"\t\t\t\t\tGUPTA,ELECTRICALS,HARDWARE && PAINTS "<<endl;
    cout<<endl<<"\t\t\t\t************************************************************"<<endl;
    
    cout<<endl<<"\t01:ADD ANY PRODUCT"<<endl;
    cout<<endl<<"\t02:DISPLAY ALL PRODUCT"<<endl;
    cout<<endl<<"\t03:SEARCH PRODUCT"<<endl;
    cout<<endl<<"\t04:EXIT....."<<endl;
    cout<<endl<<"\t05:DELETE RECORD"<<endl;
   
  cout<<endl<<"\t\t\t\t*********************************************************"<<endl;
  cout<<endl<<"\t\t\t\t\t   SELECT OPTION FROM ABOVE <0-6>  "<<endl;
  cout<<endl<<"\t\t\t\t*********************************************************"<<endl;
  cin>>n;
  switch(n){
case 1:
     add_prod();
     cout<<"RECORD HAS BEEN RECORDED >>>>>>"<<endl;
	 break;       

case 2:
  cout<<endl<<endl<<"\t\t\t RECORD OF ALL PRODUCTS "<<endl;
  cout<<"\t\t\t--------------------------------------------------";
  cout<<endl<<"\t\t\t   COMPANY NAME | PRODUCT | PRICE | QUANTITY |";
  cout<<endl<<"\t\t\t--------------------------------------------------"<<endl;
  
  prod_display();
  cout<<"\t\t\t---------------------------------------------------"<<endl; 
 break;
 
case 3:
  prod_search();
  break;
 
case 4 :
   cout<<"\t\t............EXITING ............."; 
    break;

case 5:
	char nm1[100];
	cin.ignore();
	cout<<"ENTER THE PRODUCT NAME "<<endl;
	gets(nm1);
	delete_prod(nm1);
	break;
}
  }


	return 0;
}

