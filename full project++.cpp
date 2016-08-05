#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;
struct clint 
    {
           string name ;
           int balance;
           int cardnumber;
           int pinnumber;
           };
           
           
           int numline (){
				 ifstream file;
                  file.open("clintsinformation.txt");
                  string q;
                  int x=0;
				while (!file.eof()){
					getline (file,q);
					x++;
					
				}
				return x;
           }
           void save (vector<clint> clintdatabase){
				ofstream file;
                  file.open("clintsinformation.txt");
            
				  for (int i=0;i<clintdatabase.size();i++){
						if(i)
						file<<endl;
						file<<
		        clintdatabase[i].name<<"\t"<<
		        clintdatabase[i].balance<<"\t"<<
		        clintdatabase[i].cardnumber<<"\t"<<
		        clintdatabase[i].pinnumber<<"\t";
		        
                  }
				file.close();
				
				
				
           }
           

int main(int argc, char *argv[]) {
    
	 int x,y,z;
          string b;
	      ifstream file;
        file.open("clintsinformation.txt");
       vector<clint>clintdatabase;
          clint newclint;
		  for(int i=0;!file.eof();i++){
				file>>b>>x>>y>>z;
				
		        newclint.name=b;
		        newclint.balance=x;
		        newclint.cardnumber=y;
		        newclint.pinnumber=z;
		        clintdatabase.push_back(newclint);
		        
			}
	     file.close();
	 
	 first:
	 system ("cls");
	cout<<endl;
	cout<<"   ------------------------Welcome to ATM system-------------------------"<<endl;
	cout<<endl;
	cout<<"	For Admin  moad preas 1  "<<endl;
	cout<<endl;
	cout<<"	For client moad preas 2 "<<endl;
    
	int num;
	cin>>num;
	switch(num)
	{
		case 1:
			cout<<endl;
			cout<<endl;
			cout<<"Welcome Admin"<<endl;
			cout<<"Please enter your password"<<endl;
			int Apaas;
			cin>>Apaas;
			if (Apaas==1234){
				system ("cls");
				cout<<"your functionalities are"<<endl;
				cout<<"A.Add client"<<endl;
				cout<<"B.View all availbal client"<<endl;
				char x;
				cin>>x;
				switch(x){
					case 'A':
					case 'a':
					{	system ("cls");
						clint x;
						cout<<"Enter clint name :"<<endl;
						cin>>x.name;
						cout<<"Enter clint balance :"<<endl;
						cin>>x.balance;
					    cout<<"The clint card number is :";
						srand((unsigned)time(0));
						int cardnumber=rand();
						x.cardnumber=(cardnumber*1010)%100000;
						cout<<cardnumber<<endl;
							int pinnumber=rand();
						x.pinnumber=(pinnumber*1010)%10000;
						cout<<"The clint pin number is:";
						cout<<pinnumber<<endl;
						
					
					
					clintdatabase.pop_back();
					clintdatabase.push_back(x);
					save (clintdatabase);
			
					cout<<endl;
					cout<<"prees any key to get back to admin menu"<<endl;
					system("pause");
					goto first;
					
					}
						break;
					case 'B':
					case 'b':	
					{	
							system ("cls");
					
						cout<<clintdatabase.size();
						for(int i=0;i<clintdatabase.size();i++){
							cout<<clintdatabase[i].name<<"\t"<<clintdatabase[i].balance<<"\t"
							<<clintdatabase[i].cardnumber<<"\t"<<clintdatabase[i].pinnumber<<"\t"<<endl;
						}	
							
					cout<<"prees any key to get back to admin menu"<<endl;
					system("pause");
					goto first;
					}
					break;
				}
				
				
				
			}
			else {
				cout<<"Erooor"<<endl;
				cout<<"prees any key to get back to admin menu"<<endl;
				system("pause");
				
				goto first;
			}
			break ;
	        case 2 :
				cout<<endl;
			    cout<<endl;
			    cout<<"Welcome User"<<endl;
                int numberofline=numline();
          
	 
	 
	 
	            int ucard,upin,uplace;
	            cout<<"Enter your card number"<<endl;
	            cin>>ucard;
	            cout<<"Enter your pin number"<<endl;
	            cin>>upin;
	            system ("cls");
	    
	            int numberOFclint=-1;
	    
	        	for (int i=0;i<numberofline;i++)
		    	if (ucard==clintdatabase[i].cardnumber&&upin==clintdatabase[i].pinnumber)
		    	numberOFclint=i;
		 	
			if (numberOFclint>-1)
			{
				
				
				cout<<"welcome "<<clintdatabase[numberOFclint].name<<endl;
				
             double withdraw, depositm ;
            int option;
            cout<<endl;
              

              cout<<"***   WelCoMe    ***"<<endl;
              cout<<"Choose ur option"<<endl;
              cout<<"1- change card pin"<<endl ;
              cout<<"2- Withdraw "<<endl;
              cout<<"3- Deposit "<<endl;
              cout<<"4- Quit "<<endl;
              cout<<"Enter Option:"<<endl;
              cin>>option;
              
              
              switch(option)
              {
					 case 1:
						cout<<"enter new card pin"<<endl;
                        int newcardpin ;
                        cin>>newcardpin;

                        cout<<"\n Your new pin is ====>"<<newcardpin<<endl;
                        
					clintdatabase[numberOFclint].pinnumber=newcardpin;
					save (clintdatabase);
					
                       break;
                     case 2:
                         {
                          double balance;
                          
                          int x,y,z;
                           string b;
                        cout<<"*=*=*=*(WITHDRAW)=*=*=*=*="<<endl;
                        cout<<"Enter amount: "<<endl;;
                        cin>>withdraw;
                        if(withdraw>clintdatabase[numberOFclint].balance){
							cout<<"you can't do this operation"<<endl;
                        }
                        else {
	                    file.close();
	                    cout<<"ur balance is "<<clintdatabase[numberOFclint].balance<<endl;
       
                  
                        clintdatabase[numberOFclint].balance-=withdraw;
                      

                        cout<<"You withdrew =====> "<<withdraw<<endl;
                        cout<<"Your current balance is =====>"<< clintdatabase[numberOFclint].balance<<endl;
                      
					    save (clintdatabase);
					    clintdatabase.pop_back();
					}
					
                        break ;
                         }
                     case 3:
                         {
                        cout<<"*=*=*=*=)(DEPOSIT)*=*=*=*=*"<<endl;
                        cout<<"Enter amount: $";
                        double deposit;
                         
                         double balance;
                        cin>>deposit;

                      
	                     cout<<"ur balance is"<<clintdatabase[numberOFclint].balance<<endl;
       
                  
                         clintdatabase[numberOFclint].balance+=deposit;

                         cout<<"You deposite=====>d "<<deposit<<endl;
                         cout<<"Your new balance is $=====>"<<clintdatabase[numberOFclint].balance<<endl;
                         clintdatabase.pop_back();
		      		     save (clintdatabase);
		      		     
 
				         break;
                        
                          }         
					 case 4:
                        {
                                    return 0;
     
                                    break;
                         }

                              default:
        
                             cout<<" That is ErrRRooR "<<endl;


                              break;
                              
		}
		}
		else {
			
				cout<<"your card number or pin number doesnot exict"<<endl;
			    cout<<"prees any key to get back to admin menu"<<endl;
				system("pause");
				goto first;
			}	
		
	    
	 }
	 

 
	system("pause");
	return 0;
}
