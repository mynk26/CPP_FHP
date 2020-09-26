using namespace std;
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include "account2.h"
int main(){
 AccountFile af;int choice;
 do{ system("cls");
    cout<<endl<<"===========================MS Bank==========================="<<endl<<endl;
    cout<<"1. Add Account\n2. Show All\n3. Search Account\n4. deposit\n5. withdraw\n6. Delete Account\n7. Exit\n";
    cin>>choice;
    switch(choice){
    case 1: af.add(); break;
    case 2: af.showall(); break;
    case 3: af.search2(); break;
    case 4: af.deposit(); break;
    case 5: af.withdraw(); break;
  //  case 6: af.deleteac(); break;
    case 7: cout<<"\nThanks,  visit again "; break;
    default: cout<<"\nInvalid choice";
    }
    getch();
 }while(choice!=7);
 //af.~AccountFile();
 return 0;
}
