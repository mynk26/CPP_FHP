#include "account.h"
#include<stdio.h>
typedef Account Record;
class AccountFile{
private: Record r; fstream f,n;
public:
    AccountFile(){f.open("account.dat",ios::in | ios::out | ios::ate);}
    void add();
    void showall();
    void search2();
    void deposit();
    void withdraw();
    void deleteac();
     ~AccountFile(){f.close(); f.close(); f.close();}
};
void AccountFile::add(){
r.read();
f.seekg(0,ios::end);
f.write((char*)&r,sizeof(r));
cout<<"account created successfully";
}

void AccountFile::showall(){
f.seekg(0,ios::beg);
cout.setf(ios::left,ios::adjustfield);
cout<<endl<<setw(10)<<"acno"<<setw(20)<<"name"<<setw(10)<<"balance";
while(f.read((char*)&r,sizeof(r))){
    r.show2();
}
f.clear();
}

void AccountFile::deposit(){
int ac,count=0,position=0;
cout<<"\nEnter account no.: ";
cin>>ac;
f.seekg(0,ios::beg);
while(f.read((char*)&r,sizeof(r))){
    if(ac==r.getAcno()){
        r.deposit();
        f.seekg(position,ios::beg);
        f.write((char*)&r,sizeof(r));
        count++;
        break;
    }
    position+=sizeof(r);
}
f.clear();
if(count==0){
    cout<<"\nAccount no : ("<<ac<<") NOT FOUND\n";
}
}

void AccountFile::search2(){
    int ac,count=0;
    cout<<"Enter account no: ";
    cin>>ac;
f.seekg(0,ios::beg);
while(f.read((char*)&r,sizeof(r))){
    if(ac==r.getAcno()){
        r.show(); count++; break;
    }}
f.clear();
if(count==0){
        cout<<"\nAccount no : ("<<ac<<") NOT FOUND\n";
}

}

void AccountFile::withdraw(){
int ac,count=0,position=0;
cout<<"Enter your account no.:";
cin>>ac;
f.seekg(0,ios::beg);
while(f.read((char*)&r,sizeof(r))){
    if(ac==r.getAcno()){
        r.withdraw();
        f.seekg(position,ios::beg);
        f.write((char*)&r,sizeof(r));
        count++; break;
    }
    position+=sizeof(r);
}
    f.clear();
    if(count==0){
        cout<<"\nAccount no : ("<<ac<<") NOT FOUND\n";
}
}

void AccountFile::deleteac(){
int ac,cnt=0;
n.open("newfile.dat",ios::out|ios::in|ios::ate);
cout<<"Enter account no. to delete";
cin>>ac;
f.seekg(0,ios::beg);
n.seekg(0,ios::end);
while(f.read((char*)&r,sizeof(r))){
    if(ac!=r.getAcno()){
        n.write((char*)&r,sizeof(r));
}
else cnt++;
}
n.clear();
n.close(); n.close(); n.close();
f.clear();
f.close(); f.close(); f.close();
remove((char*)&"account.dat");
rename((char*)&"account.dat",(char*)&"newfile.dat");
f.open("account.dat",ios::out|ios::in|ios::ate);
if(cnt==0){
    cout<<"No such account found";
    }
}
